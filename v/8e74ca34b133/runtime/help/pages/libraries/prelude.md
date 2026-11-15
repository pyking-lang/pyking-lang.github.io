---
title: prelude
description: "The builtins written in Pyking: `fmap`, `filter`, `foldl`, `foldr`, `any` and `all` over every collection, and the forms of `list`, `list_init`, `dynarray`, `dynarray_init`, `map_init` and `mutmap_init` that make one by calling a function or convert another."
---

The builtins written in Pyking: `fmap`, `filter`, `foldl`, `foldr`,
`any` and `all` over every collection, and the forms of `list`,
`list_init`, `dynarray`, `dynarray_init`, `map_init` and `mutmap_init`
that make one by calling a function or convert another.

Nothing imports this module: a module calling one of those names, and
binding none of them itself, has every one of the definitions below
under its `::` name, as if it began `from prelude import list::fmap,
...` (PYKING.md, "fmap and the folds"). Each name is an overload set,
and a call is resolved by the kind of collection it is given -- which
has to be known where the call is, written or worked out. A module's
own `filter` or `list` means itself.

Each function answers a **new** collection of the kind it was given,
and making an array, a DynArray or a MutMap needs `use mutation` in
the calling module. A Map's and a MutMap's elements here are its
values. The functions call `f` once per element, in order: `foldr`
from the last, and `any` and `all` stopping at the first answer that
decides.

```pyking norun
import prelude
```

<div class="pyk-api">

## array::all

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">array::all</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: Array(a)) -&gt; <span class="t">Bool</span></code></pre>

`all(p, xs)` on an array: whether `p` is true of every element,
stopping at the first that it is not.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: an array.

<p class="pyk-api-label">Returns</p>

`false` where `p` is false of one, `true` where there is none.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = array([1, 2, 3])
print(all(lam x. x > 0, xs), all(lam x. x > 1, xs))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## array::any

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">array::any</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: Array(a)) -&gt; <span class="t">Bool</span></code></pre>

`any(p, xs)` on an array: whether `p` is true of some element,
stopping at the first that it is.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: an array.

<p class="pyk-api-label">Returns</p>

`true` where `p` is true of one, `false` where there is none.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = array([1, 2, 3])
print(any(lam x. x > 2, xs), any(lam x. x > 5, xs))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## array::filter

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">array::filter</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: Array(a)) -&gt; Array(a)</code></pre>

`filter(p, xs)` on an array: what `p` is true of.

<p class="pyk-api-label">Parameters</p>

- `p`: the test, called once per element, in order.
- `xs`: an array.

<p class="pyk-api-label">Returns</p>

A new array of the elements `p` is true of, in order.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = array([1, 2, 3])
print(filter(lam x. x % 2 == 1, xs))
```

```stdout visible = true
array([1, 3])
```

</div>

<div class="pyk-api">

## array::fmap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">array::fmap</span>(<span class="p">f</span>: (a) -&gt; b, <span class="p">xs</span>: Array(a)) -&gt; Array(b)</code></pre>

`fmap(f, xs)` on an array: `f` applied to each element, as Haskell's
`fmap` and Rust's `map` are.

<p class="pyk-api-label">Parameters</p>

- `f`: the function, called once per element, in order.
- `xs`: an array.

<p class="pyk-api-label">Returns</p>

A new array of `f(x)` for each element `x`, in order.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = array([1, 2, 3])
print(fmap(lam x. x * 10, xs))
```

```stdout visible = true
array([10, 20, 30])
```

</div>

<div class="pyk-api">

## array::foldl

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">array::foldl</span>(<span class="p">f</span>: (b, a) -&gt; b, <span class="p">init</span>: b, <span class="p">xs</span>: Array(a)) -&gt; b</code></pre>

`foldl(f, init, xs)` on an array: `f(...f(f(init, x1), x2)..., xn)`, the
elements from the first.

<p class="pyk-api-label">Parameters</p>

- `f`: takes what is gathered so far and the next element.
- `init`: what is gathered before any element.
- `xs`: an array.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = array([1, 2, 3])
print(foldl(lam (acc, x). acc * 10 + x, 0, xs))
```

```stdout visible = true
123
```

</div>

<div class="pyk-api">

## array::foldr

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">array::foldr</span>(<span class="p">f</span>: (a, b) -&gt; b, <span class="p">init</span>: b, <span class="p">xs</span>: Array(a)) -&gt; b</code></pre>

`foldr(f, init, xs)` on an array: `f(x1, f(x2, ...f(xn, init)))`, the
elements from the last.

<p class="pyk-api-label">Parameters</p>

- `f`: takes the next element, from the end, and what is gathered so far.
- `init`: what is gathered before any element.
- `xs`: an array.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = array([1, 2, 3])
print(foldr(lam (x, acc). acc * 10 + x, 0, xs))
```

```stdout visible = true
321
```

</div>

<div class="pyk-api">

## array::list

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">array::list</span>(<span class="p">xs</span>: Array(a)) -&gt; [a]</code></pre>

`list(xs)` of an array: its elements as they are now.

<p class="pyk-api-label">Parameters</p>

- `xs`: an array.

<p class="pyk-api-label">Returns</p>

A new list.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
print(list(array(3, 'a')))
```

```stdout visible = true
['a', 'a', 'a']
```

</div>

<div class="pyk-api">

## dynarray::all

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">dynarray::all</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: DynArray(a)) -&gt; <span class="t">Bool</span></code></pre>

`all(p, xs)` on a DynArray: whether `p` is true of every element,
stopping at the first that it is not.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: a DynArray.

<p class="pyk-api-label">Returns</p>

`false` where `p` is false of one, `true` where there is none.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = dynarray([1, 2, 3])
print(all(lam x. x > 0, xs), all(lam x. x > 1, xs))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## dynarray::any

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">dynarray::any</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: DynArray(a)) -&gt; <span class="t">Bool</span></code></pre>

`any(p, xs)` on a DynArray: whether `p` is true of some element,
stopping at the first that it is.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: a DynArray.

<p class="pyk-api-label">Returns</p>

`true` where `p` is true of one, `false` where there is none.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = dynarray([1, 2, 3])
print(any(lam x. x > 2, xs), any(lam x. x > 5, xs))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## dynarray::filter

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">dynarray::filter</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: DynArray(a)) -&gt; DynArray(a)</code></pre>

`filter(p, xs)` on a DynArray: what `p` is true of.

<p class="pyk-api-label">Parameters</p>

- `p`: the test, called once per element, in order.
- `xs`: a DynArray.

<p class="pyk-api-label">Returns</p>

A new DynArray of the elements `p` is true of, in order.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = dynarray([1, 2, 3])
print(filter(lam x. x % 2 == 1, xs))
```

```stdout visible = true
dynarray([1, 3])
```

</div>

<div class="pyk-api">

## dynarray::fmap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">dynarray::fmap</span>(<span class="p">f</span>: (a) -&gt; b, <span class="p">xs</span>: DynArray(a)) -&gt; DynArray(b)</code></pre>

`fmap(f, xs)` on a DynArray: `f` applied to each element, as Haskell's
`fmap` and Rust's `map` are.

<p class="pyk-api-label">Parameters</p>

- `f`: the function, called once per element, in order.
- `xs`: a DynArray.

<p class="pyk-api-label">Returns</p>

A new DynArray of `f(x)` for each element `x`, in order.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = dynarray([1, 2, 3])
print(fmap(lam x. x * 10, xs))
```

```stdout visible = true
dynarray([10, 20, 30])
```

</div>

<div class="pyk-api">

## dynarray::foldl

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">dynarray::foldl</span>(<span class="p">f</span>: (b, a) -&gt; b, <span class="p">init</span>: b, <span class="p">xs</span>: DynArray(a)) -&gt; b</code></pre>

`foldl(f, init, xs)` on a DynArray: `f(...f(f(init, x1), x2)..., xn)`, the
elements from the first.

<p class="pyk-api-label">Parameters</p>

- `f`: takes what is gathered so far and the next element.
- `init`: what is gathered before any element.
- `xs`: a DynArray.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = dynarray([1, 2, 3])
print(foldl(lam (acc, x). acc * 10 + x, 0, xs))
```

```stdout visible = true
123
```

</div>

<div class="pyk-api">

## dynarray::foldr

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">dynarray::foldr</span>(<span class="p">f</span>: (a, b) -&gt; b, <span class="p">init</span>: b, <span class="p">xs</span>: DynArray(a)) -&gt; b</code></pre>

`foldr(f, init, xs)` on a DynArray: `f(x1, f(x2, ...f(xn, init)))`, the
elements from the last.

<p class="pyk-api-label">Parameters</p>

- `f`: takes the next element, from the end, and what is gathered so far.
- `init`: what is gathered before any element.
- `xs`: a DynArray.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = dynarray([1, 2, 3])
print(foldr(lam (x, acc). acc * 10 + x, 0, xs))
```

```stdout visible = true
321
```

</div>

<div class="pyk-api">

## dynarray::list

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">dynarray::list</span>(<span class="p">xs</span>: DynArray(a)) -&gt; [a]</code></pre>

`list(xs)` of a DynArray: its elements as they are now.

<p class="pyk-api-label">Parameters</p>

- `xs`: a DynArray.

<p class="pyk-api-label">Returns</p>

A new list.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
print(list(dynarray([1, 2])))
```

```stdout visible = true
[1, 2]
```

</div>

<div class="pyk-api">

## fill::dynarray

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">fill::dynarray</span>(<span class="p">n</span>: <span class="t">Int</span>, <span class="p">v</span>: a) -&gt; DynArray(a)</code></pre>

`dynarray(n, v)`: a DynArray of `n` copies of `v`. Needs `use mutation`.
A negative `n` is a runtime error.

<p class="pyk-api-label">Parameters</p>

- `n`: how many.
- `v`: the value, worked out once.

<p class="pyk-api-label">Returns</p>

A new DynArray of `n` elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
v = dynarray(2, 0)
push(v, 7)
print(v)
```

```stdout visible = true
dynarray([0, 0, 7])
```

</div>

<div class="pyk-api">

## fill::list

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">fill::list</span>(<span class="p">n</span>: <span class="t">Int</span>, <span class="p">v</span>: a) -&gt; [a]</code></pre>

`list(n, v)`: `n` copies of `v` (Haskell's `replicate`). A negative `n` is
a runtime error.

<p class="pyk-api-label">Parameters</p>

- `n`: how many.
- `v`: the value, worked out once.

<p class="pyk-api-label">Returns</p>

A list of `n` elements.

<p class="pyk-api-label">Example</p>

```pyking
print(list(3, 'a'), list(0, 1))
```

```stdout visible = true
['a', 'a', 'a'] []
```

</div>

<div class="pyk-api">

## init::dynarray_init

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">init::dynarray_init</span>(<span class="p">n</span>: <span class="t">Int</span>, <span class="p">f</span>: (<span class="t">Int</span>) -&gt; a) -&gt; DynArray(a)</code></pre>

`dynarray_init(n, f)`: element `i` is `f(i)`, as `array_init`. Needs `use
mutation`. A negative `n` is a runtime error.

<p class="pyk-api-label">Parameters</p>

- `n`: how many.
- `f`: makes element `i`.

<p class="pyk-api-label">Returns</p>

A new DynArray of `n` elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
print(dynarray_init(4, lam i. i * 2))
```

```stdout visible = true
dynarray([0, 2, 4, 6])
```

</div>

<div class="pyk-api">

## init::list_init

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">init::list_init</span>(<span class="p">n</span>: <span class="t">Int</span>, <span class="p">f</span>: (<span class="t">Int</span>) -&gt; a) -&gt; [a]</code></pre>

`list_init(n, f)`: element `i` is `f(i)`, called in index order (OCaml's
`List.init`). A negative `n` is a runtime error.

<p class="pyk-api-label">Parameters</p>

- `n`: how many.
- `f`: makes element `i`.

<p class="pyk-api-label">Returns</p>

A list of `n` elements.

<p class="pyk-api-label">Example</p>

```pyking
print(list_init(5, lam i. i * i))
```

```stdout visible = true
[0, 1, 4, 9, 16]
```

</div>

<div class="pyk-api">

## keys::map_init

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">keys::map_init</span>(<span class="p">keys</span>: [k], <span class="p">f</span>: (k) -&gt; v) -&gt; Map(k, v)</code></pre>

`map_init(keys, f)`: each key `k` maps to `f(k)`, in the order of `keys`;
a key written twice keeps its first place (Haskell's `Map.fromSet`).

<p class="pyk-api-label">Parameters</p>

- `keys`: the keys.
- `f`: makes a key's value.

<p class="pyk-api-label">Returns</p>

A new Map.

<p class="pyk-api-label">Example</p>

```pyking
print(map_init(["ann", "bo"], lam name. len(name)))
```

```stdout visible = true
map([("ann", 3), ("bo", 2)])
```

</div>

<div class="pyk-api">

## keys::mutmap_init

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">keys::mutmap_init</span>(<span class="p">keys</span>: [k], <span class="p">f</span>: (k) -&gt; v) -&gt; MutMap(k, v)</code></pre>

`mutmap_init(keys, f)`: as `map_init`, a MutMap. Needs `use mutation`.

<p class="pyk-api-label">Parameters</p>

- `keys`: the keys.
- `f`: makes a key's value.

<p class="pyk-api-label">Returns</p>

A new MutMap.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
counts = mutmap_init(["a", "b"], lam _. 0)
counts["a"] += 1
print(counts)
```

```stdout visible = true
mutmap([("a", 1), ("b", 0)])
```

</div>

<div class="pyk-api">

## list::all

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">list::all</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; <span class="t">Bool</span></code></pre>

`all(p, xs)` on a list: whether `p` is true of every element,
stopping at the first that it is not.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: a list.

<p class="pyk-api-label">Returns</p>

`false` where `p` is false of one, `true` where there is none.

<p class="pyk-api-label">Example</p>

```pyking
xs = [1, 2, 3]
print(all(lam x. x > 0, xs), all(lam x. x > 1, xs))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## list::any

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">list::any</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; <span class="t">Bool</span></code></pre>

`any(p, xs)` on a list: whether `p` is true of some element,
stopping at the first that it is.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: a list.

<p class="pyk-api-label">Returns</p>

`true` where `p` is true of one, `false` where there is none.

<p class="pyk-api-label">Example</p>

```pyking
xs = [1, 2, 3]
print(any(lam x. x > 2, xs), any(lam x. x > 5, xs))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## list::filter

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">list::filter</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

`filter(p, xs)` on a list: what `p` is true of.

<p class="pyk-api-label">Parameters</p>

- `p`: the test, called once per element, in order.
- `xs`: a list.

<p class="pyk-api-label">Returns</p>

A new list of the elements `p` is true of, in order.

<p class="pyk-api-label">Example</p>

```pyking
xs = [1, 2, 3]
print(filter(lam x. x % 2 == 1, xs))
```

```stdout visible = true
[1, 3]
```

</div>

<div class="pyk-api">

## list::fmap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">list::fmap</span>(<span class="p">f</span>: (a) -&gt; b, <span class="p">xs</span>: [a]) -&gt; [b]</code></pre>

`fmap(f, xs)` on a list: `f` applied to each element, as Haskell's
`fmap` and Rust's `map` are.

<p class="pyk-api-label">Parameters</p>

- `f`: the function, called once per element, in order.
- `xs`: a list.

<p class="pyk-api-label">Returns</p>

A new list of `f(x)` for each element `x`, in order.

<p class="pyk-api-label">Example</p>

```pyking
xs = [1, 2, 3]
print(fmap(lam x. x * 10, xs))
```

```stdout visible = true
[10, 20, 30]
```

</div>

<div class="pyk-api">

## list::foldl

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">list::foldl</span>(<span class="p">f</span>: (b, a) -&gt; b, <span class="p">init</span>: b, <span class="p">xs</span>: [a]) -&gt; b</code></pre>

`foldl(f, init, xs)` on a list: `f(...f(f(init, x1), x2)..., xn)`, the
elements from the first.

<p class="pyk-api-label">Parameters</p>

- `f`: takes what is gathered so far and the next element.
- `init`: what is gathered before any element.
- `xs`: a list.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
xs = [1, 2, 3]
print(foldl(lam (acc, x). acc * 10 + x, 0, xs))
```

```stdout visible = true
123
```

</div>

<div class="pyk-api">

## list::foldr

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">list::foldr</span>(<span class="p">f</span>: (a, b) -&gt; b, <span class="p">init</span>: b, <span class="p">xs</span>: [a]) -&gt; b</code></pre>

`foldr(f, init, xs)` on a list: `f(x1, f(x2, ...f(xn, init)))`, the
elements from the last.

<p class="pyk-api-label">Parameters</p>

- `f`: takes the next element, from the end, and what is gathered so far.
- `init`: what is gathered before any element.
- `xs`: a list.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
xs = [1, 2, 3]
print(foldr(lam (x, acc). acc * 10 + x, 0, xs))
```

```stdout visible = true
321
```

</div>

<div class="pyk-api">

## list::list

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">list::list</span>(<span class="p">xs</span>: [a]) -&gt; [a]</code></pre>

`list(xs)` of a list: itself, which is never changed.

<p class="pyk-api-label">Parameters</p>

- `xs`: a list.

<p class="pyk-api-label">Returns</p>

A new list.

<p class="pyk-api-label">Example</p>

```pyking
print(list([1, 2]))
```

```stdout visible = true
[1, 2]
```

</div>

<div class="pyk-api">

## map::all

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">map::all</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">m</span>: Map(k, a)) -&gt; <span class="t">Bool</span></code></pre>

`all(p, m)` on a Map: whether `p` is true of every value,
stopping at the first that it is not.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `m`: a Map.

<p class="pyk-api-label">Returns</p>

`false` where `p` is false of one, `true` where there is none.

<p class="pyk-api-label">Example</p>

```pyking
m = map([("a", 1), ("b", 2), ("c", 3)])
print(all(lam x. x > 0, m), all(lam x. x > 1, m))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## map::any

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">map::any</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">m</span>: Map(k, a)) -&gt; <span class="t">Bool</span></code></pre>

`any(p, m)` on a Map: whether `p` is true of some value,
stopping at the first that it is.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `m`: a Map.

<p class="pyk-api-label">Returns</p>

`true` where `p` is true of one, `false` where there is none.

<p class="pyk-api-label">Example</p>

```pyking
m = map([("a", 1), ("b", 2), ("c", 3)])
print(any(lam x. x > 2, m), any(lam x. x > 5, m))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## map::filter

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">map::filter</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">m</span>: Map(k, a)) -&gt; Map(k, a)</code></pre>

`filter(p, m)` on a Map: what `p` is true of, by value.

<p class="pyk-api-label">Parameters</p>

- `p`: the test, called once per element, in order.
- `m`: a Map.

<p class="pyk-api-label">Returns</p>

A new Map of the entries whose value `p` is true of, in order.

<p class="pyk-api-label">Example</p>

```pyking
m = map([("a", 1), ("b", 2), ("c", 3)])
print(filter(lam x. x % 2 == 1, m))
```

```stdout visible = true
map([("a", 1), ("c", 3)])
```

</div>

<div class="pyk-api">

## map::fmap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">map::fmap</span>(<span class="p">f</span>: (a) -&gt; b, <span class="p">m</span>: Map(k, a)) -&gt; Map(k, b)</code></pre>

`fmap(f, m)` on a Map: `f` applied to each value, as Haskell's
`fmap` and Rust's `map` are.

<p class="pyk-api-label">Parameters</p>

- `f`: the function, called once per element, in order.
- `m`: a Map.

<p class="pyk-api-label">Returns</p>

A new Map of the same keys, in the same order, each value `v` replaced by `f(v)`.

<p class="pyk-api-label">Example</p>

```pyking
m = map([("a", 1), ("b", 2), ("c", 3)])
print(fmap(lam x. x * 10, m))
```

```stdout visible = true
map([("a", 10), ("b", 20), ("c", 30)])
```

</div>

<div class="pyk-api">

## map::foldl

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">map::foldl</span>(<span class="p">f</span>: (b, a) -&gt; b, <span class="p">init</span>: b, <span class="p">m</span>: Map(k, a)) -&gt; b</code></pre>

`foldl(f, init, m)` on a Map: `f(...f(f(init, x1), x2)..., xn)`, the
values from the first.

<p class="pyk-api-label">Parameters</p>

- `f`: takes what is gathered so far and the next element.
- `init`: what is gathered before any element.
- `m`: a Map.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
m = map([("a", 1), ("b", 2), ("c", 3)])
print(foldl(lam (acc, x). acc * 10 + x, 0, m))
```

```stdout visible = true
123
```

</div>

<div class="pyk-api">

## map::foldr

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">map::foldr</span>(<span class="p">f</span>: (a, b) -&gt; b, <span class="p">init</span>: b, <span class="p">m</span>: Map(k, a)) -&gt; b</code></pre>

`foldr(f, init, m)` on a Map: `f(x1, f(x2, ...f(xn, init)))`, the
values from the last.

<p class="pyk-api-label">Parameters</p>

- `f`: takes the next element, from the end, and what is gathered so far.
- `init`: what is gathered before any element.
- `m`: a Map.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
m = map([("a", 1), ("b", 2), ("c", 3)])
print(foldr(lam (x, acc). acc * 10 + x, 0, m))
```

```stdout visible = true
321
```

</div>

<div class="pyk-api">

## map::list

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">map::list</span>(<span class="p">m</span>: Map(k, v)) -&gt; [(k, v)]</code></pre>

`list(m)` of a Map: its (key, value) pairs, in order.

<p class="pyk-api-label">Parameters</p>

- `m`: a Map.

<p class="pyk-api-label">Returns</p>

A new list.

<p class="pyk-api-label">Example</p>

```pyking
print(list(map([("a", 1), ("b", 2)])))
```

```stdout visible = true
[("a", 1), ("b", 2)]
```

</div>

<div class="pyk-api">

## mutmap::all

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">mutmap::all</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">m</span>: MutMap(k, a)) -&gt; <span class="t">Bool</span></code></pre>

`all(p, m)` on a MutMap: whether `p` is true of every value,
stopping at the first that it is not.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `m`: a MutMap.

<p class="pyk-api-label">Returns</p>

`false` where `p` is false of one, `true` where there is none.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
m = mutmap([("a", 1), ("b", 2), ("c", 3)])
print(all(lam x. x > 0, m), all(lam x. x > 1, m))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## mutmap::any

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">mutmap::any</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">m</span>: MutMap(k, a)) -&gt; <span class="t">Bool</span></code></pre>

`any(p, m)` on a MutMap: whether `p` is true of some value,
stopping at the first that it is.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `m`: a MutMap.

<p class="pyk-api-label">Returns</p>

`true` where `p` is true of one, `false` where there is none.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
m = mutmap([("a", 1), ("b", 2), ("c", 3)])
print(any(lam x. x > 2, m), any(lam x. x > 5, m))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## mutmap::filter

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">mutmap::filter</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">m</span>: MutMap(k, a)) -&gt; MutMap(k, a)</code></pre>

`filter(p, m)` on a MutMap: what `p` is true of, by value.

<p class="pyk-api-label">Parameters</p>

- `p`: the test, called once per element, in order.
- `m`: a MutMap.

<p class="pyk-api-label">Returns</p>

A new MutMap of the entries whose value `p` is true of, in order.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
m = mutmap([("a", 1), ("b", 2), ("c", 3)])
print(filter(lam x. x % 2 == 1, m))
```

```stdout visible = true
mutmap([("a", 1), ("c", 3)])
```

</div>

<div class="pyk-api">

## mutmap::fmap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">mutmap::fmap</span>(<span class="p">f</span>: (a) -&gt; b, <span class="p">m</span>: MutMap(k, a)) -&gt; MutMap(k, b)</code></pre>

`fmap(f, m)` on a MutMap: `f` applied to each value, as Haskell's
`fmap` and Rust's `map` are.

<p class="pyk-api-label">Parameters</p>

- `f`: the function, called once per element, in order.
- `m`: a MutMap.

<p class="pyk-api-label">Returns</p>

A new MutMap of the same keys, in the same order, each value `v` replaced by `f(v)`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
m = mutmap([("a", 1), ("b", 2), ("c", 3)])
print(fmap(lam x. x * 10, m))
```

```stdout visible = true
mutmap([("a", 10), ("b", 20), ("c", 30)])
```

</div>

<div class="pyk-api">

## mutmap::foldl

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">mutmap::foldl</span>(<span class="p">f</span>: (b, a) -&gt; b, <span class="p">init</span>: b, <span class="p">m</span>: MutMap(k, a)) -&gt; b</code></pre>

`foldl(f, init, m)` on a MutMap: `f(...f(f(init, x1), x2)..., xn)`, the
values from the first.

<p class="pyk-api-label">Parameters</p>

- `f`: takes what is gathered so far and the next element.
- `init`: what is gathered before any element.
- `m`: a MutMap.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
m = mutmap([("a", 1), ("b", 2), ("c", 3)])
print(foldl(lam (acc, x). acc * 10 + x, 0, m))
```

```stdout visible = true
123
```

</div>

<div class="pyk-api">

## mutmap::foldr

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">mutmap::foldr</span>(<span class="p">f</span>: (a, b) -&gt; b, <span class="p">init</span>: b, <span class="p">m</span>: MutMap(k, a)) -&gt; b</code></pre>

`foldr(f, init, m)` on a MutMap: `f(x1, f(x2, ...f(xn, init)))`, the
values from the last.

<p class="pyk-api-label">Parameters</p>

- `f`: takes the next element, from the end, and what is gathered so far.
- `init`: what is gathered before any element.
- `m`: a MutMap.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
m = mutmap([("a", 1), ("b", 2), ("c", 3)])
print(foldr(lam (x, acc). acc * 10 + x, 0, m))
```

```stdout visible = true
321
```

</div>

<div class="pyk-api">

## mutmap::list

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">mutmap::list</span>(<span class="p">m</span>: MutMap(k, v)) -&gt; [(k, v)]</code></pre>

`list(m)` of a MutMap: its (key, value) pairs, in order.

<p class="pyk-api-label">Parameters</p>

- `m`: a MutMap.

<p class="pyk-api-label">Returns</p>

A new list.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
print(list(mutmap([("a", 1)])))
```

```stdout visible = true
[("a", 1)]
```

</div>

<div class="pyk-api">

## option::all

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">option::all</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">o</span>: Option(a)) -&gt; <span class="t">Bool</span></code></pre>

`all(p, o)` on an Option: whether `p` is true of every value it holds,
stopping at the first that it is not.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `o`: an Option.

<p class="pyk-api-label">Returns</p>

`false` where `p` is false of one, `true` where there is none, as for an empty collection.

<p class="pyk-api-label">Example</p>

```pyking
o = Some(3)
none: Option(Int) = None
print(all(lam x. x > 2, o), all(lam x. x > 2, none))
```

```stdout visible = true
true true
```

</div>

<div class="pyk-api">

## option::any

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">option::any</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">o</span>: Option(a)) -&gt; <span class="t">Bool</span></code></pre>

`any(p, o)` on an Option: whether `p` is true of some value it holds,
stopping at the first that it is.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `o`: an Option.

<p class="pyk-api-label">Returns</p>

`true` where `p` is true of one, `false` where there is none, as for an empty collection.

<p class="pyk-api-label">Example</p>

```pyking
o = Some(3)
none: Option(Int) = None
print(any(lam x. x > 2, o), any(lam x. x > 2, none))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## option::filter

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">option::filter</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">o</span>: Option(a)) -&gt; Option(a)</code></pre>

`filter(p, o)` on an Option: what `p` is true of.

<p class="pyk-api-label">Parameters</p>

- `p`: the test, called once per element, in order.
- `o`: an Option.

<p class="pyk-api-label">Returns</p>

`o` where it holds a value `p` is true of, and otherwise `None`.

<p class="pyk-api-label">Example</p>

```pyking
o = Some(3)
none: Option(Int) = None
print(filter(lam x. x % 2 == 1, o), filter(lam x. x % 2 == 1, none))
```

```stdout visible = true
Some(3) None
```

</div>

<div class="pyk-api">

## option::fmap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">option::fmap</span>(<span class="p">f</span>: (a) -&gt; b, <span class="p">o</span>: Option(a)) -&gt; Option(b)</code></pre>

`fmap(f, o)` on an Option: `f` applied to each value it holds, as Haskell's
`fmap` and Rust's `map` are.

<p class="pyk-api-label">Parameters</p>

- `f`: the function, called once per element, in order.
- `o`: an Option.

<p class="pyk-api-label">Returns</p>

`Some(f(v))` for `Some(v)`, and `None` for `None`.

<p class="pyk-api-label">Example</p>

```pyking
o = Some(3)
none: Option(Int) = None
print(fmap(lam x. x * 10, o), fmap(lam x. x * 10, none))
```

```stdout visible = true
Some(30) None
```

</div>

<div class="pyk-api">

## option::foldl

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">option::foldl</span>(<span class="p">f</span>: (b, a) -&gt; b, <span class="p">init</span>: b, <span class="p">o</span>: Option(a)) -&gt; b</code></pre>

`foldl(f, init, o)` on an Option: `f(...f(f(init, x1), x2)..., xn)`, the
value it holds, if any from the first.

<p class="pyk-api-label">Parameters</p>

- `f`: takes what is gathered so far and the next element.
- `init`: what is gathered before any element.
- `o`: an Option.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
o = Some(3)
none: Option(Int) = None
print(foldl(lam (acc, x). acc * 10 + x, 0, o), foldl(lam (acc, x). acc * 10 + x, 0, none))
```

```stdout visible = true
3 0
```

</div>

<div class="pyk-api">

## option::foldr

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">option::foldr</span>(<span class="p">f</span>: (a, b) -&gt; b, <span class="p">init</span>: b, <span class="p">o</span>: Option(a)) -&gt; b</code></pre>

`foldr(f, init, o)` on an Option: `f(x1, f(x2, ...f(xn, init)))`, the
value it holds, if any from the last.

<p class="pyk-api-label">Parameters</p>

- `f`: takes the next element, from the end, and what is gathered so far.
- `init`: what is gathered before any element.
- `o`: an Option.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
o = Some(3)
none: Option(Int) = None
print(foldr(lam (x, acc). acc * 10 + x, 0, o), foldr(lam (x, acc). acc * 10 + x, 0, none))
```

```stdout visible = true
3 0
```

</div>

<div class="pyk-api">

## option::list

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">option::list</span>(<span class="p">o</span>: Option(a)) -&gt; [a]</code></pre>

`list(o)` of an Option: its value, or nothing.

<p class="pyk-api-label">Parameters</p>

- `o`: an Option.

<p class="pyk-api-label">Returns</p>

A new list.

<p class="pyk-api-label">Example</p>

```pyking
none: Option(Int) = None
print(list(Some(1)), list(none))
```

```stdout visible = true
[1] []
```

</div>

<div class="pyk-api">

## result::all

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">result::all</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">r</span>: Result(a, e)) -&gt; <span class="t">Bool</span></code></pre>

`all(p, r)` on a Result: whether `p` is true of every value it holds,
stopping at the first that it is not.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `r`: a Result.

<p class="pyk-api-label">Returns</p>

`false` where `p` is false of one, `true` where there is none, as for an empty collection.

<p class="pyk-api-label">Example</p>

```pyking
r: Result(Int, String) = Ok(3)
bad: Result(Int, String) = Error("no")
print(all(lam x. x > 2, r), all(lam x. x > 2, bad))
```

```stdout visible = true
true true
```

</div>

<div class="pyk-api">

## result::any

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">result::any</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">r</span>: Result(a, e)) -&gt; <span class="t">Bool</span></code></pre>

`any(p, r)` on a Result: whether `p` is true of some value it holds,
stopping at the first that it is.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `r`: a Result.

<p class="pyk-api-label">Returns</p>

`true` where `p` is true of one, `false` where there is none, as for an empty collection.

<p class="pyk-api-label">Example</p>

```pyking
r: Result(Int, String) = Ok(3)
bad: Result(Int, String) = Error("no")
print(any(lam x. x > 2, r), any(lam x. x > 2, bad))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## result::fmap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">result::fmap</span>(<span class="p">f</span>: (a) -&gt; b, <span class="p">r</span>: Result(a, e)) -&gt; Result(b, e)</code></pre>

`fmap(f, r)` on a Result: `f` applied to each value it holds, as Haskell's
`fmap` and Rust's `map` are.

<p class="pyk-api-label">Parameters</p>

- `f`: the function, called once per element, in order.
- `r`: a Result.

<p class="pyk-api-label">Returns</p>

`Ok(f(v))` for `Ok(v)`, and the same `Error` for an `Error`.

<p class="pyk-api-label">Example</p>

```pyking
r: Result(Int, String) = Ok(3)
bad: Result(Int, String) = Error("no")
print(fmap(lam x. x * 10, r), fmap(lam x. x * 10, bad))
```

```stdout visible = true
Ok(30) Error("no")
```

</div>

<div class="pyk-api">

## result::foldl

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">result::foldl</span>(<span class="p">f</span>: (b, a) -&gt; b, <span class="p">init</span>: b, <span class="p">r</span>: Result(a, e)) -&gt; b</code></pre>

`foldl(f, init, r)` on a Result: `f(...f(f(init, x1), x2)..., xn)`, the
value it holds, if any from the first.

<p class="pyk-api-label">Parameters</p>

- `f`: takes what is gathered so far and the next element.
- `init`: what is gathered before any element.
- `r`: a Result.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
r: Result(Int, String) = Ok(3)
bad: Result(Int, String) = Error("no")
print(foldl(lam (acc, x). acc * 10 + x, 0, r), foldl(lam (acc, x). acc * 10 + x, 0, bad))
```

```stdout visible = true
3 0
```

</div>

<div class="pyk-api">

## result::foldr

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">result::foldr</span>(<span class="p">f</span>: (a, b) -&gt; b, <span class="p">init</span>: b, <span class="p">r</span>: Result(a, e)) -&gt; b</code></pre>

`foldr(f, init, r)` on a Result: `f(x1, f(x2, ...f(xn, init)))`, the
value it holds, if any from the last.

<p class="pyk-api-label">Parameters</p>

- `f`: takes the next element, from the end, and what is gathered so far.
- `init`: what is gathered before any element.
- `r`: a Result.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
r: Result(Int, String) = Ok(3)
bad: Result(Int, String) = Error("no")
print(foldr(lam (x, acc). acc * 10 + x, 0, r), foldr(lam (x, acc). acc * 10 + x, 0, bad))
```

```stdout visible = true
3 0
```

</div>

<div class="pyk-api">

## slice::all

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">slice::all</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: Slice(a)) -&gt; <span class="t">Bool</span></code></pre>

`all(p, xs)` on a view: whether `p` is true of every element,
stopping at the first that it is not.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: a view.

<p class="pyk-api-label">Returns</p>

`false` where `p` is false of one, `true` where there is none.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = view(array([0, 1, 2, 3]), 1, 4)
print(all(lam x. x > 0, xs), all(lam x. x > 1, xs))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## slice::any

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">slice::any</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: Slice(a)) -&gt; <span class="t">Bool</span></code></pre>

`any(p, xs)` on a view: whether `p` is true of some element,
stopping at the first that it is.

<p class="pyk-api-label">Parameters</p>

- `p`: the test.
- `xs`: a view.

<p class="pyk-api-label">Returns</p>

`true` where `p` is true of one, `false` where there is none.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = view(array([0, 1, 2, 3]), 1, 4)
print(any(lam x. x > 2, xs), any(lam x. x > 5, xs))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## slice::filter

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">slice::filter</span>(<span class="p">p</span>: (a) -&gt; <span class="t">Bool</span>, <span class="p">xs</span>: Slice(a)) -&gt; Array(a)</code></pre>

`filter(p, xs)` on a view: what `p` is true of.

<p class="pyk-api-label">Parameters</p>

- `p`: the test, called once per element, in order.
- `xs`: a view.

<p class="pyk-api-label">Returns</p>

A new array of the elements `p` is true of, in order.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = view(array([0, 1, 2, 3]), 1, 4)
print(filter(lam x. x % 2 == 1, xs))
```

```stdout visible = true
array([1, 3])
```

</div>

<div class="pyk-api">

## slice::fmap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">slice::fmap</span>(<span class="p">f</span>: (a) -&gt; b, <span class="p">xs</span>: Slice(a)) -&gt; Array(b)</code></pre>

`fmap(f, xs)` on a view: `f` applied to each element, as Haskell's
`fmap` and Rust's `map` are.

<p class="pyk-api-label">Parameters</p>

- `f`: the function, called once per element, in order.
- `xs`: a view.

<p class="pyk-api-label">Returns</p>

A new array of `f(x)` for each element of the view.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = view(array([0, 1, 2, 3]), 1, 4)
print(fmap(lam x. x * 10, xs))
```

```stdout visible = true
array([10, 20, 30])
```

</div>

<div class="pyk-api">

## slice::foldl

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">slice::foldl</span>(<span class="p">f</span>: (b, a) -&gt; b, <span class="p">init</span>: b, <span class="p">xs</span>: Slice(a)) -&gt; b</code></pre>

`foldl(f, init, xs)` on a view: `f(...f(f(init, x1), x2)..., xn)`, the
elements from the first.

<p class="pyk-api-label">Parameters</p>

- `f`: takes what is gathered so far and the next element.
- `init`: what is gathered before any element.
- `xs`: a view.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = view(array([0, 1, 2, 3]), 1, 4)
print(foldl(lam (acc, x). acc * 10 + x, 0, xs))
```

```stdout visible = true
123
```

</div>

<div class="pyk-api">

## slice::foldr

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">slice::foldr</span>(<span class="p">f</span>: (a, b) -&gt; b, <span class="p">init</span>: b, <span class="p">xs</span>: Slice(a)) -&gt; b</code></pre>

`foldr(f, init, xs)` on a view: `f(x1, f(x2, ...f(xn, init)))`, the
elements from the last.

<p class="pyk-api-label">Parameters</p>

- `f`: takes the next element, from the end, and what is gathered so far.
- `init`: what is gathered before any element.
- `xs`: a view.

<p class="pyk-api-label">Returns</p>

What `f` gathered, or `init` where there are no elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
xs = view(array([0, 1, 2, 3]), 1, 4)
print(foldr(lam (x, acc). acc * 10 + x, 0, xs))
```

```stdout visible = true
321
```

</div>

<div class="pyk-api">

## slice::list

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">slice::list</span>(<span class="p">xs</span>: Slice(a)) -&gt; [a]</code></pre>

`list(xs)` of a view: the elements it shows now.

<p class="pyk-api-label">Parameters</p>

- `xs`: a view.

<p class="pyk-api-label">Returns</p>

A new list.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
print(list(view(array([1, 2, 3]), 1, 3)))
```

```stdout visible = true
[2, 3]
```

</div>

<div class="pyk-api">

## string::list

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">string::list</span>(<span class="p">s</span>: <span class="t">String</span>) -&gt; [Char]</code></pre>

`list(s)` of a String: its Chars.

<p class="pyk-api-label">Parameters</p>

- `s`: a String.

<p class="pyk-api-label">Returns</p>

A new list.

<p class="pyk-api-label">Example</p>

```pyking
print(list("héllo"))
```

```stdout visible = true
['h', 'é', 'l', 'l', 'o']
```

</div>

<div class="pyk-api">

## unfold::dynarray_init

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">unfold::dynarray_init</span>(
    <span class="p">n</span>: <span class="t">Int</span>,
    <span class="p">seed</span>: s,
    <span class="p">f</span>: (s) -&gt; (a, s),
) -&gt; DynArray(a)</code></pre>

`dynarray_init(n, seed, f)`: `n` elements unfolded from `seed`, as
`array_init`'s unfolding form. Needs `use mutation`.

<p class="pyk-api-label">Parameters</p>

- `n`: how many.
- `seed`: what the first element is made from.
- `f`: answers an element and the next seed.

<p class="pyk-api-label">Returns</p>

A new DynArray of `n` elements.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
print(dynarray_init(4, 1, lam x. (x, x * 3)))
```

```stdout visible = true
dynarray([1, 3, 9, 27])
```

</div>

<div class="pyk-api">

## unfold::list_init

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">unfold::list_init</span>(<span class="p">n</span>: <span class="t">Int</span>, <span class="p">seed</span>: s, <span class="p">f</span>: (s) -&gt; (a, s)) -&gt; [a]</code></pre>

`list_init(n, seed, f)`: `n` elements unfolded from `seed`, `f` answering
each element and the next seed. A negative `n` is a runtime error.

<p class="pyk-api-label">Parameters</p>

- `n`: how many.
- `seed`: what the first element is made from.
- `f`: answers an element and the next seed.

<p class="pyk-api-label">Returns</p>

A list of `n` elements.

<p class="pyk-api-label">Example</p>

```pyking
print(list_init(8, (0, 1), lam p. let (a, b) = p in (a, (b, a + b))))
```

```stdout visible = true
[0, 1, 1, 2, 3, 5, 8, 13]
```

</div>

<div class="pyk-api">

## unfold::map_init

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">unfold::map_init</span>(
    <span class="p">n</span>: <span class="t">Int</span>,
    <span class="p">seed</span>: s,
    <span class="p">f</span>: (s) -&gt; ((k, v), s),
) -&gt; Map(k, v)</code></pre>

`map_init(n, seed, f)`: `n` (key, value) entries unfolded from `seed`, a
later one with a key already there replacing its value.

<p class="pyk-api-label">Parameters</p>

- `n`: how many entries to unfold.
- `seed`: what the first is made from.
- `f`: answers an entry and the next seed.

<p class="pyk-api-label">Returns</p>

A new Map.

<p class="pyk-api-label">Example</p>

```pyking
print(map_init(3, 1, lam x. ((x, x * x), x + 1)))
```

```stdout visible = true
map([(1, 1), (2, 4), (3, 9)])
```

</div>

<div class="pyk-api">

## unfold::mutmap_init

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">unfold::mutmap_init</span>(
    <span class="p">n</span>: <span class="t">Int</span>,
    <span class="p">seed</span>: s,
    <span class="p">f</span>: (s) -&gt; ((k, v), s),
) -&gt; MutMap(k, v)</code></pre>

`mutmap_init(n, seed, f)`: as `map_init`'s unfolding form, a MutMap. Needs
`use mutation`.

<p class="pyk-api-label">Parameters</p>

- `n`: how many entries to unfold.
- `seed`: what the first is made from.
- `f`: answers an entry and the next seed.

<p class="pyk-api-label">Returns</p>

A new MutMap.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
print(mutmap_init(2, 0, lam x. ((x, string(x)), x + 1)))
```

```stdout visible = true
mutmap([(0, "0"), (1, "1")])
```

</div>
