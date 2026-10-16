---
title: time
description: "Dates and times: reading the clock, and rendering an instant."
---

Dates and times: reading the clock, and rendering an instant.

An instant is a whole number of seconds since 1970-01-01 00:00:00,
and every date and time is in UTC on every host.

```pyking norun
import time
```

<div class="pyk-api">

## COMPACT

<pre class="pyk-sig"><code><span class="n">COMPACT</span>: <span class="t">String</span> = &quot;yyyyMMddHHmmss&quot;</code></pre>

The format string for a date and a time with nothing between the
fields, as in `20261004123000`, which sorts in time order as text.

<p class="pyk-api-label">Example</p>

```pyking
import time
print(time.format((2026, 10, 4, 12, 30, 0), time.COMPACT))
```

```stdout visible = true
20261004123000
```

</div>

<div class="pyk-api">

## DATE

<pre class="pyk-sig"><code><span class="n">DATE</span>: <span class="t">String</span> = &quot;yyyy-MM-dd&quot;</code></pre>

The format string for a date alone, as in `2026-10-04`.

<p class="pyk-api-label">Example</p>

```pyking
import time
print(time.format((2026, 10, 4, 12, 30, 0), time.DATE))
```

```stdout visible = true
2026-10-04
```

</div>

<div class="pyk-api">

## DATETIME

<pre class="pyk-sig"><code><span class="n">DATETIME</span>: <span class="t">String</span> = &quot;yyyy-MM-dd HH:mm:ss&quot;</code></pre>

The format string for a date and a time separated by a space, as in
`2026-10-04 12:30:00`.

<p class="pyk-api-label">Example</p>

```pyking
import time
print(time.format((2026, 10, 4, 12, 30, 0), time.DATETIME))
```

```stdout visible = true
2026-10-04 12:30:00
```

</div>

<div class="pyk-api">

## ISO8601

<pre class="pyk-sig"><code><span class="n">ISO8601</span>: <span class="t">String</span> = &quot;yyyy-MM-ddTHH:mm:ssZ&quot;</code></pre>

The format string for ISO 8601, as in `2026-10-04T12:30:00Z`.

<p class="pyk-api-label">Example</p>

```pyking
import time
print(time.format((2026, 10, 4, 12, 30, 0), time.ISO8601))
```

```stdout visible = true
2026-10-04T12:30:00Z
```

</div>

<div class="pyk-api">

## TIME

<pre class="pyk-sig"><code><span class="n">TIME</span>: <span class="t">String</span> = &quot;HH:mm:ss&quot;</code></pre>

The format string for a time of day alone, as in `12:30:00`.

<p class="pyk-api-label">Example</p>

```pyking
import time
print(time.format((2026, 10, 4, 12, 30, 0), time.TIME))
```

```stdout visible = true
12:30:00
```

</div>

<div class="pyk-api">

## format

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">format</span>(<span class="p">t</span>: (<span class="t">Int</span>, <span class="t">Int</span>, <span class="t">Int</span>, <span class="t">Int</span>, <span class="t">Int</span>, <span class="t">Int</span>), <span class="p">fmt</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

Writes a date and time as text, following the pattern `fmt`. In `fmt`,
`yyyy` is the year, `MM` the month, `dd` the day, `HH` the hour, `mm`
the minute and `ss` the second, each padded with zeros. The characters
`- : / . ,`, a space, `T` and `Z` are copied as they are. Any other
character ends the text there.

<p class="pyk-api-label">Parameters</p>

- `t`: `(year, month, day, hour, minute, second)`, as `now` and `of_instant` answer.
- `fmt`: the pattern; `ISO8601`, `DATE`, `TIME`, `DATETIME` and `COMPACT` are ready-made ones.

<p class="pyk-api-label">Returns</p>

The formatted text.

<p class="pyk-api-label">Example</p>

```pyking
import time
t = (2026, 1, 9, 8, 5, 3)
print(time.format(t, "dd/MM/yyyy"))
print(time.format(t, "HH.mm"))
```

```stdout visible = true
09/01/2026
08.05
```

</div>

<div class="pyk-api">

## instant

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">instant</span>() -&gt; <span class="t">Int</span></code></pre>

Reads the clock.

<p class="pyk-api-label">Returns</p>

The current time as whole seconds since 1970-01-01 00:00:00 UTC.

<p class="pyk-api-label">Example</p>

```pyking
import time
t = time.instant()
print(t > 1700000000)
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## now

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">now</span>() -&gt; (<span class="t">Int</span>, <span class="t">Int</span>, <span class="t">Int</span>, <span class="t">Int</span>, <span class="t">Int</span>, <span class="t">Int</span>)</code></pre>

Reads the clock once and splits it into a date and a time of day, in
UTC.

<p class="pyk-api-label">Returns</p>

`(year, month, day, hour, minute, second)`, with the month 1 to 12 and
the day 1 to 31.

<p class="pyk-api-label">Example</p>

```pyking
import time
(year, month, day, _, _, _) = time.now()
print(year >= 2026, month >= 1, day >= 1)
```

```stdout visible = true
true true true
```

</div>

<div class="pyk-api">

## of_instant

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">of_instant</span>(<span class="p">t</span>: <span class="t">Int</span>) -&gt; (<span class="t">Int</span>, <span class="t">Int</span>, <span class="t">Int</span>, <span class="t">Int</span>, <span class="t">Int</span>, <span class="t">Int</span>)</code></pre>

Splits an instant into a date and a time of day, in UTC.

<p class="pyk-api-label">Parameters</p>

- `t`: seconds since 1970-01-01 00:00:00 UTC, as `instant` answers.

<p class="pyk-api-label">Returns</p>

`(year, month, day, hour, minute, second)`, with the month 1 to 12 and
the day 1 to 31.

<p class="pyk-api-label">Example</p>

```pyking
import time
print(time.of_instant(0))
print(time.of_instant(86400 + 3661))
```

```stdout visible = true
(1970, 1, 1, 0, 0, 0)
(1970, 1, 2, 1, 1, 1)
```

</div>
