---
title: dynarray
description: "DynArrays: copying, joining, comparing, reversing and sorting them."
---

DynArrays: copying, joining, comparing, reversing and sorting them.

A DynArray is made by the builtin `dynarray()` or `dynarray(xs)`, read with `v[i]`
and written with `v[i] := x`, and grown and shrunk by the builtins
`push`, `pop`, `insert`, `remove` and `clear`; `len(v)` and
`same(v, w)` are builtins too (PYKING.md, "DynArrays"). This module is the
rest. `copy`, `to_list` and `to_array` make a **new** value and copy
**shallowly**; `extend`, `reverse` and `sort` change the DynArray they are
given, which everyone holding it sees. `push` and `pop` take constant
time on average, `insert` and `remove` time in proportion to the
elements they move, and sorting `n log n`.

```pyking norun
import dynarray
```

<div class="pyk-api">

## bool::equal

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bool::equal</span>(<span class="p">v</span>: DynArray(<span class="t">Bool</span>), <span class="p">w</span>: DynArray(<span class="t">Bool</span>)) -&gt; <span class="t">Bool</span></code></pre>

Whether two DynArrays of Bools hold the same elements in the same order.

<p class="pyk-api-label">Parameters</p>

- `v`: one DynArray.
- `w`: the other.

<p class="pyk-api-label">Returns</p>

`true` when they have the same length and equal elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
print(dynarray.equal(dynarray([true]), dynarray([true])))
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## char::equal

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::equal</span>(<span class="p">v</span>: DynArray(Char), <span class="p">w</span>: DynArray(Char)) -&gt; <span class="t">Bool</span></code></pre>

Whether two DynArrays of Chars hold the same elements in the same order.

<p class="pyk-api-label">Parameters</p>

- `v`: one DynArray.
- `w`: the other.

<p class="pyk-api-label">Returns</p>

`true` when they have the same length and equal elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
print(dynarray.equal(dynarray(['a']), dynarray(['b'])))
```

```stdout visible = true
false
```

</div>

<div class="pyk-api">

## char::sort

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::sort</span>(<span class="p">v</span>: DynArray(Char)) -&gt; ()</code></pre>

Sorts a DynArray of Chars by code point, in place.

<p class="pyk-api-label">Parameters</p>

- `v`: the DynArray to sort.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
v = dynarray(['c', 'a', 'b'])
dynarray.sort(v)
print(v)
```

```stdout visible = true
dynarray(['a', 'b', 'c'])
```

</div>

<div class="pyk-api">

## copy

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">copy</span>(<span class="p">v</span>: DynArray(t)) -&gt; DynArray(t)</code></pre>

A new DynArray holding the same elements as `v`, in the same order.

<p class="pyk-api-label">Parameters</p>

- `v`: the DynArray to copy.

<p class="pyk-api-label">Returns</p>

A new DynArray of `len(v)` elements; changing one does not change the other.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
v = dynarray([1, 2])
w = dynarray.copy(v)
push(w, 3)
print(v, w)
```

```stdout visible = true
dynarray([1, 2]) dynarray([1, 2, 3])
```

</div>

<div class="pyk-api">

## extend

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">extend</span>(<span class="p">v</span>: DynArray(t), <span class="p">xs</span>: [t]) -&gt; ()</code></pre>

Adds every element of a list to the end of `v`, in order.

<p class="pyk-api-label">Parameters</p>

- `v`: the DynArray to grow.
- `xs`: what to add.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
v = dynarray([1])
dynarray.extend(v, [2, 3])
print(v)
```

```stdout visible = true
dynarray([1, 2, 3])
```

</div>

<div class="pyk-api">

## float::equal

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::equal</span>(<span class="p">v</span>: DynArray(<span class="t">Float</span>), <span class="p">w</span>: DynArray(<span class="t">Float</span>)) -&gt; <span class="t">Bool</span></code></pre>

Whether two DynArrays of Floats hold the same elements in the same order,
compared with `==` -- so a DynArray holding NaN equals no DynArray.

<p class="pyk-api-label">Parameters</p>

- `v`: one DynArray.
- `w`: the other.

<p class="pyk-api-label">Returns</p>

`true` when they have the same length and equal elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
print(dynarray.equal(dynarray([0.5]), dynarray([0.5])))
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## float::sort

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::sort</span>(<span class="p">v</span>: DynArray(<span class="t">Float</span>)) -&gt; ()</code></pre>

Sorts a DynArray of Floats in place, as `array.sort` orders them: `-inf`
first, `-0.0` and `0.0` as equal, then `inf`, and every NaN last.

<p class="pyk-api-label">Parameters</p>

- `v`: the DynArray to sort.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
v = dynarray([2.5, -1.0])
dynarray.sort(v)
print(v)
```

```stdout visible = true
dynarray([-1.0, 2.5])
```

</div>

<div class="pyk-api">

## from_array

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">from_array</span>(<span class="p">a</span>: Array(t)) -&gt; DynArray(t)</code></pre>

A new DynArray holding the elements of an array.

<p class="pyk-api-label">Parameters</p>

- `a`: the array.

<p class="pyk-api-label">Returns</p>

A new DynArray of `len(a)` elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
v = dynarray.from_array(array([1, 2]))
push(v, 3)
print(v)
```

```stdout visible = true
dynarray([1, 2, 3])
```

</div>

<div class="pyk-api">

## int::equal

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::equal</span>(<span class="p">v</span>: DynArray(<span class="t">Int</span>), <span class="p">w</span>: DynArray(<span class="t">Int</span>)) -&gt; <span class="t">Bool</span></code></pre>

Whether two DynArrays of Ints hold the same elements in the same order.
`same(v, w)` asks instead whether they are one DynArray.

<p class="pyk-api-label">Parameters</p>

- `v`: one DynArray.
- `w`: the other.

<p class="pyk-api-label">Returns</p>

`true` when they have the same length and equal elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
print(dynarray.equal(dynarray([1, 2]), dynarray([1, 2])), dynarray.equal(dynarray([1]), dynarray([2])))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## int::sort

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::sort</span>(<span class="p">v</span>: DynArray(<span class="t">Int</span>)) -&gt; ()</code></pre>

Sorts a DynArray of Ints from smallest to largest, in place, stably.

<p class="pyk-api-label">Parameters</p>

- `v`: the DynArray to sort.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
v = dynarray([3, 1, 2])
dynarray.sort(v)
print(v)
```

```stdout visible = true
dynarray([1, 2, 3])
```

</div>

<div class="pyk-api">

## reverse

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">reverse</span>(<span class="p">v</span>: DynArray(t)) -&gt; ()</code></pre>

Puts the elements of `v` in the opposite order, in place.

<p class="pyk-api-label">Parameters</p>

- `v`: the DynArray to reverse.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
v = dynarray([1, 2, 3])
dynarray.reverse(v)
print(v)
```

```stdout visible = true
dynarray([3, 2, 1])
```

</div>

<div class="pyk-api">

## string::equal

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::equal</span>(<span class="p">v</span>: DynArray(<span class="t">String</span>), <span class="p">w</span>: DynArray(<span class="t">String</span>)) -&gt; <span class="t">Bool</span></code></pre>

Whether two DynArrays of Strings hold the same elements in the same order.

<p class="pyk-api-label">Parameters</p>

- `v`: one DynArray.
- `w`: the other.

<p class="pyk-api-label">Returns</p>

`true` when they have the same length and equal elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
print(dynarray.equal(dynarray(["a"]), dynarray(["a"])))
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## string::sort

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::sort</span>(<span class="p">v</span>: DynArray(<span class="t">String</span>)) -&gt; ()</code></pre>

Sorts a DynArray of Strings in place, by code point.

<p class="pyk-api-label">Parameters</p>

- `v`: the DynArray to sort.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
v = dynarray(["pear", "Fig", "apple"])
dynarray.sort(v)
print(v)
```

```stdout visible = true
dynarray(["Fig", "apple", "pear"])
```

</div>

<div class="pyk-api">

## to_array

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">to_array</span>(<span class="p">v</span>: DynArray(t)) -&gt; Array(t)</code></pre>

The elements of `v` as they are now, as a new array.

<p class="pyk-api-label">Parameters</p>

- `v`: the DynArray.

<p class="pyk-api-label">Returns</p>

A new array of `len(v)` elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
print(dynarray.to_array(dynarray(["a", "b"])))
```

```stdout visible = true
array(["a", "b"])
```

</div>

<div class="pyk-api">

## to_list

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">to_list</span>(<span class="p">v</span>: DynArray(t)) -&gt; [t]</code></pre>

The elements of `v` as they are now, as a list.

<p class="pyk-api-label">Parameters</p>

- `v`: the DynArray.

<p class="pyk-api-label">Returns</p>

A list of `len(v)` elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import dynarray
v = dynarray([3, 4])
push(v, 5)
print(dynarray.to_list(v))
```

```stdout visible = true
[3, 4, 5]
```

</div>
