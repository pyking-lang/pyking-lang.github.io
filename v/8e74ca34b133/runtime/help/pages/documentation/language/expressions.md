---
title: "Operators and expressions"
description: "Operators, calls, evaluation order, if expressions, lambdas and let."
sidebar:
  parent: Language reference
  position: 3
---

> **Available:** in every module · **Compared with Python:** mostly the
> same; differs for `^` (power), non-chaining comparisons, `if … then …
> else` expressions and lambdas (`lam`)

An expression computes a value. Operands are evaluated left to right,
operators are overloaded over `Int` and `Float` but never mix them, and
three expression forms are Pyking's own: the `if … then … else`
expression, `lam` lambdas and `let … in`.

## Variables (identifier references)

An identifier is a name starting with a letter or underscore, followed by
any number of letters, digits, or underscores. Using a name in an
expression looks it up as a variable reference. A name a program binds
starts with a lowercase letter or an underscore: one starting with an
uppercase letter is a type or a constructor (see "Datatypes").

```python
x = 10
y = x
print(x, y)
```

## Arithmetic operators and parenthesized expressions

`+`, `-`, `*`, and `/` are left-associative binary operators with the usual
precedence (`*`/`/` bind tighter than `+`/`-`). Parentheses override the
default precedence.

**All four are overloaded over `Int` and `Float`**: each takes two
operands of one type and answers that same type. There is no third
possibility — an `Int` beside a `Float` is refused, not widened, and
`float(n)` and `int(x)` are what a program writes instead. See "Numbers,
and what the checker defaults to" under "Types and type inference".

On two Ints, `/` is **integer division, truncating toward zero**.
Truncation is toward zero rather than downward, so `-7 / 2` is `-3` and
not `-4`:

```pyking
print(7 / 2, (0 - 7) / 2)     # 3 -3
print(7 / (0 - 2))            # -3
print((0 - 7) / (0 - 2))      # 3
```

Dividing an Int by zero is left to whatever the target does with it, and
the targets differ — see `docs/targets.md`.

On two Floats, `/` is **IEEE division**: not truncated, and never a
failure. Dividing by zero answers an infinity or a NaN, the same way on
every target (see "Float literals" above).

```pyking
print(7.0 / 2.0)              # 3.5
print(-7.0 / 2.0)             # -3.5
print(1.0 / 0.0)              # inf
```

```python
a = 2 + 3 * 4
b = (2 + 3) * 4
c = 10 - 4 / 2
print(a, b, c)
```

A `-` written where an expression is expected is instead unary minus,
which negates what follows it, an `Int` or a `Float` alike. That covers
negative literals (`-5`, `-2.5`) and negation of anything else — a
variable, a call's result, a parenthesized expression — and it may be
repeated (`- -x`).

```python
x = 5
low = -12

print(-x, -low, - -5)
print(-(x + 1), -x + 1)
print(10 - -3, -x * 2)
```

It binds tighter than `*` and `/` and looser than a call, so `-x * y`
means `(-x) * y` and `-f(x)` negates the result of `f(x)` rather than
`f`. It reaches only over the operand it precedes, which is why `-x + 1`
is `(-x) + 1` and the parentheses in `-(x + 1)` are doing real work.
Since a binary `-` can only follow a completed expression and a unary
one can only start a new one, spacing never changes the reading: `10 - -3`
and `10 - - 3` are the same.

A `case` pattern may use a negative integer literal too — `case -1:` —
matching Python. That is a literal only: patterns are matched, not
evaluated, so `case -x:` is not a negation of anything.

**A Float is not a pattern.** `case 1.5:` is refused, because matching
on one means comparing a double for equality, and IEEE equality is not
the relation a reader of a `match` expects — a NaN matches no case, its
own spelling included. A program that wants that comparison writes `==`
and says so.

## Concatenation (`+`)

`+` joins two strings, or two lists, into one, as it adds two numbers.
It is left-associative and sits at the same precedence as `-`, so a
chain of them needs no parentheses and `*`/`/` still bind tighter.

```python
print("con" + "cat")
print("a" + "b" + "c" + "d")
print([1, 2] + [3, 4])
```

**Every operand of a `+` is of one type**: all numbers of one type, all
strings, or all lists of one element type. Which of the three a `+` is
the type checker decides from its operands, and nothing is converted on
the way -- unlike JavaScript, where `"n = " + 5` is `"n = 5"`, and like
Python, which raises:

```pyking error
print("n = " + 5)
# Type error: `+` cannot be applied to String and Int; it accepts Int +
#   Int or Float + Float or String + String or two lists of one type.
#   `+` joins two Strings and converts nothing: write string(n)
```

So `"2" + "3"` is `"23"` and `2 + 3` is `5`, and the two never meet in
one `+`. A chain is the same rule applied at each step, so `a + b + c`
is all strings or all lists or all numbers, never a mixture.

```python
print(2 + 3)        # 5
print("2" + "3")    # 23
print([1] + [] + [2, 3])
```

Where nothing has decided the operands' type yet -- two parameters with
no annotation, say -- a `+` waits for the use that decides it, as the
`++` Pyking used to have did: `def join(a, b): a + b` called with two
Strings joins them. One that nothing decides by the end of the module
adds two Ints, which is the arithmetic operators' default (see "Numbers,
and what the checker defaults to").

`++`, Pyking's old spelling of a join, is refused where it stands:

```
'prog.pyk' 1:10-1:12 Parsing error: '++' is now written '+': 'a + b'
  joins two strings or two lists
```

## Comparison operators

`<`, `<=`, `>`, `>=`, `==` and `!=` compare two expressions and produce
a single comparison expression. Comparisons do not chain: `1 < 2 < 3`
is refused, and the message says to write `1 < 2 and 2 < 3`.

```python
print(1 < 2, 2 <= 2, 3 > 4, 3 >= 3, 2 == 2, 2 != 3)
```

All six take two operands of one type, as the arithmetic operators do:
two `Int`s or two `Float`s, and `==` and `!=` additionally two
`String`s or two `Bool`s. On Floats the comparison is IEEE's, which is
where NaN's behaviour comes from (see "Float literals" above): `nan ==
nan` is false and `nan != nan` true.

```pyking
print(1.5 < 2.5, 1.5 == 1.5, "a" != "b")
```

**`==` and `!=` on compound values** compare them part by part: two
lists of the same elements in the same order, two tuples of equal
parts, two values of a struct or a datatype built by the same
constructor from equal fields. A Float inside compares by IEEE's rule
still, so `[nan] == [nan]` is false.

```pyking
struct Point(x: Int, y: Int)

datatype Shape:
    Circle(r: Float)
    Rect(w: Float, h: Float)

print([1, 2] == [1, 2], (1, "a") != (1, "b"), Point(1, 2) == Point(1, 2), Circle(1.0) == Rect(1.0, 1.0))
# true true true false
```

A value compared this way holds only what `==` compares: a function
has no equality, and an array, a DynArray, a MutMap and a `mutable struct` have
an identity instead, which `same(a, b)` asks about -- so `==` on a list
of functions or a tuple holding an array is refused, naming what it
holds. So is `==` on a type variable, `def f(x: a, y: a)`, which could
stand for a function. `<`, `<=`, `>` and `>=` stay the scalars'.

## Remainder and power

`%` is the remainder and `^` the power, both over `Int` and `Float`
with two operands of one type, as the other arithmetic operators are.

```pyking
print(7 % 3, -7 % 2, 7.5 % 2.0)     # 1 -1 1.5
print(2 ^ 10, 2 ^ 3 ^ 2, -2 ^ 2)    # 1024 512 -4
print(2.0 ^ 0.5)                     # 1.4142135623730951
```

- **`%` truncates toward zero**, as `/` does, so `a == (a / b) * b + a % b`
  for any two Ints and the remainder takes the sign of `a`: `-7 % 2` is
  `-1`, where Python's is `1`. `math.int::mod` is the remainder that is
  never negative. On two Floats `%` is IEEE's `fmod`. An Int `%` by zero
  is what `/` by zero is (see `docs/targets.md`).
- **`^` is the power**, as in mathematics -- Python's `**` is refused
  with a message saying so. It associates to the right, so `2 ^ 3 ^ 2`
  is `2 ^ 9`, and binds tighter than unary minus, so `-2 ^ 2` is
  `-(2 ^ 2)`, as `-2²` is. Its right operand may be negated:
  `2.0 ^ -1.0` is `0.5`. An Int raised to an Int is an Int, so the
  exponent is at least 0; a negative one is a runtime error in the
  interpreter and undefined elsewhere. A Float power is IEEE's `pow`.
- `%` binds as `*` and `/` do; `^` binds tighter than every other
  operator, and looser than a call.

## Boolean operators

`and`, `or` and `not` combine Bools, as in Python, and may also be
written `&&`, `||` and `!`, as in C, Java and JavaScript. The two
spellings are one operator: the same types, the same short-circuit.

```pyking
x = 5
done = false
if x > 0 and not done: print("words")
if x > 0 && !done: print("symbols")
print(true or false, false || true, not true, !false)
```

- **Short-circuit**: `a and b` evaluates `b` only when `a` is true, and
  `a or b` only when `a` is false, on every target.
- **No truthiness**: both operands are Bools. `if xs:` and `1 and 2` as
  a condition are refused rather than read as "not empty" or "not zero"
  -- there is no conversion to Bool but `bool(x)`.
- **Precedence**: both spellings of `or` bind looser than both of
  `and`, which bind looser than `not`, which binds looser than a
  comparison -- Python's order, so `x > 0 and not done` needs no
  parentheses. `!` is the exception: it binds as tightly as unary minus,
  as in C, so `!a == b` is `(!a) == b` while `not a == b` is
  `not (a == b)`.
- The spelling written is kept: `pyk compile -t pyking` prints a program
  back with `&&` where `&&` was written.

On two Ints the words `and`, `or` and `not` are the bitwise operators
instead (see "Bitwise operators"); the symbols `&&`, `||` and `!` are
Bool's alone, because in C and JavaScript `5 && 2` is `1` and `!5` is
`0`, and a different answer with no error would be a trap:

```
'prog.pyk' 1:6-1:12 Type error: `&&` cannot be applied to Int and Int;
  it accepts Bool && Bool. On Ints, write 'and' or '&'
```

## Bitwise operators

On two Ints, `&` is bitwise and, `|` bitwise or, `xor` exclusive or,
`~` bitwise not, and `<<` and `>>` shift left and right. The words
`and`, `or` and `not` are bitwise on Ints too, as they are logic on
Bools, and so is `xor`: on two Bools it is true where exactly one of
them is, as `!=` is.

```pyking
flags = 0b0101
print(flags & 0b0100, flags | 0b0010, flags xor 0b1111, ~flags)   # 4 7 10 -6
print(12 and 10, 12 or 10, not 0)                                  # 8 14 -1
print(1 << 4, 256 >> 2, -8 >> 1)                                   # 16 64 -4
print(true xor false, true xor true)                               # true false
```

- **Ints only, but for `xor`**: `&` and `|` on two Bools are refused
  with "On Bools, write 'and' (or '&&')". `xor` takes two Bools or two
  Ints. The words on Ints have no short-circuit: `0 and f()` still calls
  `f()`, and neither does `xor`, which needs both sides.
- **Precedence is Python's**: tighter than a comparison, so
  `flags & 4 == 4` is `(flags & 4) == 4`; among themselves `|` is
  loosest, then `xor`, then `&`, then the shifts, all looser than `+`.
  The words `and` and `or` keep their own, looser, level on Ints as
  well, so a mask test with them is parenthesized:
  `(flags and 4) == 4`.
- **`>>` keeps the sign** on every target: `-8 >> 1` is `-4`. `~n` is
  `-n - 1`.
- A shift by a negative count, or by 32 or more, is undefined, as Int
  overflow is (see "Integer and string literals"); every target agrees
  inside the signed 32-bit range.
- `^` is the power, not exclusive or as in Python and C: exclusive or is
  the word `xor`.

## Indexing

`xs[i]` is element `i` of the list `xs`, counting from 0. The index is
an `Int`, and an expression of any list type may be indexed -- a name,
a call's result, another index:

```pyking
xs = [10, 20, 30]
rows = [[1, 2], [3, 4]]
print(xs[0], xs[2], xs[len(xs) - 1], rows[1][0])   # 10 30 30 3
```

- An index binds as tightly as a call and a field, and the `[` is on
  the row the list ends on: a `[` starting the next line starts a list
  literal there, as a `(` there starts a new statement.
- A list is never changed: there is no `xs[i] := v`. An array's
  element is written that way (see "Arrays").
- An array is indexed the same way, and an index outside it is a
  runtime error on every target.
- An index outside the list -- negative included -- is a runtime error
  in the interpreter (`the index 5 is outside a list of 2 elements`) and
  whatever the host does with it in compiled code.
- A String is indexed too: `s[i]` is its character at position `i`,
  counting code points, and is a `Char` (see "Char literals"). An index
  outside the String is a runtime error in the interpreter (`the index 9
  is outside a String of 3 characters`).
- Only a list, an array and a String are indexed. A tuple is taken apart by a
  pattern or a `let`; the checker says so.

## Function calls

A call is a callee expression followed by `(`, a comma-separated list of
argument expressions, and `)`. Calls may be nested and may appear anywhere
an expression is expected.

```python
def add(a, b):
    return a + b


print(add(2, 3), add(add(1, 1), 5))
```

## Evaluation order

The pieces of an expression are evaluated **left to right**: an
operator's left operand before its right, a call's arguments in the
order they are written, and all of a call's arguments before the call
itself. The whole of the left operand runs before any of the right one
begins, so nesting does not change the rule.

This only matters when more than one piece has an effect — today, when
more than one of them *prints*.

```python
def step(label: String, value: Int) -> Int:
    print("step", label)
    value


sum = step("a", 1) + step("b", 2)
print("sum", sum)
```

```
step a
step b
sum 3
```

A condition is an expression like any other, so a `while` orders its
condition's pieces the same way on every turn. The branches of an
`if`/`then`/`else` expression are the exception that follows from what
`if` means rather than a special case: only the chosen branch runs at
all, and its own pieces then run left to right.

## `if`/`then`/`else` expressions

`if cond then e1 else e2` is an *expression*: it evaluates `cond`, then
yields `e1` or `e2`, whichever the condition selects — only the chosen
branch is evaluated. Python writes the same thing with the condition in
the middle, so (unlike most examples in this document) the following is
Pyking source, not valid Python; it compiles to Python's conditional
expression `e1 if cond else e2`.

Unlike the `if` *statement*, the `else` is mandatory — an expression must
always produce a value. The branches reach as far right as they can, so
parenthesize when mixing with operators, and an `else` branch that is
itself an if expression chains flat, reading like an `elif` ladder.

```pyking
def sign(x): if x < 0 then "negative" else if x == 0 then "zero" else "positive"


def clamp(x, lo, hi):
    y = if x < lo then lo else x
    return if y > hi then hi else y


print(sign(-5), sign(0), sign(7))
print(clamp(42, 1, 10))

# The `+ 1` belongs to the else branch; parenthesize to apply it to the
# whole expression instead.
print(if 1 < 2 then 100 else 200 + 1)
print((if 1 < 2 then 100 else 200) + 1)

# Parentheses are required around an if expression used as a
# comprehension filter (see the notes on the Grammar).
print([x for x in [1, 2, 3, 4] if (if x < 3 then true else false)])
```

## Lambdas — Pyking extension

`lam x. x + 1` is an expression that is a function, written as in the
lambda calculus (`λx. x + 1`): the keyword `lam`, the parameters, a `.`
and the body. One parameter with no type needs no parentheses, so
`lam x. x + 1` and `lam (x). x + 1` are the same thing; several need
them, and so does a parameter with a type -- `lam (n: Int). n - 1` --
since a type may hold a `.` of its own (`geo.Point`, `all a. a`), and in
parentheses it ends at the `)`. No parameters is `lam (). e`. The body
is **one expression** — there is no block form.

The body takes everything to its right that one expression can hold, so
a lambda binds looser than every operator and associates to the right:
`lam x. lam y. x + y` is curried. A comma ends it, since `lam x. a, b`
is a pair whose first element is the lambda.

`x => x + 1`, the spelling Pyking had before `lam`, is refused with
`a lambda is now written 'lam x. x + 1'`; `lam x, y. e` and
`lam x: Int. e` are refused too, each with the parenthesized form to
write.

```pyking
double = lam x. x * 2
add = lam (x, y). x + y
typed = lam (n: Int). n - 1
nothing = lam (). 7

print(double(21), add(3, 4), typed(10), nothing())

# A lambda answering with a lambda; a lambda associates to the right, so
# no parentheses are needed.
adder = lam x. lam y. x + y
print(adder(6)(7))

# An `if` expression is one expression, so it is a body like any other.
sign = lam n. if n < 0 then 0 - 1 else 1
print(sign(-5), sign(5))
```

A lambda captures what is bound where it is written, exactly as a `def`
body does, and a later binding of a name is a new binding rather than a
write to the old one — so what a lambda captured does not change under
it (see "Names and scoping").

```pyking
base = 100
shift = lam n. n + base
base = 200
print(shift(1))     # 101: the binding `shift` captured
```

**A lambda is monomorphic.** Its parameters are one type, settled
between its body and its uses, and never generalised; a `def` with the
same body is polymorphic and serves every type at once. That is
Hindley-Milner's own distinction between a `let`-bound definition and a
lambda-bound one, and it is the whole of the difference here:

```pyking
def named(x): x
print(named(1), named("a"))     # fine: `named` is polymorphic

id = lam x. x
print(id(1))
# print(id("a"))                -- error: `id` is Int -> Int by now
```

Two more rules follow from a lambda being an expression rather than a
definition. A lambda parameter may not have a default value, since a
default belongs to the scope a definition is written in. And a lambda
parameter is a binding like any other, so it may not shadow a `var`.

**A lambda argument is checked last.** In a call, every other argument
is checked first, and a lambda's parameters with no type written take
the ones its parameter has by then: in `apply(lam p. p.x, points)` the
list says `p` is a Point, although the lambda is written first. Only the
checking waits; the arguments still run in the order written (see
"Evaluation order").

## Let expressions — Pyking extension

`let target = value in body` is an expression: `value` is evaluated
once, bound to `target`, and the whole is worth `body`. The target is
what an `=` binding takes — a name, or a tuple taken apart — with an
optional annotation, checked as a binding's is. What it binds is seen by
the body and nowhere else, not even by `value`.

```pyking
foo = let x = 78 in x + 1
print(foo)                                  # 79

# One binding per `let`; a later one sees the earlier.
print(let a = 2 in let b = a * 3 in a + b)  # 8

pair = (1, (2, 3))
print(let (x, (y, z)) = pair in x + y * z)  # 7
print(let t: (Int, String) = (4, "four") in t)
```

Like a lambda, the body takes everything to its right that one
expression can hold, so parentheses end it: `1 + (let x = 10 in x) * 2`
is 21. A name a `let` binds starts with a lowercase letter, may not
shadow a `var`, and may not be bound twice in one target.
