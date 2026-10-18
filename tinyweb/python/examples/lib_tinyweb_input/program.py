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
c = tw_external.canvas(300, 200)
tw.rect(c, 0, 0, 300, 200, '#eeeeee', tw.rect__default__outline(), tw.rect__default__outline_width(), tw.rect__default__alpha(), tw.rect__default__radius())
tw.line(c, 0, 0, 300, 200, tw.line__default__color(), tw.line__default__width(), tw.line__default__alpha())
tw.line(c, 0, 200, 300, 0, 'red', 3, tw.line__default__alpha())
tw.text(c, 10, 10, 'click "me"', tw.text__default__color(), 20, tw.text__default__font(), tw.text__default__align(), tw.text__default__bold(), tw.text__default__alpha(), tw.text__default__baseline(), tw.text__default__outline(), tw.text__default__outline_width())
status = tw_external.label('nothing yet')

def clicked(x, y):
    tw_external.set_label(status, 'clicked at ' + str(x) + ', ' + str(y))
    return tw.circle(c, x, y, 5, 'blue', tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha())

def pressed(key):
    print('key [' + key + ']')
    if key == 'Enter':
        tw.play_file('snare1.wav')
    return ()

def moved(value):
    return tw_external.set_label(status, 'slider at ' + str(value))

tw_external.on_mouse(c, clicked)
tw_external.on_key(pressed)
tw.slider(0, 10, 5, moved)
tw.slider(1, 3, 2, tw.slider__default__on_change())
tw_external.splash()
