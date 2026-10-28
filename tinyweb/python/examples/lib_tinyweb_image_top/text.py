# --- prelude begins ---

def __pyk_div(a, b):
    q = abs(a) // abs(b)
    return q if (a < 0) == (b < 0) else -q

class __PykChar(str):
    # A Char: one code point, told from a String when printed.
    __slots__ = ()

__pyk_code = ord

def __pyk_char_of_int(n, chr=chr):
    if 0 <= n <= 0x10FFFF and not 0xD800 <= n <= 0xDFFF:
        return __PykChar(chr(n))
    return __PykChar('\0')

def __pyk_chars(s):
    return (__PykChar(c) for c in s)

# --- prelude ends; the compiled program follows ---

import text_external

def within(k, top):
    if k < 0:
        return 0
    elif k > top:
        return top
    else:
        return k

def blank(c):
    match c:
        case 32 | 9 | 10 | 13:
            return True
        case _:
            return False

def filled(s):
    return False if s == '' else True

def length(s):
    return text_external.host_length(s)

def slice(s, start, stop):
    n = text_external.host_length(s)
    a = within(start, n)
    b = within(stop, n)
    return '' if b <= a else text_external.host_slice(s, a, b)

def char_at(s, k):
    if k < 0:
        return __PykChar('\x00')
    elif k < len(s):
        return __PykChar(s[k])
    else:
        return __PykChar('\x00')

def code(c):
    return __pyk_code(c)

def from_code(n):
    return __pyk_char_of_int(n)

def chars(s):
    return [c for c in __pyk_chars(s)]

def from_chars(cs):
    return join([str(c) for c in cs], '')

def find(s, part, start):
    n = text_external.host_length(s)
    if start > n:
        return -1
    elif part == '':
        return within(start, n)
    else:
        return text_external.host_find(s, part, within(start, n))

def contains(s, part):
    return find(s, part, 0) >= 0

def starts_with(s, prefix):
    return slice(s, 0, text_external.host_length(prefix)) == prefix

def ends_with(s, suffix):
    n = text_external.host_length(s)
    m = text_external.host_length(suffix)
    return False if m > n else text_external.host_slice(s, n - m, n) == suffix

def upper(s):
    return text_external.host_upper(s)

def lower(s):
    return text_external.host_lower(s)

def trim(s):
    n = text_external.host_length(s)
    i = 0
    while i < n:
        if blank(text_external.host_code(s, i)):
            i = i + 1
        else:
            break
    first = i
    j = n
    while j > first:
        if blank(text_external.host_code(s, j - 1)):
            j = j - 1
        else:
            break
    last = j
    return '' if last <= first else text_external.host_slice(s, first, last)

def replace(s, old, new):
    return s if old == '' else text_external.host_replace(s, old, new)

def repeat(s, n):
    (k, piece, out2) = (n, s, '')
    while True:
        if k <= 0:
            break
        else:
            half = __pyk_div(k, 2)
            more = out2 + piece if k - half * 2 == 1 else out2
            (k, piece, out2) = (half, piece if half == 0 else piece + piece, more)
    (__, __, out) = (k, piece, out2)
    return out

def split(s, by):
    if by == '':
        return [s]
    else:
        m = text_external.host_length(by)
        (at2, parts2) = (0, [])
        while True:
            k = text_external.host_find(s, by, at2)
            if k < 0:
                break
            else:
                (at2, parts2) = (k + m, parts2 + [text_external.host_slice(s, at2, k)])
        (at, parts) = (at2, parts2)
        return parts + [text_external.host_slice(s, at, text_external.host_length(s))]

def words(s):
    spaced = text_external.host_replace(text_external.host_replace(text_external.host_replace(s, '\t', ' '), '\n', ' '), '\r', ' ')
    return [w for w in split(spaced, ' ') if filled(w)]

def join(parts, between):
    whole = ''
    chunk = ''
    count = 0
    chunks = 0
    for part in parts:
        chunk = part if count == 0 else chunk + between + part
        count = count + 1
        if count == 128:
            whole = chunk if chunks == 0 else whole + between + chunk
            chunks = chunks + 1
            chunk = ''
            count = 0
    return whole if count == 0 else chunk if chunks == 0 else whole + between + chunk

def lines(s):
    if s == '':
        return []
    else:
        unix = text_external.host_replace(s, '\r\n', '\n')
        ended = text_external.host_slice(unix, 0, text_external.host_length(unix) - 1) if ends_with(unix, '\n') else unix
        return split(ended, '\n')
