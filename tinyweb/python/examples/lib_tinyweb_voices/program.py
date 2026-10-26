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
kick = tw_external.load_sample('kick1.wav')
piano = tw_external.load_sample('piano_c1.wav')
sound__master_volume(0.8)
sound__channel_style(1, 0.7, -0.5, 0.4, 0.25, 0.5, 0.0, 0.0)
sound__channel_style(2, 1.0, 0.0, 0.0, 0.3, 0.35, 0.6, 1200.0)
sound__channel_style(1, 0.9, 0.0, 0.0, 0.3, 0.35, 0.0, 0.0)
tw.play(kick, 0.0, 1.0, 1.0, 0.0, tw.play__default__voice())
tw.play(kick, 0.5, 0.5, 2.0, 1.0, tw.play__default__voice())
soft = Sound__Voice(0.25, 1.0, 0.0, 1, False, False)
tw.play(kick, 0.0, 1.0, 1.0, 0.0, soft)
tw.play(kick, 0.0, 0.75, 1.0, 0.0, soft)
tw.play(piano, 0.0, 1.0, 1.0, 0.0, Sound__Voice(1.0, 1.0, 0.0, 2, False, True))
hum = sound__start(piano, 0.0, 0.3, 1.0, 0.0, True, sound__start__default__voice())
other = sound__start(piano, 1.0, 1.0, 1.0, 0.0, False, Sound__Voice(1.0, 0.5, 0.0, 2, True, False))
print(hum, other)
sound__tone(440.0, 0.0, 0.5, 'sine', 0.5, 0.0, 0)
sound__tone(sound__note('C5'), 0.25, 0.125, 'square', 0.2, 0.5, 1)
print(__pyk_float(sound__note('A4')), __pyk_float(sound__note('C4')), __pyk_float(sound__note('C#4')), __pyk_float(sound__note('Db4')), __pyk_float(sound__note('H2')), __pyk_float(sound__note('C')))
print(__pyk_float(sound__rate_of('C5', 'C4')), __pyk_float(sound__rate_of('C3', 'C4')), __pyk_float(sound__rate_of('G4', 'G3')), __pyk_float(sound__rate_of('nothing', 'C4')))

def quieter():
    sound__fade(hum, 0.0, 2.0)
    print('fading')
    return ()

def stop():
    sound__stop(other, 0.0)
    sound__stop(hum, 3.0)
    print('stopped')
    return ()

def silence():
    sound__stop_all()
    print('silence')
    return ()

tw.button('Quieter', quieter)
tw.button('Stop', stop)
tw.button('Silence', silence)
tw_external.splash()
