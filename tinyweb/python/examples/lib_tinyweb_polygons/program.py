# --- prelude begins ---
# Pyking prints a Bool as `true`/`false`, not Python's own capitalised
# `True`/`False`, wherever it sits -- on its own, or inside a list or
# a tuple. This helper exists because at least one value printed below
# isn't provably free of Bools from its Pyking source form alone (a
# variable, a call, or a container), so it is walked at runtime.

def __pyk_str(v, top):
    if isinstance(v, bool):
        return 'true' if v else 'false'
    if isinstance(v, float):
        return __pyk_float(v)
    if isinstance(v, str):
        if top:
            return v
        out = '\''
        for c in v:
            out = out + ('\\\\' if c == '\\' else '\\\'' if c == '\'' else '\\n' if c == '\n' else '\\t' if c == '\t' else '\\r' if c == '\r' else c)
        return out + '\''
    if isinstance(v, list):
        out = ''
        for e in v:
            out = out + ('' if out == '' else ', ') + __pyk_str(e, False)
        return '[' + out + ']'
    if isinstance(v, tuple):
        out = ''
        for e in v:
            out = out + ('' if out == '' else ', ') + __pyk_str(e, False)
        if len(v) == 1:
            return '(' + out + ',)'
        return '(' + out + ')'
    if hasattr(v, '_pyk_tag'):
        out = ''
        for f in v.__match_args__:
            e = getattr(v, f)
            out = out + ('' if out == '' else ', ') + __pyk_str(e, False)
        return v._pyk_tag + ('(' + out + ')' if v.__match_args__ else '')
    return str(v)

def __pyk_fdiv(a, b):
    if b == 0.0:
        # Python raises where IEEE answers. Pyking follows IEEE.
        if a != a or a == 0.0:
            return float('nan')
        below = (a < 0.0) != (repr(b)[0] == '-')
        return float('-inf') if below else float('inf')
    return a / b


def __pyk_float(x):
    if x != x:
        return 'nan'
    if x == float('inf'):
        return 'inf'
    if x == float('-inf'):
        return '-inf'
    if x == 0.0:
        # The two zeros compare equal; repr tells them apart.
        return '-0.0' if repr(x)[0] == '-' else '0.0'
    sign = '-' if x < 0.0 else ''
    a = abs(x)
    p = 0
    while p < 16:
        s = '%.*e' % (p, a)
        if float(s) == a:
            break
        p = p + 1
    else:
        s = '%.*e' % (16, a)
    at = s.index('e')
    digits = s[:at].replace('.', '')
    decpt = int(s[at + 1:]) + 1
    digits = digits.rstrip('0') or '0'
    n = len(digits)
    if decpt <= -4 or decpt > 16:
        mantissa = digits if n == 1 else digits[0] + '.' + digits[1:]
        return sign + mantissa + 'e' + str(decpt - 1)
    if decpt <= 0:
        return sign + '0.' + '0' * (-decpt) + digits
    if decpt >= n:
        return sign + digits + '0' * (decpt - n) + '.0'
    return sign + digits[:decpt] + '.' + digits[decpt:]

# --- prelude ends; the compiled program follows ---

import tinyweb as tw
import tinyweb_external as tw_external
from tinyweb import colors__palette as palette
tw.web_init(0)
c = tw_external.canvas(200, 200)
ocean = palette('ocean')
print(len(ocean))
tw.polygon(c, [(100, 10), (130, 90), (70, 90)], 'orange', 'black', tw.polygon__default__outline_width(), tw.polygon__default__alpha())
tw.path(c, [(10, 190), (60, 120), (110, 170), (190, 110)], 'teal', 3, tw.path__default__alpha())
tw.polygon(c, [], 'red', tw.polygon__default__outline(), tw.polygon__default__outline_width(), tw.polygon__default__alpha())
print(__pyk_str(palette('nothing'), True))
