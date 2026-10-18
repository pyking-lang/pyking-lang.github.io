---
title: math
description: "Numbers: trigonometry in degrees and in radians, powers and logarithms, rounding to an Int, and helpers for drawing and games."
---

Numbers: trigonometry in degrees and in radians, powers and
logarithms, rounding to an Int, and helpers for drawing and games.

Angles are in **degrees**: `sin(90.0)` is `1.0`. Each trigonometric
function has a twin ending in `_rad` that works in radians, and
`radians` and `degrees` convert between the two. `abs`, `min`, `max`,
`clamp`, `sign` and `mod` take two Ints or two Floats and answer the
same type; everything else takes and answers Floats, so an Int is
passed as `float(n)`.

```pyking norun
import math
```

<div class="pyk-api">

## e

<pre class="pyk-sig"><code><span class="n">e</span>: <span class="t">Float</span> = 2.718281828459045</code></pre>

Euler's number, the base of the natural logarithm.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.e)
```

```stdout visible = true
2.718281828459045
```

</div>

<div class="pyk-api">

## inf

<pre class="pyk-sig"><code><span class="n">inf</span>: <span class="t">Float</span> = 1.0e999</code></pre>

Positive infinity, larger than every other Float. `-math.inf` is
negative infinity.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.inf, -math.inf, 1.0e300 < math.inf)
```

```stdout visible = true
inf -inf true
```

</div>

<div class="pyk-api">

## nan

<pre class="pyk-sig"><code><span class="n">nan</span>: <span class="t">Float</span> = 0.0 / 0.0</code></pre>

Not a number: what an operation with no answer gives, such as
`0.0 / 0.0`. A NaN is equal to nothing, itself included, so test for
one with `is_nan`.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.nan, math.nan == math.nan, math.is_nan(math.nan))
```

```stdout visible = true
nan false true
```

</div>

<div class="pyk-api">

## pi

<pre class="pyk-sig"><code><span class="n">pi</span>: <span class="t">Float</span> = 3.141592653589793</code></pre>

The ratio of a circle's circumference to its diameter, π.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.pi)
```

```stdout visible = true
3.141592653589793
```

</div>

<div class="pyk-api">

## tau

<pre class="pyk-sig"><code><span class="n">tau</span>: <span class="t">Float</span> = 6.283185307179586</code></pre>

A whole turn in radians, 2π.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.tau)
```

```stdout visible = true
6.283185307179586
```

</div>

<div class="pyk-api">

## acos

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">acos</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The angle in degrees whose cosine is `x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the cosine, from -1 to 1.

<p class="pyk-api-label">Returns</p>

The angle, from 0 to 180 degrees; NaN when `x` is outside -1 to 1.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.acos(0.5), math.acos(0.0), math.acos(-1.0))
```

```stdout visible = true
60.0 90.0 180.0
```

</div>

<div class="pyk-api">

## acos_rad

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">acos_rad</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The angle in radians whose cosine is `x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the cosine, from -1 to 1.

<p class="pyk-api-label">Returns</p>

The angle, from 0 to π; NaN when `x` is outside -1 to 1.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.acos_rad(-1.0) == math.pi)
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## asin

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">asin</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The angle in degrees whose sine is `x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the sine, from -1 to 1.

<p class="pyk-api-label">Returns</p>

The angle, from -90 to 90 degrees; NaN when `x` is outside -1 to 1.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.asin(0.5), math.asin(1.0), math.asin(-1.0))
```

```stdout visible = true
30.0 90.0 -90.0
```

</div>

<div class="pyk-api">

## asin_rad

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">asin_rad</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The angle in radians whose sine is `x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the sine, from -1 to 1.

<p class="pyk-api-label">Returns</p>

The angle, from -π/2 to π/2; NaN when `x` is outside -1 to 1.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.asin_rad(1.0) == math.pi / 2.0)
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## atan

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">atan</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The angle in degrees whose tangent is `x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the tangent.

<p class="pyk-api-label">Returns</p>

The angle, between -90 and 90 degrees.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.atan(1.0), math.atan(-1.0), math.atan(math.inf))
```

```stdout visible = true
45.0 -45.0 90.0
```

</div>

<div class="pyk-api">

## atan2

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">atan2</span>(<span class="p">y</span>: <span class="t">Float</span>, <span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The direction in degrees from the origin to the point (`x`, `y`): the
angle a line from (0, 0) to that point makes with the x axis. Unlike
`atan(y / x)`, it tells all four quarters of the plane apart. Note the
order: `y` comes first.

<p class="pyk-api-label">Parameters</p>

- `y`: the point's y coordinate.
- `x`: the point's x coordinate.

<p class="pyk-api-label">Returns</p>

The angle, from -180 to 180 degrees.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.atan2(1.0, 1.0), math.atan2(1.0, -1.0), math.atan2(-1.0, 0.0))
```

```stdout visible = true
45.0 135.0 -90.0
```

</div>

<div class="pyk-api">

## atan2_rad

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">atan2_rad</span>(<span class="p">y</span>: <span class="t">Float</span>, <span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The direction in radians from the origin to the point (`x`, `y`), as
`atan2` answers it in degrees. `y` comes first.

<p class="pyk-api-label">Parameters</p>

- `y`: the point's y coordinate.
- `x`: the point's x coordinate.

<p class="pyk-api-label">Returns</p>

The angle, from -π to π.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.atan2_rad(0.0, -1.0) == math.pi)
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## atan_rad

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">atan_rad</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The angle in radians whose tangent is `x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the tangent.

<p class="pyk-api-label">Returns</p>

The angle, between -π/2 and π/2.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.atan_rad(0.0))
```

```stdout visible = true
0.0
```

</div>

<div class="pyk-api">

## cbrt

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">cbrt</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The cube root of `x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the number, which may be negative.

<p class="pyk-api-label">Returns</p>

The root, negative for a negative `x`, and exact for a perfect cube.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.cbrt(27.0), math.cbrt(-8.0))
```

```stdout visible = true
3.0 -2.0
```

</div>

<div class="pyk-api">

## ceil

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">ceil</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Int</span></code></pre>

The smallest whole number not less than `x`, rounding up.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.

<p class="pyk-api-label">Returns</p>

The Int; 0 for a NaN, an infinity, or a number outside the Int range,
as `int` answers.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.ceil(2.2), math.ceil(-2.7))
```

```stdout visible = true
3 -2
```

</div>

<div class="pyk-api">

## cos

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">cos</span>(<span class="p">angle</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The cosine of an angle in degrees.

<p class="pyk-api-label">Parameters</p>

- `angle`: the angle in degrees.

<p class="pyk-api-label">Returns</p>

The cosine, from -1 to 1. It is exact at every multiple of 30 degrees:
`cos(60.0)` is `0.5` and `cos(90.0)` is `0.0`.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.cos(0.0), math.cos(60.0), math.cos(90.0), math.cos(180.0))
```

```stdout visible = true
1.0 0.5 0.0 -1.0
```

</div>

<div class="pyk-api">

## cos_rad

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">cos_rad</span>(<span class="p">angle</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The cosine of an angle in radians.

<p class="pyk-api-label">Parameters</p>

- `angle`: the angle in radians.

<p class="pyk-api-label">Returns</p>

The cosine, from -1 to 1.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.cos_rad(0.0), math.cos_rad(math.pi))
```

```stdout visible = true
1.0 -1.0
```

</div>

<div class="pyk-api">

## cosh

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">cosh</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The hyperbolic cosine of `x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.

<p class="pyk-api-label">Returns</p>

`(e^x + e^-x) / 2`, at least 1.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.cosh(0.0))
```

```stdout visible = true
1.0
```

</div>

<div class="pyk-api">

## degrees

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">degrees</span>(<span class="p">angle</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

An angle in radians, in degrees.

<p class="pyk-api-label">Parameters</p>

- `angle`: the angle in radians.

<p class="pyk-api-label">Returns</p>

The same angle in degrees: `angle * 180 / pi`.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.degrees(math.pi))
```

```stdout visible = true
180.0
```

</div>

<div class="pyk-api">

## distance

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">distance</span>(<span class="p">x1</span>: <span class="t">Float</span>, <span class="p">y1</span>: <span class="t">Float</span>, <span class="p">x2</span>: <span class="t">Float</span>, <span class="p">y2</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The distance between the points (`x1`, `y1`) and (`x2`, `y2`).

<p class="pyk-api-label">Parameters</p>

- `x1`: the first point's x coordinate.
- `y1`: the first point's y coordinate.
- `x2`: the second point's x coordinate.
- `y2`: the second point's y coordinate.

<p class="pyk-api-label">Returns</p>

The distance, at least 0.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.distance(1.0, 1.0, 4.0, 5.0))
```

```stdout visible = true
5.0
```

</div>

<div class="pyk-api">

## exp

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">exp</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

e raised to the power `x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the exponent.

<p class="pyk-api-label">Returns</p>

e^x, always positive.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.exp(0.0), math.exp(1.0) == math.e)
```

```stdout visible = true
1.0 true
```

</div>

<div class="pyk-api">

## float::abs

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::abs</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The size of a Float, without its sign.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.

<p class="pyk-api-label">Returns</p>

`x` when it is at least 0, and `-x` otherwise; NaN for a NaN.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.abs(-2.5), math.abs(-math.inf))
```

```stdout visible = true
2.5 inf
```

</div>

<div class="pyk-api">

## float::clamp

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::clamp</span>(<span class="p">x</span>: <span class="t">Float</span>, <span class="p">low</span>: <span class="t">Float</span>, <span class="p">high</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

A Float kept within a range: `x` itself when it is between `low` and
`high`, and the nearer end when it is outside.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.
- `low`: the smallest answer.
- `high`: the largest answer, at least `low`.

<p class="pyk-api-label">Returns</p>

`x` limited to `low` to `high`; NaN when `x` is NaN.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.clamp(1.5, 0.0, 1.0), math.clamp(0.25, 0.0, 1.0))
```

```stdout visible = true
1.0 0.25
```

</div>

<div class="pyk-api">

## float::max

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::max</span>(<span class="p">x</span>: <span class="t">Float</span>, <span class="p">y</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The larger of two Floats.

<p class="pyk-api-label">Parameters</p>

- `x`: one number.
- `y`: the other.

<p class="pyk-api-label">Returns</p>

Whichever is larger; NaN when either is NaN.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.max(1.5, 0.5))
```

```stdout visible = true
1.5
```

</div>

<div class="pyk-api">

## float::min

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::min</span>(<span class="p">x</span>: <span class="t">Float</span>, <span class="p">y</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The smaller of two Floats.

<p class="pyk-api-label">Parameters</p>

- `x`: one number.
- `y`: the other.

<p class="pyk-api-label">Returns</p>

Whichever is smaller; NaN when either is NaN.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.min(1.5, 0.5))
```

```stdout visible = true
0.5
```

</div>

<div class="pyk-api">

## float::mod

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::mod</span>(<span class="p">x</span>: <span class="t">Float</span>, <span class="p">y</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The remainder of dividing `x` by `y`, rounding the quotient down, so
that the answer has the sign of `y`: `mod(-90.0, 360.0)` is 270.0.

<p class="pyk-api-label">Parameters</p>

- `x`: the number divided.
- `y`: the number divided by.

<p class="pyk-api-label">Returns</p>

A number from 0 up to, but not including, `y` -- or down to it, when
`y` is negative; NaN when `y` is 0 or `x` is infinite.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.mod(-90.0, 360.0), math.mod(7.5, 2.0))
```

```stdout visible = true
270.0 1.5
```

</div>

<div class="pyk-api">

## float::sign

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">float::sign</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The sign of a Float.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.

<p class="pyk-api-label">Returns</p>

-1.0 for a negative `x`, 0.0 for zero, 1.0 for a positive `x`, and
NaN for a NaN.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.sign(-2.5), math.sign(0.0), math.sign(math.inf))
```

```stdout visible = true
-1.0 0.0 1.0
```

</div>

<div class="pyk-api">

## floor

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">floor</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Int</span></code></pre>

The largest whole number not greater than `x`, rounding down.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.

<p class="pyk-api-label">Returns</p>

The Int; 0 for a NaN, an infinity, or a number outside the Int range,
as `int` answers.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.floor(2.7), math.floor(-2.2))
```

```stdout visible = true
2 -3
```

</div>

<div class="pyk-api">

## gcd

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">gcd</span>(<span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

The greatest common divisor of two Ints: the largest number both are
multiples of.

<p class="pyk-api-label">Parameters</p>

- `x`: one number.
- `y`: the other.

<p class="pyk-api-label">Returns</p>

The divisor, at least 0; `gcd(0, 0)` is 0.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.gcd(12, 18), math.gcd(-4, 6), math.gcd(7, 0))
```

```stdout visible = true
6 2 7
```

</div>

<div class="pyk-api">

## hypot

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">hypot</span>(<span class="p">x</span>: <span class="t">Float</span>, <span class="p">y</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The length of the hypotenuse of a right triangle with sides `x` and
`y`: the distance from (0, 0) to (`x`, `y`).

<p class="pyk-api-label">Parameters</p>

- `x`: one side.
- `y`: the other side.

<p class="pyk-api-label">Returns</p>

`sqrt(x * x + y * y)`, without overflowing where `x * x` would.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.hypot(3.0, 4.0))
```

```stdout visible = true
5.0
```

</div>

<div class="pyk-api">

## int::abs

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::abs</span>(<span class="p">x</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

The size of an Int, without its sign.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.

<p class="pyk-api-label">Returns</p>

`x` when it is at least 0, and `-x` otherwise.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.abs(-3), math.abs(3))
```

```stdout visible = true
3 3
```

</div>

<div class="pyk-api">

## int::clamp

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::clamp</span>(<span class="p">x</span>: <span class="t">Int</span>, <span class="p">low</span>: <span class="t">Int</span>, <span class="p">high</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

An Int kept within a range: `x` itself when it is between `low` and
`high`, and the nearer end when it is outside.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.
- `low`: the smallest answer.
- `high`: the largest answer, at least `low`.

<p class="pyk-api-label">Returns</p>

`x` limited to `low` to `high`.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.clamp(5, 0, 10), math.clamp(-5, 0, 10), math.clamp(15, 0, 10))
```

```stdout visible = true
5 0 10
```

</div>

<div class="pyk-api">

## int::max

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::max</span>(<span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

The larger of two Ints.

<p class="pyk-api-label">Parameters</p>

- `x`: one number.
- `y`: the other.

<p class="pyk-api-label">Returns</p>

Whichever is larger.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.max(3, 7), math.max(-3, -7))
```

```stdout visible = true
7 -3
```

</div>

<div class="pyk-api">

## int::min

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::min</span>(<span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

The smaller of two Ints.

<p class="pyk-api-label">Parameters</p>

- `x`: one number.
- `y`: the other.

<p class="pyk-api-label">Returns</p>

Whichever is smaller.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.min(3, 7), math.min(-3, -7))
```

```stdout visible = true
3 -7
```

</div>

<div class="pyk-api">

## int::mod

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::mod</span>(<span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

The remainder of dividing `x` by `y`, rounding the quotient down, so
that the answer has the sign of `y`: `mod(-1, 360)` is 359. That is
the remainder to use for wrapping around, such as an angle or a
position on a board.

<p class="pyk-api-label">Parameters</p>

- `x`: the number divided.
- `y`: the number divided by, not 0.

<p class="pyk-api-label">Returns</p>

A number from 0 up to, but not including, `y` -- or down to it, when
`y` is negative.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.mod(7, 3), math.mod(-7, 3), math.mod(7, -3))
```

```stdout visible = true
1 2 -2
```

</div>

<div class="pyk-api">

## int::sign

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">int::sign</span>(<span class="p">x</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

The sign of an Int.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.

<p class="pyk-api-label">Returns</p>

-1 for a negative `x`, 0 for 0, and 1 for a positive `x`.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.sign(-5), math.sign(0), math.sign(5))
```

```stdout visible = true
-1 0 1
```

</div>

<div class="pyk-api">

## is_finite

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">is_finite</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Bool</span></code></pre>

Tells whether `x` is an ordinary number: neither infinite nor NaN.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.

<p class="pyk-api-label">Returns</p>

`true` unless `x` is an infinity or a NaN.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.is_finite(1.5), math.is_finite(math.inf), math.is_finite(math.nan))
```

```stdout visible = true
true false false
```

</div>

<div class="pyk-api">

## is_nan

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">is_nan</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Bool</span></code></pre>

Tells whether `x` is NaN.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.

<p class="pyk-api-label">Returns</p>

`true` for a NaN, `false` for every other Float.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.is_nan(0.0 / 0.0), math.is_nan(1.0))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## lcm

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">lcm</span>(<span class="p">x</span>: <span class="t">Int</span>, <span class="p">y</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

The least common multiple of two Ints: the smallest number that is a
multiple of both.

<p class="pyk-api-label">Parameters</p>

- `x`: one number.
- `y`: the other.

<p class="pyk-api-label">Returns</p>

The multiple, at least 0; 0 when either is 0.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.lcm(4, 6), math.lcm(-3, 5), math.lcm(0, 5))
```

```stdout visible = true
12 15 0
```

</div>

<div class="pyk-api">

## lerp

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">lerp</span>(<span class="p">a</span>: <span class="t">Float</span>, <span class="p">b</span>: <span class="t">Float</span>, <span class="p">t</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The number a fraction `t` of the way from `a` to `b`: `a` when `t` is
0, `b` when it is 1, and halfway between them when it is 0.5. A `t`
outside 0 to 1 goes past the ends.

<p class="pyk-api-label">Parameters</p>

- `a`: where it starts.
- `b`: where it ends.
- `t`: how far along, usually from 0 to 1.

<p class="pyk-api-label">Returns</p>

`a + (b - a) * t`.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.lerp(10.0, 20.0, 0.25), math.lerp(10.0, 20.0, 1.0))
```

```stdout visible = true
12.5 20.0
```

</div>

<div class="pyk-api">

## log

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">log</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The natural logarithm of `x`, the power e has to be raised to to give
`x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the number, greater than 0.

<p class="pyk-api-label">Returns</p>

The logarithm; `-inf` for 0, and NaN for a negative `x`.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.log(1.0), math.log(math.e), math.log(0.0))
```

```stdout visible = true
0.0 1.0 -inf
```

</div>

<div class="pyk-api">

## log10

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">log10</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The base-10 logarithm of `x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the number, greater than 0.

<p class="pyk-api-label">Returns</p>

The logarithm; `-inf` for 0, and NaN for a negative `x`.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.log10(1000.0), math.log10(0.01))
```

```stdout visible = true
3.0 -2.0
```

</div>

<div class="pyk-api">

## log2

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">log2</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The base-2 logarithm of `x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the number, greater than 0.

<p class="pyk-api-label">Returns</p>

The logarithm, exact for a power of two; `-inf` for 0, and NaN for a
negative `x`.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.log2(8.0), math.log2(0.5))
```

```stdout visible = true
3.0 -1.0
```

</div>

<div class="pyk-api">

## map_range

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">map_range</span>(
    <span class="p">x</span>: <span class="t">Float</span>,
    <span class="p">from_low</span>: <span class="t">Float</span>,
    <span class="p">from_high</span>: <span class="t">Float</span>,
    <span class="p">to_low</span>: <span class="t">Float</span>,
    <span class="p">to_high</span>: <span class="t">Float</span>,
) -&gt; <span class="t">Float</span></code></pre>

A number moved from one range to another, keeping its place: `x` is
as far from `from_low` towards `from_high` as the answer is from
`to_low` towards `to_high`. A mouse position becomes a volume, a
time becomes a color.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.
- `from_low`: the start of the range `x` is in.
- `from_high`: the end of that range, not equal to `from_low`.
- `to_low`: the start of the range to move it to.
- `to_high`: the end of that range.

<p class="pyk-api-label">Returns</p>

The number in the new range. A number outside the first range lands
outside the second; `clamp` keeps it in.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.map_range(5.0, 0.0, 10.0, 100.0, 200.0))
print(math.map_range(0.25, 0.0, 1.0, 255.0, 0.0))
```

```stdout visible = true
150.0
191.25
```

</div>

<div class="pyk-api">

## pow

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">pow</span>(<span class="p">x</span>: <span class="t">Float</span>, <span class="p">y</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

`x` raised to the power `y`.

<p class="pyk-api-label">Parameters</p>

- `x`: the base.
- `y`: the exponent.

<p class="pyk-api-label">Returns</p>

x^y. It is NaN for a negative `x` with an exponent that is not a whole
number, and `pow(x, 0.0)` is 1.0 for every `x`.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.pow(2.0, 10.0), math.pow(9.0, 0.5), math.pow(2.0, -1.0))
```

```stdout visible = true
1024.0 3.0 0.5
```

</div>

<div class="pyk-api">

## radians

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">radians</span>(<span class="p">angle</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

An angle in degrees, in radians.

<p class="pyk-api-label">Parameters</p>

- `angle`: the angle in degrees.

<p class="pyk-api-label">Returns</p>

The same angle in radians: `angle * pi / 180`.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.radians(180.0))
```

```stdout visible = true
3.141592653589793
```

</div>

<div class="pyk-api">

## round

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">round</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Int</span></code></pre>

`x` rounded to the nearest whole number, a tie going away from zero:
2.5 rounds to 3, and -2.5 to -3.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.

<p class="pyk-api-label">Returns</p>

The Int; 0 for a NaN, an infinity, or a number outside the Int range,
as `int` answers.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.round(2.4), math.round(2.5), math.round(-2.5), math.round(-2.6))
```

```stdout visible = true
2 3 -3 -3
```

</div>

<div class="pyk-api">

## sin

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sin</span>(<span class="p">angle</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The sine of an angle in degrees.

<p class="pyk-api-label">Parameters</p>

- `angle`: the angle in degrees.

<p class="pyk-api-label">Returns</p>

The sine, from -1 to 1. It is exact at every multiple of 30 degrees:
`sin(30.0)` is `0.5` and `sin(180.0)` is `0.0`.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.sin(30.0), math.sin(90.0), math.sin(-90.0))
```

```stdout visible = true
0.5 1.0 -1.0
```

</div>

<div class="pyk-api">

## sin_rad

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sin_rad</span>(<span class="p">angle</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The sine of an angle in radians.

<p class="pyk-api-label">Parameters</p>

- `angle`: the angle in radians.

<p class="pyk-api-label">Returns</p>

The sine, from -1 to 1.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.sin_rad(0.0), math.sin_rad(math.pi / 2.0))
```

```stdout visible = true
0.0 1.0
```

</div>

<div class="pyk-api">

## sinh

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sinh</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The hyperbolic sine of `x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.

<p class="pyk-api-label">Returns</p>

`(e^x - e^-x) / 2`.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.sinh(0.0))
```

```stdout visible = true
0.0
```

</div>

<div class="pyk-api">

## sqrt

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sqrt</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The square root of `x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the number, at least 0.

<p class="pyk-api-label">Returns</p>

The root that is at least 0; NaN for a negative `x`.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.sqrt(16.0), math.sqrt(2.0))
```

```stdout visible = true
4.0 1.4142135623730951
```

</div>

<div class="pyk-api">

## tan

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">tan</span>(<span class="p">angle</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The tangent of an angle in degrees.

<p class="pyk-api-label">Parameters</p>

- `angle`: the angle in degrees.

<p class="pyk-api-label">Returns</p>

The tangent. It is exact at every multiple of 45 degrees, and `inf`
at 90 degrees, 270 degrees and so on, where the tangent grows without
bound.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.tan(45.0), math.tan(135.0), math.tan(90.0))
```

```stdout visible = true
1.0 -1.0 inf
```

</div>

<div class="pyk-api">

## tan_rad

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">tan_rad</span>(<span class="p">angle</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The tangent of an angle in radians.

<p class="pyk-api-label">Parameters</p>

- `angle`: the angle in radians.

<p class="pyk-api-label">Returns</p>

The tangent.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.tan_rad(0.0))
```

```stdout visible = true
0.0
```

</div>

<div class="pyk-api">

## tanh

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">tanh</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

The hyperbolic tangent of `x`.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.

<p class="pyk-api-label">Returns</p>

`sinh(x) / cosh(x)`, between -1 and 1.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.tanh(0.0), math.tanh(math.inf))
```

```stdout visible = true
0.0 1.0
```

</div>

<div class="pyk-api">

## trunc

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">trunc</span>(<span class="p">x</span>: <span class="t">Float</span>) -&gt; <span class="t">Int</span></code></pre>

`x` without its fraction, rounding toward zero, as `int(x)` does.

<p class="pyk-api-label">Parameters</p>

- `x`: the number.

<p class="pyk-api-label">Returns</p>

The Int; 0 for a NaN, an infinity, or a number outside the Int range.

<p class="pyk-api-label">Example</p>

```pyking
import math
print(math.trunc(2.7), math.trunc(-2.7))
```

```stdout visible = true
2 -2
```

</div>
