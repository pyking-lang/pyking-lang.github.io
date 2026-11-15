---
title: option
description: "Option: a value, or none."
---

Option: a value, or none. `Option(a)` is `Some(value)` or `None`.

Every module that uses `Option`, `Some` or `None` without declaring
its own has them as if it began `from option import Option` (PYKING.md,
"Option"); a module declaring its own Option, or its own `Some` or
`None`, means its own. `import option` reaches the functions below,
named as Rust's are. `fmap`, `filter`, `foldl`, `foldr`, `any` and
`all` take an Option too, as a collection of none or one value, and
`list(o)` makes it a list.

```pyking norun
import option
```

<div class="pyk-api">

## Option

<pre class="pyk-sig"><code><span class="k">datatype</span> <span class="n">Option</span>(a):
    None
    Some(value: a)</code></pre>

A value, or none: what a pointer that may point nowhere is (PYKING.md,
"Pointers"), and what a search that may find nothing answers.

<p class="pyk-api-label">Example</p>

```pyking
found = Some(42)
missing: Option(Int) = None
match found:
    case Some(n): print(found, missing, n)
    case None: print("none")
```

```stdout visible = true
Some(42) None 42
```

</div>

<div class="pyk-api">

## all_some

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">all_some</span>(<span class="p">os</span>: [Option(a)]) -&gt; Option([a])</code></pre>

Every value, where every option holds one; otherwise `None` (Rust's
`collect` into an Option, Haskell's `sequence`).

<p class="pyk-api-label">Parameters</p>

- `os`: the options.

<p class="pyk-api-label">Returns</p>

`Some` of every value in order, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
import option
print(option.all_some([Some(1), Some(2)]), option.all_some([Some(1), None]))
```

```stdout visible = true
Some([1, 2]) None
```

</div>

<div class="pyk-api">

## and_then

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">and_then</span>(<span class="p">o</span>: Option(a), <span class="p">f</span>: (a) -&gt; Option(b)) -&gt; Option(b)</code></pre>

Goes on with `f` where `o` holds a value: the next step of a search
that stops at the first `None` (Haskell's `>>=`, OCaml's `bind`).

<p class="pyk-api-label">Parameters</p>

- `o`: the option so far.
- `f`: the next step, given the value.

<p class="pyk-api-label">Returns</p>

What `f` answers, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
import option
def half(n: Int) -> Option(Int):
    if n % 2 == 0 then Some(n / 2) else None
print(option.and_then(Some(8), half), option.and_then(Some(3), half), option.and_then(None, half))
```

```stdout visible = true
Some(4) None None
```

</div>

<div class="pyk-api">

## expect

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">expect</span>(<span class="p">o</span>: Option(a), <span class="p">message</span>: <span class="t">String</span>) -&gt; a</code></pre>

The value `o` holds; for `None` the program stops with the runtime
error `message`.

<p class="pyk-api-label">Parameters</p>

- `o`: the option, which should hold a value.
- `message`: what the runtime error says.

<p class="pyk-api-label">Returns</p>

The value.

<p class="pyk-api-label">Example</p>

```pyking
import option
print(option.expect(Some("ready"), "the setting should be there"))
```

```stdout visible = true
ready
```

</div>

<div class="pyk-api">

## flatten

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">flatten</span>(<span class="p">oo</span>: Option(Option(a))) -&gt; Option(a)</code></pre>

An option holding an option, as one.

<p class="pyk-api-label">Parameters</p>

- `oo`: the option of an option.

<p class="pyk-api-label">Returns</p>

The inner option, or `None`.

<p class="pyk-api-label">Example</p>

```pyking
import option
nested: Option(Option(Int)) = Some(Some(1))
print(option.flatten(nested))
```

```stdout visible = true
Some(1)
```

</div>

<div class="pyk-api">

## is_none

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">is_none</span>(<span class="p">o</span>: Option(a)) -&gt; <span class="t">Bool</span></code></pre>

Whether `o` holds nothing.

<p class="pyk-api-label">Parameters</p>

- `o`: the option.

<p class="pyk-api-label">Returns</p>

`true` for `None`, `false` for a `Some`.

<p class="pyk-api-label">Example</p>

```pyking
import option
print(option.is_none(None), option.is_none(Some("x")))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## is_some

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">is_some</span>(<span class="p">o</span>: Option(a)) -&gt; <span class="t">Bool</span></code></pre>

Whether `o` holds a value.

<p class="pyk-api-label">Parameters</p>

- `o`: the option.

<p class="pyk-api-label">Returns</p>

`true` for a `Some`, `false` for `None`.

<p class="pyk-api-label">Example</p>

```pyking
import option
print(option.is_some(Some(3)), option.is_some(None))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## or_else

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">or_else</span>(<span class="p">o</span>: Option(a), <span class="p">f</span>: () -&gt; Option(a)) -&gt; Option(a)</code></pre>

`o` where it holds a value, and otherwise what `f` answers: a second
place to look (Rust's `or_else`; the default value itself is
`unwrap_or`).

<p class="pyk-api-label">Parameters</p>

- `o`: the option.
- `f`: called for `None` only.

<p class="pyk-api-label">Returns</p>

`o` for a `Some`, or `f()`.

<p class="pyk-api-label">Example</p>

```pyking
import option
print(option.or_else(None, lam (). Some(2)), option.or_else(Some(1), lam (). Some(2)))
```

```stdout visible = true
Some(2) Some(1)
```

</div>

<div class="pyk-api">

## unwrap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">unwrap</span>(<span class="p">o</span>: Option(a)) -&gt; a</code></pre>

The value `o` holds; for `None` the program stops with a runtime error.

<p class="pyk-api-label">Parameters</p>

- `o`: the option, which should hold a value.

<p class="pyk-api-label">Returns</p>

The value.

<p class="pyk-api-label">Example</p>

```pyking
import option
print(option.unwrap(Some(42)))
```

```stdout visible = true
42
```

</div>

<div class="pyk-api">

## unwrap_or

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">unwrap_or</span>(<span class="p">o</span>: Option(a), <span class="p">default</span>: a) -&gt; a</code></pre>

The value `o` holds, or `default` where it holds none (Rust's
`unwrap_or`, Haskell's `fromMaybe`).

<p class="pyk-api-label">Parameters</p>

- `o`: the option.
- `default`: what to answer for `None`.

<p class="pyk-api-label">Returns</p>

The value of a `Some`, or `default`.

<p class="pyk-api-label">Example</p>

```pyking
import option
print(option.unwrap_or(Some(3), 0), option.unwrap_or(None, 0))
```

```stdout visible = true
3 0
```

</div>

<div class="pyk-api">

## unwrap_or_else

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">unwrap_or_else</span>(<span class="p">o</span>: Option(a), <span class="p">f</span>: () -&gt; a) -&gt; a</code></pre>

The value `o` holds, or what `f` makes where it holds none: `f` is
called only then.

<p class="pyk-api-label">Parameters</p>

- `o`: the option.
- `f`: makes the value for `None`.

<p class="pyk-api-label">Returns</p>

The value of a `Some`, or `f()`.

<p class="pyk-api-label">Example</p>

```pyking
import option
print(option.unwrap_or_else(None, lam (). 6 * 7))
```

```stdout visible = true
42
```

</div>

<div class="pyk-api">

## values

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">values</span>(<span class="p">os</span>: [Option(a)]) -&gt; [a]</code></pre>

The values of the options that hold one, in order: the `None`s
dropped (Haskell's `catMaybes`, Rust's `flatten`).

<p class="pyk-api-label">Parameters</p>

- `os`: the options.

<p class="pyk-api-label">Returns</p>

Every value held, in order.

<p class="pyk-api-label">Example</p>

```pyking
import option
print(option.values([Some(1), None, Some(3)]))
```

```stdout visible = true
[1, 3]
```

</div>

<div class="pyk-api">

## zip

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">zip</span>(<span class="p">o</span>: Option(a), <span class="p">p</span>: Option(b)) -&gt; Option((a, b))</code></pre>

Both values as a pair, where both options hold one.

<p class="pyk-api-label">Parameters</p>

- `o`: the first option.
- `p`: the second.

<p class="pyk-api-label">Returns</p>

`Some((x, y))`, or `None` where either is `None`.

<p class="pyk-api-label">Example</p>

```pyking
import option
print(option.zip(Some(1), Some("a")), option.zip(Some(1), None))
```

```stdout visible = true
Some((1, "a")) None
```

</div>
