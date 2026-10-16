// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: node24. A module of the program, imported as 'tinyweb'.

import { debug, pykFormat } from './pyk-runtime.js';

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

function clear__default__color() {
  return '#ffffff';
}

function clear(c, color) {
  return tinyweb_external.fill_canvas(c, color);
}

function circle__default__color() {
  return '#000000';
}

function circle(c, x, y, radius, color) {
  return tinyweb_external.draw_circle(c, x, y, radius, color);
}

function rect__default__color() {
  return '#000000';
}

function rect(c, x, y, width, height, color) {
  return tinyweb_external.draw_rect(c, x, y, width, height, color);
}

function line__default__color() {
  return '#000000';
}

function line__default__width() {
  return 1;
}

function line(c, x1, y1, x2, y2, color, width) {
  return tinyweb_external.draw_line(c, x1, y1, x2, y2, color, width);
}

function text__default__color() {
  return '#000000';
}

function text__default__size() {
  return 16;
}

function text(c, x, y, words, color, size) {
  return tinyweb_external.draw_text(c, x, y, words, color, size);
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
    return tinyweb_external.apply_style(0, 'theme', 'name', name);
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

function page_style(background, color, font, size, padding, gap) {
  style_text(0, 'page', 'background', background);
  style_text(0, 'page', 'color', color);
  style_text(0, 'page', 'font', font);
  style_pixels(0, 'page', 'size', size);
  style_pixels(0, 'page', 'padding', padding);
  return style_pixels(0, 'page', 'gap', gap);
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
  style_text(0, 'button', 'background', background);
  style_text(0, 'button', 'color', color);
  style_text(0, 'button', 'border', border);
  style_pixels(0, 'button', 'radius', radius);
  style_text(0, 'button', 'font', font);
  style_pixels(0, 'button', 'size', size);
  return style_pixels(0, 'button', 'padding', padding);
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
  style_text(0, 'label', 'background', background);
  style_text(0, 'label', 'color', color);
  style_text(0, 'label', 'border', border);
  style_pixels(0, 'label', 'radius', radius);
  style_text(0, 'label', 'font', font);
  style_pixels(0, 'label', 'size', size);
  return style_pixels(0, 'label', 'padding', padding);
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
  style_text(0, 'slider', 'accent', accent);
  style_pixels(0, 'slider', 'width', width);
  style_text(0, 'slider', 'color', color);
  style_text(0, 'slider', 'font', font);
  return style_pixels(0, 'slider', 'size', size);
}

function canvas_style__default__border() {
  return '';
}

function canvas_style__default__radius() {
  return -1;
}

function canvas_style(border, radius) {
  style_text(0, 'canvas', 'border', border);
  return style_pixels(0, 'canvas', 'radius', radius);
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

function set_style(id, background, color, border, radius, font, size, padding, accent, width) {
  style_text(id, 'element', 'background', background);
  style_text(id, 'element', 'color', color);
  style_text(id, 'element', 'border', border);
  style_pixels(id, 'element', 'radius', radius);
  style_text(id, 'element', 'font', font);
  style_pixels(id, 'element', 'size', size);
  style_pixels(id, 'element', 'padding', padding);
  style_text(id, 'element', 'accent', accent);
  return style_pixels(id, 'element', 'width', width);
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

export { clear__default__color, clear, circle__default__color, circle, rect__default__color, rect, line__default__color, line__default__width, line, text__default__color, text__default__size, text, button__default__on_click, button, slider__default__on_change, slider, theme, page_style__default__background, page_style__default__color, page_style__default__font, page_style__default__size, page_style__default__padding, page_style__default__gap, page_style, button_style__default__background, button_style__default__color, button_style__default__border, button_style__default__radius, button_style__default__font, button_style__default__size, button_style__default__padding, button_style, label_style__default__background, label_style__default__color, label_style__default__border, label_style__default__radius, label_style__default__font, label_style__default__size, label_style__default__padding, label_style, slider_style__default__accent, slider_style__default__width, slider_style__default__color, slider_style__default__font, slider_style__default__size, slider_style, canvas_style__default__border, canvas_style__default__radius, canvas_style, set_colors__default__color, set_colors__default__background, set_colors, set_style__default__background, set_style__default__color, set_style__default__border, set_style__default__radius, set_style__default__font, set_style__default__size, set_style__default__padding, set_style__default__accent, set_style__default__width, set_style, play__default__at, play__default__volume, play__default__rate, play, play_file };
