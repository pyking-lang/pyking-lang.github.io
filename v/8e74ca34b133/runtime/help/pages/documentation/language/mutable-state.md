---
title: "Mutable state"
description: "var and :=, mutable structs, copy and deepcopy, and pointers, under use mutation."
sidebar:
  parent: Language reference
  position: 5
---

> **Available:** with `use mutation` (pointers with `use mutation,
> pointers`) · **Compared with Python:** differs -- a variable is
> declared with `var` and changed with `:=`

State that changes over time is written explicitly. A `var` is the one
kind of name that may change, `:=` is the one way to change it, and a
`mutable struct` is the one kind of record whose fields may be written.

## Mutable variables (`var` and `:=`) — Pyking extension

`var name = expr` declares a new mutable variable, initialized to the
value of `expr`. Once declared, it is updated with `name := expr`, not
`=`. Both need `use mutation` at the top of the module (see "Features
turned on with `use`"). Since `:=` is what every later write uses,
`var name := expr` is accepted too, and means the same declaration;
`-t pyking` writes it back with `=`. A `var` takes no type annotation
(its type is its starting value's) and declares one name, and a
declaration that is not `var name = expr` is refused at the token that
goes wrong, with the form it should take.

```pyking
use mutation

var total = 0
total := total + 1
print(total)
```

**A mutable variable may hold a value of any type**: a number, a
String, a tuple, a list, a datatype's value or a function. What changes
is which value the name holds; a list held by a `var` is still never
changed in place, so updating one builds the new list and stores it:

```pyking
use mutation

var balls = [(10, 20), (30, 40)]
balls := [(x + 1, y) for (x, y) in balls]
balls := balls + [(0, 0)]
print(balls)
```

Its type is its initializer's, decided once, and every `:=` must give
that same type — a mutation is not a rebinding, so it cannot change what
the name holds. Nothing else marks the name as mutable: reading one
yields an ordinary value of that type, usable anywhere an immutable one
is, which is why `total` above is added to, compared and printed like
any binding. (There are no references or pointers yet; when there are,
that reading step becomes something a program can talk about.)

A mutable variable is also the one name that may not be shadowed, and
`:=` only ever accepts one — both checked at compile time, and neither
of them a question about types; see "Names and scoping" below.

**Compound assignment.** `name op= expr` is `name := name op expr`, for
every arithmetic and bitwise operator: `+=`, `-=`, `*=`, `/=`, `%=`,
`^=`, `&=`, `|=`, `<<=`, `>>=` and `xor=`. It is checked exactly as the
`:=` it means is, so it needs `use mutation` and a `var`, and the
operator's result must be the variable's own type: `ratio /= 2` on a
Float is refused, since Pyking mixes no numbers, and `ratio /= 2.0` is
what works. The right-hand side is one whole expression, so
`n *= 1 + 2` is `n := n * (1 + 2)`:

```pyking
use mutation

var count = 10
count += 5          # 15
count *= 1 + 2      # 45
var greeting = "hello"
greeting += ", world"
var bits = 12
bits <<= 2          # 48
print(count, greeting, bits)
```

**Several at once.** `a, b := e` writes several mutable variables from
one tuple, and the names may nest to match its shape:
`(x, (y, z)) := (1, (2, 3))`. The value is worked out once, in full,
and only then is each name written, left to right — so `a, b := b, a`
swaps them, where two `:=` in a row would not. Each name must be a `var`
of the part's type, and is named once. This is how a function updates
several variables: it returns their new values, and one `:=` stores
them (there are no reference parameters):

```pyking
use mutation

def divmod(n: Int, d: Int) -> (Int, Int):
    (n / d, n % d)

var q = 0
var r = 0
q, r := divmod(17, 5)
var a = 1
var b = 2
a, b := b, a
print(q, r, a, b)       # 3 2 2 1
```

`+=` on a String or a list joins, as `+` does, and builds a new value:
a list held by a `var` is still never changed in place, so a binding
that held the old list keeps it. Like `:=`, a compound assignment is a
statement with no value of its own: `print(count += 1)` is refused.
There is no `++`, and no `and=`/`or=`. `-t pyking` prints one back as
it was written.

## Mutable structs (`mutable struct`) — Pyking extension

A **`mutable struct`** is a struct whose fields are written in place. Its
values are *shared*: every name, parameter, element and field holding
one holds the same struct, so a write through any of them is seen
through all -- Java's objects and Python's class instances work this
way. A plain `struct` stays a value that never changes. Declaring,
making and writing a `mutable struct` need `use mutation`; reading, passing,
returning and holding one do not.

```pyking
use mutation

mutable struct Point(x: Int, y: Int = 0)

p = Point(5)
p.x := 10
p.y += 1
q = p
q.x *= 3
print(p, same(p, q))        # Point(30, 1) true
```

**Declaring one.** `mutable` goes in front of `struct`, and makes every
field writable. `mutable` is a keyword, and the old spelling, `var
struct`, is refused with a hint; the rest is as "Structs" says -- fields in parentheses
or on indented lines, defaults, type parameters, `public`. A `mutable
struct` has at least one field, since one with none has nothing to
write. Only a struct is written in place: `mutable datatype` is refused, and
a datatype's or a plain struct's field is never written.

**Writing a field.** `p.x := e` writes the field `x` of the struct `p`
holds, and the compound forms (`p.x += 1`, every one "Mutable variables"
lists) read it and write it back. The left side is any expression
giving a `mutable struct`, followed by a field: `points[i].x := 0`,
`player().score += 1`, `box.inner.y := 8` -- the last needs `inner` to
be a `mutable struct` too.

- **`var` is for rebinding, not for writing.** `p = Point(1, 2)` binds
  `p` once, and `p.x := 3` still writes the struct: whether a field may
  be written is its type's question, as an array's element is. A
  function's parameter, never a `var`, writes the struct it was given.
  `var p = ...` is what lets `p := Point(0, 0)` make `p` name another
  struct.
- **A write runs in a fixed order.** `p.x := e` works out `p`, then
  `e`, and writes into the struct `p` was, even if `e` made `p` name
  another one. A compound form reads the field between the two.
- **`=` does not write.** `p.x = 1` is refused with "did you mean `p.x
  := v`?". Writing a plain struct's field is refused with how to build a
  changed copy, `Point(x = ..., ..old)`, or to declare it `mutable struct`.

**Making one.** A `mutable struct`'s constructor is called as any struct's,
with defaults and named arguments, and makes a new, separate struct
each time. `Point(x = 1, ..p)` makes a new struct too: `p` is not
changed, and a mutable field the two would hold -- an array, another
`mutable struct` -- is shared by both. Making one needs `use mutation` in
the module that makes it, wherever it was declared; a module without it
may still hold, read and pass on one another module made.

**Reading one.** `p.x` reads the field as it is now, and a pattern
`case Point(x, y):` reads every field it names as the struct is when it
is matched; a guard that writes a field is seen by the cases after it.

**Identity.** `same(p, q)` asks whether two names hold one struct, as it
does for arrays. `==` compares no structs: whether two hold the same
fields is a function the program writes. A new struct holding the same
fields is `copy(p)`, and one sharing nothing writable with `p` is
`deepcopy(p)` (see "Copying").

```pyking
use mutation

mutable struct Counter(n: Int)

def bump(c: Counter) -> ():
    c.n += 1

a = Counter(0)
b = a
bump(b)
print(a.n, same(a, b), same(a, Counter(1)))     # 1 true false
```

**Linked structures.** A `mutable struct` may hold a value of its own type,
through a datatype that can also hold nothing -- there is no null --
which is how linked lists, trees and graphs are built, cycles and all:

```pyking
use mutation

datatype Link:
    End
    Next(node: Node)

mutable struct Node(value: Int, next: Link)

a = Node(1, End)
b = Node(2, Next(a))
a.next := Next(b)
print(a)        # Node(1, Next(Node(2, Next(...))))
```

**Printing** is as for a struct, `Point(30, 1)`. A struct -- or an
array -- met again *inside itself*, a cycle, prints `...` where it
repeats, so printing always ends; one that is only shared, the same
struct twice in an array, prints in full each time. `string(p)`, the
REPL and the debugger show the same text. `print(p, f(p))` works out
every argument before it writes any, so a change `f` makes to `p` is
printed.

**Types.** A `mutable struct` with a type parameter, `mutable struct Cell(value:
a)`, is one type once made: the first use that decides its parameter
decides it everywhere. One that nothing decides, `c = Cell([])`, is
`Cell([a])`, as an empty array is `Array(a)`.

**Targets.** Every target compiles them: a class with fields that can be
written on Python and JavaScript, a final class on Java, a record with
`mutable` fields on OCaml, and on C a pointer to a struct, which plain C
mallocs and never frees and `c23-gc` takes from the collector.

## Copying (`copy` and `deepcopy`)

An array, a DynArray, a MutMap, a view, a `mutable struct` and an
object are *shared*: `b = a` and passing `a` to a function hand over
the same one, so a change through either name is seen through both
(see "Mutable structs" and "Classes and interfaces"). Two builtins make
a separate one instead. Both work on a value of any type, in every
module, with no `use` line:

- **`copy(x)`** makes a *shallow* copy: a new outermost array,
  DynArray, MutMap, `mutable struct` or object, holding the same
  elements, entries or fields as `x`. What those hold is shared by the
  original and the copy.
- **`deepcopy(x)`** makes a *deep* copy: a value equal to `x` that
  shares nothing writable with it. Every array, DynArray, MutMap, view,
  `mutable struct` and object reachable from `x` is copied.

```pyking
use mutation

mutable struct Point(x: Int, y: Int)

points = array([Point(1, 1), Point(2, 2)])
shallow = copy(points)
deep = deepcopy(points)

shallow[0] := Point(9, 9)    # changes only the shallow copy's array
deep[1].x := 20              # changes only the deep copy's point
shallow[1].x := 30           # changes the point both arrays share

print(points)                # array([Point(1, 1), Point(30, 2)])
print(shallow)               # array([Point(9, 9), Point(30, 2)])
print(deep)                  # array([Point(1, 1), Point(20, 2)])
print(same(points[1], shallow[1]), same(points[1], deep[1]))   # true false
```

What each gives, by the value copied:

| The value | `copy(x)` | `deepcopy(x)` |
|---|---|---|
| Int, Float, String, Char, Bool, `()` | `x` itself | `x` itself |
| a list, tuple, Map, plain `struct`, datatype | `x` itself: it never changes, so a copy could not be told from it | a new one whose parts are deep-copied |
| an Array, a DynArray | a new one holding the same elements | a new one, each element deep-copied |
| a MutMap | a new one holding the same entries, in the same order | a new one, the same keys, each value deep-copied |
| a view | a view with the same bounds, of a copy of the whole array behind it | the same, the array deep-copied |
| a `mutable struct` | a new struct holding the same fields | a new struct, each field deep-copied |
| an object | a new object of the class it *is* (a `Shape` holding a `Square` copies to a `Square`), holding the same fields, private and inherited ones included | a new object of that class, each field deep-copied |
| a function | `x` itself | `x` itself: a function is shared, as in Python's `copy.deepcopy` |
| a pointer | `x` itself | refused (below) |

**Sharing and cycles are kept.** A deep copy copies each array, struct
and object once. If one is reached twice in `x`, the copy reaches its
copy twice. A cycle (`a.next` leading back to `a`) gives a copy with the
same cycle, and copying it always ends. A view and the array behind it,
both inside `x`, give a view of the new array:

```pyking
use mutation

mutable struct Cell(value: Int)

shared = Cell(0)
pair = array([shared, shared])
copied = deepcopy(pair)
copied[0].value := 5
print(copied, same(copied[0], copied[1]), same(copied[0], shared))
# array([Cell(5), Cell(5)]) true false
```

**A deep copy copies everything reachable.** An object that holds a
reference to a large structure -- a `Player` holding the whole `Game` it
is in -- drags a copy of all of it along. Where only the outermost value
should be new, `copy` is the one to use, and a struct's own fields can
be copied by hand with `Point(..p)`.

**Where each is refused.** Both are made for the type at the call, so
the type must be known there: `def f(x: a) -> a: copy(x)` is refused,
since a type variable says nothing about what to copy. A definition
with no annotations is not generalised over a type it copies; its first
use decides that type, as for `+`. `deepcopy` also refuses a pointer
anywhere in the type, since the place a pointer points at is not part
of the value. `copy` takes one, and the copy holds the same pointer.

```pyking error
use mutation, pointers

mutable struct Node(value: Int, at: Ptr(Int))

var x = 1
n = deepcopy(Node(1, &x))
```

```
'node.pyk' 6:13-6:24 Type error: 'deepcopy' cannot be applied to Node;
  a pointer cannot be deep-copied, since the place it points at is not
  part of the value, and the field 'at' of Node is a Ptr(Int);
  copy(x) copies only the outermost value, sharing what it holds
```

A class below an interface may hold a pointer that the module copying
the interface cannot see: a class of another module (see "Classes across
modules"). A deep copy that meets one stops the program with `deepcopy
met a pointer, which cannot be deep-copied`.

**Identity and equality.** A copy of a shared value is a new one, so
`same(copy(a), a)` is `false`. Where `==` compares the type, it answers
`true` for a copy of a value that has not been changed since.

**Targets.** Every target makes both copies:

- Python, JavaScript and Java by walking the value at run time, with a
  table of what has been copied.
- C by a copy function written for each type, and each class's
  descriptor holding the function that copies one of its objects.
- OCaml makes `copy` for the type at the call, and `deepcopy` by walking
  the value's own blocks.

## Pointers — Pyking extension

`use pointers` adds C's pointers -- without null, arithmetic or freeing
-- for teaching how memory is addressed. It needs `use mutation` in the
same module: a pointer is a way to write to a variable.

```pyking
use mutation, pointers

def swap(a: Ptr(Int), b: Ptr(Int)) -> ():
    t = *a
    *a := *b
    *b := t

var x = 1
var y = 2
swap(&x, &y)
print(x, y)            # 2 1
```

- **`&place`** is a pointer to a place something may write: a `var`, an
  element of an array or of a view (`&a[i]`, which is the array's), a
  field of a `mutable struct` (`&p.x`), or what a pointer points at (`&*p`
  is `p`). Its type is `Ptr(T)`. An `=` binding, a list's or a DynArray's
  element, a plain struct's field, a call's result and a literal have
  no address, and `&` of one is refused with the reason.
- **`*p`** reads what `p` points at, now; **`*p := v`** and the compound
  forms (`*p += 1`) write it, the pointer worked out before the value.
  A field through a pointer is written `(*pp).x`, as in C; there is no
  `->` and no automatic dereferencing.
- **`&` and `*` are prefix** where an operand starts, and bitwise and
  and times between two operands, as `-` is negation or subtraction. A
  line starting with `*` or `&` is a statement of its own: `*p := 5`.
- **Equality.** `p == q` is true when both name one place. A pointer is
  never a MutMap's key.
- **Printing** writes what a pointer points at, `Ptr(12)`, never an
  address, so every target prints the same.
- **Lifetime.** A `var` whose address is taken lives as long as a
  pointer to it, even after its function returns -- except on plain C,
  which refuses a pointer to a local that would outlive its function
  (C would leave it dangling); `c23-gc` keeps such a variable on its
  collected heap.
- **None.** A pointer that may point nowhere is `Option(Ptr(T))`:
  `None`, or `Some(&x)`, matched before it is used.

docs/pointers.md has the whole story, with each target's
representation.
