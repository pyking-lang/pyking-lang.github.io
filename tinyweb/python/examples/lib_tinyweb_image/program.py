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

def __pyk_trunc(x):
    if x != x or x in (float('inf'), float('-inf')):
        return 0
    n = int(x)
    return n if -2147483648 <= n <= 2147483647 else 0

# --- prelude ends; the compiled program follows ---

import tinyweb as tw
import tinyweb_external as tw_external
tw.web_init(0)
c = tw_external.canvas(200, 100)
ball = tw_external.load_image('ball.png')
star = tw_external.load_image('star.png')
again = tw_external.load_image('ball.png')
print(again)

def draw(t):
    tw.clear(c, '#202040')
    tw.image(c, ball, __pyk_trunc(t * 100.0), 20, 40, 40, tw.image__default__alpha())
    return tw.image(c, star, 140, 20, 50, 50, 0.5)

tw_external.on_frame(draw)
