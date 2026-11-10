---
title: tinyweb
description: "Graphics, widgets and sound on a web page, kept in time with each other."
sidebar:
  label: tinyweb
---

Graphics, widgets and sound on a web page, kept in time with each
other.

A program builds its page by calling the functions below: each
canvas, button, label and slider goes below the ones before it. A
canvas is drawn on with `clear`, `circle`, `rect`, `line` and `text`,
in pixels from its top left corner; a shape takes a `fill` and a
`stroke` colour from the submodule `tinyweb.color`, or a `Style`
holding both.

What the first programs need is here, in `tinyweb` itself; what comes
later is a submodule of it, named for its subject:

| Submodule | What it holds |
|---|---|
| `tinyweb.color` | colours, and the paints and gradients shapes are filled with |
| `tinyweb.sound` | voices that can be stopped and faded, tones, the beat, channels and listening |
| `tinyweb.bitmap` | pictures built pixel by pixel |
| `tinyweb.layout` | rows, columns and a box of text |
| `tinyweb.net` | saving and loading files |
| `tinyweb.game` | the mouse's cursor |
| `tinyweb.smooth` | the shapes, with positions between pixels |

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

| Module | |
|---|---|
| [`tinyweb`](../tinyweb-core/) | The page, canvases and drawing, widgets, the mouse and keyboard, time, and playing samples. |
| [`tinyweb.color`](../tinyweb-color/) | Colours, and the paints a shape can be filled with. |
| [`tinyweb.sound`](../tinyweb-sound/) | Sound beyond `play`: voices that can be stopped and faded, tones made without a sample, a beat scheduled ahead of time, channels with effects, and listening to what plays. |
| [`tinyweb.bitmap`](../tinyweb-bitmap/) | Pictures built pixel by pixel: fire, plasma, a fractal, an image filter. |
| [`tinyweb.layout`](../tinyweb-layout/) | Where what is made next goes on the page, and a box to write text in. |
| [`tinyweb.net`](../tinyweb-net/) | Files: saving what the program made, and loading a file the reader picks. |
| [`tinyweb.game`](../tinyweb-game/) | What a game needs beyond drawing: for now, the mouse's cursor. |
| [`tinyweb.smooth`](../tinyweb-smooth/) | The shapes, with positions, sizes and widths that may fall between pixels: something moving slowly, a thin line at an angle or a picture built from thousands of short strokes looks smoother. |
