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
kick = tw_external.load_sample('kick1.wav')
snare = tw_external.load_sample('snare1.wav')
canvas = tw_external.canvas(400, 200)
tw.circle(canvas, 100, 50, 30, color__red, tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style())
tw.circle(canvas, 100, 50, 20, tw.circle__default__fill(), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style())
presses = 0

def play_kick():
    return tw.play(kick, 0.0, 1.0, 1.0, 0.0, tw.play__default__voice())

def play_sound():
    global presses
    presses = presses + 1
    print('snare, press ' + str(presses))
    return tw.play(snare, 0.0, 0.5, 1.0, 0.0, tw.play__default__voice())

tw.button('Play kick', play_kick)
tw.button('Play snare', play_sound)
tw.button('Does nothing', tw.button__default__on_click())
print('built the page')
tw_external.splash()
