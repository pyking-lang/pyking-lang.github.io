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

Shapes also come as `ellipse`, `arc`, `polygon`, `path` and `curve`,
each with an outline and transparency; `translate`, `rotate`, `scale`,
`push` and `pop` move what is drawn after them, `image` draws a
picture, and `shadow` and `blend` give it a glow. Colors can be built
with the submodule `tinyweb.colors` (`import tinyweb.colors as
colors`, then `colors.rgb(255, 136, 0)`). Checkboxes, radio buttons, a
dropdown and fields to type into sit beside the buttons and sliders.

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

## arc

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">arc</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">radius</span>: <span class="t">Int</span>,
    <span class="p">start</span>: <span class="t">Float</span>,
    <span class="p">end</span>: <span class="t">Float</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">outline</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">outline_width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a slice of a circle on the canvas `c`, from the angle `start` to
the angle `end`, in degrees: 0 points right, and angles turn
clockwise, as the canvas's `y` grows downwards.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the centre of the circle, in pixels.
- `radius`: its radius in pixels.
- `start`, `end`: where the slice starts and ends, in degrees.
- `color`: a CSS color to fill it with; black by default, and `""` for none, which leaves only the curved edge to outline.
- `outline`: a CSS color to outline it with; `""`, none, by default.
- `outline_width`: how thick the outline is, in pixels; 1 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.arc(c, 60, 50, 40, 30.0, 330.0, "gold")
tw.arc(c, 150, 50, 40, 180.0, 360.0, "", outline = "red", outline_width = 4)
```

</div>

<div class="pyk-api">

## bezier

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bezier</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x1</span>: <span class="t">Int</span>,
    <span class="p">y1</span>: <span class="t">Int</span>,
    <span class="p">ax</span>: <span class="t">Int</span>,
    <span class="p">ay</span>: <span class="t">Int</span>,
    <span class="p">bx</span>: <span class="t">Int</span>,
    <span class="p">by</span>: <span class="t">Int</span>,
    <span class="p">x2</span>: <span class="t">Int</span>,
    <span class="p">y2</span>: <span class="t">Int</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a curve from (`x1`, `y1`) to (`x2`, `y2`) pulled towards two
control points, the first near the start and the second near the end:
a cubic Bézier curve, which can bend two ways like an S.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x1`, `y1`: where the curve starts, in pixels.
- `ax`, `ay`: the control point near the start.
- `bx`, `by`: the control point near the end.
- `x2`, `y2`: where it ends, in pixels.
- `color`: a CSS color; black by default.
- `width`: how thick it is, in pixels; 1 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.bezier(c, 10, 50, 60, -20, 140, 120, 190, 50, "crimson", 3)
```

</div>

<div class="pyk-api">

## bitmap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bitmap</span>(<span class="p">width</span>: <span class="t">Int</span>, <span class="p">height</span>: <span class="t">Int</span>) -&gt; <span class="t">String</span></code></pre>

Makes a bitmap: a picture the program builds pixel by pixel. Setting
a pixel sends nothing to the page; `show_bitmap` draws the bitmap on a
canvas in one go. It starts black.

<p class="pyk-api-label">Parameters</p>

- `width`: its width in pixels.
- `height`: its height in pixels.

<p class="pyk-api-label">Returns</p>

The bitmap's identifier, which the other bitmap functions take as
`b`: `"bitmap"`, with a number added where something on the page has
that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(64, 64)
b = tw.bitmap(64, 64)
for y in range(64):
    for x in range(64):
        tw.set_pixel(b, x, y, tw.pixel_color(x * 4, y * 4, 128))
tw.show_bitmap(c, b)
```

</div>

<div class="pyk-api">

## blend

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">blend</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">mode</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Says how what is drawn on the canvas `c` after it mixes with what is
there: `"normal"` paints over it, and `"add"` adds the light of the two,
so overlapping colors glow.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `mode`: `"normal"` or `"add"`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.clear(c, "black")
tw.blend(c, "add")
tw.circle(c, 80, 50, 35, "#c03000")
tw.circle(c, 120, 50, 35, "#0030c0")
tw.blend(c, "normal")
```

</div>

<div class="pyk-api">

## blue

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">blue</span>(<span class="p">color</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

How much blue a pixel's color has.

<p class="pyk-api-label">Parameters</p>

- `color`: a color as `pixel_color` makes them.

<p class="pyk-api-label">Returns</p>

The blue part, from 0 to 255.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
print(tw.blue(tw.pixel_color(255, 136, 64)))
```

```stdout visible = true
64
```

</div>

<div class="pyk-api">

## button

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">button</span>(<span class="p">title</span>: <span class="t">String</span>, <span class="p">on_click</span>: () -&gt; () = nothing) -&gt; <span class="t">String</span></code></pre>

Adds a button below everything already on the page.

<p class="pyk-api-label">Parameters</p>

- `title`: the text on the button.
- `on_click`: the function to call each time it is pressed; by default nothing happens.

<p class="pyk-api-label">Returns</p>

The button's identifier: its title, with a number added where
something on the page has that name already.

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

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">canvas</span>(<span class="p">width</span>: <span class="t">Int</span>, <span class="p">height</span>: <span class="t">Int</span>) -&gt; <span class="t">String</span></code></pre>

Adds a canvas to draw on, below everything already on the page. It
starts white.

<p class="pyk-api-label">Parameters</p>

- `width`: its width in pixels.
- `height`: its height in pixels.

<p class="pyk-api-label">Returns</p>

The canvas's identifier, which the drawing functions take as `c`:
`"canvas"`, with a number added where something on the page has
that name already.

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

## checkbox

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">checkbox</span>(
    <span class="p">title</span>: <span class="t">String</span>,
    <span class="p">checked</span>: <span class="t">Bool</span> = false,
    <span class="p">on_change</span>: (<span class="t">Bool</span>) -&gt; () = ignore_bool,
) -&gt; <span class="t">String</span></code></pre>

Adds a checkbox, with its title beside it, below everything already on
the page.

<p class="pyk-api-label">Parameters</p>

- `title`: the text beside the box.
- `checked`: whether it starts ticked; `false` by default.
- `on_change`: the function to call each time the reader ticks or clears it, with whether it is ticked now; by default nothing happens.

<p class="pyk-api-label">Returns</p>

The checkbox's identifier: its title, with a number added where
something on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
shown = tw.label("trails are off")
def changed(on: Bool):
    tw.set_label(shown, if on then "trails are on" else "trails are off")
tw.checkbox("Trails", on_change = changed)
```

</div>

<div class="pyk-api">

## choice

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">choice</span>(
    <span class="p">options</span>: [<span class="t">String</span>],
    <span class="p">chosen</span>: <span class="t">Int</span> = 0,
    <span class="p">on_change</span>: (<span class="t">Int</span>) -&gt; () = ignore,
) -&gt; <span class="t">String</span></code></pre>

Adds a dropdown to choose one of several options from, below
everything already on the page.

<p class="pyk-api-label">Parameters</p>

- `options`: the choices, in the order they are shown.
- `chosen`: the position of the one chosen at first; 0, the first, by default.
- `on_change`: the function to call when the reader chooses another, with its position; by default nothing happens.

<p class="pyk-api-label">Returns</p>

The dropdown's identifier: `"choice"`, with a number added where
something on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
shown = tw.label("chose 0")
def changed(position: Int):
    tw.set_label(shown, "chose " ++ string(position))
tw.choice(["ocean", "candy", "forest"], on_change = changed)
```

</div>

<div class="pyk-api">

## circle

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">circle</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">radius</span>: <span class="t">Int</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">outline</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">outline_width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a circle on the canvas `c`: filled, outlined, or both.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the centre, in pixels from the canvas's top left corner.
- `radius`: the radius in pixels.
- `color`: a CSS color to fill it with; black by default, and `""` for none.
- `outline`: a CSS color to outline it with; `""`, none, by default.
- `outline_width`: how thick the outline is, in pixels; 1 by default.
- `alpha`: how opaque it is, from 0.0 (not at all) to 1.0, the default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.circle(c, 100, 50, 40, "gold")
tw.circle(c, 100, 50, 20)
tw.circle(c, 40, 50, 25, "", outline = "red", outline_width = 3)
tw.circle(c, 160, 50, 25, "blue", alpha = 0.3)
```

</div>

<div class="pyk-api">

## clear

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">clear</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">color</span>: <span class="t">String</span> = &quot;#ffffff&quot;) -&gt; ()</code></pre>

Fills the whole canvas `c` with one color, wiping out what was drawn,
and starts it afresh: no transformation, shadow or blending is kept.

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

## clip_circle

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">clip_circle</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>, <span class="p">radius</span>: <span class="t">Int</span>) -&gt; ()</code></pre>

Keeps everything drawn on the canvas `c` after it inside a circle,
as `clip_rect` does inside a rectangle.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the centre, in pixels.
- `radius`: the radius in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.push(c)
tw.clip_circle(c, 100, 50, 40)
tw.lines(c, [(x, 0, x - 60, 100) for x in range(0, 260, 8)], "navy", 3)
tw.pop(c)
```

</div>

<div class="pyk-api">

## clip_polygon

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">clip_polygon</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">points</span>: [(<span class="t">Int</span>, <span class="t">Int</span>)]) -&gt; ()</code></pre>

Keeps everything drawn on the canvas `c` after it inside a polygon,
as `clip_rect` does inside a rectangle.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `points`: the corners, each `(x, y)` in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.push(c)
tw.clip_polygon(c, [(100, 5), (190, 95), (10, 95)])
for y in range(0, 100, 10):
    tw.rect(c, 0, y, 200, 5, "teal")
tw.pop(c)
```

</div>

<div class="pyk-api">

## clip_rect

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">clip_rect</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>, <span class="p">width</span>: <span class="t">Int</span>, <span class="p">height</span>: <span class="t">Int</span>) -&gt; ()</code></pre>

Keeps everything drawn on the canvas `c` after it inside a rectangle:
what falls outside it is not drawn. `push` before and `pop` after to
stop clipping; a second clip keeps drawing inside both.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the rectangle's top left corner, in pixels.
- `width`, `height`: its size in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.push(c)
tw.clip_rect(c, 50, 25, 100, 50)
tw.circle(c, 100, 50, 45, "orange")
tw.pop(c)
```

</div>

<div class="pyk-api">

## column

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">column</span>() -&gt; <span class="t">String</span></code></pre>

Adds a column below everything already on the page: a box whose
elements go one below another, as on the page itself. Inside a row it
stands beside the row's other elements: a picture with its caption
under it, a stack of buttons.

<p class="pyk-api-label">Returns</p>

The column's identifier, which `inside` takes: `"column"`, with a
number added where something on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
figures = tw.row()
tw.inside(figures)
left = tw.column()
tw.inside(left)
tw.canvas(100, 60)
tw.label("the first")
tw.inside(figures)
right = tw.column()
tw.inside(right)
tw.canvas(100, 60)
tw.label("the second")
tw.outside()
```

</div>

<div class="pyk-api">

## curve

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">curve</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x1</span>: <span class="t">Int</span>,
    <span class="p">y1</span>: <span class="t">Int</span>,
    <span class="p">cx</span>: <span class="t">Int</span>,
    <span class="p">cy</span>: <span class="t">Int</span>,
    <span class="p">x2</span>: <span class="t">Int</span>,
    <span class="p">y2</span>: <span class="t">Int</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a curve from (`x1`, `y1`) to (`x2`, `y2`), pulled towards the
control point (`cx`, `cy`) on the way: a quadratic Bézier curve.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x1`, `y1`: where the curve starts, in pixels.
- `cx`, `cy`: the point it bends towards, in pixels.
- `x2`, `y2`: where it ends, in pixels.
- `color`: a CSS color; black by default.
- `width`: how thick it is, in pixels; 1 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.curve(c, 10, 90, 100, -40, 190, 90, "purple", 3)
```

</div>

<div class="pyk-api">

## ellipse

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">ellipse</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">rx</span>: <span class="t">Int</span>,
    <span class="p">ry</span>: <span class="t">Int</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">outline</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">outline_width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws an ellipse on the canvas `c`: a circle stretched to `rx` across
and `ry` up and down.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the centre, in pixels.
- `rx`, `ry`: the radius across and the radius up and down, in pixels.
- `color`: a CSS color to fill it with; black by default, and `""` for none.
- `outline`: a CSS color to outline it with; `""`, none, by default.
- `outline_width`: how thick the outline is, in pixels; 1 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.ellipse(c, 100, 50, 80, 30, "skyblue", outline = "navy")
```

</div>

<div class="pyk-api">

## erase

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">erase</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>, <span class="p">width</span>: <span class="t">Int</span>, <span class="p">height</span>: <span class="t">Int</span>) -&gt; ()</code></pre>

Erases a rectangle of the canvas `c`: what was drawn there goes, and
the page behind the canvas shows through.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the top left corner, in pixels.
- `width`, `height`: the size in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.rect(c, 20, 20, 160, 60, "#444444")
tw.erase(c, 60, 35, 80, 30)
```

</div>

<div class="pyk-api">

## fill_bitmap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">fill_bitmap</span>(<span class="p">b</span>: <span class="t">String</span>, <span class="p">color</span>: <span class="t">Int</span>) -&gt; ()</code></pre>

Sets every pixel of a bitmap to one color.

<p class="pyk-api-label">Parameters</p>

- `b`: the bitmap, as `bitmap` answered.
- `color`: the color as one number, `pixel_color(r, g, b)`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(40, 40)
b = tw.bitmap(20, 20)
tw.fill_bitmap(b, tw.pixel_color(0, 128, 0))
tw.show_bitmap(c, b, scale = 2.0)
```

</div>

<div class="pyk-api">

## get_pixel

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">get_pixel</span>(<span class="p">b</span>: <span class="t">String</span>, <span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

Reads one pixel of a bitmap, at once, since the program keeps it.

<p class="pyk-api-label">Parameters</p>

- `b`: the bitmap, as `bitmap` answered.
- `x`, `y`: the pixel, from the bitmap's top left corner.

<p class="pyk-api-label">Returns</p>

Its color as one number, as `pixel_color` makes them; 0, black,
outside the bitmap.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
b = tw.bitmap(4, 4)
tw.fill_bitmap(b, tw.pixel_color(0, 0, 255))
print(tw.blue(tw.get_pixel(b, 1, 2)))
```

```stdout visible = true
255
```

</div>

<div class="pyk-api">

## green

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">green</span>(<span class="p">color</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

How much green a pixel's color has.

<p class="pyk-api-label">Parameters</p>

- `color`: a color as `pixel_color` makes them.

<p class="pyk-api-label">Returns</p>

The green part, from 0 to 255.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
print(tw.green(tw.pixel_color(255, 136, 0)))
```

```stdout visible = true
136
```

</div>

<div class="pyk-api">

## ignore2

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">ignore2</span>(<span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>) -&gt; ()</code></pre>

A function to hand `on_move` and the others that does nothing, for a
program that only reads `mouse_x` and `mouse_y`.

<p class="pyk-api-label">Parameters</p>

- `x`, `y`: where the pointer is; not used.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.on_move(c, tw.ignore2)
```

</div>

<div class="pyk-api">

## image

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">image</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">picture</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">width</span>: <span class="t">Int</span>,
    <span class="p">height</span>: <span class="t">Int</span>,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a picture `load_image` loaded on the canvas `c`, stretched to
the size given.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `picture`: the picture, as `load_image` answered.
- `x`, `y`: its top left corner, in pixels.
- `width`, `height`: its size on the canvas, in pixels.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
star = tw.load_image("star.png")
def draw(t: Float):
    tw.clear(c, "midnightblue")
    tw.image(c, star, 70, 20, 60, 60, alpha = 0.8)
tw.on_frame(draw)
```

</div>

<div class="pyk-api">

## inside

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">inside</span>(<span class="p">id</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Makes every element added after it go into a row or a column, until
`outside` or another `inside`.

<p class="pyk-api-label">Parameters</p>

- `id`: the row or column, as `row` or `column` answered.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
controls = tw.row()
tw.inside(controls)
tw.label("speed")
tw.slider(0, 10, 5)
tw.outside()
```

</div>

<div class="pyk-api">

## key_down

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">key_down</span>(<span class="p">key</span>: <span class="t">String</span>) -&gt; <span class="t">Bool</span></code></pre>

Says whether a key is held down now. A game moves its ship each frame
while an arrow is held, rather than once per press.

<p class="pyk-api-label">Parameters</p>

- `key`: the key, named as `on_key` names it, such as `"ArrowLeft"` or `"a"`.

<p class="pyk-api-label">Returns</p>

`true` while the key is held.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 60)
var x = 100
def draw(t: Float):
    if tw.key_down("ArrowLeft"):
        x := x - 2
    if tw.key_down("ArrowRight"):
        x := x + 2
    tw.clear(c)
    tw.circle(c, x, 30, 10, "teal")
tw.on_frame(draw)
```

</div>

<div class="pyk-api">

## label

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">label</span>(<span class="p">text</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

Adds a line of text below everything already on the page.

<p class="pyk-api-label">Parameters</p>

- `text`: what the label says.

<p class="pyk-api-label">Returns</p>

The label's identifier, which `set_label` takes to change the text:
the text it starts with, with a number added where something on the
page has that name already.

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
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x1</span>: <span class="t">Int</span>,
    <span class="p">y1</span>: <span class="t">Int</span>,
    <span class="p">x2</span>: <span class="t">Int</span>,
    <span class="p">y2</span>: <span class="t">Int</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a straight line on the canvas `c`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x1`, `y1`: where the line starts, in pixels.
- `x2`, `y2`: where it ends, in pixels.
- `color`: a CSS color; black by default.
- `width`: how thick it is, in pixels; 1 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

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

## line_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">line_style</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">cap</span>: <span class="t">String</span> = &quot;round&quot;,
    <span class="p">join</span>: <span class="t">String</span> = &quot;round&quot;,
    <span class="p">dash</span>: <span class="t">Float</span> = 0.0,
    <span class="p">gap</span>: <span class="t">Float</span> = 0.0,
    <span class="p">offset</span>: <span class="t">Float</span> = 0.0,
    <span class="p">dash2</span>: <span class="t">Float</span> = 0.0,
    <span class="p">gap2</span>: <span class="t">Float</span> = 0.0,
) -&gt; ()</code></pre>

Sets how lines drawn on the canvas `c` after it end and turn their
corners, and makes them dashed, until `pop` or the next `clear`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `cap`: how a line ends: `"round"`, the default, `"butt"` (cut off square at its end) or `"square"` (cut off half its width beyond).
- `join`: how a corner turns: `"round"`, the default, `"miter"` (sharp) or `"bevel"` (cut off).
- `dash`: how long each dash is, in pixels; 0.0, a solid line, by default.
- `gap`: how long the gap between two dashes is; as long as a dash by default.
- `offset`: how far into the dashes the line starts; moving it a little each frame makes the dashes march.
- `dash2`, `gap2`: a second dash and gap, taking turns with the first: a long dash and a dot, say. None by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.line_style(c, dash = 10.0, gap = 6.0)
tw.rect(c, 20, 20, 160, 60, "", outline = "black", outline_width = 2)
tw.line_style(c, cap = "butt", join = "miter")
tw.path(c, [(30, 70), (100, 30), (170, 70)], "red", 8)
tw.line_style(c, cap = "butt", dash = 16.0, gap = 4.0, dash2 = 2.0)
tw.line(c, 20, 90, 180, 90, "purple", 3)
```

</div>

<div class="pyk-api">

## lines

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">lines</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">segments</span>: [(<span class="t">Int</span>, <span class="t">Int</span>, <span class="t">Int</span>, <span class="t">Int</span>)],
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws many separate straight lines in one go, all of one color and
width: far quicker than one `line` each, for a flow field, a grid or
the branches of a tree.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `segments`: the lines, each `(x1, y1, x2, y2)` in pixels.
- `color`: a CSS color; black by default.
- `width`: how thick they are, in pixels; 1 by default.
- `alpha`: how opaque they are, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.lines(c, [(x, 0, x, 100) for x in range(0, 200, 20)], "#cccccc")
```

</div>

<div class="pyk-api">

## load_image

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">load_image</span>(<span class="p">name</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

Starts loading a picture, so that `image` can draw it. The file is
looked for beside the page first, then among the pictures tinyweb
ships: `ball.png`, `star.png` and `tile.png`. A picture drawn before
it has loaded is not drawn; the next frame draws it.

<p class="pyk-api-label">Parameters</p>

- `name`: the file's name, such as `"ball.png"`.

<p class="pyk-api-label">Returns</p>

The picture's identifier, which `image` takes: the file's name, with a
number added where something on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
ball = tw.load_image("ball.png")
def draw(t: Float):
    tw.clear(c)
    tw.image(c, ball, 80, 30, 40, 40)
tw.on_frame(draw)
```

</div>

<div class="pyk-api">

## load_sample

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">load_sample</span>(<span class="p">name</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

Starts loading a sound file, so that `play` can play it without a
delay. The file is looked for beside the page first, then among the
samples tinyweb ships: `kick1.wav`, `snare1.wav`, `hihat1.wav` and
`piano_c1.wav`.

<p class="pyk-api-label">Parameters</p>

- `name`: the file's name, such as `"kick1.wav"`.

<p class="pyk-api-label">Returns</p>

The sample's identifier, which `play` takes: the file's name, with a
number added where something on the page has that name already.

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

## measure_text

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">measure_text</span>(
    <span class="p">words</span>: <span class="t">String</span>,
    <span class="p">answer</span>: (<span class="t">Float</span>) -&gt; (),
    <span class="p">size</span>: <span class="t">Int</span> = 16,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">bold</span>: <span class="t">Bool</span> = false,
) -&gt; ()</code></pre>

Asks the page how wide a text is, written in a given font, so that
something can be drawn to fit it. The page answers once it has
measured: `answer` is called with the width, after the code calling
`measure_text` has finished, as an event's function is.

<p class="pyk-api-label">Parameters</p>

- `words`: the text to measure.
- `answer`: the function to call; it is given the width in pixels.
- `size`: the height of the letters in pixels; 16 by default.
- `font`: a font, such as `"serif"`; the page's own by default.
- `bold`: `true` for bold letters.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(240, 60)
tw.text(c, 10, 20, "Hello, canvas!", size = 20)
def measured(width: Float):
    tw.line(c, 10, 46, 10 + int(width), 46, "teal", 2)
tw.measure_text("Hello, canvas!", measured, size = 20)
```

</div>

<div class="pyk-api">

## mouse_down

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">mouse_down</span>(<span class="p">c</span>: <span class="t">String</span>) -&gt; <span class="t">Bool</span></code></pre>

Whether the pointer's button is held down, having gone down on the
canvas `c`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.

<p class="pyk-api-label">Returns</p>

`true` while it is held.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.on_press(c, tw.ignore2)
print(tw.mouse_down(c))
```

```stdout visible = true
false
```

</div>

<div class="pyk-api">

## mouse_x

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">mouse_x</span>(<span class="p">c</span>: <span class="t">String</span>) -&gt; <span class="t">Int</span></code></pre>

Where the pointer was last seen on the canvas `c`, left to right. The
canvas reports the pointer once something has asked for it with
`on_press`, `on_release`, `on_move` or `on_drag`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.

<p class="pyk-api-label">Returns</p>

`x` in pixels from the canvas's left edge; 0 until the pointer has
been seen.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.on_move(c, tw.ignore2)
def draw(t: Float):
    tw.clear(c)
    tw.circle(c, tw.mouse_x(c), tw.mouse_y(c), 8, "teal")
tw.on_frame(draw)
```

</div>

<div class="pyk-api">

## mouse_y

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">mouse_y</span>(<span class="p">c</span>: <span class="t">String</span>) -&gt; <span class="t">Int</span></code></pre>

Where the pointer was last seen on the canvas `c`, top to bottom, as
`mouse_x` says.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.

<p class="pyk-api-label">Returns</p>

`y` in pixels from the canvas's top edge; 0 until the pointer has
been seen.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.on_move(c, tw.ignore2)
print(tw.mouse_y(c))
```

```stdout visible = true
0
```

</div>

<div class="pyk-api">

## number_input

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">number_input</span>(
    <span class="p">low</span>: <span class="t">Int</span>,
    <span class="p">high</span>: <span class="t">Int</span>,
    <span class="p">value</span>: <span class="t">Int</span>,
    <span class="p">on_change</span>: (<span class="t">Int</span>) -&gt; () = ignore,
) -&gt; <span class="t">String</span></code></pre>

Adds a field to type a whole number into, with arrows to step it,
below everything already on the page.

<p class="pyk-api-label">Parameters</p>

- `low`, `high`: the smallest and largest numbers it takes.
- `value`: the number it starts at.
- `on_change`: the function to call with each new number; by default nothing happens.

<p class="pyk-api-label">Returns</p>

The field's identifier: `"number"`, with a number added where
something on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
shown = tw.label("3 balls")
def changed(n: Int):
    tw.set_label(shown, string(n) ++ " balls")
tw.number_input(1, 20, 3, on_change = changed)
```

</div>

<div class="pyk-api">

## on_drag

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_drag</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">f</span>: (<span class="t">Int</span>, <span class="t">Int</span>) -&gt; ()) -&gt; ()</code></pre>

Calls `f` when the pointer moves with its button held, having gone
down on the canvas `c`: for painting, and for dragging things around.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `f`: the function to call; it is given `x` and `y` in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
def dragged(x: Int, y: Int):
    tw.circle(c, x, y, 3, "black")
tw.on_drag(c, dragged)
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

## on_key_up

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_key_up</span>(<span class="p">released</span>: (<span class="t">String</span>) -&gt; ()) -&gt; ()</code></pre>

Calls `released` each time a key is let go while the page has the
focus. Leaving the page lets go of every key held.

<p class="pyk-api-label">Parameters</p>

- `released`: the function to call; it is given the key, named as `on_key` names it.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
shown = tw.label("hold a key")
def released(key: String):
    tw.set_label(shown, "you let go of " ++ key)
tw.on_key_up(released)
```

</div>

<div class="pyk-api">

## on_mouse

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_mouse</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">click</span>: (<span class="t">Int</span>, <span class="t">Int</span>) -&gt; ()) -&gt; ()</code></pre>

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

## on_move

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_move</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">f</span>: (<span class="t">Int</span>, <span class="t">Int</span>) -&gt; ()) -&gt; ()</code></pre>

Calls `f` when the pointer moves over the canvas `c`, at most once a
frame, with where it is now: a drawing that follows the mouse.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `f`: the function to call; it is given `x` and `y` in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
def moved(x: Int, y: Int):
    tw.clear(c)
    tw.circle(c, x, y, 10, "orange")
tw.on_move(c, moved)
```

</div>

<div class="pyk-api">

## on_press

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_press</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">f</span>: (<span class="t">Int</span>, <span class="t">Int</span>) -&gt; ()) -&gt; ()</code></pre>

Calls `f` each time the pointer -- a mouse button, a pen or a finger --
goes down on the canvas `c`, with where it went down.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `f`: the function to call; it is given `x` and `y` in pixels from the canvas's top left corner.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
def pressed(x: Int, y: Int):
    tw.circle(c, x, y, 6, "crimson")
tw.on_press(c, pressed)
```

</div>

<div class="pyk-api">

## on_release

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_release</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">f</span>: (<span class="t">Int</span>, <span class="t">Int</span>) -&gt; ()) -&gt; ()</code></pre>

Calls `f` each time the pointer comes up after going down on the
canvas `c`, with where it came up -- even outside the canvas.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `f`: the function to call; it is given `x` and `y` in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
def released(x: Int, y: Int):
    tw.rect(c, x - 5, y - 5, 10, 10, "navy")
tw.on_release(c, released)
```

</div>

<div class="pyk-api">

## outside

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">outside</span>() -&gt; ()</code></pre>

Makes every element added after it go on the page again, below
everything there, rather than into a row.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
top = tw.row()
tw.inside(top)
tw.button("one")
tw.button("two")
tw.outside()
c = tw.canvas(200, 60)
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
    <span class="p">align</span>: <span class="t">String</span> = &quot;&quot;,
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
- `align`: where each element stands across the page: `"left"`, as a theme has it, `"center"` or `"right"`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.page_style(background = "#fdf6e3", color = "#586e75", font = "serif", size = 18, gap = 16, align = "center")
tw.label("Solarized, with room to breathe")
tw.button("OK")
```

</div>

<div class="pyk-api">

## path

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">path</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">points</span>: [(<span class="t">Int</span>, <span class="t">Int</span>)],
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws an open line through the points, in order: a zigzag, a graph,
a trail.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `points`: the points, each `(x, y)` in pixels.
- `color`: a CSS color; black by default.
- `width`: how thick it is, in pixels; 1 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.path(c, [(10, 90), (60, 20), (110, 70), (190, 10)], "teal", 3)
```

</div>

<div class="pyk-api">

## pixel_color

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">pixel_color</span>(<span class="p">r</span>: <span class="t">Int</span>, <span class="p">g</span>: <span class="t">Int</span>, <span class="p">b</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

A pixel's color from how much red, green and blue it has.

<p class="pyk-api-label">Parameters</p>

- `r`, `g`, `b`: each from 0 to 255; a number outside is taken as the nearest end.

<p class="pyk-api-label">Returns</p>

The color as one number, which `set_pixel` and `fill_bitmap` take:
`r * 65536 + g * 256 + b`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
print(tw.pixel_color(255, 136, 0))
```

```stdout visible = true
16746496
```

</div>

<div class="pyk-api">

## play

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">play</span>(
    <span class="p">sample</span>: <span class="t">String</span>,
    <span class="p">at</span>: <span class="t">Float</span> = 0.0,
    <span class="p">volume</span>: <span class="t">Float</span> = 1.0,
    <span class="p">rate</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Plays a sample that `load_sample` loaded.

<p class="pyk-api-label">Parameters</p>

- `sample`: the sample's identifier, as `load_sample` answered.
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

## polygon

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">polygon</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">points</span>: [(<span class="t">Int</span>, <span class="t">Int</span>)],
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">outline</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">outline_width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a closed shape through the points, in order, back to the first:
a triangle, a star, any outline.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `points`: the corners, each `(x, y)` in pixels.
- `color`: a CSS color to fill it with; black by default, and `""` for none.
- `outline`: a CSS color to outline it with; `""`, none, by default.
- `outline_width`: how thick the outline is, in pixels; 1 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.polygon(c, [(100, 10), (160, 90), (40, 90)], "orange", outline = "black")
```

</div>

<div class="pyk-api">

## pop

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">pop</span>(<span class="p">c</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Goes back to how the canvas `c` drew at the last `push`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.push(c)
tw.rotate(c, 10.0)
tw.rect(c, 60, 20, 80, 40, "gold")
tw.pop(c)
tw.rect(c, 60, 20, 80, 40, "", outline = "black")
```

</div>

<div class="pyk-api">

## push

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">push</span>(<span class="p">c</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Remembers how the canvas `c` draws now -- its transformation, shadow and
blending -- so that `pop` can go back to it. Pairs may nest.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.push(c)
tw.translate(c, 50.0, 50.0)
tw.circle(c, 0, 0, 20, "red")
tw.pop(c)
tw.circle(c, 20, 20, 10, "blue")
```

</div>

<div class="pyk-api">

## radio

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">radio</span>(
    <span class="p">group</span>: <span class="t">String</span>,
    <span class="p">title</span>: <span class="t">String</span>,
    <span class="p">chosen</span>: <span class="t">Bool</span> = false,
    <span class="p">on_pick</span>: (<span class="t">String</span>) -&gt; () = ignore_text,
) -&gt; <span class="t">String</span></code></pre>

Adds a radio button, with its title beside it, below everything already
on the page. Radio buttons sharing a `group` go together: choosing one
clears the others. The first of a group starts chosen, unless another
says `chosen = true`.

<p class="pyk-api-label">Parameters</p>

- `group`: the name of the buttons it goes with.
- `title`: the text beside the button.
- `chosen`: whether it starts chosen; `false` by default.
- `on_pick`: the function to call when the reader chooses it, with its title; by default nothing happens.

<p class="pyk-api-label">Returns</p>

The radio button's identifier: its title, with a number added where
something on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
shown = tw.label("time-based")
def picked(title: String):
    tw.set_label(shown, title)
tw.radio("mode", "time-based", on_pick = picked)
tw.radio("mode", "frame-based", on_pick = picked)
```

</div>

<div class="pyk-api">

## rect

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">rect</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">width</span>: <span class="t">Int</span>,
    <span class="p">height</span>: <span class="t">Int</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">outline</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">outline_width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">radius</span>: <span class="t">Int</span> = 0,
) -&gt; ()</code></pre>

Draws a rectangle on the canvas `c`, with square or rounded corners.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the top left corner, in pixels from the canvas's top left corner.
- `width`, `height`: the size in pixels.
- `color`: a CSS color to fill it with; black by default, and `""` for none.
- `outline`: a CSS color to outline it with; `""`, none, by default.
- `outline_width`: how thick the outline is, in pixels; 1 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.
- `radius`: how round its corners are, in pixels; 0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.rect(c, 20, 20, 160, 60, "#4caf50")
tw.rect(c, 40, 30, 120, 40, "white", outline = "black", outline_width = 2, radius = 10)
```

</div>

<div class="pyk-api">

## red

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">red</span>(<span class="p">color</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

How much red a pixel's color has.

<p class="pyk-api-label">Parameters</p>

- `color`: a color as `pixel_color` makes them.

<p class="pyk-api-label">Returns</p>

The red part, from 0 to 255.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
print(tw.red(tw.pixel_color(255, 136, 0)))
```

```stdout visible = true
255
```

</div>

<div class="pyk-api">

## reset

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">reset</span>(<span class="p">c</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Takes every transformation off the canvas `c`: (0, 0) is its top left
corner again, nothing is turned and nothing is stretched.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.translate(c, 100.0, 50.0)
tw.circle(c, 0, 0, 10)
tw.reset(c)
tw.circle(c, 10, 10, 10, "red")
```

</div>

<div class="pyk-api">

## rotate

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">rotate</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">degrees</span>: <span class="t">Float</span>) -&gt; ()</code></pre>

Turns everything drawn on the canvas `c` after it, around (0, 0):
`translate` first to turn around another point.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `degrees`: how far to turn, clockwise.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.translate(c, 100.0, 50.0)
tw.rotate(c, 45.0)
tw.rect(c, -20, -20, 40, 40, "crimson")
```

</div>

<div class="pyk-api">

## row

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">row</span>() -&gt; <span class="t">String</span></code></pre>

Adds a row below everything already on the page: a box whose elements
go side by side, wrapping onto a new line where the page is too
narrow. Put elements into it with `inside`.

<p class="pyk-api-label">Returns</p>

The row's identifier, which `inside` takes: `"row"`, with a number
added where something on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
buttons = tw.row()
tw.inside(buttons)
tw.button("Start")
tw.button("Stop")
tw.outside()
tw.label("below the row")
```

</div>

<div class="pyk-api">

## scale

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">scale</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">sx</span>: <span class="t">Float</span>, <span class="p">sy</span>: <span class="t">Float</span>) -&gt; ()</code></pre>

Stretches everything drawn on the canvas `c` after it: 2.0 doubles,
0.5 halves, and a negative factor mirrors.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `sx`: the factor across.
- `sy`: the factor up and down.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.scale(c, 2.0, 1.0)
tw.circle(c, 50, 50, 20, "orange")
```

</div>

<div class="pyk-api">

## set_checked

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">set_checked</span>(<span class="p">id</span>: <span class="t">String</span>, <span class="p">checked</span>: <span class="t">Bool</span>) -&gt; ()</code></pre>

Ticks or clears a checkbox, or chooses a radio button. Nothing the
program handed over is called: only the reader changes call it.

<p class="pyk-api-label">Parameters</p>

- `id`: the checkbox or radio button, as `checkbox` or `radio` answered.
- `checked`: `true` to tick it (or choose it), `false` to clear it.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
trails = tw.checkbox("Trails")
tw.set_checked(trails, true)
```

</div>

<div class="pyk-api">

## set_colors

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">set_colors</span>(
    <span class="p">id</span>: <span class="t">String</span>,
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

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">set_label</span>(<span class="p">id</span>: <span class="t">String</span>, <span class="p">text</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Replaces the text of a label, or the title of a button.

<p class="pyk-api-label">Parameters</p>

- `id`: the label's identifier, as `label` answered, or the button's, as `button` answered; a button keeps its identifier.
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

## set_pixel

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">set_pixel</span>(<span class="p">b</span>: <span class="t">String</span>, <span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>, <span class="p">color</span>: <span class="t">Int</span>) -&gt; ()</code></pre>

Sets one pixel of a bitmap. Nothing is sent to the page until the
bitmap is shown. A pixel outside the bitmap is left alone.

<p class="pyk-api-label">Parameters</p>

- `b`: the bitmap, as `bitmap` answered.
- `x`, `y`: the pixel, from the bitmap's top left corner.
- `color`: its color as one number, `pixel_color(r, g, b)`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
b = tw.bitmap(10, 10)
tw.set_pixel(b, 5, 5, tw.pixel_color(255, 0, 0))
print(tw.red(tw.get_pixel(b, 5, 5)))
```

```stdout visible = true
255
```

</div>

<div class="pyk-api">

## set_splash

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">set_splash</span>(<span class="p">message</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Sets the message the splash screen shows, `Click to Start` until it is
set. An empty message turns the splash screen off, and sound then
starts at the reader's first click on the page.

<p class="pyk-api-label">Parameters</p>

- `message`: what the splash screen says, or `""` for none.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.set_splash("Click to hear the drums")
kick = tw.load_sample("kick1.wav")
tw.play(kick)
```

</div>

<div class="pyk-api">

## set_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">set_style</span>(
    <span class="p">id</span>: <span class="t">String</span>,
    <span class="p">background</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">color</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">border</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">radius</span>: <span class="t">Int</span> = -1,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">size</span>: <span class="t">Int</span> = -1,
    <span class="p">padding</span>: <span class="t">Int</span> = -1,
    <span class="p">accent</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">width</span>: <span class="t">Int</span> = -1,
    <span class="p">weight</span>: <span class="t">Int</span> = -1,
    <span class="p">height</span>: <span class="t">Int</span> = -1,
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
- `weight`: how heavy its letters are, from 100 (thin) to 900; 400 is normal and 700 bold.
- `height`: its height, in pixels. A canvas given another size than its own is stretched to it.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.button("Normal")
big = tw.button("Important")
tw.set_style(big, border = "2px dashed orange", radius = 0, size = 22, padding = 12)
title = tw.label("A title")
tw.set_style(title, font = "serif", size = 28, weight = 700)
```

</div>

<div class="pyk-api">

## set_value

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">set_value</span>(<span class="p">id</span>: <span class="t">String</span>, <span class="p">value</span>: <span class="t">Int</span>) -&gt; ()</code></pre>

Moves a slider or a number field to a value, or picks the dropdown
choice at that position (0 is the first). Nothing the program handed
over is called.

<p class="pyk-api-label">Parameters</p>

- `id`: the slider, number field or dropdown.
- `value`: the new value, or the choice's position.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
speed = tw.slider(0, 10, 5)
tw.set_value(speed, 8)
```

</div>

<div class="pyk-api">

## shadow

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">shadow</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">color</span>: <span class="t">String</span>,
    <span class="p">blur</span>: <span class="t">Int</span> = 10,
    <span class="p">dx</span>: <span class="t">Int</span> = 0,
    <span class="p">dy</span>: <span class="t">Int</span> = 0,
) -&gt; ()</code></pre>

Gives what is drawn on the canvas `c` after it a shadow, until it is
turned off with a `color` of `""`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `color`: a CSS color for the shadow, or `""` for none.
- `blur`: how soft its edge is, in pixels; 10 by default.
- `dx`, `dy`: how far it falls from the shape, in pixels; 0 by default, which makes a glow.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.shadow(c, "rgba(0, 0, 0, 0.5)", 8, 4, 4)
tw.rect(c, 50, 25, 100, 50, "gold")
tw.shadow(c, "")
```

</div>

<div class="pyk-api">

## show_bitmap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">show_bitmap</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">b</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span> = 0,
    <span class="p">y</span>: <span class="t">Int</span> = 0,
    <span class="p">scale</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a bitmap on the canvas `c`: what changed since it was last shown
is sent to the page, in one go.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `b`: the bitmap, as `bitmap` answered.
- `x`, `y`: where its top left corner goes, in pixels; (0, 0) by default.
- `scale`: how many canvas pixels each of its pixels covers across; 1.0 by default. Above 1.0 each pixel is a sharp square, for pixel art; at 0.5 a bitmap twice the canvas's size fills it, as sharp as the screen can show.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(160, 160)
b = tw.bitmap(16, 16)
for y in range(16):
    for x in range(16):
        tw.set_pixel(b, x, y, tw.pixel_color(x * 16, 0, y * 16))
tw.show_bitmap(c, b, scale = 10.0)
```

</div>

<div class="pyk-api">

## slider

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">slider</span>(
    <span class="p">low</span>: <span class="t">Int</span>,
    <span class="p">high</span>: <span class="t">Int</span>,
    <span class="p">value</span>: <span class="t">Int</span>,
    <span class="p">on_change</span>: (<span class="t">Int</span>) -&gt; () = ignore,
) -&gt; <span class="t">String</span></code></pre>

Adds a slider below everything already on the page.

<p class="pyk-api-label">Parameters</p>

- `low`, `high`: the smallest and largest values it can be set to.
- `value`: where it starts.
- `on_change`: the function to call with each new value it is moved to; by default nothing happens.

<p class="pyk-api-label">Returns</p>

The slider's identifier: `"slider"`, with a number added where
something on the page has that name already.

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

## splash

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">splash</span>() -&gt; ()</code></pre>

Shows the splash screen: the page is dimmed and a message asks the
reader to click, since a browser plays no sound before the reader has
clicked or pressed a key. The page waits there -- what the program
draws next, its frames and its clock -- until the reader does. It is
shown at most once, and not at all where the reader has already
clicked, as in the playground and a notebook. A program that plays a
sound calls it at the end of its top level without writing it, and
the first `play` before a click shows it too.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.circle(c, 100, 50, 40, "orange")
tw.splash()
```

</div>

<div class="pyk-api">

## text

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">text</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">words</span>: <span class="t">String</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">size</span>: <span class="t">Int</span> = 16,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">align</span>: <span class="t">String</span> = &quot;left&quot;,
    <span class="p">bold</span>: <span class="t">Bool</span> = false,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">baseline</span>: <span class="t">String</span> = &quot;top&quot;,
    <span class="p">outline</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">outline_width</span>: <span class="t">Int</span> = 1,
) -&gt; ()</code></pre>

Writes text on the canvas `c`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: where the text goes, in pixels: its top left corner, or with `align` its top centre or top right corner.
- `words`: the text to write.
- `color`: a CSS color; black by default.
- `size`: the height of the letters in pixels; 16 by default.
- `font`: a font, such as `"serif"` or `"monospace"`; the page's own by default.
- `align`: `"left"`, the default, `"center"` or `"right"`.
- `bold`: `true` for bold letters.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.
- `baseline`: what `y` is: the letters' `"top"`, the default, their `"middle"`, the `"alphabetic"` line they sit on, or their `"bottom"`.
- `outline`: a CSS color to outline the letters with, drawn under their color; `""`, none, by default. With `color` set to `""` the letters are outlined only.
- `outline_width`: how thick the outline is, in pixels; 1 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 90)
tw.text(c, 10, 10, "Score: 42", "purple", 24)
tw.text(c, 100, 36, "centred", size = 14, align = "center", bold = true)
tw.text(c, 10, 80, "outlined", "white", 20, baseline = "bottom", outline = "black", outline_width = 3)
```

</div>

<div class="pyk-api">

## text_input

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">text_input</span>(
    <span class="p">placeholder</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">on_enter</span>: (<span class="t">String</span>) -&gt; () = ignore_text,
) -&gt; <span class="t">String</span></code></pre>

Adds a line to type text into, below everything already on the page.

<p class="pyk-api-label">Parameters</p>

- `placeholder`: the grey text it shows while it is empty; none by default.
- `on_enter`: the function to call when the reader presses Enter in it, with what is typed there; by default nothing happens.

<p class="pyk-api-label">Returns</p>

The field's identifier: its placeholder, or `"text"` where it has
none, with a number added where something on the page has that name
already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
shown = tw.label("Hello!")
def entered(name: String):
    tw.set_label(shown, "Hello, " ++ name ++ "!")
tw.text_input("your name", on_enter = entered)
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

## translate

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">translate</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">x</span>: <span class="t">Float</span>, <span class="p">y</span>: <span class="t">Float</span>) -&gt; ()</code></pre>

Moves where (0, 0) is for everything drawn on the canvas `c` after it,
until `reset` or the next `clear`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: how far to move it, in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.translate(c, 100.0, 50.0)
tw.circle(c, 0, 0, 30, "teal")
```

</div>

<div class="pyk-api">

## web_init

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">web_init</span>(<span class="p">port</span>: <span class="t">Int</span> = 0) -&gt; ()</code></pre>

Starts the program's page. Run as `pyk program.pyk` or compiled, it
serves the page on `port` and prints the address to open; in a browser,
the notebook or the playground the page is already there and it does
nothing. Call it before any other tinyweb function.

<p class="pyk-api-label">Parameters</p>

- `port`: the port to serve on; 0, the default, picks any free one.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init()
tw.label("The page is ready.")
```

</div>

## The submodule tinyweb.colors

These are written `colors.name` inside the library, and reached as `colors.name` through:

```pyking norun
import tinyweb.colors as colors
```

<div class="pyk-api">

## colors.conic_gradient

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">colors.conic_gradient</span>(
    <span class="p">x</span>: <span class="t">Float</span>,
    <span class="p">y</span>: <span class="t">Float</span>,
    <span class="p">angle</span>: <span class="t">Float</span>,
    <span class="p">start</span>: <span class="t">String</span>,
    <span class="p">end</span>: <span class="t">String</span>,
) -&gt; <span class="t">String</span></code></pre>

A color that changes around a point, like the hand of a clock sweeping
round from `start` to `end`: a color wheel, a pie, a radar.

<p class="pyk-api-label">Parameters</p>

- `x`, `y`: the point it turns around, in pixels.
- `angle`: where it starts, in degrees clockwise from the right.
- `start`: the CSS color where it starts.
- `end`: the CSS color it has come to all the way round.

<p class="pyk-api-label">Returns</p>

A color, which any function taking one takes.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.colors as colors
tw.web_init(0)
c = tw.canvas(200, 100)
wheel = colors.conic_gradient(100.0, 50.0, 0.0, "red", "red")
wheel2 = colors.stop(colors.stop(wheel, 0.33, "lime"), 0.67, "blue")
tw.circle(c, 100, 50, 45, wheel2)
```

</div>

<div class="pyk-api">

## colors.hsl

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">colors.hsl</span>(<span class="p">h</span>: <span class="t">Int</span>, <span class="p">s</span>: <span class="t">Int</span>, <span class="p">l</span>: <span class="t">Int</span>) -&gt; <span class="t">String</span></code></pre>

A CSS color from its hue, saturation and lightness: the easy way to
walk round the rainbow.

<p class="pyk-api-label">Parameters</p>

- `h`: the hue, in degrees round the color wheel: 0 is red, 120 green and 240 blue.
- `s`: the saturation, from 0 (grey) to 100 (full color).
- `l`: the lightness, from 0 (black) through 50 to 100 (white).

<p class="pyk-api-label">Returns</p>

The color, such as `"hsl(120, 100%, 50%)"`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.colors as colors
print(colors.hsl(120, 100, 50))
```

```stdout visible = true
hsl(120, 100%, 50%)
```

</div>

<div class="pyk-api">

## colors.linear_gradient

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">colors.linear_gradient</span>(
    <span class="p">x1</span>: <span class="t">Float</span>,
    <span class="p">y1</span>: <span class="t">Float</span>,
    <span class="p">x2</span>: <span class="t">Float</span>,
    <span class="p">y2</span>: <span class="t">Float</span>,
    <span class="p">start</span>: <span class="t">String</span>,
    <span class="p">end</span>: <span class="t">String</span>,
) -&gt; <span class="t">String</span></code></pre>

A color that changes along a line, for filling or outlining anything:
`start` where the line starts and `end` where it ends, blending
between them; `colors.stop` adds colors in between. Where it is drawn
the coordinates mean what the shape's own do, moved, turned and
scaled alike.

<p class="pyk-api-label">Parameters</p>

- `x1`, `y1`: where the gradient starts, in pixels.
- `x2`, `y2`: where it ends.
- `start`: the CSS color at the start.
- `end`: the CSS color at the end.

<p class="pyk-api-label">Returns</p>

A color, which any function taking one takes.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.colors as colors
tw.web_init(0)
c = tw.canvas(200, 100)
sky = colors.linear_gradient(0.0, 0.0, 0.0, 100.0, "navy", "skyblue")
tw.rect(c, 0, 0, 200, 100, sky)
```

</div>

<div class="pyk-api">

## colors.palette

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">colors.palette</span>(<span class="p">name</span>: <span class="t">String</span>) -&gt; [<span class="t">String</span>]</code></pre>

A few colors that go together, for generative art: `"ocean"`,
`"candy"`, `"forest"`, `"sunset"` and `"neon"`. A name that is none of
these answers no colors, and says so with `debug`.

<p class="pyk-api-label">Parameters</p>

- `name`: the palette.

<p class="pyk-api-label">Returns</p>

Its colors, as CSS colors.

<p class="pyk-api-label">Example</p>

```pyking
from tinyweb.colors import palette
print(palette("ocean"))
```

```stdout visible = true
['#03045e', '#0077b6', '#00b4d8', '#90e0ef', '#caf0f8']
```

</div>

<div class="pyk-api">

## colors.radial_gradient

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">colors.radial_gradient</span>(
    <span class="p">x1</span>: <span class="t">Float</span>,
    <span class="p">y1</span>: <span class="t">Float</span>,
    <span class="p">r1</span>: <span class="t">Float</span>,
    <span class="p">x2</span>: <span class="t">Float</span>,
    <span class="p">y2</span>: <span class="t">Float</span>,
    <span class="p">r2</span>: <span class="t">Float</span>,
    <span class="p">start</span>: <span class="t">String</span>,
    <span class="p">end</span>: <span class="t">String</span>,
) -&gt; <span class="t">String</span></code></pre>

A color that changes outwards from one circle to another: `start` at
the inner circle and `end` at the outer, for a ball lit from one side,
a glow or a sun.

<p class="pyk-api-label">Parameters</p>

- `x1`, `y1`, `r1`: the inner circle's centre and radius, in pixels.
- `x2`, `y2`, `r2`: the outer circle's.
- `start`: the CSS color at the inner circle.
- `end`: the CSS color at the outer circle.

<p class="pyk-api-label">Returns</p>

A color, which any function taking one takes.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.colors as colors
tw.web_init(0)
c = tw.canvas(200, 100)
ball = colors.radial_gradient(85.0, 35.0, 4.0, 100.0, 50.0, 40.0, "white", "crimson")
tw.circle(c, 100, 50, 40, ball)
```

</div>

<div class="pyk-api">

## colors.rgb

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">colors.rgb</span>(<span class="p">r</span>: <span class="t">Int</span>, <span class="p">g</span>: <span class="t">Int</span>, <span class="p">b</span>: <span class="t">Int</span>) -&gt; <span class="t">String</span></code></pre>

A CSS color from its red, green and blue parts.

<p class="pyk-api-label">Parameters</p>

- `r`, `g`, `b`: red, green and blue, each from 0 to 255; a number outside that range is taken as the nearest end of it.

<p class="pyk-api-label">Returns</p>

The color, such as `"#ff8800"`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.colors as colors
print(colors.rgb(255, 136, 0))
```

```stdout visible = true
#ff8800
```

</div>

<div class="pyk-api">

## colors.rgba

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">colors.rgba</span>(<span class="p">r</span>: <span class="t">Int</span>, <span class="p">g</span>: <span class="t">Int</span>, <span class="p">b</span>: <span class="t">Int</span>, <span class="p">a</span>: <span class="t">Float</span>) -&gt; <span class="t">String</span></code></pre>

A CSS color from its red, green and blue parts and how opaque it is.

<p class="pyk-api-label">Parameters</p>

- `r`, `g`, `b`: red, green and blue, each from 0 to 255.
- `a`: how opaque it is, from 0.0 (not at all) to 1.0.

<p class="pyk-api-label">Returns</p>

The color, such as `"rgba(255, 0, 0, 0.5)"`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.colors as colors
print(colors.rgba(255, 0, 0, 0.5))
```

```stdout visible = true
rgba(255, 0, 0, 0.5)
```

</div>

<div class="pyk-api">

## colors.stop

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">colors.stop</span>(<span class="p">gradient</span>: <span class="t">String</span>, <span class="p">at</span>: <span class="t">Float</span>, <span class="p">color</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

A gradient with one more color in it: `color` at `at` of the way from
its start to its end. Stops can be added in any order.

<p class="pyk-api-label">Parameters</p>

- `gradient`: a gradient, as `linear_gradient`, `radial_gradient` or `conic_gradient` made it.
- `at`: where the color goes, from 0.0 at the start to 1.0 at the end.
- `color`: the CSS color there.

<p class="pyk-api-label">Returns</p>

The gradient with the stop added.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.colors as colors
tw.web_init(0)
c = tw.canvas(200, 100)
sunset = colors.stop(colors.linear_gradient(0.0, 0.0, 0.0, 100.0, "#1a237e", "#ffb74d"), 0.6, "#e91e63")
tw.rect(c, 0, 0, 200, 100, sunset)
```

</div>

## The submodule tinyweb.smooth

These are written `smooth.name` inside the library, and reached as `smooth.name` through:

```pyking norun
import tinyweb.smooth as smooth
```

<div class="pyk-api">

## smooth.arc

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.arc</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Float</span>,
    <span class="p">y</span>: <span class="t">Float</span>,
    <span class="p">radius</span>: <span class="t">Float</span>,
    <span class="p">start</span>: <span class="t">Float</span>,
    <span class="p">end</span>: <span class="t">Float</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">outline</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">outline_width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws part of a circle, as `arc` does, at a position that need not be a
whole pixel.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the centre, in pixels.
- `radius`: the radius in pixels.
- `start`, `end`: where it starts and ends, in degrees clockwise from the right.
- `color`: a CSS color to fill the slice with; black by default, `""` for none.
- `outline`: a CSS color for the curved edge; none by default.
- `outline_width`: how thick the outline is; 1.0 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.arc(c, 100.0, 50.0, 40.0, 0.0, 270.0, "", outline = "teal", outline_width = 6.5)
```

</div>

<div class="pyk-api">

## smooth.bezier

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.bezier</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x1</span>: <span class="t">Float</span>,
    <span class="p">y1</span>: <span class="t">Float</span>,
    <span class="p">ax</span>: <span class="t">Float</span>,
    <span class="p">ay</span>: <span class="t">Float</span>,
    <span class="p">bx</span>: <span class="t">Float</span>,
    <span class="p">by</span>: <span class="t">Float</span>,
    <span class="p">x2</span>: <span class="t">Float</span>,
    <span class="p">y2</span>: <span class="t">Float</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a cubic Bézier curve, as `bezier` does, through points that need
not be whole pixels.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x1`, `y1`: where the curve starts, in pixels.
- `ax`, `ay`: the control point near the start.
- `bx`, `by`: the control point near the end.
- `x2`, `y2`: where it ends.
- `color`: a CSS color; black by default.
- `width`: how thick it is; 1.0 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.bezier(c, 10.0, 50.0, 60.0, -20.0, 140.0, 120.0, 190.0, 50.0, "crimson", 2.5)
```

</div>

<div class="pyk-api">

## smooth.circle

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.circle</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Float</span>,
    <span class="p">y</span>: <span class="t">Float</span>,
    <span class="p">radius</span>: <span class="t">Float</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">outline</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">outline_width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a circle, as `circle` does, at a position that need not be a
whole pixel.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the centre, in pixels.
- `radius`: the radius in pixels.
- `color`: a CSS color to fill it with; black by default, `""` for none.
- `outline`: a CSS color to outline it with; none by default.
- `outline_width`: how thick the outline is; 1.0 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.circle(c, 100.5, 50.25, 30.5, "gold", outline = "black", outline_width = 0.5)
```

</div>

<div class="pyk-api">

## smooth.circles

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.circles</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">circles</span>: [(<span class="t">Float</span>, <span class="t">Float</span>, <span class="t">Float</span>)],
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">outline</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">outline_width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws many circles of one color in one go, each filled and outlined
on its own as `smooth.circle` draws it: far quicker than one call each,
for blossoms, stars or snow.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `circles`: the circles, each `(x, y, radius)` in pixels.
- `color`: a CSS color to fill them with; black by default, `""` for none.
- `outline`: a CSS color to outline them with; none by default.
- `outline_width`: how thick the outline is; 1.0 by default.
- `alpha`: how opaque each is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
snow = [(float(i * 37 - i * 37 / 200 * 200), float(i * 53 - i * 53 / 100 * 100), 2.5) for i in range(40)]
smooth.circles(c, snow, "white", outline = "skyblue", alpha = 0.8)
```

</div>

<div class="pyk-api">

## smooth.clip_circle

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.clip_circle</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Float</span>,
    <span class="p">y</span>: <span class="t">Float</span>,
    <span class="p">radius</span>: <span class="t">Float</span>,
) -&gt; ()</code></pre>

Keeps everything drawn on the canvas `c` after it inside a circle, as
`clip_circle` does, at a position that need not be a whole pixel.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the centre, in pixels.
- `radius`: the radius in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
tw.push(c)
smooth.clip_circle(c, 100.5, 50.5, 40.0)
tw.rect(c, 0, 0, 100, 100, "teal")
tw.pop(c)
```

</div>

<div class="pyk-api">

## smooth.clip_polygon

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.clip_polygon</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">points</span>: [(<span class="t">Float</span>, <span class="t">Float</span>)]) -&gt; ()</code></pre>

Keeps everything drawn on the canvas `c` after it inside a polygon, as
`clip_polygon` does, with corners that need not be whole pixels.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `points`: the corners, each `(x, y)` in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
tw.push(c)
smooth.clip_polygon(c, [(100.0, 5.5), (190.5, 95.0), (9.5, 95.0)])
tw.rect(c, 0, 0, 200, 100, "gold")
tw.pop(c)
```

</div>

<div class="pyk-api">

## smooth.curve

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.curve</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x1</span>: <span class="t">Float</span>,
    <span class="p">y1</span>: <span class="t">Float</span>,
    <span class="p">cx</span>: <span class="t">Float</span>,
    <span class="p">cy</span>: <span class="t">Float</span>,
    <span class="p">x2</span>: <span class="t">Float</span>,
    <span class="p">y2</span>: <span class="t">Float</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a quadratic Bézier curve, as `curve` does, through points that
need not be whole pixels.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x1`, `y1`: where the curve starts, in pixels.
- `cx`, `cy`: the point it bends towards.
- `x2`, `y2`: where it ends.
- `color`: a CSS color; black by default.
- `width`: how thick it is; 1.0 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.curve(c, 10.0, 90.0, 100.0, -40.0, 190.0, 90.0, "purple", 2.5)
```

</div>

<div class="pyk-api">

## smooth.ellipse

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.ellipse</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Float</span>,
    <span class="p">y</span>: <span class="t">Float</span>,
    <span class="p">rx</span>: <span class="t">Float</span>,
    <span class="p">ry</span>: <span class="t">Float</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">outline</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">outline_width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws an ellipse, as `ellipse` does, at a position that need not be a
whole pixel.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the centre, in pixels.
- `rx`, `ry`: the radius across and the radius up and down.
- `color`: a CSS color to fill it with; black by default, `""` for none.
- `outline`: a CSS color to outline it with; none by default.
- `outline_width`: how thick the outline is; 1.0 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.ellipse(c, 100.0, 50.0, 80.5, 30.25, "plum")
```

</div>

<div class="pyk-api">

## smooth.line

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.line</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x1</span>: <span class="t">Float</span>,
    <span class="p">y1</span>: <span class="t">Float</span>,
    <span class="p">x2</span>: <span class="t">Float</span>,
    <span class="p">y2</span>: <span class="t">Float</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a straight line, as `line` does, between points that need not be
whole pixels, as thick as any number of pixels.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x1`, `y1`: where the line starts, in pixels.
- `x2`, `y2`: where it ends.
- `color`: a CSS color; black by default.
- `width`: how thick it is; 1.0 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.line(c, 10.0, 90.0, 190.0, 12.5, "black", 0.8)
```

</div>

<div class="pyk-api">

## smooth.lines

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.lines</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">segments</span>: [(<span class="t">Float</span>, <span class="t">Float</span>, <span class="t">Float</span>, <span class="t">Float</span>)],
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws many separate straight lines in one go, as `lines` does, between
points that need not be whole pixels.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `segments`: the lines, each `(x1, y1, x2, y2)` in pixels.
- `color`: a CSS color; black by default.
- `width`: how thick they are; 1.0 by default.
- `alpha`: how opaque they are, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
rays = [(100.0, 50.0, 100.0 + 45.0 * float(i - i / 3 * 3), 5.0 * float(i)) for i in range(20)]
smooth.lines(c, rays, "orange", 0.8, alpha = 0.5)
```

</div>

<div class="pyk-api">

## smooth.path

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.path</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">points</span>: [(<span class="t">Float</span>, <span class="t">Float</span>)],
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws an open line through the points, as `path` does, at positions
that need not be whole pixels.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `points`: the points, each `(x, y)` in pixels.
- `color`: a CSS color; black by default.
- `width`: how thick it is; 1.0 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.path(c, [(10.0, 90.0), (60.5, 20.5), (110.0, 70.0), (190.0, 10.0)], "teal", 2.5)
```

</div>

<div class="pyk-api">

## smooth.polygon

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.polygon</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">points</span>: [(<span class="t">Float</span>, <span class="t">Float</span>)],
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">outline</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">outline_width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a closed shape through the points, as `polygon` does, at
positions that need not be whole pixels.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `points`: the corners, each `(x, y)` in pixels.
- `color`: a CSS color to fill it with; black by default, `""` for none.
- `outline`: a CSS color to outline it with; none by default.
- `outline_width`: how thick the outline is; 1.0 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.polygon(c, [(100.0, 10.0), (180.5, 90.5), (19.5, 90.5)], "orange")
```

</div>

<div class="pyk-api">

## smooth.rect

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.rect</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Float</span>,
    <span class="p">y</span>: <span class="t">Float</span>,
    <span class="p">width</span>: <span class="t">Float</span>,
    <span class="p">height</span>: <span class="t">Float</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">outline</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">outline_width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">radius</span>: <span class="t">Float</span> = 0.0,
) -&gt; ()</code></pre>

Draws a rectangle, as `rect` does, at a position that need not be a
whole pixel.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: the top left corner, in pixels.
- `width`, `height`: the size in pixels.
- `color`: a CSS color to fill it with; black by default, `""` for none.
- `outline`: a CSS color to outline it with; none by default.
- `outline_width`: how thick the outline is; 1.0 by default.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.
- `radius`: how round its corners are; 0.0, square, by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.rect(c, 20.5, 20.5, 159.0, 59.0, "", outline = "navy", radius = 8.0)
```

</div>

<div class="pyk-api">

## smooth.text

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.text</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Float</span>,
    <span class="p">y</span>: <span class="t">Float</span>,
    <span class="p">words</span>: <span class="t">String</span>,
    <span class="p">color</span>: <span class="t">String</span> = &quot;#000000&quot;,
    <span class="p">size</span>: <span class="t">Int</span> = 16,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">align</span>: <span class="t">String</span> = &quot;left&quot;,
    <span class="p">bold</span>: <span class="t">Bool</span> = false,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">baseline</span>: <span class="t">String</span> = &quot;top&quot;,
    <span class="p">outline</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">outline_width</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Writes text, as `text` does, at a position that need not be a whole
pixel.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `x`, `y`: where the text goes, in pixels, as `align` and `baseline` say.
- `words`: the text to write.
- `color`: a CSS color; black by default, `""` for none.
- `size`: the height of the letters in pixels; 16 by default.
- `font`: a font, such as `"serif"`; the page's own by default.
- `align`: `"left"`, the default, `"center"` or `"right"`.
- `bold`: `true` for bold letters.
- `alpha`: how opaque it is, from 0.0 to 1.0; 1.0 by default.
- `baseline`: `"top"`, the default, `"middle"`, `"alphabetic"` or `"bottom"`.
- `outline`: a CSS color to outline the letters with; none by default.
- `outline_width`: how thick the outline is; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 60)
smooth.text(c, 100.5, 30.0, "smooth", "navy", 24, align = "center", baseline = "middle")
```

</div>
