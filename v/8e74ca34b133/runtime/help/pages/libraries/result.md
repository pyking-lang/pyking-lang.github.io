---
title: result
description: "Result: a value, or the error that stopped it."
---

Result: a value, or the error that stopped it. `Result(t, e)` is
`Ok(value)` or `Error(error)`, as Rust's is (with `Error` for Rust's
`Err`).

Every module that uses `Result`, `Ok` or `Error` without declaring
its own has them as if it began `from result import Result`
(PYKING.md, "Result"); a module declaring its own Result, or its own
`Ok` or `Error`, means its own. `import result` reaches the functions
below. `fmap`, `foldl`, `foldr`, `any` and `all` take a Result too,
acting on its `Ok` value.

```pyking norun
import result
```

<div class="pyk-api">

## Result

<pre class="pyk-sig"><code><span class="k">datatype</span> <span class="n">Result</span>(t, e):
    Ok(value: t)
    Error(error: e)</code></pre>

A value, or the error that stopped it: what a function answers when
it may fail and should say why.

<p class="pyk-api-label">Parameters</p>

- `value`: what an `Ok` holds.
- `error`: what an `Error` holds -- a String saying what went wrong, or a datatype of the ways it can.

<p class="pyk-api-label">Example</p>

```pyking
def half(n: Int) -> Result(Int, String):
    if n % 2 == 0 then Ok(n / 2) else Error(string(n) + " is odd")
print(half(10), half(7))
match half(8):
    case Ok(n): print("half is", n)
    case Error(e): print(e)
```

```stdout visible = true
Ok(5) Error("7 is odd")
half is 4
```

</div>

<div class="pyk-api">

## all_ok

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">all_ok</span>(<span class="p">rs</span>: [Result(t, e)]) -&gt; Result([t], e)</code></pre>

Every value, where every result is an `Ok`; otherwise the first error
(Rust's `collect` into a Result, Haskell's `sequence`).

<p class="pyk-api-label">Parameters</p>

- `rs`: the results.

<p class="pyk-api-label">Returns</p>

`Ok` of every value in order, or the first `Error`.

<p class="pyk-api-label">Example</p>

```pyking
import result
print(result.all_ok([Ok(1), Ok(2)]), result.all_ok([Ok(1), Error("two"), Error("three")]))
```

```stdout visible = true
Ok([1, 2]) Error("two")
```

</div>

<div class="pyk-api">

## and_then

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">and_then</span>(<span class="p">r</span>: Result(t, e), <span class="p">f</span>: (t) -&gt; Result(u, e)) -&gt; Result(u, e)</code></pre>

Goes on with `f` where `r` is an `Ok`: the next step of a computation
that stops at the first error (Haskell's `>>=`, OCaml's `bind`).

<p class="pyk-api-label">Parameters</p>

- `r`: the result so far.
- `f`: the next step, given the `Ok` value.

<p class="pyk-api-label">Returns</p>

What `f` answers, or the same `Error`.

<p class="pyk-api-label">Example</p>

```pyking
import result
def positive(n: Int) -> Result(Int, String):
    if n > 0 then Ok(n) else Error("not positive")
print(result.and_then(Ok(5), positive), result.and_then(Ok(-1), positive))
print(result.and_then(Error("earlier"), positive))
```

```stdout visible = true
Ok(5) Error("not positive")
Error("earlier")
```

</div>

<div class="pyk-api">

## error

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">error</span>(<span class="p">r</span>: Result(t, e)) -&gt; Option(e)</code></pre>

The error of an `Error` as an Option.

<p class="pyk-api-label">Parameters</p>

- `r`: the result.

<p class="pyk-api-label">Returns</p>

`Some(error)` for an `Error`, `None` for an `Ok`.

<p class="pyk-api-label">Example</p>

```pyking
import result
print(result.error(Ok(1)), result.error(Error("no")))
```

```stdout visible = true
None Some("no")
```

</div>

<div class="pyk-api">

## expect

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">expect</span>(<span class="p">r</span>: Result(t, e), <span class="p">message</span>: <span class="t">String</span>) -&gt; t</code></pre>

The value of an `Ok`; for an `Error` the program stops with the runtime
error `message`.

<p class="pyk-api-label">Parameters</p>

- `r`: the result, which should be an `Ok`.
- `message`: what the runtime error says.

<p class="pyk-api-label">Returns</p>

The `Ok` value.

<p class="pyk-api-label">Example</p>

```pyking
import result
print(result.expect(Ok("ready"), "the file should open"))
```

```stdout visible = true
ready
```

</div>

<div class="pyk-api">

## flatten

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">flatten</span>(<span class="p">rr</span>: Result(Result(t, e), e)) -&gt; Result(t, e)</code></pre>

A result holding a result, as one.

<p class="pyk-api-label">Parameters</p>

- `rr`: the result of a result.

<p class="pyk-api-label">Returns</p>

The inner result, or the outer `Error`.

<p class="pyk-api-label">Example</p>

```pyking
import result
ok: Result(Result(Int, String), String) = Ok(Ok(1))
print(result.flatten(ok))
```

```stdout visible = true
Ok(1)
```

</div>

<div class="pyk-api">

## is_error

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">is_error</span>(<span class="p">r</span>: Result(t, e)) -&gt; <span class="t">Bool</span></code></pre>

Whether `r` is an `Error`.

<p class="pyk-api-label">Parameters</p>

- `r`: the result.

<p class="pyk-api-label">Returns</p>

`true` for an `Error`, `false` for an `Ok`.

<p class="pyk-api-label">Example</p>

```pyking
import result
print(result.is_error(Ok(1)), result.is_error(Error("no")))
```

```stdout visible = true
false true
```

</div>

<div class="pyk-api">

## is_ok

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">is_ok</span>(<span class="p">r</span>: Result(t, e)) -&gt; <span class="t">Bool</span></code></pre>

Whether `r` is an `Ok`.

<p class="pyk-api-label">Parameters</p>

- `r`: the result.

<p class="pyk-api-label">Returns</p>

`true` for an `Ok`, `false` for an `Error`.

<p class="pyk-api-label">Example</p>

```pyking
import result
print(result.is_ok(Ok(1)), result.is_ok(Error("no")))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## map_error

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">map_error</span>(<span class="p">f</span>: (e) -&gt; g, <span class="p">r</span>: Result(t, e)) -&gt; Result(t, g)</code></pre>

`r` with `f` applied to its error: what `fmap` is to the `Ok` value
(Rust's `map_err`). The function comes first, as `fmap`'s does.

<p class="pyk-api-label">Parameters</p>

- `f`: applied to the error.
- `r`: the result.

<p class="pyk-api-label">Returns</p>

The same `Ok`, or `Error(f(error))`.

<p class="pyk-api-label">Example</p>

```pyking
import result
print(result.map_error(lam e. "bad: " + e, Error("input")), result.map_error(lam e. e + "!", Ok(2)))
```

```stdout visible = true
Error("bad: input") Ok(2)
```

</div>

<div class="pyk-api">

## ok

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">ok</span>(<span class="p">r</span>: Result(t, e)) -&gt; Option(t)</code></pre>

The value of an `Ok` as an Option, the error dropped.

<p class="pyk-api-label">Parameters</p>

- `r`: the result.

<p class="pyk-api-label">Returns</p>

`Some(value)` for an `Ok`, `None` for an `Error`.

<p class="pyk-api-label">Example</p>

```pyking
import result
print(result.ok(Ok(1)), result.ok(Error("no")))
```

```stdout visible = true
Some(1) None
```

</div>

<div class="pyk-api">

## ok_or

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">ok_or</span>(<span class="p">o</span>: Option(t), <span class="p">problem</span>: e) -&gt; Result(t, e)</code></pre>

An Option as a Result: `None` becomes `Error(problem)` (Rust's
`Option::ok_or`; it lives here so that lib/option needs no Result).

<p class="pyk-api-label">Parameters</p>

- `o`: the option.
- `problem`: the error to give for `None`.

<p class="pyk-api-label">Returns</p>

`Ok(value)` for a `Some`, `Error(problem)` for `None`.

<p class="pyk-api-label">Example</p>

```pyking
import result
print(result.ok_or(Some(1), "missing"), result.ok_or(None, "missing"))
```

```stdout visible = true
Ok(1) Error("missing")
```

</div>

<div class="pyk-api">

## or_else

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">or_else</span>(<span class="p">r</span>: Result(t, e), <span class="p">f</span>: (e) -&gt; Result(t, g)) -&gt; Result(t, g)</code></pre>

Tries `f` where `r` is an `Error`: a way to recover from one.

<p class="pyk-api-label">Parameters</p>

- `r`: the result.
- `f`: given the error, answers another result.

<p class="pyk-api-label">Returns</p>

The same `Ok`, or what `f` answers.

<p class="pyk-api-label">Example</p>

```pyking
import result
print(result.or_else(Error("no"), lam e. Ok(len(e))), result.or_else(Ok(1), lam e. Ok(0)))
```

```stdout visible = true
Ok(2) Ok(1)
```

</div>

<div class="pyk-api">

## partition_results

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">partition_results</span>(<span class="p">rs</span>: [Result(t, e)]) -&gt; ([t], [e])</code></pre>

The values of the `Ok`s and the errors of the `Error`s, each in order
(Haskell's `partitionEithers`).

<p class="pyk-api-label">Parameters</p>

- `rs`: the results.

<p class="pyk-api-label">Returns</p>

A pair: every value, and every error.

<p class="pyk-api-label">Example</p>

```pyking
import result
print(result.partition_results([Ok(1), Error("b"), Ok(3)]))
```

```stdout visible = true
([1, 3], ["b"])
```

</div>

<div class="pyk-api">

## unwrap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">unwrap</span>(<span class="p">r</span>: Result(t, e)) -&gt; t</code></pre>

The value of an `Ok`; for an `Error` the program stops with a runtime
error.

<p class="pyk-api-label">Parameters</p>

- `r`: the result, which should be an `Ok`.

<p class="pyk-api-label">Returns</p>

The `Ok` value.

<p class="pyk-api-label">Example</p>

```pyking
import result
print(result.unwrap(Ok(42)))
```

```stdout visible = true
42
```

</div>

<div class="pyk-api">

## unwrap_error

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">unwrap_error</span>(<span class="p">r</span>: Result(t, e)) -&gt; e</code></pre>

The error of an `Error`; for an `Ok` the program stops with a runtime
error.

<p class="pyk-api-label">Parameters</p>

- `r`: the result, which should be an `Error`.

<p class="pyk-api-label">Returns</p>

The error.

<p class="pyk-api-label">Example</p>

```pyking
import result
print(result.unwrap_error(Error("too big")))
```

```stdout visible = true
too big
```

</div>

<div class="pyk-api">

## unwrap_or

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">unwrap_or</span>(<span class="p">r</span>: Result(t, e), <span class="p">default</span>: t) -&gt; t</code></pre>

The value of an `Ok`, or `default` for an `Error`.

<p class="pyk-api-label">Parameters</p>

- `r`: the result.
- `default`: what to answer for an `Error`.

<p class="pyk-api-label">Returns</p>

The `Ok` value, or `default`.

<p class="pyk-api-label">Example</p>

```pyking
import result
print(result.unwrap_or(Ok(3), 0), result.unwrap_or(Error("no"), 0))
```

```stdout visible = true
3 0
```

</div>

<div class="pyk-api">

## unwrap_or_else

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">unwrap_or_else</span>(<span class="p">r</span>: Result(t, e), <span class="p">f</span>: (e) -&gt; t) -&gt; t</code></pre>

The value of an `Ok`, or what `f` makes of the error.

<p class="pyk-api-label">Parameters</p>

- `r`: the result.
- `f`: called with the error of an `Error` only.

<p class="pyk-api-label">Returns</p>

The `Ok` value, or `f(error)`.

<p class="pyk-api-label">Example</p>

```pyking
import result
print(result.unwrap_or_else(Error("four"), lam e. len(e)))
```

```stdout visible = true
4
```

</div>
