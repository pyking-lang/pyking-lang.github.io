---
title: "Objects"
description: "Classes, abstract classes and interfaces, under use objects, and classes across modules."
sidebar:
  parent: Language reference
  position: 10
---

> **Available:** with `use objects` · **Compared with Python:** differs --
> Java's semantics (single inheritance, interfaces, dynamic dispatch) in
> Python's spelling

## Classes and interfaces — Pyking extension

Under `use objects`, a module declares **classes**, **abstract classes**
and **interfaces**. They follow Java's semantics -- objects are shared,
a class extends one parent and implements any number of interfaces,
dispatch is dynamic -- in Python's spelling, with `self` written. The
design, with the choices it made and the ones it did not, is
`design/plan-objects.md`.

```pyking
use objects

interface Shape:
    def area(self) -> Float
    def name(self) -> String
    def describe(self) -> String:
        self.name() + " of area " + string(self.area())

class Rect(width: Float, height: Float) implements Shape:
    override def area(self) -> Float:
        self.width * self.height
    override def name(self) -> String:
        "rectangle"

class Square(side: Float) extends Rect(side, side):
    override def name(self) -> String:
        "square"

shapes: [Shape] = [Rect(2.0, 3.0), Square(2.0)]
for s in shapes:
    print(s.describe())
print(Square(2.0))
```

prints `rectangle of area 6.0`, `square of area 4.0` and `Square(2.0)`.

**The gate.** Declaring a class or an interface needs `use objects`; a
module without it may still make objects of another module's classes,
call their methods and match them. A `var` field needs `use mutation` in
the module declaring it, and writing one (`o.f := v`) in the module
writing it.

**Fields and the constructor.** A class's header lists its fields, as a
struct's does, and they are its constructor's parameters, with defaults
and named arguments: `Account("ada", limit = 100.0)`. Every field says
its type, unless a literal default says it. Fields declared in the body,
`name: T = value` or `var name: T = value`, are set up from that value,
which may use the header's parameters by name -- not `self`, so nothing
calls a method on a half-made object. An object is set up in a fixed
order: its parent's part first, then its own header fields, then its
body fields in the order written. A class with nothing to declare under
its header has no `:`: `class Tag(name: String)`. A field never shares a
name with a method, nor with a field of a class above it. A constructor
is not a value: `Tag` alone is `Tag()` where every field has a default,
and is refused otherwise.

**Methods.** A method is a `def` in the class body whose first parameter
is `self`, written without a type; every other parameter says its type,
and its result is written after `->`, or is `()` where nothing is
written. A method reaches its object's fields and methods only through
`self` (`self.width`, `self.area()`). It is called with `obj.m(args)`,
named and default arguments as for any `def`; defaults are written where
a method is first declared, never on an override. `obj.m` without a call
is a function closed over the object, worked out once. A body ending in
a value it does not return is fine in a method answering `()`.
No member is named as Python names its special ones, `__del__` or
`__init__`: Python would give such a method or field a meaning of its
own there alone (`__del__` would run when the object is collected), so
the name is refused, with `eq` or `show` named where one of those is
what was meant. A struct's or a datatype's field is refused such a name
too.

**Objects are references.** Every object is shared by each name, element
and field holding it, as in Java and Python; `same(a, b)` asks whether
two names hold one object. An object with no `var` field never changes. `copy(o)` and `deepcopy(o)` make a new object of the class `o` is (see
"Copying").

**Equality and printing.** `a == b` and `a != b` call the class's `eq`,
written `def eq(self, other: C) -> Bool`, and are refused where it has
none -- `same` is the identity test. An object prints as its class's
name and its header's fields, `Square(2.0)`, or as its `show` says,
written `def show(self) -> String`: in `print` and `string`, inside a
printed list included. A header field written `private` prints as `_`:
`Account("ada", _)`. The REPL's echo of a value and the debugger's
Variables view show the header form, every field in it, since neither
runs a method to show one and both are for looking inside. Objects have
no order: `<` is refused.

**`private`.** A field or method written `private` is reached only from
the methods of the class declaring it, on any object of that class --
read, written, matched by a pattern, or given to the constructor;
classes below it do not see it, and none of them may declare a member of
its name. A header field written `private` is a parameter of the
constructor only the class's own methods give: everywhere else -- other
functions, other modules, a class below it and its `extends` -- it takes
its default, so it has one, and it comes after the header's other
fields. That is how a class keeps a promise about what it holds: every
object is made by its own methods.

```pyking
use objects

# Every group is made empty, `Group()`, and grows by `add`, so no name
# is in one twice.
class Group(private names: [String] = []):
    def add(self, name: String) -> Group:
        if any(lam n. n == name, self.names) then self else Group(self.names + [name])
    def size(self) -> Int:
        len(self.names)

g = Group().add("ada").add("bo").add("ada")
print(g.size(), g)    # 2 Group(_)
```

Outside its methods, giving it is refused, by position or by name:

```pyking error
use objects

class Group(private names: [String] = [])

forged = Group(["ada", "ada"])
```

A named argument that is the parameter's own default -- the literal its
header writes -- chooses nothing, and is not refused; that is how the
program `pyk compile -t pyking` prints writes every construction.

**Interfaces.** An interface declares method signatures and, where it
gives one, a default body; it has no fields, may `extends` other
interfaces and may have type parameters (`interface Source(a):`, which a
class implements as `implements Source(Int)`). An interface is a type --
a parameter, an element, a field -- and is never made.

**Inheritance.** `extends P(args)` names one parent class and what its
constructor is given; the arguments may use the header's parameters. A
header parameter with the name and type of an inherited field only
passes it on, so `extends` gives it to the parent as it is, in the place
of that field: `class B(m: Int, n: Int) extends A(n)`. Written anywhere
else -- `extends A(5)`, `extends A(n + 1)` -- the value given for it
would be dropped, and it is refused. A method replacing one a class or interface above has is
written `override def`, with the same parameters, by name and type, and
the same result; `override` where nothing is replaced is refused, and so
is replacing without it. `super.m(args)` calls the body the class
inherited: its parent chain's first, then an interface's default. A class
inheriting defaults of one name from two interfaces overrides it.

**Abstract classes.** An `abstract class` may declare `abstract def`s,
which have no body, and is never made; a class that can be made gives
every method a body, its own or one it inherits.

**Where an object is seen as a supertype.** A `Square` stands where a
`Shape` is written -- an annotated binding, a declared parameter or
result, a field, a `var` of a declared type -- and inside a list, a
tuple, an `if` or a datatype's constructor written there, each part on
its own: a function declared to return `Result(Shape, String)` may end
in `Ok(Square(2.0))`, or `return` it. Nowhere else is a type guessed: `[Rect(1.0, 1.0), Circle(1.0)]` with nothing written is refused,
with where to write the type. Lists do not take subtypes: a `[Square]`
is not a `[Shape]`.

**A method call needs the class.** `x.m()` and `x.f` are checked where
the type of `x` is known there; a parameter with no type a body calls a
method on is refused with "annotate it", as a struct's field is.

**Class patterns.** `case Square(side):` matches an object of that class
or one below it, its header's fields matched as a struct's are, with `_`
for a `private` one outside the methods of the class declaring it; `case
c: Circle:` binds the object at its class or interface. A `match` on an
interface or a class others extend needs a `case _` (or a case for the
type itself), since there may be other classes:

```pyking
use objects

interface Pet:
    def name(self) -> String

class Dog(called: String, age: Int) implements Pet:
    override def name(self) -> String:
        self.called

class Cat(called: String) implements Pet:
    override def name(self) -> String:
        self.called

def describe(p: Pet) -> String:
    match p:
        case Dog(n, age) if age > 10:
            "an old dog, " + n
        case c: Cat:
            "a cat called " + c.name()
        case _:
            p.name()

print(describe(Dog("Rex", 12)))   # an old dog, Rex
print(describe(Dog("Fido", 3)))   # Fido
print(describe(Cat("Tom")))       # a cat called Tom
```

**Targets.** Every target compiles them, each in its own idiom:

| Target | A class is |
|---|---|
| Python | a class (an `abc.ABC` for an interface or abstract class), its methods defs named for it at the top level and given as attributes |
| JavaScript, web | an ES class, an interface's defaults copied into the classes without them |
| Java | a nested class, an interface a Java interface with `default` methods |
| OCaml | a class type, objects immediate objects built by a function, each method a function taking `self` |
| C | a struct starting with its class descriptor, a method table per class, one slot per method name of the program |
| interpreter | a value with its class's name and fields; methods kept by name |

A generic class is not compiled to C, which would need one copy of it per
type, and OCaml cannot write a generic class whose method gives the class
at other type arguments than its own (`swap` answering `Pair(b, a)`):
both are refused with a message saying so.

## Classes across modules — Pyking extension

`public class`, `public abstract class` and `public interface` export a
class or an interface. Another module may then use it, implement it and
extend it, as the module declaring it does:

```pyking norun
# shapes.pyk
use objects, mutation

public interface Shape:
    def area(self) -> Int
    def name(self) -> String
    def describe(self) -> String:
        self.name() + " of area " + string(self.area())

public class Rect(width: Int, height: Int = 1) implements Shape:
    private var moves: Int = 0
    override def area(self) -> Int:
        self.width * self.height
    override def name(self) -> String:
        "rectangle"
    def grow(self, by: Int = 2) -> ():
        self.moves := self.moves + by
```

```pyking norun
# main.pyk
use objects
import shapes
from shapes import Rect

class Circle(r: Int) implements shapes.Shape:
    override def area(self) -> Int:
        3 * self.r * self.r
    override def name(self) -> String:
        "circle"

class Square(side: Int) extends Rect(side, side):
    override def name(self) -> String:
        "square, a " + super.name()

all: [shapes.Shape] = [Rect(2), shapes.Rect(3, 4), Circle(1), Square(2)]
for s in all:
    print(s.describe())
match all[3]:
    case q: Square: print("a square of side", q.side)
    case _: print("something else")
```

prints `rectangle of area 2`, `rectangle of area 12`, `circle of area
3`, `square, a rectangle of area 4` and `a square of side 2`.

**What `public` exports.** The class or interface, its constructor (a
class's, not an abstract class's or an interface's), and every member
that is not `private`. A `private` member stays reachable only from the
methods of the class declaring it, wherever the object is, and a class
in another module extending it never declares a member of that name. So
another module makes the class without its `private` header fields --
`tally.Tally("a")` for `class Tally(label: String, private counts: [Int]
= [])` -- and a class pattern there writes `_` in their places.

**How it is named.** As a datatype of another module is: `shapes.Rect`
through `import shapes`, the alias through `import shapes as sh`
(`sh.Rect`), and `Rect` through `from shapes import Rect`. That holds in
a type, a constructor call, a class pattern (`case shapes.Rect(w, h)`,
`case r: shapes.Rect`), and after `extends` and `implements`.

**Everything else is as within one module.** Defaults and named
arguments of constructors and methods work from the importing module,
an override takes its defaults from where the method is first declared,
`super.m(...)` reaches a body in another module, and an interface's
default bodies are inherited. `==` calls `eq`, printing calls `show`,
and `copy` and `deepcopy` copy an object as its own class. A class of
another module is open: any module may extend it or implement it, so a
`match` on one needs a `case _` unless a case covers the class itself.

**What a public class may name.** A module importing a class has to be
able to name everything it is. So a public class builds only on public
classes and interfaces, and its members that are not `private` name
only public classes and datatypes. A public function, binding or
datatype naming a class follows the same rule:

```pyking error
use objects

interface Sized:
    def size(self) -> Int

public class Box(n: Int) implements Sized:
    override def size(self) -> Int: self.n
```

```
'box.pyk' 6:0-7:42 Type error: 'Box' is public, and builds on 'Sized',
  which is not: make 'Sized' public too, so that a module using 'Box'
  can see everything it is
```

**One class name per module.** Two modules may each declare a class of
the same name, private or public: each module's code means its own,
and another module names a public one through its module.

**Targets.** Every target compiles classes across modules:

| Target | Another module's class is |
|---|---|
| Python, JavaScript | its module's class, `shapes.Rect`, extended and implemented as its own |
| Java | a public nested class of its module's class, `Shapes.Rect`; a public class is not `final` |
| OCaml | its module's class type and functions, `Shapes.rect` and `Shapes.rect__new`, which its `.mli` declares; a class pattern tests one of its exceptions, since `exn` is the one extensible type every module shares |
| C | its module's descriptor and object struct, which its header declares; every module numbers an object's method table the same way |
| interpreter | its class by the name `module.Name`, so two modules' classes of one name are two classes |
