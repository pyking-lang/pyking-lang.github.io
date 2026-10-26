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
tw.web_init(0)
c = tw_external.canvas(300, 200)
tw.rect(c, 0, 0, 300, 200, color__hex(15658734), tw.rect__default__stroke(), 1, 1.0, tw.rect__default__paint(), tw.rect__default__style(), 0)
tw.line(c, 0, 0, 300, 200, tw.line__default__stroke(), 1, 1.0, tw.line__default__style())
tw.line(c, 0, 200, 300, 0, color__red, 3, 1.0, tw.line__default__style())
tw.text(c, 10, 10, 'click "me"', tw.text__default__fill(), 20, '', 'left', False, 1.0, 'top', tw.text__default__stroke(), 1, tw.text__default__paint(), tw.text__default__style())
status = tw_external.label('nothing yet')

def clicked(x, y):
    tw.set_text(status, 'clicked at ' + str(x) + ', ' + str(y))
    return tw.circle(c, x, y, 5, color__blue, tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style())

def pressed(key):
    print('key [' + key + ']')
    if key == 'Enter':
        tw.play_file('snare1.wav')
    return ()

def moved(value):
    return tw.set_text(status, 'slider at ' + str(value))

tw.on_click(c, clicked)
tw_external.on_key(pressed)
tw.slider(0, 10, 5, moved)
tw.slider(1, 3, 2, tw.slider__default__on_change())
tw_external.splash()
