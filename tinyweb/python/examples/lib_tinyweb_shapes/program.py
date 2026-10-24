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
c = tw_external.canvas(300, 200)
tw.clear(c, color__rgb(17, 17, 17))
gold = color__hex(16766720)
tw.circle(c, 50, 50, 30, gold, color__white, 3, 1.0, tw.circle__default__paint(), tw.circle__default__style())
tw.circle(c, 80, 50, 30, color__rgba(0, 128, 255, 0.5), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style())
tw.rect(c, 120, 20, 60, 40, color__none, color__hsl(120.0, 100.0, 50.0), 1, 1.0, tw.rect__default__paint(), tw.rect__default__style(), 8)
tw.ellipse(c, 220, 40, 50, 20, color__hex(14315734), tw.ellipse__default__stroke(), 1, 0.75, tw.ellipse__default__paint(), tw.ellipse__default__style())
tw.arc(c, 50, 140, 40, __pyk_fdiv(math.pi, 6.0), __pyk_fdiv(11.0 * math.pi, 6.0), color__yellow, tw.arc__default__stroke(), 1, 1.0, tw.arc__default__paint(), tw.arc__default__style())
tw.arc(c, 150, 140, 40, math.pi, 2.0 * math.pi, color__none, color__red, 4, 1.0, tw.arc__default__paint(), tw.arc__default__style())
tw.line(c, 200, 100, 290, 190, color__cyan, 2, 1.0, tw.line__default__style())
tw.curve(c, 200, 190, 245, 60, 290, 190, color__white, 2, 0.5, tw.curve__default__style())
tw.text(c, 150, 180, 'Step 1', color__white, 18, 'serif', 'center', True, 1.0, 'top', tw.text__default__stroke(), 1, tw.text__default__paint(), tw.text__default__style())

def show(c):
    return str(c.r) + ' ' + str(c.g) + ' ' + str(c.b) + ' ' + str(__pyk_float(c.a))

print(show(color__rgb(255, 136, 0)))
print(show(color__rgb(-5, 300, 16)))
print(show(color__hsl(200.0, 50.0, 25.0)))
print(color__to_hex(color__hex(16746496)), color__to_hex(color__rgb(1, 2, 3)))
print('true' if color__same(color__hex(65535), color__cyan) else 'false', 'true' if color__same(color__red, color__blue) else 'false')
print(show(color__mix(color__black, color__white, 0.5)))
print(show(color__with_alpha(color__red, 0.25)))
print(show(color__rgba(10, 20, 30, 0.5)), show(color__none))
