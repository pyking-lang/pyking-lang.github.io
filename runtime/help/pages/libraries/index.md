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
| [`sys`](./sys/) | The process this program is running as: its arguments, its name, and its environment. |
| [`time`](./time/) | Dates and times: reading the clock, and rendering an instant. |
| [`tinyweb`](./tinyweb/) | Graphics, widgets and sound on a web page, kept in time with each other. |

These pages are generated from the libraries' own source, in `lib/`.
