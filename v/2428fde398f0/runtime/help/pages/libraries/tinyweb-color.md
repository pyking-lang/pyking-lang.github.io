---
title: tinyweb.color
description: "Colours, and the paints a shape can be filled with."
sidebar:
  label: color
  parent: tinyweb
  position: 2
---

Colours, and the paints a shape can be filled with.

A colour is a `Color`: how much red, green and blue, each from 0 to
255, and how opaque it is, from 0.0 (not at all) to 1.0. Make one with
`rgb`, `rgba`, `hsl` or `hex`, take one of the named ones (`black`,
`white`, `red`, ...), or write `Color(255, 136, 0)`. `none` is fully
transparent: a shape with `stroke = color.none` has no outline.

A `Paint` is what fills a shape: a plain colour, or a linear, radial
or conic gradient between two colours, with more stops added by `stop`.

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 100)
tw.clear(c, color.navy)
tw.circle(c, 50, 50, 30, color.rgb(255, 136, 0), stroke = color.white)
sky = color.Linear(0.0, 0.0, 0.0, 100.0, color.blue, color.white)
tw.rect(c, 110, 10, 80, 80, paint = sky)
```

```pyking norun
import tinyweb.color as color
```

| Topic | |
|---|---|
| [Colours](#colours) | [`Color`](#colorcolor), [`black`](#colorblack), [`white`](#colorwhite), [`gray`](#colorgray), [`red`](#colorred), [`green`](#colorgreen), [`blue`](#colorblue), [`yellow`](#coloryellow), [`orange`](#colororange), [`purple`](#colorpurple), [`pink`](#colorpink), [`navy`](#colornavy), [`teal`](#colorteal), [`brown`](#colorbrown), [`cyan`](#colorcyan), [`magenta`](#colormagenta), [`none`](#colornone), [`theme`](#colortheme), [`rgb`](#colorrgb), [`rgba`](#colorrgba), [`hsl`](#colorhsl), [`hex`](#colorhex), [`to_hex`](#colorto_hex), [`with_alpha`](#colorwith_alpha), [`mix`](#colormix), [`same`](#colorsame), [`palette`](#colorpalette) |
| [Paints and gradients](#paints-and-gradients) | [`Paint`](#colorpaint), [`stop`](#colorstop) |

## Colours

<div class="pyk-api">

### color.Color

<pre class="pyk-sig"><code><span class="k">struct</span> <span class="n">color.Color</span>(r: <span class="t">Int</span>, g: <span class="t">Int</span>, b: <span class="t">Int</span>, a = 1.0)</code></pre>

A colour: its red, green and blue parts, each from 0 to 255, and how
opaque it is, from 0.0 (not at all) to 1.0.

<p class="pyk-api-label">Parameters</p>

- `r`, `g`, `b`: how much red, green and blue.
- `a`: how opaque; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
faded = color.Color(255, 0, 0, a = 0.5)
print(faded.r, faded.g, faded.b, faded.a)
```

```stdout visible = true
255 0 0 0.5
```

</div>

<div class="pyk-api">

### color.black

<pre class="pyk-sig"><code><span class="n">color.black</span>: color.Color = color.Color(0, 0, 0)</code></pre>

Black.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.black.r, color.black.g, color.black.b)
```

```stdout visible = true
0 0 0
```

</div>

<div class="pyk-api">

### color.white

<pre class="pyk-sig"><code><span class="n">color.white</span>: color.Color = color.Color(255, 255, 255)</code></pre>

White.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.white.r, color.white.g, color.white.b)
```

```stdout visible = true
255 255 255
```

</div>

<div class="pyk-api">

### color.gray

<pre class="pyk-sig"><code><span class="n">color.gray</span>: color.Color = color.Color(128, 128, 128)</code></pre>

Grey, halfway between black and white.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.gray.r, color.gray.g, color.gray.b)
```

```stdout visible = true
128 128 128
```

</div>

<div class="pyk-api">

### color.red

<pre class="pyk-sig"><code><span class="n">color.red</span>: color.Color = color.Color(255, 0, 0)</code></pre>

Red.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.red.r, color.red.g, color.red.b)
```

```stdout visible = true
255 0 0
```

</div>

<div class="pyk-api">

### color.green

<pre class="pyk-sig"><code><span class="n">color.green</span>: color.Color = color.Color(0, 128, 0)</code></pre>

Green.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.green.r, color.green.g, color.green.b)
```

```stdout visible = true
0 128 0
```

</div>

<div class="pyk-api">

### color.blue

<pre class="pyk-sig"><code><span class="n">color.blue</span>: color.Color = color.Color(0, 0, 255)</code></pre>

Blue.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.blue.r, color.blue.g, color.blue.b)
```

```stdout visible = true
0 0 255
```

</div>

<div class="pyk-api">

### color.yellow

<pre class="pyk-sig"><code><span class="n">color.yellow</span>: color.Color = color.Color(255, 255, 0)</code></pre>

Yellow.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.yellow.r, color.yellow.g, color.yellow.b)
```

```stdout visible = true
255 255 0
```

</div>

<div class="pyk-api">

### color.orange

<pre class="pyk-sig"><code><span class="n">color.orange</span>: color.Color = color.Color(255, 165, 0)</code></pre>

Orange.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.orange.r, color.orange.g, color.orange.b)
```

```stdout visible = true
255 165 0
```

</div>

<div class="pyk-api">

### color.purple

<pre class="pyk-sig"><code><span class="n">color.purple</span>: color.Color = color.Color(128, 0, 128)</code></pre>

Purple.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.purple.r, color.purple.g, color.purple.b)
```

```stdout visible = true
128 0 128
```

</div>

<div class="pyk-api">

### color.pink

<pre class="pyk-sig"><code><span class="n">color.pink</span>: color.Color = color.Color(255, 192, 203)</code></pre>

Pink.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.pink.r, color.pink.g, color.pink.b)
```

```stdout visible = true
255 192 203
```

</div>

<div class="pyk-api">

### color.navy

<pre class="pyk-sig"><code><span class="n">color.navy</span>: color.Color = color.Color(0, 0, 128)</code></pre>

Navy, a dark blue.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.navy.r, color.navy.g, color.navy.b)
```

```stdout visible = true
0 0 128
```

</div>

<div class="pyk-api">

### color.teal

<pre class="pyk-sig"><code><span class="n">color.teal</span>: color.Color = color.Color(0, 128, 128)</code></pre>

Teal, a dark cyan.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.teal.r, color.teal.g, color.teal.b)
```

```stdout visible = true
0 128 128
```

</div>

<div class="pyk-api">

### color.brown

<pre class="pyk-sig"><code><span class="n">color.brown</span>: color.Color = color.Color(139, 69, 19)</code></pre>

Brown.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.brown.r, color.brown.g, color.brown.b)
```

```stdout visible = true
139 69 19
```

</div>

<div class="pyk-api">

### color.cyan

<pre class="pyk-sig"><code><span class="n">color.cyan</span>: color.Color = color.Color(0, 255, 255)</code></pre>

Cyan.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.cyan.r, color.cyan.g, color.cyan.b)
```

```stdout visible = true
0 255 255
```

</div>

<div class="pyk-api">

### color.magenta

<pre class="pyk-sig"><code><span class="n">color.magenta</span>: color.Color = color.Color(255, 0, 255)</code></pre>

Magenta.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.magenta.r, color.magenta.g, color.magenta.b)
```

```stdout visible = true
255 0 255
```

</div>

<div class="pyk-api">

### color.none

<pre class="pyk-sig"><code><span class="n">color.none</span>: color.Color = color.Color(0, 0, 0, a = 0.0)</code></pre>

No colour at all: fully transparent. A shape filled with it shows only
its outline, and one stroked with it has none.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.none.a)
```

```stdout visible = true
0.0
```

</div>

<div class="pyk-api">

### color.theme

<pre class="pyk-sig"><code><span class="n">color.theme</span>: color.Color = color.Color(-1, -1, -1, a = -1.0)</code></pre>

The theme's own colour: what a `_style` function leaves as it is.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.theme.a < 0.0)
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

### color.rgb

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">color.rgb</span>(<span class="p">r</span>: <span class="t">Int</span>, <span class="p">g</span>: <span class="t">Int</span>, <span class="p">b</span>: <span class="t">Int</span>) -&gt; color.Color</code></pre>

A colour from its red, green and blue parts.

<p class="pyk-api-label">Parameters</p>

- `r`, `g`, `b`: how much red, green and blue, each from 0 to 255.

<p class="pyk-api-label">Returns</p>

The colour, fully opaque.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
orange = color.rgb(255, 136, 0)
print(orange.r, orange.g, orange.b)
```

```stdout visible = true
255 136 0
```

</div>

<div class="pyk-api">

### color.rgba

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">color.rgba</span>(<span class="p">r</span>: <span class="t">Int</span>, <span class="p">g</span>: <span class="t">Int</span>, <span class="p">b</span>: <span class="t">Int</span>, <span class="p">a</span>: <span class="t">Float</span>) -&gt; color.Color</code></pre>

A colour from its red, green and blue parts and how opaque it is.

<p class="pyk-api-label">Parameters</p>

- `r`, `g`, `b`: how much red, green and blue, each from 0 to 255.
- `a`: how opaque, from 0.0 (not at all) to 1.0.

<p class="pyk-api-label">Returns</p>

The colour.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.rgba(0, 0, 0, 0.25).a)
```

```stdout visible = true
0.25
```

</div>

<div class="pyk-api">

### color.hsl

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">color.hsl</span>(<span class="p">h</span>: <span class="t">Float</span>, <span class="p">s</span>: <span class="t">Float</span>, <span class="p">l</span>: <span class="t">Float</span>) -&gt; color.Color</code></pre>

A colour from its hue, saturation and lightness: the easy way to walk
round the colour wheel.

<p class="pyk-api-label">Parameters</p>

- `h`: the hue, an angle on the colour wheel in degrees: 0 is red, 120 green and 240 blue.
- `s`: the saturation, from 0 (grey) to 100 (the purest colour).
- `l`: the lightness, from 0 (black) to 100 (white); 50 is the colour itself.

<p class="pyk-api-label">Returns</p>

The colour, fully opaque.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
green = color.hsl(120.0, 100.0, 50.0)
print(green.r, green.g, green.b)
```

```stdout visible = true
0 255 0
```

</div>

<div class="pyk-api">

### color.hex

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">color.hex</span>(<span class="p">n</span>: <span class="t">Int</span>) -&gt; color.Color</code></pre>

A colour from one number holding its red, green and blue parts, as a
hexadecimal literal writes it: `0xff8800` is red 255, green 136, blue 0.

<p class="pyk-api-label">Parameters</p>

- `n`: the colour, `0xRRGGBB`.

<p class="pyk-api-label">Returns</p>

The colour, fully opaque.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
orange = color.hex(0xff8800)
print(orange.r, orange.g, orange.b)
```

```stdout visible = true
255 136 0
```

</div>

<div class="pyk-api">

### color.to_hex

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">color.to_hex</span>(<span class="p">c</span>: color.Color) -&gt; <span class="t">Int</span></code></pre>

A colour as one number, `0xRRGGBB`: what `hex` takes. How opaque it is
is left out.

<p class="pyk-api-label">Parameters</p>

- `c`: the colour.

<p class="pyk-api-label">Returns</p>

Its red part times 65536, plus its green part times 256, plus its blue part.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.to_hex(color.rgb(255, 136, 0)) == 0xff8800)
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

### color.with_alpha

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">color.with_alpha</span>(<span class="p">c</span>: color.Color, <span class="p">a</span>: <span class="t">Float</span>) -&gt; color.Color</code></pre>

The same colour with another opacity.

<p class="pyk-api-label">Parameters</p>

- `c`: the colour.
- `a`: how opaque, from 0.0 to 1.0.

<p class="pyk-api-label">Returns</p>

The colour.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.with_alpha(color.red, 0.5).a)
```

```stdout visible = true
0.5
```

</div>

<div class="pyk-api">

### color.mix

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">color.mix</span>(<span class="p">a</span>: color.Color, <span class="p">b</span>: color.Color, <span class="p">t</span>: <span class="t">Float</span>) -&gt; color.Color</code></pre>

A colour between two others: `t` 0.0 is `a`, 1.0 is `b`, 0.5 halfway.

<p class="pyk-api-label">Parameters</p>

- `a`, `b`: the two colours.
- `t`: how far from `a` towards `b`, from 0.0 to 1.0.

<p class="pyk-api-label">Returns</p>

The colour, each part and the opacity taken that far.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
grey = color.mix(color.black, color.white, 0.5)
print(grey.r, grey.g, grey.b)
```

```stdout visible = true
128 128 128
```

</div>

<div class="pyk-api">

### color.same

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">color.same</span>(<span class="p">a</span>: color.Color, <span class="p">b</span>: color.Color) -&gt; <span class="t">Bool</span></code></pre>

Whether two colours are the same: every part and the opacity.

<p class="pyk-api-label">Parameters</p>

- `a`, `b`: the colours.

<p class="pyk-api-label">Returns</p>

`true` when they are the same colour.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
print(color.same(color.rgb(255, 0, 0), color.red), color.same(color.red, color.blue))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

### color.palette

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">color.palette</span>(<span class="p">name</span>: <span class="t">String</span>) -&gt; [color.Color]</code></pre>

Five colours that go together, for a picture that should look
designed.

<p class="pyk-api-label">Parameters</p>

- `name`: `"ocean"`, `"candy"`, `"forest"`, `"sunset"` or `"neon"`.

<p class="pyk-api-label">Returns</p>

The five colours, darkest or first first; no colours for a name there
is none of, which is reported on the debug output.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.color as color
ocean = color.palette("ocean")
match ocean:
    case [darkest, ..rest]:
        print(len(ocean), darkest.b, len(rest))
    case []:
        print("none")
```

```stdout visible = true
5 94 4
```

</div>

## Paints and gradients

<div class="pyk-api">

### color.Paint

<pre class="pyk-sig"><code><span class="k">datatype</span> <span class="n">color.Paint</span>:
    Plain(color.Color)
    Linear(x1: <span class="t">Float</span>, y1: <span class="t">Float</span>, x2: <span class="t">Float</span>, y2: <span class="t">Float</span>, start: color.Color, end: color.Color, stops = "")
    Radial(x1: <span class="t">Float</span>, y1: <span class="t">Float</span>, r1: <span class="t">Float</span>, x2: <span class="t">Float</span>, y2: <span class="t">Float</span>, r2: <span class="t">Float</span>, start: color.Color, end: color.Color, stops = "")
    Conic(x: <span class="t">Float</span>, y: <span class="t">Float</span>, angle: <span class="t">Float</span>, start: color.Color, end: color.Color, stops = "")</code></pre>

What fills a shape: a plain colour, or a gradient between two colours
across a line (`Linear`), out from a circle (`Radial`) or round a
point (`Conic`). Positions are in the canvas's pixels, and an angle is
in radians. `stop` adds a colour on the way; `stops` is how those are
kept, and is left out when one is written.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 100)
glow = color.Radial(100.0, 50.0, 0.0, 100.0, 50.0, 50.0, color.yellow, color.none)
tw.circle(c, 100, 50, 50, paint = glow)
```

</div>

<div class="pyk-api">

### color.stop

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">color.stop</span>(
    <span class="p">paint</span>: color.Paint,
    <span class="p">at</span>: <span class="t">Float</span>,
    <span class="p">c</span>: color.Color,
) -&gt; color.Paint</code></pre>

A gradient with one more colour on the way: `at` 0.0 is where it
starts and 1.0 where it ends. A plain colour is left as it is.

<p class="pyk-api-label">Parameters</p>

- `paint`: the gradient.
- `at`: where the colour is, from 0.0 to 1.0.
- `c`: the colour.

<p class="pyk-api-label">Returns</p>

The gradient.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(200, 40)
rainbow = color.stop(color.Linear(0.0, 0.0, 200.0, 0.0, color.red, color.blue), 0.5, color.green)
tw.rect(c, 0, 0, 200, 40, paint = rainbow)
```

</div>
