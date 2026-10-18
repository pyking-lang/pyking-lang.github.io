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
| [`fs`](./fs/) | Reading and writing files. |
| [`io`](./io/) | Standard input and standard output. |
| [`math`](./math/) | Numbers: trigonometry in degrees and in radians, powers and logarithms, rounding to an Int, and helpers for drawing and games. |
| [`random`](./random/) | Random numbers: a Float between 0.0 and 1.0, a whole number in a range, a pick from a list and a list shuffled. |
| [`sys`](./sys/) | The process this program is running as: its arguments, its name, and its environment. |
| [`time`](./time/) | Dates and times: reading the clock, and rendering an instant. |
| [`tinyweb`](./tinyweb/) | Graphics, widgets and sound on a web page, kept in time with each other. |

These pages are generated from the libraries' own source, in `lib/`.
