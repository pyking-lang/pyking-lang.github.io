# --- prelude begins ---

def __pyk_div(a, b):
    q = abs(a) // abs(b)
    return q if (a < 0) == (b < 0) else -q

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

import math_external
pi = 3.141592653589793
tau = 6.283185307179586
e = 2.718281828459045
inf = float('inf')
nan = __pyk_fdiv(0.0, 0.0)

def is_nan(x):
    return False if x == x else True

def is_finite(x):
    return x - x == 0.0

def to_radians(deg):
    return __pyk_fdiv(deg * pi, 180.0)

def to_degrees(rad):
    return __pyk_fdiv(rad * 180.0, pi)

def int__abs(x):
    return -x if x < 0 else x

def float__abs(x):
    return 0.0 - x if x <= 0.0 else x

def int__min(x, y):
    return y if y < x else x

def float__min(x, y):
    if is_nan(x):
        return x
    elif is_nan(y):
        return y
    else:
        return y if y < x else x

def int__max(x, y):
    return y if y > x else x

def float__max(x, y):
    if is_nan(x):
        return x
    elif is_nan(y):
        return y
    else:
        return y if y > x else x

def int__clamp(x, low, high):
    return int__max(low, int__min(x, high))

def float__clamp(x, low, high):
    return float__max(low, float__min(x, high))

def int__sign(x):
    if x < 0:
        return -1
    elif x > 0:
        return 1
    else:
        return 0

def float__sign(x):
    if x < 0.0:
        return -1.0
    elif x > 0.0:
        return 1.0
    elif x == 0.0:
        return 0.0
    else:
        return x

def int__mod(x, y):
    r = x - __pyk_div(x, y) * y
    if r < 0:
        return r + y if y > 0 else r
    elif r > 0:
        return r + y if y < 0 else r
    else:
        return 0

def float__mod(x, y):
    r = x - y * math_external.host_floor(__pyk_fdiv(x, y))
    if y > 0.0:
        return 0.0 if r >= y else r
    else:
        return 0.0 if r <= y else r

def sin(angle):
    return math_external.host_sin(angle)

def cos(angle):
    return math_external.host_cos(angle)

def tan(angle):
    return math_external.host_tan(angle)

def asin(x):
    return math_external.host_asin(x)

def acos(x):
    return math_external.host_acos(x)

def atan(x):
    return math_external.host_atan(x)

def atan2(y, x):
    return math_external.host_atan2(y, x)

def sinh(x):
    return math_external.host_sinh(x)

def cosh(x):
    return math_external.host_cosh(x)

def tanh(x):
    return math_external.host_tanh(x)

def exp(x):
    return math_external.host_exp(x)

def log(x):
    return math_external.host_log(x)

def log2(x):
    return math_external.host_log2(x)

def log10(x):
    return math_external.host_log10(x)

def sqrt(x):
    return math_external.host_sqrt(x)

def cbrt(x):
    root = math_external.host_cbrt(x)
    nearest = math_external.host_floor(root + 0.5)
    return nearest if nearest * nearest * nearest == x else root

def pow(x, y):
    return math_external.host_pow(x, y)

def hypot(x, y):
    return math_external.host_hypot(x, y)

def distance(x1, y1, x2, y2):
    return math_external.host_hypot(x2 - x1, y2 - y1)

def floor(x):
    return __pyk_trunc(math_external.host_floor(x))

def ceil(x):
    return __pyk_trunc(math_external.host_ceil(x))

def trunc(x):
    return __pyk_trunc(math_external.host_trunc(x))

def round(x):
    whole = math_external.host_trunc(x)
    part = x - whole
    if part >= 0.5:
        return __pyk_trunc(whole + 1.0)
    elif part <= -0.5:
        return __pyk_trunc(whole - 1.0)
    else:
        return __pyk_trunc(whole)

def euclid(x, y):
    (x2, y2) = (x, y)
    while True:
        if y2 == 0:
            return x2
        else:
            (x2, y2) = (y2, x2 - __pyk_div(x2, y2) * y2)
    return (x2, y2)

def gcd(x, y):
    return euclid(int__abs(x), int__abs(y))

def lcm(x, y):
    if x == 0:
        return 0
    elif y == 0:
        return 0
    else:
        return int__abs(__pyk_div(x, gcd(x, y)) * y)

def lerp(a, b, t):
    return a + (b - a) * t

def map_range(x, from_low, from_high, to_low, to_high):
    return to_low + __pyk_fdiv((x - from_low) * (to_high - to_low), from_high - from_low)
