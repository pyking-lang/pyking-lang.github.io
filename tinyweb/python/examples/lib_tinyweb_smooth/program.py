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
from tinyweb import Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop
from tinyweb import Smooth__Point, smooth__circle, smooth__circles, smooth__rect, smooth__ellipse, smooth__arc, smooth__polygon, smooth__line, smooth__lines, smooth__path, smooth__curve, smooth__bezier, smooth__text, smooth__clip_circle, smooth__clip_polygon, smooth__circle__default__fill, smooth__circle__default__stroke, smooth__circle__default__paint, smooth__circle__default__style, smooth__circles__default__fill, smooth__circles__default__stroke, smooth__circles__default__style, smooth__rect__default__fill, smooth__rect__default__stroke, smooth__rect__default__paint, smooth__rect__default__style, smooth__ellipse__default__fill, smooth__ellipse__default__stroke, smooth__ellipse__default__paint, smooth__ellipse__default__style, smooth__arc__default__fill, smooth__arc__default__stroke, smooth__arc__default__paint, smooth__arc__default__style, smooth__polygon__default__fill, smooth__polygon__default__stroke, smooth__polygon__default__style, smooth__line__default__stroke, smooth__line__default__style, smooth__lines__default__stroke, smooth__lines__default__style, smooth__path__default__stroke, smooth__path__default__style, smooth__curve__default__stroke, smooth__curve__default__style, smooth__bezier__default__stroke, smooth__bezier__default__style, smooth__text__default__fill, smooth__text__default__stroke, smooth__text__default__paint, smooth__text__default__style
from tinyweb import Point
tw.web_init(0)
c = tw_external.canvas(200, 120)
smooth__polygon(c, [Smooth__Point(100.0, 10.5), Smooth__Point(180.5, 90.5), Smooth__Point(19.5, 90.5)], color__orange, color__black, 0.5, 1.0, smooth__polygon__default__style())
smooth__path(c, [Smooth__Point(10.0, 110.0), Smooth__Point(60.5, 20.5), Smooth__Point(110.25, 70.0), Smooth__Point(190.0, 10.0)], color__teal, 2.5, 1.0, smooth__path__default__style())
rays = [(Smooth__Point(100.0, 60.0), Smooth__Point(100.0 + 45.0 * float(i - __pyk_div(i, 3) * 3), 5.0 * float(i))) for i in list(range(8))]
smooth__lines(c, rays, color__hex(14423100), 0.8, 0.5, smooth__lines__default__style())
tw.lines(c, [(Point(x, 0), Point(x, 120)) for x in list(range(0, 200, 40))], color__hex(13421772), 1, 1.0, tw.lines__default__style())
smooth__circles(c, [(10.5, 10.5, 3.0), (20.0, 10.0, 2.5)], color__navy, smooth__circles__default__stroke(), 1.0, 1.0, smooth__circles__default__style())
tw.push(c)
smooth__clip_polygon(c, [Smooth__Point(100.0, 5.5), Smooth__Point(190.5, 115.0), Smooth__Point(9.5, 115.0)])
tw.rect(c, 0, 60, 200, 60, color__hex(16766720), tw.rect__default__stroke(), 1, 0.4, tw.rect__default__paint(), tw.rect__default__style(), 0)
tw.pop(c)
tw.push(c)
tw.clip_polygon(c, [Point(0, 0), Point(60, 0), Point(0, 60)])
tw.rect(c, 0, 0, 60, 60, color__navy, tw.rect__default__stroke(), 1, 1.0, tw.rect__default__paint(), tw.rect__default__style(), 0)
tw.pop(c)
many = [(Smooth__Point(float(i), 0.0), Smooth__Point(float(i) + 0.5, 120.0)) for i in list(range(300))]
smooth__lines(c, many, color__black, 0.25, 0.1, smooth__lines__default__style())
print('drew', len(many), 'lines in one go')
