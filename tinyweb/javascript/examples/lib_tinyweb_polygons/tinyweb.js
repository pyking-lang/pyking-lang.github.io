// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: node24. A module of the program, imported as 'tinyweb'.

import { debug, pykFormat, pykFloatStr } from './pyk-runtime.js';

// A Pyking list is a JavaScript array with a marker on it: a tuple
// is an array too, and the two print differently. A property rather
// than a class, so that a formatter in another module can read it.
function pykList(items) {
  items.pykList = true;
  return items;
}

// Pyking's `++` joins two strings or two lists. A list is an array
// here and JavaScript's `+` would stringify one, so which is meant
// is decided by looking -- this backend infers no types.
function pykConcat(a, b) {
  return Array.isArray(a) ? pykList([...a, ...b]) : a + b;
}

import * as tinyweb_external from './tinyweb_external.js';

function nothing() {
  return [];
}

function ignore(value) {
  return [];
}

function ignore_bool(value) {
  return [];
}

function ignore_text(value) {
  return [];
}

function clear__default__color() {
  return '#ffffff';
}

function clear(c, color) {
  return tinyweb_external.fill_canvas(c, color);
}

function numbers2(a, b) {
  return pykConcat(pykConcat(pykFormat(a), ' '), pykFormat(b));
}

function numbers3(a, b, c) {
  return pykConcat(pykConcat(numbers2(a, b), ' '), pykFormat(c));
}

function numbers4(a, b, c, d) {
  return pykConcat(pykConcat(numbers2(a, b), ' '), numbers2(c, d));
}

function joined_by(words, between) {
  let whole = '';
  let chunk = '';
  let count = 0;
  let chunks = 0;
  for (const word of words) {
    chunk = count === 0 ? word : pykConcat(pykConcat(chunk, between), word);
    count = count + 1;
    if (count === 128) {
      whole = chunks === 0 ? chunk : pykConcat(pykConcat(whole, between), chunk);
      chunks = chunks + 1;
      chunk = '';
      count = 0;
    }
  }
  return count === 0 ? whole : chunks === 0 ? chunk : pykConcat(pykConcat(whole, between), chunk);
}

function joined(words) {
  return joined_by(words, ' ');
}

function points_text(points) {
  return joined(pykList(points.flatMap((__item) => {
  const x = __item[0];
  const y = __item[1];
  return [numbers2(x, y)];
})));
}

function segments_text(segments) {
  return joined(pykList(segments.flatMap((__item) => {
  const x1 = __item[0];
  const y1 = __item[1];
  const x2 = __item[2];
  const y2 = __item[3];
  return [numbers4(x1, y1, x2, y2)];
})));
}

function floats2(a, b) {
  return pykConcat(pykConcat(pykFloatStr(a), ' '), pykFloatStr(b));
}

function floats3(a, b, c) {
  return pykConcat(pykConcat(floats2(a, b), ' '), pykFloatStr(c));
}

function floats4(a, b, c, d) {
  return pykConcat(pykConcat(floats2(a, b), ' '), floats2(c, d));
}

function float_points_text(points) {
  return joined(pykList(points.flatMap((__item) => {
  const x = __item[0];
  const y = __item[1];
  return [floats2(x, y)];
})));
}

function web_init__default__port() {
  return 0;
}

function web_init(port) {
  return tinyweb_external.web_start(port);
}

function circle__default__color() {
  return '#000000';
}

function circle__default__outline() {
  return '';
}

function circle__default__outline_width() {
  return 1;
}

function circle__default__alpha() {
  return 1.0;
}

function circle(c, x, y, radius, color, outline, outline_width, alpha) {
  return tinyweb_external.draw_shape(c, 'circle', numbers3(x, y, radius), color, outline, outline_width, alpha);
}

function rect__default__color() {
  return '#000000';
}

function rect__default__outline() {
  return '';
}

function rect__default__outline_width() {
  return 1;
}

function rect__default__alpha() {
  return 1.0;
}

function rect__default__radius() {
  return 0;
}

function rect(c, x, y, width, height, color, outline, outline_width, alpha, radius) {
  return tinyweb_external.draw_shape(c, 'rect', pykConcat(pykConcat(numbers4(x, y, width, height), ' '), pykFormat(radius)), color, outline, outline_width, alpha);
}

function ellipse__default__color() {
  return '#000000';
}

function ellipse__default__outline() {
  return '';
}

function ellipse__default__outline_width() {
  return 1;
}

function ellipse__default__alpha() {
  return 1.0;
}

function ellipse(c, x, y, rx, ry, color, outline, outline_width, alpha) {
  return tinyweb_external.draw_shape(c, 'ellipse', numbers4(x, y, rx, ry), color, outline, outline_width, alpha);
}

function arc__default__color() {
  return '#000000';
}

function arc__default__outline() {
  return '';
}

function arc__default__outline_width() {
  return 1;
}

function arc__default__alpha() {
  return 1.0;
}

function arc(c, x, y, radius, start, end, color, outline, outline_width, alpha) {
  return tinyweb_external.draw_shape(c, 'arc', pykConcat(pykConcat(pykConcat(pykConcat(numbers3(x, y, radius), ' '), pykFloatStr(start)), ' '), pykFloatStr(end)), color, outline, outline_width, alpha);
}

function polygon__default__color() {
  return '#000000';
}

function polygon__default__outline() {
  return '';
}

function polygon__default__outline_width() {
  return 1;
}

function polygon__default__alpha() {
  return 1.0;
}

function polygon(c, points, color, outline, outline_width, alpha) {
  return tinyweb_external.draw_shape(c, 'polygon', points_text(points), color, outline, outline_width, alpha);
}

function line__default__color() {
  return '#000000';
}

function line__default__width() {
  return 1;
}

function line__default__alpha() {
  return 1.0;
}

function line(c, x1, y1, x2, y2, color, width, alpha) {
  return tinyweb_external.draw_shape(c, 'line', numbers4(x1, y1, x2, y2), '', color, width, alpha);
}

function path__default__color() {
  return '#000000';
}

function path__default__width() {
  return 1;
}

function path__default__alpha() {
  return 1.0;
}

function path(c, points, color, width, alpha) {
  return tinyweb_external.draw_shape(c, 'path', points_text(points), '', color, width, alpha);
}

function curve__default__color() {
  return '#000000';
}

function curve__default__width() {
  return 1;
}

function curve__default__alpha() {
  return 1.0;
}

function curve(c, x1, y1, cx, cy, x2, y2, color, width, alpha) {
  return tinyweb_external.draw_shape(c, 'curve', pykConcat(pykConcat(numbers2(x1, y1), ' '), numbers4(cx, cy, x2, y2)), '', color, width, alpha);
}

function lines__default__color() {
  return '#000000';
}

function lines__default__width() {
  return 1;
}

function lines__default__alpha() {
  return 1.0;
}

function lines(c, segments, color, width, alpha) {
  return tinyweb_external.draw_shape(c, 'lines', segments_text(segments), '', color, width, alpha);
}

function bezier__default__color() {
  return '#000000';
}

function bezier__default__width() {
  return 1;
}

function bezier__default__alpha() {
  return 1.0;
}

function bezier(c, x1, y1, ax, ay, bx, by, x2, y2, color, width, alpha) {
  return tinyweb_external.draw_shape(c, 'bezier', pykConcat(pykConcat(numbers4(x1, y1, ax, ay), ' '), numbers4(bx, by, x2, y2)), '', color, width, alpha);
}

function erase(c, x, y, width, height) {
  return tinyweb_external.draw_shape(c, 'erase', numbers4(x, y, width, height), '', '', 0.0, 1.0);
}

function line_style__default__cap() {
  return 'round';
}

function line_style__default__join() {
  return 'round';
}

function line_style__default__dash() {
  return 0.0;
}

function line_style__default__gap() {
  return 0.0;
}

function line_style__default__offset() {
  return 0.0;
}

function line_style__default__dash2() {
  return 0.0;
}

function line_style__default__gap2() {
  return 0.0;
}

function line_style(c, cap, join, dash, gap, offset, dash2, gap2) {
  const first = dash <= 0.0 ? '' : gap <= 0.0 ? pykConcat(' ', floats2(dash, dash)) : pykConcat(' ', floats2(dash, gap));
  const second = dash <= 0.0 ? '' : dash2 <= 0.0 ? '' : gap2 <= 0.0 ? pykConcat(' ', floats2(dash2, dash2)) : pykConcat(' ', floats2(dash2, gap2));
  return tinyweb_external.set_state(c, 'line_style', pykConcat(pykConcat(cap, ' '), join), pykConcat(pykConcat(pykFloatStr(offset), first), second));
}

function clip_rect(c, x, y, width, height) {
  return tinyweb_external.set_state(c, 'clip', 'rect', pykConcat(numbers4(x, y, width, height), ' 0'));
}

function clip_circle(c, x, y, radius) {
  return tinyweb_external.set_state(c, 'clip', 'circle', numbers3(x, y, radius));
}

function clip_polygon(c, points) {
  return tinyweb_external.set_state(c, 'clip', 'polygon', points_text(points));
}

function text__default__color() {
  return '#000000';
}

function text__default__size() {
  return 16;
}

function text__default__font() {
  return '';
}

function text__default__align() {
  return 'left';
}

function text__default__bold() {
  return false;
}

function text__default__alpha() {
  return 1.0;
}

function text__default__baseline() {
  return 'top';
}

function text__default__outline() {
  return '';
}

function text__default__outline_width() {
  return 1;
}

function text(c, x, y, words, color, size, font, align, bold, alpha, baseline, outline, outline_width) {
  return tinyweb_external.draw_text(c, x, y, words, color, size, font, align, baseline, bold, outline, outline_width, alpha);
}

function measure_text__default__size() {
  return 16;
}

function measure_text__default__font() {
  return '';
}

function measure_text__default__bold() {
  return false;
}

function measure_text(words, answer, size, font, bold) {
  return tinyweb_external.measure(words, size, font, bold, answer);
}

function translate(c, x, y) {
  return tinyweb_external.set_state(c, 'translate', '', pykConcat(pykConcat(pykFloatStr(x), ' '), pykFloatStr(y)));
}

function rotate(c, degrees) {
  return tinyweb_external.set_state(c, 'rotate', '', pykFloatStr(degrees));
}

function scale(c, sx, sy) {
  return tinyweb_external.set_state(c, 'scale', '', pykConcat(pykConcat(pykFloatStr(sx), ' '), pykFloatStr(sy)));
}

function push(c) {
  return tinyweb_external.set_state(c, 'push', '', '');
}

function pop(c) {
  return tinyweb_external.set_state(c, 'pop', '', '');
}

function reset(c) {
  return tinyweb_external.set_state(c, 'reset', '', '');
}

function shadow__default__blur() {
  return 10;
}

function shadow__default__dx() {
  return 0;
}

function shadow__default__dy() {
  return 0;
}

function shadow(c, color, blur, dx, dy) {
  return tinyweb_external.set_state(c, 'shadow', color, numbers3(blur, dx, dy));
}

function blend(c, mode) {
  const __subject = mode;
  if (__subject === 'normal' || __subject === 'add') {
    return tinyweb_external.set_state(c, 'blend', mode, '');
  } else {
    debug(pykConcat(pykConcat('tinyweb: there is no blending called "', mode), '"; the modes are normal and add'));
  }
}

function image__default__alpha() {
  return 1.0;
}

function image(c, picture, x, y, width, height, alpha) {
  return tinyweb_external.draw_image(c, picture, x, y, width, height, alpha);
}

function colors__hex2(n) {
  const clamped = n < 0 ? 0 : n > 255 ? 255 : n;
  return pykConcat(colors__hex_digit(Math.trunc(clamped / 16)), colors__hex_digit(clamped - Math.trunc(clamped / 16) * 16));
}

function colors__hex_digit(d) {
  const __subject = d;
  if (__subject === 0) {
    return '0';
  } else if (__subject === 1) {
    return '1';
  } else if (__subject === 2) {
    return '2';
  } else if (__subject === 3) {
    return '3';
  } else if (__subject === 4) {
    return '4';
  } else if (__subject === 5) {
    return '5';
  } else if (__subject === 6) {
    return '6';
  } else if (__subject === 7) {
    return '7';
  } else if (__subject === 8) {
    return '8';
  } else if (__subject === 9) {
    return '9';
  } else if (__subject === 10) {
    return 'a';
  } else if (__subject === 11) {
    return 'b';
  } else if (__subject === 12) {
    return 'c';
  } else if (__subject === 13) {
    return 'd';
  } else if (__subject === 14) {
    return 'e';
  } else {
    return 'f';
  }
}

function colors__rgb(r, g, b) {
  return pykConcat(pykConcat(pykConcat('#', colors__hex2(r)), colors__hex2(g)), colors__hex2(b));
}

function colors__rgba(r, g, b, a) {
  return pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat('rgba(', pykFormat(r)), ', '), pykFormat(g)), ', '), pykFormat(b)), ', '), pykFloatStr(a)), ')');
}

function colors__hsl(h, s, l) {
  return pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat('hsl(', pykFormat(h)), ', '), pykFormat(s)), '%, '), pykFormat(l)), '%)');
}

function colors__palette(name) {
  const __subject = name;
  if (__subject === 'ocean') {
    return pykList(['#03045e', '#0077b6', '#00b4d8', '#90e0ef', '#caf0f8']);
  } else if (__subject === 'candy') {
    return pykList(['#ff70a6', '#ff9770', '#ffd670', '#e9ff70', '#70d6ff']);
  } else if (__subject === 'forest') {
    return pykList(['#2d6a4f', '#40916c', '#52b788', '#95d5b2', '#d8f3dc']);
  } else if (__subject === 'sunset') {
    return pykList(['#f94144', '#f3722c', '#f8961e', '#f9c74f', '#90be6d']);
  } else if (__subject === 'neon') {
    return pykList(['#ff00ff', '#00ffff', '#39ff14', '#ffff00', '#ff3131']);
  } else {
    debug(pykConcat(pykConcat('tinyweb: there is no palette called "', name), '"; the palettes are ocean, candy, forest, sunset and neon'));
    return pykList([]);
  }
}

function colors__linear_gradient(x1, y1, x2, y2, start, end) {
  return pykConcat(pykConcat(pykConcat(pykConcat(pykConcat('linear-gradient(', floats4(x1, y1, x2, y2)), '); 0.0 '), start), '; 1.0 '), end);
}

function colors__radial_gradient(x1, y1, r1, x2, y2, r2, start, end) {
  return pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat('radial-gradient(', floats3(x1, y1, r1)), ' '), floats3(x2, y2, r2)), '); 0.0 '), start), '; 1.0 '), end);
}

function colors__conic_gradient(x, y, angle, start, end) {
  return pykConcat(pykConcat(pykConcat(pykConcat(pykConcat('conic-gradient(', floats3(x, y, angle)), '); 0.0 '), start), '; 1.0 '), end);
}

function colors__stop(gradient, at, color) {
  return pykConcat(pykConcat(pykConcat(pykConcat(gradient, '; '), pykFloatStr(at)), ' '), color);
}

function button__default__on_click() {
  return nothing;
}

function button(title, on_click) {
  return tinyweb_external.make_button(title, on_click);
}

function slider__default__on_change() {
  return ignore;
}

function slider(low, high, value, on_change) {
  return tinyweb_external.make_slider(low, high, value, on_change);
}

function checkbox__default__checked() {
  return false;
}

function checkbox__default__on_change() {
  return ignore_bool;
}

function checkbox(title, checked, on_change) {
  return tinyweb_external.make_checkbox(title, checked, on_change);
}

function radio__default__chosen() {
  return false;
}

function radio__default__on_pick() {
  return ignore_text;
}

function radio(group, title, chosen, on_pick) {
  return tinyweb_external.make_radio(group, title, chosen, on_pick);
}

function lines_of(options) {
  const __subject = options;
  if (__subject.length === 0) {
    return '';
  } else if (__subject.length === 1) {
    const only = __subject[0];
    return only;
  } else if (__subject.length >= 1) {
    const first = __subject[0];
    const rest = pykList(__subject.slice(1, __subject.length - 0));
    return pykConcat(pykConcat(first, '\n'), lines_of(rest));
  }
}

function choice__default__chosen() {
  return 0;
}

function choice__default__on_change() {
  return ignore;
}

function choice(options, chosen, on_change) {
  return tinyweb_external.make_choice(lines_of(options), chosen, on_change);
}

function text_input__default__placeholder() {
  return '';
}

function text_input__default__on_enter() {
  return ignore_text;
}

function text_input(placeholder, on_enter) {
  return tinyweb_external.make_text_input(placeholder, on_enter);
}

function number_input__default__on_change() {
  return ignore;
}

function number_input(low, high, value, on_change) {
  return tinyweb_external.make_number_input(low, high, value, on_change);
}

function known_theme(name) {
  const __subject = name;
  if (__subject === 'light') {
    return true;
  } else if (__subject === 'dark') {
    return true;
  } else if (__subject === 'plain') {
    return true;
  } else if (__subject === 'paper') {
    return true;
  } else if (__subject === 'retro') {
    return true;
  } else {
    return false;
  }
}

function style_text(id, kind, property, value) {
  if (value === '') {
    return [];
  } else {
    return tinyweb_external.apply_style(id, kind, property, value);
  }
}

function style_pixels(id, kind, property, value) {
  if (value < 0) {
    return [];
  } else {
    return tinyweb_external.apply_style(id, kind, property, pykConcat(pykFormat(value), 'px'));
  }
}

function theme(name) {
  if (known_theme(name)) {
    return tinyweb_external.apply_style('', 'theme', 'name', name);
  } else {
    debug(pykConcat(pykConcat('tinyweb: there is no theme called "', name), '"; the themes are light, dark, plain, paper and retro'));
  }
}

function page_style__default__background() {
  return '';
}

function page_style__default__color() {
  return '';
}

function page_style__default__font() {
  return '';
}

function page_style__default__size() {
  return -1;
}

function page_style__default__padding() {
  return -1;
}

function page_style__default__gap() {
  return -1;
}

function page_style__default__align() {
  return '';
}

function page_style(background, color, font, size, padding, gap, align) {
  style_text('', 'page', 'background', background);
  style_text('', 'page', 'color', color);
  style_text('', 'page', 'font', font);
  style_pixels('', 'page', 'size', size);
  style_pixels('', 'page', 'padding', padding);
  style_pixels('', 'page', 'gap', gap);
  return style_text('', 'page', 'align', align);
}

function button_style__default__background() {
  return '';
}

function button_style__default__color() {
  return '';
}

function button_style__default__border() {
  return '';
}

function button_style__default__radius() {
  return -1;
}

function button_style__default__font() {
  return '';
}

function button_style__default__size() {
  return -1;
}

function button_style__default__padding() {
  return -1;
}

function button_style(background, color, border, radius, font, size, padding) {
  style_text('', 'button', 'background', background);
  style_text('', 'button', 'color', color);
  style_text('', 'button', 'border', border);
  style_pixels('', 'button', 'radius', radius);
  style_text('', 'button', 'font', font);
  style_pixels('', 'button', 'size', size);
  return style_pixels('', 'button', 'padding', padding);
}

function label_style__default__background() {
  return '';
}

function label_style__default__color() {
  return '';
}

function label_style__default__border() {
  return '';
}

function label_style__default__radius() {
  return -1;
}

function label_style__default__font() {
  return '';
}

function label_style__default__size() {
  return -1;
}

function label_style__default__padding() {
  return -1;
}

function label_style(background, color, border, radius, font, size, padding) {
  style_text('', 'label', 'background', background);
  style_text('', 'label', 'color', color);
  style_text('', 'label', 'border', border);
  style_pixels('', 'label', 'radius', radius);
  style_text('', 'label', 'font', font);
  style_pixels('', 'label', 'size', size);
  return style_pixels('', 'label', 'padding', padding);
}

function slider_style__default__accent() {
  return '';
}

function slider_style__default__width() {
  return -1;
}

function slider_style__default__color() {
  return '';
}

function slider_style__default__font() {
  return '';
}

function slider_style__default__size() {
  return -1;
}

function slider_style(accent, width, color, font, size) {
  style_text('', 'slider', 'accent', accent);
  style_pixels('', 'slider', 'width', width);
  style_text('', 'slider', 'color', color);
  style_text('', 'slider', 'font', font);
  return style_pixels('', 'slider', 'size', size);
}

function canvas_style__default__border() {
  return '';
}

function canvas_style__default__radius() {
  return -1;
}

function canvas_style(border, radius) {
  style_text('', 'canvas', 'border', border);
  return style_pixels('', 'canvas', 'radius', radius);
}

function set_colors__default__color() {
  return '';
}

function set_colors__default__background() {
  return '';
}

function set_colors(id, color, background) {
  style_text(id, 'element', 'color', color);
  style_text(id, 'element', 'accent', color);
  return style_text(id, 'element', 'background', background);
}

function set_style__default__background() {
  return '';
}

function set_style__default__color() {
  return '';
}

function set_style__default__border() {
  return '';
}

function set_style__default__radius() {
  return -1;
}

function set_style__default__font() {
  return '';
}

function set_style__default__size() {
  return -1;
}

function set_style__default__padding() {
  return -1;
}

function set_style__default__accent() {
  return '';
}

function set_style__default__width() {
  return -1;
}

function set_style__default__weight() {
  return -1;
}

function set_style__default__height() {
  return -1;
}

function set_style(id, background, color, border, radius, font, size, padding, accent, width, weight, height) {
  style_text(id, 'element', 'background', background);
  style_text(id, 'element', 'color', color);
  style_text(id, 'element', 'border', border);
  style_pixels(id, 'element', 'radius', radius);
  style_text(id, 'element', 'font', font);
  style_pixels(id, 'element', 'size', size);
  style_pixels(id, 'element', 'padding', padding);
  style_text(id, 'element', 'accent', accent);
  style_pixels(id, 'element', 'width', width);
  if (weight >= 0) {
    style_text(id, 'element', 'weight', pykFormat(weight));
  }
  return style_pixels(id, 'element', 'height', height);
}

function play__default__at() {
  return 0.0;
}

function play__default__volume() {
  return 1.0;
}

function play__default__rate() {
  return 1.0;
}

function play(sample, at, volume, rate) {
  return tinyweb_external.play_sample(sample, at, volume, rate);
}

function play_file(name) {
  return play(tinyweb_external.load_sample(name), play__default__at(), play__default__volume(), play__default__rate());
}

function on_press(c, f) {
  return tinyweb_external.watch_pointer(c, 'press', f);
}

function on_release(c, f) {
  return tinyweb_external.watch_pointer(c, 'release', f);
}

function on_move(c, f) {
  return tinyweb_external.watch_pointer(c, 'move', f);
}

function on_drag(c, f) {
  return tinyweb_external.watch_pointer(c, 'drag', f);
}

function mouse_x(c) {
  return tinyweb_external.pointer(c, 'x');
}

function mouse_y(c) {
  return tinyweb_external.pointer(c, 'y');
}

function mouse_down(c) {
  return tinyweb_external.pointer(c, 'down') === 1;
}

function ignore2(x, y) {
  return [];
}

function show_bitmap__default__x() {
  return 0;
}

function show_bitmap__default__y() {
  return 0;
}

function show_bitmap__default__scale() {
  return 1.0;
}

function show_bitmap(c, b, x, y, scale2) {
  return tinyweb_external.draw_bitmap(c, b, x, y, scale2);
}

function channel_of(n) {
  return n < 0 ? 0 : n > 255 ? 255 : n;
}

function pixel_color(r, g, b) {
  return channel_of(r) * 65536 + channel_of(g) * 256 + channel_of(b);
}

function red(color) {
  return Math.trunc(color / 65536) - Math.trunc(color / 16777216) * 256;
}

function green(color) {
  return Math.trunc(color / 256) - Math.trunc(color / 65536) * 256;
}

function blue(color) {
  return color - Math.trunc(color / 256) * 256;
}

function smooth__circle__default__color() {
  return '#000000';
}

function smooth__circle__default__outline() {
  return '';
}

function smooth__circle__default__outline_width() {
  return 1.0;
}

function smooth__circle__default__alpha() {
  return 1.0;
}

function smooth__circle(c, x, y, radius, color, outline, outline_width, alpha) {
  return tinyweb_external.draw_shape(c, 'circle', floats3(x, y, radius), color, outline, outline_width, alpha);
}

function smooth__circles__default__color() {
  return '#000000';
}

function smooth__circles__default__outline() {
  return '';
}

function smooth__circles__default__outline_width() {
  return 1.0;
}

function smooth__circles__default__alpha() {
  return 1.0;
}

function smooth__circles(c, circles, color, outline, outline_width, alpha) {
  return tinyweb_external.draw_triples(c, 'circles', circles, color, outline, outline_width, alpha);
}

function smooth__rect__default__color() {
  return '#000000';
}

function smooth__rect__default__outline() {
  return '';
}

function smooth__rect__default__outline_width() {
  return 1.0;
}

function smooth__rect__default__alpha() {
  return 1.0;
}

function smooth__rect__default__radius() {
  return 0.0;
}

function smooth__rect(c, x, y, width, height, color, outline, outline_width, alpha, radius) {
  return tinyweb_external.draw_shape(c, 'rect', pykConcat(pykConcat(floats4(x, y, width, height), ' '), pykFloatStr(radius)), color, outline, outline_width, alpha);
}

function smooth__ellipse__default__color() {
  return '#000000';
}

function smooth__ellipse__default__outline() {
  return '';
}

function smooth__ellipse__default__outline_width() {
  return 1.0;
}

function smooth__ellipse__default__alpha() {
  return 1.0;
}

function smooth__ellipse(c, x, y, rx, ry, color, outline, outline_width, alpha) {
  return tinyweb_external.draw_shape(c, 'ellipse', floats4(x, y, rx, ry), color, outline, outline_width, alpha);
}

function smooth__arc__default__color() {
  return '#000000';
}

function smooth__arc__default__outline() {
  return '';
}

function smooth__arc__default__outline_width() {
  return 1.0;
}

function smooth__arc__default__alpha() {
  return 1.0;
}

function smooth__arc(c, x, y, radius, start, end, color, outline, outline_width, alpha) {
  return tinyweb_external.draw_shape(c, 'arc', pykConcat(pykConcat(floats3(x, y, radius), ' '), floats2(start, end)), color, outline, outline_width, alpha);
}

function smooth__polygon__default__color() {
  return '#000000';
}

function smooth__polygon__default__outline() {
  return '';
}

function smooth__polygon__default__outline_width() {
  return 1.0;
}

function smooth__polygon__default__alpha() {
  return 1.0;
}

function smooth__polygon(c, points, color, outline, outline_width, alpha) {
  return tinyweb_external.draw_pairs(c, 'polygon', points, color, outline, outline_width, alpha);
}

function smooth__line__default__color() {
  return '#000000';
}

function smooth__line__default__width() {
  return 1.0;
}

function smooth__line__default__alpha() {
  return 1.0;
}

function smooth__line(c, x1, y1, x2, y2, color, width, alpha) {
  return tinyweb_external.draw_shape(c, 'line', floats4(x1, y1, x2, y2), '', color, width, alpha);
}

function smooth__lines__default__color() {
  return '#000000';
}

function smooth__lines__default__width() {
  return 1.0;
}

function smooth__lines__default__alpha() {
  return 1.0;
}

function smooth__lines(c, segments, color, width, alpha) {
  return tinyweb_external.draw_quads(c, 'lines', segments, '', color, width, alpha);
}

function smooth__path__default__color() {
  return '#000000';
}

function smooth__path__default__width() {
  return 1.0;
}

function smooth__path__default__alpha() {
  return 1.0;
}

function smooth__path(c, points, color, width, alpha) {
  return tinyweb_external.draw_pairs(c, 'path', points, '', color, width, alpha);
}

function smooth__curve__default__color() {
  return '#000000';
}

function smooth__curve__default__width() {
  return 1.0;
}

function smooth__curve__default__alpha() {
  return 1.0;
}

function smooth__curve(c, x1, y1, cx, cy, x2, y2, color, width, alpha) {
  return tinyweb_external.draw_shape(c, 'curve', pykConcat(pykConcat(floats2(x1, y1), ' '), floats4(cx, cy, x2, y2)), '', color, width, alpha);
}

function smooth__bezier__default__color() {
  return '#000000';
}

function smooth__bezier__default__width() {
  return 1.0;
}

function smooth__bezier__default__alpha() {
  return 1.0;
}

function smooth__bezier(c, x1, y1, ax, ay, bx, by, x2, y2, color, width, alpha) {
  return tinyweb_external.draw_shape(c, 'bezier', pykConcat(pykConcat(floats4(x1, y1, ax, ay), ' '), floats4(bx, by, x2, y2)), '', color, width, alpha);
}

function smooth__text__default__color() {
  return '#000000';
}

function smooth__text__default__size() {
  return 16;
}

function smooth__text__default__font() {
  return '';
}

function smooth__text__default__align() {
  return 'left';
}

function smooth__text__default__bold() {
  return false;
}

function smooth__text__default__alpha() {
  return 1.0;
}

function smooth__text__default__baseline() {
  return 'top';
}

function smooth__text__default__outline() {
  return '';
}

function smooth__text__default__outline_width() {
  return 1.0;
}

function smooth__text(c, x, y, words, color, size, font, align, bold, alpha, baseline, outline, outline_width) {
  return tinyweb_external.draw_text(c, x, y, words, color, size, font, align, baseline, bold, outline, outline_width, alpha);
}

function smooth__clip_circle(c, x, y, radius) {
  return tinyweb_external.set_state(c, 'clip', 'circle', floats3(x, y, radius));
}

function smooth__clip_polygon(c, points) {
  return tinyweb_external.set_state(c, 'clip', 'polygon', float_points_text(points));
}

export { clear__default__color, clear, web_init__default__port, web_init, circle__default__color, circle__default__outline, circle__default__outline_width, circle__default__alpha, circle, rect__default__color, rect__default__outline, rect__default__outline_width, rect__default__alpha, rect__default__radius, rect, ellipse__default__color, ellipse__default__outline, ellipse__default__outline_width, ellipse__default__alpha, ellipse, arc__default__color, arc__default__outline, arc__default__outline_width, arc__default__alpha, arc, polygon__default__color, polygon__default__outline, polygon__default__outline_width, polygon__default__alpha, polygon, line__default__color, line__default__width, line__default__alpha, line, path__default__color, path__default__width, path__default__alpha, path, curve__default__color, curve__default__width, curve__default__alpha, curve, lines__default__color, lines__default__width, lines__default__alpha, lines, bezier__default__color, bezier__default__width, bezier__default__alpha, bezier, erase, line_style__default__cap, line_style__default__join, line_style__default__dash, line_style__default__gap, line_style__default__offset, line_style__default__dash2, line_style__default__gap2, line_style, clip_rect, clip_circle, clip_polygon, text__default__color, text__default__size, text__default__font, text__default__align, text__default__bold, text__default__alpha, text__default__baseline, text__default__outline, text__default__outline_width, text, measure_text__default__size, measure_text__default__font, measure_text__default__bold, measure_text, translate, rotate, scale, push, pop, reset, shadow__default__blur, shadow__default__dx, shadow__default__dy, shadow, blend, image__default__alpha, image, colors__rgb, colors__rgba, colors__hsl, colors__palette, colors__linear_gradient, colors__radial_gradient, colors__conic_gradient, colors__stop, button__default__on_click, button, slider__default__on_change, slider, checkbox__default__checked, checkbox__default__on_change, checkbox, radio__default__chosen, radio__default__on_pick, radio, choice__default__chosen, choice__default__on_change, choice, text_input__default__placeholder, text_input__default__on_enter, text_input, number_input__default__on_change, number_input, theme, page_style__default__background, page_style__default__color, page_style__default__font, page_style__default__size, page_style__default__padding, page_style__default__gap, page_style__default__align, page_style, button_style__default__background, button_style__default__color, button_style__default__border, button_style__default__radius, button_style__default__font, button_style__default__size, button_style__default__padding, button_style, label_style__default__background, label_style__default__color, label_style__default__border, label_style__default__radius, label_style__default__font, label_style__default__size, label_style__default__padding, label_style, slider_style__default__accent, slider_style__default__width, slider_style__default__color, slider_style__default__font, slider_style__default__size, slider_style, canvas_style__default__border, canvas_style__default__radius, canvas_style, set_colors__default__color, set_colors__default__background, set_colors, set_style__default__background, set_style__default__color, set_style__default__border, set_style__default__radius, set_style__default__font, set_style__default__size, set_style__default__padding, set_style__default__accent, set_style__default__width, set_style__default__weight, set_style__default__height, set_style, play__default__at, play__default__volume, play__default__rate, play, play_file, on_press, on_release, on_move, on_drag, mouse_x, mouse_y, mouse_down, ignore2, show_bitmap__default__x, show_bitmap__default__y, show_bitmap__default__scale, show_bitmap, pixel_color, red, green, blue, smooth__circle__default__color, smooth__circle__default__outline, smooth__circle__default__outline_width, smooth__circle__default__alpha, smooth__circle, smooth__circles__default__color, smooth__circles__default__outline, smooth__circles__default__outline_width, smooth__circles__default__alpha, smooth__circles, smooth__rect__default__color, smooth__rect__default__outline, smooth__rect__default__outline_width, smooth__rect__default__alpha, smooth__rect__default__radius, smooth__rect, smooth__ellipse__default__color, smooth__ellipse__default__outline, smooth__ellipse__default__outline_width, smooth__ellipse__default__alpha, smooth__ellipse, smooth__arc__default__color, smooth__arc__default__outline, smooth__arc__default__outline_width, smooth__arc__default__alpha, smooth__arc, smooth__polygon__default__color, smooth__polygon__default__outline, smooth__polygon__default__outline_width, smooth__polygon__default__alpha, smooth__polygon, smooth__line__default__color, smooth__line__default__width, smooth__line__default__alpha, smooth__line, smooth__lines__default__color, smooth__lines__default__width, smooth__lines__default__alpha, smooth__lines, smooth__path__default__color, smooth__path__default__width, smooth__path__default__alpha, smooth__path, smooth__curve__default__color, smooth__curve__default__width, smooth__curve__default__alpha, smooth__curve, smooth__bezier__default__color, smooth__bezier__default__width, smooth__bezier__default__alpha, smooth__bezier, smooth__text__default__color, smooth__text__default__size, smooth__text__default__font, smooth__text__default__align, smooth__text__default__bold, smooth__text__default__alpha, smooth__text__default__baseline, smooth__text__default__outline, smooth__text__default__outline_width, smooth__text, smooth__clip_circle, smooth__clip_polygon };
