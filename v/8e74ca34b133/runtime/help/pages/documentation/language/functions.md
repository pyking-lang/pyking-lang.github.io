---
title: "Functions"
description: "def, default and named arguments, annotations, return, tail position and tail calls."
sidebar:
  parent: Language reference
  position: 6
---

> **Available:** in every module · **Compared with Python:** mostly the
> same; a body's last statement is its value, and default and named
> arguments are checked at compile time

A function is defined with `def`. Annotations are optional: where they
are left out, the checker infers the most general type. A function body
answers the value of its last statement, so `return` is needed only to
leave early.

## Function definitions (`def`)

`def name(params):` introduces a function with a comma-separated parameter
list, followed by an indented block of statements as its body.

```python
def average(a, b):
    return (a + b) / 2


print(average(4, 8))
```

A body that is one expression may be written on the header's own line,
after the `:` (see "A block on its header's own line" in the Grammar). It is the
same body: one statement, in tail position, so it supplies the
function's value exactly as an indented one does. A body that does
anything else — returns, binds a name, branches as a statement — goes
under the header, where it is plain.

```pyking
def average(a, b): (a + b) / 2
def swap(a, b): b, a

print(average(4, 8))
print(swap(1, 2))
```

Annotations are unaffected — the `:` that opens the block is the one
that was always there:

```pyking
def average(a:Int, b:Int) -> Int: (a + b) / 2
```

When the body stops fitting beside the header, indent it under the
header instead. Nothing else changes:

```pyking
def scaled(a, b):
    (a + b) * 2


def sign(n: Int) -> String:
    if n < 0 then "negative" else "positive"


print(scaled(1, 2), sign(-3))
```

## Default parameters

A parameter may be given a **default**: an expression used when a call
leaves that argument out.

```pyking
def greet(who: String = "world", times: Int = 1) -> Int:
    print("hello, " + who)
    return times


print(greet())               # hello, world
print(greet("pyking"))       # hello, pyking
print(greet("a", 3))         # hello, a
```

Every parameter after the first one with a default has one too, so a
positional call is never ambiguous about which parameter it filled:

```pyking error
def f(a: Int = 1, b: Int) -> Int: a + b     # refused
```

A default is an ordinary expression, and it is evaluated **in the scope
the `def` is written in, at each call that omits the argument**. Both
halves matter. Rebinding a name after the definition does not change
what the default is worth:

```pyking
size = 10


def scaled(x: Int = size) -> Int:
    return x * 2


size = 20

print(scaled())              # 20 -- the first `size`, not the second
```

and a default that has an effect has it once per call that omits it,
not once when the `def` is reached:

```pyking
use mutation

var counter = 0


def tick(from_: Int = counter) -> Int:
    return from_ + 1


print(tick())                # 1
counter := 40
print(tick())                # 41
```

A default may name anything in scope where the definition stands,
including a function written further down — a `def` name is visible
throughout its block, so a default may call one:

```pyking
def padded(amount: Int = width()) -> Int:
    return amount + 1


def width() -> Int:
    return 7
```

**A default is not part of a function's type.** `greet` above has type
`(String, Int) -> Int`, exactly as it would without the defaults, and
nothing that holds the function as a value carries them:

```pyking norun
g = greet
print(g())                   # refused: `g` is a binding, not a definition
```

The same rule settles where the sugar is available at all: a call may
leave an argument out only where the callee is a `def` this module can
see the parameters of — written directly by name, or reached as
`module.name` through an imported Pyking module. A builtin has no
parameter names, and an external module's function is written in another
language, so neither takes one.

An **exported** function's defaulted parameter must carry a type
annotation:

```pyking error
public def greet(who: String = "world") -> String: "hi " + who
public def greet(who = "world") -> String: "hi " + who     # refused
```

An exported function carries its complete type in the source, and a
parameter's type is part of that whether or not it also has a default
(see "What a module may export").

A default may be written on a parameter of a nested `def`, in a loop
body, or anywhere else a definition may stand; what it captures is what
is bound where the definition is written, as any body is.

## Named arguments

An argument may be written `name = expr`, naming the parameter it fills:

```pyking
def box(width: Int = 1, height: Int = 2, depth: Int = 3) -> Int:
    return (width * 100) + (height * 10) + depth


print(box(height = 9))          # 193 -- width and depth default
print(box(4, depth = 6))        # 426
print(box(width = 4, depth = 6))
```

Three rules:

- **Every positional argument comes first.** A positional argument after
  a named one has no position left to mean.
- **Names may be written in any order.** `box(depth = 6, width = 4)`
  is `box(4, 2, 6)`. The arguments still run in the order they are
  written (see "Evaluation order"): the depth's before the width's.
- **A parameter is filled once.** Naming one that a positional argument
  already filled is refused, as is naming the same one twice.

A name may be given to a parameter that has no default — it is a way of
saying at the call site what an argument is for:

```pyking
def join(left: String, right: String) -> String: left + "-" + right

print(join("a", right = "c"))
```

but a name does not make a parameter optional: every parameter without a
default still has to be given something.

Named arguments are available exactly where defaults are — the callee
must be a `def` this module can see the parameters of, since neither is
part of a function's type.

An omitted argument is worth its default **in its own position**, so a
default with an effect has that effect between the supplied arguments
around it rather than before or after all of them -- where the names
are written in the parameters' order. Where they are not, every
argument written runs first, in the order written, and then the
defaults of the parameters left out, in the parameters' order:

```pyking
def note(label: String, n: Int) -> Int:
    print(label)
    n

def box(width: Int, height: Int = note("height", 1), depth: Int = 2) -> Int:
    width * 100 + height * 10 + depth

print(box(depth = note("depth", 6), width = note("width", 4)))
```

```
depth
width
height
416
```

## Type annotations

An immutable binding may be annotated on its name, `x: Int = 1`:

```pyking
count: Int = 42
name: String = "pyking"
total: Int = count + 1
```

Parameters and the return value may optionally be annotated with a type:
`Int`, `Float`, `String`, `Char`, `Bool`, a list type `[T]`, a tuple type `(T1, T2, ...)`
or `(T,)`, or a function type `(T1, T2, ...) -> T` (all nesting freely,
e.g. `[(Int, Bool)]` or `[(Int) -> Bool]`). `()`, the zero-element tuple
type, is the Unit type, and `(T)` with no comma is grouping rather than
a tuple. Annotations are entirely optional and independent per
parameter/return value — a function can mix annotated and unannotated
parameters freely.

```pyking
use mutation

def add(a:Int, b:Int) -> Int:
    return a + b


def sum_list(xs:[Int]) -> Int:
    var total = 0
    for x in xs:
        total := total + x
    return total


def scale(x, factor:Int) -> Int:
    return x * factor


print(add(2, 3))
print(sum_list([1, 2, 3, 4]))
print(scale(3, 4))
```

**Function types.** `(T1, T2, ...) -> T` is the type of a function, and
may be written wherever a type may. The parentheses are the parameter
*list*'s, not a tuple's, so the count of parameters is what they show: a
function of two parameters is `(Int, Bool) -> Int`, and one of a single
parameter that happens to be a pair is `((Int, Bool)) -> Int`. Without an
arrow after it, the same parenthesized list is an ordinary tuple type.
The result is a type in its turn, so `->` groups to the right and a
function returning a function needs no parentheses of its own.

```python
def inc(n:Int) -> Int:
    return n + 1


def apply(f:(Int) -> Int, x:Int) -> Int:
    return f(x)


# Returning a function: the return type is `(Int) -> Int`.
def stepper(up:Bool) -> (Int) -> Int:
    return inc


# Nested: a list of them, a pair holding one, one taken by another.
def each(fs:[(Int) -> Int], first:((Int) -> Int, Int)) -> Int:
    return apply(inc, 0)


def under(f:((Int) -> Int) -> Int) -> Int:
    return 0


step:(Int) -> Int = inc

print(apply(inc, 1), apply(step, 1), apply(stepper(true), 1))
```

Annotations are parsed and stored in the AST (see `Param`,
`SFunctionDef.return_type` and `SLet.type` in `src/syntax.ml`) and
pretty-printed back out in Pyking's own syntax. Compiling erases every
one of them: no generated code carries type syntax at all.

Nothing verifies an annotation in an ordinary compile. There *is* a type
checker, opt-in and covering only part of the language so far; what it
accepts, what it refuses, and which annotations it treats as declarations
rather than as decoration are in "Types and type inference". How the pass itself is built is a compiler matter, described
in docs/architecture.md.

## `return` statements

`return expr` evaluates `expr` and returns it as the function's result.

```python
def first(x, y):
    return x


print(first(1, 2))
```

## Tail position

A function body's **last statement is in tail position**, and whatever
value it produces is the function's result — there is no need to write
`return` for it. The rule is recursive, so it reaches through branches
rather than only the outermost statement:

| last statement | the function's value |
|---|---|
| an expression | that expression |
| an `if`/`else` | each branch's own tail, recursively |
| a `match` | each `case` arm's own tail, recursively |
| a `loop` | the accumulator it stopped with |
| an explicit `return` | what it returns |
| anything else (`for`, `while`, `=`, `var`, `:=`) | unit, `()` |

```pyking
def add(x, y):
    x + y


def pick(x, y, z):
    if z > 5:
        x + y
    else:
        2 * x


def name_of(n):
    match n:
        case 0: "zero"
        case _:
            "many"


print(add(1, 2), pick(2, 3, 9), name_of(0))
```

Because the rule recurses, an `if` nested inside a `match` nested inside
an `if` needs nothing special: every branch of every level is itself in
tail position. An `else if` ladder works for the same reason — a ladder
*is* a nested `if` in the else branch (see "`if`/`else` statements").

Only the **last** statement is in tail position. An `if` with something
after it is an ordinary statement run for its effect -- its branches
need not even agree on a type (see "Types and type inference") -- and the trailing
expression is the value:

```pyking
use mutation

def not_last(n):
    var acc = 0
    if n > 0:
        acc := 1
    else:
        acc := 2
    acc + 10


print(not_last(1))
```

A branch that produces no value simply does not return one, and the
function yields unit for that path — an `if` with no `else`, or a body
ending in a `for` or `while` that carries no accumulator:

```pyking
def only_then(n):
    if n > 0:
        "positive"


print(only_then(1), only_then(-1))
```

## `return` with an `if`/`match`

`return` also accepts a value-form `if`/`match` directly, so each
branch's tail expression becomes the returned value. This says
explicitly what tail position says implicitly — and, unlike the implicit
rule, it works *before* the end of a body:

```pyking
def sign(x):
    return if x < 0:
        "negative"
    else:
        "not negative"


def classify(n):
    return match n:
        case 0: "zero"
        case _: "many"


print(sign(-2), classify(0))
```

The same two rules a value-form binding obeys apply here: a `return if`
must have its `else`, and every branch must end in an expression — there
would otherwise be a path with nothing to return.

## Tail calls

A call in tail position is one nothing is waiting for: its answer is the
answer. So a function that calls *itself* in tail position is a loop
written as a recursion, and Pyking runs it as one -- the compiler
rewrites it into a `loop` carrying the parameters. A tail-recursive
function therefore runs in constant space on every target and in the
interpreter, however deep it goes:

```pyking
def climb(x):
    if x >= 20000:
        1000 + x
    else:
        climb(x + 1)       # a tail call: nothing waits for it


print(climb(0))            # 21000, in one frame
```

Functions that tail-call *each other* get the same treatment: the group
becomes one loop they share, as wide as its widest member. Nothing about
this changes what a program means -- only how much room it needs to
run -- and `pyk --no-tail-call-opt` turns it off, which is worth doing
only to read a program back as it was written.

The rewrite applies to programs the **type checker accepts**: what a
group can share, and what a slot one member has no argument for is
entered with, are questions about types. A program outside that fragment
(see "Types and type inference") is compiled as written and recurses as any other
language would. What counts as a tail call, what is left alone and why,
are in docs/optimization.md.

A call that is *not* in tail position is an ordinary recursion and stays
one: in `n * factorial(n - 1)` the multiplication is still waiting, so
there is nothing to turn into a loop.

## `if`/`match` statements as bound values

An `=` binding may take a block-form `if` or `match` on its right-hand
side instead of an expression. The construct stays a statement — it is
written and indented exactly as it would be on its own — but the branch
that runs supplies the bound value, which is its **last expression**.
Python has no statement that evaluates to a value, so the examples in
this section are Pyking source, not valid Python.

```pyking
y = 3
my = 2

x = if 7 > my:
    78 + y
else:
    tt = 5 + y
    tt + 8

print(x)
```

Only the *last* statement of a branch is its value; everything before it
is an ordinary statement run for its effect, as `tt = 5 + y` is above. A
branch may equally print, or update an enclosing `var` — nothing is
hidden inside a new scope, because the compiled Python is the very same
`if` statement with each branch's final expression assigned to `x`:

```python
if 7 > my:
    x = 78 + y
else:
    tt = 5 + y
    x = tt + 8
```

A bound `if` must have an `else` (there would otherwise be no value to
bind when no condition holds), including at the end of an `else if`
ladder. Every branch must end in an expression; the parser rejects both
mistakes rather than binding something undefined.

`match` works the same way, with either style of `case` arm — `-> expr`
gives the value directly, and a block arm gives its last expression:

```pyking
def describe(point):
    text = match point:
        case (0, 0): "origin"
        case (0, y):
            side = if y > 0 then "up" else "down"
            "on the y axis, " + side
        case (x, y): "at " + string(x) + "," + string(y)
    return text


print(describe((0, 0)), describe((0, 5)), describe((3, 4)))
```

The last statement of a branch may itself be a bound-value `if`/`match`
rather than a plain expression, in which case *its* branches supply the
value — this is also what lets an `else if` ladder be bound, a ladder
being a nested `if` statement in the `else` branch:

```pyking
n = 7

k = if n > 5:
    match n:
        case 7: "seven"
        case _: "big"
else if n > 0:
    "small"
else:
    "none"

print(k)
```

The value form belongs to `=` alone: `var name = ...` and `name := ...`
still take an ordinary expression (use `=` for the value form, or an
`if ... then ... else ...` expression). A tuple `target` destructures the
bound value exactly as it does in a plain binding.

Finally, the bound value may begin on the line *after* the `=`, indented
one level — which reads better when a `match` subject or `if` condition
would otherwise crowd the binding, and is the only way to keep a long
header off the `=` line. The indented block holds exactly one value:

```pyking
y = 2

z =
    match y:
        case 2: "hi"
        case xx: string(xx)

print(z)
```

This is just a layout choice, not a different construct: it applies to
any bound value (an ordinary expression, and `var`/`:=` too), and both
pretty-printers print it back on the `=` line, since the two spellings
produce the identical AST.

## Expression statements

Any expression, most commonly a function call, may be used directly as a
statement. Its value is discarded — *unless* the statement is in **tail
position**, where it becomes the enclosing function's return value (see
"Tail position").

```python
print("hello, pyking")
```
