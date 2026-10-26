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

def __pyk_trunc(x):
    if x != x or x in (float('inf'), float('-inf')):
        return 0
    n = int(x)
    return n if -2147483648 <= n <= 2147483647 else 0

# --- prelude ends; the compiled program follows ---

import tinyweb as tw
import tinyweb_external as tw_external
from tinyweb import bitmap__bitmap, bitmap__set_pixel, bitmap__get_pixel, bitmap__fill_bitmap, bitmap__show_bitmap, bitmap__bitmap__default__background
from tinyweb import Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop
tw.web_init(0)
c = tw_external.canvas(160, 100)

def show(p):
    return str(p.r) + ' ' + str(p.g) + ' ' + str(p.b)

b = bitmap__bitmap(16, 10, bitmap__bitmap__default__background())
print('a new bitmap is white:', show(bitmap__get_pixel(b, 3, 3)))
print('or its background:', show(bitmap__get_pixel(bitmap__bitmap(2, 2, color__green), 1, 1)))
for y in range(10):
    for x in range(16):
        bitmap__set_pixel(b, x, y, color__rgb(x * 16, y * 25, 128))
bitmap__show_bitmap(c, b, 0, 0, 10.0)
orange = color__rgb(255, 136, 0)
bitmap__set_pixel(b, 4, 2, orange)
bitmap__set_pixel(b, 7, 5, orange)
bitmap__set_pixel(b, 40, 2, orange)
print('pixel (4, 2):', show(bitmap__get_pixel(b, 4, 2)), 'outside:', show(bitmap__get_pixel(b, -1, 0)), __pyk_float(bitmap__get_pixel(b, -1, 0).a))
bitmap__show_bitmap(c, b, 0, 0, 10.0)
bitmap__show_bitmap(c, b, 5, 5, 1.0)
small = bitmap__bitmap(4, 4, bitmap__bitmap__default__background())
bitmap__fill_bitmap(small, color__blue)
print('filled:', bitmap__get_pixel(small, 3, 3).b)

def frame(t):
    bitmap__set_pixel(small, 1, 1, color__rgb(__pyk_trunc(t * 100.0), 0, 0))
    return bitmap__show_bitmap(c, small, 120, 60, 2.0)

bitmap__show_bitmap(c, small, 120, 60, 0.5)
tw_external.on_frame(frame)
