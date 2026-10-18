# --- prelude begins ---

def __pyk_div(a, b):
    q = abs(a) // abs(b)
    return q if (a < 0) == (b < 0) else -q

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
from tinyweb import smooth__circle, smooth__circles, smooth__rect, smooth__ellipse, smooth__arc, smooth__polygon, smooth__line, smooth__lines, smooth__path, smooth__curve, smooth__bezier, smooth__text, smooth__clip_circle, smooth__clip_polygon, smooth__circle__default__color, smooth__circle__default__outline, smooth__circle__default__outline_width, smooth__circle__default__alpha, smooth__circles__default__color, smooth__circles__default__outline, smooth__circles__default__outline_width, smooth__circles__default__alpha, smooth__rect__default__color, smooth__rect__default__outline, smooth__rect__default__outline_width, smooth__rect__default__alpha, smooth__rect__default__radius, smooth__ellipse__default__color, smooth__ellipse__default__outline, smooth__ellipse__default__outline_width, smooth__ellipse__default__alpha, smooth__arc__default__color, smooth__arc__default__outline, smooth__arc__default__outline_width, smooth__arc__default__alpha, smooth__polygon__default__color, smooth__polygon__default__outline, smooth__polygon__default__outline_width, smooth__polygon__default__alpha, smooth__line__default__color, smooth__line__default__width, smooth__line__default__alpha, smooth__lines__default__color, smooth__lines__default__width, smooth__lines__default__alpha, smooth__path__default__color, smooth__path__default__width, smooth__path__default__alpha, smooth__curve__default__color, smooth__curve__default__width, smooth__curve__default__alpha, smooth__bezier__default__color, smooth__bezier__default__width, smooth__bezier__default__alpha, smooth__text__default__color, smooth__text__default__size, smooth__text__default__font, smooth__text__default__align, smooth__text__default__bold, smooth__text__default__alpha, smooth__text__default__baseline, smooth__text__default__outline, smooth__text__default__outline_width
tw.web_init(0)
c = tw_external.canvas(200, 120)
smooth__polygon(c, [(100.0, 10.5), (180.5, 90.5), (19.5, 90.5)], 'orange', 'black', 0.5, smooth__polygon__default__alpha())
smooth__path(c, [(10.0, 110.0), (60.5, 20.5), (110.25, 70.0), (190.0, 10.0)], 'teal', 2.5, smooth__path__default__alpha())
rays = [(100.0, 60.0, 100.0 + 45.0 * float(i - __pyk_div(i, 3) * 3), 5.0 * float(i)) for i in list(range(8))]
smooth__lines(c, rays, 'crimson', 0.8, 0.5)
tw.lines(c, [(x, 0, x, 120) for x in list(range(0, 200, 40))], '#cccccc', tw.lines__default__width(), tw.lines__default__alpha())
tw.push(c)
smooth__clip_polygon(c, [(100.0, 5.5), (190.5, 115.0), (9.5, 115.0)])
tw.rect(c, 0, 60, 200, 60, 'gold', tw.rect__default__outline(), tw.rect__default__outline_width(), 0.4, tw.rect__default__radius())
tw.pop(c)
tw.push(c)
tw.clip_polygon(c, [(0, 0), (60, 0), (0, 60)])
tw.rect(c, 0, 0, 60, 60, 'navy', tw.rect__default__outline(), tw.rect__default__outline_width(), tw.rect__default__alpha(), tw.rect__default__radius())
tw.pop(c)
many = [(float(i), 0.0, float(i) + 0.5, 120.0) for i in list(range(300))]
smooth__lines(c, many, 'black', 0.25, 0.1)
print('drew', len(many), 'lines in one go')
