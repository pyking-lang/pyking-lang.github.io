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

# --- prelude ends; the compiled program follows ---

import tinyweb as tw
import tinyweb_external as tw_external
from tinyweb import colors__rgb, colors__rgba, colors__hsl, colors__palette, colors__linear_gradient, colors__radial_gradient, colors__conic_gradient, colors__stop
tw.web_init(0)
c = tw_external.canvas(300, 200)
tw.clear(c, colors__rgb(17, 17, 17))
tw.circle(c, 50, 50, 30, 'gold', 'white', 3, tw.circle__default__alpha())
tw.circle(c, 80, 50, 30, colors__rgba(0, 128, 255, 0.5), tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha())
tw.rect(c, 120, 20, 60, 40, '', colors__hsl(120, 100, 50), tw.rect__default__outline_width(), tw.rect__default__alpha(), 8)
tw.ellipse(c, 220, 40, 50, 20, 'orchid', tw.ellipse__default__outline(), tw.ellipse__default__outline_width(), 0.75)
tw.arc(c, 50, 140, 40, 30.0, 330.0, 'yellow', tw.arc__default__outline(), tw.arc__default__outline_width(), tw.arc__default__alpha())
tw.arc(c, 150, 140, 40, 180.0, 360.0, '', 'red', 4, tw.arc__default__alpha())
tw.line(c, 200, 100, 290, 190, 'cyan', 2, tw.line__default__alpha())
tw.curve(c, 200, 190, 245, 60, 290, 190, 'white', 2, 0.5)
tw.text(c, 150, 180, 'Step 1', 'white', 18, 'serif', 'center', True, tw.text__default__alpha(), tw.text__default__baseline(), tw.text__default__outline(), tw.text__default__outline_width())
print(colors__rgb(255, 136, 0))
print(colors__rgb(-5, 300, 16))
print(colors__hsl(200, 50, 25))
