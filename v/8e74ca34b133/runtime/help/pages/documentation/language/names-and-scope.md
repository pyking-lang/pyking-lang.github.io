---
title: "Names, bindings and scope"
description: "Immutable bindings, block scope and shadowing."
sidebar:
  parent: Language reference
  position: 4
---

> **Available:** in every module · **Compared with Python:** differs --
> every block is a scope, and `=` makes a new binding, never an update

A name is bound by `=`, by a `def`, by a parameter, by a `for` loop or by
a pattern. Every block is a scope, so a name bound inside an `if` or a
loop body is gone after it, and every use of a name is checked at
compile time.

## Immutable bindings (`=`) and tuple destructuring

`name = expr` binds `name` to the value of `expr`. Per the Pyking design,
this is a binding, not a mutation — it is not meant to update an existing
variable in place (the bootstrap parser accepts the syntax as shown; there
is no evaluator yet to enforce the distinction at runtime).

```python
x = 1
x = x + 1
print(x)
```

The left-hand side of `=` may also *destructure* a tuple value into
several names at once, either with or without parentheses, and nesting
freely — this is the only place in Pyking where the two forms interact:
the right-hand side is parsed with `tuple_or_expr` (so it may itself be a
bare tuple), while the left-hand side is a `target`, always resolved
independently of what the right-hand side turns out to be (there is no
type checker to confirm the two shapes actually match — a mismatched
tuple arity is only caught when the program runs).

```python
a, b = 1, 2
(c, d) = (10, 20)
(e, (f, g)) = (1, (2, 3))
(h,) = (99,)

print(a, b, c, d, e, f, g, h)
```

## Names and scoping

Pyking is **lexically scoped**: every use of a name refers to the
innermost enclosing binding of that name, decided entirely by where the
code is written. A scope is a function body or any indented block — the
body of an `if`/`else` branch, a `for`, `while` or `loop` body, a `case`
arm, a value-form branch — plus a list comprehension and the file's top
level.
Names bound inside a scope are not visible outside it:

```pyking
total = 0

if 1 < 2:
    inner = total + 1
    print(inner)

# `inner` is not in scope here -- using it is a compile-time error.
```

**What binds a name.** An `=` binding, a `var` declaration, a `def` (its
own name, visible throughout the block it is written in — see "Bindings
are sequential — except `def`" below), a parameter, a `for` variable, a
`loop` accumulator, a pattern variable in a `case` arm or
comprehension. All of them behave
the same way with respect to *scope*; they differ only in when within
that scope the name becomes visible.

**Shadowing.** Any of those may reuse a name that is already in scope;
the inner binding wins until its scope ends, and the outer one is
untouched and visible again afterwards. Two `=` bindings of the same name
in one scope are the same thing — the second shadows the first, which is
why a binding may change what a name means (and even its type) without
ever being an update:

```pyking
n = "outer"


def describe(n):
    "param " + string(n)


print(describe(1), n)
```

**A `def`'s name is the exception to that.** Within one block, a
function name means exactly one thing: two `def`s of the same name are
an error, and so is any *other* binding of a name a `def` in that block
uses — in either order, and whatever the binding form:

```pyking
# Each of these is a compile-time error:
#   f = 1              def f(n): n * 2       (a binding and a function)
#   def f(n): n * 2    f = 1                 (the same, written the other way)
#   var f = 1          def f(n): n * 2       (a variable and a function)
#   def f(n): n        def f(n): n * 2       (two functions)
```

This is what makes the next rule safe. A function's name is visible
*throughout* its block, so if the name could also mean something else
there, a use of it would have two candidates and no reason to prefer
either — is `use()` below returning the number or the function?

```pyking error
f = 1

def apply(): f          # rejected: which `f`?

def f(n): n * 2
```

Nothing forbids the *name*; it forbids sharing a **block**. A nested
block may shadow a function freely, because there the answer is never in
doubt:

```pyking
f = 1


def apply():
    def f(): 5        # a different block: this shadows the binding
    return f()


print(apply())           # 5
```

**The other restriction:** a `var` may not be shadowed. While a mutable
variable is in scope, no binding of any kind may reuse its name — not an
`=` binding, parameter, `for` variable, pattern variable, `def`, or
another `var`:

```pyking
use mutation

var count = 0

# Each of these is a compile-time error while `count` is in scope:
#   count = 1                  (binding shadows the variable)
#   def f(count): ...          (parameter shadows it)
#   for count in range(3): ... (loop variable shadows it)
```

This is what makes `:=` unambiguous. `count := 1` updates the mutable
variable `count` denotes; if an inner scope could rebind that name to
something immutable, a reader would have to search every enclosing scope
to know whether a given `:=` updates the variable, is an error, or
reaches a *different* variable of the same name. With shadowing
forbidden, the answer is always the nearest `var` — and correspondingly
`:=` requires one: applying it to a binding, parameter, or pattern
variable is an error, not a silent conversion.

A `var` may itself shadow any *immutable* name, and two sibling scopes
may each declare their own `var` of one name, since neither is in scope
where the other is:

```pyking
use mutation

count = 100


def tally(items):
    var count = 0
    for item in items:
        count := count + item
    return count


print(tally([1, 2, 3]), count)
```

**Bindings are sequential — except `def`.** A scope's names come into
being in the order they are written, so a name must already be bound
where it is used:

```pyking
# total = later + 1     -- error: `later` is not bound yet
later = 41
total = later + 1
```

**Functions are the exception**: every `def` in a block is in scope
throughout that block, from its first line, not from the `def` onward.
That is what makes a function usable before it is written — its own
recursive calls, two functions that call each other, a helper defined at
the bottom of the file — and it is safe to do for a `def` and not for an
`=` binding, because a `def` says what its name means on the `def`
itself, while a binding's meaning is whatever its right-hand side works
out to.

```pyking
def is_even(n):
    if n == 0:
        true
    else:
        is_odd(n - 1)        # written below; in scope anyway


def is_odd(n):
    if n == 0:
        false
    else:
        is_even(n - 1)       # and its own name, so plain recursion too


print(is_even(10), is_odd(10))
```

It applies per block, so a `def` inside a function body — or inside one
branch of an `if` — is in scope for that body or that branch, and
nowhere else. Nested functions may be mutually recursive on exactly the
same terms.

**Only the *names* are visible ahead — not the values.** A function
body sees whatever is bound *where the body is written*. Rebinding a
name afterwards makes a new binding; it does not reach back into a
function that already captured the old one:

```pyking
x = 1


def show() -> Int:
    return x


x = "two"
print(x, show())        # two 1
```

`show` was written where `x` was `1`, so that is the `x` it returns —
even though the name means something else, of another type, by the time
`show` is called. This follows from `=` being a binding rather than an
assignment, and it is what lets the type checker say anything reliable
about a function at all.

The two rules meet like this: the *name* of a `def` written below is
already usable, but the *bindings* it captures are the ones above it:

```pyking
x = 1


def f():
    return g()          # `g` is written below -- fine, it is a function


x = 2


def g():
    return x            # the `x` visible here: the second binding


print(f(), g())         # 2 2
```

A `var` is the deliberate other half: `:=` updates the one binding
rather than making a new one, so a function reading a `var` sees the
updates. That is what a `var` is for.

```pyking
use mutation

var counter = 0


def read(): counter


counter := 42
print(read())           # 42
```

A loop binds afresh on every turn — its variable and everything in its
body — so a `def` written inside one keeps the turn it was written on,
not the last. Functions written in the same turn that call each other
find each other's copy from that turn, wherever in the body they are
written:

```pyking
fns =
loop made = [] for i in range(3):
    def show(): i
    made + [show]

for f in fns:
    print(f())          # 0, then 1, then 2
```

The design behind these rules, the alternatives, and how other languages
answer the same question are in
docs/defshadow.md.

Being *in scope* is not the same as having *run*, though. A function
value comes into being when its `def` is reached, so a call that
executes before that fails at run time, exactly as the same program
would in Python:

```pyking
def top(n):
    helper(n)          # fine: `top` is called below, after both defs


def helper(n):
    n + 1


print(top(1))

# print(later(1))     -- compiles, but fails at run time: `later` has
# def later(n):          not been reached yet
#     n
```

**Checking.** All of this is checked statically, before any code is
generated, and reported as a `Name error` against the offending source
position. A handful of names are predefined and count as bound
everywhere — `print`, `debug`, `range`, `string`, `len`, `int`, `float`
and `bool` — since no
Pyking program
declares them; every other unbound name is an error. They are host
*operations*, not values: each may be called, and using one as a value
(`f = print`) is an error. `range(n)` yields a list of `Int`, which is
what the language has — there is no lazy-sequence type — though
iterating one with `for` need not build it. `print` produces no
value: it yields unit, `()`, so it is meaningful as a statement and not
as something to bind or return. Unit prints as `()` — the same in every
backend, whatever the host language calls its own absence of a value.

**Compiling preserves this.** A backend whose own scoping is coarser than
Pyking's has to work to keep these rules; how each one does is a compiler
concern rather than a language one, described in
docs/targets.md.
