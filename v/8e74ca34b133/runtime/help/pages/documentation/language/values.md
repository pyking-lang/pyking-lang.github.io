---
title: "Values and basic types"
description: "Int, Float, String, Char, Bool and unit: their literals and what they mean."
sidebar:
  parent: Language reference
  position: 2
---

> **Available:** in every module · **Compared with Python:** differs --
> `true`/`false` are lowercase, `'a'` is a `Char`, and nothing converts
> implicitly

Pyking has five basic types: `Int`, `Float`, `String`, `Char` and
`Bool`, and the unit value `()`, which is what a statement that answers
nothing answers. Values of one type become another only through the
conversions `int`, `float`, `string`, `bool` and `char` (see "Builtins
and I/O").

## Integer and string literals

Integers are sequences of digits, or hexadecimal or binary ones: `0x`
or `0X` before hexadecimal digits (either case), `0b` or `0B` before
binary ones. In those two, `_` may stand between two digits to make a
long number readable, and means nothing: `0b0001_0101` is `0b00010101`
is 21. It may not come first, last, twice in a row, or right after the
`0x` or `0b`. Each is an ordinary `Int`.

```pyking
orange = 0xff8800
print(orange, 0b0001_0101, 0x7fff_ffff)
```

Strings are delimited by double quotes, and support backslash escapes:
`\n`, `\t`, `\r`, `\0`, `\\`, `\'`, `\"` (so a string can contain
a double quote, once escaped) and `\$` (a dollar sign that does not
start an interpolation: see "String interpolation" below). Single
quotes write a `Char` instead, one character: see "Char literals"
below. A String is counted in
characters -- Unicode code points -- so `len("åäö")` is 3 and
`len("👑")` is 1 on every target.

An `Int` holds **at least the signed 32-bit range**, −2 147 483 648 to
2 147 483 647. Every implementation carries that much; several carry
more, and none is made to pretend otherwise.

**Past that range the result is undefined.** `2147483647 + 1` may be
2 147 483 648, or −2 147 483 648, or anything else the host arrives at —
the language does not say, and two implementations may answer
differently without either being wrong. There is no overflow error to
handle, and nothing is inserted into generated code to force one answer:
what a target computes is what its own arithmetic computes.

A program that stays inside the 32-bit range therefore means the same
thing everywhere, and that is the range to write programs for. One that
leaves it is relying on a width the language does not promise.

**What a program may write down stops at 32 bits, whatever the host.** A
literal outside the range is a lexical error on every target, so the
front end refuses the same programs wherever it runs:

```pyking error
biggest = 2147483647      # fine
too_big = 2147483648      # Lexing error: integer literal is too large
also = 0x8000_0000        # Lexing error, as is the same number in binary
```

The lower end is one short of the range for a reason worth knowing: a
negative literal is unary minus applied to a positive one, so
`-2147483648` asks for the literal `2147483648`, which is refused.
Write `-2147483647` — or, if the exact value is needed,
`-2147483647 - 1`, which computes it without writing it.

`docs/targets.md` shows what each target does past the range, and why
nothing is inserted to hide the difference.

```python
count = 42
message = "hello, pyking"
quoted = "it's a test with a \"quoted\" word\nand a second line"
print(count, message)
print(quoted)
```

## String interpolation

A String may hold values to show inside it. `${e}` holds any expression,
and `$name` a name -- the name ends at the first character that cannot
be part of one, so `"$a,$b"` is `a`, then `","`, then `b`. Each is shown
the way `print` shows it.

```pyking
name = "Ada"
a = 1
b = 2.5
print("Hello, ${name}! ${a + 1} is more than $a.")
print("List{$a,$b}")
print("${[1, 2]} and ${(a, "one")} and ${a, b}")
```

`${a, b}` holds the tuple `(a, b)`, as `${(a, b)}` does. An
interpolation is not a new kind of value: the parser rewrites it, before
anything is checked, into the `+` and `string(...)` it stands for, so
`"List{$a,$b}"` is `"List{" + string(a) + "," + string(b) + "}"`, and a
program compiled to Pyking (`-t pyking`) has no `$` left in its
Strings. What `string` refuses an interpolation refuses too -- a
function, say -- and an error in the expression is an error at its place
in the String:

```pyking error
def f(x: Int) -> Int:
    x + 1

print("f is ${f}")    # Type error: an interpolation cannot show (Int) -> Int
```

A `$` that is followed by neither `{` nor a letter or `_` is a dollar
sign, so `"$5"` needs no escape; `\$` writes one anywhere, and `$` before
a keyword (`"$if"`) is refused. An interpolation shows its value with the
builtin `string`, so a program that defines a `string` of its own cannot
interpolate where that definition is in scope. A pattern is matched and
never evaluated, so a String in a pattern cannot interpolate.

A **raw String**, `r"..."`, is every character between its quotes as
written: no escapes and no interpolation. It cannot hold a `"`.

```pyking
print(r"C:\new\table has ${no} $interpolation")
print("costs \$5, or $5")
```

## Float literals

A `Float` is **IEEE 754 binary64**, double precision, and it means
exactly that on every implementation. Unlike an `Int`, whose width the
language leaves open past 32 bits, a Float is the same 64 bits
everywhere, so a Float program means one thing wherever it runs.

A literal is a digit run with a point that has **digits on both sides**,
an exponent, or both:

```pyking
half = 0.5
one = 1.0
billion = 1e9
tiny = 1.5e-3
huge = 2E+10
```

Neither `1.` nor `.5` is a literal — a point needs a digit after it,
which is what keeps `1.` and a name written after a value unambiguous.
Write `1.0` and `0.5`.

There is no bound on the magnitude the way there is on an integer
literal. A literal past what a double holds is an **infinity**, which is
IEEE's own answer and the same on every host:

```pyking
print(1e400)              # inf
```

**The infinities and NaN are ordinary values.** Division never fails:

```pyking
zero = 0.0
print(1.0 / zero)         # inf
print(-1.0 / zero)        # -inf
print(zero / zero)        # nan
```

NaN brings IEEE's one surprise with it, and Pyking does not hide it:
**a NaN is equal to nothing, itself included**, and every ordering
against one is false.

```pyking
nan = 0.0 / 0.0
print(nan == nan)         # false
print(nan < 1.0)          # false
print(nan >= 1.0)         # false
```

The two zeros are different values that compare equal, and print
differently:

```pyking
print(0.0)                # 0.0
print(-0.0)               # -0.0
print(0.0 == -0.0)        # true
```

**How a Float is written** is part of the language, since one program
prints the same characters wherever it runs: the shortest decimal that
reads back as the same double, always with a point or an exponent, so a
Float is always visibly one.

```pyking
print(1.0)                # 1.0, not 1
print(0.1)                # 0.1, not the exact binary value
print(100.0)              # 100.0, not 1e2
print(1e16)               # 1e16
print(1.0 / 3.0)          # 0.3333333333333333
```

## Boolean literals

`true` and `false` are literals for the two `Bool` values — Pyking
extension, with no Python equivalent, so (unlike every other example in
this section so far) the following is Pyking source, not valid Python:
Python spells the same two values `True`/`False`, capitalised, which
Pyking has no binding for at all (see the notes on the Grammar). They are
ordinary values, usable anywhere an expression is: bound with `=`,
declared with `var` and updated with `:=`, passed as arguments, returned,
compared with `==`, and so on.

```pyking
use mutation

done = false
var flag = true

flag := false

print(done, flag)
```

A boolean literal and a comparison that happens to agree with it are
completely interchangeable — `true` is not a different kind of value from
what `1 == 1` produces, just a shorter way to write the same one:

```pyking
print(true == (1 == 1), false == (2 == 3))
```

`true`/`false` may also appear as a `match`/`case` pattern, matching only
that exact value — see ["`match`/`case` pattern
matching"](/documentation/language/datatypes/#matchcase-pattern-matching) below.

## Char literals

A `Char` is one character -- one Unicode code point -- written between
single quotes: `'a'`, `'å'`, `'👑'`, or one of the escapes a String has,
`'\n'`, `'\t'`, `'\r'`, `'\0'`, `'\\'`, `'\''` and `'\"'`. `''` and
`'ab'` are lexical errors, and the second says that a String is written
in double quotes. A String's characters are Chars: `s[i]` is the one at
position `i`, `for c in s` walks them, and `text.chars(s)` lists them.

```pyking
word = "Håll 👑"
first = word[0]                     # 'H', a Char
print(first, word[5], len(word))    # H 👑 6
print(int('A'), char(66), 'a' < 'b', string('é') + "!")   # 65 B true é!
print([c for c in "ok"], ("ab", 'c'))   # ['o', 'k'] ("ab", 'c')
```

- **Comparisons** `==`, `!=`, `<`, `<=`, `>` and `>=` compare two Chars by
  code point; a Char is compared with nothing else.
- **Conversions**: `string(c)` is the one-character String, `int(c)` and
  `float(c)` its code point, and `bool(c)` is false for `'\0'` alone.
  `char(x)` goes the other way: from an Int code point, from a String
  (its first character), or from a Char; where there is none -- a
  negative Int, a surrogate, past 1114111, an empty String -- it is
  `'\0'` (see "Conversions").
- **No joining**: `+` joins two Strings, and a Char is not one, so
  `"a" + c` is a type error that says to write `"a" + string(c)`.
- **Printing**: a Char on its own prints as its character. Inside a list,
  a tuple or a datatype's value it prints in single quotes, as a String
  there prints in double quotes, so the two are told apart.
- **Patterns**: `case 'a':` matches that Char, and a `match` on a Char
  needs a `case _`, since no list of literals covers every one.
