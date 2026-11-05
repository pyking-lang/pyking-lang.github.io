---
title: array
description: "Arrays: copying, filling, comparing, sorting and joining them."
---

Arrays: copying, filling, comparing, sorting and joining them.

An array is made by the builtins `array(...)` and `array_init(...)`,
read with `a[i]` and written with `a[i] := v`, and `len(a)` and
`same(a, b)` are builtins too (PYKING.md, "Arrays"). This module is
the rest. `copy`, `concat`
and `resize` make a **new** array, and copy **shallowly**: an array of
arrays copied still shares its rows. `fill`, `reverse`, `swap` and
`sort` change the array they are given, which everyone holding it
sees. Indexing, writing and `len` take constant time; copying,
filling and comparing take time in proportion to the length, and
sorting `n log n`.

```pyking norun
import array
```

<div class="pyk-api">

## bool::equal

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bool::equal</span>(<span class="p">a</span>: Array(<span class="t">Bool</span>), <span class="p">b</span>: Array(<span class="t">Bool</span>)) -&gt; <span class="t">Bool</span></code></pre>

Whether two arrays of Bools hold the same elements in the same order.

<p class="pyk-api-label">Parameters</p>

- `a`: one array.
- `b`: the other.

<p class="pyk-api-label">Returns</p>

`true` when they have the same length and equal elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
print(array.equal(array([true]), array([true])))
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## char::equal

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::equal</span>(<span class="p">a</span>: Array(Char), <span class="p">b</span>: Array(Char)) -&gt; <span class="t">Bool</span></code></pre>

Whether two arrays of Chars hold the same elements in the same order.

<p class="pyk-api-label">Parameters</p>

- `a`: one array.
- `b`: the other.

<p class="pyk-api-label">Returns</p>

`true` when they have the same length and equal elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
print(array.equal(array(['a', 'b']), array(['a', 'c'])))
```

```stdout visible = true
false
```

</div>

<div class="pyk-api">

## char::sort

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::sort</span>(<span class="p">a</span>: Array(Char)) -&gt; ()</code></pre>

Sorts an array of Chars by code point, in place.

<p class="pyk-api-label">Parameters</p>

- `a`: the array to sort.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(['c', 'a', 'b'])
array.sort(a)
print(a)
```

```stdout visible = true
array(['a', 'b', 'c'])
```

</div>

<div class="pyk-api">

## concat

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">concat</span>(<span class="p">a</span>: Array(t), <span class="p">b</span>: Array(t)) -&gt; Array(t)</code></pre>

A new array holding the elements of `a` and then those of `b`.

<p class="pyk-api-label">Parameters</p>

- `a`: the first part.
- `b`: the second part.

<p class="pyk-api-label">Returns</p>

A new array of `len(a) + len(b)` elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
print(array.concat(array([1, 2]), array([3])))
```

```stdout visible = true
array([1, 2, 3])
```

</div>

<div class="pyk-api">

## copy

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">copy</span>(<span class="p">a</span>: Array(t)) -&gt; Array(t)</code></pre>

A new array holding the same elements as `a`, in the same order.
Writing to one does not change the other; an element that is itself
an array is shared by both.

<p class="pyk-api-label">Parameters</p>

- `a`: the array to copy.

<p class="pyk-api-label">Returns</p>

A new array of `len(a)` elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1, 2, 3])
b = array.copy(a)
b[0] := 9
print(a, b, same(a, b))
```

```stdout visible = true
array([1, 2, 3]) array([9, 2, 3]) false
```

</div>

<div class="pyk-api">

## fill

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">fill</span>(<span class="p">a</span>: Array(t), <span class="p">v</span>: t) -&gt; ()</code></pre>

Writes `v` into every element of `a`.

<p class="pyk-api-label">Parameters</p>

- `a`: the array to fill.
- `v`: the value every element gets.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1, 2, 3])
array.fill(a, 0)
print(a)
```

```stdout visible = true
array([0, 0, 0])
```

</div>

<div class="pyk-api">

## float::equal

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::equal</span>(<span class="p">a</span>: Array(<span class="t">Float</span>), <span class="p">b</span>: Array(<span class="t">Float</span>)) -&gt; <span class="t">Bool</span></code></pre>

Whether two arrays of Floats hold the same elements in the same
order, compared with `==` -- so an array holding NaN equals no array.

<p class="pyk-api-label">Parameters</p>

- `a`: one array.
- `b`: the other.

<p class="pyk-api-label">Returns</p>

`true` when they have the same length and equal elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
print(array.equal(array([0.5]), array([0.5])))
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## float::sort

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::sort</span>(<span class="p">a</span>: Array(<span class="t">Float</span>)) -&gt; ()</code></pre>

Sorts an array of Floats from smallest to largest, in place: `-inf`
first, `-0.0` and `0.0` as equal, then `inf`, and every NaN last, the
same on every target.

<p class="pyk-api-label">Parameters</p>

- `a`: the array to sort.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
import math
a = array([2.5, math.nan, -1.0, math.inf])
array.sort(a)
print(a)
```

```stdout visible = true
array([-1.0, 2.5, inf, nan])
```

</div>

<div class="pyk-api">

## int::equal

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::equal</span>(<span class="p">a</span>: Array(<span class="t">Int</span>), <span class="p">b</span>: Array(<span class="t">Int</span>)) -&gt; <span class="t">Bool</span></code></pre>

Whether two arrays of Ints hold the same elements in the same order,
compared with `==`. `same(a, b)` asks instead whether they are one
array.

<p class="pyk-api-label">Parameters</p>

- `a`: one array.
- `b`: the other.

<p class="pyk-api-label">Returns</p>

`true` when they have the same length and equal elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
print(array.equal(array([1, 2]), array([1, 2])), array.equal(array([1]), array([2])))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## int::sort

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::sort</span>(<span class="p">a</span>: Array(<span class="t">Int</span>)) -&gt; ()</code></pre>

Sorts an array of Ints from smallest to largest, in place.

<p class="pyk-api-label">Parameters</p>

- `a`: the array to sort.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([3, 1, 2])
array.sort(a)
print(a)
```

```stdout visible = true
array([1, 2, 3])
```

</div>

<div class="pyk-api">

## resize

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">resize</span>(<span class="p">a</span>: Array(t), <span class="p">n</span>: <span class="t">Int</span>, <span class="p">v</span>: t) -&gt; Array(t)</code></pre>

A new array of `n` elements: those of `a` while it has them, and `v`
after that. It is always new, so an old array is never changed.

<p class="pyk-api-label">Parameters</p>

- `a`: the array to start from.
- `n`: the new length, never negative.
- `v`: what fills the elements `a` does not have.

<p class="pyk-api-label">Returns</p>

A new array of `n` elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1, 2, 3])
print(array.resize(a, 5, 0), array.resize(a, 2, 0))
```

```stdout visible = true
array([1, 2, 3, 0, 0]) array([1, 2])
```

</div>

<div class="pyk-api">

## reverse

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">reverse</span>(<span class="p">a</span>: Array(t)) -&gt; ()</code></pre>

Puts the elements of `a` in the opposite order, in place.

<p class="pyk-api-label">Parameters</p>

- `a`: the array to reverse.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1, 2, 3, 4])
array.reverse(a)
print(a)
```

```stdout visible = true
array([4, 3, 2, 1])
```

</div>

<div class="pyk-api">

## string::equal

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::equal</span>(<span class="p">a</span>: Array(<span class="t">String</span>), <span class="p">b</span>: Array(<span class="t">String</span>)) -&gt; <span class="t">Bool</span></code></pre>

Whether two arrays of Strings hold the same elements in the same order.

<p class="pyk-api-label">Parameters</p>

- `a`: one array.
- `b`: the other.

<p class="pyk-api-label">Returns</p>

`true` when they have the same length and equal elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
print(array.equal(array(["a"]), array(["a"])))
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## string::sort

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::sort</span>(<span class="p">a</span>: Array(<span class="t">String</span>)) -&gt; ()</code></pre>

Sorts an array of Strings in place, by code point: every target
orders them alike, `"B"` before `"a"`, and a String before every
longer one it starts.

<p class="pyk-api-label">Parameters</p>

- `a`: the array to sort.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(["pear", "apple", "Fig", "app"])
array.sort(a)
print(a)
```

```stdout visible = true
array(["Fig", "app", "apple", "pear"])
```

</div>

<div class="pyk-api">

## swap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">swap</span>(<span class="p">a</span>: Array(t), <span class="p">i</span>: <span class="t">Int</span>, <span class="p">j</span>: <span class="t">Int</span>) -&gt; ()</code></pre>

Exchanges the elements at `i` and `j`.

<p class="pyk-api-label">Parameters</p>

- `a`: the array.
- `i`: one index.
- `j`: the other.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(["x", "y", "z"])
array.swap(a, 0, 2)
print(a)
```

```stdout visible = true
array(["z", "y", "x"])
```

</div>

<div class="pyk-api">

## to_list

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">to_list</span>(<span class="p">a</span>: Array(t)) -&gt; [t]</code></pre>

The elements of `a` as they are now, as a list.

<p class="pyk-api-label">Parameters</p>

- `a`: the array.

<p class="pyk-api-label">Returns</p>

A list of `len(a)` elements; changing `a` afterwards does not change it.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array_init(3, lam i. i * 10)
print(array.to_list(a))
```

```stdout visible = true
[0, 10, 20]
```

</div>
