---
title: tinyweb.smooth
description: "The shapes, with positions, sizes and widths that may fall between pixels: something moving slowly, a thin line at an angle or a picture built from thousands of short strokes looks smoother."
sidebar:
  label: smooth
  parent: tinyweb
  position: 8
---

The shapes, with positions, sizes and widths that may fall between
pixels: something moving slowly, a thin line at an angle or a picture
built from thousands of short strokes looks smoother. Each draws
exactly what `tinyweb`'s function of the same name does.

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.circle(c, 100.5, 50.25, 20.75)
```

```pyking norun
import tinyweb.smooth as smooth
```

| Topic | |
|---|---|
| [Shapes](#shapes) | [`Point`](#smoothpoint), [`circle`](#smoothcircle), [`circles`](#smoothcircles), [`rect`](#smoothrect), [`ellipse`](#smoothellipse), [`arc`](#smootharc), [`polygon`](#smoothpolygon), [`line`](#smoothline), [`lines`](#smoothlines), [`path`](#smoothpath), [`curve`](#smoothcurve), [`bezier`](#smoothbezier), [`text`](#smoothtext), [`clip_circle`](#smoothclip_circle), [`clip_polygon`](#smoothclip_polygon) |

## Shapes

<div class="pyk-api">

### smooth.Point

<pre class="pyk-sig"><code><span class="k">struct</span> <span class="n">smooth.Point</span>(x: <span class="t">Float</span>, y: <span class="t">Float</span>)</code></pre>

A point on a canvas whose position may fall between pixels.

<p class="pyk-api-label">Parameters</p>

- `x`: how far right.
- `y`: how far down.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.smooth as smooth
p = smooth.Point(1.5, 2.25)
print(p.x, p.y)
```

```stdout visible = true
1.5 2.25
```

</div>

<div class="pyk-api">

### smooth.circle

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.circle</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Float</span>,
    <span class="p">y</span>: <span class="t">Float</span>,
    <span class="p">radius</span>: <span class="t">Float</span>,
    <span class="p">fill</span>: color.Color = color.black,
    <span class="p">stroke</span>: color.Color = color.none,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">paint</span>: color.Paint = color.Plain(color.none),
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

`tw.circle`, with a position and radius that need not be whole.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: its centre.
- `radius`: its radius.
- `fill`: the colour inside; black by default.
- `stroke`: the outline's colour; none by default.
- `width`: the outline's width.
- `alpha`: how opaque, from 0.0 to 1.0.
- `paint`: a gradient to fill with instead of `fill`.
- `style`: a `tw.Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.circle(c, 100.5, 50.5, 10.25)
```

</div>

<div class="pyk-api">

### smooth.circles

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.circles</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">circles</span>: [(<span class="t">Float</span>, <span class="t">Float</span>, <span class="t">Float</span>)],
    <span class="p">fill</span>: color.Color = color.black,
    <span class="p">stroke</span>: color.Color = color.none,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

Many circles of one look in one go, each `(x, y, radius)`: quicker
than calling `circle` for each.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `circles`: each circle's centre and radius.
- `fill`: the colour inside; black by default.
- `stroke`: the outline's colour; none by default.
- `width`: the outline's width.
- `alpha`: how opaque, from 0.0 to 1.0.
- `style`: a `tw.Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.circles(c, [(float(x), 50.0, 4.5) for x in range(10, 200, 20)])
```

</div>

<div class="pyk-api">

### smooth.rect

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.rect</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Float</span>,
    <span class="p">y</span>: <span class="t">Float</span>,
    <span class="p">w</span>: <span class="t">Float</span>,
    <span class="p">h</span>: <span class="t">Float</span>,
    <span class="p">fill</span>: color.Color = color.black,
    <span class="p">stroke</span>: color.Color = color.none,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">paint</span>: color.Paint = color.Plain(color.none),
    <span class="p">style</span>: Style = Style(),
    <span class="p">radius</span>: <span class="t">Float</span> = 0.0,
) -&gt; ()</code></pre>

`tw.rect`, with a position and size that need not be whole.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: its top left corner.
- `w`, `h`: its width and height.
- `fill`: the colour inside; black by default.
- `stroke`: the outline's colour; none by default.
- `width`: the outline's width.
- `alpha`: how opaque, from 0.0 to 1.0.
- `paint`: a gradient to fill with instead of `fill`.
- `style`: a `tw.Style` for what is not given here.
- `radius`: how round its corners are.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.rect(c, 10.5, 10.5, 50.25, 30.75, radius = 4.5)
```

</div>

<div class="pyk-api">

### smooth.ellipse

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.ellipse</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Float</span>,
    <span class="p">y</span>: <span class="t">Float</span>,
    <span class="p">rx</span>: <span class="t">Float</span>,
    <span class="p">ry</span>: <span class="t">Float</span>,
    <span class="p">fill</span>: color.Color = color.black,
    <span class="p">stroke</span>: color.Color = color.none,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">paint</span>: color.Paint = color.Plain(color.none),
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

`tw.ellipse`, with a position and size that need not be whole.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: its centre.
- `rx`, `ry`: its radius across and up and down.
- `fill`: the colour inside; black by default.
- `stroke`: the outline's colour; none by default.
- `width`: the outline's width.
- `alpha`: how opaque, from 0.0 to 1.0.
- `paint`: a gradient to fill with instead of `fill`.
- `style`: a `tw.Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.ellipse(c, 100.0, 50.0, 60.5, 20.5)
```

</div>

<div class="pyk-api">

### smooth.arc

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.arc</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Float</span>,
    <span class="p">y</span>: <span class="t">Float</span>,
    <span class="p">radius</span>: <span class="t">Float</span>,
    <span class="p">start</span>: <span class="t">Float</span>,
    <span class="p">end</span>: <span class="t">Float</span>,
    <span class="p">fill</span>: color.Color = color.black,
    <span class="p">stroke</span>: color.Color = color.none,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">paint</span>: color.Paint = color.Plain(color.none),
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

`tw.arc`, with a position and radius that need not be whole.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: the circle's centre.
- `radius`: its radius.
- `start`, `end`: where the slice starts and ends, in radians.
- `fill`: the colour inside; black by default.
- `stroke`: the outline's colour; none by default.
- `width`: the outline's width.
- `alpha`: how opaque, from 0.0 to 1.0.
- `paint`: a gradient to fill with instead of `fill`.
- `style`: a `tw.Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.arc(c, 100.0, 50.0, 40.5, 0.0, 3.0, color.none, stroke = color.red, width = 2.5)
```

</div>

<div class="pyk-api">

### smooth.polygon

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.polygon</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">points</span>: [smooth.Point],
    <span class="p">fill</span>: color.Color = color.black,
    <span class="p">stroke</span>: color.Color = color.none,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

`tw.polygon`, through points that need not be whole.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `points`: the corners.
- `fill`: the colour inside; black by default.
- `stroke`: the outline's colour; none by default.
- `width`: the outline's width.
- `alpha`: how opaque, from 0.0 to 1.0.
- `style`: a `tw.Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.polygon(c, [smooth.Point(100.0, 10.5), smooth.Point(160.5, 90.0), smooth.Point(39.5, 90.0)])
```

</div>

<div class="pyk-api">

### smooth.line

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.line</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x1</span>: <span class="t">Float</span>,
    <span class="p">y1</span>: <span class="t">Float</span>,
    <span class="p">x2</span>: <span class="t">Float</span>,
    <span class="p">y2</span>: <span class="t">Float</span>,
    <span class="p">stroke</span>: color.Color = color.black,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

`tw.line`, between points that need not be whole.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x1`, `y1`: where it starts.
- `x2`, `y2`: where it ends.
- `stroke`: its colour; black by default.
- `width`: how thick it is.
- `alpha`: how opaque, from 0.0 to 1.0.
- `style`: a `tw.Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.line(c, 0.5, 0.5, 199.5, 99.5, width = 0.5)
```

</div>

<div class="pyk-api">

### smooth.lines

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.lines</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">segments</span>: [(smooth.Point, smooth.Point)],
    <span class="p">stroke</span>: color.Color = color.black,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

`tw.lines`, between points that need not be whole.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `segments`: each line, from its first point to its second.
- `stroke`: their colour; black by default.
- `width`: how thick they are.
- `alpha`: how opaque, from 0.0 to 1.0.
- `style`: a `tw.Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.lines(c, [(smooth.Point(float(x), 0.0), smooth.Point(float(x) + 5.5, 100.0)) for x in range(0, 200, 20)])
```

</div>

<div class="pyk-api">

### smooth.path

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.path</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">points</span>: [smooth.Point],
    <span class="p">stroke</span>: color.Color = color.black,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

`tw.path`, through points that need not be whole.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `points`: the points it goes through.
- `stroke`: its colour; black by default.
- `width`: how thick it is.
- `alpha`: how opaque, from 0.0 to 1.0.
- `style`: a `tw.Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.path(c, [smooth.Point(float(x), 50.0 + float(x - x / 40 * 40) / 2.0) for x in range(0, 200, 5)])
```

</div>

<div class="pyk-api">

### smooth.curve

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.curve</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x1</span>: <span class="t">Float</span>,
    <span class="p">y1</span>: <span class="t">Float</span>,
    <span class="p">cx</span>: <span class="t">Float</span>,
    <span class="p">cy</span>: <span class="t">Float</span>,
    <span class="p">x2</span>: <span class="t">Float</span>,
    <span class="p">y2</span>: <span class="t">Float</span>,
    <span class="p">stroke</span>: color.Color = color.black,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

`tw.curve`, through points that need not be whole.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x1`, `y1`: where it starts.
- `cx`, `cy`: the point it is pulled towards.
- `x2`, `y2`: where it ends.
- `stroke`: its colour; black by default.
- `width`: how thick it is.
- `alpha`: how opaque, from 0.0 to 1.0.
- `style`: a `tw.Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.curve(c, 10.5, 90.0, 100.0, 0.5, 189.5, 90.0)
```

</div>

<div class="pyk-api">

### smooth.bezier

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
    <span class="p">stroke</span>: color.Color = color.black,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

`tw.bezier`, through points that need not be whole.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x1`, `y1`: where it starts.
- `ax`, `ay`: the first point it is pulled towards.
- `bx`, `by`: the second.
- `x2`, `y2`: where it ends.
- `stroke`: its colour; black by default.
- `width`: how thick it is.
- `alpha`: how opaque, from 0.0 to 1.0.
- `style`: a `tw.Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.bezier(c, 10.0, 50.0, 60.5, 0.0, 140.5, 100.0, 190.0, 50.0, width = 2.5)
```

</div>

<div class="pyk-api">

### smooth.text

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.text</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Float</span>,
    <span class="p">y</span>: <span class="t">Float</span>,
    <span class="p">words</span>: <span class="t">String</span>,
    <span class="p">fill</span>: color.Color = color.black,
    <span class="p">size</span>: <span class="t">Int</span> = 16,
    <span class="p">font</span>: <span class="t">String</span> = &quot;&quot;,
    <span class="p">align</span>: <span class="t">String</span> = &quot;left&quot;,
    <span class="p">bold</span>: <span class="t">Bool</span> = false,
    <span class="p">alpha</span>: <span class="t">Float</span> = 1.0,
    <span class="p">baseline</span>: <span class="t">String</span> = &quot;top&quot;,
    <span class="p">stroke</span>: color.Color = color.none,
    <span class="p">width</span>: <span class="t">Float</span> = 1.0,
    <span class="p">paint</span>: color.Paint = color.Plain(color.none),
    <span class="p">style</span>: Style = Style(),
) -&gt; ()</code></pre>

`tw.text`, at a position that need not be whole.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: where the text goes.
- `words`: what is written.
- `fill`: its colour; black by default.
- `size`: its size in pixels; 16 by default.
- `font`: the font's name; the page's own by default.
- `align`: which part of the text is at `x`: `"left"`, `"center"` or `"right"`.
- `bold`: whether it is bold.
- `alpha`: how opaque, from 0.0 to 1.0.
- `baseline`: which part is at `y`: `"top"`, `"middle"`, `"alphabetic"` or `"bottom"`.
- `stroke`: the colour of an outline round each letter; none by default.
- `width`: the outline's width.
- `paint`: a gradient to fill the letters with instead of `fill`.
- `style`: a `tw.Style` for what is not given here.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 60)
smooth.text(c, 10.5, 20.25, "Smooth")
```

</div>

<div class="pyk-api">

### smooth.clip_circle

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.clip_circle</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Float</span>,
    <span class="p">y</span>: <span class="t">Float</span>,
    <span class="p">radius</span>: <span class="t">Float</span>,
) -&gt; ()</code></pre>

`tw.clip_circle`, with a position and radius that need not be whole.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `x`, `y`: the circle's centre.
- `radius`: its radius.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.clip_circle(c, 100.5, 50.5, 40.25)
tw.rect(c, 0, 0, 200, 100)
```

</div>

<div class="pyk-api">

### smooth.clip_polygon

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">smooth.clip_polygon</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">points</span>: [smooth.Point]) -&gt; ()</code></pre>

`tw.clip_polygon`, through points that need not be whole.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `points`: the polygon's corners.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.smooth as smooth
tw.web_init(0)
c = tw.canvas(200, 100)
smooth.clip_polygon(c, [smooth.Point(100.5, 0.0), smooth.Point(200.0, 100.0), smooth.Point(0.0, 100.0)])
tw.rect(c, 0, 0, 200, 100)
```

</div>
