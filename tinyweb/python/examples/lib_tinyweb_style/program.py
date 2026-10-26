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
tw.theme('paper')
tw.theme('no such theme')
tw.page_style(color__hex(16643811), color__hex(5795445), 'serif', 18, 12, 16, '')
tw.button_style(color__hex(2526162), color__white, color__none, -1, 14, 'monospace', 16, 8)
tw.label_style(color__hex(16777184), color__hex(3355443), color__hex(16766720), 1, 4, 'sans-serif', 14, 6)
tw.slider_style(color__hex(14423100), 240, color__hex(14423100), 'monospace', 20)
tw.canvas_style(color__teal, 3, 10)
title = tw_external.label('Styled')
tw.set_style(title, color__navy, color__white, color__orange, 2, 0, 'Georgia', 28, 10, tw.set_style__default__accent(), 300, -1, -1)
level = tw.slider(0, 10, 4, tw.slider__default__on_change())
tw.set_style(level, tw.set_style__default__background(), color__hex(3050327), tw.set_style__default__border(), -1, -1, '', -1, -1, tw.set_style__default__accent(), -1, -1, -1)
c = tw_external.canvas(120, 60)
tw.set_style(c, tw.set_style__default__background(), tw.set_style__default__foreground(), color__black, 1, -1, '', -1, -1, tw.set_style__default__accent(), -1, -1, -1)

def pressed():
    tw.theme('retro')
    tw.set_style(title, color__black, tw.set_style__default__foreground(), tw.set_style__default__border(), -1, -1, '', -1, -1, tw.set_style__default__accent(), -1, -1, -1)
    print('now retro')
    return ()

ok = tw.button('Retro', pressed)
(lambda background__arg: (lambda border__arg: (lambda accent__arg: tw.set_style(ok, background__arg, color__black, border__arg, -1, -1, '', -1, -1, accent__arg, -1, -1, -1))(tw.set_style__default__accent()))(tw.set_style__default__border()))(color__rgba(255, 215, 0, 0.5))
