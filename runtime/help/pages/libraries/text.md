---
title: text
description: "Looking inside a String: its length, its characters, finding and replacing a part, and taking it apart into pieces and words."
---

Looking inside a String: its length, its characters, finding and
replacing a part, and taking it apart into pieces and words.

A position or a length counts **characters** -- Unicode code points
-- so `"åäö"` has length 3 and `"👑"` length 1 on every target. The
first character is at position 0, and a character is a `Char`, as
`s[k]` gives it. `upper`, `lower`, `trim` and
`words` know the ASCII letters and the ASCII spaces only, so every
target answers alike. A String is read as a number by the builtins
`int` and `float`, and a number written as one by `string`.

```pyking norun
import text
```

<div class="pyk-api">

## char_at

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">char_at</span>(<span class="p">s</span>: <span class="t">String</span>, <span class="p">k</span>: <span class="t">Int</span>) -&gt; Char</code></pre>

The character at position `k`: `s[k]`, where `s` has a position `k`.

<p class="pyk-api-label">Parameters</p>

- `s`: the string.
- `k`: the position, 0 for the first character.

<p class="pyk-api-label">Returns</p>

That character, or `'\0'` where `s` has no position `k`.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.char_at("åäö 👑", 4), text.char_at("abc", 0))
print(text.char_at("abc", 3) == '\0')
```

```stdout visible = true
👑 a
true
```

</div>

<div class="pyk-api">

## chars

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">chars</span>(<span class="p">s</span>: <span class="t">String</span>) -&gt; [Char]</code></pre>

The characters of a string, in order: what `for c in s` walks.

<p class="pyk-api-label">Parameters</p>

- `s`: the string.

<p class="pyk-api-label">Returns</p>

A list of its characters, empty for `""`.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.chars("hé!"), text.chars(""))
```

```stdout visible = true
['h', 'é', '!'] []
```

</div>

<div class="pyk-api">

## code

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">code</span>(<span class="p">c</span>: Char) -&gt; <span class="t">Int</span></code></pre>

The number of a character: its Unicode code point, as `int(c)` gives
it.

<p class="pyk-api-label">Parameters</p>

- `c`: the character.

<p class="pyk-api-label">Returns</p>

The code point.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.code('A'), text.code("åäö 👑"[4]))
```

```stdout visible = true
65 128081
```

</div>

<div class="pyk-api">

## contains

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">contains</span>(<span class="p">s</span>: <span class="t">String</span>, <span class="p">part</span>: <span class="t">String</span>) -&gt; <span class="t">Bool</span></code></pre>

Tells whether `part` appears anywhere in `s`.

<p class="pyk-api-label">Parameters</p>

- `s`: the string to look in.
- `part`: what to look for.

<p class="pyk-api-label">Returns</p>

`true` if it does; an empty `part` is in every string.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.contains("hello", "ell"), text.contains("hello", "Hell"))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## ends_with

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">ends_with</span>(<span class="p">s</span>: <span class="t">String</span>, <span class="p">suffix</span>: <span class="t">String</span>) -&gt; <span class="t">Bool</span></code></pre>

Tells whether `s` ends with `suffix`.

<p class="pyk-api-label">Parameters</p>

- `s`: the string.
- `suffix`: what it may end with.

<p class="pyk-api-label">Returns</p>

`true` if it does; every string ends with `""`.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.ends_with("photo.png", ".png"), text.ends_with("photo.png", ".jpg"))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## find

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">find</span>(<span class="p">s</span>: <span class="t">String</span>, <span class="p">part</span>: <span class="t">String</span>, <span class="p">start</span>: <span class="t">Int</span> = 0) -&gt; <span class="t">Int</span></code></pre>

Where `part` first appears in `s`, at or after position `start`.

<p class="pyk-api-label">Parameters</p>

- `s`: the string to look in.
- `part`: what to look for.
- `start`: where to begin looking; 0, the start, by default. Below 0 counts as 0.

<p class="pyk-api-label">Returns</p>

The position `part` begins at, or -1 if it is nowhere from `start`
on. An empty `part` is found at once, at `start`.

<p class="pyk-api-label">Example</p>

```pyking
import text
s = "one two one"
print(text.find(s, "one"), text.find(s, "one", 1), text.find(s, "three"))
print(text.find("åäö 👑", "👑"))
```

```stdout visible = true
0 8 -1
4
```

</div>

<div class="pyk-api">

## from_chars

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">from_chars</span>(<span class="p">cs</span>: [Char]) -&gt; <span class="t">String</span></code></pre>

A string of characters: `chars`'s other way round.

<p class="pyk-api-label">Parameters</p>

- `cs`: the characters.

<p class="pyk-api-label">Returns</p>

The string they spell, `""` for none.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.from_chars(['o', 'k']), text.from_chars(text.chars("åäö")))
```

```stdout visible = true
ok åäö
```

</div>

<div class="pyk-api">

## from_code

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">from_code</span>(<span class="p">n</span>: <span class="t">Int</span>) -&gt; Char</code></pre>

The character whose code point is `n`: `code`'s other way round, as
`char(n)` gives it.

<p class="pyk-api-label">Parameters</p>

- `n`: the code point.

<p class="pyk-api-label">Returns</p>

That character, or `'\0'` where `n` is not one: a negative number, a
surrogate (55296 to 57343) or past 1114111.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(string(text.from_code(65)) + string(text.from_code(229)) + string(text.from_code(128081)))
print(text.from_code(-1) == '\0')
```

```stdout visible = true
Aå👑
true
```

</div>

<div class="pyk-api">

## join

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">join</span>(<span class="p">parts</span>: [<span class="t">String</span>], <span class="p">between</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

`parts` joined into one string, with `between` between each two.

<p class="pyk-api-label">Parameters</p>

- `parts`: the strings to join.
- `between`: what goes between two of them.

<p class="pyk-api-label">Returns</p>

The joined string; `""` where `parts` is empty.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.join(["a", "b", "c"], ", "))
print(text.join(text.words(" spaced   out "), "_"))
```

```stdout visible = true
a, b, c
spaced_out
```

</div>

<div class="pyk-api">

## length

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">length</span>(<span class="p">s</span>: <span class="t">String</span>) -&gt; <span class="t">Int</span></code></pre>

The number of characters in `s`.

<p class="pyk-api-label">Parameters</p>

- `s`: the string.

<p class="pyk-api-label">Returns</p>

How many characters it holds, each counted once however many bytes
it takes.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.length("hello"), text.length("åäö 👑"), text.length(""))
```

```stdout visible = true
5 5 0
```

</div>

<div class="pyk-api">

## lines

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">lines</span>(<span class="p">s</span>: <span class="t">String</span>) -&gt; [<span class="t">String</span>]</code></pre>

The lines of `s`. A line ends at a newline, or at a carriage return
and a newline, which is not part of it; the last line need not end
in one.

<p class="pyk-api-label">Parameters</p>

- `s`: the string.

<p class="pyk-api-label">Returns</p>

The lines, without their line endings; `[]` where `s` is `""`.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.lines("one\r\ntwo\n\nfour\n"))
```

```stdout visible = true
["one", "two", "", "four"]
```

</div>

<div class="pyk-api">

## lower

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">lower</span>(<span class="p">s</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

`s` with every ASCII letter in lower case. Every other character,
`Å` among them, is left as it is.

<p class="pyk-api-label">Parameters</p>

- `s`: the string.

<p class="pyk-api-label">Returns</p>

The string in lower case.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.lower("Hello, ÅSA!"))
```

```stdout visible = true
hello, Åsa!
```

</div>

<div class="pyk-api">

## repeat

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">repeat</span>(<span class="p">s</span>: <span class="t">String</span>, <span class="p">n</span>: <span class="t">Int</span>) -&gt; <span class="t">String</span></code></pre>

`s` written `n` times, one after the other.

<p class="pyk-api-label">Parameters</p>

- `s`: the string.
- `n`: how many times; 0 or less gives `""`.

<p class="pyk-api-label">Returns</p>

The repeated string.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.repeat("ab", 3), text.repeat("-", 10))
```

```stdout visible = true
ababab ----------
```

</div>

<div class="pyk-api">

## replace

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">replace</span>(<span class="p">s</span>: <span class="t">String</span>, <span class="p">old</span>: <span class="t">String</span>, <span class="p">new</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

`s` with every `old` in it replaced by `new`, from left to right: an
`old` that overlaps one already replaced is not replaced.

<p class="pyk-api-label">Parameters</p>

- `s`: the string.
- `old`: what to replace. Where it is `""`, `s` is answered as it is.
- `new`: what to put in its place.

<p class="pyk-api-label">Returns</p>

The string with the replacements made.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.replace("one two one", "one", "1"))
print(text.replace("aaa", "aa", "b"))
```

```stdout visible = true
1 two 1
ba
```

</div>

<div class="pyk-api">

## slice

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">slice</span>(<span class="p">s</span>: <span class="t">String</span>, <span class="p">start</span>: <span class="t">Int</span>, <span class="p">stop</span>: <span class="t">Int</span>) -&gt; <span class="t">String</span></code></pre>

The characters of `s` from `start` up to, but not including, `stop`.
A position below 0 counts as 0 and one past the end as the end.

<p class="pyk-api-label">Parameters</p>

- `s`: the string.
- `start`: where the part begins.
- `stop`: where it ends.

<p class="pyk-api-label">Returns</p>

That part of `s`, or `""` where `stop` is not after `start`.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.slice("hello world", 6, 11))
print(text.slice("åäö 👑", 2, 100))
print(text.slice("hello", 3, 1) == "")
```

```stdout visible = true
world
ö 👑
true
```

</div>

<div class="pyk-api">

## split

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">split</span>(<span class="p">s</span>: <span class="t">String</span>, <span class="p">by</span>: <span class="t">String</span>) -&gt; [<span class="t">String</span>]</code></pre>

The pieces of `s` between the occurrences of `by`, from left to
right.

<p class="pyk-api-label">Parameters</p>

- `s`: the string.
- `by`: what separates the pieces. Where it is `""`, the one piece is `s`.

<p class="pyk-api-label">Returns</p>

The pieces, one more than there are occurrences of `by`; a piece is
`""` where two of them are next to each other or one is at an end.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.split("a,b,,c", ","))
print(text.split("one and two", " and "))
```

```stdout visible = true
["a", "b", "", "c"]
["one", "two"]
```

</div>

<div class="pyk-api">

## starts_with

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">starts_with</span>(<span class="p">s</span>: <span class="t">String</span>, <span class="p">prefix</span>: <span class="t">String</span>) -&gt; <span class="t">Bool</span></code></pre>

Tells whether `s` begins with `prefix`.

<p class="pyk-api-label">Parameters</p>

- `s`: the string.
- `prefix`: what it may begin with.

<p class="pyk-api-label">Returns</p>

`true` if it does; every string begins with `""`.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.starts_with("hello", "he"), text.starts_with("he", "hello"))
```

```stdout visible = true
true false
```

</div>

<div class="pyk-api">

## trim

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">trim</span>(<span class="p">s</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

`s` without the spaces, tabs, newlines and carriage returns at either
end.

<p class="pyk-api-label">Parameters</p>

- `s`: the string.

<p class="pyk-api-label">Returns</p>

The string from its first character that is none of those to its
last.

<p class="pyk-api-label">Example</p>

```pyking
import text
print("[" + text.trim("  two words \n") + "]")
```

```stdout visible = true
[two words]
```

</div>

<div class="pyk-api">

## upper

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">upper</span>(<span class="p">s</span>: <span class="t">String</span>) -&gt; <span class="t">String</span></code></pre>

`s` with every ASCII letter in upper case. Every other character,
`å` among them, is left as it is.

<p class="pyk-api-label">Parameters</p>

- `s`: the string.

<p class="pyk-api-label">Returns</p>

The string in upper case.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.upper("Hello, åsa!"))
```

```stdout visible = true
HELLO, åSA!
```

</div>

<div class="pyk-api">

## words

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">words</span>(<span class="p">s</span>: <span class="t">String</span>) -&gt; [<span class="t">String</span>]</code></pre>

The words of `s`: the pieces between its spaces, tabs, newlines and
carriage returns, however many of them there are in a row.

<p class="pyk-api-label">Parameters</p>

- `s`: the string.

<p class="pyk-api-label">Returns</p>

The words, none of them `""`; `[]` where `s` holds no word.

<p class="pyk-api-label">Example</p>

```pyking
import text
print(text.words("  the quick\tbrown \n fox "))
```

```stdout visible = true
["the", "quick", "brown", "fox"]
```

</div>
