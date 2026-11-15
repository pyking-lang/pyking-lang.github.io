---
title: mutmap
description: "MutMaps: changing an entry in place, keeping a count, and the rest of what a MutMap is asked."
---

MutMaps: changing an entry in place, keeping a count, and the rest of
what a MutMap is asked.

A MutMap is made by `mutmap(...)` or `mutmap_init(...)`, read with
`d[k]`, `get`, `has`, `keys`, `values`, `items` and `len`, and changed
with `d[k] := v`, `remove`, `discard` and `clear`, all builtins
(PYKING.md, "MutMaps"). This module is the rest. `update`,
`insert_with`, `extend` and `retain` change the MutMap they are given,
which everyone holding it sees, and need `use mutation` in the calling
module as every change does.

```pyking norun
import mutmap
```

<div class="pyk-api">

## copy

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">copy</span>(<span class="p">d</span>: MutMap(k, v)) -&gt; MutMap(k, v)</code></pre>

A new MutMap of the same entries, in the same order: `mutmap(d)`.

<p class="pyk-api-label">Parameters</p>

- `d`: the MutMap.

<p class="pyk-api-label">Returns</p>

A new MutMap; changing one does not change the other.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import mutmap
d = mutmap([("ann", 31), ("bo", 5)])
e = mutmap.copy(d)
e["cy"] := 1
print(d, e)
```

```stdout visible = true
mutmap([("ann", 31), ("bo", 5)]) mutmap([("ann", 31), ("bo", 5), ("cy", 1)])
```

</div>

<div class="pyk-api">

## equal_by

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">equal_by</span>(
    <span class="p">alike</span>: (v, v) -&gt; <span class="t">Bool</span>,
    <span class="p">d1</span>: MutMap(k, v),
    <span class="p">d2</span>: MutMap(k, v),
) -&gt; <span class="t">Bool</span></code></pre>

Whether two MutMaps have the same keys, the values of each alike by
`alike`, in whatever order.

<p class="pyk-api-label">Parameters</p>

- `alike`: whether two values count as the same.
- `d1`: the first MutMap.
- `d2`: the second.

<p class="pyk-api-label">Returns</p>

`true` where they are.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import mutmap
print(mutmap.equal_by(lam (a, b). a == b, mutmap([(1, "a"), (2, "b")]), mutmap([(2, "b"), (1, "a")])))
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## extend

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">extend</span>(<span class="p">d</span>: MutMap(k, v), <span class="p">pairs</span>: [(k, v)]) -&gt; ()</code></pre>

Puts every (key, value) pair in, in order.

<p class="pyk-api-label">Parameters</p>

- `d`: the MutMap.
- `pairs`: the entries to put in.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import mutmap
d = mutmap([("ann", 31), ("bo", 5)])
mutmap.extend(d, [("cy", 40), ("ann", 32)])
print(d)
```

```stdout visible = true
mutmap([("ann", 32), ("bo", 5), ("cy", 40)])
```

</div>

<div class="pyk-api">

## find_key

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">find_key</span>(<span class="p">p</span>: (v) -&gt; <span class="t">Bool</span>, <span class="p">d</span>: MutMap(k, v)) -&gt; Option(k)</code></pre>

The first key whose value `p` is true of.

<p class="pyk-api-label">Parameters</p>

- `p`: the test, given a value.
- `d`: the MutMap.

<p class="pyk-api-label">Returns</p>

`Some` of the key, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import mutmap
d = mutmap([("ann", 31), ("bo", 5)])
print(mutmap.find_key(lam age. age > 18, d))
```

```stdout visible = true
Some("ann")
```

</div>

<div class="pyk-api">

## fold_with_key

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">fold_with_key</span>(<span class="p">f</span>: (b, k, v) -&gt; b, <span class="p">init</span>: b, <span class="p">d</span>: MutMap(k, v)) -&gt; b</code></pre>

`foldl` given each key as well as its value, in order.

<p class="pyk-api-label">Parameters</p>

- `f`: takes what is gathered so far, a key and its value.
- `init`: what is gathered before any entry.
- `d`: the MutMap.

<p class="pyk-api-label">Returns</p>

What `f` gathered.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import mutmap
d = mutmap([("ann", 31), ("bo", 5)])
print(mutmap.fold_with_key(lam (acc, name, age). acc + age, 0, d))
```

```stdout visible = true
36
```

</div>

<div class="pyk-api">

## insert_with

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">insert_with</span>(<span class="p">f</span>: (v, v) -&gt; v, <span class="p">d</span>: MutMap(k, v), <span class="p">key</span>: k, <span class="p">value</span>: v) -&gt; ()</code></pre>

Puts `value` in for `key`, or, where `key` has a value already, `f(old,
value)`: how a count is kept.

<p class="pyk-api-label">Parameters</p>

- `f`: combines the value there with the new one.
- `d`: the MutMap.
- `key`: the key.
- `value`: the new value.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import mutmap
counts: MutMap(String, Int) = mutmap()
for word in ["a", "b", "a"]:
    mutmap.insert_with(lam (old, new). old + new, counts, word, 1)
print(counts)
```

```stdout visible = true
mutmap([("a", 2), ("b", 1)])
```

</div>

<div class="pyk-api">

## is_empty

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">is_empty</span>(<span class="p">d</span>: MutMap(k, v)) -&gt; <span class="t">Bool</span></code></pre>

Whether the MutMap has no entries.

<p class="pyk-api-label">Parameters</p>

- `d`: the MutMap.

<p class="pyk-api-label">Returns</p>

`true` for an empty one.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import mutmap
d = mutmap([("ann", 31), ("bo", 5)])
print(mutmap.is_empty(d))
```

```stdout visible = true
false
```

</div>

<div class="pyk-api">

## lookup

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">lookup</span>(<span class="p">d</span>: MutMap(k, v), <span class="p">key</span>: k) -&gt; Option(v)</code></pre>

The value of `key` as an Option: `d[key]` that does not fail.

<p class="pyk-api-label">Parameters</p>

- `d`: the MutMap.
- `key`: the key.

<p class="pyk-api-label">Returns</p>

`Some` of its value, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import mutmap
d = mutmap([("ann", 31), ("bo", 5)])
print(mutmap.lookup(d, "bo"), mutmap.lookup(d, "zed"))
```

```stdout visible = true
Some(5) None
```

</div>

<div class="pyk-api">

## retain

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">retain</span>(<span class="p">p</span>: (v) -&gt; <span class="t">Bool</span>, <span class="p">d</span>: MutMap(k, v)) -&gt; ()</code></pre>

Takes out every entry whose value `p` is false of, in place: `filter`
without a copy (Rust's `retain`).

<p class="pyk-api-label">Parameters</p>

- `p`: the test, given a value.
- `d`: the MutMap.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import mutmap
d = mutmap([("ann", 31), ("bo", 5)])
mutmap.retain(lam age. age > 18, d)
print(d)
```

```stdout visible = true
mutmap([("ann", 31)])
```

</div>

<div class="pyk-api">

## update

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">update</span>(<span class="p">f</span>: (v) -&gt; v, <span class="p">d</span>: MutMap(k, v), <span class="p">key</span>: k) -&gt; ()</code></pre>

Applies `f` to the value of `key`, in place, where `d` has one.

<p class="pyk-api-label">Parameters</p>

- `f`: makes the new value from the old.
- `d`: the MutMap.
- `key`: the key.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import mutmap
d = mutmap([("ann", 31), ("bo", 5)])
mutmap.update(lam age. age + 1, d, "bo")
mutmap.update(lam age. age + 1, d, "zed")
print(d)
```

```stdout visible = true
mutmap([("ann", 31), ("bo", 6)])
```

</div>
