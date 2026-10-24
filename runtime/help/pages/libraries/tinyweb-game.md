---
title: tinyweb.game
description: "What a game needs beyond drawing: for now, the mouse's cursor."
sidebar:
  label: game
  parent: tinyweb
  position: 7
---

What a game needs beyond drawing: for now, the mouse's cursor.

```pyking
import tinyweb as tw
import tinyweb.game as game
tw.web_init(0)
c = tw.canvas(200, 100)
game.cursor(c, "crosshair")
```

```pyking norun
import tinyweb.game as game
```

| Topic | |
|---|---|
| [The cursor](#the-cursor) | [`cursor`](#gamecursor) |

## The cursor

<div class="pyk-api">

### game.cursor

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">game.cursor</span>(<span class="p">c</span>: <span class="t">String</span>, <span class="p">name</span>: <span class="t">String</span>) -&gt; ()</code></pre>

Sets what the mouse's cursor looks like over the canvas `c`, or over
the whole page where `c` is `""`.

<p class="pyk-api-label">Parameters</p>

- `c`: the canvas, or `""` for the page.
- `name`: a CSS cursor: `"default"`, `"pointer"`, `"crosshair"`, `"grab"`, `"grabbing"`, `"none"` and the rest.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.game as game
tw.web_init(0)
c = tw.canvas(200, 100)
game.cursor(c, "grab")
```

</div>
