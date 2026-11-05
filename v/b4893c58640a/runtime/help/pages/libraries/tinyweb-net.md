---
title: tinyweb.net
description: "Files: saving what the program made, and loading a file the reader picks."
sidebar:
  label: net
  parent: tinyweb
  position: 6
---

Files: saving what the program made, and loading a file the reader
picks. A file saved is offered by the browser showing the page, which
is where it lands, whatever the program runs on.

```pyking
import tinyweb as tw
import tinyweb.net as net
tw.web_init(0)
c = tw.canvas(100, 100)
tw.circle(c, 50, 50, 40)
def save():
    net.save_canvas(c, "circle.png")
tw.button("Save as PNG", on_click = save)
```

```pyking norun
import tinyweb.net as net
```

| Topic | |
|---|---|
| [Files](#files) | [`save_canvas`](#netsave_canvas), [`download`](#netdownload), [`file_button`](#netfile_button), [`file_text`](#netfile_text) |

## Files

<div class="pyk-api">

### net.save_canvas

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">net.save_canvas</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">name</span>: <span class="t">String</span> = &quot;canvas.png&quot;) -&gt; ()</code></pre>

Offers what is drawn on the canvas `c` to the reader as a PNG file, on
white.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `name`: the file's name.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.net as net
tw.web_init(0)
c = tw.canvas(100, 100)
tw.rect(c, 10, 10, 80, 80)
net.save_canvas(c, "square.png")
```

</div>

<div class="pyk-api">

### net.download

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">net.download</span>(<span class="p">name</span>: <span class="t">String</span>, <span class="p">words</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Offers text to the reader as a file.

<p class="pyk-api-label">Parameters</p>

- `name`: the file's name.
- `words`: what it holds.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.net as net
tw.web_init(0)
net.download("notes.txt", "C4 D4 E4\n")
```

</div>

<div class="pyk-api">

### net.file_button

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">net.file_button</span>(
    <span class="p">title</span>: <span class="t">String</span>,
    <span class="p">on_load</span>: (<span class="t">String</span>) -&gt; () = ignore_text,
) -&gt; <span class="t">String</span></code></pre>

A button that lets the reader pick a file. Once it is read,
`on_load` is called with its name. A sound file -- WAV, MP3, OGG -- is
then a sample under the button's identifier, which `tw.play` and
`sound.start` take; any other file's text is `file_text()`.

<p class="pyk-api-label">Parameters</p>

- `title`: what the button says.
- `on_load`: what is called with the file's name.

<p class="pyk-api-label">Returns</p>

The button's identifier: its title, with a number added where
something on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import tinyweb as tw
import tinyweb.net as net
tw.web_init(0)
var song = ""
def loaded(name: String):
    print("loaded", name)
    tw.play(song)
song := net.file_button("Load a song", on_load = loaded)
```

</div>

<div class="pyk-api">

### net.file_text

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">net.file_text</span>() -&gt; <span class="t">String</span></code></pre>

The text of the last file a `file_button` loaded that is not a sound.

<p class="pyk-api-label">Returns</p>

Its text; empty before one is loaded.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.net as net
tw.web_init(0)
def loaded(name: String):
    print(name, "holds", len(net.file_text()), "letters")
net.file_button("Open", on_load = loaded)
```

</div>
