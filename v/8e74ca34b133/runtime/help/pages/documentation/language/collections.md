---
title: "Collections"
description: "Lists, tuples, Maps, Arrays, DynArrays, MutMaps, slices and views, and the folds."
sidebar:
  parent: Language reference
  position: 8
---

> **Available:** lists, tuples and Maps in every module; Arrays,
> DynArrays, MutMaps and views with `use mutation` · **Compared with
> Python:** differs -- lists are immutable, and each collection has one
> element type

| Collection | Changes in place | Needs |
|---|---|---|
| list `[T]` | no | nothing |
| tuple `(A, B, …)` | no | nothing |
| `Map(K, V)` | no | nothing |
| `Array(T)` | its elements | `use mutation` |
| `DynArray(T)` | its elements and its length | `use mutation` |
| `MutMap(K, V)` | its entries | `use mutation` |
| view `Slice(T)` | the elements it shares | `use mutation` |

Every collection is made and converted the same way (`list(...)`,
`array(...)`, ...), and `fmap`, `filter`, `foldl`, `foldr`, `any` and
`all` work on all of them.

## List literals

`[e1, e2, ...]` builds a list from a comma-separated list of expressions,
using the same syntax as call arguments.

```pyking
use mutation

values = [1, 2, 3]
var total = 0
for v in values:
    total := total + v
print(values, total)
```

## List comprehensions

`[expr for pattern in seq if cond ...]` builds a list by running `expr`
once for every element of `seq` that matches `pattern` (with any `if`
conditions also holding), in order. Multiple `for`/`if` clauses can be
mixed freely, just like Python's own comprehensions, including nested
`for`s over multiple sequences and a comprehension nested inside another
(the `expr`, a sequence, or a condition can itself be a comprehension).

```python
values = [1, 2, 3, 4, 5]
doubled = [x * 2 for x in values if x > 2]
print(doubled)

rows = [1, 2, 3]
cols = [10, 20]
products = [r * c for r in rows for c in cols]
print(products)

table = [[r * c for c in cols] for r in rows]
print(table)
```

Unlike Python, `pattern` is a full Pyking pattern, not just a plain name
or a simple destructuring target — it can be a literal, `_`, a tuple
pattern, or a list pattern (see "list patterns" below), and nests
arbitrarily.

A *refutable* pattern — a literal, or a list pattern — may reject a value,
and an element it doesn't match is filtered out of the result rather than
raising an error:

```python
readings = [0, 5, 0, 8, 3]
only_zero = [1 for 0 in readings]
print(only_zero)

rows = [[1, 2], [3], [4, 5], []]
pair_sums = [a + b for [a, b] in rows]
print(pair_sums)
```

`0 in readings` above only produces one `1` per element that literally
equals `0` (filtering out everything else); `[a, b] in rows` only matches
sub-lists of exactly two elements, filtering out `[3]` and `[]`.

An *irrefutable* pattern — a plain name, `_`, or a tuple destructuring
built from those — always binds and never filters, matching how the same
target behaves in a Python comprehension. A tuple pattern is a fixed-arity
destructuring (like its tuple type `(T1, ..., Tn)`), so a wrong-arity
value is a shape error that surfaces at runtime the same way Python's own
unpacking would, rather than being silently skipped:

```python
pairs = [(1, "a"), (2, "b"), (3, "c")]
labels = [label for (_, label) in pairs]
print(labels)
```

A refutable pattern therefore does two things at once — it *filters* and
it *binds* — while an irrefutable one only binds. That is a statement
about the language; how a backend achieves it is its own business, and
the Python target's encoding is described in
docs/target_python.md.

`tests/list_comprehension_pattern_helper.pyk` exercises every refutable
case; the other `list_comprehension_*` tests use irrefutable patterns.

## Tuple literals

`(e1, e2, ...)` builds a tuple, corresponding directly to a Python tuple.
Three shapes need explicit parentheses: `()` is the empty tuple (also
called Unit), `(e,)` is a singleton (the trailing comma is required — a
plain `(e)` is just a parenthesized `e`, not a tuple), and any 2+-element
tuple may optionally end in a trailing comma, `(e1, e2,)`. A 2+-element
tuple can *also* be written without the enclosing parentheses at all,
Python-style: `e1, e2, ...` — but this bare form requires at least two
elements and never allows a trailing comma (see the notes on the Grammar
for why). Tuples nest arbitrarily, with list literals or with themselves.

```python
unit = ()
single = (1,)
pair = (1, 2)
bare_pair = 1, 2
nested = (1, (2, 3), [4, 5])

print(unit, single, pair, bare_pair, nested)
```

## Maps (`Map(K, V)`) — Pyking extension

A **Map** maps keys to values as a MutMap does, and remembers the order
its keys were put in, but it is a value that never changes, like a list:
making one needs no `use mutation`, and a change answers a new Map,
leaving the old one as it was. Its type is `Map(K, V)`.

```pyking
import map

ages = map([("ann", 31), ("bo", 5)])
older = map.insert(ages, "cy", 40)
print(ages, older["cy"], get(ages, "zed", 0), len(older))
# map([("ann", 31), ("bo", 5)]) 40 0 3
```

**Making one.** `map()` makes one with no entries, whose types its use
or an annotation decides, `map(pairs)` one from a list of `(key,
value)` pairs -- a key written twice keeps its first place and its last
value -- and `map(d)` one holding a MutMap's entries as they are now
(see "Making and converting collections").

**Reading** is a MutMap's: `m[k]` (a runtime error, `the Map has no key
"zed"`, where there is none), `get(m, k, default)`, `has(m, k)`,
`keys(m)`, `values(m)`, `items(m)` and `len(m)`, and `for k in m` and a
comprehension walk the keys in order. A Map is never written: `m[k] :=
v`, `remove`, `discard` and `clear` are refused, each saying what makes
a new Map instead.

**Changing one** is lib/map's: `map.insert(m, k, v)`, `map.remove(m, k)`,
`map.insert_with(f, m, k, v)`, `map.adjust(f, m, k)` and `map.alter(f,
m, k)`, and `union`, `intersection`, `difference`, `map_with_key`,
`filter_with_key`, `partition`, `lookup` and `fold_with_key`. A new key
goes at the end, a key already there keeps its place, and one taken out
and put back goes to the end, as in a MutMap. Each change copies the
Map, so it takes time in proportion to its size: a Map built one entry
at a time is better built as a list of pairs, or as a MutMap, and made
a Map at the end.

**Keys** are a MutMap's: Int, Char, String, Bool, (), and tuples, lists,
structs and datatypes of those -- not a Float, a function, anything that
changes, or a Map.

**Equality and printing.** `==` and `!=` compare two Maps by their
entries, in whatever order: the same keys, each with an equal value,
which is Python's rule for a dict. A Map prints as what makes one,
`map([("ann", 31)])`, in its order -- so two equal Maps may print
differently. A Map has no identity for `same` to ask about, and no
order for `<`.

## Arrays (`Array(T)`) — Pyking extension

An **array** is a fixed number of elements of one type, written in
place and shared by every name that holds it. Its type is `Array(T)`,
apart from the list type `[T]`: a list is a value that is never
changed, an array is a store that is. Making one and writing to one
need `use mutation`; reading, passing, returning and holding one do
not.

**Making one.** An array is made by `array(...)` or `array_init(...)`
alone -- `var` before a list still makes a `var` holding a list. Each is
a builtin overload set (see "Static overloading") of two forms, told
apart by how many arguments they take:

| call | form | makes |
|---|---|---|
| `array(xs)` | `list::array` | the elements of the list `xs` |
| `array(c)` | `dynarray::array`, ... | the elements of another collection: an array, a DynArray, a view, a String's Chars, a Map's or a MutMap's (key, value) pairs (see "Making and converting collections") |
| `array(n, v)` | `fill::array` | `n` elements, each the one value `v`, worked out once |
| `array_init(n, f)`, `f: (Int) -> T` | `init::array_init` | element `i` is `f(i)` |
| `array_init(n, seed, f)`, `f: (S) -> (T, S)` | `unfold::array_init` | each element and the next `seed` from `f` |

```pyking
use mutation

primes = array([2, 3, 5])
zeros = array(4, 0)
squares = array_init(5, lam i. i * i)
fibs = array_init(8, (0, 1), lam p. let (a, b) = p in (a, (b, a + b)))
print(primes, zeros, squares, fibs)
# array([2, 3, 5]) array([0, 0, 0, 0]) array([0, 1, 4, 9, 16]) array([0, 1, 1, 2, 3, 5, 8, 13])
```

- **`array` fills, `array_init` generates.** `array(3, f)` with a
  function `f` is an array of three copies of `f`; `array_init(3, f)`
  calls it for each element. Since the two names take different
  arguments, no call is ever ambiguous, whatever is known of its
  arguments' types.
- **`array_init` calls `f` in index order**, once per element, and
  never when `n` is 0; the unfolding form drops the last `seed`. A
  negative `n` is a runtime error (`an array's size is never negative`)
  on `c23-gc` and every target but plain C, and a size is checked before
  anything is allocated.
- **An empty array's element type is decided by its use**, or
  written, `empty: Array(Int) = array([])`. One whose element type
  nothing decides has the type `Array(a)`, as `xs = []` has `[a]`:
  `empty = array([])` followed by `print(empty)` is a whole program, and
  a hover or the REPL shows `Array(a)`. Writing that type is allowed
  too, `empty: Array(a) = array([])`: a type variable no enclosing
  `def` holds says the value does not decide that type, so `x: a = 5`,
  whose value does, is refused. An array is still one type: the first
  use that decides it decides it everywhere, and a second use at
  another type is refused. A backend that has to name the element type
  (C, Java, OCaml) is given `Int`, which no program can tell apart,
  since an array of no decided type holds no element to read.

**Reading and writing.** `a[i]` reads element `i`, counting from 0, and
`a[i] := v` writes it; the compound forms (`a[i] += 1`) work on an
element as on a `var`. `len(a)` is the number of elements, fixed when it
was made: an array never grows or shrinks.

```pyking
use mutation

a = array([5, 1, 2])
a[0] := a[1] + a[2]
a[2] *= 10
print(a, len(a))        # array([3, 1, 20]) 3
```

- **Every index is checked, on every target but plain C.** One outside
  the array -- a negative one too, since nothing counts from the end --
  is a runtime error, `the index 5 is outside an array of 2 elements`,
  where C, Java and Python would each do something different. Plain C
  (`c89`, `c99`, `c23`) is the exception, kept as plain C for teaching:
  `a[i]` is C's own `a.items[i]`, checked by nothing, and an index
  outside the array is undefined there, as it is in C. `c23-gc` checks
  every index, as the other targets do.
- **An element write runs in a fixed order.** `a[i] := e` works out `a`,
  then `i`, then checks `i` -- an index outside the array fails before
  `e` runs -- then works out `e`, and writes into the array `a` was. A
  compound form reads the element between the check and `e`. So if `e`
  writes `a[i]` itself, `a[i] += e` adds to what was there before `e`
  ran, and if `e` makes `a` name another array, the write still goes to
  the first one.
- **`=` does not write.** `a[i] = v` is refused with "did you mean
  `a[i] := v`?", and a list's or a String's element cannot be written at
  all.
- **The costs.** Reading, writing and `len` take constant time; making,
  copying and filling one take time in proportion to its length. Growing
  a list with `xs := xs + [x]` copies it each time, so a loop doing that
  is quadratic: an array made by `array_init(n, f)`, or a comprehension,
  is linear.

**Sharing.** `b = a` makes `b` a second name for the same array, and a
call `f(a)` gives `f` the same array, so a write through either is seen
through both -- Java's and Python's rule. `same(a, b)` asks whether two
names hold one array. `==` compares no arrays: whether two hold the
same elements is `array.equal(a, b)` from `lib/array`, which says so
when `==` is tried.

```pyking
use mutation

def zero_first(xs: Array(Int)) -> ():
    xs[0] := 0

a = array([5, 6])
b = a
zero_first(b)
print(a, same(a, b), same(a, array([0, 6])))   # array([0, 6]) true false
```

**Arrays of arrays** are a matrix, indexed `m[r][c]`. `array(n, v)` with
an array `v` stores one row `n` times -- the classic trap -- and the
`shared-fill` warning says so (see "Warnings"); `array_init` makes a
new row each time:

```pyking
use mutation

grid = array_init(3, lam _. array(3, 0))
grid[0][0] := 1
print(grid)      # array([array([1, 0, 0]), array([0, 0, 0]), array([0, 0, 0])])
```

**Walking one.** `for x in a` runs `len(a)` turns and reads each
element as its turn is reached, so a write ahead of the loop is seen. A
comprehension over an array makes a list, and a `loop` may carry an
array as its accumulator. There are no array patterns: a `match` takes
an array as a whole, with a name or `_`.

**Printing.** An array prints as what makes one, `array([1, 2])`, so it
is told from the list `[1, 2]`, and nested arrays print nested.
`string(a)` is the same text.

**Types.** `Array(T)` is a type like any datatype's, and it is
*invariant*: an `Array(Int)` is never an `Array(a)` of some other `a`.
Only `def`s are polymorphic, so `def first(xs: Array(a)) -> a` serves
every element type, while a binding's array has one.

The rest -- copying, filling, comparing, sorting, joining -- is the
library `lib/array` (see "Modules", and its help page): `copy`,
`to_list`, `fill`, `swap`, `reverse`, `concat`, `resize`, `equal` and
`sort`, which is stable and orders Floats with NaN last and Strings by
code point, alike on every target; `sort_by`, `sort_on` and
`map_in_place`, which change the array too; and lib/list's searching
and counting functions over an array (`first`, `find`, `count`,
`contains`, `maximum`, `sum`, `sorted`, `reversed`, ...).

## DynArrays (`DynArray(T)`) — Pyking extension

A **DynArray** is an array that grows: its elements are read and written by
index as an array's are, and it is shared by every name that holds it,
but `push`, `pop`, `insert`, `remove` and `clear` change how many it
has. It is how a collection is built one element at a time in linear
time. Its type is `DynArray(T)`. Making and changing one need `use
mutation`; reading, passing, returning and holding one do not.

```pyking
use mutation

squares: DynArray(Int) = dynarray()
for i in range(5):
    push(squares, i * i)
print(squares, len(squares), squares[4])      # dynarray([0, 1, 4, 9, 16]) 5 16
```

**Making one.** `dynarray()` makes one with no elements, whose element type
its use or an annotation decides, `dynarray(xs)` one holding a list's
elements -- or another collection's (see "Making and converting
collections") -- and `dynarray(n, v)` one of `n` copies of `v`;
`dynarray_init(n, f)` and `dynarray_init(n, seed, f)` generate one as
`array_init` does.

**Growing and shrinking.** Five builtins change a DynArray:

| call | does | answers |
|---|---|---|
| `push(v, x)` | adds `x` at the end | `()` |
| `pop(v)` | takes the last element out | it |
| `insert(v, i, x)` | puts `x` before index `i`, moving the elements from `i` on up; `0 <= i <= len(v)` | `()` |
| `remove(v, i)` | takes the element at `i` out, moving the ones after it down | it |
| `clear(v)` | removes every element | `()` |

These are functions, called with the DynArray as the first argument:
`push(v, x)`, not `v.push(x)`. A DynArray, like an array, a MutMap, a
list or a String, has no methods or fields, and `v.push(x)` is refused
with the call to write instead.

`pop` of an empty DynArray, and an index outside one, are runtime errors on
every target but plain C. `push` and `pop` take constant time on
average, `insert` and `remove` time in proportion to the elements they
move.

**Reading and writing** are an array's: `v[i]`, `v[i] := x`, `v[i] += 1`,
`len(v)`, the index checked against the length the DynArray has *now*. A
`for` over a DynArray reads each element as it is reached and goes on while
the index is below the DynArray's length at that turn, so what the loop
pushes is walked too and what it removes ends it sooner; a
comprehension over a DynArray makes a list of its elements as they are.

```pyking
use mutation

v = dynarray([1, 2, 3])
v[0] := 10
insert(v, 1, 5)
print(pop(v), remove(v, 0), v)                 # 3 10 dynarray([5, 2])
```

**Sharing and identity** are as for arrays: `w = v` and `f(v)` hand
over the one DynArray, `same(v, w)` asks whether two are one, and `==`
compares none -- `dynarray.equal(v, w)` from `lib/dynarray` compares elements. A
DynArray prints as what makes one, `dynarray([1, 2])`.

**The names are yours to take.** `push`, `pop`, `insert`, `remove` and
`clear` are builtins, but a module's own definition or import of one of
those names wins there: a module defining `insert` for a tree, or
importing tinyweb's `push`, means its own.

The rest is the library `lib/dynarray`: `copy`, `to_list`, `to_array`,
`from_array`, `extend`, `reverse`, `equal` and `sort` (lib/array's, the
same on every target), `truncate`, `retain` and `append`, and the
functions lib/array has too.

## MutMaps (`MutMap(K, V)`) — Pyking extension

A **MutMap** maps keys to values, and remembers the order its keys were
put in. It is written in place and shared by every name that holds one.
Its type is `MutMap(K, V)`. Making and changing one need `use mutation`;
reading, passing, returning and holding one do not.

```pyking
use mutation

counts: MutMap(String, Int) = mutmap()
for word in ["the", "cat", "the", "hat"]:
    counts[word] := get(counts, word, 0) + 1
print(counts, counts["the"], len(counts))
# mutmap([("the", 2), ("cat", 1), ("hat", 1)]) 2 3
```

**Making one.** `mutmap()` makes one with no entries, whose types its use
or an annotation decides, and `mutmap(pairs)` one from a list of `(key,
value)` pairs; a key written twice keeps its first place and its last
value. `mutmap(m)` copies a Map or another MutMap, and
`mutmap_init(keys, f)` maps each key to `f(key)` (see "Making and
converting collections"). There is no literal syntax.

**Reading and writing.** `d[k]` reads the value of the key `k` -- one
the MutMap has no entry for is a runtime error, `the MutMap has no key
"zed"` -- and `d[k] := v` writes one: an entry for a new key goes at the
end, and a key already there keeps its place and gets the new value.
The compound forms read and write it back, `d[k] += 1`.

| call | answers |
|---|---|
| `get(d, k, default)` | the value of `k`, or `default` where there is none (`default` is worked out either way) |
| `has(d, k)` | whether `d` has an entry for `k` |
| `remove(d, k)` | the value of `k`, its entry taken out -- a runtime error where there is none |
| `discard(d, k)` | `()`, its entry taken out where there is one |
| `keys(d)`, `values(d)`, `items(d)` | lists, in the MutMap's order; `items` gives `(key, value)` pairs |
| `clear(d)` | `()`, every entry taken out |
| `len(d)`, `same(d, e)` | the number of entries; whether two are one MutMap |

A key taken out and put back goes to the end.

**Walking one.** `for k in d` walks the keys in order. Putting a new
key in or taking one out while the walk is on is a runtime error, `the
MutMap changed while a for loop was reading it`, at the next step of the
walk; replacing a value is not a change. A comprehension over a MutMap
makes a list of its keys.

**Keys.** A key is compared and hashed, so its type is one whose values
never change and always equal themselves: Int, Char, String, Bool, (),
and tuples, lists, structs and datatypes of those. A Float is not a key
-- NaN equals nothing, itself included -- nor is a function, nor an
array, a DynArray, a MutMap or a `mutable struct`, nor anything holding one; the
checker says which part of the key type is not.

```pyking
use mutation

struct Pos(row: Int, col: Int)

board = mutmap([(Pos(0, 0), 'x')])
board[Pos(1, 1)] := 'o'
print(board[Pos(1, 1)], has(board, Pos(2, 2)), keys(board))
# o false [Pos(0, 0), Pos(1, 1)]
```

**Sharing and printing** are as for arrays and DynArrays: `same(d, e)` asks
whether two names hold one MutMap, `==` compares none, and a MutMap prints
as what makes one, `mutmap([(1, "a")])`.

**Names.** `get`, `has`, `keys`, `values`, `items`, `discard`, `remove`
and `clear` are builtins, but a module's own definition or import of
one of those names wins there.

The rest is the library `lib/mutmap`: `update`, `insert_with` (for a
count), `extend` and `retain`, which change the MutMap, and `lookup`,
`fold_with_key`, `find_key`, `is_empty`, `equal_by` and `copy`.

## Slices and views — Pyking extension

**A slice copies.** `s[i:j]` is a new value holding elements `i` up to
`j` of a list, a String (by character), an array or a DynArray -- of the
same kind -- with either bound left out for the start or the end. The
bounds satisfy `0 <= i <= j <= len(s)`; anything else is a runtime
error, `the slice 2:4 is outside an array of 3 elements`, on every
target but plain C. There are no negative bounds and no step. A copy is
shallow: an element that is itself an array or a `mutable struct` is shared
by both.

```pyking
xs = [1, 2, 3, 4, 5]
print(xs[1:3], xs[:2], xs[3:], "héllo"[1:4])     # [2, 3] [1, 2] [4, 5] éll
```

**A view shares.** Under `use mutation`, `view(a, i, j)` is a
`Slice(T)` of elements `i` up to `j` of the array `a` -- or of another
view, which reaches the same array. It holds no elements of its own:
`w[k]` reads `a[i + k]` and `w[k] := x` writes it, `len(w)` is `j - i`,
`for` and comprehensions walk it, and `same` asks whether two are one
view. A view prints as its elements are now, `view([2, 3])`, and a
slice of a view, `w[1:]`, is a new array.

```pyking
use mutation

a = array([10, 20, 30, 40])
w = view(a, 1, 3)
w[0] := 21
print(w, a)          # view([21, 30]) array([10, 21, 30, 40])
```

**`copy_into(dst, src)`** writes the elements of an array or a view
`src` over the first ones of `dst`, as C's `memmove` does: right even
where the two share elements. `src` is no longer than `dst`.

```pyking
use mutation

b = array([1, 2, 3, 4, 5, 6])
copy_into(view(b, 2, 6), view(b, 0, 4))
print(b)             # array([1, 2, 1, 2, 3, 4])
```

## Making and converting collections — Pyking extension

Every collection is made the same way: by a call named for its kind of
a list, of one value repeated, or of another collection, and by a call
named with `_init` that calls a function for each element.

| collection | of a list | of one value | of another collection | calling a function |
|---|---|---|---|---|
| list | `list(xs)` (itself) | `list(n, v)` | `list(c)` | `list_init(n, f)`, `list_init(n, seed, f)` |
| array | `array(xs)` | `array(n, v)` | `array(c)` | `array_init(n, f)`, `array_init(n, seed, f)` |
| DynArray | `dynarray(xs)` | `dynarray(n, v)` | `dynarray(c)` | `dynarray_init(n, f)`, `dynarray_init(n, seed, f)` |
| Map | `map(pairs)` | -- | `map(m)`, `map(d)` | `map_init(keys, f)`, `map_init(n, seed, f)` |
| MutMap | `mutmap(pairs)` | -- | `mutmap(m)`, `mutmap(d)` | `mutmap_init(keys, f)`, `mutmap_init(n, seed, f)` |

```pyking
use mutation

print(list(3, 'a'), list_init(4, lam i. i * i), dynarray(2, 0))
print(list(array(3, "x")), array("abc"), map_init(["ann", "bo"], lam name. len(name)))
# ['a', 'a', 'a'] [0, 1, 4, 9] dynarray([0, 0])
# ["x", "x", "x"] array(['a', 'b', 'c']) map([("ann", 3), ("bo", 2)])
```

- **Converting copies.** `list(c)`, `array(c)` and `dynarray(c)` take the
  elements of a list, an array, a DynArray or a view, a String's Chars,
  or a Map's or a MutMap's `(key, value)` pairs in order, and `list` an
  Option's value, if any; `map(c)` and `mutmap(c)` take a Map or a
  MutMap. What comes back shares nothing with what went in, so `array(a)`
  is a new array.
- **Making a store needs `use mutation`**: an array, a DynArray or a
  MutMap, by any of these calls. A list and a Map need none.
- **`_init` calls `f` in order**, once per element, and the unfolding
  form drops the last seed; `map_init(keys, f)` maps each key to `f(key)`
  in the order of `keys`. The one-value forms work `v` out once, so
  `list(3, f())` calls `f` once and `list_init(3, lam i. f())` three
  times. A negative `n` is a runtime error.
- **The kind of collection is the argument's type**, which has to be
  known where the call is, written or worked out: `list(c)` of a
  parameter nothing has said anything about is refused with the
  annotation to write.

## fmap and the folds — Pyking extension

Six builtins work on every collection, an Option and a Result, each by
one name -- Haskell's for the first four:

| call | gives |
|---|---|
| `fmap(f, c)` | a new collection of the same kind, `f(x)` for each element `x` |
| `filter(p, c)` | a new collection of the same kind, of the elements `p` is true of |
| `foldl(f, init, c)` | `f(...f(f(init, x1), x2)..., xn)`, from the first element |
| `foldr(f, init, c)` | `f(x1, f(x2, ...f(xn, init)))`, from the last |
| `any(p, c)` | whether `p` is true of some element |
| `all(p, c)` | whether `p` is true of every element |

```pyking
struct Person(name: String, age: Int)

people = [Person("ann", 31), Person("bo", 5)]
print(fmap(lam p. p.name, people), filter(lam p. p.age > 18, people))
print(foldl(lam (total, p). total + p.age, 0, people), any(lam p. p.age < 10, people))
print(fmap(lam n. n * 2, Some(21)), foldr(lam (x, acc). acc + string(x), "", [1, 2, 3]))
# ["ann", "bo"] [Person("ann", 31)]
# 36 true
# Some(42) 321
```

- **Each answers a new collection of the kind it was given**: a list
  for a list, an array for an array or a view, a DynArray for a
  DynArray, a Map or a MutMap for one. Making an array, a DynArray or a
  MutMap this way needs `use mutation`, as every making of one does.
- **A Map's and a MutMap's elements are its values.** `fmap` keeps the
  keys, in their order, and `filter` keeps the entries whose value
  passes; `for k in m` walks the keys, as Python's does. lib/map's
  `map_with_key`, `filter_with_key` and `fold_with_key` see the keys too.
- **An Option and a Result hold none or one value.** `fmap(f, Some(x))`
  is `Some(f(x))` and `fmap(f, Ok(x))` is `Ok(f(x))`, an `Error` staying
  as it is. A Result has no `filter`: where the test is false there is
  no error to give.
- **A String is not one of them**: `fmap` and the folds refuse it, and
  `list(s)` makes its Chars a list they take.
- **The calls run in order.** `f` and `p` are called once per element,
  from the first -- `foldr` from the last -- and `any` and `all` stop at
  the first element that decides. `foldr` walks the elements without
  recursing, so a long list does not overflow the stack.
- **The function comes first, the collection last**, and the collection
  says what the function's parameters are: in `fmap(lam p. p.name,
  people)` the list says `p` is a Person. A lambda argument is checked
  after the other arguments of any call for this reason -- the arguments
  still run in the order written.
- **The kind of collection is known where the call is.** A parameter
  nothing has said anything about is refused with the annotation to
  write (`'c: [Int]'`): one definition serves one kind of collection,
  of any element type.
- **The names are yours to take.** These builtins are written in Pyking,
  in lib/prelude, and a module calling one of them, and binding none of
  them itself, has them all, as Option arrives. A module that defines
  its own `map`, `filter` or `list` means its own.

lib/list is the rest of what a list is asked -- `first`, `nth`, `take`,
`drop`, `zip`, `enumerate`, `chunks`, `find`, `count`, `partition`,
`unique`, `group`, `sum`, `maximum`, `sort`, `sort_by`, `sort_on`, ... --
named as Haskell names them where Haskell, OCaml and Rust differ, with a
function first and the list last. A function comparing elements is
written once per scalar type and once more as `..._by`, taking the
comparison.
