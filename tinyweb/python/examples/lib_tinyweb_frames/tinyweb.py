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

# --- prelude ends; the compiled program follows ---

import tinyweb_external

def nothing():
    return ()

def ignore(value):
    return ()

def ignore_bool(value):
    return ()

def ignore_text(value):
    return ()

def clear__default__color():
    return '#ffffff'

def clear(c, color):
    return tinyweb_external.fill_canvas(c, color)

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
    return joined([numbers2(x, y) for (x, y) in points])

def segments_text(segments):
    return joined([numbers4(x1, y1, x2, y2) for (x1, y1, x2, y2) in segments])

def floats2(a, b):
    return str(__pyk_float(a)) + ' ' + str(__pyk_float(b))

def floats3(a, b, c):
    return floats2(a, b) + ' ' + str(__pyk_float(c))

def floats4(a, b, c, d):
    return floats2(a, b) + ' ' + floats2(c, d)

def float_points_text(points):
    return joined([floats2(x, y) for (x, y) in points])

def web_init__default__port():
    return 0

def web_init(port):
    return tinyweb_external.web_start(port)

def circle__default__color():
    return '#000000'

def circle__default__outline():
    return ''

def circle__default__outline_width():
    return 1

def circle__default__alpha():
    return 1.0

def circle(c, x, y, radius, color, outline, outline_width, alpha):
    return tinyweb_external.draw_shape(c, 'circle', numbers3(x, y, radius), color, outline, float(outline_width), alpha)

def rect__default__color():
    return '#000000'

def rect__default__outline():
    return ''

def rect__default__outline_width():
    return 1

def rect__default__alpha():
    return 1.0

def rect__default__radius():
    return 0

def rect(c, x, y, width, height, color, outline, outline_width, alpha, radius):
    return tinyweb_external.draw_shape(c, 'rect', numbers4(x, y, width, height) + ' ' + str(radius), color, outline, float(outline_width), alpha)

def ellipse__default__color():
    return '#000000'

def ellipse__default__outline():
    return ''

def ellipse__default__outline_width():
    return 1

def ellipse__default__alpha():
    return 1.0

def ellipse(c, x, y, rx, ry, color, outline, outline_width, alpha):
    return tinyweb_external.draw_shape(c, 'ellipse', numbers4(x, y, rx, ry), color, outline, float(outline_width), alpha)

def arc__default__color():
    return '#000000'

def arc__default__outline():
    return ''

def arc__default__outline_width():
    return 1

def arc__default__alpha():
    return 1.0

def arc(c, x, y, radius, start, end, color, outline, outline_width, alpha):
    return tinyweb_external.draw_shape(c, 'arc', numbers3(x, y, radius) + ' ' + str(__pyk_float(start)) + ' ' + str(__pyk_float(end)), color, outline, float(outline_width), alpha)

def polygon__default__color():
    return '#000000'

def polygon__default__outline():
    return ''

def polygon__default__outline_width():
    return 1

def polygon__default__alpha():
    return 1.0

def polygon(c, points, color, outline, outline_width, alpha):
    return tinyweb_external.draw_shape(c, 'polygon', points_text(points), color, outline, float(outline_width), alpha)

def line__default__color():
    return '#000000'

def line__default__width():
    return 1

def line__default__alpha():
    return 1.0

def line(c, x1, y1, x2, y2, color, width, alpha):
    return tinyweb_external.draw_shape(c, 'line', numbers4(x1, y1, x2, y2), '', color, float(width), alpha)

def path__default__color():
    return '#000000'

def path__default__width():
    return 1

def path__default__alpha():
    return 1.0

def path(c, points, color, width, alpha):
    return tinyweb_external.draw_shape(c, 'path', points_text(points), '', color, float(width), alpha)

def curve__default__color():
    return '#000000'

def curve__default__width():
    return 1

def curve__default__alpha():
    return 1.0

def curve(c, x1, y1, cx, cy, x2, y2, color, width, alpha):
    return tinyweb_external.draw_shape(c, 'curve', numbers2(x1, y1) + ' ' + numbers4(cx, cy, x2, y2), '', color, float(width), alpha)

def lines__default__color():
    return '#000000'

def lines__default__width():
    return 1

def lines__default__alpha():
    return 1.0

def lines(c, segments, color, width, alpha):
    return tinyweb_external.draw_shape(c, 'lines', segments_text(segments), '', color, float(width), alpha)

def bezier__default__color():
    return '#000000'

def bezier__default__width():
    return 1

def bezier__default__alpha():
    return 1.0

def bezier(c, x1, y1, ax, ay, bx, by, x2, y2, color, width, alpha):
    return tinyweb_external.draw_shape(c, 'bezier', numbers4(x1, y1, ax, ay) + ' ' + numbers4(bx, by, x2, y2), '', color, float(width), alpha)

def erase(c, x, y, width, height):
    return tinyweb_external.draw_shape(c, 'erase', numbers4(x, y, width, height), '', '', 0.0, 1.0)

def line_style__default__cap():
    return 'round'

def line_style__default__join():
    return 'round'

def line_style__default__dash():
    return 0.0

def line_style__default__gap():
    return 0.0

def line_style__default__offset():
    return 0.0

def line_style__default__dash2():
    return 0.0

def line_style__default__gap2():
    return 0.0

def line_style(c, cap, join, dash, gap, offset, dash2, gap2):
    first = '' if dash <= 0.0 else ' ' + floats2(dash, dash) if gap <= 0.0 else ' ' + floats2(dash, gap)
    second = '' if dash <= 0.0 else '' if dash2 <= 0.0 else ' ' + floats2(dash2, dash2) if gap2 <= 0.0 else ' ' + floats2(dash2, gap2)
    return tinyweb_external.set_state(c, 'line_style', cap + ' ' + join, str(__pyk_float(offset)) + first + second)

def clip_rect(c, x, y, width, height):
    return tinyweb_external.set_state(c, 'clip', 'rect', numbers4(x, y, width, height) + ' 0')

def clip_circle(c, x, y, radius):
    return tinyweb_external.set_state(c, 'clip', 'circle', numbers3(x, y, radius))

def clip_polygon(c, points):
    return tinyweb_external.set_state(c, 'clip', 'polygon', points_text(points))

def text__default__color():
    return '#000000'

def text__default__size():
    return 16

def text__default__font():
    return ''

def text__default__align():
    return 'left'

def text__default__bold():
    return False

def text__default__alpha():
    return 1.0

def text__default__baseline():
    return 'top'

def text__default__outline():
    return ''

def text__default__outline_width():
    return 1

def text(c, x, y, words, color, size, font, align, bold, alpha, baseline, outline, outline_width):
    return tinyweb_external.draw_text(c, float(x), float(y), words, color, size, font, align, baseline, bold, outline, float(outline_width), alpha)

def measure_text__default__size():
    return 16

def measure_text__default__font():
    return ''

def measure_text__default__bold():
    return False

def measure_text(words, answer, size, font, bold):
    return tinyweb_external.measure(words, size, font, bold, answer)

def translate(c, x, y):
    return tinyweb_external.set_state(c, 'translate', '', str(__pyk_float(x)) + ' ' + str(__pyk_float(y)))

def rotate(c, degrees):
    return tinyweb_external.set_state(c, 'rotate', '', str(__pyk_float(degrees)))

def scale(c, sx, sy):
    return tinyweb_external.set_state(c, 'scale', '', str(__pyk_float(sx)) + ' ' + str(__pyk_float(sy)))

def push(c):
    return tinyweb_external.set_state(c, 'push', '', '')

def pop(c):
    return tinyweb_external.set_state(c, 'pop', '', '')

def reset(c):
    return tinyweb_external.set_state(c, 'reset', '', '')

def shadow__default__blur():
    return 10

def shadow__default__dx():
    return 0

def shadow__default__dy():
    return 0

def shadow(c, color, blur, dx, dy):
    return tinyweb_external.set_state(c, 'shadow', color, numbers3(blur, dx, dy))

def blend(c, mode):
    match mode:
        case 'normal' | 'add':
            return tinyweb_external.set_state(c, 'blend', mode, '')
        case _:
            print('tinyweb: there is no blending called "' + mode + '"; the modes are normal and add', file=__import__('sys').stderr)
    return ()

def image__default__alpha():
    return 1.0

def image(c, picture, x, y, width, height, alpha):
    return tinyweb_external.draw_image(c, picture, x, y, width, height, alpha)

def colors__hex2(n):
    clamped = 0 if n < 0 else 255 if n > 255 else n
    return colors__hex_digit(__pyk_div(clamped, 16)) + colors__hex_digit(clamped - __pyk_div(clamped, 16) * 16)

def colors__hex_digit(d):
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

def colors__rgb(r, g, b):
    return '#' + colors__hex2(r) + colors__hex2(g) + colors__hex2(b)

def colors__rgba(r, g, b, a):
    return 'rgba(' + str(r) + ', ' + str(g) + ', ' + str(b) + ', ' + str(__pyk_float(a)) + ')'

def colors__hsl(h, s, l):
    return 'hsl(' + str(h) + ', ' + str(s) + '%, ' + str(l) + '%)'

def colors__palette(name):
    match name:
        case 'ocean':
            return ['#03045e', '#0077b6', '#00b4d8', '#90e0ef', '#caf0f8']
        case 'candy':
            return ['#ff70a6', '#ff9770', '#ffd670', '#e9ff70', '#70d6ff']
        case 'forest':
            return ['#2d6a4f', '#40916c', '#52b788', '#95d5b2', '#d8f3dc']
        case 'sunset':
            return ['#f94144', '#f3722c', '#f8961e', '#f9c74f', '#90be6d']
        case 'neon':
            return ['#ff00ff', '#00ffff', '#39ff14', '#ffff00', '#ff3131']
        case _:
            print('tinyweb: there is no palette called "' + name + '"; the palettes are ocean, candy, forest, sunset and neon', file=__import__('sys').stderr)
            return []

def colors__linear_gradient(x1, y1, x2, y2, start, end):
    return 'linear-gradient(' + floats4(x1, y1, x2, y2) + '); 0.0 ' + start + '; 1.0 ' + end

def colors__radial_gradient(x1, y1, r1, x2, y2, r2, start, end):
    return 'radial-gradient(' + floats3(x1, y1, r1) + ' ' + floats3(x2, y2, r2) + '); 0.0 ' + start + '; 1.0 ' + end

def colors__conic_gradient(x, y, angle, start, end):
    return 'conic-gradient(' + floats3(x, y, angle) + '); 0.0 ' + start + '; 1.0 ' + end

def colors__stop(gradient, at, color):
    return gradient + '; ' + str(__pyk_float(at)) + ' ' + color

def button__default__on_click():
    return nothing

def button(title, on_click):
    return tinyweb_external.make_button(title, on_click)

def slider__default__on_change():
    return ignore

def slider(low, high, value, on_change):
    return tinyweb_external.make_slider(low, high, value, on_change)

def checkbox__default__checked():
    return False

def checkbox__default__on_change():
    return ignore_bool

def checkbox(title, checked, on_change):
    return tinyweb_external.make_checkbox(title, checked, on_change)

def radio__default__chosen():
    return False

def radio__default__on_pick():
    return ignore_text

def radio(group, title, chosen, on_pick):
    return tinyweb_external.make_radio(group, title, chosen, on_pick)

def lines_of(options):
    match options:
        case []:
            return ''
        case [only]:
            return only
        case [first, *rest]:
            return first + '\n' + lines_of(rest)

def choice__default__chosen():
    return 0

def choice__default__on_change():
    return ignore

def choice(options, chosen, on_change):
    return tinyweb_external.make_choice(lines_of(options), chosen, on_change)

def text_input__default__placeholder():
    return ''

def text_input__default__on_enter():
    return ignore_text

def text_input(placeholder, on_enter):
    return tinyweb_external.make_text_input(placeholder, on_enter)

def number_input__default__on_change():
    return ignore

def number_input(low, high, value, on_change):
    return tinyweb_external.make_number_input(low, high, value, on_change)

def known_theme(name):
    match name:
        case 'light':
            return True
        case 'dark':
            return True
        case 'plain':
            return True
        case 'paper':
            return True
        case 'retro':
            return True
        case _:
            return False

def style_text(id, kind, property, value):
    if value == '':
        return ()
    else:
        return tinyweb_external.apply_style(id, kind, property, value)

def style_pixels(id, kind, property, value):
    if value < 0:
        return ()
    else:
        return tinyweb_external.apply_style(id, kind, property, str(value) + 'px')

def theme(name):
    if known_theme(name):
        return tinyweb_external.apply_style('', 'theme', 'name', name)
    else:
        print('tinyweb: there is no theme called "' + name + '"; the themes are light, dark, plain, paper and retro', file=__import__('sys').stderr)
    return ()

def page_style__default__background():
    return ''

def page_style__default__color():
    return ''

def page_style__default__font():
    return ''

def page_style__default__size():
    return -1

def page_style__default__padding():
    return -1

def page_style__default__gap():
    return -1

def page_style__default__align():
    return ''

def page_style(background, color, font, size, padding, gap, align):
    style_text('', 'page', 'background', background)
    style_text('', 'page', 'color', color)
    style_text('', 'page', 'font', font)
    style_pixels('', 'page', 'size', size)
    style_pixels('', 'page', 'padding', padding)
    style_pixels('', 'page', 'gap', gap)
    return style_text('', 'page', 'align', align)

def button_style__default__background():
    return ''

def button_style__default__color():
    return ''

def button_style__default__border():
    return ''

def button_style__default__radius():
    return -1

def button_style__default__font():
    return ''

def button_style__default__size():
    return -1

def button_style__default__padding():
    return -1

def button_style(background, color, border, radius, font, size, padding):
    style_text('', 'button', 'background', background)
    style_text('', 'button', 'color', color)
    style_text('', 'button', 'border', border)
    style_pixels('', 'button', 'radius', radius)
    style_text('', 'button', 'font', font)
    style_pixels('', 'button', 'size', size)
    return style_pixels('', 'button', 'padding', padding)

def label_style__default__background():
    return ''

def label_style__default__color():
    return ''

def label_style__default__border():
    return ''

def label_style__default__radius():
    return -1

def label_style__default__font():
    return ''

def label_style__default__size():
    return -1

def label_style__default__padding():
    return -1

def label_style(background, color, border, radius, font, size, padding):
    style_text('', 'label', 'background', background)
    style_text('', 'label', 'color', color)
    style_text('', 'label', 'border', border)
    style_pixels('', 'label', 'radius', radius)
    style_text('', 'label', 'font', font)
    style_pixels('', 'label', 'size', size)
    return style_pixels('', 'label', 'padding', padding)

def slider_style__default__accent():
    return ''

def slider_style__default__width():
    return -1

def slider_style__default__color():
    return ''

def slider_style__default__font():
    return ''

def slider_style__default__size():
    return -1

def slider_style(accent, width, color, font, size):
    style_text('', 'slider', 'accent', accent)
    style_pixels('', 'slider', 'width', width)
    style_text('', 'slider', 'color', color)
    style_text('', 'slider', 'font', font)
    return style_pixels('', 'slider', 'size', size)

def canvas_style__default__border():
    return ''

def canvas_style__default__radius():
    return -1

def canvas_style(border, radius):
    style_text('', 'canvas', 'border', border)
    return style_pixels('', 'canvas', 'radius', radius)

def set_colors__default__color():
    return ''

def set_colors__default__background():
    return ''

def set_colors(id, color, background):
    style_text(id, 'element', 'color', color)
    style_text(id, 'element', 'accent', color)
    return style_text(id, 'element', 'background', background)

def set_style__default__background():
    return ''

def set_style__default__color():
    return ''

def set_style__default__border():
    return ''

def set_style__default__radius():
    return -1

def set_style__default__font():
    return ''

def set_style__default__size():
    return -1

def set_style__default__padding():
    return -1

def set_style__default__accent():
    return ''

def set_style__default__width():
    return -1

def set_style__default__weight():
    return -1

def set_style__default__height():
    return -1

def set_style(id, background, color, border, radius, font, size, padding, accent, width, weight, height):
    style_text(id, 'element', 'background', background)
    style_text(id, 'element', 'color', color)
    style_text(id, 'element', 'border', border)
    style_pixels(id, 'element', 'radius', radius)
    style_text(id, 'element', 'font', font)
    style_pixels(id, 'element', 'size', size)
    style_pixels(id, 'element', 'padding', padding)
    style_text(id, 'element', 'accent', accent)
    style_pixels(id, 'element', 'width', width)
    if weight >= 0:
        style_text(id, 'element', 'weight', str(weight))
    return style_pixels(id, 'element', 'height', height)

def play__default__at():
    return 0.0

def play__default__volume():
    return 1.0

def play__default__rate():
    return 1.0

def play(sample, at, volume, rate):
    return tinyweb_external.play_sample(sample, at, volume, rate)

def play_file(name):
    return play(tinyweb_external.load_sample(name), play__default__at(), play__default__volume(), play__default__rate())

def on_press(c, f):
    return tinyweb_external.watch_pointer(c, 'press', f)

def on_release(c, f):
    return tinyweb_external.watch_pointer(c, 'release', f)

def on_move(c, f):
    return tinyweb_external.watch_pointer(c, 'move', f)

def on_drag(c, f):
    return tinyweb_external.watch_pointer(c, 'drag', f)

def mouse_x(c):
    return tinyweb_external.pointer(c, 'x')

def mouse_y(c):
    return tinyweb_external.pointer(c, 'y')

def mouse_down(c):
    return tinyweb_external.pointer(c, 'down') == 1

def ignore2(x, y):
    return ()

def show_bitmap__default__x():
    return 0

def show_bitmap__default__y():
    return 0

def show_bitmap__default__scale():
    return 1.0

def show_bitmap(c, b, x, y, scale):
    return tinyweb_external.draw_bitmap(c, b, x, y, scale)

def channel_of(n):
    return 0 if n < 0 else 255 if n > 255 else n

def pixel_color(r, g, b):
    return channel_of(r) * 65536 + channel_of(g) * 256 + channel_of(b)

def red(color):
    return __pyk_div(color, 65536) - __pyk_div(color, 16777216) * 256

def green(color):
    return __pyk_div(color, 256) - __pyk_div(color, 65536) * 256

def blue(color):
    return color - __pyk_div(color, 256) * 256

def smooth__circle__default__color():
    return '#000000'

def smooth__circle__default__outline():
    return ''

def smooth__circle__default__outline_width():
    return 1.0

def smooth__circle__default__alpha():
    return 1.0

def smooth__circle(c, x, y, radius, color, outline, outline_width, alpha):
    return tinyweb_external.draw_shape(c, 'circle', floats3(x, y, radius), color, outline, outline_width, alpha)

def smooth__circles__default__color():
    return '#000000'

def smooth__circles__default__outline():
    return ''

def smooth__circles__default__outline_width():
    return 1.0

def smooth__circles__default__alpha():
    return 1.0

def smooth__circles(c, circles, color, outline, outline_width, alpha):
    return tinyweb_external.draw_triples(c, 'circles', circles, color, outline, outline_width, alpha)

def smooth__rect__default__color():
    return '#000000'

def smooth__rect__default__outline():
    return ''

def smooth__rect__default__outline_width():
    return 1.0

def smooth__rect__default__alpha():
    return 1.0

def smooth__rect__default__radius():
    return 0.0

def smooth__rect(c, x, y, width, height, color, outline, outline_width, alpha, radius):
    return tinyweb_external.draw_shape(c, 'rect', floats4(x, y, width, height) + ' ' + str(__pyk_float(radius)), color, outline, outline_width, alpha)

def smooth__ellipse__default__color():
    return '#000000'

def smooth__ellipse__default__outline():
    return ''

def smooth__ellipse__default__outline_width():
    return 1.0

def smooth__ellipse__default__alpha():
    return 1.0

def smooth__ellipse(c, x, y, rx, ry, color, outline, outline_width, alpha):
    return tinyweb_external.draw_shape(c, 'ellipse', floats4(x, y, rx, ry), color, outline, outline_width, alpha)

def smooth__arc__default__color():
    return '#000000'

def smooth__arc__default__outline():
    return ''

def smooth__arc__default__outline_width():
    return 1.0

def smooth__arc__default__alpha():
    return 1.0

def smooth__arc(c, x, y, radius, start, end, color, outline, outline_width, alpha):
    return tinyweb_external.draw_shape(c, 'arc', floats3(x, y, radius) + ' ' + floats2(start, end), color, outline, outline_width, alpha)

def smooth__polygon__default__color():
    return '#000000'

def smooth__polygon__default__outline():
    return ''

def smooth__polygon__default__outline_width():
    return 1.0

def smooth__polygon__default__alpha():
    return 1.0

def smooth__polygon(c, points, color, outline, outline_width, alpha):
    return tinyweb_external.draw_pairs(c, 'polygon', points, color, outline, outline_width, alpha)

def smooth__line__default__color():
    return '#000000'

def smooth__line__default__width():
    return 1.0

def smooth__line__default__alpha():
    return 1.0

def smooth__line(c, x1, y1, x2, y2, color, width, alpha):
    return tinyweb_external.draw_shape(c, 'line', floats4(x1, y1, x2, y2), '', color, width, alpha)

def smooth__lines__default__color():
    return '#000000'

def smooth__lines__default__width():
    return 1.0

def smooth__lines__default__alpha():
    return 1.0

def smooth__lines(c, segments, color, width, alpha):
    return tinyweb_external.draw_quads(c, 'lines', segments, '', color, width, alpha)

def smooth__path__default__color():
    return '#000000'

def smooth__path__default__width():
    return 1.0

def smooth__path__default__alpha():
    return 1.0

def smooth__path(c, points, color, width, alpha):
    return tinyweb_external.draw_pairs(c, 'path', points, '', color, width, alpha)

def smooth__curve__default__color():
    return '#000000'

def smooth__curve__default__width():
    return 1.0

def smooth__curve__default__alpha():
    return 1.0

def smooth__curve(c, x1, y1, cx, cy, x2, y2, color, width, alpha):
    return tinyweb_external.draw_shape(c, 'curve', floats2(x1, y1) + ' ' + floats4(cx, cy, x2, y2), '', color, width, alpha)

def smooth__bezier__default__color():
    return '#000000'

def smooth__bezier__default__width():
    return 1.0

def smooth__bezier__default__alpha():
    return 1.0

def smooth__bezier(c, x1, y1, ax, ay, bx, by, x2, y2, color, width, alpha):
    return tinyweb_external.draw_shape(c, 'bezier', floats4(x1, y1, ax, ay) + ' ' + floats4(bx, by, x2, y2), '', color, width, alpha)

def smooth__text__default__color():
    return '#000000'

def smooth__text__default__size():
    return 16

def smooth__text__default__font():
    return ''

def smooth__text__default__align():
    return 'left'

def smooth__text__default__bold():
    return False

def smooth__text__default__alpha():
    return 1.0

def smooth__text__default__baseline():
    return 'top'

def smooth__text__default__outline():
    return ''

def smooth__text__default__outline_width():
    return 1.0

def smooth__text(c, x, y, words, color, size, font, align, bold, alpha, baseline, outline, outline_width):
    return tinyweb_external.draw_text(c, x, y, words, color, size, font, align, baseline, bold, outline, outline_width, alpha)

def smooth__clip_circle(c, x, y, radius):
    return tinyweb_external.set_state(c, 'clip', 'circle', floats3(x, y, radius))

def smooth__clip_polygon(c, points):
    return tinyweb_external.set_state(c, 'clip', 'polygon', float_points_text(points))
