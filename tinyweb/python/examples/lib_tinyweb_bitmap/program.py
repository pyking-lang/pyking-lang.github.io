# --- prelude begins ---

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

def __pyk_trunc(x):
    if x != x or x in (float('inf'), float('-inf')):
        return 0
    n = int(x)
    return n if -2147483648 <= n <= 2147483647 else 0

# --- prelude ends; the compiled program follows ---

import tinyweb as tw
import tinyweb_external as tw_external
tw.web_init(0)
c = tw_external.canvas(160, 100)
b = tw_external.bitmap(16, 10)
print('a new bitmap is black:', tw_external.get_pixel(b, 3, 3))
for y in range(10):
    for x in range(16):
        tw_external.set_pixel(b, x, y, tw.pixel_color(x * 16, y * 25, 128))
tw.show_bitmap(c, b, tw.show_bitmap__default__x(), tw.show_bitmap__default__y(), 10.0)
orange = tw.pixel_color(255, 136, 0)
print('orange is', orange, tw.red(orange), tw.green(orange), tw.blue(orange))
print('clamped:', tw.pixel_color(300, -5, 70))
tw_external.set_pixel(b, 4, 2, orange)
tw_external.set_pixel(b, 7, 5, orange)
tw_external.set_pixel(b, 40, 2, orange)
print('pixel (4, 2):', tw_external.get_pixel(b, 4, 2), 'outside:', tw_external.get_pixel(b, -1, 0))
tw.show_bitmap(c, b, 0, 0, 10.0)
tw.show_bitmap(c, b, 5, 5, tw.show_bitmap__default__scale())
small = tw_external.bitmap(4, 4)
tw_external.fill_bitmap(small, tw.pixel_color(0, 0, 255))
print('filled:', tw.blue(tw_external.get_pixel(small, 3, 3)))
tw.show_bitmap(c, small, 120, 60, 0.5)

def frame(t):
    tw_external.set_pixel(small, 1, 1, tw.pixel_color(__pyk_trunc(t * 100.0), 0, 0))
    return tw.show_bitmap(c, small, 120, 60, 2.0)

tw_external.on_frame(frame)
