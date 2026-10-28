from dataclasses import dataclass

# --- prelude begins ---

def __pyk_import(name):
    from importlib.util import module_from_spec, spec_from_file_location
    from os.path import abspath, dirname, join
    spec = spec_from_file_location(name, join(dirname(abspath(__file__)), name + '.py'))
    module = module_from_spec(spec)
    spec.loader.exec_module(module)
    return module

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

def __pyk_trunc(x):
    if x != x or x in (float('inf'), float('-inf')):
        return 0
    n = int(x)
    return n if -2147483648 <= n <= 2147483647 else 0

def __pyk_int(s):
    digits = s[1:] if s[:1] in ('-', '+') else s
    if not (digits.isascii() and digits.isdigit()):
        return 0
    n = int(s)
    return n if -2147483648 <= n <= 2147483647 else 0

# --- prelude ends; the compiled program follows ---

import tinyweb_external

@dataclass(frozen=True, slots=True)
class Color__Color:
    r: int
    g: int
    b: int
    a: float

@dataclass(frozen=True, slots=True)
class Color__Plain:
    _0: Color__Color

@dataclass(frozen=True, slots=True)
class Color__Linear:
    x1: float
    y1: float
    x2: float
    y2: float
    start: Color__Color
    end: Color__Color
    stops: str

@dataclass(frozen=True, slots=True)
class Color__Radial:
    x1: float
    y1: float
    r1: float
    x2: float
    y2: float
    r2: float
    start: Color__Color
    end: Color__Color
    stops: str

@dataclass(frozen=True, slots=True)
class Color__Conic:
    x: float
    y: float
    angle: float
    start: Color__Color
    end: Color__Color
    stops: str

type Color__Paint = Color__Plain | Color__Linear | Color__Radial | Color__Conic

@dataclass(frozen=True, slots=True)
class Point:
    x: int
    y: int

@dataclass(frozen=True, slots=True)
class Style:
    fill: Color__Color
    stroke: Color__Color
    width: int
    alpha: float
    paint: Color__Paint

@dataclass(frozen=True, slots=True)
class Pointer:
    x: int
    y: int
    down: bool

@dataclass(frozen=True, slots=True)
class Sound__Voice:
    volume: float
    rate: float
    pan: float
    channel: int
    looping: bool
    reverse: bool

@dataclass(frozen=True, slots=True)
class Smooth__Point:
    x: float
    y: float

math = __pyk_import('math')
import math_external
import text as strings
import text_external as strings_external

def nothing():
    return ()

def ignore(value):
    return ()

def ignore_bool(value):
    return ()

def ignore_text(value):
    return ()

def ignore_float(value):
    return ()

def numbers2(a, b):
    return str(a) + ' ' + str(b)

def numbers3(a, b, c):
    return numbers2(a, b) + ' ' + str(c)

def numbers4(a, b, c, d):
    return numbers2(a, b) + ' ' + numbers2(c, d)

def joined_by(words, between):
    whole = ''
    chunk = ''
    count = 0
    chunks = 0
    for word in words:
        chunk = word if count == 0 else chunk + between + word
        count = count + 1
        if count == 128:
            whole = chunk if chunks == 0 else whole + between + chunk
            chunks = chunks + 1
            chunk = ''
            count = 0
    return whole if count == 0 else chunk if chunks == 0 else whole + between + chunk

def joined(words):
    return joined_by(words, ' ')

def points_text(points):
    return joined([numbers2(p.x, p.y) for p in points])

def segments_text(segments):
    return joined([numbers4(a.x, a.y, b.x, b.y) for (a, b) in segments])

def floats2(a, b):
    return str(__pyk_float(a)) + ' ' + str(__pyk_float(b))

def floats3(a, b, c):
    return floats2(a, b) + ' ' + str(__pyk_float(c))

def floats4(a, b, c, d):
    return floats2(a, b) + ' ' + floats2(c, d)

def float_points_text(points):
    return joined([floats2(p.x, p.y) for p in points])

def bit(on):
    return '1' if on else '0'

color__black = Color__Color(0, 0, 0, 1.0)
color__white = Color__Color(255, 255, 255, 1.0)
color__gray = Color__Color(128, 128, 128, 1.0)
color__red = Color__Color(255, 0, 0, 1.0)
color__green = Color__Color(0, 128, 0, 1.0)
color__blue = Color__Color(0, 0, 255, 1.0)
color__yellow = Color__Color(255, 255, 0, 1.0)
color__orange = Color__Color(255, 165, 0, 1.0)
color__purple = Color__Color(128, 0, 128, 1.0)
color__pink = Color__Color(255, 192, 203, 1.0)
color__navy = Color__Color(0, 0, 128, 1.0)
color__teal = Color__Color(0, 128, 128, 1.0)
color__brown = Color__Color(139, 69, 19, 1.0)
color__cyan = Color__Color(0, 255, 255, 1.0)
color__magenta = Color__Color(255, 0, 255, 1.0)
color__none = Color__Color(0, 0, 0, 0.0)
color__theme = Color__Color(-1, -1, -1, -1.0)

def color__sector(sector, chroma, x):
    match sector:
        case 0:
            return (chroma, x, 0.0)
        case 1:
            return (x, chroma, 0.0)
        case 2:
            return (0.0, chroma, x)
        case 3:
            return (0.0, x, chroma)
        case 4:
            return (x, 0.0, chroma)
        case _:
            return (chroma, 0.0, x)

def color__part(n):
    return 0 if n < 0 else 255 if n > 255 else n

def color__unit(x):
    return 0.0 if x < 0.0 else 1.0 if x > 1.0 else x

def color__byte(x):
    return color__part(__pyk_trunc(color__unit(x) * 255.0 + 0.5))

def color__absolute(x):
    return -x if x < 0.0 else x

def color__wrap(x, m):
    r = x - float(__pyk_trunc(__pyk_fdiv(x, m))) * m
    return r + m if r < 0.0 else r

def color__between(a, b, t):
    return float(a) + float(b - a) * t

def color__hex2(n):
    clamped = color__part(n)
    return color__hex_digit(__pyk_div(clamped, 16)) + color__hex_digit(clamped - __pyk_div(clamped, 16) * 16)

def color__hex_digit(d):
    match d:
        case 0:
            return '0'
        case 1:
            return '1'
        case 2:
            return '2'
        case 3:
            return '3'
        case 4:
            return '4'
        case 5:
            return '5'
        case 6:
            return '6'
        case 7:
            return '7'
        case 8:
            return '8'
        case 9:
            return '9'
        case 10:
            return 'a'
        case 11:
            return 'b'
        case 12:
            return 'c'
        case 13:
            return 'd'
        case 14:
            return 'e'
        case _:
            return 'f'

def color__css(c):
    if c.a >= 1.0:
        return '#' + color__hex2(c.r) + color__hex2(c.g) + color__hex2(c.b)
    else:
        return 'rgba(' + str(color__part(c.r)) + ', ' + str(color__part(c.g)) + ', ' + str(color__part(c.b)) + ', ' + str(__pyk_float(color__unit(c.a))) + ')'

def color__drawn(c):
    return '' if c.a <= 0.0 else color__css(c)

def color__paint_text(p):
    match p:
        case Color__Plain(c):
            return color__drawn(c)
        case Color__Linear(x1, y1, x2, y2, start, end, stops):
            return 'linear-gradient(' + floats4(x1, y1, x2, y2) + '); 0.0 ' + color__css(start) + '; 1.0 ' + color__css(end) + stops
        case Color__Radial(x1, y1, r1, x2, y2, r2, start, end, stops):
            return 'radial-gradient(' + floats3(x1, y1, r1) + ' ' + floats3(x2, y2, r2) + '); 0.0 ' + color__css(start) + '; 1.0 ' + color__css(end) + stops
        case Color__Conic(x, y, angle, start, end, stops):
            return 'conic-gradient(' + floats3(x, y, angle) + '); 0.0 ' + color__css(start) + '; 1.0 ' + color__css(end) + stops

def color__painted(p):
    match p:
        case Color__Plain(c):
            return c.a > 0.0
        case _:
            return True

def color__is_theme(c):
    return c.a < 0.0

def color__rgb(r, g, b):
    return Color__Color(color__part(r), color__part(g), color__part(b), 1.0)

def color__rgba(r, g, b, a):
    return Color__Color(color__part(r), color__part(g), color__part(b), 0.0 if a < 0.0 else 1.0 if a > 1.0 else a)

def color__hsl(h, s, l):
    hue = __pyk_fdiv(color__wrap(h, 360.0), 60.0)
    sat = color__unit(__pyk_fdiv(s, 100.0))
    light = color__unit(__pyk_fdiv(l, 100.0))
    chroma = (1.0 - color__absolute(2.0 * light - 1.0)) * sat
    x = chroma * (1.0 - color__absolute(color__wrap(hue, 2.0) - 1.0))
    m = light - __pyk_fdiv(chroma, 2.0)
    (r, g, b) = color__sector(__pyk_trunc(hue), chroma, x)
    return Color__Color(color__byte(r + m), color__byte(g + m), color__byte(b + m), 1.0)

def color__hex(n):
    return Color__Color(color__part(__pyk_div(n, 65536)), color__part(__pyk_div(n, 256) - __pyk_div(n, 65536) * 256), color__part(n - __pyk_div(n, 256) * 256), 1.0)

def color__to_hex(c):
    return color__part(c.r) * 65536 + color__part(c.g) * 256 + color__part(c.b)

def color__with_alpha(c, a):
    return Color__Color(c.r, c.g, c.b, color__unit(a))

def color__mix(a, b, t):
    k = color__unit(t)
    return Color__Color(color__byte(__pyk_fdiv(color__between(a.r, b.r, k), 255.0)), color__byte(__pyk_fdiv(color__between(a.g, b.g, k), 255.0)), color__byte(__pyk_fdiv(color__between(a.b, b.b, k), 255.0)), a.a + (b.a - a.a) * k)

def color__same(a, b):
    return ((a.a == b.a if a.b == b.b else False) if a.g == b.g else False) if a.r == b.r else False

def color__palette(name):
    match name:
        case 'ocean':
            return [color__hex(197726), color__hex(30646), color__hex(46296), color__hex(9494767), color__hex(13299960)]
        case 'candy':
            return [color__hex(16740518), color__hex(16750448), color__hex(16766576), color__hex(15335280), color__hex(7395071)]
        case 'forest':
            return [color__hex(2976335), color__hex(4231532), color__hex(5420936), color__hex(9819570), color__hex(14218204)]
        case 'sunset':
            return [color__hex(16335172), color__hex(15954476), color__hex(16291358), color__hex(16369487), color__hex(9485933)]
        case 'neon':
            return [color__hex(16711935), color__hex(65535), color__hex(3800852), color__hex(16776960), color__hex(16724273)]
        case _:
            print('tinyweb: there is no palette called "' + name + '"; the palettes are ocean, candy, forest, sunset and neon', file=__import__('sys').stderr)
            return []

def color__stop(paint, at, c):
    more = '; ' + str(__pyk_float(at)) + ' ' + color__css(c)
    match paint:
        case Color__Plain(_):
            return paint
        case Color__Linear(x1, y1, x2, y2, start, end, stops):
            return Color__Linear(x1, y1, x2, y2, start, end, stops + more)
        case Color__Radial(x1, y1, r1, x2, y2, r2, start, end, stops):
            return Color__Radial(x1, y1, r1, x2, y2, r2, start, end, stops + more)
        case Color__Conic(x, y, angle, start, end, stops):
            return Color__Conic(x, y, angle, start, end, stops + more)

def web_init(port):
    return tinyweb_external.web_start(port)

def field__default__Style__fill():
    return color__black

def field__default__Style__stroke():
    return color__none

def field__default__Style__paint():
    return Color__Plain(color__none)

def fill_of(fill, paint, style):
    if color__painted(paint):
        return color__paint_text(paint)
    elif not_default_fill(fill):
        return color__drawn(fill)
    elif color__painted(style.paint):
        return color__paint_text(style.paint)
    else:
        return color__drawn(style.fill)

def not_default_fill(fill):
    return False if color__same(fill, color__black) else True

def stroke_of(stroke, style):
    return color__drawn(style.stroke if color__same(stroke, color__none) else stroke)

def line_of(stroke, style):
    if not_default_fill(stroke):
        return color__drawn(stroke)
    elif color__same(style.stroke, color__none):
        return color__drawn(style.fill)
    else:
        return color__drawn(style.stroke)

def width_of(width, style):
    return float(style.width if width == 1 else width)

def alpha_of(alpha, style):
    return style.alpha if alpha == 1.0 else alpha

def shape(c, kind, numbers, fill, stroke, width, alpha, paint, style):
    return tinyweb_external.draw_shape(c, kind, numbers, fill_of(fill, paint, style), stroke_of(stroke, style), width_of(width, style), alpha_of(alpha, style))

def stroked(c, kind, numbers, stroke, width, alpha, style):
    return tinyweb_external.draw_shape(c, kind, numbers, '', line_of(stroke, style), width_of(width, style), alpha_of(alpha, style))

def clear__default__fill():
    return color__white

def clear(c, fill):
    return tinyweb_external.fill_canvas(c, color__css(fill))

def circle__default__fill():
    return color__black

def circle__default__stroke():
    return color__none

def circle__default__paint():
    return Color__Plain(color__none)

def circle__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def circle(c, x, y, radius, fill, stroke, width, alpha, paint, style):
    return shape(c, 'circle', numbers3(x, y, radius), fill, stroke, width, alpha, paint, style)

def rect__default__fill():
    return color__black

def rect__default__stroke():
    return color__none

def rect__default__paint():
    return Color__Plain(color__none)

def rect__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def rect(c, x, y, w, h, fill, stroke, width, alpha, paint, style, radius):
    return shape(c, 'rect', numbers4(x, y, w, h) + ' ' + str(radius), fill, stroke, width, alpha, paint, style)

def ellipse__default__fill():
    return color__black

def ellipse__default__stroke():
    return color__none

def ellipse__default__paint():
    return Color__Plain(color__none)

def ellipse__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def ellipse(c, x, y, rx, ry, fill, stroke, width, alpha, paint, style):
    return shape(c, 'ellipse', numbers4(x, y, rx, ry), fill, stroke, width, alpha, paint, style)

def arc__default__fill():
    return color__black

def arc__default__stroke():
    return color__none

def arc__default__paint():
    return Color__Plain(color__none)

def arc__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def arc(c, x, y, radius, start, end, fill, stroke, width, alpha, paint, style):
    return shape(c, 'arc', numbers3(x, y, radius) + ' ' + floats2(start, end), fill, stroke, width, alpha, paint, style)

def polygon__default__fill():
    return color__black

def polygon__default__stroke():
    return color__none

def polygon__default__paint():
    return Color__Plain(color__none)

def polygon__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def polygon(c, points, fill, stroke, width, alpha, paint, style):
    return shape(c, 'polygon', points_text(points), fill, stroke, width, alpha, paint, style)

def line__default__stroke():
    return color__black

def line__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def line(c, x1, y1, x2, y2, stroke, width, alpha, style):
    return stroked(c, 'line', numbers4(x1, y1, x2, y2), stroke, width, alpha, style)

def path__default__stroke():
    return color__black

def path__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def path(c, points, stroke, width, alpha, style):
    return stroked(c, 'path', points_text(points), stroke, width, alpha, style)

def curve__default__stroke():
    return color__black

def curve__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def curve(c, x1, y1, cx, cy, x2, y2, stroke, width, alpha, style):
    return stroked(c, 'curve', numbers2(x1, y1) + ' ' + numbers4(cx, cy, x2, y2), stroke, width, alpha, style)

def lines__default__stroke():
    return color__black

def lines__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def lines(c, segments, stroke, width, alpha, style):
    return stroked(c, 'lines', segments_text(segments), stroke, width, alpha, style)

def bezier__default__stroke():
    return color__black

def bezier__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def bezier(c, x1, y1, ax, ay, bx, by, x2, y2, stroke, width, alpha, style):
    return stroked(c, 'bezier', numbers4(x1, y1, ax, ay) + ' ' + numbers4(bx, by, x2, y2), stroke, width, alpha, style)

def erase(c, x, y, w, h):
    return tinyweb_external.draw_shape(c, 'erase', numbers4(x, y, w, h), '', '', 0.0, 1.0)

def line_style(c, cap, join, dash, gap, offset, dash2, gap2):
    first = '' if dash <= 0.0 else ' ' + floats2(dash, dash) if gap <= 0.0 else ' ' + floats2(dash, gap)
    second = '' if dash <= 0.0 else '' if dash2 <= 0.0 else ' ' + floats2(dash2, dash2) if gap2 <= 0.0 else ' ' + floats2(dash2, gap2)
    return tinyweb_external.set_state(c, 'line_style', cap + ' ' + join, str(__pyk_float(offset)) + first + second)

def clip_rect(c, x, y, w, h):
    return tinyweb_external.set_state(c, 'clip', 'rect', numbers4(x, y, w, h) + ' 0')

def clip_circle(c, x, y, radius):
    return tinyweb_external.set_state(c, 'clip', 'circle', numbers3(x, y, radius))

def clip_polygon(c, points):
    return tinyweb_external.set_state(c, 'clip', 'polygon', points_text(points))

def text__default__fill():
    return color__black

def text__default__stroke():
    return color__none

def text__default__paint():
    return Color__Plain(color__none)

def text__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def text(c, x, y, words, fill, size, font, align, bold, alpha, baseline, stroke, width, paint, style):
    return tinyweb_external.draw_text(c, float(x), float(y), words, fill_of(fill, paint, style), size, font, align, baseline, bold, stroke_of(stroke, style), width_of(width, style), alpha_of(alpha, style))

def measure_text(words, answer, size, font, bold):
    return tinyweb_external.measure(words, size, font, bold, answer)

def translate(c, x, y):
    return tinyweb_external.set_state(c, 'translate', '', floats2(x, y))

def rotate(c, angle):
    return tinyweb_external.set_state(c, 'rotate', '', str(__pyk_float(angle)))

def scale(c, sx, sy):
    return tinyweb_external.set_state(c, 'scale', '', floats2(sx, sy))

def push(c):
    return tinyweb_external.set_state(c, 'push', '', '')

def pop(c):
    return tinyweb_external.set_state(c, 'pop', '', '')

def reset(c):
    return tinyweb_external.set_state(c, 'reset', '', '')

def shadow(c, shade, blur, dx, dy):
    return tinyweb_external.set_state(c, 'shadow', color__drawn(shade), numbers3(blur, dx, dy))

def blend(c, mode):
    match mode:
        case 'normal' | 'add':
            return tinyweb_external.set_state(c, 'blend', mode, '')
        case _:
            print('tinyweb: there is no blending called "' + mode + '"; the modes are normal and add', file=__import__('sys').stderr)
    return ()

def image(c, picture, x, y, w, h, alpha):
    return tinyweb_external.draw_image(c, picture, x, y, w, h, alpha)

def button__default__on_click():
    return nothing

def button(title, on_click):
    return tinyweb_external.make_button(title, on_click)

def slider__default__on_change():
    return ignore

def slider(low, high, value, on_change):
    return tinyweb_external.make_slider(low, high, value, on_change)

def checkbox__default__on_change():
    return ignore_bool

def checkbox(title, checked, on_change):
    return tinyweb_external.make_checkbox(title, checked, on_change)

def radio__default__on_pick():
    return ignore_text

def radio(group, title, chosen, on_pick):
    return tinyweb_external.make_radio(group, title, chosen, on_pick)

def lines_of(options):
    return joined_by(options, '\n')

def choice__default__on_change():
    return ignore

def choice(options, chosen, on_change):
    return tinyweb_external.make_choice(lines_of(options), chosen, on_change)

def text_input__default__on_enter():
    return ignore_text

def text_input(placeholder, on_enter):
    return tinyweb_external.make_text_input(placeholder, on_enter)

def number_input__default__on_change():
    return ignore

def number_input(low, high, value, on_change):
    return tinyweb_external.make_number_input(low, high, value, on_change)

def set_text(id, words):
    return tinyweb_external.command('set_text', id, words, '', 1)

def show(id):
    return tinyweb_external.command('visible', id, '', '1', 1)

def hide(id):
    return tinyweb_external.command('visible', id, '', '0', 1)

def enable(id):
    return tinyweb_external.command('enabled', id, '', '1', 1)

def disable(id):
    return tinyweb_external.command('enabled', id, '', '0', 1)

def remove(id):
    return tinyweb_external.command('remove', id, '', '', 0)

def value_of(id):
    return tinyweb_external.report_text('value.' + id)

def known_theme(name):
    match name:
        case 'light' | 'dark' | 'plain' | 'paper' | 'retro':
            return True
        case _:
            return False

def style_text(id, kind, property, value):
    return () if value == '' else tinyweb_external.apply_style(id, kind, property, value)

def style_color(id, kind, property, c):
    return () if color__is_theme(c) else tinyweb_external.apply_style(id, kind, property, color__css(c))

def style_border(id, kind, border, width):
    if color__is_theme(border):
        return tinyweb_external.apply_style(id, kind, 'border', str(width) + 'px solid currentColor') if width >= 0 else ()
    elif border.a <= 0.0:
        return tinyweb_external.apply_style(id, kind, 'border', 'none')
    else:
        return tinyweb_external.apply_style(id, kind, 'border', str(width if width >= 0 else 1) + 'px solid ' + color__css(border))

def style_pixels(id, kind, property, value):
    return () if value < 0 else tinyweb_external.apply_style(id, kind, property, str(value) + 'px')

def theme(name):
    if known_theme(name):
        return tinyweb_external.apply_style('', 'theme', 'name', name)
    else:
        print('tinyweb: there is no theme called "' + name + '"; the themes are light, dark, plain, paper and retro', file=__import__('sys').stderr)
    return ()

def page_style__default__background():
    return color__theme

def page_style__default__foreground():
    return color__theme

def page_style(background, foreground, font, size, padding, gap, align):
    style_color('', 'page', 'background', background)
    style_color('', 'page', 'color', foreground)
    style_text('', 'page', 'font', font)
    style_pixels('', 'page', 'size', size)
    style_pixels('', 'page', 'padding', padding)
    style_pixels('', 'page', 'gap', gap)
    return style_text('', 'page', 'align', align)

def button_style__default__background():
    return color__theme

def button_style__default__foreground():
    return color__theme

def button_style__default__border():
    return color__theme

def button_style(background, foreground, border, border_width, radius, font, size, padding):
    style_color('', 'button', 'background', background)
    style_color('', 'button', 'color', foreground)
    style_border('', 'button', border, border_width)
    style_pixels('', 'button', 'radius', radius)
    style_text('', 'button', 'font', font)
    style_pixels('', 'button', 'size', size)
    return style_pixels('', 'button', 'padding', padding)

def label_style__default__background():
    return color__theme

def label_style__default__foreground():
    return color__theme

def label_style__default__border():
    return color__theme

def label_style(background, foreground, border, border_width, radius, font, size, padding):
    style_color('', 'label', 'background', background)
    style_color('', 'label', 'color', foreground)
    style_border('', 'label', border, border_width)
    style_pixels('', 'label', 'radius', radius)
    style_text('', 'label', 'font', font)
    style_pixels('', 'label', 'size', size)
    return style_pixels('', 'label', 'padding', padding)

def slider_style__default__accent():
    return color__theme

def slider_style__default__foreground():
    return color__theme

def slider_style(accent, width, foreground, font, size):
    style_color('', 'slider', 'accent', accent)
    style_pixels('', 'slider', 'width', width)
    style_color('', 'slider', 'color', foreground)
    style_text('', 'slider', 'font', font)
    return style_pixels('', 'slider', 'size', size)

def canvas_style__default__border():
    return color__theme

def canvas_style(border, border_width, radius):
    style_border('', 'canvas', border, border_width)
    return style_pixels('', 'canvas', 'radius', radius)

def set_style__default__background():
    return color__theme

def set_style__default__foreground():
    return color__theme

def set_style__default__border():
    return color__theme

def set_style__default__accent():
    return color__theme

def set_style(id, background, foreground, border, border_width, radius, font, size, padding, accent, width, weight, height):
    style_color(id, 'element', 'background', background)
    style_color(id, 'element', 'color', foreground)
    style_border(id, 'element', border, border_width)
    style_pixels(id, 'element', 'radius', radius)
    style_text(id, 'element', 'font', font)
    style_pixels(id, 'element', 'size', size)
    style_pixels(id, 'element', 'padding', padding)
    style_color(id, 'element', 'accent', accent)
    style_pixels(id, 'element', 'width', width)
    if weight >= 0:
        style_text(id, 'element', 'weight', str(weight))
    return style_pixels(id, 'element', 'height', height)

def on_click(c, f):
    return tinyweb_external.on_mouse(c, f)

def on_press(c, f):
    return tinyweb_external.watch_pointer(c, 'press', f)

def on_release(c, f):
    return tinyweb_external.watch_pointer(c, 'release', f)

def on_move(c, f):
    return tinyweb_external.watch_pointer(c, 'move', f)

def on_drag(c, f):
    return tinyweb_external.watch_pointer(c, 'drag', f)

def track_mouse(c):
    return tinyweb_external.watch_pointer(c, 'move', ignore2)

def mouse(c):
    return Pointer(tinyweb_external.pointer(c, 'x'), tinyweb_external.pointer(c, 'y'), tinyweb_external.pointer(c, 'down') == 1)

def ignore2(x, y):
    return ()

def after(seconds, f):
    id = tinyweb_external.fresh_id('timer')
    tinyweb_external.watch(id, 'timer', f)
    tinyweb_external.command('after', id, '', str(__pyk_float(seconds)), 0)
    return id

def every(seconds, f):
    id = tinyweb_external.fresh_id('timer')
    tinyweb_external.watch(id, 'timer', f)
    tinyweb_external.command('every', id, '', str(__pyk_float(seconds)), 0)
    return id

def cancel(timer):
    return tinyweb_external.command('cancel', timer, '', '', 0)

def sound__settings(at, volume, rate, pan, voice):
    v = voice.volume if volume == 1.0 else volume
    r = voice.rate if rate == 1.0 else rate
    p = voice.pan if pan == 0.0 else pan
    return floats4(at, v, r, p) + ' ' + str(voice.channel) + ' ' + bit(voice.reverse)

def play__default__voice():
    return Sound__Voice(1.0, 1.0, 0.0, 0, False, False)

def play(sample, at, volume, rate, pan, voice):
    return tinyweb_external.command('play', sample, '', sound__settings(at, volume, rate, pan, voice), 2)

def play_file(name):
    return play(tinyweb_external.load_sample(name), 0.0, 1.0, 1.0, 0.0, play__default__voice())

def sound__start__default__voice():
    return Sound__Voice(1.0, 1.0, 0.0, 0, False, False)

def sound__start(sample, at, volume, rate, pan, looping, voice):
    id = tinyweb_external.fresh_id('voice')
    looped = True if looping else voice.looping
    tinyweb_external.command('start', id, sample, sound__settings(at, volume, rate, pan, voice) + ' ' + bit(looped), 2)
    return id

def sound__stop(voice, at):
    return tinyweb_external.command('stop', voice, '', str(__pyk_float(at)), 2)

def sound__fade(voice, volume, over):
    return tinyweb_external.command('fade', voice, '', floats2(volume, over), 2)

def sound__stop_all():
    return tinyweb_external.command('stop_all', '', '', '', 2)

def sound__master_volume(volume):
    return tinyweb_external.command('master', '', '', str(__pyk_float(volume)), 1)

def sound__tone(frequency, at, duration, wave, volume, pan, channel):
    return tinyweb_external.command('tone', '', wave, floats4(frequency, at, duration, volume) + ' ' + str(__pyk_float(pan)) + ' ' + str(channel), 2)

def sound__note(name):
    semitones = sound__semitones(name)
    return 0.0 if semitones < -1000 else 440.0 * math.pow(2.0, __pyk_fdiv(float(semitones - 57), 12.0))

def sound__rate_of(name, base):
    origin = sound__semitones(base)
    target = sound__semitones(name)
    return 1.0 if origin < -1000 else 1.0 if target < -1000 else math.pow(2.0, __pyk_fdiv(float(target - origin), 12.0))

def sound__semitones(name):
    match strings.char_at(name, 0):
        case 'C' | 'c':
            base = 0
        case 'D' | 'd':
            base = 2
        case 'E' | 'e':
            base = 4
        case 'F' | 'f':
            base = 5
        case 'G' | 'g':
            base = 7
        case 'A' | 'a':
            base = 9
        case 'B' | 'b':
            base = 11
        case _:
            base = -10000
    match strings.char_at(name, 1):
        case '#':
            shift = 1
        case 'b':
            shift = -1
        case _:
            shift = 0
    rest = strings.slice(name, 1 if shift == 0 else 2, strings.length(name))
    octave = 4 if rest == '' else __pyk_int(rest)
    valid = False if base < 0 else True if rest == '' else str(octave) == rest
    return base + shift + octave * 12 if valid else -10000

def sound__tempo(bpm):
    return tinyweb_external.command('tempo', '', '', str(__pyk_float(bpm)), 1)

def sound__swing(amount):
    return tinyweb_external.command('swing', '', '', str(__pyk_float(amount)), 1)

def sound__on_beat(f, steps):
    id = tinyweb_external.fresh_id('beat')
    tinyweb_external.watch_step(id, 'beat', f)
    tinyweb_external.command('beat', id, '', str(steps), 0)
    return id

def sound__beat():
    return tinyweb_external.report_number('clock', 0)

def sound__latency():
    return tinyweb_external.report_number('clock', 1)

def sound__pause():
    return tinyweb_external.command('audio', '', 'pause', '', 2)

def sound__resume():
    return tinyweb_external.command('audio', '', 'resume', '', 2)

def sound__channel_style(channel, volume, pan, echo, echo_time, feedback, reverb, low_pass):
    return tinyweb_external.command('channel', str(channel), '', floats4(volume, pan, echo, echo_time) + ' ' + floats3(feedback, reverb, low_pass), 1)

def sound__listen(bins, smoothing):
    return tinyweb_external.command('listen', '', '', str(bins) + ' ' + str(__pyk_float(smoothing)), 1)

def sound__level():
    return tinyweb_external.report_number('level', 0)

def sound__band(k):
    return tinyweb_external.report_number('band', k)

def sound__bands():
    return tinyweb_external.report_count('band')

def sound__wave(k):
    return tinyweb_external.report_number('wave', k)

def sound__render_wav__default__on_rendered():
    return sound__ignore_rendered

def sound__render_wav(seconds, f, name, on_rendered):
    id = tinyweb_external.fresh_id('render')
    tinyweb_external.watch_pair(id, 'rendered', on_rendered)
    tinyweb_external.command('render', id, name, str(__pyk_float(seconds)), 2)
    f()
    return tinyweb_external.command('render_end', id, '', '', 2)

def sound__ignore_rendered(took, peak):
    return ()

def bitmap__bitmap__default__background():
    return color__white

def bitmap__bitmap(width, height, background):
    return tinyweb_external.make_bitmap(width, height, color__to_hex(background))

def bitmap__set_pixel(b, x, y, pixel):
    return tinyweb_external.set_pixel(b, x, y, color__to_hex(pixel))

def bitmap__get_pixel(b, x, y):
    return color__hex(tinyweb_external.get_pixel(b, x, y))

def bitmap__fill_bitmap(b, fill):
    return tinyweb_external.fill_bitmap(b, color__to_hex(fill))

def bitmap__show_bitmap(c, b, x, y, scale):
    return tinyweb_external.draw_bitmap(c, b, x, y, scale)

def layout__row():
    return tinyweb_external.row()

def layout__column():
    return tinyweb_external.column()

def layout__inside(id):
    return tinyweb_external.inside(id)

def layout__outside():
    return tinyweb_external.outside()

def layout__text_area__default__on_change():
    return ignore_text

def layout__text_area(words, rows, columns, on_change):
    id = tinyweb_external.fresh_id('text')
    tinyweb_external.watch_text(id, 'change', 'value.' + id, on_change)
    tinyweb_external.command('text_area', id, words, numbers2(rows, columns), 0)
    return id

def net__save_canvas(c, name):
    return tinyweb_external.command('save_canvas', c, name, '', 2)

def net__download(name, words):
    return tinyweb_external.command('download', name, words, '', 2)

def net__file_button__default__on_load():
    return ignore_text

def net__file_button(title, on_load):
    id = tinyweb_external.fresh_id(title)
    tinyweb_external.watch_text(id, 'loaded', 'file', on_load)
    tinyweb_external.command('file_button', id, title, '', 0)
    return id

def net__file_text():
    return tinyweb_external.report_text('file.text')

def game__cursor(c, name):
    return tinyweb_external.command('cursor', c, name, '', 1)

def smooth__width_of(width, style):
    return float(style.width) if width == 1.0 else width

def smooth__shape(c, kind, numbers, fill, stroke, width, alpha, paint, style):
    return tinyweb_external.draw_shape(c, kind, numbers, fill_of(fill, paint, style), stroke_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style))

def smooth__stroked(c, kind, numbers, stroke, width, alpha, style):
    return tinyweb_external.draw_shape(c, kind, numbers, '', line_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style))

def smooth__pairs(points):
    return [(p.x, p.y) for p in points]

def smooth__circle__default__fill():
    return color__black

def smooth__circle__default__stroke():
    return color__none

def smooth__circle__default__paint():
    return Color__Plain(color__none)

def smooth__circle__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def smooth__circle(c, x, y, radius, fill, stroke, width, alpha, paint, style):
    return smooth__shape(c, 'circle', floats3(x, y, radius), fill, stroke, width, alpha, paint, style)

def smooth__circles__default__fill():
    return color__black

def smooth__circles__default__stroke():
    return color__none

def smooth__circles__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def smooth__circles(c, circles, fill, stroke, width, alpha, style):
    return tinyweb_external.draw_triples(c, 'circles', circles, fill_of(fill, Color__Plain(color__none), style), stroke_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style))

def smooth__rect__default__fill():
    return color__black

def smooth__rect__default__stroke():
    return color__none

def smooth__rect__default__paint():
    return Color__Plain(color__none)

def smooth__rect__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def smooth__rect(c, x, y, w, h, fill, stroke, width, alpha, paint, style, radius):
    return smooth__shape(c, 'rect', floats4(x, y, w, h) + ' ' + str(__pyk_float(radius)), fill, stroke, width, alpha, paint, style)

def smooth__ellipse__default__fill():
    return color__black

def smooth__ellipse__default__stroke():
    return color__none

def smooth__ellipse__default__paint():
    return Color__Plain(color__none)

def smooth__ellipse__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def smooth__ellipse(c, x, y, rx, ry, fill, stroke, width, alpha, paint, style):
    return smooth__shape(c, 'ellipse', floats4(x, y, rx, ry), fill, stroke, width, alpha, paint, style)

def smooth__arc__default__fill():
    return color__black

def smooth__arc__default__stroke():
    return color__none

def smooth__arc__default__paint():
    return Color__Plain(color__none)

def smooth__arc__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def smooth__arc(c, x, y, radius, start, end, fill, stroke, width, alpha, paint, style):
    return smooth__shape(c, 'arc', floats3(x, y, radius) + ' ' + floats2(start, end), fill, stroke, width, alpha, paint, style)

def smooth__polygon__default__fill():
    return color__black

def smooth__polygon__default__stroke():
    return color__none

def smooth__polygon__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def smooth__polygon(c, points, fill, stroke, width, alpha, style):
    return tinyweb_external.draw_pairs(c, 'polygon', smooth__pairs(points), fill_of(fill, Color__Plain(color__none), style), stroke_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style))

def smooth__line__default__stroke():
    return color__black

def smooth__line__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def smooth__line(c, x1, y1, x2, y2, stroke, width, alpha, style):
    return smooth__stroked(c, 'line', floats4(x1, y1, x2, y2), stroke, width, alpha, style)

def smooth__lines__default__stroke():
    return color__black

def smooth__lines__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def smooth__lines(c, segments, stroke, width, alpha, style):
    return tinyweb_external.draw_quads(c, 'lines', [(a.x, a.y, b.x, b.y) for (a, b) in segments], '', line_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style))

def smooth__path__default__stroke():
    return color__black

def smooth__path__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def smooth__path(c, points, stroke, width, alpha, style):
    return tinyweb_external.draw_pairs(c, 'path', smooth__pairs(points), '', line_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style))

def smooth__curve__default__stroke():
    return color__black

def smooth__curve__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def smooth__curve(c, x1, y1, cx, cy, x2, y2, stroke, width, alpha, style):
    return smooth__stroked(c, 'curve', floats2(x1, y1) + ' ' + floats4(cx, cy, x2, y2), stroke, width, alpha, style)

def smooth__bezier__default__stroke():
    return color__black

def smooth__bezier__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def smooth__bezier(c, x1, y1, ax, ay, bx, by, x2, y2, stroke, width, alpha, style):
    return smooth__stroked(c, 'bezier', floats4(x1, y1, ax, ay) + ' ' + floats4(bx, by, x2, y2), stroke, width, alpha, style)

def smooth__text__default__fill():
    return color__black

def smooth__text__default__stroke():
    return color__none

def smooth__text__default__paint():
    return Color__Plain(color__none)

def smooth__text__default__style():
    return Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint())

def smooth__text(c, x, y, words, fill, size, font, align, bold, alpha, baseline, stroke, width, paint, style):
    return tinyweb_external.draw_text(c, x, y, words, fill_of(fill, paint, style), size, font, align, baseline, bold, stroke_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style))

def smooth__clip_circle(c, x, y, radius):
    return tinyweb_external.set_state(c, 'clip', 'circle', floats3(x, y, radius))

def smooth__clip_polygon(c, points):
    return tinyweb_external.set_state(c, 'clip', 'polygon', float_points_text(points))
