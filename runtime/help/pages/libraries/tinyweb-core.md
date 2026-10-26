---
title: tinyweb
description: "What `import tinyweb` reaches: the names written `tw.name` after `import tinyweb as tw`."
sidebar:
  label: page, canvas, widgets
  parent: tinyweb
  position: 1
---

What `import tinyweb` reaches: the names written `tw.name` after `import tinyweb as tw`.

```pyking norun
import tinyweb as tw
```

| Topic | |
|---|---|
| [Page](#page) | [`web_init`](#web_init) |
| [Points and styles](#points-and-styles) | [`Point`](#point), [`Style`](#style), [`Pointer`](#pointer) |
| [Canvas](#canvas) | [`canvas`](#canvas), [`clear`](#clear) |
| [Shapes](#shapes) | [`circle`](#circle), [`rect`](#rect), [`ellipse`](#ellipse), [`arc`](#arc), [`polygon`](#polygon), [`line`](#line), [`path`](#path), [`curve`](#curve), [`lines`](#lines), [`bezier`](#bezier), [`erase`](#erase) |
| [Lines and clipping](#lines-and-clipping) | [`line_style`](#line_style), [`clip_rect`](#clip_rect), [`clip_circle`](#clip_circle), [`clip_polygon`](#clip_polygon) |
| [Text](#text) | [`text`](#text), [`measure_text`](#measure_text) |
| [Transformations](#transformations) | [`translate`](#translate), [`rotate`](#rotate), [`scale`](#scale), [`push`](#push), [`pop`](#pop), [`reset`](#reset), [`shadow`](#shadow), [`blend`](#blend) |
| [Images](#images) | [`load_image`](#load_image), [`image`](#image) |
| [Widgets](#widgets) | [`label`](#label), [`set_checked`](#set_checked), [`set_value`](#set_value), [`button`](#button), [`slider`](#slider), [`checkbox`](#checkbox), [`radio`](#radio), [`choice`](#choice), [`text_input`](#text_input), [`number_input`](#number_input) |
| [Changing the page](#changing-the-page) | [`set_text`](#set_text), [`show`](#show), [`hide`](#hide), [`enable`](#enable), [`disable`](#disable), [`remove`](#remove), [`value_of`](#value_of) |
| [Styles](#styles) | [`theme`](#theme), [`page_style`](#page_style), [`button_style`](#button_style), [`label_style`](#label_style), [`slider_style`](#slider_style), [`canvas_style`](#canvas_style), [`set_style`](#set_style) |
| [Mouse and keyboard](#mouse-and-keyboard) | [`on_key`](#on_key), [`on_key_up`](#on_key_up), [`key_down`](#key_down), [`on_click`](#on_click), [`on_press`](#on_press), [`on_release`](#on_release), [`on_move`](#on_move), [`on_drag`](#on_drag), [`track_mouse`](#track_mouse), [`mouse`](#mouse) |
| [Time](#time) | [`time`](#time), [`sdelay`](#sdelay), [`on_frame`](#on_frame), [`after`](#after), [`every`](#every), [`cancel`](#cancel) |
| [Sound](#sound) | [`load_sample`](#load_sample), [`play`](#play), [`play_file`](#play_file) |
| [Splash screen](#splash-screen) | [`splash`](#splash), [`set_splash`](#set_splash) |

## Page

<div class="pyk-api">

### web_init

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">web_init</span>(<span class="p">port</span>: <span class="t">Int</span> = 0) -&gt; ()</code></pre>

Starts the program's page. Run as `pyk program.pyk` or compiled, it
serves the page on `port` and prints its address; in a browser it does
nothing, since the page is there already.

<p class="pyk-api-label">Parameters</p>

- `port`: the port to serve the page on; 0, the default, takes any free one.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.label("Hello")
```

</div>

## Points and styles

<div class="pyk-api">

### Point

<pre class="pyk-sig"><code><span class="k">struct</span> <span class="n">Point</span>(x: <span class="t">Int</span>, y: <span class="t">Int</span>)</code></pre>

A point on a canvas, in whole pixels from its top left corner: what
`polygon` and `path` take a list of.

<p class="pyk-api-label">Parameters</p>

- `x`: how far right.
- `y`: how far down.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
p = tw.Point(10, 20)
print(p.x, p.y, tw.Point(x = 5, ..p).x)
```

```stdout visible = true
10 20 5
```

</div>

<div class="pyk-api">

### Style

<pre class="pyk-sig"><code><span class="k">struct</span> <span class="n">Style</span>(fill: color.Color = color.black, stroke: color.Color = color.none, width = 1, alpha = 1.0, paint: color.Paint = color.Plain(color.none))</code></pre>

How a shape is drawn, defined once and given to as many shapes as
look alike with `style = ...`. A shape's own argument left at its
default takes the style's value, and one written wins.

<p class="pyk-api-label">Parameters</p>

- `fill`: the colour inside; black by default.
- `stroke`: the colour of the outline, or of a line; `color.none` (no outline) by default.
- `width`: how thick the outline or line is, in pixels; 1 by default.
- `alpha`: how opaque, from 0.0 to 1.0; 1.0 by default.
- `paint`: a gradient to fill with instead of `fill`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 80)
glow = tw.Style(fill = color.yellow, stroke = color.orange, width = 3)
tw.circle(c, 40, 40, 30, style = glow)
tw.circle(c, 120, 40, 30, color.red, style = glow)
tw.circle(c, 170, 40, 20, style = tw.Style(alpha = 0.5, ..glow))
```

</div>

<div class="pyk-api">

### Pointer

<pre class="pyk-sig"><code><span class="k">struct</span> <span class="n">Pointer</span>(x: <span class="t">Int</span>, y: <span class="t">Int</span>, down: <span class="t">Bool</span>)</code></pre>

Where the pointer is on a canvas, and whether its button is held: what
`mouse` answers.

<p class="pyk-api-label">Parameters</p>

- `x`: how far right, in the canvas's pixels.
- `y`: how far down.
- `down`: whether the button is held.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
p = tw.Pointer(3, 4, true)
print(p.x, p.y, p.down)
```

```stdout visible = true
3 4 true
```

</div>

## Canvas

<div class="pyk-api">

### canvas

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
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 60)
tw.rect(c, 10, 10, 180, 40, color.teal)
```

</div>

<div class="pyk-api">

### clear

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">clear</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">fill</span>: color.Color = color.white) -&gt; ()</code></pre>

Fills the whole canvas `c` with one colour, wiping out what was drawn,
and starts it afresh: no transformation, shadow or blending is kept.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, as `canvas` answered.
- `fill`: the colour; white by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 60)
tw.clear(c, color.navy)
```

</div>

## Shapes

<div class="pyk-api">

### circle

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">circle</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">radius</span>: <span class="t">Int</span>,
    <span class="p">fill</span>: color.Color = color.black,
    <span class="p">stroke</span>: color.Color = color.none,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">paint</span>: color.Paint = color.Plain(color.none),
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

Draws a circle on the canvas `c`: filled, outlined, or both.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: its centre.
- `radius`: its radius.
- `fill`: the colour inside; black by default, `color.none` for none.
- `stroke`: the outline's colour; none by default.
- `width`: the outline's width; 1 by default.
- `alpha`: how opaque, from 0.0 to 1.0.
- `paint`: a gradient to fill with instead of `fill`.
- `style`: a `Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 100)
tw.circle(c, 50, 50, 40, color.orange)
tw.circle(c, 150, 50, 40, color.none, stroke = color.blue, width = 4)
```

</div>

<div class="pyk-api">

### rect

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">rect</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">w</span>: <span class="t">Int</span>,
    <span class="p">h</span>: <span class="t">Int</span>,
    <span class="p">fill</span>: color.Color = color.black,
    <span class="p">stroke</span>: color.Color = color.none,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">paint</span>: color.Paint = color.Plain(color.none),
    <span class="p">style</span>: Style = Style(),
    <span class="p">radius</span>: <span class="t">Int</span> = 0,
) -&gt; ()</code></pre>

Draws a rectangle on the canvas `c`, with square or rounded corners.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: its top left corner.
- `w`, `h`: its width and height.
- `fill`: the colour inside; black by default.
- `stroke`: the outline's colour; none by default.
- `width`: the outline's width; 1 by default.
- `alpha`: how opaque, from 0.0 to 1.0.
- `paint`: a gradient to fill with instead of `fill`.
- `style`: a `Style` for what is not given here.
- `radius`: how round its corners are; 0, square, by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 100)
tw.rect(c, 10, 10, 80, 60, color.teal)
tw.rect(c, 110, 10, 80, 60, color.pink, radius = 12)
```

</div>

<div class="pyk-api">

### ellipse

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">ellipse</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">rx</span>: <span class="t">Int</span>,
    <span class="p">ry</span>: <span class="t">Int</span>,
    <span class="p">fill</span>: color.Color = color.black,
    <span class="p">stroke</span>: color.Color = color.none,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">paint</span>: color.Paint = color.Plain(color.none),
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

Draws an ellipse on the canvas `c`: a circle stretched to `rx` across
and `ry` up and down.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: its centre.
- `rx`, `ry`: its radius across and up and down.
- `fill`: the colour inside; black by default.
- `stroke`: the outline's colour; none by default.
- `width`: the outline's width; 1 by default.
- `alpha`: how opaque, from 0.0 to 1.0.
- `paint`: a gradient to fill with instead of `fill`.
- `style`: a `Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 100)
tw.ellipse(c, 100, 50, 80, 30, color.purple)
```

</div>

<div class="pyk-api">

### arc

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">arc</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">radius</span>: <span class="t">Int</span>,
    <span class="p">start</span>: <span class="t">Float</span>,
    <span class="p">end</span>: <span class="t">Float</span>,
    <span class="p">fill</span>: color.Color = color.black,
    <span class="p">stroke</span>: color.Color = color.none,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">paint</span>: color.Paint = color.Plain(color.none),
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

Draws a slice of a circle on the canvas `c`, from the angle `start` to
the angle `end`, both in radians, clockwise from the right: a pie
slice when filled, a bow when only stroked.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: the circle's centre.
- `radius`: its radius.
- `start`, `end`: where the slice starts and ends, in radians.
- `fill`: the colour inside; black by default.
- `stroke`: the outline's colour; none by default.
- `width`: the outline's width; 1 by default.
- `alpha`: how opaque, from 0.0 to 1.0.
- `paint`: a gradient to fill with instead of `fill`.
- `style`: a `Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
import math
tw.web_init(0)
c = tw.canvas(200, 100)
tw.arc(c, 100, 50, 40, 0.0, math.pi * 1.5, color.yellow)
```

</div>

<div class="pyk-api">

### polygon

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">polygon</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">points</span>: [Point],
    <span class="p">fill</span>: color.Color = color.black,
    <span class="p">stroke</span>: color.Color = color.none,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">paint</span>: color.Paint = color.Plain(color.none),
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

Draws a closed shape through the points, in order, back to the first:
a triangle, a star, any outline.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `points`: the corners.
- `fill`: the colour inside; black by default.
- `stroke`: the outline's colour; none by default.
- `width`: the outline's width; 1 by default.
- `alpha`: how opaque, from 0.0 to 1.0.
- `paint`: a gradient to fill with instead of `fill`.
- `style`: a `Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 100)
tw.polygon(c, [tw.Point(100, 10), tw.Point(160, 90), tw.Point(40, 90)], color.green)
```

</div>

<div class="pyk-api">

### line

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">line</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x1</span>: <span class="t">Int</span>,
    <span class="p">y1</span>: <span class="t">Int</span>,
    <span class="p">x2</span>: <span class="t">Int</span>,
    <span class="p">y2</span>: <span class="t">Int</span>,
    <span class="p">stroke</span>: color.Color = color.black,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

Draws a straight line on the canvas `c`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x1`, `y1`: where it starts.
- `x2`, `y2`: where it ends.
- `stroke`: its colour; black by default.
- `width`: how thick it is; 1 by default.
- `alpha`: how opaque, from 0.0 to 1.0.
- `style`: a `Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 100)
tw.line(c, 10, 90, 190, 10, color.red, width = 3)
```

</div>

<div class="pyk-api">

### path

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">path</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">points</span>: [Point],
    <span class="p">stroke</span>: color.Color = color.black,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

Draws an open line through the points, in order: a zigzag, a graph,
a path walked.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `points`: the points it goes through.
- `stroke`: its colour; black by default.
- `width`: how thick it is; 1 by default.
- `alpha`: how opaque, from 0.0 to 1.0.
- `style`: a `Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.path(c, [tw.Point(10, 90), tw.Point(60, 20), tw.Point(110, 70), tw.Point(190, 10)], width = 2)
```

</div>

<div class="pyk-api">

### curve

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">curve</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x1</span>: <span class="t">Int</span>,
    <span class="p">y1</span>: <span class="t">Int</span>,
    <span class="p">cx</span>: <span class="t">Int</span>,
    <span class="p">cy</span>: <span class="t">Int</span>,
    <span class="p">x2</span>: <span class="t">Int</span>,
    <span class="p">y2</span>: <span class="t">Int</span>,
    <span class="p">stroke</span>: color.Color = color.black,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

Draws a curve from (`x1`, `y1`) to (`x2`, `y2`), pulled towards the
point (`cx`, `cy`) on the way.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x1`, `y1`: where it starts.
- `cx`, `cy`: the point it is pulled towards.
- `x2`, `y2`: where it ends.
- `stroke`: its colour; black by default.
- `width`: how thick it is; 1 by default.
- `alpha`: how opaque, from 0.0 to 1.0.
- `style`: a `Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.curve(c, 10, 90, 100, 0, 190, 90, width = 2)
```

</div>

<div class="pyk-api">

### lines

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">lines</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">segments</span>: [(Point, Point)],
    <span class="p">stroke</span>: color.Color = color.black,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

Draws many separate straight lines in one go, all of one colour and
width: quicker than calling `line` for each.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `segments`: each line, from its first point to its second.
- `stroke`: their colour; black by default.
- `width`: how thick they are; 1 by default.
- `alpha`: how opaque, from 0.0 to 1.0.
- `style`: a `Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.lines(c, [(tw.Point(x, 10), tw.Point(x, 90)) for x in range(10, 200, 20)])
```

</div>

<div class="pyk-api">

### bezier

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
    <span class="p">stroke</span>: color.Color = color.black,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

Draws a curve from (`x1`, `y1`) to (`x2`, `y2`) pulled towards two
points on the way, (`ax`, `ay`) first and then (`bx`, `by`): an S, a
wave.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x1`, `y1`: where it starts.
- `ax`, `ay`: the first point it is pulled towards.
- `bx`, `by`: the second.
- `x2`, `y2`: where it ends.
- `stroke`: its colour; black by default.
- `width`: how thick it is; 1 by default.
- `alpha`: how opaque, from 0.0 to 1.0.
- `style`: a `Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.bezier(c, 10, 50, 60, 0, 140, 100, 190, 50, width = 3)
```

</div>

<div class="pyk-api">

### erase

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">erase</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>, <span class="p">w</span>: <span class="t">Int</span>, <span class="p">h</span>: <span class="t">Int</span>) -&gt; ()</code></pre>

Erases a rectangle of the canvas `c`: what was drawn there goes, and
what is behind the canvas shows through.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: the rectangle's top left corner.
- `w`, `h`: its width and height.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.rect(c, 0, 0, 200, 100)
tw.erase(c, 50, 25, 100, 50)
```

</div>

## Lines and clipping

<div class="pyk-api">

### line_style

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
corners, and whether they are dashed.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `cap`: how a line ends: `"round"` (the default), `"butt"` or `"square"`.
- `join`: how a corner turns: `"round"` (the default), `"miter"` or `"bevel"`.
- `dash`: how long a dash is; 0.0, a solid line, by default.
- `gap`: how long the gap after it is; the dash's length unless given.
- `offset`: how far into the pattern the line starts.
- `dash2`, `gap2`: a second dash and gap, for a dash-dot pattern.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 60)
tw.line_style(c, cap = "butt", dash = 10.0, gap = 5.0)
tw.line(c, 10, 30, 190, 30, width = 4)
```

</div>

<div class="pyk-api">

### clip_rect

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">clip_rect</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>, <span class="p">w</span>: <span class="t">Int</span>, <span class="p">h</span>: <span class="t">Int</span>) -&gt; ()</code></pre>

Keeps everything drawn on the canvas `c` after it inside a rectangle:
what falls outside is not drawn, until `pop` or `reset`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: the rectangle's top left corner.
- `w`, `h`: its width and height.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.push(c)
tw.clip_rect(c, 50, 25, 100, 50)
tw.circle(c, 100, 50, 60)
tw.pop(c)
```

</div>

<div class="pyk-api">

### clip_circle

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">clip_circle</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>, <span class="p">radius</span>: <span class="t">Int</span>) -&gt; ()</code></pre>

Keeps everything drawn on the canvas `c` after it inside a circle,
until `pop` or `reset`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: the circle's centre.
- `radius`: its radius.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.clip_circle(c, 100, 50, 40)
tw.rect(c, 0, 0, 200, 100)
```

</div>

<div class="pyk-api">

### clip_polygon

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">clip_polygon</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">points</span>: [Point]) -&gt; ()</code></pre>

Keeps everything drawn on the canvas `c` after it inside a polygon,
until `pop` or `reset`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `points`: the polygon's corners.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.clip_polygon(c, [tw.Point(100, 0), tw.Point(200, 100), tw.Point(0, 100)])
tw.rect(c, 0, 0, 200, 100)
```

</div>

## Text

<div class="pyk-api">

### text

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">text</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">words</span>: <span class="t">String</span>,
    <span class="p">fill</span>: color.Color = color.black,
    <span class="p">size</span>: <span class="t">Int</span> = 16,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">align</span>: <span class="t">String</span> = &quot;left&quot;,
    <span class="p">bold</span>: <span class="t">Bool</span> = false,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">baseline</span>: <span class="t">String</span> = &quot;top&quot;,
    <span class="p">stroke</span>: color.Color = color.none,
    <span class="p">width</span>: <span class="t">Int</span> = 1,
    <span class="p">paint</span>: color.Paint = color.Plain(color.none),
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

Writes text on the canvas `c`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: where the text goes: its top left corner, unless `align` and `baseline` say otherwise.
- `words`: what is written.
- `fill`: its colour; black by default.
- `size`: its size in pixels; 16 by default.
- `font`: the font's name, such as `"serif"`; the page's own by default.
- `align`: which part of the text is at `x`: `"left"`, `"center"` or `"right"`.
- `bold`: whether it is bold.
- `alpha`: how opaque, from 0.0 to 1.0.
- `baseline`: which part is at `y`: `"top"`, `"middle"`, `"alphabetic"` or `"bottom"`.
- `stroke`: the colour of an outline round each letter; none by default.
- `width`: the outline's width.
- `paint`: a gradient to fill the letters with instead of `fill`.
- `style`: a `Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 60)
tw.text(c, 100, 30, "Hello!", color.navy, size = 24, align = "center", baseline = "middle")
```

</div>

<div class="pyk-api">

### measure_text

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">measure_text</span>(
    <span class="p">words</span>: <span class="t">String</span>,
    <span class="p">answer</span>: (<span class="t">Float</span>) -&gt; (),
    <span class="p">size</span>: <span class="t">Int</span> = 16,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">bold</span>: <span class="t">Bool</span> = false,
) -&gt; ()</code></pre>

Asks the page how wide a text is, written in a given font, so that
something can be placed beside it. The page answers by calling
`answer` with the width in pixels, a moment later.

<p class="pyk-api-label">Parameters</p>

- `words`: the text.
- `answer`: what is called with its width.
- `size`: its size in pixels; 16 by default.
- `font`: the font's name; the page's own by default.
- `bold`: whether it is bold.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(300, 60)
def underline(w: Float):
    tw.line(c, 10, 40, 10 + int(w), 40)
tw.text(c, 10, 10, "Underlined", size = 20)
tw.measure_text("Underlined", underline, size = 20)
```

</div>

## Transformations

<div class="pyk-api">

### translate

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">translate</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">x</span>: <span class="t">Float</span>, <span class="p">y</span>: <span class="t">Float</span>) -&gt; ()</code></pre>

Moves where (0, 0) is for everything drawn on the canvas `c` after it,
until `pop` or `reset`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: how far right and down (0, 0) moves.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.translate(c, 100.0, 50.0)
tw.circle(c, 0, 0, 20)
```

</div>

<div class="pyk-api">

### rotate

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">rotate</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">angle</span>: <span class="t">Float</span>) -&gt; ()</code></pre>

Turns everything drawn on the canvas `c` after it, around (0, 0), by
an angle in radians, clockwise: `translate` first to turn round
another point.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `angle`: how far to turn, in radians: `math.pi / 2.0` is a quarter turn.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import math
tw.web_init(0)
c = tw.canvas(200, 100)
tw.translate(c, 100.0, 50.0)
tw.rotate(c, math.pi / 4.0)
tw.rect(c, -20, -20, 40, 40)
```

</div>

<div class="pyk-api">

### scale

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">scale</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">sx</span>: <span class="t">Float</span>, <span class="p">sy</span>: <span class="t">Float</span>) -&gt; ()</code></pre>

Stretches everything drawn on the canvas `c` after it: 2.0 doubles,
0.5 halves, and -1.0 mirrors.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `sx`: across.
- `sy`: up and down.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.scale(c, 2.0, 1.0)
tw.circle(c, 50, 50, 20)
```

</div>

<div class="pyk-api">

### push

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">push</span>(<span class="p">c</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Remembers how the canvas `c` draws now -- its transformation, shadow,
blending, line style and clipping -- so that `pop` can go back to it.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.push(c)
tw.translate(c, 100.0, 50.0)
tw.circle(c, 0, 0, 10)
tw.pop(c)
tw.circle(c, 10, 10, 10)
```

</div>

<div class="pyk-api">

### pop

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">pop</span>(<span class="p">c</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Goes back to how the canvas `c` drew at the last `push`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.push(c)
tw.scale(c, 3.0, 3.0)
tw.pop(c)
tw.circle(c, 50, 50, 10)
```

</div>

<div class="pyk-api">

### reset

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">reset</span>(<span class="p">c</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Takes every transformation off the canvas `c`: (0, 0) is its top left
corner again, nothing is turned or stretched, and nothing is clipped.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.translate(c, 50.0, 50.0)
tw.reset(c)
tw.circle(c, 10, 10, 10)
```

</div>

<div class="pyk-api">

### shadow

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">shadow</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">shade</span>: color.Color,
    <span class="p">blur</span>: <span class="t">Int</span> = 10,
    <span class="p">dx</span>: <span class="t">Int</span> = 0,
    <span class="p">dy</span>: <span class="t">Int</span> = 0,
) -&gt; ()</code></pre>

Gives what is drawn on the canvas `c` after it a shadow, until it is
given `color.none` or the canvas is `reset`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `shade`: the shadow's colour; `color.none` turns shadows off.
- `blur`: how blurred it is, in pixels; 10 by default.
- `dx`, `dy`: how far right and down it falls.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 100)
tw.shadow(c, color.gray, blur = 8, dx = 4, dy = 4)
tw.rect(c, 50, 25, 100, 50, color.orange)
```

</div>

<div class="pyk-api">

### blend

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">blend</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">mode</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Says how what is drawn on the canvas `c` after it mixes with what is
there: `"normal"` covers it, `"add"` adds the colours, so overlapping
light glows.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `mode`: `"normal"` or `"add"`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 100)
tw.clear(c, color.black)
tw.blend(c, "add")
tw.circle(c, 80, 50, 40, color.red)
tw.circle(c, 120, 50, 40, color.blue)
```

</div>

## Images

<div class="pyk-api">

### load_image

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">load_image</span>(<span class="p">name</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

Starts loading a picture, so that `image` can draw it. The file is
looked for beside the page first, then among the pictures tinyweb
ships: `ball.png`, `star.png` and `tile.png`. Drawing a picture
before it has loaded waits for it: the page holds that and everything
after it until the picture has loaded, so what is drawn later still
lands on top of it.

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
tw.image(c, ball, 80, 30, 40, 40)
```

</div>

<div class="pyk-api">

### image

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">image</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">picture</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">w</span>: <span class="t">Int</span>,
    <span class="p">h</span>: <span class="t">Int</span>,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a picture `load_image` loaded on the canvas `c`, stretched to
the rectangle given. A picture not loaded yet is drawn once it has
loaded, and what the program draws after it waits until then.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `picture`: the picture, as `load_image` answered.
- `x`, `y`: where its top left corner goes.
- `w`, `h`: how wide and tall it is drawn.
- `alpha`: how opaque, from 0.0 to 1.0.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
ball = tw.load_image("ball.png")
tw.image(c, ball, 70, 20, 60, 60)
```

</div>

## Widgets

<div class="pyk-api">

### label

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">label</span>(<span class="p">text</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

Adds a line of text below everything already on the page.

<p class="pyk-api-label">Parameters</p>

- `text`: what the label says.

<p class="pyk-api-label">Returns</p>

The label's identifier, which `set_text` takes to change the text:
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

### set_checked

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

### set_value

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

### button

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">button</span>(<span class="p">title</span>: <span class="t">String</span>, <span class="p">on_click</span>: () -&gt; () = nothing) -&gt; <span class="t">String</span></code></pre>

A button showing `title`, below what the page already holds. Pressing
it calls `on_click`.

<p class="pyk-api-label">Parameters</p>

- `title`: what the button says.
- `on_click`: what is called when it is pressed.

<p class="pyk-api-label">Returns</p>

The button's identifier: its title, with a number added where
something on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
def hello():
    print("hello")
print(tw.button("Say hello", on_click = hello))
```

```stdout visible = true
Say hello
```

</div>

<div class="pyk-api">

### slider

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">slider</span>(
    <span class="p">low</span>: <span class="t">Int</span>,
    <span class="p">high</span>: <span class="t">Int</span>,
    <span class="p">value</span>: <span class="t">Int</span>,
    <span class="p">on_change</span>: (<span class="t">Int</span>) -&gt; () = ignore,
) -&gt; <span class="t">String</span></code></pre>

A slider from `low` to `high`, standing at `value`. Moving it calls
`on_change` with where it stands.

<p class="pyk-api-label">Parameters</p>

- `low`, `high`: its two ends.
- `value`: where it starts.
- `on_change`: what is called with each new value.

<p class="pyk-api-label">Returns</p>

The slider's identifier: `"slider"`, with a number added where
something on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
def moved(v: Int):
    print(v)
print(tw.slider(0, 100, 50, on_change = moved))
```

```stdout visible = true
slider
```

</div>

<div class="pyk-api">

### checkbox

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">checkbox</span>(
    <span class="p">title</span>: <span class="t">String</span>,
    <span class="p">checked</span>: <span class="t">Bool</span> = false,
    <span class="p">on_change</span>: (<span class="t">Bool</span>) -&gt; () = ignore_bool,
) -&gt; <span class="t">String</span></code></pre>

A box to tick, with `title` beside it. Ticking or unticking it calls
`on_change` with whether it is ticked.

<p class="pyk-api-label">Parameters</p>

- `title`: what it says.
- `checked`: whether it starts ticked.
- `on_change`: what is called with each change.

<p class="pyk-api-label">Returns</p>

Its identifier: its title, with a number added where something on the
page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
print(tw.checkbox("Sound", checked = true))
```

```stdout visible = true
Sound
```

</div>

<div class="pyk-api">

### radio

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">radio</span>(
    <span class="p">group</span>: <span class="t">String</span>,
    <span class="p">title</span>: <span class="t">String</span>,
    <span class="p">chosen</span>: <span class="t">Bool</span> = false,
    <span class="p">on_pick</span>: (<span class="t">String</span>) -&gt; () = ignore_text,
) -&gt; <span class="t">String</span></code></pre>

A radio button: one of the buttons sharing `group`, of which one is
chosen at a time. Choosing it calls `on_pick` with its title. The
first of a group is chosen unless another says `chosen = true`.

<p class="pyk-api-label">Parameters</p>

- `group`: the buttons it belongs with.
- `title`: what it says.
- `chosen`: whether it starts chosen.
- `on_pick`: what is called with its title when it is chosen.

<p class="pyk-api-label">Returns</p>

Its identifier: its title, with a number added where something on the
page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
def picked(name: String):
    print("picked", name)
tw.radio("size", "Small", on_pick = picked)
tw.radio("size", "Large", chosen = true, on_pick = picked)
```

</div>

<div class="pyk-api">

### choice

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">choice</span>(
    <span class="p">options</span>: [<span class="t">String</span>],
    <span class="p">chosen</span>: <span class="t">Int</span> = 0,
    <span class="p">on_change</span>: (<span class="t">Int</span>) -&gt; () = ignore,
) -&gt; <span class="t">String</span></code></pre>

A dropdown of `options`. Choosing one calls `on_change` with its
position, from 0.

<p class="pyk-api-label">Parameters</p>

- `options`: what can be chosen.
- `chosen`: which one is chosen to start with; 0, the first, by default.
- `on_change`: what is called with the position of each choice.

<p class="pyk-api-label">Returns</p>

Its identifier: `"choice"`, with a number added where something on the
page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
print(tw.choice(["red", "green", "blue"], chosen = 1))
```

```stdout visible = true
choice
```

</div>

<div class="pyk-api">

### text_input

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">text_input</span>(
    <span class="p">placeholder</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">on_enter</span>: (<span class="t">String</span>) -&gt; () = ignore_text,
) -&gt; <span class="t">String</span></code></pre>

A line of text to type into. Pressing Enter in it calls `on_enter`
with what it holds; `value_of` reads it at any time.

<p class="pyk-api-label">Parameters</p>

- `placeholder`: what it shows, greyed out, while it is empty.
- `on_enter`: what is called with the text when Enter is pressed.

<p class="pyk-api-label">Returns</p>

Its identifier: the placeholder, or `"text"` where there is none, with
a number added where something on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
def greet(name: String):
    print("Hello,", name)
print(tw.text_input("Your name", on_enter = greet))
```

```stdout visible = true
Your name
```

</div>

<div class="pyk-api">

### number_input

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">number_input</span>(
    <span class="p">low</span>: <span class="t">Int</span>,
    <span class="p">high</span>: <span class="t">Int</span>,
    <span class="p">value</span>: <span class="t">Int</span>,
    <span class="p">on_change</span>: (<span class="t">Int</span>) -&gt; () = ignore,
) -&gt; <span class="t">String</span></code></pre>

A field holding a whole number from `low` to `high`, with arrows to
step it. A new number calls `on_change`.

<p class="pyk-api-label">Parameters</p>

- `low`, `high`: the smallest and largest number.
- `value`: the number it starts with.
- `on_change`: what is called with each new number.

<p class="pyk-api-label">Returns</p>

Its identifier: `"number"`, with a number added where something on the
page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
print(tw.number_input(1, 12, 3))
```

```stdout visible = true
number
```

</div>

## Changing the page

<div class="pyk-api">

### set_text

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">set_text</span>(<span class="p">id</span>: <span class="t">String</span>, <span class="p">words</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Changes the text of a label or a button, or what a text field or a
text area holds.

<p class="pyk-api-label">Parameters</p>

- `id`: the element, as the function that made it answered.
- `words`: its new text.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
score = tw.label("Score: 0")
tw.set_text(score, "Score: 10")
```

</div>

<div class="pyk-api">

### show

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">show</span>(<span class="p">id</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Shows an element `hide` hid.

<p class="pyk-api-label">Parameters</p>

- `id`: the element.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
secret = tw.label("Surprise!")
tw.hide(secret)
tw.show(secret)
```

</div>

<div class="pyk-api">

### hide

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">hide</span>(<span class="p">id</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Hides an element without removing it: `show` brings it back where it
was.

<p class="pyk-api-label">Parameters</p>

- `id`: the element.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.hide(tw.label("Not yet"))
```

</div>

<div class="pyk-api">

### enable

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">enable</span>(<span class="p">id</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Lets a button, or any widget, be used again after `disable`.

<p class="pyk-api-label">Parameters</p>

- `id`: the widget.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
go = tw.button("Go")
tw.disable(go)
tw.enable(go)
```

</div>

<div class="pyk-api">

### disable

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">disable</span>(<span class="p">id</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Greys a button, or any widget, out, so it cannot be used until
`enable`.

<p class="pyk-api-label">Parameters</p>

- `id`: the widget.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.disable(tw.button("Next level"))
```

</div>

<div class="pyk-api">

### remove

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">remove</span>(<span class="p">id</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Removes an element from the page for good.

<p class="pyk-api-label">Parameters</p>

- `id`: the element.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.remove(tw.label("Loading..."))
```

</div>

<div class="pyk-api">

### value_of

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">value_of</span>(<span class="p">id</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

What a widget holds now, as text, as the page last reported it: a
text field's or text area's text, a slider's or number field's number,
a dropdown's position, a checkbox's `"true"` or `"false"`. Empty until
the reader has changed it.

<p class="pyk-api-label">Parameters</p>

- `id`: the widget.

<p class="pyk-api-label">Returns</p>

Its value, as text.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
name = tw.text_input("Your name")
def check():
    print("typed:", tw.value_of(name))
tw.button("Check", on_click = check)
```

</div>

## Styles

<div class="pyk-api">

### theme

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">theme</span>(<span class="p">name</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Gives the page one of tinyweb's looks, forgetting what was changed
with the `_style` functions.

<p class="pyk-api-label">Parameters</p>

- `name`: `"light"` (the default), `"dark"`, `"plain"`, `"paper"` or `"retro"`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
tw.theme("dark")
tw.label("Dark")
```

</div>

<div class="pyk-api">

### page_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">page_style</span>(
    <span class="p">background</span>: color.Color = color.theme,
    <span class="p">foreground</span>: color.Color = color.theme,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">size</span>: <span class="t">Int</span> = -1,
    <span class="p">padding</span>: <span class="t">Int</span> = -1,
    <span class="p">gap</span>: <span class="t">Int</span> = -1,
    <span class="p">align</span>: <span class="t">String</span> = &quot;&quot;,
) -&gt; ()</code></pre>

Changes the page's look: its colours, its text, and the space round
and between what it holds. What is not given stays as it is.

<p class="pyk-api-label">Parameters</p>

- `background`: the page's colour.
- `foreground`: its text's colour.
- `font`: its font's name.
- `size`: its text's size, in pixels.
- `padding`: the space round the page's edge, in pixels.
- `gap`: the space between one element and the next, in pixels.
- `align`: where elements stand: `"left"`, `"center"` or `"right"`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
tw.page_style(background = color.hex(0x111111), foreground = color.hex(0xeeeeee), align = "center")
```

</div>

<div class="pyk-api">

### button_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">button_style</span>(
    <span class="p">background</span>: color.Color = color.theme,
    <span class="p">foreground</span>: color.Color = color.theme,
    <span class="p">border</span>: color.Color = color.theme,
    <span class="p">border_width</span>: <span class="t">Int</span> = -1,
    <span class="p">radius</span>: <span class="t">Int</span> = -1,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">size</span>: <span class="t">Int</span> = -1,
    <span class="p">padding</span>: <span class="t">Int</span> = -1,
) -&gt; ()</code></pre>

Changes the look of every button. What is not given stays as it is.

<p class="pyk-api-label">Parameters</p>

- `background`: the button's colour.
- `foreground`: its title's colour.
- `border`: its border's colour; `color.none` for no border.
- `border_width`: its border's width, in pixels.
- `radius`: how round its corners are, in pixels.
- `font`: its title's font.
- `size`: its title's size, in pixels.
- `padding`: the space round its title, in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
tw.button_style(background = color.teal, foreground = color.white, radius = 12)
tw.button("Round")
```

</div>

<div class="pyk-api">

### label_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">label_style</span>(
    <span class="p">background</span>: color.Color = color.theme,
    <span class="p">foreground</span>: color.Color = color.theme,
    <span class="p">border</span>: color.Color = color.theme,
    <span class="p">border_width</span>: <span class="t">Int</span> = -1,
    <span class="p">radius</span>: <span class="t">Int</span> = -1,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">size</span>: <span class="t">Int</span> = -1,
    <span class="p">padding</span>: <span class="t">Int</span> = -1,
) -&gt; ()</code></pre>

Changes the look of every label. What is not given stays as it is.

<p class="pyk-api-label">Parameters</p>

- `background`: the label's colour.
- `foreground`: its text's colour.
- `border`: its border's colour; `color.none` for no border.
- `border_width`: its border's width, in pixels.
- `radius`: how round its corners are, in pixels.
- `font`: its text's font.
- `size`: its text's size, in pixels.
- `padding`: the space round its text, in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
tw.label_style(foreground = color.navy, size = 20)
tw.label("Big and blue")
```

</div>

<div class="pyk-api">

### slider_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">slider_style</span>(
    <span class="p">accent</span>: color.Color = color.theme,
    <span class="p">width</span>: <span class="t">Int</span> = -1,
    <span class="p">foreground</span>: color.Color = color.theme,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">size</span>: <span class="t">Int</span> = -1,
) -&gt; ()</code></pre>

Changes the look of every slider. What is not given stays as it is.

<p class="pyk-api-label">Parameters</p>

- `accent`: the colour of its track and handle.
- `width`: how long it is, in pixels.
- `foreground`: the colour of the number beside it.
- `font`: that number's font.
- `size`: that number's size, in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
tw.slider_style(accent = color.orange, width = 300)
tw.slider(0, 10, 5)
```

</div>

<div class="pyk-api">

### canvas_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">canvas_style</span>(
    <span class="p">border</span>: color.Color = color.theme,
    <span class="p">border_width</span>: <span class="t">Int</span> = -1,
    <span class="p">radius</span>: <span class="t">Int</span> = -1,
) -&gt; ()</code></pre>

Changes the look of every canvas's frame. What is not given stays as
it is.

<p class="pyk-api-label">Parameters</p>

- `border`: the frame's colour.
- `border_width`: its width, in pixels; 0 for no frame.
- `radius`: how round its corners are, in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
tw.canvas_style(border = color.gray, border_width = 2, radius = 6)
tw.canvas(100, 50)
```

</div>

<div class="pyk-api">

### set_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">set_style</span>(
    <span class="p">id</span>: <span class="t">String</span>,
    <span class="p">background</span>: color.Color = color.theme,
    <span class="p">foreground</span>: color.Color = color.theme,
    <span class="p">border</span>: color.Color = color.theme,
    <span class="p">border_width</span>: <span class="t">Int</span> = -1,
    <span class="p">radius</span>: <span class="t">Int</span> = -1,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">size</span>: <span class="t">Int</span> = -1,
    <span class="p">padding</span>: <span class="t">Int</span> = -1,
    <span class="p">accent</span>: color.Color = color.theme,
    <span class="p">width</span>: <span class="t">Int</span> = -1,
    <span class="p">weight</span>: <span class="t">Int</span> = -1,
    <span class="p">height</span>: <span class="t">Int</span> = -1,
) -&gt; ()</code></pre>

Changes the look of one element. What is not given stays as it is.

<p class="pyk-api-label">Parameters</p>

- `id`: the element.
- `background`: its colour.
- `foreground`: its text's colour.
- `border`: its border's colour; `color.none` for no border.
- `border_width`: its border's width, in pixels.
- `radius`: how round its corners are, in pixels.
- `font`: its text's font.
- `size`: its text's size, in pixels.
- `padding`: the space round its text, in pixels.
- `accent`: the colour of a slider's or checkbox's marks.
- `width`: how wide it is, in pixels.
- `weight`: how bold its text is, 100 to 900; 700 is bold.
- `height`: how tall it is, in pixels.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
warning = tw.label("Careful!")
tw.set_style(warning, background = color.yellow, padding = 6, weight = 700)
```

</div>

## Mouse and keyboard

<div class="pyk-api">

### on_key

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
    tw.set_text(shown, "you pressed " + key)
tw.on_key(pressed)
```

</div>

<div class="pyk-api">

### on_key_up

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
    tw.set_text(shown, "you let go of " + key)
tw.on_key_up(released)
```

</div>

<div class="pyk-api">

### key_down

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">key_down</span>(<span class="p">key</span>: <span class="t">String</span>) -&gt; <span class="t">Bool</span></code></pre>

Says whether a key is held down now. A game moves its ship each frame
while an arrow is held, rather than once per press.

<p class="pyk-api-label">Parameters</p>

- `key`: the key, named as `on_key` names it, such as `"ArrowLeft"` or `"a"`.

<p class="pyk-api-label">Returns</p>

`true` while the key is held.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 60)
var x = 100
def draw(t: Float):
    if tw.key_down("ArrowLeft"):
        x := x - 2
    if tw.key_down("ArrowRight"):
        x := x + 2
    tw.clear(c)
    tw.circle(c, x, 30, 10, color.teal)
tw.on_frame(draw)
```

</div>

<div class="pyk-api">

### on_click

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_click</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">f</span>: (<span class="t">Int</span>, <span class="t">Int</span>) -&gt; ()) -&gt; ()</code></pre>

Calls `f` with where the pointer is each time the canvas `c` is
clicked.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `f`: what is called with the pointer's `x` and `y`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
def clicked(x: Int, y: Int):
    tw.circle(c, x, y, 5)
tw.on_click(c, clicked)
```

</div>

<div class="pyk-api">

### on_press

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_press</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">f</span>: (<span class="t">Int</span>, <span class="t">Int</span>) -&gt; ()) -&gt; ()</code></pre>

Calls `f` each time the pointer's button goes down on the canvas `c`:
a mouse button, a pen or a finger.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `f`: what is called with the pointer's `x` and `y`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
def pressed(x: Int, y: Int):
    print("down at", x, y)
tw.on_press(c, pressed)
```

</div>

<div class="pyk-api">

### on_release

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_release</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">f</span>: (<span class="t">Int</span>, <span class="t">Int</span>) -&gt; ()) -&gt; ()</code></pre>

Calls `f` each time the pointer's button comes up over the canvas `c`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `f`: what is called with the pointer's `x` and `y`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
def released(x: Int, y: Int):
    print("up at", x, y)
tw.on_release(c, released)
```

</div>

<div class="pyk-api">

### on_move

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_move</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">f</span>: (<span class="t">Int</span>, <span class="t">Int</span>) -&gt; ()) -&gt; ()</code></pre>

Calls `f` each time the pointer moves over the canvas `c`, at most
once a frame.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `f`: what is called with the pointer's `x` and `y`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
def moved(x: Int, y: Int):
    tw.clear(c)
    tw.circle(c, x, y, 10)
tw.on_move(c, moved)
```

</div>

<div class="pyk-api">

### on_drag

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_drag</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">f</span>: (<span class="t">Int</span>, <span class="t">Int</span>) -&gt; ()) -&gt; ()</code></pre>

Calls `f` each time the pointer moves over the canvas `c` with its
button held: dragging, and drawing with a finger.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `f`: what is called with the pointer's `x` and `y`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
def drawing(x: Int, y: Int):
    tw.circle(c, x, y, 3)
tw.on_drag(c, drawing)
```

</div>

<div class="pyk-api">

### track_mouse

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">track_mouse</span>(<span class="p">c</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Has the canvas `c` report where the pointer is, so `mouse` can say:
what watching it with `on_press`, `on_move` or the others also does.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.track_mouse(c)
```

</div>

<div class="pyk-api">

### mouse

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">mouse</span>(<span class="p">c</span>: <span class="t">String</span>) -&gt; Pointer</code></pre>

Where the pointer was last seen on the canvas `c`, and whether its
button was held, as of the last event. The canvas reports the pointer
once it is watched: by `track_mouse`, or by `on_press` and the others.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.

<p class="pyk-api-label">Returns</p>

The pointer; at (0, 0) and not held until the canvas has reported it.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
c = tw.canvas(200, 100)
tw.track_mouse(c)
p = tw.mouse(c)
print(p.x, p.y, p.down)
```

```stdout visible = true
0 0 false
```

</div>

## Time

<div class="pyk-api">

### time

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

### sdelay

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sdelay</span>(<span class="p">time</span>: <span class="t">Float</span>) -&gt; ()</code></pre>

Waits, keeping in time with the sound: the program goes on `time`
seconds after the last `sdelay` ended, on the page's audio clock. The
first waits `time` seconds from now. Since each counts from where the
last one ended rather than from when it was called, a loop of them
does not drift, however long what runs between them takes. A program
that has fallen behind -- where that end has passed already -- goes on
at once, and the next counts from then.

A sound started after `sdelay`, with no `at` of its own, starts
exactly where it ends, and what is drawn after it is shown then.
While the program waits, the page's events still arrive: a button's
function runs, and so does `on_frame`'s. Since the program really
waits, `print` after it comes out then too.

With no page open yet, the program waits for one. It cannot be used
in a program compiled for the web target, which cannot wait: run it
with the interpreter (`pyk`, `-t iweb`, the playground) or compile it
for another target.

<p class="pyk-api-label">Parameters</p>

- `time`: how long after the last `sdelay` to go on, in seconds; a negative one is 0.

<p class="pyk-api-label">Example</p>

```pyking norun
import tinyweb as tw
tw.web_init(0)
kick = tw.load_sample("kick1.wav")
loop:
    tw.play(kick)
    print("kick")
    tw.sdelay(0.5)
```

```stdout visible = true
kick
kick
kick
```

</div>

<div class="pyk-api">

### on_frame

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">on_frame</span>(<span class="p">draw</span>: (<span class="t">Float</span>) -&gt; ()) -&gt; ()</code></pre>

Calls `draw` before each frame the page shows, about 60 times a second,
with the time the frame is for. This is how a program animates.

<p class="pyk-api-label">Parameters</p>

- `draw`: the function to call; it is given the frame's time in seconds, as `time` reads it.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 60)
def draw(t: Float):
    tw.clear(c)
    x = int(t * 50.0) - int(t * 50.0) / 200 * 200
    tw.circle(c, x, 30, 10, color.orange)
tw.on_frame(draw)
```

</div>

<div class="pyk-api">

### after

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">after</span>(<span class="p">seconds</span>: <span class="t">Float</span>, <span class="p">f</span>: () -&gt; ()) -&gt; <span class="t">String</span></code></pre>

Calls `f` once, `seconds` from now on the page's clock.

<p class="pyk-api-label">Parameters</p>

- `seconds`: how long to wait.
- `f`: what is called.

<p class="pyk-api-label">Returns</p>

The timer's identifier, which `cancel` takes: `"timer"`, with a number
added where something on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
def ring():
    print("ring!")
print(tw.after(3.0, ring))
```

```stdout visible = true
timer
```

</div>

<div class="pyk-api">

### every

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">every</span>(<span class="p">seconds</span>: <span class="t">Float</span>, <span class="p">f</span>: () -&gt; ()) -&gt; <span class="t">String</span></code></pre>

Calls `f` again and again, every `seconds` on the page's clock, until
`cancel` stops it.

<p class="pyk-api-label">Parameters</p>

- `seconds`: how long from one call to the next.
- `f`: what is called.

<p class="pyk-api-label">Returns</p>

The timer's identifier, which `cancel` takes.

<p class="pyk-api-label">Example</p>

```pyking
use mutation
import tinyweb as tw
tw.web_init(0)
clock = tw.label("0")
var seconds = 0
def tick():
    seconds := seconds + 1
    tw.set_text(clock, string(seconds))
tw.every(1.0, tick)
```

</div>

<div class="pyk-api">

### cancel

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">cancel</span>(<span class="p">timer</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Stops a timer `after` or `every` started, or a beat `sound.on_beat`
started.

<p class="pyk-api-label">Parameters</p>

- `timer`: the timer, as `after`, `every` or `sound.on_beat` answered.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
def never():
    print("never")
tw.cancel(tw.after(5.0, never))
```

</div>

## Sound

<div class="pyk-api">

### load_sample

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

### play

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">play</span>(
    <span class="p">sample</span>: <span class="t">String</span>,
    <span class="p">at</span>: <span class="t">Float</span> = 0.0,
    <span class="p">volume</span>: <span class="t">Float</span> = 1.0,
    <span class="p">rate</span>: <span class="t">Float</span> = 1.0,
    <span class="p">pan</span>: <span class="t">Float</span> = 0.0,
    <span class="p">voice</span>: sound.Voice = sound.Voice(),
) -&gt; ()</code></pre>

Plays a sample `load_sample` loaded, once, to its end: a drum hit, a
click, a note. `at` is a time on the page's clock (`time`), so sounds
can be lined up exactly; a time already past plays now.

<p class="pyk-api-label">Parameters</p>

- `sample`: the sample, as `load_sample` answered.
- `at`: when, on the page's clock; now by default.
- `volume`: how loud, as a multiple of the sample's own volume.
- `rate`: how fast: 2.0 plays it twice as fast and an octave higher.
- `pan`: where it is heard, from -1.0 (left) to 1.0 (right).
- `voice`: a `sound.Voice` for what is not given here, and its channel and direction.

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

### play_file

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">play_file</span>(<span class="p">name</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Plays a sound file now, loading it first if nothing has loaded it yet.
For a sound played often, `load_sample` once and then `play` is
quicker.

<p class="pyk-api-label">Parameters</p>

- `name`: the file's name, beside the page or one tinyweb ships.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
tw.web_init(0)
def boom():
    tw.play_file("kick1.wav")
tw.button("Boom", on_click = boom)
```

</div>

## Splash screen

<div class="pyk-api">

### splash

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
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 100)
tw.circle(c, 100, 50, 40, color.orange)
tw.splash()
```

</div>

<div class="pyk-api">

### set_splash

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
