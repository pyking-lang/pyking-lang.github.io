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
tw.web_init(0)
c = tw_external.canvas(200, 200)

def draw(t):
    tw.clear(c, 'black')
    tw.push(c)
    tw.translate(c, 100.0, 100.0)
    tw.rotate(c, t * 90.0)
    tw.rect(c, -20, -20, 40, 40, 'crimson', tw.rect__default__outline(), tw.rect__default__outline_width(), tw.rect__default__alpha(), tw.rect__default__radius())
    tw.push(c)
    tw.scale(c, 0.5, 2.0)
    tw.circle(c, 60, 0, 10, 'white', tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha())
    tw.pop(c)
    tw.pop(c)
    tw.shadow(c, 'white', 12, tw.shadow__default__dx(), tw.shadow__default__dy())
    tw.circle(c, 30, 30, 10, 'gold', tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha())
    tw.shadow(c, '', tw.shadow__default__blur(), tw.shadow__default__dx(), tw.shadow__default__dy())
    tw.blend(c, 'add')
    tw.circle(c, 160, 160, 20, '#800000', tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha())
    tw.circle(c, 175, 160, 20, '#000080', tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha())
    tw.blend(c, 'normal')
    tw.blend(c, 'multiply')
    return tw.reset(c)

tw_external.on_frame(draw)
