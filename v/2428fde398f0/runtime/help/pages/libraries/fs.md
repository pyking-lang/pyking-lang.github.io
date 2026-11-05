---
title: fs
description: "Reading and writing files."
---

Reading and writing files.

Reading a file that is not there, or writing where the host does not
allow it, is undefined. Call `exists` first.

```pyking norun
import fs
```

<div class="pyk-api">

## exists

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">exists</span>(<span class="p">path</span>: <span class="t">String</span>) -&gt; <span class="t">Bool</span></code></pre>

Tells whether there is a file at `path`.

<p class="pyk-api-label">Parameters</p>

- `path`: the file, relative to the directory the program runs in, or absolute.

<p class="pyk-api-label">Returns</p>

`true` when the file exists, `false` otherwise.

<p class="pyk-api-label">Example</p>

```pyking norun
import fs
print(fs.exists("no-such-file.txt"))
```

```stdout visible = true
false
```

</div>

<div class="pyk-api">

## read_text

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">read_text</span>(<span class="p">path</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

Reads the whole file at `path` as text. Reading a file that does not
exist is undefined, so check with `exists` first.

<p class="pyk-api-label">Parameters</p>

- `path`: the file, relative to the directory the program runs in, or absolute.

<p class="pyk-api-label">Returns</p>

The file's contents.

<p class="pyk-api-label">Example</p>

```pyking norun
import fs
fs.write_text("notes.txt", "milk\neggs\n")
if fs.exists("notes.txt"):
    print(fs.read_text("notes.txt"))
```

```stdout visible = true
milk
eggs

```

</div>

<div class="pyk-api">

## write_text

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">write_text</span>(<span class="p">path</span>: <span class="t">String</span>, <span class="p">text</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Writes `text` to the file at `path`, replacing what it held, and
creating it if it does not exist. Writing where the host does not
allow it is undefined.

<p class="pyk-api-label">Parameters</p>

- `path`: the file, relative to the directory the program runs in, or absolute.
- `text`: the new contents.

<p class="pyk-api-label">Example</p>

```pyking norun
import fs
fs.write_text("greeting.txt", "hello")
print(fs.read_text("greeting.txt"))
```

```stdout visible = true
hello
```

</div>
