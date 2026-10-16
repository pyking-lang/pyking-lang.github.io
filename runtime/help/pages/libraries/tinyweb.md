---
title: tinyweb
description: "Graphics, widgets and sound on a web page, kept in time with each other."
---

Graphics, widgets and sound on a web page, kept in time with each
other.

A program builds its page by calling the functions below: each
canvas, button, label and slider goes below the ones before it. A
canvas is drawn on with `clear`, `circle`, `rect`, `line` and `text`,
in pixels from its top left corner, and a color is a CSS color such
as "#ff0000" or "red".

A page has a look of its own, the same wherever it is shown: `theme`
picks one of tinyweb's, the `_style` functions change every element
of one kind, and `set_style` and `set_colors` change one element.

A program that handed the page a function -- `on_click`, `on_frame`
and the rest -- keeps running after its last line: the page calls the
function each time the event happens. Sound and pictures are kept in
step by one clock, `time`: a frame is drawn for a time, and `play`
can start a sound at one.

tinyweb needs a page to show. A program starts with
`web_init(port)`, which serves one and prints its address wherever
the program runs -- `pyk program.pyk`, the REPL, or any compiled
target -- and does nothing in a browser, where the page is there
already: on a web page, and beside the program in the notebook and
the playground.

```pyking norun
import tinyweb
```

<div class="pyk-api">

## button

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">button</span>(<span class="p">title</span>: <span class="t">String</span>, <span class="p">on_click</span>: () -&gt; () = nothing) -&gt; <span class="t">Int</span></code></pre>

Adds a button below everything already on the page.

<p class="pyk-api-label">Parameters</p>

- `title`: the text on the button.
- `on_click`: the function to call each time it is pressed; by default nothing happens.

<p class="pyk-api-label">Returns</p>

The button's number.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
var count = 0
def pressed():
    count := count + 1
    print("pressed", count, "times")
tw.button("Count", on_click = pressed)
```

</div>

<div class="pyk-api">

## button_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">button_style</span>(
    <span class="p">background</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">color</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">border</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">radius</span>: <span class="t">Int</span> = -1,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">size</span>: <span class="t">Int</span> = -1,
    <span class="p">padding</span>: <span class="t">Int</span> = -1,
) -&gt; ()</code></pre>

Changes every button on the page, those made already and those made
later. Only what is named changes; the rest stays as the theme has it.

<p class="pyk-api-label">Parameters</p>

- `background`: a CSS color for the button.
- `color`: a CSS color for its text.
- `border`: a CSS border, such as `"2px solid navy"` or `"none"`.
- `radius`: how round its corners are, in pixels.
- `font`: a font, such as `"serif"` or `"monospace"`.
- `size`: the size of its text, in pixels.
- `padding`: the space between its text and its edge, in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.button_style(background = "#2f6fdd", color = "white", border = "none", radius = 14, padding = 10)
tw.button("Start")
tw.button("Stop")
```

</div>

<div class="pyk-api">

## canvas

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">canvas</span>(<span class="p">width</span>: <span class="t">Int</span>, <span class="p">height</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

Adds a canvas to draw on, below everything already on the page. It
starts white.

<p class="pyk-api-label">Parameters</p>

- `width`: its width in pixels.
- `height`: its height in pixels.

<p class="pyk-api-label">Returns</p>

The canvas's number, which the drawing functions take as `c`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 60)
tw.rect(c, 10, 10, 180, 40, "teal")
```

</div>

<div class="pyk-api">

## canvas_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">canvas_style</span>(<span class="p">border</span>: <span class="t">String</span> = &quot;&quot;, <span class="p">radius</span>: <span class="t">Int</span> = -1) -&gt; ()</code></pre>

Changes the frame of every canvas on the page, those made already and
those made later. What is drawn on a canvas is not changed.

<p class="pyk-api-label">Parameters</p>

- `border`: a CSS border, such as `"3px solid black"` or `"none"`.
- `radius`: how round its corners are, in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.canvas_style(border = "3px solid teal", radius = 12)
c = tw.canvas(200, 80)
tw.rect(c, 20, 20, 160, 40, "teal")
```

</div>

<div class="pyk-api">

## circle

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">circle</span>(
    <span class="p">c</span>: <span class="t">Int</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">radius</span>: <span class="t">Int</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
) -&gt; ()</code></pre>

Draws a filled circle on the canvas `c`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the centre, in pixels from the canvas's top left corner.
- `radius`: the radius in pixels.
- `color`: a CSS color; black by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.circle(c, 100, 50, 40, "gold")
tw.circle(c, 100, 50, 20)
```

</div>

<div class="pyk-api">

## clear

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">clear</span>(<span class="p">c</span>: <span class="t">Int</span>, <span class="p">color</span>: <span class="t">String</span> = &quot;#ffffff&quot;) -&gt; ()</code></pre>

Fills the whole canvas `c` with one color, wiping out what was drawn.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `color`: a CSS color, such as `"#ff0000"` or `"red"`; white by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 60)
tw.clear(c, "navy")
```

</div>

<div class="pyk-api">

## label

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">label</span>(<span class="p">text</span>: <span class="t">String</span>) -&gt; <span class="t">Int</span></code></pre>

Adds a line of text below everything already on the page.

<p class="pyk-api-label">Parameters</p>

- `text`: what the label says.

<p class="pyk-api-label">Returns</p>

The label's number, which `set_label` takes to change the text.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.label("Hello from tinyweb")
```

</div>

<div class="pyk-api">

## label_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">label_style</span>(
    <span class="p">background</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">color</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">border</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">radius</span>: <span class="t">Int</span> = -1,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">size</span>: <span class="t">Int</span> = -1,
    <span class="p">padding</span>: <span class="t">Int</span> = -1,
) -&gt; ()</code></pre>

Changes every label on the page, those made already and those made
later. Only what is named changes; the rest stays as the theme has it.

<p class="pyk-api-label">Parameters</p>

- `background`: a CSS color behind the text.
- `color`: a CSS color for the text.
- `border`: a CSS border, such as `"1px solid gray"`.
- `radius`: how round its corners are, in pixels.
- `font`: a font, such as `"serif"` or `"monospace"`.
- `size`: the size of the text, in pixels.
- `padding`: the space between the text and its edge, in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.label_style(background = "lightyellow", border = "1px solid gold", radius = 6, size = 18, padding = 8)
tw.label("Note: labels can look like this.")
tw.label("And so does every other one.")
```

</div>

<div class="pyk-api">

## line

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">line</span>(
    <span class="p">c</span>: <span class="t">Int</span>,
    <span class="p">x1</span>: <span class="t">Int</span>,
    <span class="p">y1</span>: <span class="t">Int</span>,
    <span class="p">x2</span>: <span class="t">Int</span>,
    <span class="p">y2</span>: <span class="t">Int</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
) -&gt; ()</code></pre>

Draws a straight line on the canvas `c`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x1`, `y1`: where the line starts, in pixels.
- `x2`, `y2`: where it ends, in pixels.
- `color`: a CSS color; black by default.
- `width`: how thick it is, in pixels; 1 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.line(c, 0, 0, 200, 100)
tw.line(c, 0, 100, 200, 0, "red", 4)
```

</div>

<div class="pyk-api">

## load_sample

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">load_sample</span>(<span class="p">name</span>: <span class="t">String</span>) -&gt; <span class="t">Int</span></code></pre>

Starts loading a sound file, so that `play` can play it without a
delay. The file is looked for beside the page first, then among the
samples tinyweb ships: `kick1.wav`, `snare1.wav`, `hihat1.wav` and
`piano_c1.wav`.

<p class="pyk-api-label">Parameters</p>

- `name`: the file's name, such as `"kick1.wav"`.

<p class="pyk-api-label">Returns</p>

The sample's number, which `play` takes.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
kick = tw.load_sample("kick1.wav")
def hit():
    tw.play(kick)
tw.button("Kick", on_click = hit)
```

</div>

<div class="pyk-api">

## on_frame

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_frame</span>(<span class="p">draw</span>: (<span class="t">Float</span>) -&gt; ()) -&gt; ()</code></pre>

Calls `draw` before each frame the page shows, about 60 times a second,
with the time the frame is for. This is how a program animates.

<p class="pyk-api-label">Parameters</p>

- `draw`: the function to call; it is given the frame's time in seconds, as `time` reads it.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 60)
def draw(t: Float):
    tw.clear(c)
    x = int(t * 50.0) - int(t * 50.0) / 200 * 200
    tw.circle(c, x, 30, 10, "orange")
tw.on_frame(draw)
```

</div>

<div class="pyk-api">

## on_key

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_key</span>(<span class="p">pressed</span>: (<span class="t">String</span>) -&gt; ()) -&gt; ()</code></pre>

Calls `pressed` each time a key is pressed while the page has the
focus.

<p class="pyk-api-label">Parameters</p>

- `pressed`: the function to call; it is given the key: a letter or digit as itself, and otherwise the browser's name for it, such as `"ArrowLeft"`, `"Enter"` or `" "`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
shown = tw.label("press a key")
def pressed(key: String):
    tw.set_label(shown, "you pressed " ++ key)
tw.on_key(pressed)
```

</div>

<div class="pyk-api">

## on_mouse

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_mouse</span>(<span class="p">c</span>: <span class="t">Int</span>, <span class="p">click</span>: (<span class="t">Int</span>, <span class="t">Int</span>) -&gt; ()) -&gt; ()</code></pre>

Calls `click` each time the canvas `c` is clicked, with where the click
was.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `click`: the function to call; it is given `x` and `y` in pixels from the canvas's top left corner.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
def click(x: Int, y: Int):
    tw.circle(c, x, y, 5, "red")
tw.on_mouse(c, click)
```

</div>

<div class="pyk-api">

## page_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">page_style</span>(
    <span class="p">background</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">color</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">size</span>: <span class="t">Int</span> = -1,
    <span class="p">padding</span>: <span class="t">Int</span> = -1,
    <span class="p">gap</span>: <span class="t">Int</span> = -1,
) -&gt; ()</code></pre>

Changes the page itself: its background, and the text and spacing
everything on it shares. Only what is named changes; the rest stays
as the theme has it.

<p class="pyk-api-label">Parameters</p>

- `background`: a CSS color for the page.
- `color`: a CSS color for its text.
- `font`: a font, such as `"serif"`, `"monospace"` or `"Georgia"`.
- `size`: the size of its text, in pixels.
- `padding`: the space around everything on it, in pixels.
- `gap`: the space between one element and the next, in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.page_style(background = "#fdf6e3", color = "#586e75", font = "serif", size = 18, gap = 16)
tw.label("Solarized, with room to breathe")
tw.button("OK")
```

</div>

<div class="pyk-api">

## play

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">play</span>(
    <span class="p">sample</span>: <span class="t">Int</span>,
    <span class="p">at</span>: <span class="t">Float</span> = 0.0,
    <span class="p">volume</span>: <span class="t">Float</span> = 1.0,
    <span class="p">rate</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Plays a sample that `load_sample` loaded.

<p class="pyk-api-label">Parameters</p>

- `sample`: the sample's number, as `load_sample` answered.
- `at`: when to start, in seconds on the page's clock (see `time`), which counts from when the page started rather than from now: two seconds from now is `at = tw.time() + 2.0`, while `at = 2.0` is already past once the page has been open two seconds. A time already past, such as the default 0.0, means now.
- `volume`: how loud, as a multiple of the sample's own volume; 1.0 by default.
- `rate`: how fast, as a multiple of normal speed; 2.0 plays it twice as fast and an octave higher. 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
piano = tw.load_sample("piano_c1.wav")
def chord():
    start = tw.time()
    tw.play(piano, at = start)
    tw.play(piano, at = start + 0.25, rate = 1.25)
    tw.play(piano, at = start + 0.5, volume = 0.7, rate = 1.5)
tw.button("Play", on_click = chord)
```

</div>

<div class="pyk-api">

## play_file

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">play_file</span>(<span class="p">name</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Plays a sound file now, loading it first if nothing has loaded it yet.
For a sound played often, `load_sample` once and then `play` is
quicker.

<p class="pyk-api-label">Parameters</p>

- `name`: the file's name, such as `"snare1.wav"`; see `load_sample` for where it is looked for.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
def hit():
    tw.play_file("snare1.wav")
tw.button("Snare", on_click = hit)
```

</div>

<div class="pyk-api">

## rect

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">rect</span>(
    <span class="p">c</span>: <span class="t">Int</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">width</span>: <span class="t">Int</span>,
    <span class="p">height</span>: <span class="t">Int</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
) -&gt; ()</code></pre>

Draws a filled rectangle on the canvas `c`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the top left corner, in pixels from the canvas's top left corner.
- `width`, `height`: the size in pixels.
- `color`: a CSS color; black by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.rect(c, 20, 20, 160, 60, "#4caf50")
```

</div>

<div class="pyk-api">

## set_colors

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">set_colors</span>(
    <span class="p">id</span>: <span class="t">Int</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">background</span>: <span class="t">String</span> = &quot;&quot;,
) -&gt; ()</code></pre>

Changes the colors of one button, label or slider. It wins over the
theme and over the `_style` functions.

<p class="pyk-api-label">Parameters</p>

- `id`: the element, as `button`, `label` or `slider` answered.
- `color`: a CSS color for its text, or for a slider's track and handle.
- `background`: a CSS color behind it.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
ok = tw.button("OK")
cancel = tw.button("Cancel")
tw.set_colors(ok, color = "white", background = "seagreen")
tw.set_colors(cancel, color = "white", background = "firebrick")
```

</div>

<div class="pyk-api">

## set_label

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">set_label</span>(<span class="p">id</span>: <span class="t">Int</span>, <span class="p">text</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Replaces the text of a label.

<p class="pyk-api-label">Parameters</p>

- `id`: the label's number, as `label` answered.
- `text`: the new text.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
status = tw.label("waiting")
def pressed():
    tw.set_label(status, "pressed")
tw.button("Press me", on_click = pressed)
```

</div>

<div class="pyk-api">

## set_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">set_style</span>(
    <span class="p">id</span>: <span class="t">Int</span>,
    <span class="p">background</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">color</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">border</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">radius</span>: <span class="t">Int</span> = -1,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">size</span>: <span class="t">Int</span> = -1,
    <span class="p">padding</span>: <span class="t">Int</span> = -1,
    <span class="p">accent</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">width</span>: <span class="t">Int</span> = -1,
) -&gt; ()</code></pre>

Changes how one element is drawn: a button, a label, a slider or a
canvas. It wins over the theme and over the `_style` functions. Only
what is named changes.

<p class="pyk-api-label">Parameters</p>

- `id`: the element, as the function that made it answered.
- `background`: a CSS color behind it.
- `color`: a CSS color for its text.
- `border`: a CSS border, such as `"2px dashed orange"`.
- `radius`: how round its corners are, in pixels.
- `font`: a font, such as `"serif"` or `"monospace"`.
- `size`: the size of its text, in pixels.
- `padding`: the space between its text and its edge, in pixels.
- `accent`: a CSS color for a slider's track and handle.
- `width`: its width, in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.button("Normal")
big = tw.button("Important")
tw.set_style(big, border = "2px dashed orange", radius = 0, size = 22, padding = 12)
title = tw.label("A title")
tw.set_style(title, font = "serif", size = 28)
```

</div>

<div class="pyk-api">

## slider

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">slider</span>(
    <span class="p">low</span>: <span class="t">Int</span>,
    <span class="p">high</span>: <span class="t">Int</span>,
    <span class="p">value</span>: <span class="t">Int</span>,
    <span class="p">on_change</span>: (<span class="t">Int</span>) -&gt; () = ignore,
) -&gt; <span class="t">Int</span></code></pre>

Adds a slider below everything already on the page.

<p class="pyk-api-label">Parameters</p>

- `low`, `high`: the smallest and largest values it can be set to.
- `value`: where it starts.
- `on_change`: the function to call with each new value it is moved to; by default nothing happens.

<p class="pyk-api-label">Returns</p>

The slider's number.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
shown = tw.label("50")
def moved(value: Int):
    tw.set_label(shown, string(value))
tw.slider(0, 100, 50, on_change = moved)
```

</div>

<div class="pyk-api">

## slider_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">slider_style</span>(
    <span class="p">accent</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">width</span>: <span class="t">Int</span> = -1,
    <span class="p">color</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">size</span>: <span class="t">Int</span> = -1,
) -&gt; ()</code></pre>

Changes every slider on the page, those made already and those made
later. Only what is named changes; the rest stays as the theme has it.

<p class="pyk-api-label">Parameters</p>

- `accent`: a CSS color for the slider's track and handle.
- `width`: how long the slider is, in pixels.
- `color`: a CSS color for the value shown beside it.
- `font`: a font for that value.
- `size`: the size of that value's text, in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.slider_style(accent = "crimson", width = 300, size = 20)
tw.slider(0, 100, 70)
```

</div>

<div class="pyk-api">

## text

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">text</span>(
    <span class="p">c</span>: <span class="t">Int</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">words</span>: <span class="t">String</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">size</span>: <span class="t">Int</span> = 16,
) -&gt; ()</code></pre>

Writes text on the canvas `c`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the top left corner of the text, in pixels.
- `words`: the text to write.
- `color`: a CSS color; black by default.
- `size`: the height of the letters in pixels; 16 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 60)
tw.text(c, 10, 10, "Score: 42", "purple", 24)
```

</div>

<div class="pyk-api">

## theme

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">theme</span>(<span class="p">name</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Gives the whole page one of tinyweb's looks: its colors, fonts, and
how buttons, sliders and canvases are drawn. A page starts in
`"light"`, which looks the same wherever it is shown. Call it before
any of the `_style` functions, since it forgets what they changed.

The themes are `"light"`, `"dark"`, `"plain"` (the browser's own
buttons and sliders, on white), `"paper"` (ink on warm paper, with a
serif font) and `"retro"` (green on black, in a typewriter font). A
name that is none of these changes nothing, and says so with `debug`.

<p class="pyk-api-label">Parameters</p>

- `name`: the theme.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.theme("dark")
tw.label("A dark page")
tw.button("Press me")
tw.slider(0, 10, 3)
c = tw.canvas(160, 40)
tw.circle(c, 20, 20, 12, "orange")
```

</div>

<div class="pyk-api">

## time

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">time</span>() -&gt; <span class="t">Float</span></code></pre>

Reads the page's clock. Once sound has started this is the audio clock,
so a time read here can be given to `play` to start a sound exactly
then.

<p class="pyk-api-label">Returns</p>

The time in seconds.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
print(tw.time() >= 0.0)
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## web_init

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">web_init</span>(<span class="p">port</span>: <span class="t">Int</span>) -&gt; ()</code></pre>

Starts the program's page. Run as `pyk program.pyk` or compiled, it
serves the page on `port` and prints the address to open; in a browser,
the notebook or the playground the page is already there and it does
nothing. Call it before any other tinyweb function.

<p class="pyk-api-label">Parameters</p>

- `port`: the port to serve on; 0 picks any free one.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.label("The page is ready.")
```

</div>
