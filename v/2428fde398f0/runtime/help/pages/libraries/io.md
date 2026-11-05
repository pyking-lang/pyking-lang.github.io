---
title: io
description: "Standard input and standard output."
---

Standard input and standard output.

`print` writes to the same standard output as `write` and
`write_line`, so all three interleave in the order they ran. Every
read first writes out whatever has been written so far, so a prompt
is on screen before the program waits for an answer.

```pyking norun
import io
```

<div class="pyk-api">

## is_eof

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">is_eof</span>() -&gt; <span class="t">Bool</span></code></pre>

Tells whether standard input has been read to the end. `read_line`
answers `""` both for an empty line and at the end of the input, and
this is how a program tells the two apart.

<p class="pyk-api-label">Returns</p>

`true` when nothing is left to read, `false` otherwise.

<p class="pyk-api-label">Example</p>

```pyking stdin = "only line\n"
import io
print(io.is_eof())
print(io.read_line())
print(io.is_eof())
```

```stdout visible = true
false
only line
true
```

</div>

<div class="pyk-api">

## read

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">read</span>() -&gt; <span class="t">String</span></code></pre>

Reads everything left on standard input, from where the last read
stopped to the end, line endings included.

<p class="pyk-api-label">Returns</p>

The rest of the input, or `""` when nothing is left.

<p class="pyk-api-label">Example</p>

```pyking stdin = "one\ntwo\n"
import io
rest = io.read()
print(rest == "one\ntwo\n")
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## read_line

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">read_line</span>(<span class="p">prompt</span>: <span class="t">String</span> = &quot;&quot;) -&gt; <span class="t">String</span></code></pre>

Writes `prompt`, with no newline, then reads one line of standard input.
The line ending is not part of the answer.

<p class="pyk-api-label">Parameters</p>

- `prompt`: what to show before waiting for the line; nothing by default.

<p class="pyk-api-label">Returns</p>

The line, or `""` at the end of the input. Use `is_eof` to tell an
empty line from the end.

<p class="pyk-api-label">Example</p>

```pyking stdin = "Ada\n"
import io
name = io.read_line("Your name: ")
print("Hello,", name)
```

```stdout visible = true
Your name: Hello, Ada
```

</div>

<div class="pyk-api">

## write

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">write</span>(<span class="p">text</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Writes `text` to standard output exactly as it is, with no newline
after it. Use it to build a line from several pieces, and `write_line`
or `print` to end it.

<p class="pyk-api-label">Parameters</p>

- `text`: the characters to write.

<p class="pyk-api-label">Example</p>

```pyking
import io
io.write("one, ")
io.write("two")
io.write_line(".")
```

```stdout visible = true
one, two.
```

</div>

<div class="pyk-api">

## write_line

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">write_line</span>(<span class="p">text</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Writes `text` to standard output, then a newline. Unlike `print`, it
takes exactly one string and writes it as it is.

<p class="pyk-api-label">Parameters</p>

- `text`: the line to write, without its newline.

<p class="pyk-api-label">Example</p>

```pyking
import io
io.write_line("first line")
io.write_line("second line")
```

```stdout visible = true
first line
second line
```

</div>
