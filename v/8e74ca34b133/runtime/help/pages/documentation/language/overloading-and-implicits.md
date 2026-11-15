---
title: "Overloading and implicits"
description: "Static overloading and implicit parameters."
sidebar:
  parent: Language reference
  position: 12
---

> **Available:** in every module · **Compared with Python:** new in Pyking

Two features let one name stand for several functions, both settled at
compile time: static overloading, where the types at a call pick the
definition, and implicit parameters, which the compiler fills in from
the definitions in scope. Both are advanced; a program need use neither.

## Static overloading — Pyking extension

Two definitions may share a base name if a **qualifier** tells them
apart:

```pyking
def int::twice(x: Int) -> Int: x * 2
def string::twice(x: String) -> String: x + x

print(twice(21), twice("ab"))       # 42 abab
print(int::twice(3))                # 6
```

`int` and `float` are not special: the qualifier is part of the name and
nothing else, and `wow::twice` works exactly as well. What it does is
make the names unique, so both definitions may be written in one block.

A call may write the whole name or leave the qualifier out. Leaving it
out is resolved by the **arguments**: the one definition whose
parameters they fit is the one meant. Nothing else takes part — not the
result type, and not what the call is used for.

```pyking
def a::join(x: Int, y: Int) -> Int: x + y
def b::join(x: String, y: String) -> String: x + y

print(join(2, 3), join("hi", "!"))  # 5 hi!
```

Three rules follow, and each is refused where it is written:

- **A `::` name belongs to a `def` that takes at least one argument.**
  A binding, a `var`, a parameter, a loop variable, a pattern capture,
  a module name and an import alias may not carry one, and neither may
  a `def` with no parameters — there would be nothing to resolve it by.
- **A plain definition is not a member of any set.** If a block binds
  `twice` with no qualifier, `twice(...)` means that one and is a type
  error if it does not fit.
- **A builtin's name is never part of a set.** `string(1)` is the builtin
  whatever `q::string` definitions are in scope. The exceptions are the
  collection builtins, which *are* sets: `array` (`list::array`,
  `fill::array`, and a conversion per collection, `dynarray::array`,
  ...), `array_init`, `dynarray`, `mutmap` and `map` (see "Making and
  converting collections"), and the ones written in lib/prelude,
  `fmap`, `filter`, `foldl`, `foldr`, `any`, `all`, `list`, `list_init`,
  `dynarray_init`, `map_init` and `mutmap_init` (see "fmap and the
  folds"), whose members a module calling one has under their `::`
  names. Members of one arity are told apart by their arguments' types.

Resolution needs the argument types to be decided. Inside a function
whose parameter could be anything, they are not, and the call is
refused with the way out named:

```pyking
# def both(x): (twice(x), twice(x))
#   -- error: nothing here decides which 'twice' is meant. Annotate it,
#      or take the definition as an implicit parameter
```

Two definitions that both fit is an error too. There is no ordering
between them: write the one that is meant. Where a lambda is among the
arguments, its body may decide: `list.sort_on(lam p. p.age, people)`
fits every key type until the body says it gives an Int, so a
definition the lambda's body does not check against is set aside.

**A default parameter counts.** It lets a definition take fewer
arguments, so it is part of what says whether a call could mean that
definition — and two definitions taking one call, where one of them
needs a default, is refused:

```pyking
def b::my2(x: Bool, y: Int) -> Int: y + 100
def c::my2(x: Bool, y: Int, z: Int = 1000) -> Int: y + z

# print(my2(true, 1))
#   -- error: 'b::my2' takes them as written and 'c::my2' takes them
#      with its default for 'z'
```

Where only one definition can take the call that way, it is the one
meant and its default is used. A **named argument** may not be written
on an overloaded call at all: putting one in its parameter's place
needs to know which definition is meant, which the arguments have not
said yet.

## Implicits — Pyking extension

A parameter written `implicit` may be left out at a call, and is filled
from the calling context by **name** and by **type**:

```pyking
def foo(x: a, implicit bar: (a) -> b) -> (b, b):
    (bar(x), bar(x))

def my1() -> ():
    implicit def bar(z: Int) -> String: string(z) + "!"
    print(foo(78))                  # ("78!", "78!")

def my2() -> ():
    implicit def bar(z: String) -> String: z + "!"
    print(foo("hi"))                # ("hi!", "hi!")
```

`foo` is written once and means two things, because the implicit `bar`
it asks for is a different definition in each scope. The name matters:
`implicit bar` asks for something *called* `bar`, so the parameter's
name is part of `foo`'s type —

```
foo : (a, implicit bar: (a) -> b) -> (b, b)
```

— and that is what `-t pyking` prints and what a written annotation has
to say.

**Only an `implicit` definition is ever resolved to.** A binding of the
right name and the right type that was not written `implicit` is
invisible to the search:

```pyking error
def my3() -> ():
    def bar(z: Int) -> String: string(z)
    print(foo(1))       # error: there is a 'bar', but it is not
                        #        declared 'implicit'
```

`implicit` goes in front of a `def` or an `=` binding of one name, and
in front of `def` it follows `public`. Any value may be implicit, not
only a function:

```pyking
implicit width = 4

def pad(text: String, implicit width: Int) -> String:
    loop out = text while len(out) < width:
        out + "."

print(pad("a"))         # a...
print(pad("a", 8))      # a....... -- written out, which always works
```

Implicit parameters come after every ordinary one, each needs its type
written, and none may have a default value: an omitted implicit
argument is resolved rather than defaulted. A call writes out every
implicit argument or none of them, by position or by the parameter's
name (`pad("a", width = 8)`).

**A definition with implicit parameters, or one that is itself
implicit, writes its whole type down** — resolving is a question about
types, so there has to be a type to ask it of.

**An implicit obligation does not cross a `def`.** If a body calls
something whose type carries an implicit `bar` and that body has no
implicit `bar` in scope, it is an error there, and the fix is to write
`implicit bar` among its own parameters. What the body's *caller* has
in scope does not reach inside it.

What does work — and is why the parameter is part of the type — is
passing such a function as a value and calling it elsewhere. The
resolution happens where the **call** is written:

```pyking norun
def apply_twice(f: (Int, implicit bar: (Int) -> String) -> (String, String),
                n: Int) -> (String, String):
    implicit def bar(z: Int) -> String: string(z * 2)
    f(n)

print(apply_twice(foo, 5))          # ("10", "10")
```

An implicit may be resolved to a definition that takes implicits of its
own, and those are discharged in turn, in the scope of the call. A
chain that does not stop is cut at a fixed depth and reported.

**A function carrying an implicit parameter may be passed where an
ordinary function is wanted**, and its implicit is then resolved where
it is *passed*:

```pyking
implicit my = 10

def bar(a, f):                  # `f` is an ordinary (Int) -> a here:
    f(a + 1)                    # a body cannot discover an implicit

def foo(x: Int, implicit my: Int) -> Int: x + my

print(bar(7, foo))              # 18 -- foo's `my` is the 10 above
```

Writing the implicit into `f`'s own type says the other thing: resolve
it in `bar`'s body, against whatever is in scope there.

```pyking
def bar(a, f: (Int, implicit my: Int) -> Int):
    implicit my = 7
    f(a + 1)                    # 15
```

That is the whole of what the annotation decides, and it is why an
implicit parameter is part of a function's type.

The adaptation goes both ways, so the annotated `f` above still accepts
a function that asks for nothing — `bar(2, lam x. x + 1)` works, and the
lambda simply never sees the implicit. A function that needs less
stands wherever one that needs more is wanted.

The two features meet: an implicit definition may be overloaded, and
the search considers every qualifier.

```pyking
implicit def int::leq(x: Int, y: Int) -> Bool: x <= y
implicit def float::leq(x: Float, y: Float) -> Bool: x <= y

implicit def list::leq(xs: [a], ys: [a],
                       implicit leq: (a, a) -> Bool) -> Bool:
    match (xs, ys):
        case ([x] + xrest, [y] + yrest):
            if leq(x, y):
                list::leq(xrest, yrest)
            else:
                false
        case ([], []): true
        case (_, _): false

print(leq(88, 100), leq(79.12, 18.2), leq([171, 10], [188]))
# true false false
```

## Overloading and implicits, resolved

Two more things the checker settles, and the only two where it decides
what a *name* means rather than what a type is (see "Static
overloading" and "Implicits").

**An overloaded call is resolved by its arguments.** They are checked
once, and each `q::name` definition in scope is then tried against what
they turned out to be. Exactly one fitting resolves the call; none and
several are both errors, and an argument type nothing has decided fits
every candidate, which is reported as such. The test is unification, so
choosing a candidate may be what *decides* an argument's type —
`leq([171, 10], [188])` picks `list::leq` and settles the element type
by doing so.

**An implicit parameter is resolved by name and type.** Every
`implicit` binding in scope whose base name is the parameter's is
tried, with its own implicit parameters set aside as obligations to
discharge in turn, in the scope of the call. A binding that was not
written `implicit` is never considered. Exactly one fit resolves it.

Both are questions about the program's *text*, settled once, where the
call is written. Nothing is deferred to a caller and nothing is decided
at run time: a program that compiles has one definition per call site,
chosen before anything runs.
