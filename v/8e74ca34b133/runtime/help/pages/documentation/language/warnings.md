---
title: "Warnings"
description: "What the compiler warns about, and the -W flags."
sidebar:
  parent: Language reference
  position: 15
---

A program that checks may still say something its writer did not mean.
The compiler reports what it can see of that as **warnings**: each is
printed before the program runs, and the program then runs as usual.
Today they are about names bound and never used.

```pyking
x = 5
if true:
    x = 10

def helper(n: Int) -> Int:
    return n + 1

print("done")
```

```
'prog.pyk' 1:0-1:1 Warning: Unused binding 'x', bound on line 1: it is
  never used in its scope. [-Wunused-binding]
'prog.pyk' 3:4-3:5 Warning: Unused binding 'x', bound on line 3: it is
  never used in its scope. Did you try to update x as a variable? Name
  x is bound on line 1, but is not defined as a mutable variable. The
  declaration on line 3 is shadowing x, and then never used in the
  scope. [-Wshadowed-update]
'prog.pyk' 5:4-5:10 Warning: Function 'helper' is defined but never
  used. [-Wunused-function]
done
```

The second is the one worth knowing about. `x = 10` inside the `if` is
a *new* binding of `x` for that block -- `=` never updates (see
"Immutable bindings") -- so the `x` outside is still 5 after it. Where
such a binding shadows a name from an enclosing block and is then never
used, an update is almost certainly what was meant, and the warning
asks whether it was. An update is written with a `var` and `:=` (see
"Mutable variables").

## What is reported

Each warning has a name, which is what its flag is called:

| warning | on by default | reports |
|---|---|---|
| `unused-binding` | yes | a name bound with `=`, or by a `let`, that nothing in its scope uses |
| `unused-function` | yes | a function defined with `def` that is never called or passed on |
| `unused-var` | yes | a `var` that is never read -- writing to it with `:=` does not count |
| `shadowed-update` | yes | an unused `=` binding in a block that shadows a name bound outside it, as above |
| `unused-pattern-var` | no | a name a `case` pattern binds that its arm never uses |
| `unused-parameter` | no | a parameter of a `def` or a lambda that its body never uses |
| `unused-loop-var` | no | a `for` variable, a loop's accumulator, or a name a comprehension binds, that is never used |
| `shared-fill` | yes | `array(n, v)` where `v` is itself an array, so every element is one and the same array (see "Arrays"); not for a size of 0 or 1 |

A function is used when something that runs calls it, or passes it on
as a value. A function that only calls itself is reported, and so is a
group of functions that only call one another; one called only by an
unused function is not reported as well, since the unused function is
the one to look at. A call that overloading or an implicit argument
resolves uses the definition it reaches, though its name is not
written there (see "Static overloading" and "Implicits"). A `var` read
anywhere is used, in the value of its own update too
(`count := count + 1`).

**A name starting with `_` is never reported**, which is how to say
that a name is meant to go unused: `_, second = pair`,
`for _ in range(3)`, `def handler(_event: String)`. Neither is a
module's `public` name, which another module uses, nor anything in a
module of a library.

## Flags

Which warnings are reported, and which are errors, is said with the
flags GCC uses, applied in the order they are written, so a later one
wins:

| flag | what it does |
|---|---|
| `-W<name>` | turns one warning on: `-Wunused-parameter` |
| `-Wno-<name>` | turns one off: `-Wno-unused-function` |
| `-Wall` | turns every warning on |
| `-w` | turns every warning off |
| `-Werror` | makes every warning that is on an error |
| `-Werror=<name>` | makes one an error, and turns it on |
| `-Wno-error` / `-Wno-error=<name>` | makes every warning, or one, a warning again |

```
pyk -Wall prog.pyk
pyk compile -Werror -Wno-error=unused-binding prog.pyk
```

**An error stops the program.** Every warning is still printed, those
that are errors as `Error:` with the flag that made them so, and then
nothing runs and nothing is written:

```
'prog.pyk' 5:4-5:10 Error: Function 'helper' is defined but never
  used. [-Werror=unused-function]
```

The flags are taken by `pyk <file>`, `pyk compile`, `pyk repl`, `pyk
lsp`, `pyk dap` and `pyk notebook`, and `pyk --help` lists every
warning. At the REPL an entry's own top-level names are never reported,
since a later entry may use them. An editor shows warnings under the
names they are about, set with its `warnings` setting (see "Editors"
on the website), and the playground has a Warnings tab in its settings
that says each flag and what it means.
