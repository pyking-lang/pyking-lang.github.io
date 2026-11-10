---
title: map
description: "Maps: a new Map with an entry put in, taken out or changed, and the rest of what a Map is asked."
---

Maps: a new Map with an entry put in, taken out or changed, and the
rest of what a Map is asked.

A Map is made by `map(...)` or `map_init(...)`, read with `m[k]`,
`get`, `has`, `keys`, `values`, `items` and `len`, which are builtins,
as `fmap`, `filter` and the folds on its values are (PYKING.md,
"Maps"). A Map is never changed: each function here that changes one
answers a **new** Map and leaves the one it was given as it was. A new
key goes at the end, a key already there keeps its place, and one
taken out and put back goes to the end, as in a MutMap.

Each change copies the Map, so it takes time in proportion to its
size: a Map built one entry at a time in a loop is better built as a
list of pairs, or as a MutMap, and then made one with `map(...)`.

```pyking norun
import map
```

<div class="pyk-api">

## adjust

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">adjust</span>(<span class="p">f</span>: (v) -&gt; v, <span class="p">m</span>: Map(k, v), <span class="p">key</span>: k) -&gt; Map(k, v)</code></pre>

`m` with `f` applied to the value of `key`, where it has one.

<p class="pyk-api-label">Parameters</p>

- `f`: makes the new value from the old.
- `m`: the Map.
- `key`: the key.

<p class="pyk-api-label">Returns</p>

A new Map, or `m` where `key` is not in it.

<p class="pyk-api-label">Example</p>

```pyking
import map
m = map([("ann", 31), ("bo", 5)])
print(map.adjust(lam age. age + 1, m, "bo"), map.adjust(lam age. age + 1, m, "zed"))
```

```stdout visible = true
map([("ann", 31), ("bo", 6)]) map([("ann", 31), ("bo", 5)])
```

</div>

<div class="pyk-api">

## alter

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">alter</span>(
    <span class="p">f</span>: (Option(v)) -&gt; Option(v),
    <span class="p">m</span>: Map(k, v),
    <span class="p">key</span>: k,
) -&gt; Map(k, v)</code></pre>

`m` with the entry for `key` as `f` says: `f` is given its value or
`None`, and answers the new value or `None` to take the entry out
(Haskell's `alter`).

<p class="pyk-api-label">Parameters</p>

- `f`: the old value, if any, to the new, if any.
- `m`: the Map.
- `key`: the key.

<p class="pyk-api-label">Returns</p>

A new Map.

<p class="pyk-api-label">Example</p>

```pyking
import map
m = map([("ann", 31), ("bo", 5)])
print(map.alter(lam o. None, m, "ann"), map.alter(lam o. Some(1), m, "cy"))
```

```stdout visible = true
map([("bo", 5)]) map([("ann", 31), ("bo", 5), ("cy", 1)])
```

</div>

<div class="pyk-api">

## difference

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">difference</span>(<span class="p">m1</span>: Map(k, v), <span class="p">m2</span>: Map(k, w)) -&gt; Map(k, v)</code></pre>

`m1`'s entries whose key `m2` does not have.

<p class="pyk-api-label">Parameters</p>

- `m1`: the Map whose entries are kept.
- `m2`: the Map whose keys are left out.

<p class="pyk-api-label">Returns</p>

A new Map.

<p class="pyk-api-label">Example</p>

```pyking
import map
print(map.difference(map([(1, "a"), (2, "b")]), map([(2, true)])))
```

```stdout visible = true
map([(1, "a")])
```

</div>

<div class="pyk-api">

## equal_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">equal_by</span>(
    <span class="p">alike</span>: (v, v) -&gt; <span class="t">Bool</span>,
    <span class="p">m1</span>: Map(k, v),
    <span class="p">m2</span>: Map(k, v),
) -&gt; <span class="t">Bool</span></code></pre>

Whether two Maps have the same keys, the values of each alike by
`alike`, in whatever order: what `==` asks where the values have no
`==`.

<p class="pyk-api-label">Parameters</p>

- `alike`: whether two values count as the same.
- `m1`: the first Map.
- `m2`: the second.

<p class="pyk-api-label">Returns</p>

`true` where they are.

<p class="pyk-api-label">Example</p>

```pyking
import map
print(map.equal_by(lam (a, b). a * a == b * b, map([(1, 2), (2, 3)]), map([(2, -3), (1, -2)])))
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## filter_with_key

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">filter_with_key</span>(<span class="p">p</span>: (k, v) -&gt; <span class="t">Bool</span>, <span class="p">m</span>: Map(k, v)) -&gt; Map(k, v)</code></pre>

`filter` given each key as well as its value.

<p class="pyk-api-label">Parameters</p>

- `p`: the test, given a key and its value.
- `m`: the Map.

<p class="pyk-api-label">Returns</p>

A new Map of the entries `p` is true of.

<p class="pyk-api-label">Example</p>

```pyking
import map
m = map([("ann", 31), ("bo", 5)])
print(map.filter_with_key(lam (name, age). len(name) > 2, m))
```

```stdout visible = true
map([("ann", 31)])
```

</div>

<div class="pyk-api">

## find_key

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">find_key</span>(<span class="p">p</span>: (v) -&gt; <span class="t">Bool</span>, <span class="p">m</span>: Map(k, v)) -&gt; Option(k)</code></pre>

The first key whose value `p` is true of.

<p class="pyk-api-label">Parameters</p>

- `p`: the test, given a value.
- `m`: the Map.

<p class="pyk-api-label">Returns</p>

`Some` of the key, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
import map
m = map([("ann", 31), ("bo", 5)])
print(map.find_key(lam age. age < 10, m))
```

```stdout visible = true
Some("bo")
```

</div>

<div class="pyk-api">

## fold_with_key

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">fold_with_key</span>(<span class="p">f</span>: (b, k, v) -&gt; b, <span class="p">init</span>: b, <span class="p">m</span>: Map(k, v)) -&gt; b</code></pre>

`foldl` given each key as well as its value, in order.

<p class="pyk-api-label">Parameters</p>

- `f`: takes what is gathered so far, a key and its value.
- `init`: what is gathered before any entry.
- `m`: the Map.

<p class="pyk-api-label">Returns</p>

What `f` gathered.

<p class="pyk-api-label">Example</p>

```pyking
import map
m = map([("ann", 31), ("bo", 5)])
print(map.fold_with_key(lam (acc, name, age). acc + "[" + name + "=" + string(age) + "]", "", m))
```

```stdout visible = true
[ann=31][bo=5]
```

</div>

<div class="pyk-api">

## insert

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">insert</span>(<span class="p">m</span>: Map(k, v), <span class="p">key</span>: k, <span class="p">value</span>: v) -&gt; Map(k, v)</code></pre>

`m` with `key` mapped to `value`: a new key at the end, or a key already
there given the new value in its place (Haskell's and Rust's `insert`).

<p class="pyk-api-label">Parameters</p>

- `m`: the Map.
- `key`: the key.
- `value`: its value.

<p class="pyk-api-label">Returns</p>

A new Map; `m` is as it was.

<p class="pyk-api-label">Example</p>

```pyking
import map
m = map([("ann", 31), ("bo", 5)])
print(map.insert(m, "cy", 40), map.insert(m, "ann", 32), m)
```

```stdout visible = true
map([("ann", 31), ("bo", 5), ("cy", 40)]) map([("ann", 32), ("bo", 5)]) map([("ann", 31), ("bo", 5)])
```

</div>

<div class="pyk-api">

## insert_with

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">insert_with</span>(
    <span class="p">f</span>: (v, v) -&gt; v,
    <span class="p">m</span>: Map(k, v),
    <span class="p">key</span>: k,
    <span class="p">value</span>: v,
) -&gt; Map(k, v)</code></pre>

`m` with `value` put in for `key`, or, where `key` has a value already,
`f(old, value)` (Haskell's `insertWith`): how a count is kept.

<p class="pyk-api-label">Parameters</p>

- `f`: combines the value there with the new one.
- `m`: the Map.
- `key`: the key.
- `value`: the new value.

<p class="pyk-api-label">Returns</p>

A new Map.

<p class="pyk-api-label">Example</p>

```pyking
import map
counts = map([("a", 1)])
print(map.insert_with(lam (old, new). old + new, counts, "a", 1), map.insert_with(lam (old, new). old + new, counts, "b", 1))
```

```stdout visible = true
map([("a", 2)]) map([("a", 1), ("b", 1)])
```

</div>

<div class="pyk-api">

## intersection

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">intersection</span>(<span class="p">m1</span>: Map(k, v), <span class="p">m2</span>: Map(k, w)) -&gt; Map(k, v)</code></pre>

`m1`'s entries whose key `m2` has too.

<p class="pyk-api-label">Parameters</p>

- `m1`: the Map whose entries are kept.
- `m2`: the Map whose keys say which.

<p class="pyk-api-label">Returns</p>

A new Map.

<p class="pyk-api-label">Example</p>

```pyking
import map
print(map.intersection(map([(1, "a"), (2, "b")]), map([(2, true)])))
```

```stdout visible = true
map([(2, "b")])
```

</div>

<div class="pyk-api">

## is_empty

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">is_empty</span>(<span class="p">m</span>: Map(k, v)) -&gt; <span class="t">Bool</span></code></pre>

Whether the Map has no entries.

<p class="pyk-api-label">Parameters</p>

- `m`: the Map.

<p class="pyk-api-label">Returns</p>

`true` for an empty Map.

<p class="pyk-api-label">Example</p>

```pyking
import map
empty: Map(Int, Int) = map()
print(map.is_empty(empty), map.is_empty(map([(1, 1)])))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## lookup

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">lookup</span>(<span class="p">m</span>: Map(k, v), <span class="p">key</span>: k) -&gt; Option(v)</code></pre>

The value of `key` as an Option: `m[key]` that does not fail (Haskell's
`lookup`, Rust's `get`).

<p class="pyk-api-label">Parameters</p>

- `m`: the Map.
- `key`: the key.

<p class="pyk-api-label">Returns</p>

`Some` of its value, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
import map
m = map([("ann", 31), ("bo", 5)])
print(map.lookup(m, "bo"), map.lookup(m, "zed"))
```

```stdout visible = true
Some(5) None
```

</div>

<div class="pyk-api">

## map_with_key

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">map_with_key</span>(<span class="p">f</span>: (k, v) -&gt; w, <span class="p">m</span>: Map(k, v)) -&gt; Map(k, w)</code></pre>

`fmap` given each key as well as its value (Haskell's `mapWithKey`).

<p class="pyk-api-label">Parameters</p>

- `f`: makes the new value from a key and its value.
- `m`: the Map.

<p class="pyk-api-label">Returns</p>

A new Map of the same keys.

<p class="pyk-api-label">Example</p>

```pyking
import map
m = map([("ann", 31), ("bo", 5)])
print(map.map_with_key(lam (name, age). name + string(age), m))
```

```stdout visible = true
map([("ann", "ann31"), ("bo", "bo5")])
```

</div>

<div class="pyk-api">

## partition

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">partition</span>(<span class="p">p</span>: (v) -&gt; <span class="t">Bool</span>, <span class="p">m</span>: Map(k, v)) -&gt; (Map(k, v), Map(k, v))</code></pre>

The entries whose value `p` is true of, and the others, `p` called once
per entry.

<p class="pyk-api-label">Parameters</p>

- `p`: the test, given a value.
- `m`: the Map.

<p class="pyk-api-label">Returns</p>

A pair of new Maps.

<p class="pyk-api-label">Example</p>

```pyking
import map
m = map([("ann", 31), ("bo", 5)])
print(map.partition(lam age. age > 18, m))
```

```stdout visible = true
(map([("ann", 31)]), map([("bo", 5)]))
```

</div>

<div class="pyk-api">

## remove

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">remove</span>(<span class="p">m</span>: Map(k, v), <span class="p">key</span>: k) -&gt; Map(k, v)</code></pre>

`m` without an entry for `key`; the same entries where it has none.

<p class="pyk-api-label">Parameters</p>

- `m`: the Map.
- `key`: the key to take out.

<p class="pyk-api-label">Returns</p>

A new Map.

<p class="pyk-api-label">Example</p>

```pyking
import map
m = map([("ann", 31), ("bo", 5)])
print(map.remove(m, "ann"), map.remove(m, "zed"))
```

```stdout visible = true
map([("bo", 5)]) map([("ann", 31), ("bo", 5)])
```

</div>

<div class="pyk-api">

## singleton

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">singleton</span>(<span class="p">key</span>: k, <span class="p">value</span>: v) -&gt; Map(k, v)</code></pre>

A Map of one entry.

<p class="pyk-api-label">Parameters</p>

- `key`: the key.
- `value`: its value.

<p class="pyk-api-label">Returns</p>

A new Map.

<p class="pyk-api-label">Example</p>

```pyking
import map
print(map.singleton("one", 1))
```

```stdout visible = true
map([("one", 1)])
```

</div>

<div class="pyk-api">

## union

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">union</span>(<span class="p">m1</span>: Map(k, v), <span class="p">m2</span>: Map(k, v)) -&gt; Map(k, v)</code></pre>

Every entry of both Maps, `m1`'s value where both have a key; `m2`'s
entries first, then `m1`'s new keys (Haskell's `union`, which prefers
the left).

<p class="pyk-api-label">Parameters</p>

- `m1`: the Map whose values win.
- `m2`: the other.

<p class="pyk-api-label">Returns</p>

A new Map.

<p class="pyk-api-label">Example</p>

```pyking
import map
print(map.union(map([(1, "a")]), map([(1, "x"), (2, "b")])))
```

```stdout visible = true
map([(1, "a"), (2, "b")])
```

</div>

<div class="pyk-api">

## union_with

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">union_with</span>(
    <span class="p">f</span>: (v, v) -&gt; v,
    <span class="p">m1</span>: Map(k, v),
    <span class="p">m2</span>: Map(k, v),
) -&gt; Map(k, v)</code></pre>

Every entry of both Maps, `f(v1, v2)` where both have a key; `m1`'s
entries first.

<p class="pyk-api-label">Parameters</p>

- `f`: combines the two values of a key both have.
- `m1`: the first Map.
- `m2`: the second.

<p class="pyk-api-label">Returns</p>

A new Map.

<p class="pyk-api-label">Example</p>

```pyking
import map
print(map.union_with(lam (a, b). a + b, map([("x", 1)]), map([("x", 10), ("y", 2)])))
```

```stdout visible = true
map([("x", 11), ("y", 2)])
```

</div>
