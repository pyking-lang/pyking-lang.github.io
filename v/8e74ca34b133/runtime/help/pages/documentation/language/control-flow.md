---
title: "Control flow"
description: "if, for, while and loop, break and continue."
sidebar:
  parent: Language reference
  position: 7
---

> **Available:** in every module · **Compared with Python:** mostly the
> same; `else if` instead of `elif`, no `while … else`, and the `loop`
> loop is new

`if`, `for` and `while` are Python's. `loop` is Pyking's own: a loop
that carries an accumulator from one turn to the next and answers its
final value, which is how a functional module adds things up.

## `if`/`else` statements

`if cond:` runs its indented body when `cond` holds. An optional
`else:` with its own indented body runs otherwise.

```python
def classify(x):
    if x >= 10:
        return 1
    else:
        return 0


print(classify(12), classify(3))
```

Further conditions chain with `else if` — two ordinary keywords, since
Pyking has no `elif`. Each `else if` takes its own condition and
indented body, and the first branch whose condition holds is the only
one that runs. The trailing `else:` stays optional: without it, a value
matching none of the conditions runs no branch at all. The example below
is therefore Pyking source, not valid Python — it compiles to Python's
`elif`.

```pyking
def grade(score):
    if score >= 90:
        return "A"
    else if score >= 80:
        return "B"
    else if score >= 70:
        return "C"
    else:
        return "F"


print(grade(95), grade(85), grade(75), grade(65))
```

Because `else if` is just an `else` block holding one nested `if`
statement (see the notes on the Grammar), the two forms below mean
exactly the same thing; the flat one is preferred, and is the form the
Pyking pretty-printer produces for either.

```pyking norun
if a:
    print(1)
else if b:
    print(2)

if a:
    print(1)
else:
    if b:
        print(2)
```

## `for`/`in` loops

`for name in iterable:` binds `name` to each successive element produced
by `iterable`, running the indented body once per element. The iterable
is a list, or a String, whose elements are its characters, each a
`Char`; a comprehension walks a String the same way.

```python
for i in range(3):
    print(i)
for c in "ok":
    print(c)
```

## `while` loops

`while cond:` runs its indented body repeatedly for as long as `cond`
holds.

```pyking
use mutation

var i = 0
while i < 3:
    print(i)
    i := i + 1
```

## `loop` loops -- Pyking extension

`loop` is a loop whose state is a *binding* rather than a mutable
variable, and which is worth something when it stops. Python has no
equivalent, so everything in this section is Pyking source rather than
valid Python.

`loop x = 5:` evaluates `5` once and binds `x` to it for the first turn.
What the body ends in is the next turn's `x`, and `break` ends the loop,
which is then worth the `x` the turn it stopped on started with:

```pyking
counted = loop x = 5:
    if x <= 10:
        x + 1
    else:
        break

print(counted)          # 11
```

The body's last statement is the accumulator, recursively through the
branches of a trailing `if` or `match` -- the same tail-position rule a
function body follows. A path ending in `break`, `continue` or `return`
says nothing, since none of them reaches the end of the body.

**What a loop carries is what it is worth.** The accumulator is the
state -- the initializer's type, and what the body must end in -- and it
is the loop's value when it stops, whichever way it stops. So a loop
answers with what it carries, and a loop that carries two things answers
with the pair:

```pyking
def factorial(n, acc) -> Int:
    (left, product) = loop n, acc = n, acc:   # carries (Int, Int)
        if n == 0:
            break                             # and is worth (Int, Int)
        else:
            (n - 1, n * acc)
    return product


print(factorial(10, 1))        # 3628800
```

`continue` says "go round again" from wherever it is written, skipping
the rest of the body; the next turn starts with the accumulator this one
started with, so it is a way to leave the accumulator alone for a turn:

```pyking
def total_positive(xs:[Int]) -> Int:
    return loop acc = 0 for x in xs:
        if x < 0:
            continue        # this element adds nothing
        acc + x


print(total_positive([1, 0 - 5, 2]))    # 3
```

**A jump may carry the accumulator.** `break x` stops the loop worth
`x`, and `continue x` goes round with `x` as the next turn's
accumulator -- so a loop can stop with something other than what the
turn started with, or go round early with a new value, without arranging
for the body to end in it. The value is written the way the header's
initializer is, a tuple with or without its parentheses:

```pyking
def first_over(xs:[Int], limit:Int) -> Int:
    return loop found = 0 - 1 for x in xs:
        if x > limit:
            break x         # the loop is worth this element
        found


def saturating_sum(xs:[Int]) -> Int:
    return loop acc = 0 for x in xs:
        if acc + x > 10:
            continue 10     # the next turn starts from 10
        acc + x


steps, last = loop steps, n = 0, 6:
    if n == 1:
        break steps, n
    else if n % 2 == 0:
        continue steps + 1, n / 2
    steps + 1, 3 * n + 1


print(first_over([1, 5, 9, 12], 6))      # 9
print(saturating_sum([3, 4, 5, 6]))      # 10
print(steps, last)                       # 8 1
```

The value must have the accumulator's type (`this loop carries Int,
but this 'break' gives it String`), and a loop that carries nothing --
`loop:`, or a plain `for`/`while` -- takes none.

**A loop is worth its accumulator**, so it stands wherever a value-form
`if`/`match` does -- bound with `=`, returned with `return`, or left as
a function's last statement:

```pyking
def doubled_over(limit) -> Int:
    loop n = 1:
        if n > limit:
            break
        else:
            n * 2


print(doubled_over(50))   # 64
```

**Several values are one tuple.** The accumulator is a single value, so
a loop carrying two things carries a pair: the header takes it apart on
every turn, and what the body ends in has to give the whole tuple back.

```pyking
foo, bar = loop x, y = 0, true:
    if x <= 10:
        (x + 1, y)
    else:
        break


print(foo, bar)         # 11 true
```

**`loop:` carries nothing.** Written with no accumulator its body may
end in anything -- there is no accumulator to say, so nothing is asked
of its last statement -- and the loop is worth `()`. The only way out
is `break`.

```pyking norun
loop:
    print("forever")
```

That program is perfectly valid and never finishes, which is the point:
nothing about a loop requires it to end.

**Where `break` and `continue` belong.** Each belongs to the innermost
`loop` it is written in, and may not reach out of a `for`, a `while` or
a `def` to find one -- both checked at compile time (see the notes on the
Grammar). `for` and `while` have no exit of their own, so a `break`
written inside one is an error rather than that loop's exit.

**Scope.** The accumulator is bound in the loop's own body and nowhere
else: it is gone after the loop, and a name it shadows means what it
meant again. Every turn binds it afresh, as a `for` variable is bound
afresh, so a `def` written inside a loop body keeps the turn it was
written on (see "Names and scoping").

```pyking
x = "outer"

shadowed = loop x = 1:
    if x > 2:
        break
    else:
        x + 1

print(shadowed, x)      # 3 outer
```

## One loop, three halves — Pyking extension

`for`, `while` and `loop` are the same construct with different halves
written: an **accumulator** and an **iteration clause**, either of which
may be left out. So they combine, and `break` and `continue` mean the
same thing in every combination.

```pyking
def total(xs:[Int]) -> Int:
    return loop acc = 0 for x in xs:
        acc + x


def countdown(from_:Int) -> Int:
    return loop i = from_ while i > 0:
        i - 1
```

A `for`/`while` is a loop, so a `break` in one belongs to *it* — there
is no crossing out of a loop any more. A `def` is the one thing a
`break` still may not reach out of.

**Going round.** A loop that carries an accumulator carries what its
body *ends in*: the body's last statement is the next turn's
accumulator, recursively through the branches of a trailing `if` or
`match`, exactly as tail position works everywhere else. A path that
`break`s, `continue`s or `return`s says nothing, since none of them
reaches the end of the body.

```pyking
def total(xs:[Int]) -> Int:
    return loop acc = 0 for x in xs:
        acc + x                 # the next turn's `acc`
```

A loop carrying nothing asks nothing of its body: there is no next
accumulator for it to give, so it may end in any type at all.

**Leaving a loop.** `break` ends the loop. Written bare, the loop is
worth the accumulator the turn it stopped on started with. `continue`
is the other way round -- it starts the next turn at once, with that
same accumulator unchanged.

Either may instead say what the accumulator is from then on: `break x`
ends the loop worth `x`, and `continue x` starts the next turn with
`x`, just as a body ending in `x` would. `x` is held to the
accumulator's type, as what the body ends in is. A loop that carries
nothing has no accumulator for a value to be, so there both are written
bare.

**What a loop is worth.** One rule:

> the accumulator it stopped with, if one is written; else `()`.

A `break x` stops it with `x`; a `continue x` on the last turn of a
`for`/`while` leaves it with `x` too, since that is what the next turn
would have started with.

However it stops -- on a `break`, or by a `for`/`while` running out of
turns -- the answer is the same, so a loop that can stop both ways
still has one value rather than two. A plain `loop:` that never breaks
never stops, and nothing ever asks.
