---
title: "Builtins and I/O"
description: "print, debug, len, range, the conversions and panic, and where input and output go."
sidebar:
  parent: Language reference
  position: 14
---

> **Available:** in every module · **Compared with Python:** similar --
> `print`, `len`, `range` and the conversions are Python's; `printsl`,
> `eprint`, `eprintsl` and `debug` are new

A few operations are built into the language rather than defined in a
library: printing, `len`, `range`, the conversions, copying and `panic`. A
builtin may only be called: it is not a value that can be stored or
passed.

## Builtin functions

`print`, `printsl`, `eprint`, `eprintsl`, `debug`, `range`, `string`,
`len`, `int`, `float`, `bool`, `char`, `copy`, `deepcopy` and `panic` are checked at the call, each by its own rule,
because none of them is a function *value*: a builtin is a host operation (see "Names
and scoping"), it has no type that can be written down, and it may be
called and nothing else.

| call | accepts | gives |
|---|---|---|
| `print(…)` | any number of arguments, of any type | `()` |
| `printsl(…)` | any number of arguments, of any type | `()` |
| `eprint(…)` | any number of arguments, of any type | `()` |
| `eprintsl(…)` | any number of arguments, of any type | `()` |
| `debug(…)` | any number of arguments, of any type | `()` |
| `string(x)` | one `Int`, `Float`, `String`, `Char`, `Bool`, list or tuple | `String` |
| `len(x)` | one list, array, DynArray, view, Map, MutMap or `String` (counted in characters) | `Int` |
| `panic(m)` | one `String`: stops the program with it as a runtime error | any type, since it never answers |
| `copy(x)` | one value of any type known at the call | a shallow copy, of the same type (see "Copying") |
| `deepcopy(x)` | one value of any type known at the call, holding no pointer | a deep copy, of the same type (see "Copying") |
| `range(n)` | one to three `Int`s | `[Int]` |
| `int(x)` | one `Int`, `Float`, `String`, `Char` or `Bool` | `Int` |
| `float(x)` | one `Int`, `Float`, `String`, `Char` or `Bool` | `Float` |
| `bool(x)` | one `Int`, `Float`, `String`, `Char` or `Bool` | `Bool` |
| `char(x)` | one `Int`, `String` or `Char` | `Char` |

```pyking
count = len("hello")          # Int
label = "n = " + string(count)   # String
numbers = range(4)            # [Int]
ratio = float(count) / 2.0    # Float

print(label, numbers, count, ratio)  # anything, any number of them
```

## Conversions

`string`, `int`, `float`, `bool` and `char` are how a
value of one type becomes another — Pyking converts nothing on its own.
`string` writes a value exactly as `print` would. The other four answer
every argument they accept, and where there is no right answer they
answer a **default**: 0 for `int`, NaN for `float`, false for `bool`,
`'\0'` for `char`. A Char converts to and from its code point: `int(c)`,
`float(c)`, `char(n)`; `bool(c)` is false for `'\0'` only, and
`char(s)` is a String's first character.

- `int` truncates a Float toward zero, takes true to 1 and false to 0,
  and reads a String written as an optional `+` or `-` and decimal digits,
  with nothing around them — not a space, not a point, not `0x`. An
  answer outside the signed 32-bit range, and a Float with no Int to
  truncate to (a NaN, an infinity), is 0.
- `float` widens an Int, takes true to 1.0 and false to 0.0, and reads a
  String written the way a Float literal is — digits, an optional
  fraction, an optional exponent, and an optional sign — or as `inf`,
  `-inf` or `nan`, which is how `print` writes those. So
  `float(string(x))` is `x`.
- `bool` is true for `true`, the String `"true"`, the Int 1 and the Float
  1.0, and false for anything else — `"True"` and 2 included.

Each accepts its own type too, and answers it unchanged.

```pyking
print(int("42"), int("4 2"), int(-2.9), int(true))   # 42 0 -2 1
print(float("1e3"), float("one"), float(false))       # 1000.0 nan 0.0
print(bool("true"), bool("yes"), bool(1), bool(2.0))  # true false true false
print(string(1.5) + "!", string([1, 2]))             # 1.5! [1, 2]
```

The defaults stand in for an answer Pyking cannot yet give. Once it has
an **option type**, `int`, `float` and `bool` will answer either no value
or the value converted, so a program can tell `int("0")` from
`int("zero")`; until then it has to check the String itself.

Using one as a value rather than calling it is an error — `shout = print`
is refused — which is also what the C and Java backends do with `print`.

## Printing

`print` writes its arguments, separated by spaces, as one line of
standard output. Three more builtins take and format their arguments
exactly as `print` does, and differ in where they write and whether they
end the line: an `e` in front writes to **standard error**, and `sl` at
the end writes on the **same line**, with no newline after.

| | ends the line | same line |
|---|---|---|
| standard output | `print` | `printsl` |
| standard error | `eprint` | `eprintsl` |

```pyking
printsl("loading")
printsl("...")
print(" done")              # loading... done
eprint("warning:", 3)       # warning: 3, on standard error
```

In a browser, standard error is the console's error stream, and a
`printsl` or `eprintsl` line is shown once it is complete. `eprint` and
`eprintsl` are the program's own output to standard error, and stay in
a program built in release mode; `debug`, below, does not.

## `debug`

`debug` is `print`'s twin for diagnostic output — Pyking extension. It
takes and formats its arguments exactly as `print` does, and writes the
line where diagnostics go rather than to the program's output, so
tracing a program never changes what it prints. A program built in
**release mode** has every call to `debug` removed, arguments and all,
and `print` kept:

```pyking
def square(x: Int) -> Int:
    debug("square of", x)       # a diagnostic line, gone in release mode
    return x * x

print(square(7))                # 49, in both modes
```

A call removed in release mode is worth the unit it always was, so a
program means the same thing in both modes except for its diagnostics —
and for anything an argument to `debug` would have done, which does not
happen at all. That difference is also the reason `debug` exists beside
`print`: writing a diagnostic is not something a program is *observed*
to do, so `debug` will be allowed in a pure function, where `print` will
not.

A program may define a `debug` of its own, like any other name; a call to
it is an ordinary call, and release mode leaves it alone.

## Input and output

`print` and `printsl` write to standard output, and `eprint`,
`eprintsl` and `debug` to standard error. Everything else a program
reads or writes goes through the standard library: `io` reads standard
input and writes without a newline, `sys`
gives the program's arguments and environment and ends it with an exit
code, and `fs` reads and writes files.

```stdin
3
4
```

```pyking
import io

a = int(io.read_line())
b = int(io.read_line())
io.write_line("sum: " + string(a + b))
```

Each library's functions are listed on its page under Libraries.
