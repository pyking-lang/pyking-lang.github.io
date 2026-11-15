---
title: "Programs, modes and use"
description: "A program, its modules, and the use lines that turn on mutation, pointers and objects."
sidebar:
  parent: Language reference
  position: 1
---

> **Available:** in every module · **Compared with Python:** new in Pyking

A program is one file, its main module, together with every module it
imports (see "Modules"). How much of the language a module may use is
chosen by the module itself, with `use` lines at its top. Without one, a
module is functional: names are bound once and data is not changed in
place.

## Features turned on with `use` — Pyking extension

A module is functional and immutable unless it turns more of the
language on, with `use` lines at its top -- before any import or
statement, though comments may come first:

```pyking
# A counter, kept in a mutable variable.
use mutation

var count = 0
count := count + 1
print(count)
```

| Feature | Turns on |
|---|---|
| `mutation` | `var`, `:=` and compound assignment such as `+=` (see "Mutable variables"), making and writing arrays (see "Arrays"), DynArrays (see "DynArrays"), MutMaps (see "MutMaps") and views (see "Slices and views"), and declaring, making and writing `mutable struct`s (see "Mutable structs") |
| `pointers` | `&`, `*` and `*p := v` (see "Pointers"); needs `mutation` too |
| `objects` | declaring classes, abstract classes and interfaces (see "Classes and interfaces") |

Several are written on one line, `use mutation, objects`, or on lines
of their own.

**One parser reads every module.** A `use` changes nothing about how
the module is read: `var` is parsed in every module, and refused in one
that has not turned mutation on, as a syntax error that names the line
that would allow it:

```
'prog.pyk' 1:0-1:3 Parsing error: 'var' declares a mutable variable,
  which needs 'use mutation' at the top of this module
'prog.pyk' 2:0-2:6 Parsing error: ':=' changes the mutable variable
  'count', which needs 'use mutation' at the top of this module
```

**A feature belongs to its module.** Importing a module that uses
mutation does not turn mutation on in the importer, and nothing turns
it on for a module but its own `use` line. A library may use mutation
inside itself, and a module implemented in a target's own language
(tinyweb's host half, for one) does whatever its host does: neither
makes the program that imports it mutable. Submodules share their
file's `use` lines.

Without `use mutation`, `for` and `while` still work -- a `for` prints
each element, and `while not io.is_eof():` reads to the end of the input
-- and a `loop`'s accumulator is a fresh binding each turn, not a
mutation. That is how a functional module adds something up:

```pyking
total = loop sum = 0 for x in [1, 2, 3]:
    sum + x
print(total)
```

In the REPL, a `use` line typed at the prompt holds for the rest of the
session, and `pyk repl --use mutation` starts one with it on. In a
notebook, every cell is a program of its own and writes its own `use`.
