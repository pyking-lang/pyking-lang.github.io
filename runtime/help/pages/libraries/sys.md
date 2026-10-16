---
title: sys
description: "The process this program is running as: its arguments, its name, and its environment."
---

The process this program is running as: its arguments, its name, and
its environment.

```pyking norun
import sys
```

<div class="pyk-api">

## args

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">args</span>() -&gt; [<span class="t">String</span>]</code></pre>

The arguments the program was started with, not counting the program's
own name: the words after `--` in `pyk program.pyk -- a b`.

<p class="pyk-api-label">Returns</p>

The arguments, in order; an empty list when there are none.

<p class="pyk-api-label">Example</p>

```pyking args = "red green"
import sys
for word in sys.args():
    print(word)
```

```stdout visible = true
red
green
```

</div>

<div class="pyk-api">

## env

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">env</span>() -&gt; [(<span class="t">String</span>, <span class="t">String</span>)]</code></pre>

Every environment variable the program was started with.

<p class="pyk-api-label">Returns</p>

A list of `(name, value)` pairs, in no particular order.

<p class="pyk-api-label">Example</p>

```pyking
import sys
pairs = sys.env()
print(len(pairs) >= 0)
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## env_get

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">env_get</span>(<span class="p">name</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

The value of the environment variable `name`.

<p class="pyk-api-label">Parameters</p>

- `name`: the variable, such as `"HOME"`.

<p class="pyk-api-label">Returns</p>

Its value, or `""` when it is not set. A variable set to `""` answers
the same, and `env_has` tells the two apart.

<p class="pyk-api-label">Example</p>

```pyking
import sys
print(sys.env_get("PYKING_EXAMPLE_UNSET") == "")
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## env_has

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">env_has</span>(<span class="p">name</span>: <span class="t">String</span>) -&gt; <span class="t">Bool</span></code></pre>

Tells whether the environment variable `name` is set, even to `""`.

<p class="pyk-api-label">Parameters</p>

- `name`: the variable, such as `"HOME"`.

<p class="pyk-api-label">Returns</p>

`true` when it is set, `false` otherwise.

<p class="pyk-api-label">Example</p>

```pyking
import sys
print(sys.env_has("PYKING_EXAMPLE_UNSET"))
```

```stdout visible = true
false
```

</div>

<div class="pyk-api">

## exit

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">exit</span>(<span class="p">code</span>: <span class="t">Int</span>) -&gt; ()</code></pre>

Ends the program at once with exit status `code`. Output written so
far is written out first, and nothing after the call runs. A program
that never calls it ends with status 0.

<p class="pyk-api-label">Parameters</p>

- `code`: the exit status; 0 means success, anything else failure.

<p class="pyk-api-label">Example</p>

```pyking
import sys
print("done")
sys.exit(0)
print("never printed")
```

```stdout visible = true
done
```

</div>

<div class="pyk-api">

## prog_name

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">prog_name</span>() -&gt; <span class="t">String</span></code></pre>

The name the program was started as, without its directory, such as
`hello.pyk` or `hello`.

<p class="pyk-api-label">Returns</p>

The name; `""` where the host does not know one, as in a browser.

<p class="pyk-api-label">Example</p>

```pyking norun
import sys
print(len(sys.prog_name()) > 0)
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## prog_path

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">prog_path</span>() -&gt; <span class="t">String</span></code></pre>

The directory the program was started from.

<p class="pyk-api-label">Returns</p>

The directory as an absolute path; `""` where the host does not know
one, as in a browser.

<p class="pyk-api-label">Example</p>

```pyking norun
import sys
print(len(sys.prog_path()) > 0)
```

```stdout visible = true
true
```

</div>
