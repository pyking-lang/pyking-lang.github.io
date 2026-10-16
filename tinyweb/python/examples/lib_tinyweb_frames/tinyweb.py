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

import tinyweb_external

def nothing():
    return ()

def ignore(value):
    return ()

def clear__default__color():
    return '#ffffff'

def clear(c, color):
    return tinyweb_external.fill_canvas(c, color)

def circle__default__color():
    return '#000000'

def circle(c, x, y, radius, color):
    return tinyweb_external.draw_circle(c, x, y, radius, color)

def rect__default__color():
    return '#000000'

def rect(c, x, y, width, height, color):
    return tinyweb_external.draw_rect(c, x, y, width, height, color)

def line__default__color():
    return '#000000'

def line__default__width():
    return 1

def line(c, x1, y1, x2, y2, color, width):
    return tinyweb_external.draw_line(c, x1, y1, x2, y2, color, width)

def text__default__color():
    return '#000000'

def text__default__size():
    return 16

def text(c, x, y, words, color, size):
    return tinyweb_external.draw_text(c, x, y, words, color, size)

def button__default__on_click():
    return nothing

def button(title, on_click):
    return tinyweb_external.make_button(title, on_click)

def slider__default__on_change():
    return ignore

def slider(low, high, value, on_change):
    return tinyweb_external.make_slider(low, high, value, on_change)

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
        return tinyweb_external.apply_style(0, 'theme', 'name', name)
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

def page_style(background, color, font, size, padding, gap):
    style_text(0, 'page', 'background', background)
    style_text(0, 'page', 'color', color)
    style_text(0, 'page', 'font', font)
    style_pixels(0, 'page', 'size', size)
    style_pixels(0, 'page', 'padding', padding)
    return style_pixels(0, 'page', 'gap', gap)

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
    style_text(0, 'button', 'background', background)
    style_text(0, 'button', 'color', color)
    style_text(0, 'button', 'border', border)
    style_pixels(0, 'button', 'radius', radius)
    style_text(0, 'button', 'font', font)
    style_pixels(0, 'button', 'size', size)
    return style_pixels(0, 'button', 'padding', padding)

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
    style_text(0, 'label', 'background', background)
    style_text(0, 'label', 'color', color)
    style_text(0, 'label', 'border', border)
    style_pixels(0, 'label', 'radius', radius)
    style_text(0, 'label', 'font', font)
    style_pixels(0, 'label', 'size', size)
    return style_pixels(0, 'label', 'padding', padding)

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
    style_text(0, 'slider', 'accent', accent)
    style_pixels(0, 'slider', 'width', width)
    style_text(0, 'slider', 'color', color)
    style_text(0, 'slider', 'font', font)
    return style_pixels(0, 'slider', 'size', size)

def canvas_style__default__border():
    return ''

def canvas_style__default__radius():
    return -1

def canvas_style(border, radius):
    style_text(0, 'canvas', 'border', border)
    return style_pixels(0, 'canvas', 'radius', radius)

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

def set_style(id, background, color, border, radius, font, size, padding, accent, width):
    style_text(id, 'element', 'background', background)
    style_text(id, 'element', 'color', color)
    style_text(id, 'element', 'border', border)
    style_pixels(id, 'element', 'radius', radius)
    style_text(id, 'element', 'font', font)
    style_pixels(id, 'element', 'size', size)
    style_pixels(id, 'element', 'padding', padding)
    style_text(id, 'element', 'accent', accent)
    return style_pixels(id, 'element', 'width', width)

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
