---
title: tinyweb.bitmap
description: "Pictures built pixel by pixel: fire, plasma, a fractal, an image filter."
sidebar:
  label: bitmap
  parent: tinyweb
  position: 4
---

Pictures built pixel by pixel: fire, plasma, a fractal, an image
filter. A bitmap is kept by the program, so setting and reading a
pixel sends nothing to the page; `show_bitmap` draws it on a canvas,
sending only what changed since it was last shown.

```pyking
import tinyweb as tw
import tinyweb.bitmap as bitmap
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(64, 64)
b = bitmap.bitmap(64, 64)
for y in range(64):
    for x in range(64):
        bitmap.set_pixel(b, x, y, color.rgb(x * 4, y * 4, 128))
bitmap.show_bitmap(c, b)
```

```pyking norun
import tinyweb.bitmap as bitmap
```

| Topic | |
|---|---|
| [Bitmaps](#bitmaps) | [`bitmap`](#bitmapbitmap), [`set_pixel`](#bitmapset_pixel), [`get_pixel`](#bitmapget_pixel), [`fill_bitmap`](#bitmapfill_bitmap), [`show_bitmap`](#bitmapshow_bitmap) |

## Bitmaps

<div class="pyk-api">

### bitmap.bitmap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bitmap.bitmap</span>(
    <span class="p">width</span>: <span class="t">Int</span>,
    <span class="p">height</span>: <span class="t">Int</span>,
    <span class="p">background</span>: color.Color = color.white,
) -&gt; <span class="t">String</span></code></pre>

Makes a bitmap: a picture the program builds pixel by pixel. Setting
a pixel sends nothing to the page; `show_bitmap` draws the bitmap on a
canvas in one go. It starts filled with `background`.

<p class="pyk-api-label">Parameters</p>

- `width`: its width in pixels.
- `height`: its height in pixels.
- `background`: the colour every pixel starts as; white by default.

<p class="pyk-api-label">Returns</p>

The bitmap's identifier, which the other bitmap functions take as
`b`: `"bitmap"`, with a number added where something on the page has
that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.bitmap as bitmap
import tinyweb.color as color
tw.web_init(0)
white = bitmap.bitmap(2, 2)
dark = bitmap.bitmap(2, 2, color.black)
print(bitmap.get_pixel(white, 1, 1).r, bitmap.get_pixel(dark, 1, 1).r)
```

```stdout visible = true
255 0
```

</div>

<div class="pyk-api">

### bitmap.set_pixel

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bitmap.set_pixel</span>(
    <span class="p">b</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span>,
    <span class="p">y</span>: <span class="t">Int</span>,
    <span class="p">pixel</span>: color.Color,
) -&gt; ()</code></pre>

Sets one pixel of a bitmap. Nothing is sent to the page until the
bitmap is shown. A pixel outside the bitmap is left alone, and how
opaque the colour is, too: a bitmap's pixels are opaque.

<p class="pyk-api-label">Parameters</p>

- `b`: the bitmap, as `bitmap` answered.
- `x`, `y`: the pixel, from the bitmap's top left corner.
- `pixel`: its colour.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.bitmap as bitmap
import tinyweb.color as color
tw.web_init(0)
b = bitmap.bitmap(10, 10)
bitmap.set_pixel(b, 5, 5, color.red)
print(bitmap.get_pixel(b, 5, 5).r)
```

```stdout visible = true
255
```

</div>

<div class="pyk-api">

### bitmap.get_pixel

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bitmap.get_pixel</span>(<span class="p">b</span>: <span class="t">String</span>, <span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>) -&gt; color.Color</code></pre>

Reads one pixel of a bitmap, at once, since the program keeps it.

<p class="pyk-api-label">Parameters</p>

- `b`: the bitmap, as `bitmap` answered.
- `x`, `y`: the pixel, from the bitmap's top left corner.

<p class="pyk-api-label">Returns</p>

Its colour; black outside the bitmap.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.bitmap as bitmap
import tinyweb.color as color
tw.web_init(0)
b = bitmap.bitmap(4, 4, color.blue)
print(bitmap.get_pixel(b, 1, 2).b, bitmap.get_pixel(b, 9, 9).b)
```

```stdout visible = true
255 0
```

</div>

<div class="pyk-api">

### bitmap.fill_bitmap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bitmap.fill_bitmap</span>(<span class="p">b</span>: <span class="t">String</span>, <span class="p">fill</span>: color.Color) -&gt; ()</code></pre>

Sets every pixel of a bitmap to one colour.

<p class="pyk-api-label">Parameters</p>

- `b`: the bitmap, as `bitmap` answered.
- `fill`: the colour.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.bitmap as bitmap
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(40, 40)
b = bitmap.bitmap(20, 20)
bitmap.fill_bitmap(b, color.green)
bitmap.show_bitmap(c, b, scale = 2.0)
```

</div>

<div class="pyk-api">

### bitmap.show_bitmap

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">bitmap.show_bitmap</span>(
    <span class="p">c</span>: <span class="t">String</span>,
    <span class="p">b</span>: <span class="t">String</span>,
    <span class="p">x</span>: <span class="t">Int</span> = 0,
    <span class="p">y</span>: <span class="t">Int</span> = 0,
    <span class="p">scale</span>: <span class="t">Float</span> = 1.0,
) -&gt; ()</code></pre>

Draws a bitmap on the canvas `c`: what changed since it was last shown
is sent to the page.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas.
- `b`: the bitmap, as `bitmap` answered.
- `x`, `y`: where its top left corner goes; (0, 0) by default.
- `scale`: how many of the canvas's pixels each of its pixels takes across: above 1.0 it is drawn as sharp squares, for pixel art; at 0.5 a bitmap twice the canvas's size fills it, as sharp as the screen can show.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.bitmap as bitmap
import tinyweb.color as color
tw.web_init(0)
c = tw.canvas(160, 160)
b = bitmap.bitmap(16, 16)
for y in range(16):
    for x in range(16):
        bitmap.set_pixel(b, x, y, color.rgb(x * 16, 0, y * 16))
bitmap.show_bitmap(c, b, scale = 10.0)
```

</div>
