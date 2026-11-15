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

## bool::contains

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bool::contains</span>(<span class="p">x</span>: <span class="t">Bool</span>, <span class="p">a</span>: Array(<span class="t">Bool</span>)) -&gt; <span class="t">Bool</span></code></pre>

Whether `x` is an element of an array of Bools.

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`true` where it is.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([true])
print(array.contains(true, a))
```

```stdout visible = true
true
```

</div>

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

## bool::index_of

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bool::index_of</span>(<span class="p">x</span>: <span class="t">Bool</span>, <span class="p">a</span>: Array(<span class="t">Bool</span>)) -&gt; Option(<span class="t">Int</span>)</code></pre>

The index of the first `x` in an array of Bools.

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of the index, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([true])
print(array.index_of(true, a))
```

```stdout visible = true
Some(0)
```

</div>

<div class="pyk-api">

## char::contains

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::contains</span>(<span class="p">x</span>: Char, <span class="p">a</span>: Array(Char)) -&gt; <span class="t">Bool</span></code></pre>

Whether `x` is an element of an array of Chars.

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`true` where it is.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(['a'])
print(array.contains('a', a))
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

## char::index_of

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::index_of</span>(<span class="p">x</span>: Char, <span class="p">a</span>: Array(Char)) -&gt; Option(<span class="t">Int</span>)</code></pre>

The index of the first `x` in an array of Chars.

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of the index, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(['a'])
print(array.index_of('a', a))
```

```stdout visible = true
Some(0)
```

</div>

<div class="pyk-api">

## char::maximum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::maximum</span>(<span class="p">a</span>: Array(Char)) -&gt; Option(Char)</code></pre>

The greatest Char.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(['b', 'a'])
print(array.maximum(a))
```

```stdout visible = true
Some('b')
```

</div>

<div class="pyk-api">

## char::minimum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::minimum</span>(<span class="p">a</span>: Array(Char)) -&gt; Option(Char)</code></pre>

The smallest Char.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(['b', 'a'])
print(array.minimum(a))
```

```stdout visible = true
Some('a')
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

## char::sort_on

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::sort_on</span>(<span class="p">key</span>: (t) -&gt; Char, <span class="p">a</span>: Array(t)) -&gt; ()</code></pre>

Sorts in place by each element's Char key, `key` called once per element;
equal keys keep their order.

<p class="pyk-api-label">Parameters</p>

- `key`: the Char an element is sorted by.
- `a`: an array to sort.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(["b1", "a2"])
array.sort_on(lam s. s[0], a)
print(a)
```

```stdout visible = true
array(["a2", "b1"])
```

</div>

<div class="pyk-api">

## char::sorted

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::sorted</span>(<span class="p">a</span>: Array(Char)) -&gt; Array(Char)</code></pre>

A new Array of the Chars from smallest to largest; `a` is as it was
(`sort` sorts in place).

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

A new Array.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(['b', 'a'])
print(array.sorted(a), a)
```

```stdout visible = true
array(['a', 'b']) array(['b', 'a'])
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

## contains_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">contains_by</span>(<span class="p">alike</span>: (t, t) -&gt; <span class="t">Bool</span>, <span class="p">x</span>: t, <span class="p">a</span>: Array(t)) -&gt; <span class="t">Bool</span></code></pre>

Whether some element is alike to `x`, by `alike`.

<p class="pyk-api-label">Parameters</p>

- `alike`: whether two elements count as the same.
- `x`: what to look for.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`true` where one is.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([10, 21])
print(array.contains_by(lam (p, q). p % 10 == q % 10, 1, a))
```

```stdout visible = true
true
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

## count

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">count</span>(<span class="p">p</span>: (t) -&gt; <span class="t">Bool</span>, <span class="p">a</span>: Array(t)) -&gt; <span class="t">Int</span></code></pre>

How many elements `p` is true of.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

The count.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1, 2, 3, 4])
print(array.count(lam x. x % 2 == 0, a))
```

```stdout visible = true
2
```

</div>

<div class="pyk-api">

## enumerate

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">enumerate</span>(<span class="p">a</span>: Array(t)) -&gt; Array((<span class="t">Int</span>, t))</code></pre>

Each element with its index.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

A new Array of (index, element) pairs.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(["a", "b"])
print(array.enumerate(a))
```

```stdout visible = true
array([(0, "a"), (1, "b")])
```

</div>

<div class="pyk-api">

## equal_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">equal_by</span>(
    <span class="p">alike</span>: (t, t) -&gt; <span class="t">Bool</span>,
    <span class="p">a</span>: Array(t),
    <span class="p">other</span>: Array(t),
) -&gt; <span class="t">Bool</span></code></pre>

Whether two Arrays are as long and alike element by element, by `alike`.

<p class="pyk-api-label">Parameters</p>

- `alike`: whether two elements count as the same.
- `a`: one Array.
- `other`: the other.

<p class="pyk-api-label">Returns</p>

`true` where they are.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
print(array.equal_by(lam (x, y). x % 2 == y % 2, array([1, 2]), array([3, 4])))
```

```stdout visible = true
true
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

## find

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">find</span>(<span class="p">p</span>: (t) -&gt; <span class="t">Bool</span>, <span class="p">a</span>: Array(t)) -&gt; Option(t)</code></pre>

The first element `p` is true of.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1, 2, 3])
print(array.find(lam x. x > 1, a))
```

```stdout visible = true
Some(2)
```

</div>

<div class="pyk-api">

## find_index

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">find_index</span>(<span class="p">p</span>: (t) -&gt; <span class="t">Bool</span>, <span class="p">a</span>: Array(t)) -&gt; Option(<span class="t">Int</span>)</code></pre>

The index of the first element `p` is true of.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of the index, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1, 2, 3])
print(array.find_index(lam x. x > 1, a))
```

```stdout visible = true
Some(1)
```

</div>

<div class="pyk-api">

## first

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">first</span>(<span class="p">a</span>: Array(t)) -&gt; Option(t)</code></pre>

The first element of an array, where there is one.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([4, 5])
print(array.first(a))
```

```stdout visible = true
Some(4)
```

</div>

<div class="pyk-api">

## flat_map

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">flat_map</span>(<span class="p">f</span>: (t) -&gt; [u], <span class="p">a</span>: Array(t)) -&gt; Array(u)</code></pre>

The lists `f` makes of each element, joined.

<p class="pyk-api-label">Parameters</p>

- `f`: makes a list of one element.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

A new Array.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1, 2])
print(array.flat_map(lam x. [x, x], a))
```

```stdout visible = true
array([1, 1, 2, 2])
```

</div>

<div class="pyk-api">

## float::contains

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::contains</span>(<span class="p">x</span>: <span class="t">Float</span>, <span class="p">a</span>: Array(<span class="t">Float</span>)) -&gt; <span class="t">Bool</span></code></pre>

Whether `x` is an element of an array of Floats.

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`true` where it is.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1.5])
print(array.contains(1.5, a))
```

```stdout visible = true
true
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

## float::index_of

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::index_of</span>(<span class="p">x</span>: <span class="t">Float</span>, <span class="p">a</span>: Array(<span class="t">Float</span>)) -&gt; Option(<span class="t">Int</span>)</code></pre>

The index of the first `x` in an array of Floats.

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of the index, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1.5])
print(array.index_of(1.5, a))
```

```stdout visible = true
Some(0)
```

</div>

<div class="pyk-api">

## float::maximum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::maximum</span>(<span class="p">a</span>: Array(<span class="t">Float</span>)) -&gt; Option(<span class="t">Float</span>)</code></pre>

The greatest Float.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([2.5, -1.0])
print(array.maximum(a))
```

```stdout visible = true
Some(2.5)
```

</div>

<div class="pyk-api">

## float::minimum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::minimum</span>(<span class="p">a</span>: Array(<span class="t">Float</span>)) -&gt; Option(<span class="t">Float</span>)</code></pre>

The smallest Float.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([2.5, -1.0])
print(array.minimum(a))
```

```stdout visible = true
Some(-1.0)
```

</div>

<div class="pyk-api">

## float::product

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::product</span>(<span class="p">a</span>: Array(<span class="t">Float</span>)) -&gt; <span class="t">Float</span></code></pre>

The Floats multiplied.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

The product.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([0.5, 1.5])
print(array.product(a))
```

```stdout visible = true
0.75
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

## float::sort_on

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::sort_on</span>(<span class="p">key</span>: (t) -&gt; <span class="t">Float</span>, <span class="p">a</span>: Array(t)) -&gt; ()</code></pre>

Sorts in place by each element's Float key, `key` called once per element;
equal keys keep their order.

<p class="pyk-api-label">Parameters</p>

- `key`: the Float an element is sorted by.
- `a`: an array to sort.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1.0, 3.0])
array.sort_on(lam x. 0.0 - x, a)
print(a)
```

```stdout visible = true
array([3.0, 1.0])
```

</div>

<div class="pyk-api">

## float::sorted

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::sorted</span>(<span class="p">a</span>: Array(<span class="t">Float</span>)) -&gt; Array(<span class="t">Float</span>)</code></pre>

A new Array of the Floats from smallest to largest; `a` is as it was
(`sort` sorts in place).

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

A new Array.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([2.5, -1.0])
print(array.sorted(a), a)
```

```stdout visible = true
array([-1.0, 2.5]) array([2.5, -1.0])
```

</div>

<div class="pyk-api">

## float::sum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::sum</span>(<span class="p">a</span>: Array(<span class="t">Float</span>)) -&gt; <span class="t">Float</span></code></pre>

The Floats added up.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

The sum.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([0.5, 1.5])
print(array.sum(a))
```

```stdout visible = true
2.0
```

</div>

<div class="pyk-api">

## index_of_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">index_of_by</span>(<span class="p">alike</span>: (t, t) -&gt; <span class="t">Bool</span>, <span class="p">x</span>: t, <span class="p">a</span>: Array(t)) -&gt; Option(<span class="t">Int</span>)</code></pre>

The index of the first element alike to `x`, by `alike`.

<p class="pyk-api-label">Parameters</p>

- `alike`: whether two elements count as the same.
- `x`: what to look for.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of the index, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([10, 21])
print(array.index_of_by(lam (p, q). p % 10 == q % 10, 1, a))
```

```stdout visible = true
Some(1)
```

</div>

<div class="pyk-api">

## int::contains

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::contains</span>(<span class="p">x</span>: <span class="t">Int</span>, <span class="p">a</span>: Array(<span class="t">Int</span>)) -&gt; <span class="t">Bool</span></code></pre>

Whether `x` is an element of an array of Ints.

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`true` where it is.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([3, 1])
print(array.contains(1, a))
```

```stdout visible = true
true
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

## int::index_of

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::index_of</span>(<span class="p">x</span>: <span class="t">Int</span>, <span class="p">a</span>: Array(<span class="t">Int</span>)) -&gt; Option(<span class="t">Int</span>)</code></pre>

The index of the first `x` in an array of Ints.

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of the index, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([3, 1])
print(array.index_of(1, a))
```

```stdout visible = true
Some(1)
```

</div>

<div class="pyk-api">

## int::maximum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::maximum</span>(<span class="p">a</span>: Array(<span class="t">Int</span>)) -&gt; Option(<span class="t">Int</span>)</code></pre>

The greatest Int.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([3, 1, 2])
print(array.maximum(a))
```

```stdout visible = true
Some(3)
```

</div>

<div class="pyk-api">

## int::minimum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::minimum</span>(<span class="p">a</span>: Array(<span class="t">Int</span>)) -&gt; Option(<span class="t">Int</span>)</code></pre>

The smallest Int.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([3, 1, 2])
print(array.minimum(a))
```

```stdout visible = true
Some(1)
```

</div>

<div class="pyk-api">

## int::product

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::product</span>(<span class="p">a</span>: Array(<span class="t">Int</span>)) -&gt; <span class="t">Int</span></code></pre>

The Ints multiplied.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

The product.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1, 2, 3])
print(array.product(a))
```

```stdout visible = true
6
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

## int::sort_on

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::sort_on</span>(<span class="p">key</span>: (t) -&gt; <span class="t">Int</span>, <span class="p">a</span>: Array(t)) -&gt; ()</code></pre>

Sorts in place by each element's Int key, `key` called once per element;
equal keys keep their order.

<p class="pyk-api-label">Parameters</p>

- `key`: the Int an element is sorted by.
- `a`: an array to sort.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(["ccc", "a", "bb"])
array.sort_on(lam s. len(s), a)
print(a)
```

```stdout visible = true
array(["a", "bb", "ccc"])
```

</div>

<div class="pyk-api">

## int::sorted

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::sorted</span>(<span class="p">a</span>: Array(<span class="t">Int</span>)) -&gt; Array(<span class="t">Int</span>)</code></pre>

A new Array of the Ints from smallest to largest; `a` is as it was
(`sort` sorts in place).

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

A new Array.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([3, 1, 2])
print(array.sorted(a), a)
```

```stdout visible = true
array([1, 2, 3]) array([3, 1, 2])
```

</div>

<div class="pyk-api">

## int::sum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::sum</span>(<span class="p">a</span>: Array(<span class="t">Int</span>)) -&gt; <span class="t">Int</span></code></pre>

The Ints added up.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

The sum.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1, 2, 3])
print(array.sum(a))
```

```stdout visible = true
6
```

</div>

<div class="pyk-api">

## is_empty

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">is_empty</span>(<span class="p">a</span>: Array(t)) -&gt; <span class="t">Bool</span></code></pre>

Whether an array has no elements.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

`true` where it has none.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([0])
print(array.is_empty(a))
```

```stdout visible = true
false
```

</div>

<div class="pyk-api">

## last

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">last</span>(<span class="p">a</span>: Array(t)) -&gt; Option(t)</code></pre>

The last element of an array, where there is one.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([4, 5])
print(array.last(a))
```

```stdout visible = true
Some(5)
```

</div>

<div class="pyk-api">

## map_in_place

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">map_in_place</span>(<span class="p">f</span>: (t) -&gt; t, <span class="p">a</span>: Array(t)) -&gt; ()</code></pre>

Replaces each element `x` by `f(x)`, in place, in index order: `fmap`
without a copy.

<p class="pyk-api-label">Parameters</p>

- `f`: makes the new element from the old.
- `a`: an array.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1, 2, 3])
array.map_in_place(lam x. x * x, a)
print(a)
```

```stdout visible = true
array([1, 4, 9])
```

</div>

<div class="pyk-api">

## maximum_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">maximum_by</span>(<span class="p">before</span>: (t, t) -&gt; <span class="t">Bool</span>, <span class="p">a</span>: Array(t)) -&gt; Option(t)</code></pre>

The greatest element, `before(x, y)` saying `x` is smaller; the first of
several equal ones.

<p class="pyk-api-label">Parameters</p>

- `before`: whether its first argument is smaller.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(["ab", "c"])
print(array.maximum_by(lam (x, y). len(x) < len(y), a))
```

```stdout visible = true
Some("ab")
```

</div>

<div class="pyk-api">

## minimum_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">minimum_by</span>(<span class="p">before</span>: (t, t) -&gt; <span class="t">Bool</span>, <span class="p">a</span>: Array(t)) -&gt; Option(t)</code></pre>

The smallest element, `before(x, y)` saying `x` is smaller; the first of
several equal ones.

<p class="pyk-api-label">Parameters</p>

- `before`: whether its first argument is smaller.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(["ab", "c"])
print(array.minimum_by(lam (x, y). len(x) < len(y), a))
```

```stdout visible = true
Some("c")
```

</div>

<div class="pyk-api">

## nth

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">nth</span>(<span class="p">a</span>: Array(t), <span class="p">i</span>: <span class="t">Int</span>) -&gt; Option(t)</code></pre>

Element `i`, where there is one: `a[i]` that does not fail.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.
- `i`: the index.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None` where `i` is outside.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([4, 5])
print(array.nth(a, 1), array.nth(a, 2))
```

```stdout visible = true
Some(5) None
```

</div>

<div class="pyk-api">

## reduce

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">reduce</span>(<span class="p">f</span>: (t, t) -&gt; t, <span class="p">a</span>: Array(t)) -&gt; Option(t)</code></pre>

The elements gathered by `f` from the first, with no starting value.

<p class="pyk-api-label">Parameters</p>

- `f`: combines what is gathered with the next element.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of the result, or `None` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([2, 3, 4])
print(array.reduce(lam (x, y). x * y, a))
```

```stdout visible = true
Some(24)
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

## reversed

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">reversed</span>(<span class="p">a</span>: Array(t)) -&gt; Array(t)</code></pre>

A new Array of the elements in the other order; `a` is as it was.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

A new Array.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([1, 2, 3])
print(array.reversed(a), a)
```

```stdout visible = true
array([3, 2, 1]) array([1, 2, 3])
```

</div>

<div class="pyk-api">

## sort_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sort_by</span>(<span class="p">before</span>: (t, t) -&gt; <span class="t">Bool</span>, <span class="p">a</span>: Array(t)) -&gt; ()</code></pre>

Sorts in place, `before(x, y)` saying `x` goes before `y`; equal ones
keep their order (one merge sort, the same on every target).

<p class="pyk-api-label">Parameters</p>

- `before`: whether its first argument goes first.
- `a`: an array to sort.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(["ccc", "a", "bb"])
array.sort_by(lam (x, y). len(x) < len(y), a)
print(a)
```

```stdout visible = true
array(["a", "bb", "ccc"])
```

</div>

<div class="pyk-api">

## string::contains

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::contains</span>(<span class="p">x</span>: <span class="t">String</span>, <span class="p">a</span>: Array(<span class="t">String</span>)) -&gt; <span class="t">Bool</span></code></pre>

Whether `x` is an element of an array of Strings.

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`true` where it is.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(["a"])
print(array.contains("b", a))
```

```stdout visible = true
false
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

## string::index_of

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::index_of</span>(<span class="p">x</span>: <span class="t">String</span>, <span class="p">a</span>: Array(<span class="t">String</span>)) -&gt; Option(<span class="t">Int</span>)</code></pre>

The index of the first `x` in an array of Strings.

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of the index, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(["a"])
print(array.index_of("b", a))
```

```stdout visible = true
None
```

</div>

<div class="pyk-api">

## string::maximum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::maximum</span>(<span class="p">a</span>: Array(<span class="t">String</span>)) -&gt; Option(<span class="t">String</span>)</code></pre>

The greatest String.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(["b", "a"])
print(array.maximum(a))
```

```stdout visible = true
Some("b")
```

</div>

<div class="pyk-api">

## string::minimum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::minimum</span>(<span class="p">a</span>: Array(<span class="t">String</span>)) -&gt; Option(<span class="t">String</span>)</code></pre>

The smallest String.

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(["b", "a"])
print(array.minimum(a))
```

```stdout visible = true
Some("a")
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

## string::sort_on

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::sort_on</span>(<span class="p">key</span>: (t) -&gt; <span class="t">String</span>, <span class="p">a</span>: Array(t)) -&gt; ()</code></pre>

Sorts in place by each element's String key, `key` called once per element;
equal keys keep their order.

<p class="pyk-api-label">Parameters</p>

- `key`: the String an element is sorted by.
- `a`: an array to sort.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array([(2, "b"), (1, "a")])
array.sort_on(lam p. let (_, s) = p in s, a)
print(a)
```

```stdout visible = true
array([(1, "a"), (2, "b")])
```

</div>

<div class="pyk-api">

## string::sorted

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::sorted</span>(<span class="p">a</span>: Array(<span class="t">String</span>)) -&gt; Array(<span class="t">String</span>)</code></pre>

A new Array of the Strings from smallest to largest; `a` is as it was
(`sort` sorts in place).

<p class="pyk-api-label">Parameters</p>

- `a`: an array.

<p class="pyk-api-label">Returns</p>

A new Array.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
a = array(["b", "a"])
print(array.sorted(a), a)
```

```stdout visible = true
array(["a", "b"]) array(["b", "a"])
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

<div class="pyk-api">

## zip

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">zip</span>(<span class="p">a</span>: Array(t), <span class="p">other</span>: Array(u)) -&gt; Array((t, u))</code></pre>

The elements of two Arrays in pairs, as long as the shorter one.

<p class="pyk-api-label">Parameters</p>

- `a`: the first Array.
- `other`: the second.

<p class="pyk-api-label">Returns</p>

A new Array of pairs.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import array
print(array.zip(array([1, 2]), array(["a", "b", "c"])))
```

```stdout visible = true
array([(1, "a"), (2, "b")])
```

</div>
