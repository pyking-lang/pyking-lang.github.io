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
from tinyweb import Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop
tw.web_init(0)
c = tw_external.canvas(200, 100)
other = tw_external.canvas(50, 50)
tw.track_mouse(c)

def pressed(x, y):
    print('press at', x, y, 'down', 'true' if tw.mouse(c).down else 'false')
    return tw.circle(c, x, y, 4, color__hex(14423100), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style())

def dragged(x, y):
    print('drag to', x, y, 'down', 'true' if tw.mouse(c).down else 'false')
    return tw.line(c, 0, 0, x, y, color__black, 2, 1.0, tw.line__default__style())

def moved(x, y):
    print('move to', x, y, 'down', 'true' if tw.mouse(c).down else 'false')
    return ()

def released(x, y):
    print('release at', x, y, 'down', 'true' if tw.mouse(c).down else 'false')
    return ()

def nothing(x, y):
    return ()

tw.on_press(c, pressed)
tw.on_drag(c, dragged)
tw.on_move(c, moved)
tw.on_release(c, released)
tw.on_move(other, nothing)
start = tw.mouse(c)
print('before any event', start.x, start.y, 'true' if start.down else 'false')

def let_go(key):
    print('let go of', key, 'still held:', 'true' if tw_external.key_down(key) else 'false')
    return ()

tw_external.on_key_up(let_go)

def frame(t):
    left = tw_external.key_down('ArrowLeft')
    right = tw_external.key_down('ArrowRight')
    print('frame', __pyk_float(t), 'left', 'true' if left else 'false', 'right', 'true' if right else 'false')
    return ()

tw_external.on_frame(frame)
