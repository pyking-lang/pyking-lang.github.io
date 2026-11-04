---
title: option
description: "Option: a value, or none."
---

Option: a value, or none. `Option(a)` is `Some(value)` or `None`.

Every module that uses `Option`, `Some` or `None` without declaring
its own has them as if it began `from option import Option` (PYKING.md,
"Option"); a module declaring its own Option, or its own `Some` or
`None`, means its own. `import option` reaches the functions below.

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

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">or_else</span>(<span class="p">o</span>: Option(a), <span class="p">default</span>: a) -&gt; a</code></pre>

The value `o` holds, or `default` where it holds none.

<p class="pyk-api-label">Parameters</p>

- `o`: the option.
- `default`: what to answer for `None`.

<p class="pyk-api-label">Returns</p>

The value of a `Some`, or `default`.

<p class="pyk-api-label">Example</p>

```pyking
import option
print(option.or_else(Some(3), 0), option.or_else(None, 0))
```

```stdout visible = true
3 0
```

</div>
