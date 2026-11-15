---
title: "Grammar"
description: "Pyking's syntax: lexical structure, layout, the grammar in EBNF, and how it compares with Python."
sidebar:
  order: 10
  group: Language
---

This page is Pyking's syntax and nothing else: what may be written, and
how it is read. What each construct means is in the Language reference.

## Lexical structure

A source file is UTF-8 text. The lexer reads it into tokens and turns
its indentation into block structure.

- **Identifiers** start with a letter or `_` and go on with letters,
  digits and `_`. A name a program binds starts with a lowercase letter
  or `_`; a name starting with an uppercase letter is a type or a
  constructor.
- **Keywords**, which may not be used as names: `and`, `as`, `break`,
  `case`, `continue`, `datatype`, `def`, `else`, `false`, `for`, `from`,
  `if`, `implicit`, `import`, `in`, `lam`, `let`, `loop`, `match`,
  `mutable`, `not`, `or`, `public`, `return`, `struct`, `then`, `true`,
  `use`, `var`, `while`, `xor`, and the type names `Bool`, `Char`,
  `Float`, `Int` and `String`.
- **Reserved words** of objects, also never names: `abstract`, `class`,
  `extends`, `implements`, `interface`, `override`, `private`, `self`
  and `super`.
- **Literals**: integers (decimal, `0x` hexadecimal, `0b` binary),
  floats, `'c'` Chars, `"…"` Strings and `r"…"` raw Strings, written as
  "Values and basic types" in the Language reference says. An
  interpolation in a String -- `${…}` or `$name` -- is lexed as the
  tokens of its expression, and the parser rewrites it into `+` and
  `string(…)` before anything is checked.
- **Comments** start with `#`; see below.

## Comments

A `#` starts a line comment that runs to the end of the line. It may appear
on its own line or trail after other tokens.

```python
# This is a line comment.
x = 1  # comments may also trail after other tokens
print(x)
```

## Layout

Blocks are written by indentation, four spaces a level, as in Python. A
line goes on while a bracket is open, and a block may be written on its
header's own line.

### Indentation-based blocks

Blocks are delimited purely by indentation, in 4-space increments — there
are no `{ }` or `begin`/`end` keywords. Increasing the indentation opens a
nested block (after a line ending in `:`); returning to a shallower
indentation closes it, and a single line may close several nested blocks
at once.

```python
def bucket(x):
    for limit in range(3):
        if x < limit:
            return limit
    return 3


print(bucket(0), bucket(5))
```

A non-breaking space (U+00A0) is a space wherever a space may stand:
in indentation, where it counts as one space, and between the words
of a line. Code copied out of a PDF, a slide or a web page often has
them in place of ordinary spaces, and it runs as it looks. Inside a
string or a comment one is kept as written. A tab is not a space. `pyk highlight`, and the
playground's Copy for slides, write indentation with them for this
reason (see the documentation's "Code on slides" page,
`sitesrc/documentation/slides.md`).

### Lines and continuation

A statement ends where the tokens stop being able to continue it, and
each line's leading whitespace is what opens and closes blocks — but
**not while a bracket is open**. Inside an unclosed `(` or `[` the
indentation rules are suspended entirely, so a parameter list, a call's
arguments, a list literal, a comprehension and a tuple may each span
several lines:

```pyking
def window(
        start: Int,
        size: Int,
        step: Int) -> Int:
    return start + (size * step)


numbers = [
    1,
    2,
    3,
    4]

print(window(
    1,
    2,
    3))
```

The continuation lines are part of the same statement, and their own
indentation means nothing at all — it is there for the reader. Nesting
one bracket inside another keeps the line open until the outermost one
closes. Outside brackets, indentation means exactly what it did.

There is no backslash continuation: a line is continued by an open
bracket or not at all.

### A block on its header's own line

Any header ending in `:` may carry its block on that same line instead
of indenting it, provided what it carries is **one expression**. Python
allows something similar but wider — any *simple* statement, and `;` to
write several; Pyking's line holds a value and nothing else.

```pyking
def square(x): x * x
def twice(x): x + x

if square(3) > 5: print("big")
else: print("small")

for i in range(3): print(i)
```

**It is the same program either way.** `def square(x): x * x` parses to
exactly what

```pyking
def square(x):
    x * x
```

parses to — one block, one statement — so nothing after the parser can
tell which was written, and the pretty-printer prints both indented. The
form is a layout, not a second kind of definition: what the body means,
where its names come from, whether its last expression is in tail
position (it is) are all unchanged.

It works for every header, because the rule belongs to the *block*:
`def`, `if` and its `else`, `for`, `while`, `loop`, and a `case` clause.

```pyking
def name_of(n):
    match n:
        case 0: "zero"
        case 1: "one"
        case _: "many"


print(name_of(0), name_of(7))
```

A `match`'s clause list is the one thing that looks like a block and is
not one: `match e:` opens a list of `case` clauses rather than a list of
statements, and a clause is not an expression, so there is nothing its
line could carry. The clauses are always indented under it.

##### What may be written there

An **expression**, and only an expression. A `return`, an `=` binding, a
`:=` mutation, or a nested header is not one, and is refused where it
stands:

```
'prog.pyk' 4:14-4:22 Parsing error: a block written on its header's
  own line must be one expression, and 'return a' is not; write it in
  an indented block instead
```

That is the whole point of the restriction. A line ending in `:` is a
promise that a value follows; letting a statement follow instead would
mean control flow and new names could hide behind a `:` at the end of a
line, and every such line would have to be read to the end to find out
what it did. So the value-producing forms stay on one line and
everything else goes under its header:

```pyking
def first_positive(a, b):
    if a > 0:
        return a
    b
```

Note that a function ending in a value needs no `return` at all (see
"Tail position"), so the shorthand is rarely what a one-line body wanted
in the first place. And `if` written inline is the `if`/`then`/`else`
*expression*, which is an expression like any other:

```pyking
def describe(n): if n < 0 then "negative" else "positive"
```

##### The line ends there

An inline block is the end of its line, and two rules follow. Each is
reported where it is written:

- **Nothing may be indented under it.** The header's line already held
  the block, so an indented line after it belongs to nothing — `if c:
  print(1)` with a second `print` indented below is refused rather than
  read as a two-statement body.
- **Nothing may continue the construct on that line.** An `else`
  belonging to the `if` starts the *next* line (see below).

So an `if` and its `else` each carry their own line:

```pyking
x = 2

if x > 1: print(7)
else: print(8)
```

Written `if x > 1: print(7) else: print(8)`, one line would hold an
`if`, its whole then-block, and the start of another block; that is the
run-on the one-statement-per-line rule exists to prevent, and it is
refused (`'else' must start on a new line: the block written on the
header's own line ends that line`). The same holds for an `else if`
rung.

A second *statement* sharing the line is caught by that
one-statement-per-line rule itself (see "Indentation-based blocks"
above): `if c: print(1) print(2)` puts the second `print` beside the
`if`, not inside it.

A block that begins on the *next* line without being indented is neither
form, and is the error it always was — `expected an indented block`.

## The grammar


EBNF for the subset currently accepted by `parse()` in `src/parser.ml`.
`INDENT`/`DEDENT` are not literal characters — they are synthesized by the
lexer from 4-space indentation changes (see "Indentation-based blocks"
below). Comments are stripped by the lexer and don't appear here.

```ebnf
(* An import and a `public` belong to a module's top level, so they are
   here rather than in `statement`, which is what a block holds. The
   `use` lines come before everything else. *)
program     = { use_stmt } , { top_statement } ;
use_stmt    = "use" , feature , { "," , feature } ;
feature     = "mutation" | "pointers" | "objects" ;
top_statement = import_stmt
            | from_stmt
            | public_stmt
            | datatype_stmt
            | struct_stmt
            | class_stmt
            | statement ;

import_stmt = "import" , module_item , { "," , module_item } ;
module_item = module_path , [ "as" , ident ] ;
from_stmt   = "from" , module_path , "import" , field_item , { "," , field_item } ;
(* A module, or a submodule of one: `hello`, `hello.mymod`. *)
module_path = ident , { "." , ident } ;
field_item  = ident , [ "as" , ident ] ;
public_stmt = "public" , ( function_def | function_sig | datatype_stmt
                          | struct_stmt | class_stmt | assignment ) ;

(* A datatype belongs to a module's top level. Its name and every
   constructor's start with an uppercase letter; its parameters are type
   variables. Its constructors follow the ':' on its own line, or on
   indented lines under it, or both; a line holds one or more,
   separated by commas. *)
datatype_stmt = "datatype" , [ sub_path , "." ] , upper_ident , [ "(" , type_var , { "," , type_var } , ")" ] ,
                ":" , ( constructor_line , [ INDENT , { constructor_line } , DEDENT ]
                      | INDENT , constructor_line , { constructor_line } , DEDENT ) ;
constructor_line = constructor , { "," , constructor } ;
constructor = upper_ident , [ "(" , [ field , { "," , field } ] , ")" ] ;
(* A field is a type alone (positional only), or named; a named field's
   type may be left to its default. Unnamed fields come first, and every
   field after one with a default has one too. *)
field       = type
            | ident , ":" , type , [ "=" , expr ]
            | ident , "=" , expr ;
upper_ident = ? an ident beginning with an uppercase letter ? ;

(* A struct is a datatype of one constructor, named as the type is. Its
   fields are in parentheses on its own line -- every type variable they
   name is then a parameter -- or on indented lines under its ':', a
   line holding one or more separated by commas, after the parameters
   written in parentheses. With neither it has no fields. "mutable"
   makes it a mutable struct, whose fields are written in place: it has
   at least one field, and needs `use mutation`. *)
struct_stmt = [ "mutable" ] , "struct" , [ sub_path , "." ] , upper_ident ,
              [ "(" , [ field , { "," , field } ] , ")"
              | [ "(" , type_var , { "," , type_var } , ")" ] , ":" ,
                INDENT , field_line , { field_line } , DEDENT ] ;
field_line  = field , { "," , field } ;

(* A class, an abstract class or an interface belongs to a module's top
   level and needs `use objects` (see "Classes and interfaces"). A
   class's header holds its type parameters (bare lowercase names) and
   its fields, which are its constructor's parameters; a parent class is
   written with its constructor's arguments, an interface with its type
   arguments. Its members are on indented lines under its ':'. *)
class_stmt  = ( [ "abstract" ] , "class" , upper_ident ,
                "(" , [ header_item , { "," , header_item } ] , ")" ,
                [ "extends" , class_name , "(" , [ args ] , ")" ] ,
                [ "implements" , iface , { "," , iface } ]
              | "interface" , upper_ident , [ "(" , type_var , { "," , type_var } , ")" ] ,
                [ "extends" , iface , { "," , iface } ] ) ,
              [ ":" , INDENT , member , { member } , DEDENT ] ;
header_item = type_var | member_field ;
class_name  = [ sub_path , "." ] , upper_ident ;
iface       = class_name , [ "(" , type , { "," , type } , ")" ] ;
member      = member_field | method ;
(* A header field has a default only where every one after it has; a
   body field always has its first value. *)
member_field = [ "private" ] , [ "var" ] , ident , ( ":" , type , [ "=" , expr ] | "=" , literal ) ;
(* A method's parameters after `self` all say their types; one with no
   body is abstract (in an abstract class) or an interface's. *)
method      = [ "private" ] , [ "override" ] , [ "abstract" ] ,
              "def" , ident , "(" , "self" , { "," , param } , ")" , [ "->" , type ] ,
              [ ":" , block ] ;

(* A block is indented under its header, or is the single expression
   written on the header's own line -- which the EBNF cannot say, since
   it cannot see where a line ends; see the notes below. *)
block       = INDENT , { statement } , DEDENT
            | expr_stmt ;

statement   = function_def
            | function_sig
            | return_stmt
            | loop_stmt
            | break_stmt
            | continue_stmt
            | if_stmt
            | match_stmt
            | var_decl
            | assignment
            | mutation
            | expr_stmt ;

(* `implicit` marks a definition an implicit argument may be resolved
   to; a definition's own name may carry a `::` qualifier, which is what
   makes two definitions of one base name distinct. *)
function_def = [ "implicit" ] , "def" , def_name ,
               "(" , [ params ] , ")" , [ "->" , type ] , ":" , block ;
(* The second form names its parameters; it ends its line, every
   parameter has a type and none a default, and it means the first form
   with the parameter types in order. *)
function_sig = "def" , def_name , ":" , type
             | "def" , def_name , "(" , [ named_type , { "," , named_type } ] ,
               ")" , "->" , type ;
named_type   = ident , ":" , type ;
(* A dotted name defines in a submodule: `mymod.foo`, `mymod.deep.foo`. *)
def_name     = [ sub_path , "." ] , ( ident | qualified_name ) ;
sub_path     = ident , { "." , ident } ;
(* No whitespace is permitted on either side of the "::", and neither
   half may be a keyword. *)
qualified_name = ident , "::" , ident ;
(* Every parameter after the first one with a default has one too, and
   every implicit parameter comes after every ordinary one. *)
params       = param , { "," , param } , { "," , implicit_param }
             | implicit_param , { "," , implicit_param } ;
param        = ident , [ ":" , type ] , [ "=" , expr ] ;
implicit_param = "implicit" , ident , ":" , type ;

type         = type_atom , [ "->" , type ] ;
type_atom    = "Int" | "Float" | "String" | "Char" | "Bool"
             | type_var
             | [ sub_path , "." ] , upper_ident , [ "(" , type , { "," , type } , ")" ]
             | "all" , type_var , { type_var } , "." , type
             | "[" , type , "]"
             | type_paren ;
(* One parenthesized list, three readings, decided by the token after
   ")" and by whether a comma is written -- exactly as `tuple_lit` and a
   parenthesized expression are told apart among values. *)
type_paren   = "(" , [ type , { "," , type } ,
                       { "," , implicit_param } , [ "," ] ] , ")" ,
               "->" , type
             | "(" , implicit_param , { "," , implicit_param } , ")" ,
               "->" , type
             | "(" , type , ")"
             | "(" , ")"
             | "(" , type , "," , ")"
             | "(" , type , ( "," , type )+ , [ "," ] , ")" ;
type_var     = ? an ident beginning with a lowercase letter ? ;

return_stmt = "return" , bound_value ;

(* `for`, `while` and the accumulator loop are one construct with
   different halves written; every combination of them is a loop_stmt. *)
loop_stmt   = ( "loop" , accumulator , [ iteration ]
              | iteration ) , ":" , block ;
accumulator = target , [ ":" , type ] , "=" , tuple_or_expr ;
iteration   = "for" , ident , "in" , expr | "while" , expr ;

(* The value, written on the `break`/`continue` line itself, is the
   accumulator the jump leaves with. *)
break_stmt    = "break" , [ tuple_or_expr ] ;
continue_stmt = "continue" , [ tuple_or_expr ] ;

if_stmt     = "if" , expr , ":" , block ,
              { "else" , "if" , expr , ":" , block } ,
              [ "else" , ":" , block ] ;

(* Always indented: a `match` opens a list of clauses rather than a
   block of statements, and a `case` clause is not an expression, so
   there is nothing its header's line could carry. *)
match_stmt  = "match" , expr , ":" , INDENT , case_clause , { case_clause } , DEDENT ;
case_clause = "case" , pattern , [ "if" , expr ] , ":" , block ;
pattern     = pattern_as , { "," , pattern_as } ;
pattern_as  = pattern_or , [ "as" , ident ] ;
pattern_or  = pattern_join , { "|" , pattern_join } ;
pattern_join = pattern_atom , { "+" , pattern_atom } ;
pattern_atom = int | "-" , int | string | char | bool | "_" | ident
             | constructor_pattern
             | "(" , ")"
             | "(" , pattern_as , ")"
             | "(" , pattern_as , "," , ")"
             | "(" , pattern_as , ( "," , pattern_as )+ , [ "," ] , ")"
             | list_pattern ;
(* Positional sub-patterns first, then named ones in any order; a field
   not mentioned matches anything. *)
constructor_pattern = [ sub_path , "." ] , upper_ident ,
                      [ "(" , [ field_pattern , { "," , field_pattern } ] , ")" ] ;
field_pattern = pattern_as | ident , "=" , pattern_as ;

list_pattern = "[" , [ list_pattern_items ] , "]" ;
list_pattern_items = list_pattern_item , { "," , list_pattern_item } ;
list_pattern_item  = pattern_as | rest_marker ;
rest_marker        = ".." , [ ident ] ;

var_decl    = "var" , ident , ( "=" | ":=" ) , bound_expr ;   (* ":=" is accepted as "=" *)
assignment  = [ "implicit" ] , target , [ ":" , type ] , "=" , bound_value ;
mutation    = ident , ":=" , bound_expr
            | target , ":=" , bound_expr            (* a tuple of names *)
            | ident , compound_op , bound_expr
            | atom , ( ":=" | compound_op ) , bound_expr
                       (* an array's element, an atom ending in an
                          index_tail, or a mutable struct's field, an atom
                          ending in "." ident *)
            | "*" , unary , ( ":=" | compound_op ) , bound_expr ;
                       (* what a pointer points at *)
compound_op = "+=" | "-=" | "*=" | "/=" | "%=" | "^="
            | "&=" | "|=" | "<<=" | ">>=" | "xor" "=" ;   (* no space in "xor=" *)

(* A bound value may start on the line after its "=", indented -- the
   lexer wraps it in the same INDENT/DEDENT any other block gets. *)
bound_value = tuple_or_expr | value_stmt | INDENT , bound_value , DEDENT ;
bound_expr  = tuple_or_expr | INDENT , bound_expr , DEDENT ;

value_stmt  = value_if | match_stmt | loop_stmt ;
value_if    = "if" , expr , ":" , block ,
              { "else" , "if" , expr , ":" , block } ,
              "else" , ":" , block ;

target      = target_atom , { "," , target_atom } ;
target_atom = ident
            | sub_path , "." , ident
            | "(" , ")"
            | "(" , target_atom , "," , ")"
            | "(" , target_atom , ( "," , target_atom )+ , [ "," ] , ")" ;

expr_stmt   = tuple_or_expr ;

tuple_or_expr = expr , { "," , expr } ;

expr        = lambda | if_expr | let_expr | disjunction ;

(* A lambda takes everything to its right that one expression can hold,
   so it associates to the right and binds looser than every operator;
   a comma ends it, since `lam x. a, b` is a pair. A parameter with a
   type, and more than one, are written in parentheses. *)
lambda      = "lam" , lambda_params , "." , expr ;
lambda_params = ident
            | "(" , [ param , { "," , param } ] , ")" ;

if_expr     = "if" , expr , "then" , expr , "else" , expr ;

(* Like a lambda, the body takes everything to its right that one
   expression can hold. *)
let_expr    = "let" , target , [ ":" , type ] , "=" , expr , "in" , expr ;

(* `and`/`or`/`not` and their symbol spellings bind looser than a
   comparison; the bitwise operators bind tighter, as Python's do. *)
disjunction = conjunction , { ( "or" | "||" ) , conjunction } ;
conjunction = negation , { ( "and" | "&&" ) , negation } ;
negation    = "not" , negation | comparison ;

comparison  = bit_or , [ comp_op , bit_or ] ;
comp_op     = "<" | "<=" | ">" | ">=" | "==" | "!=" ;

bit_or      = bit_xor , { "|" , bit_xor } ;
bit_xor     = bit_and , { "xor" , bit_and } ;
bit_and     = shift , { "&" , shift } ;
shift       = additive , { ( "<<" | ">>" ) , additive } ;
additive    = multiplicative , { ( "+" | "-" ) , multiplicative } ;
multiplicative = unary , { ( "*" | "/" | "%" ) , unary } ;
unary       = ( "-" | "!" | "~" | "&" | "*" ) , unary | power ;
                       (* "&" and "*" are a pointer's, under
                          `use pointers`: an address and what a pointer
                          points at *)
(* `^` associates to the right, and its right operand may be negated:
   `2 ^ -1`. It binds tighter than unary minus: `-2 ^ 2` is `-(2 ^ 2)`. *)
power       = atom , [ "^" , unary ] ;

atom        = ( float | int | string | char | bool | ident | list_lit | list_comp
              | tuple_lit | construct
              | "(" , expr , ")" ) ,
              { call_tail | field_tail | index_tail } ;
(* `xs[i]`: the `[` on the row the indexed expression ends on. *)
index_tail  = "[" , expr , "]"
            | "[" , [ expr ] , ":" , [ expr ] , "]" ;   (* a slice: a copy *)
(* A constructor applied to its fields, with a call's arguments; one with
   no fields is written bare. *)
construct   = [ sub_path , "." ] , upper_ident , [ call_tail ] ;
field_tail  = "." , ident ;
(* Every named argument comes after every positional one; the named
   ones may be written in any order. A constructor's arguments may end
   in `..expr`, which gives every field not written before it. *)
call_tail   = "(" , [ call_args ] , ")" ;
call_args   = expr , { "," , expr } , { "," , named_arg } , [ "," , update ]
            | named_arg , { "," , named_arg } , [ "," , update ]
            | update ;
named_arg   = ident , "=" , expr ;
update      = ".." , expr ;
args        = expr , { "," , expr } ;

list_lit    = "[" , [ args ] , "]" ;

list_comp   = "[" , expr , comp_for , { comp_for | comp_if } , "]" ;
comp_for    = "for" , pattern , "in" , expr ;
comp_if     = "if" , expr ;

tuple_lit   = "(" , ")"
            | "(" , expr , "," , ")"
            | "(" , expr , ( "," , expr )+ , [ "," ] , ")" ;

ident       = letter , { letter | digit } ;
int         = digit , { digit }
            | "0" , ( "x" | "X" ) , hex_digit , { [ "_" ] , hex_digit }
            | "0" , ( "b" | "B" ) , bin_digit , { [ "_" ] , bin_digit } ;
hex_digit   = digit | "a" | "b" | "c" | "d" | "e" | "f"
            | "A" | "B" | "C" | "D" | "E" | "F" ;
bin_digit   = "0" | "1" ;
(* A point needs a digit on each side, so `1.` and `.5` are not floats.
   An exponent alone makes one: `1e9` is a Float. *)
float       = digits , "." , digits , [ exponent ]
            | digits , exponent ;
digits      = digit , { digit } ;
exponent    = ( "e" | "E" ) , [ "+" | "-" ] , digits ;
bool        = "true" | "false" ;
(* A String is in double quotes; a Char is exactly one character -- one
   Unicode code point, or one escape -- in single quotes. A String may
   interpolate: `${` an expression `}`, or `$` and a name. A `$` before
   anything else is a dollar sign. A raw String, `r"..."`, is its
   characters as written, with no escapes and no interpolation. *)
string      = '"' , { string_char | interpolation } , '"'
            | 'r"' , { any_char_except_double_quote } , '"' ;
interpolation = "${" , expr , { "," , expr } , "}"
            | "$" , ident ;
char        = "'" , char_char , "'" ;
string_char = any_char_except_double_quote_or_backslash
            | "\" , escape ;
char_char   = any_char_except_single_quote_or_backslash
            | "\" , escape ;
escape      = "n" | "t" | "r" | "0" | "\" | "'" | '"' | "$" ;
```

## Notes on the grammar

Notes that don't fall out of the grammar alone:

- **A statement starts a line of its own**, and so does a `case` clause.
  There is no statement separator in Pyking: a statement ends where the
  tokens stop being able to continue it, which by itself would make

  ```
  print h
  ```

  *two* statements — a bare `print`, then a bare `h` — and so a program
  that reads as though it prints and does not. The rule cannot be stated
  in the EBNF, because the grammar cannot see line boundaries: the lexer
  turns indentation into block structure and emits nothing at all for the
  end of a line. It is checked against the source positions the tokens
  carry, and reported as an ordinary `Parsing error`:

  ```
  'prog.pyk' 2:6-2:7 Parsing error: each statement must start on a new
    line. In this case, 'print' and 'h' are seen as two different
    statements
  ```

  Both are quoted back, because the mistake is not that something is in
  the wrong place but that *two* things were read where one was meant.

  One line may still hold a whole statement whose header opens a block
  (`x = if c:`), and a statement may still span as many lines as its
  blocks need. What one line may not hold is *two* statements.
- Two rules about `break`/`continue` cannot be stated in the grammar and
  are checked in `src/parser.ml` beside the others, so they hold in
  every mode and are reported as a `Parsing error`. First, each may only
  appear in the body of a `loop`, and may not reach out of a `for`, a
  `while` or a `def` to find one:

  ```
  'prog.pyk' 3:8-3:13 Parsing error: 'break' may only appear in the
    body of a 'loop', and this one is inside a 'for', which it may not
    reach out of
  ```

  Second, nothing may be written after one in the same block, since
  nothing there can run:

  ```
  'prog.pyk' 3:4-3:17 Parsing error: this statement cannot be reached:
    'continue' has already left the loop, so nothing written after it
    in the same block runs
  ```

  A `return` is deliberately not part of that second rule: statements
  after one are legal Pyking, and a branch that returns is an ordinary
  way to leave a body early.

  Third, a `break x`/`continue x` gives the loop it belongs to an
  accumulator, so the loop must have one to give: a value is refused in
  a `loop:` with none written, and in a plain `for`/`while`:

  ```
  'prog.pyk' 2:10-2:12 Parsing error: this loop carries nothing, so
    'break' takes no value: give the loop an accumulator ('loop acc =
    ...') for 'break' to give one
  ```

  The value is whatever follows the keyword on its own line, a bare
  tuple included (`break n, acc`), exactly as a loop header's
  initializer is written. A second thing after it on the line is two
  statements on one line, refused as such.
- A `loop_stmt` is a `value_stmt`, so a loop may be bound with `=` or
  returned with `return`, exactly as a value-form `if`/`match` may. It
  needs none of the rules those two obey -- every loop has an
  accumulator (unit where none was written), so there is no way through
  one that produces nothing.
- `comp_op` does not repeat — `1 < 2 < 3` is not a valid `expr`
  (comparisons don't chain), and the parser says what to write instead:
  `'prog.pyk' 1:12-1:13 Parsing error: comparisons do not chain: write
  'a < b and b < c' rather than 'a < b < c'`.
- Three spellings Pyking no longer has are refused where they stand,
  each with the one it has instead: `++` (`'++' is now written '+'`),
  `=>` (`a lambda is now written 'lam x. x + 1'`) and `**` (`a power is
  written with '^'`).
- A `use` line is written before anything else in a module, comments
  aside; one written later is refused (`'use' turns on a feature for
  the whole module, so it is written before anything else`), and so is
  a feature `use` does not know, or one named twice. What a feature
  turns on is parsed in every module and refused, as a `Parsing error`,
  in one that has not turned it on: see "Features turned on with
  `use`".
- `while_stmt` has no `else` clause (unlike Python's `while`/`else`).
- An `if_stmt`'s chain is written `else if`, two ordinary keywords —
  there is no `elif` keyword to reserve. The chained header must be the
  *statement* form, i.e. end in `:`; `else if c then a else b` is an
  error, since an `if_expr` may not start an `else` tail. This makes
  `else if` exactly equivalent to an `else` block holding one nested
  `if_stmt`, and that is how it is parsed: `src/parser.ml` builds no
  ladder node, just an `SIf` whose `else_body` is a one-element list
  holding the next `SIf`. Both pretty-printers undo the nesting when
  printing (as `else if` in Pyking's own syntax), so
  a ladder round-trips flat instead of stepping one level right per
  branch — and an `else:` block a program *did* write with a single
  nested `if_stmt` inside prints as an `else if` chain, the two being
  the same AST.
- A trailing `else` is optional at every point in the chain, so a ladder
  may end after its last `else if` block and run no branch at all.
- `if_expr` sits at the very bottom of the precedence ladder, below
  `comparison`, and its three sub-expressions are each a full `expr`. Two
  consequences: the branches extend as far right as they can (`if c then
  1 else 2 + 1` has `2 + 1` as its else branch, not `(if ...) + 1`), and
  an `if_expr` cannot be an operand without parentheses (`1 + if c then a
  else b` is a syntax error; write `1 + (if c then a else b)`).
- The branches are `expr`, not `tuple_or_expr`, so a comma ends the
  `if_expr` instead of being absorbed into it: `if c then a else b, d` is
  a two-element tuple whose first element is the `if_expr`. This matches
  how Python reads `a if c else b, d`.
- `if_expr` is right-associative, so an `else` branch that is itself an
  `if_expr` chains flat, with the very same `else if` keyword pair the
  `if_stmt` ladder uses, only inline:
  `if a then 1 else if b then 2 else 3`.
- Unlike `if_stmt`, `if_expr`'s `else` is **mandatory**, and that is what
  makes the two `if`s coexist without ambiguity. Because every `else`
  therefore has exactly one possible owner, even
  `if a then if b then c else d else e` has a single valid parse (the
  inner `if` must claim the first `else`, so the outer claims the
  second). The classic dangling-else ambiguity comes from `else` being
  *optional* — true of Pyking's `if_stmt`, deliberately not of its
  `if_expr`. The two also never compete for the same token in practice:
  an `if_stmt`'s `else` always starts a line after a DEDENT, an
  `if_expr`'s is always inline. This holds for the `else if` pair too,
  and what follows it separates the two cases the same way a leading
  `if` is separated at `statement` (see the next note): a `:` ends an
  `if_stmt` chain's condition, a `then` an `if_expr` chain's.
- A `statement` beginning with `if` is where the real parsing difficulty
  lies: it may be an `if_stmt` or an `expr_stmt` holding an `if_expr`,
  and the two share the entire `"if" , expr` prefix. Since that `expr`
  can be arbitrarily long, no bounded lookahead separates them — the
  grammar is not LL(1) at `statement`. `src/parser.ml` handles this
  without backtracking by parsing the shared prefix once and then
  dispatching on the single token that follows it: `:` means `if_stmt`,
  `then` means `if_expr`. (An `if_stmt` whose *condition* is an `if_expr`
  needs no special handling — `expr` already covers it, so
  `if if a then b else c:` parses.)
- The right-hand side of an `assignment` faces that same standoff and
  resolves it the same way: `x = if c:` is a `value_stmt`, `x = if c
  then a else b` an ordinary `expr`, and only the token after the shared
  `"if" , expr` prefix (`:` or `then`) tells them apart. A `match` on
  the right of `=` needs no such care — `match` is a reserved keyword,
  so it can never begin an `expr`.
- Two restrictions on a `value_stmt` are not expressible in the grammar
  and are checked by the parser instead, since every backend depends on
  both: every branch's `block` must **end in an expression**
  (an `expr_stmt`, or a nested `value_stmt` that recursively ends in
  one), and a `value_if`'s final `else` is **mandatory** — a binding
  cannot be left without a value when no condition holds. A `match_stmt`
  needs no such existence rule: it already requires at least one
  `case_clause`, and a subject matching none of them is a runtime error,
  not a silently skipped branch. The nested-`value_stmt` case is also
  what makes an `else if` ladder work in value form, a ladder being
  exactly a nested `if_stmt` as its `else` branch's only statement.
- `assignment` and `return_stmt` accept a `value_stmt`; `var_decl` and
  `mutation` keep taking a plain `tuple_or_expr`, and the parser says so
  explicitly if you try. The value form works by pushing something into
  each branch's tail — an assignment to the target for `assignment`, a
  `return` for `return_stmt` — and both of those are single, unambiguous
  things to push. `var`/`:=` distinguish *declaring* from *updating*,
  and a form that expands to one of them per branch has no way to say
  which of the two each of those is.
- The indented `bound_value`/`bound_expr` form holds exactly **one**
  value: anything left in the block before its DEDENT is an error
  (`expected a single value in the indented block after '='`). It exists
  mainly for a `value_stmt` whose header would otherwise share the `=`
  line, but nothing restricts it to those — `x =` followed by an
  indented `1 + 2` is the same rule, as is `var`/`:=` (both take a
  `bound_expr`: the next-line layout, but no `value_stmt`). Both
  pretty-printers
  normalize it away, printing the value back on the `=` line; the two
  spellings are the same AST.
- A `value_stmt` is rejected in each `bound_expr` position with an error
  naming it (`a 'var' declaration takes an expression; a value-form
  'if'/'match' can only be bound with '='`). A value form binds its
  target in every branch tail, which is what `var` declares and `:=`
  updates — neither of which the branches can decide between.
- Statements before a branch's last one are ordinary statements, run for
  their effect: a branch may bind local names, print, or update an
  enclosing `var` before yielding its value. This is a consequence of
  how a `value_stmt` compiles — it stays one `if`/`match` *statement*,
  with only the branch tails turned into assignments to the target — and
  is why the value form is not the same as an `if_expr` spread over
  several lines.
- `comp_if` and `comp_for`'s sequence are the one place an `if_expr`
  needs parentheses: `[x for x in xs if (if a then b else c)]`. Written
  bare, the comprehension's own `if`/`in` would run straight into the
  `if_expr`'s keywords. Python restricts these exact two positions for
  exactly this reason (its grammar admits only an `or_test` there,
  excluding the conditional expression), so `[x for x in xs if b if a
  else c]` is a syntax error in Python too. Pyking's parser is in fact
  lenient enough to recover in some of these cases, but both
  pretty-printers always emit the parentheses.
- `additive`, `multiplicative`, `shift`, `bit_and`, `bit_xor`, `bit_or`,
  `conjunction` and `disjunction` are left-associative; `power` is
  right-associative.
- `call_tail` can repeat after any atom, so `f(1)(2)` parses (a call
  result can itself be called), even though no example in this document
  uses that. This chaining only applies to a `(` on the *same source row*
  as the atom it follows — a `(` that starts a new row is always treated
  as the start of the next statement instead, never as a continuation of
  the previous one. (There are no statement-separator tokens in this
  grammar at all — see the parser module comment in `src/parser.ml` —
  so without this row check, a statement immediately followed by one
  starting with `(`, e.g. a parenthesized tuple destructuring assignment,
  would be misparsed as one giant chained call.)
- `unary` is where the prefix operators are: `-expr` negates, `!expr`
  is `not` and `~expr` is a bitwise not, and each nests (`- -x`). It
  sits between `multiplicative` and `power`, so it binds tighter than
  `*`/`/` and looser than `^` and a `call_tail` — `-x * y` is
  `(-x) * y`, `-2 ^ 2` is `-(2 ^ 2)`, and `-f(x)` negates the call's
  *result*, not `f`. `not`, the word, binds as loosely as Python's
  instead: `not a == b` is `not (a == b)`, where `!a == b` is
  `(!a) == b`. It
  applies to the operand it precedes and no further, so parentheses are
  what extend it over a sum: `-x + 1` is `(-x) + 1`, not `-(x + 1)`.
- The same `-` token serves both operators and they never compete: a
  binary `-` can only appear where an expression has just ended, a unary
  one only where an expression is about to begin, so spacing never
  matters (`10 - -3`, `10 - - 3` and `10 - -3` all subtract minus three).
  One consequence of the grammar having no statement separators (see
  `call_tail` above) does follow: a statement *starting* with `-` on the
  line after an expression statement continues that expression instead
  of starting a new one, exactly as a leading `(` does.
- A `pattern_atom` admits a negative integer, matching Python
  (`case -1:`). Only a literal — a pattern is matched, never evaluated,
  so there is no expression there for the general `unary` rule to apply
  to.
- `match_stmt` requires at least one `case_clause`.
- Unlike Python, where `match`/`case` are context-sensitive ("soft")
  keywords, they're always reserved in Pyking — a variable or parameter
  can't be named `match` or `case`. The same is true of `Int`, `String`,
  and `Bool` (the atomic type names): they're reserved everywhere, not
  just in type position, so no identifier may be named after one of them
  either; of `then` and `let`, which have no Python counterpart at all; and of
  `true`/`false`, which do have a Python counterpart (`True`/`False`) but
  not this spelling of one — a Pyking program cannot use `true`, `false`,
  `True`, or `False` as an identifier (the first two because they're
  keywords, the last two because they're simply unbound: Pyking has no
  binding for Python's capitalised spelling). `use`, `lam`, `and`, `or`,
  `not`, `xor` and `mutable` (of `mutable struct`) are keywords too, and `class`, `interface`, `extends`,
  `self` and `super` are reserved for a later part of the language:
  nothing uses them yet, and no program may bind one (`'class' is
  reserved for a later part of the language, so it cannot be used as a
  name`).
- `assignment`'s `[ ":" , type ]` annotates the *binding*, e.g.
  `x: Int = 1`. Like every other annotation it is optional and nothing
  verifies it (see "Type annotations"), but it is the one the type
  checker writes back into: `pyk compile -t pyking` prints each binding
  with the type it inferred, in exactly this syntax, so that output can
  be fed back to the compiler. A destructuring target takes one
  annotation for the whole binding, not one per name.
- `param`'s `[ ":" , type ]` and `function_def`'s `[ "->" , type ]` are
  both optional and independent — a function may annotate none, some, or
  all of its parameters, with or without a return type. Annotations are
  purely syntactic in an ordinary compile: they're parsed, stored in the
  AST, and pretty-printed back out, and every backend erases them
  completely — no generated code carries type syntax at all. Whether
  anything is *verified* against them is a separate question, answered by
  "Types and type inference" in the Language reference.
- **A tuple type is written the way the tuple value is.** A tuple `type`
  with zero elements, `()`, is the Unit type; one with a single element
  is `(Int,)`, carrying the same comma the singleton value `(1,)`
  carries; and `(Int, Bool)` upwards needs no comma to be a tuple, with
  a trailing one allowed as it is among values. So `(1,)` has type
  `(Int,)` and `(1, true)` has type `(Int, Bool)`, each spelled like the
  value it describes. Tuple and list types nest arbitrarily, e.g.
  `[(Int, Bool)]`, `(Int, [String], (Bool, Bool))` or `((Int,),)`.
- **Parentheses around one type are grouping**, exactly as they are
  around one expression: `(Int)` is `Int`, `((Int))` is `Int` again, and
  `(1)` is likewise just `1`. The comma is the whole difference between
  grouping and a singleton, in types and in values alike — which is why
  a singleton must be written with it in both.
- The trailing `[ "->" , type ]` in `type` is what makes a **function
  type**, `(Int, Bool) -> Int`. The parenthesized list before the arrow
  is the *parameter list*, and the same list without an arrow after it is
  a tuple — which is the whole rule, decided by the one token after `)`.
  So `(Int, Bool)` is a pair, `(Int, Bool) -> Int` takes two parameters,
  and `((Int, Bool)) -> Int` takes one parameter that is a pair. The
  arrow settles the singleton too: `(Int) -> Int` and `(Int,) -> Int`
  both take one `Int` — the comma is a list's, and there is no tuple
  there for it to make — while `((Int,)) -> Int` takes one parameter
  that *is* a one-tuple. The
  result is a `type` in its turn, so `->` groups to the right:
  `(Int) -> (Int) -> Int` returns a function and needs no parentheses of
  its own. A function type may appear wherever a type may, including
  nested inside list and tuple types — `[(Int) -> Bool]`,
  `((Int) -> Int, Int)` — and as another function type's parameter,
  `((Int) -> Int) -> Int`.
- The same is true of `tuple_lit`, `target_atom`, and `pattern_atom` —
  and of `type_paren` above, which is the point of writing them alike:
  `()` is the empty tuple, and a *parenthesized* single element followed
  by a comma, e.g. `(1,)`, `(x,)`, `case (p,):` or `(Int,)`, is a genuine
  singleton tuple/target/pattern/type, distinct from a plain
  parenthesized `(1)`/`(x)`/`(p)`/`(Int)` (which is just grouping,
  unwrapped by the parser). Tuples nest arbitrarily in all four
  positions.
- `tuple_or_expr`, `target`, and `pattern` all also accept a *bare*
  (unparenthesized) form — `1, 2`, `a, b`, `case a, b:` — but deliberately
  require at least two elements and forbid a trailing comma there: a
  singleton must be written with explicit parens, `(e,)`/`(name,)`/
  `case (p,):`. This isn't just a style rule — since (as noted above)
  there are no statement-separator tokens, a bare trailing comma is
  genuinely ambiguous with the start of the next statement, and the
  parser doesn't detect or reject it: `x = 1,` followed by `print(x)` on
  the next line silently parses as the single statement
  `x = (1, print(x))` instead of two statements. Always use the
  parenthesized singleton form when there's any doubt.
- `pattern_atom` is intentionally minimal beyond tuples and lists: an
  integer, string, or boolean literal matches only that exact value; `_`
  always matches, discarding the value; a plain `ident` also always
  matches, but binds the value to that name; a parenthesized group
  destructures a tuple value element-by-element; a `list_pattern`
  destructures a list value; a `constructor_pattern` destructures a
  datatype's value. All of these nest arbitrarily (e.g.
  `case (a, [b, ..c]):`). An identifier starting with an uppercase
  letter is a constructor wherever a pattern holds it, so `case Red:`
  matches the constructor `Red` rather than binding a name.
- `|` binds looser than `+` and tighter than `as`, which binds looser
  than everything but the comma: `case 1 | 2, x as y:` is
  `case (1 | 2), (x as y):`. Every alternative of a `|` binds the same
  names, refused at parse time otherwise:

  ```
  'prog.pyk' 3:22-3:28 Parsing error: every alternative of '|' binds
    the same names, and 'x' is bound in one of them but not in this one
  ```
- A guard is any expression, read after the pattern and up to the
  `:`. It is asked only once its pattern has matched, and it sees the
  names the pattern binds.
- A `datatype` is written at a module's top level only; inside a block
  it is a parse error. Two constructors on one line are separated by a
  comma, and a line of them after the header's starts a line of its
  own. A field written
  `name = default` with no type takes its default's type (see
  "Datatypes"). A `struct` is written at the top level too, and two
  fields on one of its lines are separated by a comma.
- `..expr` is written only as the last argument of a constructor, and
  at most once; in a call to a `def` it is a parse error.
- An uppercase identifier in an expression is a constructor. Every
  name a program binds -- with `=`, `var` or `def`, as a parameter, a
  loop variable, in a pattern, or as an import's alias -- starts with a
  lowercase letter or `_`; one starting with an uppercase letter is
  refused at parse time, since an uppercase name is a type or a
  constructor. A constant is written `pi = 3.14`, not `PI = 3.14`. A
  `from` line renaming a datatype or a constructor gives it a name
  starting with an uppercase letter, as the name it renames does.
- `x.name` reads a field where `x` is a value, and reaches a module's
  public name where `x` is an imported module; the two are told apart by
  what `x` is bound to. The `.` and the field name are on the line the
  value ends on.
- No pattern (tuple, list, or nested combination of either) may bind the
  same name more than once — e.g. `case [a, ..b, a]:` is rejected at
  parse time with "duplicate binding 'a' in pattern". This mirrors
  Python's own restriction on repeated names within one `match` pattern,
  mirroring Python's own restriction on repeated names within one
  `match` pattern.
- `list_pattern_items` may contain **at most one** `rest_marker`,
  appearing anywhere among the items — patterns before it are a prefix
  that must match the start of the list, patterns after it are a suffix
  that must match the end, and `rest_marker` itself consumes everything
  in between (possibly nothing). A bare `..` matches and discards that
  middle portion; `..name` matches and binds it (as a list) to `name`.
  With no rest marker at all, `list_pattern` matches only a list of
  exactly that length. `[]` matches only the empty list.
- `comp_for`'s `pattern` is `pattern` (i.e. the *full* pattern grammar,
  same as a `case_clause`'s), not just a name or Python's assignment-like
  targets — this is Pyking's one deliberate departure from Python's own
  comprehension grammar. An element the pattern doesn't match (a literal
  that doesn't equal it, or a list pattern whose shape doesn't fit) is
  silently filtered out of the result — it never raises an error. (A
  `match`, unlike a comprehension, has to match every value; see
  "Exhaustiveness".) `list_comp` always starts with a `comp_for`; `comp_for`/
  `comp_if` may then repeat in any order, matching Python's own
  multi-clause comprehensions (nested `for`s, interspersed `if`s).
- A `qualified_name` may be a **definition's** name and nothing else --
  not a binding, a `var`, a parameter, a loop variable, a pattern
  capture, a module name or an import alias -- and the definition must
  take at least one argument, since the arguments of a call are what
  resolve which of them is meant. Both are refused where they are
  written (`'int::zero' takes no argument, so nothing could say which
  definition of 'zero' a call means`). A module-qualified name is
  `m.int::leq`: the module is written with a `.` and the definition's
  own qualifier with a `::`, and the two never mix.
- A **dotted** `def_name`, datatype name or `=` target -- `mymod.foo` --
  defines a name in a submodule (see "Submodules"), and is written only
  at a module's top level: inside a block it is refused. A
  `qualified_name` goes last, `mymod.int::abs`. Every `.` in a dotted
  name, in a `module_path` and in a `sub_path` is on the row the name
  before it ended on.
- `implicit` in front of a statement marks a `def` or an `=` binding of
  one name, and nothing else. It is a statement's prefix rather than a
  top-level one, so a definition inside a function may be implicit
  there and nowhere else; `public implicit def ...` is written in that
  order.
- An `implicit_param` needs both its name and its type written: the
  pair is what resolves it. It may not carry a default value, and a
  lambda may not have one at all.
- `lambda_params` shares `param` with `function_def`, but a lambda
  parameter may **not** carry a default value: a default is evaluated in
  the scope the definition is written in, and a lambda is an expression
  written wherever it stands. Writing one is refused (`the lambda
  parameter 'x' may not have a default value; only a 'def' parameter
  may`).
- A lambda starts with `lam`, so nothing has to be tried to tell one
  from a parenthesized expression: `(x)` after `lam` is a parameter
  list, and anywhere else the expression `x`. The `.` ending the
  parameters is the first one after them, which is why a parameter with
  a type is parenthesized: `lam x: geo.Point. x` would end its type at
  the wrong `.`.
- In a pattern, `+` joins pieces (`[x] + xs`) and `|` separates
  alternatives; `||` there is refused as the slip it is (`alternatives
  in a pattern are separated by '|', not '||'`). A pattern holds no
  expressions, so its `|` and an expression's bitwise `|` never meet --
  a guard is an expression, and its `|` is bitwise or.
- **A line may be continued while a bracket is open.** The lexer
  synthesizes `INDENT`/`DEDENT` from each physical line's leading
  whitespace (see "Indentation-based blocks" below), and suspends that
  entirely while an `(` or `[` is unclosed — so a parameter list, a
  call's arguments, a list literal, a comprehension and a tuple may each
  span several lines. The continuation lines are part of the same
  statement and their own indentation means nothing; outside brackets,
  indentation means exactly what it did. See "Lines and continuation".
- `block`'s bare-`expr_stmt` alternative is taken **only** when that
  expression begins on the row the header's `:` ends on. The EBNF cannot
  state this, for the same reason it cannot state "a statement starts a
  line of its own": the lexer emits no token for a line break, so both
  are checked in `src/parser.ml` against the positions the tokens
  already carry. A block that begins on the *next* line without being
  indented is therefore not an inline block but the error it always was
  (`expected an indented block`).
- It is an `expr_stmt`, not a `statement`: only a value may be written
  there. A `return`, a binding, a `:=`, or a nested header is refused
  where it stands (`a block written on its header's own line must be
  one expression, and 'return a' is not; write it in an indented block
  instead`), so no line ever hides control flow or a new name behind
  its `:`. An `if` written there is the `if_expr`, which is an
  expression; the statement form is not.
- An inline block **ends its line**. Nothing may be indented under it
  (`a block written on its header's own line is the whole block, so
  nothing may be indented under it`), and nothing may continue the
  construct on the same line — an `else` has to start the next one
  (`'else' must start on a new line: the block written on the header's
  own line ends that line`). A second *statement* after it on the line
  is caught by the one-statement-per-line rule instead, since it is a
  sibling of the header rather than part of its block.
- The two layouts are the same program. `def add(a, b): a + b` parses to
  exactly what `def add(a, b):` followed by an indented `a + b` parses
  to, so nothing after the parser can tell them apart — including the
  pretty-printer, which prints every block indented.
- The rule is the *block's*, so it holds wherever a block does:
  `function_def`, `if_stmt` and its `else`, `for_stmt`, `while_stmt`,
  `loop_stmt` and `case_clause`. A `match_stmt`'s clause list is not a
  block and has no inline form.

## Syntax by mode

One parser reads every module. A `use` line adds no syntax; it allows
what the parser already reads:

| Mode | Allows |
|---|---|
| `use mutation` | `var_decl`, `:=` and compound assignment, `mutable struct`, and the calls that make and write Arrays, DynArrays, MutMaps and views |
| `use pointers` (with `mutation`) | `&` and `*` in expressions, and `*p := v` |
| `use objects` | `class`, `abstract class` and `interface` declarations |

A construct of a mode the module has not turned on is refused as a
`Parsing error` that names the `use` line it needs.

## Compared with Python

**The same as Python:** indentation-based blocks, `def`, `if`/`else`,
`for … in`, `while`, `return`, list comprehensions, `match`/`case`,
indexing and slicing, `import`, `from … import … as`, `#` comments, and
most operators (`+ - * / %`, comparisons, `and`/`or`/`not`, bitwise
operators).

**Different:**

| Python | Pyking |
|---|---|
| `True`, `False` | `true`, `false` |
| `elif` | `else if` |
| `a ** b` | `a ^ b` |
| `lambda x: x + 1` | `lam x. x + 1` |
| `a if c else b` | `if c then a else b` |
| `'text'` or `"text"` | `"text"`; `'c'` is a Char |
| `f"{a} and {b + 1}"` | `"$a and ${b + 1}"`, in every String |
| `print(x, end="")`, `print(x, file=sys.stderr)` | `printsl(x)`, `eprint(x)` |
| `1 < 2 < 3` | refused: `1 < 2 and 2 < 3` |
| `x = x + 1` updating `x` | `x := x + 1`, on a `var x` |
| `(y := 3)`, the walrus | `:=` is a statement, never an expression |
| `class A:` with fields assigned in `__init__` | `class A(x: Int):`, under `use objects` |
| `copy.copy(x)`, `copy.deepcopy(x)` | `copy(x)`, `deepcopy(x)`: builtins, no import |

**New in Pyking:** `use`, `var`, `datatype`, `struct`, `mutable struct`,
`$name` interpolation without braces, `printsl`/`eprint`/`eprintsl`,
`let … in`, `loop`, `public`, `implicit`, `Type::name` overloading, type
annotations that are checked, and pointers (`&`, `*`).

**Not in Pyking:** `try`/`except`/`raise` (use `Result` and `panic`),
`with`, decorators (`@` is not a character Pyking reads), `*args` and
`**kwargs`, `yield`, `async`, `global`/`nonlocal`, `assert`, `del`,
format specifications (`{x:.2f}`), dict and set literals (`{` is not read; use `map(...)`), the
`in` and `is` operators, `//` (Int `/` already truncates), and
`while … else`. Where the parser can tell what was meant -- `elif`,
`**`, a chained comparison, a String in single quotes -- the error says
what to write instead.
