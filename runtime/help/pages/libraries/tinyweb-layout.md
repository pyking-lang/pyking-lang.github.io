---
title: tinyweb.layout
description: "Where what is made next goes on the page, and a box to write text in."
sidebar:
  label: layout
  parent: tinyweb
  position: 5
---

Where what is made next goes on the page, and a box to write text in.

Everything made goes below what the page already holds, unless a row
or a column is opened with `inside`: then it goes in it, side by side
in a row, until `outside`.

```pyking
import tinyweb as tw
import tinyweb.layout as layout
tw.web_init(0)
controls = layout.row()
layout.inside(controls)
tw.button("Play")
tw.button("Stop")
layout.outside()
tw.canvas(200, 100)
```

```pyking norun
import tinyweb.layout as layout
```

| Topic | |
|---|---|
| [Rows and columns](#rows-and-columns) | [`row`](#layoutrow), [`column`](#layoutcolumn), [`inside`](#layoutinside), [`outside`](#layoutoutside) |
| [Text areas](#text-areas) | [`text_area`](#layouttext_area) |

## Rows and columns

<div class="pyk-api">

### layout.row

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">layout.row</span>() -&gt; <span class="t">String</span></code></pre>

A row: what is made inside it goes side by side.

<p class="pyk-api-label">Returns</p>

Its identifier, which `inside` takes: `"row"`, with a number added
where something on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.layout as layout
tw.web_init(0)
print(layout.row())
```

```stdout visible = true
row
```

</div>

<div class="pyk-api">

### layout.column

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">layout.column</span>() -&gt; <span class="t">String</span></code></pre>

A column: what is made inside it goes one below the other, in a box of
its own, which a row can hold.

<p class="pyk-api-label">Returns</p>

Its identifier, which `inside` takes: `"column"`, with a number added
where something on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.layout as layout
tw.web_init(0)
print(layout.column())
```

```stdout visible = true
column
```

</div>

<div class="pyk-api">

### layout.inside

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">layout.inside</span>(<span class="p">id</span>: <span class="t">String</span>) -&gt; ()</code></pre>

What is made from now on goes into the row or column `id`.

<p class="pyk-api-label">Parameters</p>

- `id`: the row or column, as `row` or `column` answered.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.layout as layout
tw.web_init(0)
r = layout.row()
layout.inside(r)
tw.label("Left")
tw.label("Right")
layout.outside()
```

</div>

<div class="pyk-api">

### layout.outside

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">layout.outside</span>() -&gt; ()</code></pre>

What is made from now on goes on the page again, below what it holds.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.layout as layout
tw.web_init(0)
layout.inside(layout.row())
tw.button("In the row")
layout.outside()
tw.label("Below it")
```

</div>

## Text areas

<div class="pyk-api">

### layout.text_area

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">layout.text_area</span>(
    <span class="p">words</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">rows</span>: <span class="t">Int</span> = 4,
    <span class="p">columns</span>: <span class="t">Int</span> = 40,
    <span class="p">on_change</span>: (<span class="t">String</span>) -&gt; () = ignore_text,
) -&gt; <span class="t">String</span></code></pre>

A box of text of several lines, to read and edit: a score, a note, a
program. `on_change` is called with what it holds after each edit;
`tw.value_of` reads it at any time, and `tw.set_text` changes it.

<p class="pyk-api-label">Parameters</p>

- `words`: what it holds to start with.
- `rows`: how many lines tall it is.
- `columns`: how many letters wide it is.
- `on_change`: what is called with what it holds after each edit.

<p class="pyk-api-label">Returns</p>

Its identifier: `"text"`, with a number added where something on the
page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.layout as layout
tw.web_init(0)
def edited(words: String):
    print(len(words), "letters")
print(layout.text_area("C4 D4 E4", rows = 3, on_change = edited))
```

```stdout visible = true
text
```

</div>
