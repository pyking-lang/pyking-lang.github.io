# --- prelude begins ---

def __pyk_fdiv(a, b):
    if b == 0.0:
        # Python raises where IEEE answers. Pyking follows IEEE.
        if a != a or a == 0.0:
            return float('nan')
        below = (a < 0.0) != (repr(b)[0] == '-')
        return float('-inf') if below else float('inf')
    return a / b


def __pyk_fmod(a, b):
    # Python's fmod raises on a zero divisor or an infinite
    # dividend, where IEEE answers NaN.
    if b == 0.0 or a != a or b != b or a in (float('inf'), float('-inf')):
        return float('nan')
    return __import__('math').fmod(a, b)


def __pyk_fpow(a, b):
    # Python's pow raises on an overflow, a zero to a negative
    # power and a negative number to a fraction, where IEEE
    # answers an infinity or a NaN.
    odd = b == b and abs(b) != float('inf') and b == int(b) and int(b) % 2 == 1
    try:
        return __import__('math').pow(a, b)
    except OverflowError:
        return float('-inf') if a < 0.0 and odd else float('inf')
    except ValueError:
        if a == 0.0:
            return float('-inf') if repr(a)[0] == '-' and odd else float('inf')
        return float('nan')


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
from tinyweb import Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop
from tinyweb import color__palette as palette
from tinyweb import Point
tw.web_init(0)
c = tw_external.canvas(200, 200)
ocean = palette('ocean')
print(len(ocean))
tw.polygon(c, [Point(100, 10), Point(130, 90), Point(70, 90)], color__orange, color__black, 1, 1.0, tw.polygon__default__paint(), tw.polygon__default__style())
tw.path(c, [Point(10, 190), Point(60, 120), Point(110, 170), Point(190, 110)], color__teal, 3, 1.0, tw.path__default__style())
tw.polygon(c, [], color__red, tw.polygon__default__stroke(), 1, 1.0, tw.polygon__default__paint(), tw.polygon__default__style())
tw.lines(c, [(Point(0, 0), Point(20, 20)), (Point(20, 0), Point(0, 20))], color__navy, 1, 1.0, tw.lines__default__style())
print(len(palette('nothing')))
