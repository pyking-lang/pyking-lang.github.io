---
title: list
description: "Lists: taking parts, searching, combining, counting and sorting them."
---

Lists: taking parts, searching, combining, counting and sorting them.

A list is made by a literal, a comprehension, `list(...)` or
`list_init(...)`, and `len`, `fmap`, `filter`, `foldl`, `foldr`, `any`
and `all` are builtins (PYKING.md, "Lists", "fmap and the folds").
This module is the rest, named as Haskell names them where Haskell,
OCaml and Rust differ. A list is never changed: every function
answers a new one. Where a function is given a function, it comes
first, and the list comes last.

A function that compares elements -- `contains`, `unique`, `sort`,
`maximum` -- is written once for each of Int, Float, String, Char and
Bool where it can be, and once more as `..._by`, taking the comparison
as a function, for every other element type. Floats sort with every
NaN last, and Strings by code point, the same on every target.

```pyking norun
import list
```

<div class="pyk-api">

## bool::contains

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bool::contains</span>(<span class="p">x</span>: <span class="t">Bool</span>, <span class="p">xs</span>: [<span class="t">Bool</span>]) -&gt; <span class="t">Bool</span></code></pre>

Whether `x` is an element of a list of Bools (Haskell's `elem`).

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`true` where it is.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.contains(false, [true, true]))
```

```stdout visible = true
false
```

</div>

<div class="pyk-api">

## bool::group

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bool::group</span>(<span class="p">xs</span>: [<span class="t">Bool</span>]) -&gt; [[<span class="t">Bool</span>]]</code></pre>

The list cut into runs of equal Bools next to each other (Haskell's
`group`).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A list of the runs, in order.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.group([true, false, false]))
```

```stdout visible = true
[[true], [false, false]]
```

</div>

<div class="pyk-api">

## bool::index_of

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bool::index_of</span>(<span class="p">x</span>: <span class="t">Bool</span>, <span class="p">xs</span>: [<span class="t">Bool</span>]) -&gt; Option(<span class="t">Int</span>)</code></pre>

The index of the first `x` in a list of Bools (Haskell's `elemIndex`).

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of the index, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.index_of(false, [true, true]))
```

```stdout visible = true
None
```

</div>

<div class="pyk-api">

## bool::unique

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bool::unique</span>(<span class="p">xs</span>: [<span class="t">Bool</span>]) -&gt; [<span class="t">Bool</span>]</code></pre>

Each Bool once, the first of each, in order (Haskell's `nub`).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list with no element twice.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.unique([true, false, true]))
```

```stdout visible = true
[true, false]
```

</div>

<div class="pyk-api">

## char::contains

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::contains</span>(<span class="p">x</span>: Char, <span class="p">xs</span>: [Char]) -&gt; <span class="t">Bool</span></code></pre>

Whether `x` is an element of a list of Chars (Haskell's `elem`).

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`true` where it is.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.contains('a', ['b', 'a']))
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## char::group

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::group</span>(<span class="p">xs</span>: [Char]) -&gt; [[Char]]</code></pre>

The list cut into runs of equal Chars next to each other (Haskell's
`group`).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A list of the runs, in order.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.group(['x', 'x', 'y']))
```

```stdout visible = true
[['x', 'x'], ['y']]
```

</div>

<div class="pyk-api">

## char::index_of

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::index_of</span>(<span class="p">x</span>: Char, <span class="p">xs</span>: [Char]) -&gt; Option(<span class="t">Int</span>)</code></pre>

The index of the first `x` in a list of Chars (Haskell's `elemIndex`).

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of the index, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.index_of('a', ['b', 'a']))
```

```stdout visible = true
Some(1)
```

</div>

<div class="pyk-api">

## char::maximum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::maximum</span>(<span class="p">xs</span>: [Char]) -&gt; Option(Char)</code></pre>

The greatest Char.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None` for `[]`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.maximum(['c', 'a']))
```

```stdout visible = true
Some('c')
```

</div>

<div class="pyk-api">

## char::minimum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::minimum</span>(<span class="p">xs</span>: [Char]) -&gt; Option(Char)</code></pre>

The smallest Char.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None` for `[]`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.minimum(['c', 'a']))
```

```stdout visible = true
Some('a')
```

</div>

<div class="pyk-api">

## char::sort

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::sort</span>(<span class="p">xs</span>: [Char]) -&gt; [Char]</code></pre>

The Chars from smallest to largest.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list, sorted.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.sort(['c', 'a']))
```

```stdout visible = true
['a', 'c']
```

</div>

<div class="pyk-api">

## char::sort_on

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::sort_on</span>(<span class="p">key</span>: (a) -&gt; Char, <span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

The elements in the order of their Char keys, `key` called once per
element; equal keys keep their order (Haskell's `sortOn`).

<p class="pyk-api-label">Parameters</p>

- `key`: the Char an element is sorted by.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list, sorted.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.sort_on(lam s. s[0], ["b1", "a2"]))
```

```stdout visible = true
["a2", "b1"]
```

</div>

<div class="pyk-api">

## char::unique

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char::unique</span>(<span class="p">xs</span>: [Char]) -&gt; [Char]</code></pre>

Each Char once, the first of each, in order (Haskell's `nub`).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list with no element twice.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.unique(['x', 'x']))
```

```stdout visible = true
['x']
```

</div>

<div class="pyk-api">

## chunks

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">chunks</span>(<span class="p">n</span>: <span class="t">Int</span>, <span class="p">xs</span>: [a]) -&gt; [[a]]</code></pre>

The list cut into pieces of `n` elements, the last perhaps shorter
(Rust's `chunks`). `n` must be above 0.

<p class="pyk-api-label">Parameters</p>

- `n`: how long each piece is.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A list of the pieces, in order.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.chunks(2, [1, 2, 3, 4, 5]))
```

```stdout visible = true
[[1, 2], [3, 4], [5]]
```

</div>

<div class="pyk-api">

## contains_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">contains_by</span>(<span class="p">alike</span>: (a, a) -&gt; <span class="t">Bool</span>, <span class="p">x</span>: a, <span class="p">xs</span>: [a]) -&gt; <span class="t">Bool</span></code></pre>

Whether some element is alike to `x`, by `alike`.

<p class="pyk-api-label">Parameters</p>

- `alike`: whether two elements count as the same.
- `x`: what to look for.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`true` where one is.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.contains_by(lam (a, b). len(a) == len(b), "xyz", ["ab", "abc"]))
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## count

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">count</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; <span class="t">Int</span></code></pre>

How many elements `p` is true of.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

The count.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.count(lam x. x % 2 == 0, [1, 2, 3, 4]))
```

```stdout visible = true
2
```

</div>

<div class="pyk-api">

## drop

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">drop</span>(<span class="p">n</span>: <span class="t">Int</span>, <span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

Every element after the first `n`.

<p class="pyk-api-label">Parameters</p>

- `n`: how many to leave out.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

The rest of the list.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.drop(2, [1, 2, 3]), list.drop(5, [1]))
```

```stdout visible = true
[3] []
```

</div>

<div class="pyk-api">

## drop_while

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">drop_while</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

The list from the first element `p` is false of.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

What `take_while` leaves.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.drop_while(lam x. x < 3, [1, 2, 3, 1]))
```

```stdout visible = true
[3, 1]
```

</div>

<div class="pyk-api">

## enumerate

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">enumerate</span>(<span class="p">xs</span>: [a]) -&gt; [(<span class="t">Int</span>, a)]</code></pre>

Each element with its index (Rust's `enumerate`).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A list of (index, element) pairs.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.enumerate(["a", "b"]))
```

```stdout visible = true
[(0, "a"), (1, "b")]
```

</div>

<div class="pyk-api">

## equal_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">equal_by</span>(<span class="p">alike</span>: (a, a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a], <span class="p">ys</span>: [a]) -&gt; <span class="t">Bool</span></code></pre>

Whether two lists are as long and alike element by element, by `alike`.

<p class="pyk-api-label">Parameters</p>

- `alike`: whether two elements count as the same.
- `xs`: the first list.
- `ys`: the second.

<p class="pyk-api-label">Returns</p>

`true` where they are.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.equal_by(lam (a, b). a % 2 == b % 2, [1, 2], [3, 4]))
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## find

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">find</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; Option(a)</code></pre>

The first element `p` is true of.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.find(lam x. x > 1, [1, 2, 3]), list.find(lam x. x > 5, [1]))
```

```stdout visible = true
Some(2) None
```

</div>

<div class="pyk-api">

## find_index

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">find_index</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; Option(<span class="t">Int</span>)</code></pre>

The index of the first element `p` is true of (Rust's `position`).

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of the index, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.find_index(lam x. x > 1, [1, 2, 3]))
```

```stdout visible = true
Some(1)
```

</div>

<div class="pyk-api">

## first

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">first</span>(<span class="p">xs</span>: [a]) -&gt; Option(a)</code></pre>

The first element, where there is one (Rust's `first`; Haskell's `head`
fails on `[]`, and this does not).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of the first element, or `None` for `[]`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.first([3, 4]), list.first([]))
```

```stdout visible = true
Some(3) None
```

</div>

<div class="pyk-api">

## flat_map

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">flat_map</span>(<span class="p">f</span>: (a) -&gt; [b], <span class="p">xs</span>: [a]) -&gt; [b]</code></pre>

The lists `f` makes of each element, joined (Haskell's `concatMap`).

<p class="pyk-api-label">Parameters</p>

- `f`: makes a list of one element.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

One list of everything `f` made, in order.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.flat_map(lam x. [x, x * 10], [1, 2]))
```

```stdout visible = true
[1, 10, 2, 20]
```

</div>

<div class="pyk-api">

## flatten

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">flatten</span>(<span class="p">xss</span>: [[a]]) -&gt; [a]</code></pre>

The lists of a list joined into one, in order (Haskell's `concat`).

<p class="pyk-api-label">Parameters</p>

- `xss`: the lists.

<p class="pyk-api-label">Returns</p>

One list of every element.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.flatten([[1, 2], [], [3]]))
```

```stdout visible = true
[1, 2, 3]
```

</div>

<div class="pyk-api">

## float::contains

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::contains</span>(<span class="p">x</span>: <span class="t">Float</span>, <span class="p">xs</span>: [<span class="t">Float</span>]) -&gt; <span class="t">Bool</span></code></pre>

Whether `x` is an element of a list of Floats (Haskell's `elem`).

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`true` where it is.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.contains(0.5, [1.5, 0.5]))
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## float::group

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::group</span>(<span class="p">xs</span>: [<span class="t">Float</span>]) -&gt; [[<span class="t">Float</span>]]</code></pre>

The list cut into runs of equal Floats next to each other (Haskell's
`group`).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A list of the runs, in order.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.group([0.5, 0.5, 1.0]))
```

```stdout visible = true
[[0.5, 0.5], [1.0]]
```

</div>

<div class="pyk-api">

## float::index_of

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::index_of</span>(<span class="p">x</span>: <span class="t">Float</span>, <span class="p">xs</span>: [<span class="t">Float</span>]) -&gt; Option(<span class="t">Int</span>)</code></pre>

The index of the first `x` in a list of Floats (Haskell's `elemIndex`).

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of the index, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.index_of(0.5, [1.5, 0.5]))
```

```stdout visible = true
Some(1)
```

</div>

<div class="pyk-api">

## float::maximum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::maximum</span>(<span class="p">xs</span>: [<span class="t">Float</span>]) -&gt; Option(<span class="t">Float</span>)</code></pre>

The greatest Float, NaN counting as greater than every other Float.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None` for `[]`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.maximum([2.5, float("nan"), -1.0]))
```

```stdout visible = true
Some(nan)
```

</div>

<div class="pyk-api">

## float::minimum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::minimum</span>(<span class="p">xs</span>: [<span class="t">Float</span>]) -&gt; Option(<span class="t">Float</span>)</code></pre>

The smallest Float.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None` for `[]`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.minimum([2.5, float("nan"), -1.0]))
```

```stdout visible = true
Some(-1.0)
```

</div>

<div class="pyk-api">

## float::product

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::product</span>(<span class="p">xs</span>: [<span class="t">Float</span>]) -&gt; <span class="t">Float</span></code></pre>

The Floats multiplied; 1.0 for `[]`.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

The product.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.product([0.5, 1.5, 2.0]))
```

```stdout visible = true
1.5
```

</div>

<div class="pyk-api">

## float::sort

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::sort</span>(<span class="p">xs</span>: [<span class="t">Float</span>]) -&gt; [<span class="t">Float</span>]</code></pre>

The Floats from smallest to largest, every NaN last.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list, sorted.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.sort([2.5, float("nan"), -1.0]))
```

```stdout visible = true
[-1.0, 2.5, nan]
```

</div>

<div class="pyk-api">

## float::sort_on

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::sort_on</span>(<span class="p">key</span>: (a) -&gt; <span class="t">Float</span>, <span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

The elements in the order of their Float keys, `key` called once per
element; equal keys keep their order (Haskell's `sortOn`).

<p class="pyk-api-label">Parameters</p>

- `key`: the Float an element is sorted by.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list, sorted.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.sort_on(lam x. 0.0 - x, [1.0, 3.0, 2.0]))
```

```stdout visible = true
[3.0, 2.0, 1.0]
```

</div>

<div class="pyk-api">

## float::sum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::sum</span>(<span class="p">xs</span>: [<span class="t">Float</span>]) -&gt; <span class="t">Float</span></code></pre>

The Floats added up; 0.0 for `[]`.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

The sum.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.sum([0.5, 1.5, 2.0]), list.sum(list_init(0, lam i. 0.0)))
```

```stdout visible = true
4.0 0.0
```

</div>

<div class="pyk-api">

## float::unique

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::unique</span>(<span class="p">xs</span>: [<span class="t">Float</span>]) -&gt; [<span class="t">Float</span>]</code></pre>

Each Float once, the first of each, in order (Haskell's `nub`).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list with no element twice.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.unique([0.5, 0.5, 1.0]))
```

```stdout visible = true
[0.5, 1.0]
```

</div>

<div class="pyk-api">

## group_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">group_by</span>(<span class="p">alike</span>: (a, a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; [[a]]</code></pre>

The list cut into runs of elements next to each other that are alike, by
`alike` (Haskell's `groupBy`).

<p class="pyk-api-label">Parameters</p>

- `alike`: whether two neighbours belong to one run.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A list of the runs, in order.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.group_by(lam (a, b). a < b, [1, 2, 3, 2, 5]))
```

```stdout visible = true
[[1, 2, 3], [2, 5]]
```

</div>

<div class="pyk-api">

## index_of_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">index_of_by</span>(<span class="p">alike</span>: (a, a) -&gt; <span class="t">Bool</span>, <span class="p">x</span>: a, <span class="p">xs</span>: [a]) -&gt; Option(<span class="t">Int</span>)</code></pre>

The index of the first element alike to `x`, by `alike`.

<p class="pyk-api-label">Parameters</p>

- `alike`: whether two elements count as the same.
- `x`: what to look for.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of the index, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.index_of_by(lam (a, b). a % 10 == b % 10, 3, [21, 13]))
```

```stdout visible = true
Some(1)
```

</div>

<div class="pyk-api">

## int::contains

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::contains</span>(<span class="p">x</span>: <span class="t">Int</span>, <span class="p">xs</span>: [<span class="t">Int</span>]) -&gt; <span class="t">Bool</span></code></pre>

Whether `x` is an element of a list of Ints (Haskell's `elem`).

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`true` where it is.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.contains(2, [3, 1, 2]))
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## int::group

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::group</span>(<span class="p">xs</span>: [<span class="t">Int</span>]) -&gt; [[<span class="t">Int</span>]]</code></pre>

The list cut into runs of equal Ints next to each other (Haskell's
`group`).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A list of the runs, in order.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.group([1, 1, 2, 1]))
```

```stdout visible = true
[[1, 1], [2], [1]]
```

</div>

<div class="pyk-api">

## int::index_of

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::index_of</span>(<span class="p">x</span>: <span class="t">Int</span>, <span class="p">xs</span>: [<span class="t">Int</span>]) -&gt; Option(<span class="t">Int</span>)</code></pre>

The index of the first `x` in a list of Ints (Haskell's `elemIndex`).

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of the index, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.index_of(2, [3, 1, 2]))
```

```stdout visible = true
Some(2)
```

</div>

<div class="pyk-api">

## int::maximum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::maximum</span>(<span class="p">xs</span>: [<span class="t">Int</span>]) -&gt; Option(<span class="t">Int</span>)</code></pre>

The greatest Int.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None` for `[]`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.maximum([3, 1, 2]))
```

```stdout visible = true
Some(3)
```

</div>

<div class="pyk-api">

## int::minimum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::minimum</span>(<span class="p">xs</span>: [<span class="t">Int</span>]) -&gt; Option(<span class="t">Int</span>)</code></pre>

The smallest Int.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None` for `[]`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.minimum([3, 1, 2]))
```

```stdout visible = true
Some(1)
```

</div>

<div class="pyk-api">

## int::product

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::product</span>(<span class="p">xs</span>: [<span class="t">Int</span>]) -&gt; <span class="t">Int</span></code></pre>

The Ints multiplied; 1 for `[]`.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

The product.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.product([1, 2, 3, 4]))
```

```stdout visible = true
24
```

</div>

<div class="pyk-api">

## int::sort

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::sort</span>(<span class="p">xs</span>: [<span class="t">Int</span>]) -&gt; [<span class="t">Int</span>]</code></pre>

The Ints from smallest to largest.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list, sorted.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.sort([3, 1, 2]))
```

```stdout visible = true
[1, 2, 3]
```

</div>

<div class="pyk-api">

## int::sort_on

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::sort_on</span>(<span class="p">key</span>: (a) -&gt; <span class="t">Int</span>, <span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

The elements in the order of their Int keys, `key` called once per
element; equal keys keep their order (Haskell's `sortOn`).

<p class="pyk-api-label">Parameters</p>

- `key`: the Int an element is sorted by.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list, sorted.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.sort_on(lam s. len(s), ["ccc", "a", "bb"]))
```

```stdout visible = true
["a", "bb", "ccc"]
```

</div>

<div class="pyk-api">

## int::sum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::sum</span>(<span class="p">xs</span>: [<span class="t">Int</span>]) -&gt; <span class="t">Int</span></code></pre>

The Ints added up; 0 for `[]`.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

The sum.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.sum([1, 2, 3, 4]), list.sum(list_init(0, lam i. 0)))
```

```stdout visible = true
10 0
```

</div>

<div class="pyk-api">

## int::unique

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::unique</span>(<span class="p">xs</span>: [<span class="t">Int</span>]) -&gt; [<span class="t">Int</span>]</code></pre>

Each Int once, the first of each, in order (Haskell's `nub`).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list with no element twice.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.unique([1, 2, 1, 3, 2]))
```

```stdout visible = true
[1, 2, 3]
```

</div>

<div class="pyk-api">

## intersperse

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">intersperse</span>(<span class="p">x</span>: a, <span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

`x` put between every two elements.

<p class="pyk-api-label">Parameters</p>

- `x`: what goes between.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.intersperse(0, [1, 2, 3]))
```

```stdout visible = true
[1, 0, 2, 0, 3]
```

</div>

<div class="pyk-api">

## is_empty

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">is_empty</span>(<span class="p">xs</span>: [a]) -&gt; <span class="t">Bool</span></code></pre>

Whether the list has no elements (Haskell's `null`).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`true` for `[]`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.is_empty([]), list.is_empty([0]))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## last

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">last</span>(<span class="p">xs</span>: [a]) -&gt; Option(a)</code></pre>

The last element, where there is one.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of the last element, or `None` for `[]`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.last([3, 4]), list.last([]))
```

```stdout visible = true
Some(4) None
```

</div>

<div class="pyk-api">

## maximum_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">maximum_by</span>(<span class="p">before</span>: (a, a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; Option(a)</code></pre>

The greatest element, `before(x, y)` saying `x` is smaller than `y`; the
first of several equal ones.

<p class="pyk-api-label">Parameters</p>

- `before`: whether its first argument is smaller.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None` for `[]`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.maximum_by(lam (a, b). len(a) < len(b), ["ab", "abcd", "efgh"]))
```

```stdout visible = true
Some("abcd")
```

</div>

<div class="pyk-api">

## minimum_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">minimum_by</span>(<span class="p">before</span>: (a, a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; Option(a)</code></pre>

The smallest element, `before(x, y)` saying `x` is smaller than `y`; the
first of several equal ones.

<p class="pyk-api-label">Parameters</p>

- `before`: whether its first argument is smaller.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None` for `[]`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.minimum_by(lam (a, b). len(a) < len(b), ["abc", "d", "e"]))
```

```stdout visible = true
Some("d")
```

</div>

<div class="pyk-api">

## nth

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">nth</span>(<span class="p">xs</span>: [a], <span class="p">i</span>: <span class="t">Int</span>) -&gt; Option(a)</code></pre>

Element `i`, counting from 0, where there is one: `xs[i]` that does not
fail (Rust's `get`).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.
- `i`: the index.

<p class="pyk-api-label">Returns</p>

`Some(xs[i])`, or `None` where `i` is outside the list.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.nth([5, 6, 7], 1), list.nth([5, 6, 7], 3))
```

```stdout visible = true
Some(6) None
```

</div>

<div class="pyk-api">

## partition

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">partition</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; ([a], [a])</code></pre>

The elements `p` is true of, and the ones it is false of, each in order;
`p` is called once per element.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A pair of lists.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.partition(lam x. x > 1, [3, 1, 2, 0]))
```

```stdout visible = true
([3, 2], [1, 0])
```

</div>

<div class="pyk-api">

## reduce

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">reduce</span>(<span class="p">f</span>: (a, a) -&gt; a, <span class="p">xs</span>: [a]) -&gt; Option(a)</code></pre>

The elements gathered by `f` from the first, with no starting value
(Rust's `reduce`, Haskell's `foldl1`).

<p class="pyk-api-label">Parameters</p>

- `f`: combines what is gathered with the next element.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of the result, or `None` for `[]`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.reduce(lam (a, b). a * b, [2, 3, 4]), list.reduce(lam (a, b). a + b, []))
```

```stdout visible = true
Some(24) None
```

</div>

<div class="pyk-api">

## rest

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">rest</span>(<span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

Every element but the first; `[]` for `[]` (Haskell's `tail` fails there).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

The list without its first element.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.rest([1, 2, 3]), list.rest([]))
```

```stdout visible = true
[2, 3] []
```

</div>

<div class="pyk-api">

## reverse

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">reverse</span>(<span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

The elements in the other order.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list, last element first.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.reverse([1, 2, 3]))
```

```stdout visible = true
[3, 2, 1]
```

</div>

<div class="pyk-api">

## scanl

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">scanl</span>(<span class="p">f</span>: (b, a) -&gt; b, <span class="p">init</span>: b, <span class="p">xs</span>: [a]) -&gt; [b]</code></pre>

Every value `foldl` gathers on the way, `init` first (Haskell's `scanl`).

<p class="pyk-api-label">Parameters</p>

- `f`: as `foldl`'s.
- `init`: the first value.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A list one longer than `xs`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.scanl(lam (acc, x). acc + x, 0, [1, 2, 3]))
```

```stdout visible = true
[0, 1, 3, 6]
```

</div>

<div class="pyk-api">

## scanr

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">scanr</span>(<span class="p">f</span>: (a, b) -&gt; b, <span class="p">init</span>: b, <span class="p">xs</span>: [a]) -&gt; [b]</code></pre>

Every value `foldr` gathers on the way, `init` last (Haskell's `scanr`).

<p class="pyk-api-label">Parameters</p>

- `f`: as `foldr`'s.
- `init`: the last value.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A list one longer than `xs`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.scanr(lam (x, acc). x + acc, 0, [1, 2, 3]))
```

```stdout visible = true
[6, 5, 3, 0]
```

</div>

<div class="pyk-api">

## sort_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sort_by</span>(<span class="p">before</span>: (a, a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

The elements in order, `before(x, y)` saying `x` goes before `y`; equal
ones keep their order (a stable merge sort, the same on every target).

<p class="pyk-api-label">Parameters</p>

- `before`: whether its first argument goes first.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list, sorted.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.sort_by(lam (a, b). len(a) < len(b), ["ccc", "a", "bb", "d"]))
```

```stdout visible = true
["a", "d", "bb", "ccc"]
```

</div>

<div class="pyk-api">

## span

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">span</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; ([a], [a])</code></pre>

`take_while` and `drop_while` at once, `p` called once per element it
looks at.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A pair of lists.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.span(lam x. x % 2 == 1, [1, 3, 4, 5]))
```

```stdout visible = true
([1, 3], [4, 5])
```

</div>

<div class="pyk-api">

## split_at

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">split_at</span>(<span class="p">n</span>: <span class="t">Int</span>, <span class="p">xs</span>: [a]) -&gt; ([a], [a])</code></pre>

The first `n` elements, and the rest.

<p class="pyk-api-label">Parameters</p>

- `n`: where to split.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A pair of lists.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.split_at(1, [1, 2, 3]))
```

```stdout visible = true
([1], [2, 3])
```

</div>

<div class="pyk-api">

## string::contains

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::contains</span>(<span class="p">x</span>: <span class="t">String</span>, <span class="p">xs</span>: [<span class="t">String</span>]) -&gt; <span class="t">Bool</span></code></pre>

Whether `x` is an element of a list of Strings (Haskell's `elem`).

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`true` where it is.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.contains("a", ["b", "a"]))
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## string::group

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::group</span>(<span class="p">xs</span>: [<span class="t">String</span>]) -&gt; [[<span class="t">String</span>]]</code></pre>

The list cut into runs of equal Strings next to each other (Haskell's
`group`).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A list of the runs, in order.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.group(["a", "a", "b"]))
```

```stdout visible = true
[["a", "a"], ["b"]]
```

</div>

<div class="pyk-api">

## string::index_of

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::index_of</span>(<span class="p">x</span>: <span class="t">String</span>, <span class="p">xs</span>: [<span class="t">String</span>]) -&gt; Option(<span class="t">Int</span>)</code></pre>

The index of the first `x` in a list of Strings (Haskell's `elemIndex`).

<p class="pyk-api-label">Parameters</p>

- `x`: what to look for.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of the index, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.index_of("a", ["b", "a"]))
```

```stdout visible = true
Some(1)
```

</div>

<div class="pyk-api">

## string::maximum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::maximum</span>(<span class="p">xs</span>: [<span class="t">String</span>]) -&gt; Option(<span class="t">String</span>)</code></pre>

The greatest String.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None` for `[]`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.maximum(["b", "ab", "a"]))
```

```stdout visible = true
Some("b")
```

</div>

<div class="pyk-api">

## string::minimum

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::minimum</span>(<span class="p">xs</span>: [<span class="t">String</span>]) -&gt; Option(<span class="t">String</span>)</code></pre>

The smallest String.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

`Some` of it, or `None` for `[]`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.minimum(["b", "ab", "a"]))
```

```stdout visible = true
Some("a")
```

</div>

<div class="pyk-api">

## string::sort

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::sort</span>(<span class="p">xs</span>: [<span class="t">String</span>]) -&gt; [<span class="t">String</span>]</code></pre>

The Strings from smallest to largest, by code point.

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list, sorted.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.sort(["b", "ab", "a"]))
```

```stdout visible = true
["a", "ab", "b"]
```

</div>

<div class="pyk-api">

## string::sort_on

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::sort_on</span>(<span class="p">key</span>: (a) -&gt; <span class="t">String</span>, <span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

The elements in the order of their String keys, `key` called once per
element; equal keys keep their order (Haskell's `sortOn`).

<p class="pyk-api-label">Parameters</p>

- `key`: the String an element is sorted by.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list, sorted.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.sort_on(lam p. let (name, _) = p in name, [("bo", 1), ("ann", 2)]))
```

```stdout visible = true
[("ann", 2), ("bo", 1)]
```

</div>

<div class="pyk-api">

## string::unique

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::unique</span>(<span class="p">xs</span>: [<span class="t">String</span>]) -&gt; [<span class="t">String</span>]</code></pre>

Each String once, the first of each, in order (Haskell's `nub`).

<p class="pyk-api-label">Parameters</p>

- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list with no element twice.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.unique(["a", "b", "a"]))
```

```stdout visible = true
["a", "b"]
```

</div>

<div class="pyk-api">

## take

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">take</span>(<span class="p">n</span>: <span class="t">Int</span>, <span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

The first `n` elements, or all of them where there are fewer.

<p class="pyk-api-label">Parameters</p>

- `n`: how many.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A list of at most `n` elements.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.take(2, [1, 2, 3]), list.take(5, [1]))
```

```stdout visible = true
[1, 2] [1]
```

</div>

<div class="pyk-api">

## take_while

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">take_while</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

The elements from the start for as long as `p` is true of them.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

The longest start of `xs` that `p` is true of.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.take_while(lam x. x < 3, [1, 2, 3, 1]))
```

```stdout visible = true
[1, 2]
```

</div>

<div class="pyk-api">

## unfold

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">unfold</span>(<span class="p">seed</span>: s, <span class="p">f</span>: (s) -&gt; Option((a, s))) -&gt; [a]</code></pre>

The elements `f` makes from `seed`, one after another, until it answers
`None` (Haskell's `unfoldr`).

<p class="pyk-api-label">Parameters</p>

- `seed`: what the first element is made from.
- `f`: answers an element and the next seed, or `None` to stop.

<p class="pyk-api-label">Returns</p>

A list of what `f` made.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.unfold(1, lam n. if n > 100 then None else Some((n, n * 3))))
```

```stdout visible = true
[1, 3, 9, 27, 81]
```

</div>

<div class="pyk-api">

## unique_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">unique_by</span>(<span class="p">alike</span>: (a, a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

Each element once, by `alike`: the first of each, in order.

<p class="pyk-api-label">Parameters</p>

- `alike`: whether two elements count as the same.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A new list with no two alike.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.unique_by(lam (a, b). a % 3 == b % 3, [1, 2, 4, 3, 5]))
```

```stdout visible = true
[1, 2, 3]
```

</div>

<div class="pyk-api">

## unzip

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">unzip</span>(<span class="p">ps</span>: [(a, b)]) -&gt; ([a], [b])</code></pre>

A list of pairs as a pair of lists.

<p class="pyk-api-label">Parameters</p>

- `ps`: the pairs.

<p class="pyk-api-label">Returns</p>

The first parts, and the second parts.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.unzip([(1, "a"), (2, "b")]))
```

```stdout visible = true
([1, 2], ["a", "b"])
```

</div>

<div class="pyk-api">

## windows

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">windows</span>(<span class="p">n</span>: <span class="t">Int</span>, <span class="p">xs</span>: [a]) -&gt; [[a]]</code></pre>

Every run of `n` elements in a row, in order (Rust's `windows`). `n`
must be above 0.

<p class="pyk-api-label">Parameters</p>

- `n`: how long each run is.
- `xs`: the list.

<p class="pyk-api-label">Returns</p>

A list of the runs; none where the list is shorter than `n`.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.windows(2, [1, 2, 3]))
```

```stdout visible = true
[[1, 2], [2, 3]]
```

</div>

<div class="pyk-api">

## zip

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">zip</span>(<span class="p">xs</span>: [a], <span class="p">ys</span>: [b]) -&gt; [(a, b)]</code></pre>

The elements of two lists in pairs, as long as the shorter list.

<p class="pyk-api-label">Parameters</p>

- `xs`: the first list.
- `ys`: the second.

<p class="pyk-api-label">Returns</p>

A list of pairs.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.zip([1, 2, 3], ["a", "b"]))
```

```stdout visible = true
[(1, "a"), (2, "b")]
```

</div>

<div class="pyk-api">

## zip_with

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">zip_with</span>(<span class="p">f</span>: (a, b) -&gt; c, <span class="p">xs</span>: [a], <span class="p">ys</span>: [b]) -&gt; [c]</code></pre>

`f` of the elements of two lists, in pairs, as long as the shorter list
(Haskell's `zipWith`).

<p class="pyk-api-label">Parameters</p>

- `f`: combines one element of each.
- `xs`: the first list.
- `ys`: the second.

<p class="pyk-api-label">Returns</p>

A list of what `f` answered.

<p class="pyk-api-label">Example</p>

```pyking
import list
print(list.zip_with(lam (x, y). x * y, [1, 2, 3], [4, 5, 6]))
```

```stdout visible = true
[4, 10, 18]
```

</div>
