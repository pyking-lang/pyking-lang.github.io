---
title: Libraries
description: The standard library that comes with Pyking.
sidebar:
  label: Overview
  order: 0
---

The standard library comes with every installation of Pyking. A program
uses a module by importing it, and needs no flag to find it:

```pyking
import io

io.write("Hello, ")
io.write_line("libraries")
```

| Module | |
|---|---|
| [`array`](./array/) | Arrays: copying, filling, comparing, sorting and joining them. |
| [`dynarray`](./dynarray/) | DynArrays: copying, joining, comparing, reversing and sorting them. |
| [`fs`](./fs/) | Reading and writing files. |
| [`io`](./io/) | Standard input and standard output. |
| [`list`](./list/) | Lists: taking parts, searching, combining, counting and sorting them. |
| [`map`](./map/) | Maps: a new Map with an entry put in, taken out or changed, and the rest of what a Map is asked. |
| [`math`](./math/) | Numbers: trigonometry, powers and logarithms, rounding to an Int, and helpers for drawing and games. |
| [`mutmap`](./mutmap/) | MutMaps: changing an entry in place, keeping a count, and the rest of what a MutMap is asked. |
| [`option`](./option/) | Option: a value, or none. |
| [`prelude`](./prelude/) | The builtins written in Pyking: `fmap`, `filter`, `foldl`, `foldr`, `any` and `all` over every collection, and the forms of `list`, `list_init`, `dynarray`, `dynarray_init`, `map_init` and `mutmap_init` that make one by calling a function or convert another. |
| [`random`](./random/) | Random numbers: a Float between 0.0 and 1.0, a whole number in a range, a pick from a list and a list shuffled. |
| [`result`](./result/) | Result: a value, or the error that stopped it. |
| [`sys`](./sys/) | The process this program is running as: its arguments, its name, and its environment. |
| [`text`](./text/) | Looking inside a String: its length, its characters, finding and replacing a part, and taking it apart into pieces and words. |
| [`time`](./time/) | Dates and times: reading the clock, and rendering an instant. |
| [`tinyweb`](./tinyweb/) | Graphics, widgets and sound on a web page, kept in time with each other. |

These pages are generated from the libraries' own source, in `lib/`.
