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
from tinyweb import Sound__Voice, sound__start, sound__stop, sound__fade, sound__stop_all, sound__master_volume, sound__tone, sound__note, sound__rate_of, sound__tempo, sound__swing, sound__on_beat, sound__beat, sound__latency, sound__pause, sound__resume, sound__channel_style, sound__listen, sound__level, sound__band, sound__bands, sound__wave, sound__render_wav, sound__start__default__voice, sound__render_wav__default__on_rendered
tw.web_init(0)
ticks = 0
repeating = ''

def tick():
    global ticks
    ticks = ticks + 1
    print('tick', ticks, __pyk_float(tw_external.time()))
    if ticks == 3:
        tw.cancel(repeating)
    return ()

def once():
    print('once at', __pyk_float(tw_external.time()), 'beat', __pyk_float(sound__beat()), 'latency', __pyk_float(sound__latency()), 'level', __pyk_float(sound__level()))
    print('bands', sound__bands(), __pyk_float(sound__band(0)), __pyk_float(sound__band(1)), __pyk_float(sound__band(9)))
    print('typed', tw.value_of('name'))
    return ()

repeating = tw.every(0.5, tick)
later = tw.after(2.0, once)
print(repeating, later)
