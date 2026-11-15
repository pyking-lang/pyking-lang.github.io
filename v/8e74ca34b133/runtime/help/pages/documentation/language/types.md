---
title: "Types and type inference"
description: "The types, what the checker checks, type variables and inference."
sidebar:
  parent: Language reference
  position: 11
---

> **Available:** in every module · **Compared with Python:** differs --
> every program is type-checked before it runs


**Pyking is statically typed.** Every program is checked before anything
is printed, compiled or run — there is no flag for it and no way round
it — and a failure stops the compile. Static semantics come in three
kinds, reported under three labels:

- the shape rules the grammar cannot state: a value-form `if` must have
  its `else` and every branch must end in an expression (see the section
  on `if`/`match` statements as bound values), a `case` pattern may
  not bind the same name twice, and no name a program binds starts with
  an uppercase letter. These are reported as `Parsing error`.
- names and types, both settled by the checker: every name must be bound
  where it is used, and every value must have the type its use requires.
  An unbound name is a `Name error`; everything else below is a
  `Type error`.
- mutability, the one rule about a name that a type cannot state: `:=`
  may only name a `var`, and a `var` may not be shadowed (see "Names and
  scoping"). Also a `Name error`.

The checker covers a *fragment* of the language, and refuses everything
else rather than guessing:

```
'prog.pyk' 4:8-4:13 Type error: Construct is not supported
```

That is deliberate. A checker that quietly accepted what it had not
reasoned about would be worse than one that says where it stops — so
the list below is a floor that grows, not a description of what will
always be refused.

## Types

The checker works in the types "Type annotations" lists, and no others:
`Int`, `Float`, `String`, `Char`, `Bool`, list types `[T]`, tuple types
`(T1, T2, ...)`
— with `(T,)` the one-element one and `()`, the zero-element tuple, the
unit type — function types `(T1, T2, ...) -> T`, datatypes (`Shape`,
`Tree(Int)`; see "Datatypes"), and type *variables* (see "Type
variables" below). Two datatypes are one type when they are the same
declaration applied to the same types: two datatypes of one name in two
modules are two types.

There is no "one of these" type. A value is an `Int` or it is a
`String`; nothing says it may be either, and there is no narrowing that
would make such a thing usable. A function that has to serve several
types serves them the way `map` does — with a variable, which says the
*caller* chooses and the body does not care. Where the body does care
— `string(value)`, say, which asks what it was given — there is nothing to
write and nothing to infer, and the definition means the one type it
was first used at. Closing that gap needs something like type classes,
which Pyking does not have.

The function type is the one a program rarely writes but the checker
constantly infers, since it is what a `def`'s *name* means. So it is
what `pyk compile -t pyking` prints for a name bound to a function,
whether or not the source said so:

```pyking
def choose(a:Int, keep:Bool) -> Int:
    if keep:
        return a
    else:
        return 0


picker = choose      # picker: (Int, Bool) -> Int
```

Two types are the same type when they have the same structure; where
they were written, and whether one was written at all, does not enter
into it. So a parameter annotated `(Int) -> Int` accepts any function of
that shape, and rejects `(Int) -> Bool`.

## Numbers, and what the checker defaults to

`Int` and `Float` are two types and nothing converts between them on its
own. `+`, `-`, `*`, `/` and the five comparisons each take two operands
of **one** type, so one of each is refused where it is written:

```pyking error
print(1 + 1.0)
# Type error: `+` cannot be applied to Int and Float; it accepts
# Int + Int or Float + Float. Pyking mixes no numbers on its own:
# `float(n)` makes an Int a Float, and `int(x)` truncates a Float to an
# Int
```

Two builtins are what a program writes instead. `float(n)` widens an
`Int`; `int(x)` truncates a `Float` toward zero, the rounding `/`
already does on two Ints.

```pyking
total = 7
count = 2
print(total / count)                      # 3
print(float(total) / float(count))        # 3.5
```

Implicit widening is deliberately absent. It would mean `1 / 2` changed
meaning depending on what surrounded it, which is the thing about a
numeric tower that costs the most and is hardest to see.

**Where nothing has decided, an arithmetic operator means `Int`.** An
unannotated `def` whose parameters no literal and no call pins down is
an `Int` function:

```pyking
def add(a, b):
    return a + b          # add : (Int, Int) -> Int
```

That keeps every program written before Float existed compiling and
meaning what it did. A Float one says so — with an annotation, or with a
Float reaching the body:

```pyking
def fadd(a:Float, b:Float) -> Float:
    return a + b

def twice(x):
    return x * 2.0        # twice : (Float) -> Float
```

**The comparisons behave differently, and that is not an oversight.**
`<` answers `Bool` whichever type it compares, so it has nothing to
decide and leaves its operands open — exactly as `==` already did:

```pyking
def taller(a, b):
    return a > b          # settled by the first call, at either type
```

A `var` may hold a `Float`, as it may hold an `Int` or a `Bool`, which
is what a running total needs.

## What is checked

**Literals and names.** `1` is `Int`, `'s'` is `String`, `true` and
`false` are `Bool`. A name has the type of the binding it refers to,
under Pyking's ordinary lexical scoping.

**Operators.** Both operands must match the *same* signature:

| operator | accepts | gives |
|---|---|---|
| `+` | two `Int`s, two `Float`s, two `String`s, or two lists of one type | what the operands are |
| `-`, `*`, `/`, `%`, `^` | two `Int`s or two `Float`s | what the operands are |
| `-` (unary) | an `Int` or a `Float` | what the operand is |
| `<`, `<=`, `>`, `>=` | two `Int`s or two `Float`s | `Bool` |
| `==`, `!=` | two `Int`s, `Float`s, `String`s or `Bool`s | `Bool` |
| `and`, `or`, `xor` | two `Bool`s (logic), or two `Int`s (bitwise) | what the operands are |
| `not` | a `Bool`, or an `Int` | what the operand is |
| `&&`, `!` and or-or | `Bool`s | `Bool` |
| `&`, `<<`, `>>`, bitwise or | two `Int`s | `Int` |
| `~` | an `Int` | `Int` |
| `xs[i]` | a list `[a]`, an array, a DynArray, a view or a `String`, and an `Int` | the element (a `Char` for a `String`) |

(Bitwise or is `|` and the Bool or is `||`; a `|` cannot be written
inside a Markdown table cell.)

So `1 + 'a'` is an error -- `+` converts nothing -- and so is
`1 == 'a'`: a comparison of two different types is refused rather than
answered `false`. Where nothing has decided its operands, `and`, `or`
and `not` are Bool logic, `+` waits for a use to decide it and adds
two Ints if nothing does, and `xs[i]` leaves the kind of `xs` to the
first call and indexes a list if nothing decides it ("Functions without
annotations").

**Bindings and expression statements.** An `=` binding takes the type of
its right-hand side, and that is what its name means to the statements
that follow. An expression statement has its expression's type, which is
what lets a block yield a value.

A binding that *annotates* itself is checked against that annotation —
an annotation is a claim about the program, and where one is written it
is verified rather than replaced, which is the whole difference between
an annotation and a comment. Both forms of binding are checked, the
ordinary one and the value form:

```pyking
def foo(x:Int, y:Int) -> Int: x + y


ok:(Int, Int) -> Int = foo      # fine
# f:(Int, String) -> Int = foo  # error: foo is (Int, Int) -> Int
# n:String = 1 + 2              # error: the value is an Int
```

```
'prog.pyk' 3:2-3:22 Type error: this binding is annotated (Int,
  String) -> Int, but its value has type (Int, Int) -> Int
```

A binding with no annotation claims nothing and takes whatever its value
has; `-t pyking` then prints the type that was worked out, which is what
makes that output worth reading.

A `let` expression binds by the same rules: its value is checked where
the `let` is written, its annotation against that value, and its body
with the target bound. The `let` has its body's type. A name it binds
has one type, as a name an `=` binding binds does: binding a lambda
with `let` does not make it polymorphic.

**Blocks and `if`.** A block's type is its last statement's, and unit if
it is empty. Where that value is used, the two branches of an `if` must
have the *same* type — which is what makes `x = if ...` sound, since only
one branch runs but the binding has one type either way:

```pyking
flag = 3 < 4

best = if flag:      # both branches yield Int
    1
else:
    2

if flag:             # both branches yield unit
    a = 1
else:
    b = "two"
```

The **expression** form is checked the same way, and always yields a
value: its `else` is mandatory, so there is no way through it that
produces nothing, and its two branches must agree on a type just as a
statement's do. It is an expression like any other — an argument, an
operand, the right-hand side of a binding, or the whole body of a
function:

```pyking
def fact(n): if n <= 1 then 1 else fact(n - 1) * n


picked = if 3 < 4 then 10 else 20
print(fact(7), picked, "grade " + (if picked > 5 then "a" else "b"))
```

An `if` with no `else` supplies unit, whatever its one branch ends in:
there is a way through such a statement that runs no branch at all, so
there is no value it can be counted on for. A function that needed that
value is refused where the value was needed — at the function, not at
the `if`. A condition must be `Bool` — there is no truthiness.

**An `if` whose value nothing uses** need not have branches of one type.
Its value is used where it is bound (`x = if ...`, `return if ...`) and
where it is in tail position: the last statement of a function body, or
of a loop body that carries a value (see "Tail position"). Anywhere else
— with a statement after it, as the last statement of a loop that
carries nothing, or of the program — it is only run, and it supplies
unit. That reaches into its branches: an `if` ending a branch of such an
`if` is not used either. The arms of a `match` follow the same rule.

```pyking
def twice(n: Int) -> Int:
    n * 2


def first(n: Int) -> Int:
    if n > 0:
        twice(n)             # Int
    else:
        print("no")          # unit: fine, the `if` is only run
    n + 1


print(first(3))
```

Where the value is used, the branches are still held to one type, and
the error says why. Here the `if` is `pick`'s last statement, so it is
`pick`'s value:

```
def twice(n: Int) -> Int:
    n * 2
def pick(n: Int):
    if n > 0:
        twice(n)
    else:
        print("no")
```

```
'prog.pyk' 4:4-7:19 Type error: the branches of this 'if' have
  different types: Int and (). Its value is used -- it is bound, or it
  ends a function or a loop body that carries a value -- so its
  branches must give one type. With a statement after it, the 'if'
  would only be run, and its branches could differ
```

The REPL shows the value of every statement typed at its prompt, so
there an `if` on its own is used, and its branches must agree.

**Tuples.** `(e1, e2, ...)` has the tuple type of its elements, `()` is
unit, and a binding may take one apart -- `a, b = pair` binds each name
to its part, and is refused if the value is not a tuple of that many.

**Loops.** A loop has one type, and it is the accumulator's: its
initializer's, which an annotation on the header is checked against
exactly as a binding's is, and which what the body ends in must give.
The loop itself is worth that type, since a loop is worth the
accumulator it stopped with:

```pyking
counted = loop x = 1:      # carries Int
    if x > 3:
        break              # and is worth Int
    else:
        x + 1              # the next turn's accumulator
```

A body that ends in something else is refused, since a turn would hand
on a value the next one cannot take:

```
'prog.pyk' 12:4-12:12 Type error: this loop carries Int, but its body
  ends in ()
```

`break`, `continue` and `return` supply *nothing*, which is what lets a
branch that breaks sit beside one that ends in the next accumulator
without either being a special case: the branch that supplies a value
decides, exactly as it does in an `if` one of whose branches returns. A
body all of whose paths jump is asked for nothing at all. A `return`
written in a loop body leaves the *function*, so what it gives is one
of the function's answers like any other `return`.

A `break x` or `continue x` still supplies nothing where it stands, but
its value is held to the accumulator's type, exactly as what the body
ends in is -- it is the loop's value, or the next turn's accumulator:

```
'prog.pyk' 11:14-11:20 Type error: this loop carries Int, but this
  'break' gives it String
```

A `loop:` with no accumulator carries unit, is worth unit, and discards
whatever its body ends in -- so its body's last statement may be of any
type.

**Functions.** A `def` that is *fully* annotated — every parameter and
the return type — is checked where it is written. One that is not is
checked where it is *called*, and by exactly the same rules; see
"Functions without annotations" below. Either way, its type is the
function type above, and:

- every `return` must give the declared return type;
- the body must *produce* that type, either by returning on every path
  or by ending in a value of it — the two ways "Tail position"
  describes, and a body that does neither does not honour its own
  annotation;
- a call must give as many arguments as there are parameters, each of
  the parameter's type, and the call has the return type.

**Tail position is checked as the language defines it**: the body's last
statement supplies the function's value, recursively through branches,
with no `return` written. So this checks, and `scale` returns `Int`
because both branches of its one statement do:

```pyking
def scale(x:Int, factor:Int) -> Int:
    if x * factor == 4:
        8
    else:
        9
```

The two ways mix, because the checker asks every statement the same
question "Tail position" asks — *what value do you supply?* — and a
`return` answers with what it returns, which is exactly what that
section's table says of it. So a branch that returns and a
branch that ends in an expression are comparable, and one may return
while the other supplies the value:

```pyking
def size(n:Int) -> Int:
    if n > 0:
        return n
    else:
        0 - n
```

A body that ends in a value of the *wrong* type is an error, and so is
one that ends without producing anything at all:

```
'prog.pyk' 2:4-2:8 Type error: 'f' returns Int, but its body ends in a
  value of type String
'prog.pyk' 1:0-3:16 Type error: 'f' returns Int, so its body must
  return on every path, or end in an expression of that type
```

**A body is checked where it is written.** The checker reads a `def`'s
body in the environment at that `def`'s own position, which is what the
language says the body captures — so what it checks is what runs:

```pyking
x = 1

def show() -> Int:
    x

x = "two"          # fine: `show` was checked against the Int above
```

**Recursion and forward references check like anything else.** Every
`def` in a block is declared before any of the block is checked (see
"Names and scoping"), so a body has a type for its own name, for its
siblings', and for functions written below it — and a recursive or
mutually recursive call is then checked against that type like any other
call, argument by argument:

```pyking
def spell(n:Int) -> String:
    if n < 1:
        ""
    else:
        "x" + spell(n - 1)          # checked against (Int) -> String


def is_even(n:Int) -> Bool:
    if n == 0:
        true
    else:
        is_odd(n - 1)               # declared below, and known here


def is_odd(n:Int) -> Bool:
    if n == 0:
        false
    else:
        is_even(n - 1)
```

Nothing is taken on faith: the declared type is what the body is checked
*against*, and a body that does not honour it is refused. The same
applies to nested functions, per block.

Anything of function type may be called, not only a `def`'s own name, so
a parameter annotated with a function type is callable inside the body
and higher-order functions check like anything else:

```pyking
def inc(n:Int) -> Int:
    return n + 1


def twice(f:(Int) -> Int, x:Int) -> Int:
    return f(f(x))


answer = twice(inc, 5)      # answer: Int
```

Both body forms are checked the same way, and a function's parameters
are in scope only in its own body:

```pyking
def sign(n:Int) -> String:
    if n < 1:
        return "small"
    else if n == 1:
        return "one"
    else:
        return "large"


def shout(word:String) -> String: word + "!"


kind = sign(4)
loud = shout("hi")
```

## Type variables

An annotation may name a type it does not fix. A **type variable** is an
identifier beginning with a lowercase letter, and it stands for a type
the *caller* chooses:

```pyking
def id(x:a) -> a:
    return x


print(id(1))          # 1
print(id("two"))      # two
print(id(true))       # true
```

Every variable a written type leaves free is **quantified at its
outermost level**, so `(a) -> a` and `all a. (a) -> a` are the same
type. The quantifier may be written out, and one `all` may bind several
variables at once, but it is never needed at the top and is never
printed there:

```pyking
def pick(x:a, y:b) -> (a, a, b):     # all a b. (a, b) -> (a, a, b)
    return (x, x, y)
```

**A variable written twice is one type.** `(a, a) -> a` takes two
arguments of the same type, whichever the caller picks; two different
ones are refused. And a variable is **rigid inside the body that
declares it** — the body knows nothing about `a` beyond its being some
type, so `x + 1` on an `a` is an error where it is written rather than
at whichever call turned out to be wrong.

**Inside that body, an annotation's `a` is the definition's `a`.** A
binding annotated with one of the type variables the enclosing
definition's own types hold means that one, not a new one: in `def
f(xs: [a]) -> [a]`, `out: DynArray(a) = dynarray()` is a DynArray of
whatever `xs` holds. This is how `-t pyking` writes the types it worked
out back into a generic body.

**A type may be written on a line of its own.** `def name : type` gives
the type of the `def name(...)` in the same block; the two need not be
adjacent, and the definition then writes no annotations of its own,
since a `def` says its type in one place or the other:

```pyking
def compose : ((b) -> c, (a) -> b, a) -> c

def compose(g, f, x):
    return g(f(x))
```

**A `def` with no body is a signature too**, with its parameters named:
`def scale(n: Int, factor: Int) -> Int`, on a line of its own, says what
`def scale : (Int, Int) -> Int` says. Every parameter has a type and none
has a default, and the result type is written, since the line declares a
function rather than defining one:

```pyking
def scale(n: Int, factor: Int) -> Int

def scale(n, factor):
    return n * factor

print(scale(6, 7))
```

**A single parameter needs no parentheses**: `x -> x` and `(x) -> x` are
one type — the `->` after the `)` is what makes the parenthesized list a
parameter list. With no arrow after it, one type in parentheses is
*grouping*, `(x)` being `x`, as the notes on the Grammar say; a
one-element tuple is `(x,)`, written with the comma the value `(1,)` is
written with.

**An `all` written inside a type stays there**, which is first-class
polymorphism: a parameter can demand a function that is itself
polymorphic, rather than one at whatever single type the caller picked.

```pyking
def both_ways : (all x. (x) -> x) -> String
def both_ways(f):
    return f("a") + string(f(1))       # f used at two types, in one body
```

Without the inner `all` the variable would be bound at the top, and `f`
would be a function at one type for the whole body.

**A polymorphic value fits wherever one of its instances does.** Every
instance of `all a. (a) -> a` exists, so it is a `(Int) -> Int` where
one is asked for. The inner `all` above is the stronger demand, and only
a value that really is polymorphic meets that one:

```pyking
def apply(f:(Int) -> Int, x:Int) -> Int:
    return f(x)


def id(x:a) -> a:
    return x


print(apply(id, 3))                  # 3
```

Type variables are **written and also inferred**. A `def` with no
annotations gets one wherever its body never asks what a parameter is
(see "Functions without annotations"), so the two halves of this
section describe one kind of type reached two ways — and the inferred
half is checked against the body exactly as a written one is.

## Lists and `match`, checked

A list literal's elements agree on one type, the way an `if`'s branches
do and for the same reason: they are all elements of the same list. The
empty list is the exception that proves it — with nothing to disagree,
`[]` is `[a]` for a type variable nothing has constrained, and since a
Pyking list is immutable it fits wherever a list of anything is
wanted:

```pyking
def count(xs:[Int]) -> Int:
    return len(xs)


print(count([]), count([1, 2]))     # 0 2
```

A **pattern is checked against the type of what it matches**, and what
it answers is the names it binds: `case [x, ..rest]` over a `[Int]`
gives `x : Int` and `rest : [Int]`. A pattern that could never match —
a String pattern over an Int — is refused where it is written.

The **arms of a `match` agree on one type** where its value is used,
again the `if` rule — one with a statement after it is only run. Where
the arms disagree only in how general they are, the more general one
wins, which is what lets a base case return `[]`:

```pyking
def reverse(xs:[Int]) -> [Int]:
    match xs:
        case []:
            return []                    # [a], and so [Int] here
        case [x, ..rest]:
            return reverse(rest) + [x]
```

A constructor pattern is checked the same way: it demands that the
subject be its datatype, at parameters it leaves to be settled, and each
field's pattern is checked against that field's type. A guard is
checked in the environment its pattern binds, and must be a `Bool`.

A field written with no type has its default's type, worked out from
the default alone, where it is written: the field's uses agree with it
or are refused, and a default whose type is still open -- `[]`, or a
call answering a type variable -- is refused with a request to write the
type. An update `C(f = e, ..base)` is checked as `C(f = e, g = base.g,
...)`: `base` must have every field it fills, which is to say be a value
of `C`'s datatype.

## Exhaustiveness

**Every `match` matches every value of its subject's type**, whether
its value is taken or it is a statement. A `match` some value would
reach no case of is refused, and the refusal names such a value, as the
pattern that would match it:

```pyking error
datatype Shape:
    Circle(Float)
    Square(Float)
    Triangle(Float, Float, Float)


def area(s: Shape) -> Float:
    match s:
        case Circle(r): 3.0 * r * r
        case Square(a): a * a
```

```
'prog.pyk' 9:4-11:29 Type error: this 'match' does not match every
  value: no case matches Triangle(_, _, _). Add a case for it, or a
  'case _'
```

A `match` with nothing to do for most values says so with `case _: ()`.

What counts as covered is decided by the patterns and the type, exactly,
whatever they nest: a datatype's every constructor, both of a `Bool`'s
values, every length of a list (`[]` and `[x, ..rest]` between them take
them all), and a tuple position by position, so `(true, true)`,
`(true, false)` and `(false, _)` cover a `(Bool, Bool)`. An `Int` or a
`String` has too many values to name, so only a case that takes any of
them -- `_`, a name, or a `+` split with a name for all of the string
-- covers one.

**A case with a guard does not count towards covering**, since its
guard may be false:

```pyking error
def sign(n: Int) -> String:
    match n:
        case m if m > 0: "positive"
        case m if m <= 0: "not positive"
```

**Every case is reachable.** A case whose every value is taken by the
unguarded cases above it is refused rather than left as code that never
runs:

```pyking error
datatype Color:
    Red
    Blue


def name(c: Color) -> String:
    match c:
        case Red: "red"
        case _: "another"
        case Blue: "blue"
```

The two rules are one question asked twice -- is there a value this
pattern matches and no case above it does? -- which is how the refusal
can name the value it found.

A comprehension's `for` walks a list and its pattern binds over the
elements; an element the pattern does not match is left out rather than
being an error, matching what the construct already means.

## Functions without annotations

A `def` that did not write its type down is not checked where it is
written. It is worked out the first time something **uses** it —
calling it, or reading its name as a value — but not *from* that use. Its parameters start as types nothing has decided,
and what the **body** does with them is what decides them:

```pyking
def double(n):
    n * 2                    # nothing is checked here ...


doubled = double(21)         # ... here: `*` says n is Int, so double
                             # is (Int) -> Int
```

What comes out is the **principal type**: the most general type the body
has, from which every type it can be used at follows. So a definition is
worth the same whatever calls it and in whatever order:

```pyking
def apply(f, x):
    f(x)                     # apply : ((a) -> b, a) -> b, always
```

Three rules follow, and they are the whole of what a program has to
know:

**An annotation that *is* written is still a claim.** A half-annotated
`def` is checked against what it did say, at every call, exactly as a
fully annotated one is. Only what it left out comes from the call:

```pyking
def scale(n:Int, factor):    # `n` is a claim; `factor` is a question
    n * factor


print(scale(6, 7))
# print(scale("six", 7))     # error: argument 1 has type String, but
                             #        Int was expected
```

**A body is still checked where it is written.** The call says *when*
the body is checked; it does not say what is in scope while it is. A
body that names something bound *after* the `def` is an error, however
late the call comes:

```pyking error
def f(n):
    n + offset               # error: unbound name 'offset'


offset = 10
print(f(1))
```

**A definition is worked out once**, at its first use, and every later
one uses what came out. A parameter the body never asks about becomes a
**type variable**, which is what lets one definition serve every later
call, at a different type each time:

```pyking
def echo(x):
    x


number = echo(1)             # number : Int
word = echo("two")           # word   : String
same = echo                  # same : (a) -> a
```

A parameter the body asks a question no *one* type answers is the
exception. `string` accepts an Int, a Float, a String, a Bool, a list
and a tuple, and Pyking has no way to say "any of those" — so such a parameter cannot become a variable
and is fixed instead to what the first call passed:

```pyking
def announce(value):
    "got " + string(value)     # `string` asks what it was given


print(announce(1))           # announce : (Int) -> String
# print(announce(true))      # error: argument 1 has type Bool, but Int
                             #        was expected
```

That is a real limit rather than an oversight, and a written annotation
would not help either, because there is none to write.

**A parameter that is indexed takes its kind from the first call.**
`xs[i]`, `xs[i] := v`, `xs[i:j]`, `for x in xs` and a comprehension over
`xs` work on several kinds of store -- a list, an array, a DynArray, a
view and a String -- so a body that only does those leaves the *kind*
open, and the first call settles it. The *element* type is not fixed:
it is generalised as any other type is, so one definition serves lists
of Ints and lists of Strings once its first call has said "a list":

```pyking
use mutation

def vec_add(v1, v2):
    res = array(len(v1), 0)
    for i in range(len(v1)):
        res[i] := v1[i] + v2[i]
    return res


def first(xs):
    xs[0]


print(vec_add(array([2, 5]), array([3, 4])))    # array([5, 9])
print(first([1, 2]), first(["a", "b"]))         # 1 a
# print(first(array([1])))   # error: argument 1 has type Array(Int), but
                             #   [a] was expected: first's parameter xs was
                             #   fixed to a list by its first call, at line 15
```

A body narrows what its first call may pass: one that writes `xs[i]`
allows an array, a DynArray or a view, and one that slices `xs` allows
anything but a view (whose slice is an array). Until a call decides
it, such a parameter shows as `Indexed(a)`; one nothing ever decides --
a definition never called, or only handed on -- is a list, or an array
where the body writes it.

**A parameter is not generalised.** A parameter used at *two* types
inside one body would have to be polymorphic itself, and inference does
not invent that — a `def` gets a type variable, a parameter gets a type:

```pyking
def apply(f):
    print(f(1), f(true))     # error: argument 1 has type Bool, but Int
                             #        was expected
```

Writing the type down is how that program is expressed, and the checker
then enforces it (see "Type variables" above for the `all`):

```pyking
def apply : (all a. (a) -> a) -> ()
def apply(f):
    print(f(1), f(true))     # fine: `f` is polymorphic because it says so
```

That line is deliberate. Inferring such a type is undecidable in
general, and guessing at it made the checker's answers depend on the
order a program's calls were written in. Inference has one guarantee —
the principal type, always — and first-class polymorphism is written
rather than guessed.

**Handing over a polymorphic function does not narrow what receives
it.** What a body asks of a parameter is what that parameter is worth,
and being passed something more general than it asked for changes
nothing about the body:

```pyking
def id(x): x


def apply(f, x):             # apply : ((a) -> b, a) -> b
    f(x)


def bump(n): n + 1


print(apply(id, "hi"))       # hi
print(apply(bump, 1))        # 2
```

The same definition serves both calls, and it would serve them in either
order: what `apply` is worth does not depend on which caller reached it
first.

The inferred signature is not taken on trust. The body is checked
against it a second time with the variables rigid — the same check an
annotated polymorphic function gets — so what is reported is always
something the checker enforces.

**Recursion is not a special case.** While a body is checked, its own
name means a plain type rather than a variable one, so a recursive call
is an ordinary call and its result is one more thing the body decides:

```pyking
def fact(n):                 # (Int) -> Int
    if n < 1:
        1
    else:
        n * fact(n - 1)


def forever(n):              # (Int) -> Int: `+ 1` says what the
    forever(n + 1) + 1       # recursive call gave back
```

Functions that name **each other** are worked out together and get their
type variables together, so `even` and `odd` below are one question with
one answer. A function they merely call is worked out first, and is
polymorphic by the time they use it.

```pyking
def even(n):
    if n == 0 then true else odd(n - 1)


def odd(n):
    if n == 0 then false else even(n - 1)
```

**Two functions of unknown type are indistinguishable**, so an `if` that
yields one of them is refused: nothing could say which of the two a
later call would be checking. Annotating either one settles it.

Which functions ended up with which types is what
`pyk compile -t pyking` prints, and is the best way to see what
was worked out — the reasoning behind all of this is in
docs/type_inference.md.

## Names, and what is not checked

**Names are the checker's too.** Its environment *is* the scope, so it
applies the rules under "Names and scoping" — a name must be bound where
it is used, a block's bindings do not escape it, a name is visible only
after its own binding *unless it is a `def`*, an inner binding shadows an
outer one, a `def` may not share its name with another binding of its
block, and the builtins are in scope throughout. An unbound name is
reported as a name error rather than a type error, since that is what it
is:

```
'prog.pyk' 14:16-14:23 Name error: unbound name 'missing'
```

**Did you mean.** Where a name that is not in scope is close to one
that is, or to a keyword, the message names it: `unbound name 'nmae':
did you mean 'name'?`, `unbound name 'braek': did you mean the keyword
'break'?`, and for an uppercase name, which is read as a constructor,
`unknown constructor 'True': ... Did you mean the keyword 'true'?`.
Close means a few single-character edits -- one inserted, removed or
changed, or two neighbours swapped -- none in a one-letter name, one in
a name of up to three letters, and two or more the longer it is.

Three mistakes that would otherwise be reported as something else are
named for what they are:

- **A misspelled keyword before an expression.** `returns x` is a name
  followed by a second statement on the same line, so it breaks the
  one-statement-per-line rule; the message says `'returns' is not a
  keyword: did you mean 'return'?`. A lone name that is no keyword's
  misspelling is told how a call is written instead: `prnt "hi"` gets
  `Did you mean 'print'? To call it, write print("hi")`.
- **`=` in a condition.** `if i = 5:`, `while i = 5:` and `else if i =
  5:` get `did you mean '=='? A single '=' binds a name; '==' compares
  two values`.
- **A loop body that ends in an `if` with no `else`.** The body of a
  loop carrying a value must give the next turn that value on every
  path; an `if` with no `else` at its end has a path that does not, and
  the message points at that `if`: `this loop carries Float, but its
  body can reach its end without a 'continue' or a 'break': this 'if'
  has no 'else', so when its condition is false nothing says what the
  loop does next`.

**Mutability is not a type.** A `var` may hold any type, and the checker
says only that each `:=` gives the type its declaration fixed; *which* names may be written to is a separate question, and
one a type cannot answer — the same `Int` is a `var` in one scope and an
`=` binding in another. So a pass of its own applies the two rules under
"Mutable variables": `:=` may only name a `var`, and nothing may shadow
one. Both are `Name error`s.

A name may be in scope and still have no type the checker knows — a
builtin, or a function's own name inside its own body. Using one is
refused as `Construct is not supported` rather than as an unbound name,
since the name is perfectly well bound; it is the *type* that is
missing.
