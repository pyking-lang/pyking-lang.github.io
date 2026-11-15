---
title: "Modules"
description: "Modules, public, imports, submodules and modules implemented elsewhere."
sidebar:
  parent: Language reference
  position: 13
---

**One file is one module.** A file called `list.pyk` is the module
`list`, and a program is that file together with every module it
reaches. There is no declaration to write and no directory layout to
follow: the file's own name is the module's name.

## Nothing is exported by default

A name at the top of a module is the module's own until `public` is
written in front of it. `public` goes before a `def`, before a `def`'s
signature line, or before an `=` binding:

```pyking
# list.pyk

step = 1

public def next(n:Int) -> Int:
    return n + step


public def previous : (Int) -> Int
def previous(n):
    return n - step


public first: Int = 0
```

`next`, `previous` and `first` are what another module can reach.
`step` is not, even though `first` and both functions are worked out
from it: what a module exports is a name, not the things that name was
built from.

A definition says its type in one place or the other (see "Type
variables"), and `public` follows the same rule loosely: writing it on
either the signature line or the definition exports the definition, and
writing it on both is allowed and means the same thing.

Two restrictions hold:

- **A `var` cannot be public.** A module exports values and functions,
  not variables another module could write to.
- **An exported name is bound once.** A module exports one thing under
  one name, so a name marked `public` is not also bound a second time at
  the top level, and two `public`s of one name are refused.

## What a module may export

**A module says what it exports, in the file that exports it.** An
exported name carries its complete type in the source: a public `def`
annotates every parameter and its return type, or has a signature line
of its own, and a public `=` binding annotates its name:

```pyking
# Each of these says what it is.

public def next(n:Int) -> Int:
    return n + 1


public def double : (Int) -> Int
def double(n): n * 2


public size: Int = 12
```

```pyking error
public def triple(n): n * 3
```

```
'list.pyk' 1:0-1:27 Type error: 'triple' is public, and a public
  function or value needs a complete annotated type signature:
  annotate every parameter and the return type, or give it a 'def
  triple : ...' signature line.
```

A `def` that writes no annotations is worked out from a call — inference
reads a definition off its own module's use of it (see "Functions
without annotations"). That works out what this module's own program
needs, and it is not a promise to another one, so a call here does not
stand in for the annotations: what crosses the boundary is what the
source wrote down.

A `public datatype` or `public struct` says its fields' types the same
way: a field whose default is not a literal has its type written beside
it (`value: Int = start()`).

A `public class`, `public abstract class` or `public interface` exports
the class with its constructor and every member that is not `private`
(see "Classes across modules"). Its members say their types already: a
method writes every parameter's type, and a field its own.

A written type is the type it always was, so an exported function is as
general as its annotation says. `identity` here is exported as
`(a) -> a` and may be used at every type:

```pyking
public def identity : (a) -> a
def identity(x): x
```

## Importing a whole module

`import` brings a module in under a name, and its public names are
reached through that name and a dot:

```pyking norun
import list
import web

print(list.next(7))
```

Several modules may be named on one line, which means exactly what the
separate lines mean:

```pyking norun
import list, web
```

A module may be brought in under a name of the program's choosing, which
is then the only name it has here:

```pyking norun
import numerical as nm

print(nm.sum(3))
```

## Importing names

`from` takes named things out of a module and binds them in this
module's own top level, so they are written without a qualifier. Each
may be renamed:

```pyking norun
from list import next, first
from list import previous as back

print(next(first))
print(back(2))
```

The module itself is *not* in scope after a `from` line: `list.next` is
an error there unless `import list` is also written.

**There is no `import *`.** Every name a module reaches is written down,
so reading the top of a file says where each of them comes from.

## What an import may name

A `from` line may only name something the module exports. A name the
module has but did not mark `public` is refused, and so is a name it
does not have at all.

Every name an import brings in must be free: a collision with anything
the importing module binds at its top level, with a builtin, or with
another import, is refused rather than settled by one of them winning.
`as` is how a collision is resolved.

An import belongs to a module's **top level** — it says what the module
is built from, so it cannot be written inside a `def`, a loop or a
branch. Like a `def`, an import is visible throughout the module rather
than from its line down, so where it is written among the other
top-level statements does not matter.

## Submodules

A definition whose name has a dot in it is in a **submodule** of its
module: `mymod.foo` is `foo` in the submodule `mymod`, and
`mymod.another.foo` is `foo` in `another` inside `mymod`. A submodule is
nothing but those names -- there is no file or declaration for it -- so
a library groups what it offers by subject inside one file:

```pyking norun
# hello.pyk
public def mymod.foo(x: Int) -> Int: x + 1
public def mymod.another.foo(x: Int) -> Int: x + 100
public mymod.limit: Int = 10

public datatype shapes.Shape:
    Circle(r: Float)
    Square(s: Float)

def mymod.helper(x: Int) -> Int: mymod.foo(x) * 2
```

A `def`, a signature line, an `=` binding and a datatype may have a
dotted name, at a module's top level only. A dotted datatype's
constructors are in its submodule too: `shapes.Circle(1.0)`, and `case
shapes.Circle(r):`. Each name is `public` or not on its own, as any
other is.

**Inside its own file**, a name in a submodule is always written with
its whole path -- `mymod.foo(1)`, even inside `mymod.helper` -- so a name
means the same thing wherever it is read. A submodule's name is then
taken in the whole file: nothing else there, at the top level or in any
block, may be called `mymod`, so `mymod.foo` is never a field of a
value. A dotted name and the plain one with `__` in place of each dot
(`mymod.foo` and `mymod__foo`) are one name, and a module may not define
both.

**From another module** there are four ways to reach one:

```pyking norun
import hello
print(hello.mymod.foo(7))          # through the module

from hello import mymod            # the submodule, by its own name
print(mymod.foo(8))
print(mymod.another.foo(8))

import hello.mymod as m            # the same, renamed; without `as`
print(m.foo(9))                    # it is known as `mymod`

from hello.mymod import foo        # one name out of it
print(foo(10))
```

`import hello.mymod` binds `mymod`, the last part, rather than `hello`.
A name a submodule did not make public is refused from outside, however
it is reached, and so are a submodule the module does not have and a
name the submodule does not have. A name that stands for a submodule
here -- `mymod` above, or `m` -- is taken in the whole file, as one of
the file's own is.

## A public implicit arrives unqualified

A `public` name is reached through the module name (`mod.less_index`).
A name that is **both `public` and `implicit`** is different: it is also
found by an unqualified call in the file that imports the module,
automatically, so an ordering a library defines is usable without being
named.

```pyking norun
# ordering.pyk
public implicit def int::leq(x: Int, y: Int) -> Bool: x <= y
public def less_index(elem: a, lst: [a],
                      implicit leq: (a, a) -> Bool) -> Int: ...
```

```pyking norun
# main.pyk
import ordering as ord

print(ord.int::leq(7, 8))       # by its full name, which always works
print(leq(88, 100))             # found because it is public *and* implicit
print(ord.less_index(10, [7, 4, 12, 2]))
```

`less_index` is public and not implicit, so it is reached through
`ord.` like anything else — but *its* implicit parameter is resolved at
each call, against everything in scope there, including implicits this
file writes itself.

Auto-import is **not transitive**: what is in scope is what this file
imports. If `main` imports `middle` and `middle` imports `ordering`,
`ordering`'s implicits do not reach `main`. The cost is that a library
cannot re-export another's orderings; the gain is that reading a file
says where every name it uses comes from.

## No circular imports

A module is compiled, and run, after everything it imports. Two modules
that import each other — directly, or round a longer ring — have no such
order, so a cycle is a compile-time error naming the ring it found:

```
'b.pyk' 1:0-1:8 Module error: these modules import one another: a -> b
  -> a. Pyking has no circular imports: a module is compiled, and run,
  after everything it imports
```

## When a module runs

A module's top level is ordinary code, and it runs **once**, before the
top level of anything that imports it. The order is the one the imports
themselves give, and the program's own module is last:

```pyking
# base.pyk
print("base")

public def one() -> Int:
    return 1
```

```pyking norun
# middle.pyk
import base

print("middle")

public def two() -> Int:
    return base.one() + 1
```

```pyking norun
# main.pyk
import middle

print("main")
print(middle.two())
```

```
base
middle
main
2
```

`base` runs before `middle` because `middle` imports it, and both run
before `main`. Nothing else about the order is promised, and nothing
needs to be: a program's modules form an acyclic graph, and every module
sees a fully-run version of everything it imports.

## Finding a module

`import list` in `dir/main.pyk` reads `dir/list.pyk` — a module is
looked for beside the file that imports it, whatever directory the
compiler was run from. There is no search path and no way to reach
another directory.

## A module implemented elsewhere

A module can be implemented in a target language rather than in Pyking.
A file called `sys_external.pyk` is still the module `sys`, but it holds
*signatures only* — every name it exports is written down with its type
and left without a body, in either form of a signature line; the one that
names its parameters says what each is for. A name ending in `_external` therefore never
names a module of its own: `import sys_external` is refused, and the
module is imported as `sys`.

```pyking norun
public def loadfile(path: String) -> String

public def start : Int
```

Importing it is no different from importing any other module, and a call
is checked against the type written here:

```pyking norun
import sys

print(sys.loadfile("notes.txt"))
print(sys.start)
```

Two rules hold of such a file, and each is refused where it is broken:

- **Signatures and nothing else.** No bodies, no top-level bindings. The
  file says what the module offers; something else provides it.
- **No type variables, and no functions but callbacks, in a
  signature.** A parameter may be a function whose own parameters cross
  the boundary and which answers `()`: the host calls it back, for its
  effect. No other function crosses, and one implementation cannot be
  polymorphic.

A plain `sys.pyk` is unaffected: a signature there still has to describe
a `def` in the same file, exactly as before.

**A module may be written in both.** `sys.pyk` and `sys_external.pyk`
are one module `sys`, not two: the first is written in Pyking against
what the second declares, and a program that imports `sys` reaches
everything either half offers, under the one name.

```pyking norun
# clock_external.pyk -- what the host provides
public def now() -> Int

def raw() -> Int


# clock.pyk -- written against it
public def doubled() -> Int:
    return raw() * 2
```

```pyking norun
import clock

print(clock.now())
print(clock.doubled())
```

Two things follow, and both are the ordinary rules read across the two
files rather than anything new:

- **A declaration is in scope in the Pyking half**, unqualified and with
  no import — `raw()` above is written as any other name of the module
  is, because it *is* one.
- **`public` means the same on either side.** `raw` is not public, so
  `clock.raw()` from another module is refused exactly as a `def`
  written without `public` would be. A name declared in one half and
  defined in the other is refused too: a module offers one thing under
  one name.

Everything else about such a module — which file implements it for which
target, what each Pyking type becomes on the other side, and how the
interpreter reaches it — is about *compiling* rather than about the
language, and lives in docs/modules.md.

## Modules and types

An imported name has the type the checker gave it where it was written.
Nothing is inferred a second time and nothing crosses the boundary but
the exported names and their types, so a mistake about one is reported
where it is made:

```pyking norun
from list import next

print(next("seven"))
```

```
'main.pyk' 3:11-3:18 Type error: argument 1 has type String, but Int
  was expected
```

A public function whose type was never written down has the type the
checker worked out for it, including its type variables, so a
polymorphic function stays polymorphic across the boundary.
