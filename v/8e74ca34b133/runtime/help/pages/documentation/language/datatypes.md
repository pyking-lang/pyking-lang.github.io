---
title: "Datatypes, structs and pattern matching"
description: "datatype, struct, match and its patterns, Option and Result."
sidebar:
  parent: Language reference
  position: 9
---

> **Available:** in every module (`mutable struct` with `use mutation`) ·
> **Compared with Python:** `match` is Python's; datatypes and structs are
> new in Pyking

A datatype lists the shapes a value may have, each a constructor with
fields; a struct is a datatype with one constructor. `match` takes a
value apart by its shape, and the checker makes sure every shape is
handled. `Option` and `Result` are datatypes of the standard library,
used where Python would use `None` or an exception.

## Datatypes — Pyking extension

`datatype` declares a type of its own: a name, the type variables it is
written over, and its **constructors**, one per indented line. A value
of the datatype is built by a constructor, and is one of them and
nothing else:

```pyking
datatype Shape:
    Circle(radius: Float)
    Rect(width: Float, height: Float)
    Dot


def area(s: Shape) -> Float:
    match s:
        case Circle(r): 3.0 * r * r
        case Rect(w, h): w * h
        case Dot: 0.0


print(area(Circle(1.0)), area(Rect(2.0, 3.0)), area(Dot))
print(Rect(2.0, 3.0), Dot)
```

The name of a datatype and of each constructor starts with an
uppercase letter, which is what tells a constructor from a name in a
pattern: `case Dot:` matches the constructor, and `case dot:` binds
whatever arrives. A constructor with no fields is written bare, `Dot`,
in a pattern and as a value. A datatype is declared at the top level of
a module, and every datatype of the module is in scope throughout it,
so datatypes may name each other in any order, and one may name
itself.

Constructors may share a line, separated by commas, and the first line
of them may follow the datatype's `:` directly; each further line of
them is indented under it:

```pyking
datatype Color: Red, Green, Blue
    Gray(level: Int), Black

datatype Bit: Zero, One

print(Gray(3), One)
```

A value prints as the constructor applied to its fields, every field by
position, a string among them quoted: `Rect(2.0, 3.0)`.

**A field** is a type alone, which makes it positional, or a name and a
type, which may also be given by name. A named field may carry a
default, any expression, and may leave its type to it:

```pyking
def opening() -> Int:
    return 100


datatype Account:
    Account(String, balance = opening(), currency = "SEK")


print(Account("ada"))
print(Account("grace", 10))
print(Account("don", currency = "EUR"))
```

A field with no type written has its default's type, and that default
has to decide one: `items = []` is refused, since an empty list says
nothing about what it holds. An exported datatype writes its fields'
types down, a literal default's apart (see "What a module may
export").

A constructor is called with exactly the rules a `def` is (see "Default
parameters" and "Named arguments"): positional arguments first, named
ones in any order, every field without a default
given something, and a default evaluated at each construction that
leaves it out, in the scope the datatype is declared in. The unnamed
fields come first, and every field after one with a default has one
too.

**A datatype may have parameters**, written as type variables after its
name, and applied to types where it is named -- `Tree(Int)`,
`Option(String)`. A polymorphic function over one is written and
inferred like any other:

```pyking
datatype Option(a):
    Nothing
    Just(a)


def default(o: Option(a), d: a) -> a:
    match o:
        case Just(x): x
        case Nothing: d


print(default(Just(3), 0), default(Nothing, "none"))
```

A field's type may name only the datatype's own parameters.

**A constructor pattern** takes a value apart by the same rules a call
puts one together: positional patterns first, then `field = pattern`,
here in any order, and a field the pattern does not mention matches
anything:

```pyking
datatype Person:
    Person(name: String, age: Int, admin: Bool = false)


def role(p: Person) -> String:
    match p:
        case Person(admin = true): "admin"
        case Person(n, age = a) if a < 18: n + " is young"
        case Person(name = n): n


print(role(Person("ada", 36)), role(Person("tim", 12)), role(Person("root", 1, true)))
```

**A named field is read with `.`**, `p.name`, where every constructor of
the datatype has a field of that name at one type -- so a datatype of one
constructor is a record:

```pyking
datatype Point:
    Point(x: Int, y: Int)


p = Point(3, 4)
print(p.x * p.x + p.y * p.y)
```

A constructor is not a value of its own: one with fields is always
applied to them, and `Point` alone is refused.

**Across modules**, `public datatype` exports the datatype and every
constructor. A constructor is reached through the module as any public
name is -- `shapes.Circle(1.0)`, `case shapes.Circle(r):` -- and a
datatype named on a `from` line brings its constructors with it:
`from shapes import Shape` makes `Circle` a constructor here. A public
definition whose type names a datatype that is not public is refused,
since a module holding such a value could not say its type.

## Structs — Pyking extension

`struct` declares a datatype of one constructor, named as the type is.
It means exactly the `datatype` it stands for, which is why everything
"Datatypes" says of fields, defaults, construction, patterns and
modules holds of it:

```pyking
struct Point(x: Int, y = 78)

# the same as
#   datatype Point:
#       Point(x: Int, y: Int = 78)

p = Point(7, 10)
print(p, Point(1), p.x + p.y)
```

Its fields are in parentheses after its name, or on indented lines under
its `:`, a line holding one or more separated by commas. With neither,
it has no fields:

```pyking
struct Size:
    width: Int, height: Int
    unit = "px"


struct Pair(Int, Int)


struct Empty


print(Size(4, 5), Pair(1, 2), Empty)
```

**Type parameters** are written in parentheses before the `:` of the
indented form. On one line, every type variable a field names is a
parameter, in the order they first appear:

```pyking
struct Pair(a, b):
    first: a
    second: b


struct Box(value: a, label = "box")


print(Pair(1, "one"), Box(true).label)
```

A struct's value never changes: there is no assignment to its field. A
changed copy is built instead, with `..` below. A struct whose fields
are written in place is a `mutable struct` (see "Mutable structs").

**`..base`** as the last argument of a constructor gives every field
not written before it from `base`, a value of the same datatype, by
name:

```pyking
struct Point(x: Int, y: Int, z: Int = 0)


p = Point(7, 10)
print(Point(x = 5, ..p))          # Point(5, 10, 0)
print(Point(1, ..p))              # Point(1, 10, 0)
```

`Point(x = 5, ..p)` means `Point(x = 5, y = p.y, z = p.z)`: what is
written before the `..` is evaluated first, in the order written, and
`base` after it, once. Defaults play no part, since every field left
out comes from `base`. A field an update can fill is one with a
name, so an unnamed field is given before the `..`. `..` is written for
any datatype of one constructor -- one of several might not be the
constructor `base` was built by -- and is refused where it fills no
field, and in a call to a `def`, which has no fields to fill. Where the
datatype has parameters, the fields written may change them:
`Pair(first = true, ..Pair(1, "one"))` is a `Pair(Bool, String)`.

## `match`/`case` pattern matching

`match expr:` is followed by one or more indented `case pattern:` clauses;
the body of the first case whose pattern matches runs. A pattern is an
integer literal, a string literal, a boolean literal, `_` (always
matches, discards the value), a plain identifier (always matches, binds
the value to that name), or a tuple pattern that destructures a tuple
value element by element (with or without parentheses, nesting
arbitrarily, and sub-patterns can themselves be literals, `_`,
identifiers, or further tuple patterns) — see the notes on the Grammar,
and the sections below for constructor patterns, or-patterns, `as` and
guards. A `match` matches every value of its subject's type, which is
why `describe` ends in a case that binds a name (see "Exhaustiveness").

```python
def describe(n):
    match n:
        case 0:
            return "zero"
        case 1:
            return "one"
        case value:
            return "many: " + string(value)


for i in [0, 1, 5]:
    print(describe(i))
```

A boolean pattern matches only that exact value, the same way an integer
or string literal pattern does:

```pyking
def describe(flag):
    match flag:
        case true: "yes"
        case false: "no"


print(describe(1 < 2), describe(3 < 2))
```

```python
def classify_point(p):
    match p:
        case (0, 0):
            return "origin"
        case (x, 0):
            return "on the x axis"
        case (0, y):
            return "on the y axis"
        case (x, y):
            return "elsewhere"


print(classify_point((0, 0)))
print(classify_point((3, 0)))
print(classify_point((0, 3)))
print(classify_point((3, 4)))
```

A list pattern destructures a list value, and — unlike a tuple pattern —
may include **one** `..`/`..name` "rest" marker anywhere among its
elements, matching a run of zero or more elements there: `..` matches and
discards them, `..name` matches and binds them (as a list) to `name`.
Patterns before the marker are a required prefix, patterns after it are
a required suffix, and with no marker at all the list pattern matches
only a list of exactly that length. A plain `_` still matches (and
discards) a single element, exactly as in a tuple pattern.

```python
def describe(xs):
    match xs:
        case []:
            return "empty"
        case [x]:
            return "exactly one: " + string(x)
        case [a, b, c]:
            return "exactly three"
        case [first, ..rest]:
            return "prefix + rest, first=" + string(first)


print(describe([]))
print(describe([1]))
print(describe([1, 2, 3]))
```

A case that no value can reach -- every value it matches is taken by a
case above it -- is refused, so after `[first, ..rest]`, which takes
every list of one element or more, nothing more may be written. The
other forms, `[..init, last]`, `[p, q, ..mid, r]`, `[u, v, ..]` and
`[_, ..w]`, are each shown in a function of their own in
`tests/list_pattern_match.pyk`.

**Splitting with `+`.** A pattern may be written as pieces joined with
`+`, the concatenation operator read backwards: a pattern says how the
value was put together. Every piece but one has a fixed length, and the
one name in the middle takes whatever is left:

```pyking norun
[x] + xs               is  [x, ..xs]
first + [x, y, z]      is  [..first, x, y, z]
[x, y] + m + [k1, k2]  is  [x, y, ..m, k1, k2]
```

For a list the two spellings are the same pattern, and the printed
program uses the `..` one whichever was written. For a **string** this is the only
spelling, and the only way to match a string by anything but equality:

```pyking
def command(line:String) -> String:
    match line:
        case "get " + rest:
            return "GET(" + rest + ")"
        case "<" + body + ">":
            return body
        case other:
            return "?" + other
```

Only *literal* text can be stripped this way. `_ + rest` leaves two
parts open and is refused, and so is a chain mixing a list with a
string, or one whose pieces are not all of fixed length (`[x, ..r] + ys`
would need two rest markers).

A `case` clause opens a block like any other header, so an arm whose
body is one expression can be written on the clause's own line (see "A
block on its header's own line" in the Grammar). The arm then supplies its value
the way any branch tail does: it is the function's value directly inside
a function, and the bound value when the whole `match` is bound with `=`
(see "`if`/`match` statements as bound values"). Arms written each
way mix freely within one `match`.

```pyking
def describe(n):
    match n:
        case 0: "zero"
        case 1: "one"
        case _: "many"


for i in [0, 1, 5]:
    print(describe(i))
```

## Or-patterns, `as` and guards

`p1 | p2` matches what either alternative matches. The alternatives
bind the same names, at the same types, so the arm after it sees one set
of bindings whichever matched:

```pyking
def on_axis(p: (Int, Int)) -> String:
    match p:
        case (0, 0): "origin"
        case (x, 0) | (0, x): "on an axis at " + string(x)
        case _: "elsewhere"


print(on_axis((3, 0)), on_axis((0, -4)), on_axis((1, 1)))
```

`pattern as name` binds the whole value the pattern matched, beside
what the pattern takes apart:

```pyking
match (1, (2, 3)):
    case (x, (y, z) as inner):
        print(x, y, z, inner)
```

A **guard**, `case pattern if condition:`, is asked once the pattern has
matched, with what the pattern bound in scope. A guard that is false
goes on to the next case, as a pattern that does not match does. The
guard is a `Bool`:

```pyking
def sign(n: Int) -> String:
    match n:
        case 0: "zero"
        case m if m > 0: "positive"
        case _: "negative"


print(sign(5), sign(0), sign(-5))
```

Guards are asked in order, and only as far as the first that holds, so
one that calls a function calls it only when every case above it was
passed over.

## Option — Pyking extension

`Option(a)` is a value or none: `Some(value)` or `None`. It is builtin
in the way a library is: a module that uses `Option`, `Some` or `None`,
and declares and imports none of them, has lib/option's -- as if it
began `from option import Option` -- and `import option` reaches its
functions, named as Rust's are: `is_some`, `is_none`, `unwrap_or`,
`unwrap_or_else`, `and_then`, `or_else`, `zip`, `flatten`, `unwrap`,
`expect`, `all_some` and `values`. `fmap`, `filter`, the folds and
`list(o)` take an Option too (see "fmap and the folds").

```pyking
import option

def first_even(xs: [Int]) -> Option(Int):
    match xs:
        case []: None
        case [x, ..rest]: if x % 2 == 0 then Some(x) else first_even(rest)

print(first_even([1, 4, 5]), first_even([1]), option.unwrap_or(first_even([3]), 0))
# Some(4) None 0
```

A module declaring a datatype `Option`, or one with a constructor `Some`
or `None`, means its own, as programs written before Option was builtin
do. A pointer that may point nowhere is an `Option(Ptr(T))` (see
"Pointers"): Pyking has no null.

`option.or_else(o, f)` takes a function answering an Option, as Rust's
does; until November 2026 it took the default value, which is now
`option.unwrap_or(o, value)`, and an old call is refused with that
named.

## Result — Pyking extension

`Result(t, e)` is a value or the error that stopped it: `Ok(value)` or
`Error(error)`, as Rust's is, with `Error` for Rust's `Err`. It is
builtin as Option is: a module that uses `Result`, `Ok` or `Error`, and
declares and imports none of them, has lib/result's, and `import
result` reaches its functions.

```pyking
import result

def parse_age(s: String) -> Result(Int, String):
    n = int(s)
    if string(n) == s and n >= 0 then Ok(n) else Error("not an age: " + s)

print(parse_age("31"), parse_age("x"), fmap(lam n. n + 1, parse_age("31")))
print(result.unwrap_or(parse_age("x"), 0), result.and_then(parse_age("31"), lam n. if n < 150 then Ok(n) else Error("too old")))
# Ok(31) Error("not an age: x") Ok(32)
# 0 Ok(31)
```

lib/result has `is_ok`, `is_error`, `ok`, `error`, `unwrap_or`,
`unwrap_or_else`, `and_then` (the next step, which stops at the first
error), `or_else`, `map_error`, `unwrap`, `expect`, `unwrap_error`,
`flatten`, `all_ok`, `partition_results`, and `ok_or`, which makes an
Option a Result. `unwrap` of an `Error` stops the program with a runtime
error, as `panic` does. A module declaring its own `Result`, `Ok` or
`Error` means its own.
