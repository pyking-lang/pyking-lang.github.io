---
title: "Language reference"
description: "What Pyking is, how it differs from Python, and its modes at a glance."
sidebar:
  label: Language reference
  order: 8
  group: Language
---

Pyking reads like Python, and most of what a Python programmer writes
first means what they expect. Where it differs, it differs on purpose:
every block is a scope, `=` never changes a name, every program is
type-checked before it runs, and data is described by datatypes and
taken apart by `match`. The pages of this reference say what each
construct means; the syntax on its own is the Grammar page, and how
Pyking lines up with the languages it compiles to is "Pyking vs. other
languages".

## How to read this reference

Each page starts with a line saying when its constructs are available
and how they compare with Python:

> **Available:** in every module · **Compared with Python:** the same

*Available* names the `use` line a construct needs, if any (see
"Programs, modes and `use`"). *Compared with Python* is one of "the
same", "differs" (and how) or "new in Pyking".

Examples marked `pyking` are whole programs. On the website each is a
cell that runs in the page -- edit it and run it again. An example the
compiler refuses is shown with the error it gives.

## New in Pyking (not in Python)

A quick reference for readers already familiar with Python: everything
else in this document is either borrowed directly from Python or a
restriction of it, but these are genuinely new.

- **Full lexical scoping, with every block a scope**: Python scopes only
  at function boundaries, so a name bound inside an `if`/`for`/`while`
  body outlives it. In Pyking every block is a scope — an `if`/`else`
  branch, a loop body, a `case` arm, a value-form branch — so a binding
  made inside one is gone after it, and using a name that no enclosing
  scope binds is a compile-time error rather than a `NameError` at run
  time. Any binding may shadow a name already in scope (parameters,
  `for` variables, pattern variables, `def`s, `=` bindings), with one
  exception: a mutable variable may not be shadowed while it is in
  scope, which is what keeps `:=` pointing at exactly one variable.
  All of it is checked at compile time. See "Names and scoping" for the
  details.
- **Immutable-by-default bindings**: plain `=` never mutates — it's
  always a fresh binding. A name must first be declared with `var`
  before it can be updated, and only then with `:=`: `var n = 0` then
  `n := n + 1` (a plain `n = n + 1` would just re-bind `n`, not update it
  in place). Both belong to `use mutation`.
- **Features turned on with `use`**: `use mutation` at the top of a
  module turns on `var` and `:=` for that module and no other; without
  it they are a syntax error. Importing a module that uses mutation does
  not turn it on in the importer. See "Features turned on with `use`".
- **`+` joins as well as adds**: `"con" + "cat"` and `[1] + [2]` join,
  `1 + 2` adds, and every operand of a `+` is of one type -- all
  strings, all lists of one element type, or all numbers of one type.
  Nothing converts: `"n = " + 5` is a type error, where Python raises
  and JavaScript writes `"n = 5"`.
- **Boolean operators in two spellings**: `and`, `or` and `not`, as in
  Python, or `&&`, `||` and `!`, as in C, Java and JavaScript. They take
  Bools only -- there is no truthiness -- and on two Ints the words
  `and`, `or` and `not` are the bitwise operators instead. See "Boolean
  operators".
- **`^` is power, and `xor` exclusive or**: `2 ^ 10` is 1024, as in
  mathematics; Python's `**` is refused, and its `^` is spelled `xor`.
  See "Remainder and power" and "Bitwise operators".
- **`lam x. e` lambdas**: a lambda is written as in the lambda calculus,
  `lam x. x + 1` or `lam (x, y). x + y`, rather than Python's
  `lambda x: x + 1`. See "Lambdas".
- **A block on its header's own line**: any header ending in `:` may
  carry its block on that same line instead of indenting it, as long as
  what it carries is one **expression** — `def add(a, b): a + b`,
  `if n < 0: print("negative")`, `case 0: "zero"`,
  `for x in xs: print(x)`. Python allows something similar but wider:
  any *simple* statement, and `;` to write several. Pyking's line holds
  a value and nothing else, so nothing is ever hidden behind a ':' — no
  `return`, no binding, no `:=` — and the line ends there, which is why
  an `else` starts the next one. The two layouts are the same program:
  `def add(a, b): a + b` is `def add(a, b):` followed by `a + b` on its
  own indented line, down to the AST, so nothing after the parser can
  tell which was written. That is what makes a definition short enough
  to read at a glance stay on one line, and lets several such
  definitions follow one another with nothing in between.
- **Modules that export nothing by default**: a file is a module, and a
  name in it is private until `public` is written in front of it —
  the opposite of Python, where every top-level name of an imported
  module is reachable. The import forms look like Python's
  (`import m`, `import m as n`, `from m import a, b as c`), with no
  `import *`: every name a module reaches is written down. Circular
  imports are a compile-time error rather than a run-time surprise, so
  the modules of a program run in one order, each after everything it
  imports. See "Modules".
- **Submodules by dotted names**: `def mymod.foo(...)` defines `foo` in
  the submodule `mymod` of its file, reached as `hello.mymod.foo`, or
  with `from hello import mymod` or `from hello.mymod import foo`; there
  are no package folders or `__init__` files. `import hello.mymod` binds
  `mymod` rather than `hello`. See "Submodules".
- **String interpolation without an `f`**: every String may hold
  `${expr}` or `$name` -- `"Hello, $name, ${n + 1}"` -- where Python
  needs an f-string; `r"..."` turns it off, and `\$` writes a `$`. The
  parser rewrites each into `+` and `string(...)` (see "String
  interpolation").
- **`printsl`, `eprint` and `eprintsl`**: `print` on the same line, to
  standard error, or both -- what Python writes with `end=""` and
  `file=sys.stderr` (see "Printing").
- **A `Char` type, and Strings in double quotes only**: `'a'` is a
  `Char` -- one Unicode code point -- and a String is always written
  `"..."`; `'abc'` is refused. `s[i]` is a String's i-th character, and
  `for c in s` walks them. Python has no character type: its `s[i]` is a
  String of one, and either quote writes a String. See "Char literals".
- **Lowercase `true`/`false` boolean literals**: Python spells its two
  boolean values `True`/`False`; Pyking spells them lowercase, `true` and
  `false`, matching most other languages' convention rather than
  Python's. They are genuinely new *keywords* (not existing identifiers
  given a meaning), so, like `then` below, neither `true` nor `false` can
  be used as an identifier anywhere. `1 == 1` and `true` are
  interchangeable Pyking values — the only difference is that one is
  computed and the other is written directly — and every backend prints
  either one the same way; see "Booleans" below.
- **`if ... then ... else ...` expressions**: Python writes a conditional
  expression with the condition in the middle (`e1 if cond else e2`);
  Pyking puts it first, behind a new `then` keyword —
  `if cond then e1 else e2`. Semantically the two are identical (only the
  taken branch is evaluated, and `else` is mandatory), and Pyking's form
  matches Python's exactly. This is a genuinely new *keyword*, so
  `then` is reserved everywhere and can no longer be used as an
  identifier.
- **`let` expressions**: `let x = 78 in x + 1` binds a name — or takes a
  tuple apart — for one expression, its body, and is worth the body.
  Python has no counterpart (its nearest is the `:=` operator, which
  binds in the enclosing scope instead). `let` is a new keyword, so it
  is reserved everywhere. See "Let expressions".
- **`else if` instead of `elif`**: Pyking has no `elif` keyword — an
  `if` statement chains with the two ordinary keywords `else if`, e.g.
  `else if n == 0:` on its own line. It means exactly what Python's
  `elif` does, so it is neither more nor less than
  sugar for an `else:` block containing a single nested `if` statement.
- **`if`/`match` statements as bound values**: the right-hand side of an
  `=` binding may be a block-form `if` or `match` instead of an
  expression — `x = if cond:` / `x = match e:`, written over as many
  lines as the branches need. They stay *statements*; binding one just
  requires that it produce a value, which is the last expression of
  whichever branch runs, and a bound `if` must therefore have an `else`.
  Python has no statement that evaluates to a value (its `if`/`match`
  yield nothing, and its conditional *expression* holds no statements),
  so no backend can express it as one. Any bound value may also
  start on the line after its `=`, indented — a layout Python has no
  need for, since its right-hand sides are always expressions.
- **`loop`, an accumulator loop with `break` and `continue`**: Python
  has no loop that *carries a value*. `loop x = 5:` binds `x` for the
  first turn, and what the body ends in is the `x` the next turn gets,
  so a loop needs no mutable variable to add something up. A loop is
  *worth* the accumulator it stopped with -- which makes it usable as a
  bound value -- or unit where it carries none. `break` ends it and
  `continue` starts the next turn early. Python's take no operand;
  Pyking's may take one, the accumulator they leave with: `break x`
  makes the loop worth `x`, and `continue x` starts the next turn with
  `x`. See "`loop` loops" below.
- **`..`/`..name` list-pattern rest markers**: Python spells "match the
  rest of a list" as `*_`/`*name`; Pyking spells it `..`/`..name`, and it
  may appear anywhere in the pattern — start, middle, or end — not just
  once in a fixed position, e.g. `case [first, ..rest]:` or
  `case [a, b, ..middle, z]:`.
- **Datatypes**: `datatype Tree(a):` declares an algebraic data type,
  its constructors on indented lines or after its `:`, several to a
  line separated by commas, each with its fields -- positional, named,
  defaulted -- and a value is built by calling a constructor with the
  rules a call to a `def` follows (`Leaf(7, age = 100)`). Python's
  nearest is a class per constructor; a datatype is one type, its
  constructors are its only values, and `match` takes them apart. See
  "Datatypes".
- **Structs**: `struct Point(x: Int, y = 78)` is a datatype of one
  constructor, and `Point(x = 5, ..p)` builds a copy of `p` with `x`
  changed. Python's nearest is a frozen dataclass and
  `dataclasses.replace`. See "Structs". Under `use mutation`, a `mutable
  struct` is one whose fields are written in place (`p.x := 1`), shared
  by every name that holds it, as a Python object is. See "Mutable
  structs".
- **Classes and interfaces**: under `use objects`, `class Rect(width:
  Float, height: Float) implements Shape:` declares a class whose header
  is its constructor's parameters and its fields, with methods taking an
  explicit `self` and saying their types; an `interface` declares
  signatures and defaults, and a class `extends` one parent and
  `implements` any number of interfaces. Java's semantics in Python's
  spelling: objects are shared, dispatch is dynamic, `override` is
  written, and `==` calls a class's `eq`. A `public class` is another
  module's to use, implement and extend. See "Classes and interfaces"
  and "Classes across modules".
- **`copy` and `deepcopy`**: a shallow and a deep copy of any value, as
  Python's `copy.copy` and `copy.deepcopy`, built in. A deep copy keeps
  what the original shares and its cycles, copies an object as the class
  it is, and is checked at compile time. See "Copying".
- **Uppercase is for types and constructors**: every name a program
  binds starts with a lowercase letter or `_`, so a constant is
  `pi = 3.14` rather than Python's `PI = 3.14`, and an uppercase name is
  always a type or a constructor.
- **Every `match` matches every value**: a `match` that some value
  reaches no case of is refused at compile time, naming a value it
  misses, and so is a case no value can reach. Python's `match` quietly
  does nothing for a subject no case takes. See "Exhaustiveness".
- **Warnings**: a name bound and never used is reported before the
  program runs, and so is an `=` in a block that shadows a name from
  outside it and is never used -- an update written as a new binding,
  which the warning asks about. GCC's flags say which
  are reported and which stop the program: `-Wall`, `-Werror`,
  `-Wno-unused-function`. See "Warnings".
- **Arbitrary, refutable patterns in list comprehensions**:
  `[expr for pattern in seq]` accepts any Pyking pattern, not just a
  plain name or Python's simple destructuring targets. When the pattern
  is *refutable* — a literal, or a list pattern — an element that doesn't
  match is silently filtered out rather than raising an error, e.g.
  `[1 for 0 in readings]` (keeps only the elements equal to `0`) or
  `[a + b for [a, b] in rows]` (skips any row that isn't a 2-element
  list). Irrefutable patterns (names and tuple destructuring like
  `[label for (_, label) in pairs]`) simply bind, exactly as in Python.

## Modes at a glance

| Mode | Turned on by | Adds |
|---|---|---|
| functional, immutable | nothing: every module starts here | `=` bindings, functions, lambdas, lists, tuples, Maps, datatypes, structs, `match`, `loop`, `for`, `while`, Option, Result, modules |
| mutation | `use mutation` | `var` and `:=`, compound assignment, Arrays, DynArrays, MutMaps, views, `mutable struct` |
| pointers | `use mutation, pointers` | `&x`, `*p`, `*p := v`, `Ptr(T)` |
| objects | `use objects` | classes, abstract classes and interfaces |

## Feature summary

Expressions:

- Comments
- Integer literals (decimal, hexadecimal `0xff`, binary `0b101`) and
  string literals (with backslash escapes), String interpolation
  (`"${e}"`, `"$name"`) and raw Strings (`r"..."`)
- Float literals (`1.0`, `0.5`, `1e9`, `1.5e-3`) — IEEE 754 binary64,
  with a digit required on each side of the point
- Boolean literals (`true`, `false`) — Pyking extension; spelled
  lowercase, unlike Python's `True`/`False`
- Char literals (`'a'`, `'\n'`, `'👑'`): one Unicode code point, of type
  `Char`; a String is written in double quotes only — Pyking extension
  (see "Char literals")
- Variables (identifier references)
- Arithmetic operators (`+`, `-`, `*`, `/`, the remainder `%` and the
  power `^`), overloaded over `Int` and `Float`, unary minus (`-x`, and
  negative literals like `-5`), and parenthesized expressions. Nothing
  is converted implicitly: `float(n)` and `int(x)` are how the two
  numeric types meet
- Conversions `string(x)`, `int(x)`, `float(x)`, `bool(x)` and
  `char(x)` between `Int`, `Float`, `String`, `Char` and `Bool`, each
  answering a default (0, NaN, false, `'\0'`) where there is no right
  answer (see "Conversions")
- Concatenation with `+` of two strings or two lists of one type, every
  operand of a `+` being of one type (see "Concatenation")
- Comparison operators (`<`, `<=`, `>`, `>=`, `==`, `!=`), which do not
  chain
- Boolean operators `and`, `or` and `not`, also spelled `&&`, `||` and
  `!`, short-circuiting and on Bools only (see "Boolean operators")
- Bitwise operators on Ints: `&`, `|`, `xor`, `~`, `<<` and `>>`, and
  the words `and`, `or` and `not` on two Ints; `xor` on two Bools too
  (see "Bitwise operators")
- List and String indexing (`xs[i]`, `s[i]`), counting from 0; a
  String's element is a `Char` (see "Indexing")
- Type variables (`def id(x:a) -> a`) and `all` quantifiers, including
  first-class polymorphism — Pyking extension; a `def`'s type may also
  be written on a line of its own (`def id : (a) -> a`)
- Function calls, whose arguments may be **named** after the parameters
  they fill (`box(width = 4, depth = 6)`) where the callee is a `def`
  this module can see — Pyking extension (see "Named arguments")
- Qualified names (`m.f`) — Pyking extension; a public name of an
  imported module, reached through the name that module was imported
  under (see "Modules")
- List literals (`[e1, e2, ...]`)
- List comprehensions (`[expr for pattern in seq if cond ...]`), with
  Python-like support for multiple/nested `for`s and `if`s — but unlike
  Python, `pattern` can be *any* Pyking pattern (not just a plain name or
  simple destructuring target), and an element the pattern doesn't match
  is filtered out rather than raising an error
- Tuple literals (`(e1, e2, ...)`, the singleton `(e,)`, and the empty
  tuple `()`), constructible with or without the enclosing parentheses
  (`e1, e2, ...` — Python-like implicit tuples)
- If expressions (`if cond then e1 else e2`) — Pyking extension; note the
  keyword order differs from Python's `e1 if cond else e2`
- **Lambdas** (`lam x. x + 1`, `lam (x, y). x + y`) — Pyking extension;
  an expression that is a function, whose body is one expression. A lambda
  is monomorphic; `def` is how a polymorphic function is written (see
  "Lambdas")
- **Let expressions** (`let x = 78 in x + 1`, `let (a, b) = pair in a + b`)
  — Pyking extension; one binding, seen by the body alone (see "Let
  expressions")
- **Static overloading** (`def int::leq(...)`, `def float::leq(...)`) —
  Pyking extension; a qualifier makes two definitions of one base name
  distinct, and a call written without it is resolved by its arguments
  (see "Static overloading")

Statements:

- Immutable bindings (`=`), with an optional type annotation on the
  name (`x: Int = 1`), which may destructure a tuple value into
  several names at once (e.g. `a, b = 1, 2` or `(a, (b, c)) = pair`),
  and whose right-hand side may be an `if`/`match` *statement* in value
  form (`x = if cond:` / `x = match e:`) — Pyking extension
- Mutable variables (`var` and `:=`), and compound assignment
  (`count += 1`, `bits <<= 2`, `flag xor= true`), turned on with
  `use mutation` — Pyking extension
- Features turned on per module with `use` (`use mutation`) — Pyking
  extension (see "Features turned on with `use`")
- **Default parameters** (`def greet(who: String = "world"):`), used
  when a call leaves that argument out; the default is an expression
  evaluated in the scope the `def` is written in, at each call that
  omits it — Pyking extension (see "Default parameters")
- **Implicit parameters** (`def foo(x: a, implicit bar: (a) -> b)`),
  filled from the calling context by name and by type where a call
  leaves them out; `implicit` in front of a `def` or an `=` binding is
  what makes one findable — Pyking extension (see "Implicits")
- Function definitions (`def`), with optional parameter and return type
  annotations (`Int`, `Float`, `String`, `Char`, `Bool`, list types `[T]`, tuple types
  `(T1, T2, ...)` including the singleton `(T,)` and the unit type `()`,
  function types
  `(T1, T2, ...) -> T`, and nesting of any of these) — annotations are
  pretty-printed in Pyking's own syntax but erased when compiling
- `return` statements, whose operand may be an ordinary expression or
  an `if`/`match` *statement* in value form (`return if cond:` /
  `return match e:`) — Pyking extension
- **Tail position**: a function body's last statement supplies the
  function's value with no `return` written, recursively through
  `if` branches and `case` arms — Pyking extension
- `for`/`in` loops
- `while` loops
- `loop` loops, which carry an accumulator from turn to turn and are
  worth it when they stop, with `break` and `continue`, each of which
  may give the accumulator it leaves with (`break x`, `continue x`) --
  Pyking extension
- `if`/`else` statements, chained with `else if` — spelled as two
  keywords; Pyking has no `elif`
- `match`/`case` pattern matching, including tuple patterns
  (`case (a, b):`), list patterns (`case [a, ..rest]:`, or the same
  written `[a] + rest`; `"get " + rest` splits a string) and
  constructor patterns (`case Leaf(v, age = n):`) that destructure a
  tuple, a list or a datatype's value
- **Datatypes** (`datatype Shape: Circle(radius: Float) / Square(Float)`),
  with type parameters (`datatype Tree(a):`), fields that are
  positional, named or defaulted, and constructors applied with a
  call's rules; a named field is read with `.` (`p.x`) — Pyking
  extension (see "Datatypes")
- **Structs** (`struct Point(x: Int, y = 78)`), datatypes of one
  constructor, and updates (`Point(x = 5, ..p)`) — Pyking extension (see
  "Structs")
- **DynArrays** (`DynArray(T)`), arrays that grow by `push`, `pop`, `insert`,
  `remove` and `clear` — Pyking extension (see "DynArrays")
- **MutMaps** (`MutMap(K, V)`), maps that keep their keys' order, read with
  `d[k]` and written with `d[k] := v` — Pyking extension (see "MutMaps")
- **Maps** (`Map(K, V)`), immutable maps that keep their keys' order,
  made by `map(...)`; lib/map's changes answer a new one — Pyking
  extension (see "Maps")
- **One way to make and convert every collection**: `list(...)`,
  `array(...)`, `dynarray(...)`, `map(...)` and `mutmap(...)` of a list,
  of one value repeated, or of another collection, and `list_init`,
  `array_init`, `dynarray_init`, `map_init` and `mutmap_init` calling a
  function — Pyking extension (see "Making and converting collections")
- **`fmap`, `filter`, `foldl`, `foldr`, `any` and `all`** on every
  collection, an Option and a Result — Pyking extension (see "fmap and
  the folds")
- **Slices** (`xs[i:j]`, a copy) and **views** (`view(a, i, j)`, sharing
  an array's elements) — Pyking extension (see "Slices and views")
- **Option** (`Some(x)`, `None`), builtin from lib/option — Pyking
  extension (see "Option")
- **Result** (`Ok(x)`, `Error(e)`), builtin from lib/result, as Rust's
  with `Error` for `Err` — Pyking extension (see "Result")
- **Pointers** (`&x`, `*p`, `*p := v`, `Ptr(T)`) under `use mutation,
  pointers` — Pyking extension (see "Pointers")
- **Mutable structs** (`mutable struct Point(x: Int, y: Int)`), whose fields
  are written with `:=` and the compound operators and whose values are
  shared; `same(p, q)` asks whether two are one — Pyking extension (see
  "Mutable structs")
- **Classes and interfaces** under `use objects`: `class`, `abstract
  class` and `interface`, header and body fields (`var` ones with `use
  mutation`), methods with `self`, `private`, `extends`, `implements`,
  `override`, `super`, `eq` and `show`, upcasts where a type is written,
  and class patterns (`case Square(side):`, `case c: Circle:`), and
  `public` ones used, implemented and extended from other modules —
  Pyking extension (see "Classes and interfaces", "Classes across
  modules")
- Shallow and deep copies of any value, `copy(x)` and `deepcopy(x)`
  (see "Copying")
- Patterns of every kind may be combined with `|` (`case 1 | 2:`), bind
  the whole value as well with `as` (`case Node(l, r) as whole:`), and
  carry a guard (`case n if n > 0:`); every `match` matches every
  value, and every case is reachable (see "Exhaustiveness")
- Expression statements
- Output with `print`, and diagnostic output with `debug` — Pyking
  extension; `debug` writes the way `print` does, where diagnostics go,
  and a program built in release mode has none of it (see "Builtins and I/O")
- A block written on its header's own line (`def f(x): x * x`,
  `if c: print(1)`, `case 0: "zero"`) — one expression, meaning exactly
  what the indented form means
- Imports (`import m`, `import m as n`, `from m import a, b as c`) and
  exports (`public` in front of a `def`, a `def` signature line, a
  `datatype`, a `struct`, or an `=` binding) — Pyking extension; both belong to a module's top level,
  and there is no `import *` (see "Modules")

Structure:

- Left-to-right evaluation: an operator's operands and a call's
  arguments run in the order they are written -- named arguments
  included, whatever order the parameters are in -- and all of a call's
  arguments before the call (see "Evaluation order")
- Indentation-based blocks, with a line continued while a bracket is
  open (see "Lines and continuation")
- Lexical scoping, with every block a scope, free shadowing of immutable
  names, and no shadowing of a mutable one — checked statically by
  (see "Names and scoping")
- Lexical scoping with `def` *names* visible throughout their block, so
  functions may be recursive, mutually recursive, or called before they
  are written — while what a body *captures* is what is bound where the
  body stands; every other binding stays sequential, and a `def` may not
  share its name with another binding of the same block (see "Names and
  scoping")
- Statically typed: every program is type-checked, whatever is then done
  with it, and a type error stops the compile (see "Types and type inference")
- Warnings for names bound and never used, and for an `=` shadowing a
  name it was probably meant to update, with GCC's `-W` flags (see
  "Warnings")
- One file is one module, exporting only what it marks `public`, and a
  program is the acyclic graph of the modules its main file reaches —
  each running its own top level before anything that imports it (see
  "Modules")
