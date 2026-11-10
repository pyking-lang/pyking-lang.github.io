---
title: random
description: "Random numbers: a Float between 0.0 and 1.0, a whole number in a range, a pick from a list and a list shuffled."
---

Random numbers: a Float between 0.0 and 1.0, a whole number in a
range, a pick from a list and a list shuffled.

The numbers come from a generator written in Pyking, so a program
that calls `seed` first gets the same numbers on every target -- art
that comes out the same each time, and a game that can be replayed.
Without `seed` the generator starts from the clock.

```pyking norun
import random
```

<div class="pyk-api">

## choice

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">choice</span>(<span class="p">items</span>: [a]) -&gt; a</code></pre>

One of the items, chosen at random. The list must not be empty.

<p class="pyk-api-label">Parameters</p>

- `items`: what to choose from.

<p class="pyk-api-label">Returns</p>

The item chosen.

<p class="pyk-api-label">Example</p>

```pyking
import random
color = random.choice(["red", "green", "blue"])
print(len(color) > 2)
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## randint

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">randint</span>(<span class="p">low</span>: <span class="t">Int</span>, <span class="p">high</span>: <span class="t">Int</span>) -&gt; <span class="t">Int</span></code></pre>

A random whole number from `low` to `high`, both included.

<p class="pyk-api-label">Parameters</p>

- `low`: the smallest it may be.
- `high`: the largest it may be; where it is below `low`, the answer is `low`.

<p class="pyk-api-label">Returns</p>

The number.

<p class="pyk-api-label">Example</p>

```pyking
import random
roll = random.randint(1, 6)
print(roll >= 1)
print(roll <= 6)
```

```stdout visible = true
true
true
```

</div>

<div class="pyk-api">

## random

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">random</span>() -&gt; <span class="t">Float</span></code></pre>

A random Float from 0.0 up to, but not including, 1.0.

<p class="pyk-api-label">Returns</p>

The number.

<p class="pyk-api-label">Example</p>

```pyking
import random
x = random.random()
print(x >= 0.0)
print(x < 1.0)
```

```stdout visible = true
true
true
```

</div>

<div class="pyk-api">

## seed

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">seed</span>(<span class="p">n</span>: <span class="t">Int</span>) -&gt; ()</code></pre>

Starts the generator again from `n`, so that what follows is the same
each time the program runs, on every target.

<p class="pyk-api-label">Parameters</p>

- `n`: any whole number; two different ones start two different sequences.

<p class="pyk-api-label">Example</p>

```pyking
import random
random.seed(42)
a = random.randint(1, 100)
random.seed(42)
print(random.randint(1, 100) == a)
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

## shuffle

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">shuffle</span>(<span class="p">items</span>: [a]) -&gt; [a]</code></pre>

The items in a random order: every order equally likely. The list
given is left as it was.

<p class="pyk-api-label">Parameters</p>

- `items`: what to shuffle.

<p class="pyk-api-label">Returns</p>

A new list holding the same items.

<p class="pyk-api-label">Example</p>

```pyking
import random
deck = random.shuffle([1, 2, 3, 4, 5])
print(len(deck))
```

```stdout visible = true
5
```

</div>

<div class="pyk-api">

## uniform

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">uniform</span>(<span class="p">low</span>: <span class="t">Float</span>, <span class="p">high</span>: <span class="t">Float</span>) -&gt; <span class="t">Float</span></code></pre>

A random Float from `low` up to, but not including, `high`.

<p class="pyk-api-label">Parameters</p>

- `low`: the smallest it may be.
- `high`: what it stays below.

<p class="pyk-api-label">Returns</p>

The number.

<p class="pyk-api-label">Example</p>

```pyking
import random
x = random.uniform(-1.0, 1.0)
print(x >= -1.0)
print(x < 1.0)
```

```stdout visible = true
true
true
```

</div>
