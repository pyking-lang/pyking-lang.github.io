# --- prelude begins ---

def __pyk_import(name):
    from importlib.util import module_from_spec, spec_from_file_location
    from os.path import abspath, dirname, join
    spec = spec_from_file_location(name, join(dirname(abspath(__file__)), name + '.py'))
    module = module_from_spec(spec)
    spec.loader.exec_module(module)
    return module

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

math = __pyk_import('math')
import math_external
import tinyweb as tw
import tinyweb_external as tw_external
from tinyweb import Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop
tw.web_init(0)
c = tw_external.canvas(200, 200)

def draw(t):
    tw.clear(c, color__black)
    tw.push(c)
    tw.translate(c, 100.0, 100.0)
    tw.rotate(c, __pyk_fdiv(t * math.pi, 2.0))
    tw.rect(c, -20, -20, 40, 40, color__hex(14423100), tw.rect__default__stroke(), 1, 1.0, tw.rect__default__paint(), tw.rect__default__style(), 0)
    tw.push(c)
    tw.scale(c, 0.5, 2.0)
    tw.circle(c, 60, 0, 10, color__white, tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style())
    tw.pop(c)
    tw.pop(c)
    tw.shadow(c, color__white, 12, 0, 0)
    tw.circle(c, 30, 30, 10, color__hex(16766720), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style())
    tw.shadow(c, color__none, 10, 0, 0)
    tw.blend(c, 'add')
    tw.circle(c, 160, 160, 20, color__hex(8388608), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style())
    tw.circle(c, 175, 160, 20, color__hex(128), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style())
    tw.blend(c, 'normal')
    tw.blend(c, 'multiply')
    return tw.reset(c)

tw_external.on_frame(draw)
