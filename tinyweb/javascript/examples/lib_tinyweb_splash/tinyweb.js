// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: node22. A module of the program, imported as 'tinyweb'.

import { debug, pykFormat, pykFloatStr, pykParseInt, pykTrunc } from './pyk-runtime.js';

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

// A value of a datatype: its constructor's name and its fields, in
// order, with each field that has a name also a property by it.
function pykData(tag, values, names) {
  const value = { pykTag: tag, pykValues: values, pykShape: null };
  names.forEach((name, i) => { if (name !== null) value[name] = values[i]; });
  return value;
}

// Which fields of a datatype's value are Floats, which only the
// compiler knows: a JavaScript number cannot say.
function pykWithShape(value, shape) {
  value.pykShape = shape;
  return value;
}

import * as tinyweb_external from './tinyweb_external.js';
import * as math2 from './math.js';
import * as math2_external from './math_external.js';
import * as strings from './text.js';
import * as strings_external from './text_external.js';

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

function ignore_float(value) {
  return [];
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
  const p = __item;
  return [numbers2(p.x, p.y)];
})));
}

function segments_text(segments) {
  return joined(pykList(segments.flatMap((__item) => {
  const a = __item[0];
  const b = __item[1];
  return [numbers4(a.x, a.y, b.x, b.y)];
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
  const p = __item;
  return [floats2(p.x, p.y)];
})));
}

function bit(on) {
  return on ? '1' : '0';
}

function Color__Color(v0, v1, v2, v3) {
  return pykData('Color__Color', [v0, v1, v2, v3], ['r', 'g', 'b', 'a']);
}

const color__black = pykWithShape(Color__Color(0, 0, 0, 1.0), '(.,.,.,f)');
const color__white = pykWithShape(Color__Color(255, 255, 255, 1.0), '(.,.,.,f)');
const color__gray = pykWithShape(Color__Color(128, 128, 128, 1.0), '(.,.,.,f)');
const color__red = pykWithShape(Color__Color(255, 0, 0, 1.0), '(.,.,.,f)');
const color__green = pykWithShape(Color__Color(0, 128, 0, 1.0), '(.,.,.,f)');
const color__blue = pykWithShape(Color__Color(0, 0, 255, 1.0), '(.,.,.,f)');
const color__yellow = pykWithShape(Color__Color(255, 255, 0, 1.0), '(.,.,.,f)');
const color__orange = pykWithShape(Color__Color(255, 165, 0, 1.0), '(.,.,.,f)');
const color__purple = pykWithShape(Color__Color(128, 0, 128, 1.0), '(.,.,.,f)');
const color__pink = pykWithShape(Color__Color(255, 192, 203, 1.0), '(.,.,.,f)');
const color__navy = pykWithShape(Color__Color(0, 0, 128, 1.0), '(.,.,.,f)');
const color__teal = pykWithShape(Color__Color(0, 128, 128, 1.0), '(.,.,.,f)');
const color__brown = pykWithShape(Color__Color(139, 69, 19, 1.0), '(.,.,.,f)');
const color__cyan = pykWithShape(Color__Color(0, 255, 255, 1.0), '(.,.,.,f)');
const color__magenta = pykWithShape(Color__Color(255, 0, 255, 1.0), '(.,.,.,f)');
const color__none = pykWithShape(Color__Color(0, 0, 0, 0.0), '(.,.,.,f)');
const color__theme = pykWithShape(Color__Color(-1, -1, -1, -1.0), '(.,.,.,f)');

function color__sector(sector, chroma, x) {
  const __subject = sector;
  if (__subject === 0) {
    return [chroma, x, 0.0];
  } else if (__subject === 1) {
    return [x, chroma, 0.0];
  } else if (__subject === 2) {
    return [0.0, chroma, x];
  } else if (__subject === 3) {
    return [0.0, x, chroma];
  } else if (__subject === 4) {
    return [x, 0.0, chroma];
  } else {
    return [chroma, 0.0, x];
  }
}

function color__part(n) {
  return n < 0 ? 0 : n > 255 ? 255 : n;
}

function color__unit(x) {
  return x < 0.0 ? 0.0 : x > 1.0 ? 1.0 : x;
}

function color__byte(x) {
  return color__part(pykTrunc(color__unit(x) * 255.0 + 0.5));
}

function color__absolute(x) {
  return x < 0.0 ? -x : x;
}

function color__wrap(x, m) {
  const r = x - pykTrunc(x / m) * m;
  return r < 0.0 ? r + m : r;
}

function color__between(a, b, t) {
  return a + (b - a) * t;
}

function color__hex2(n) {
  const clamped = color__part(n);
  return pykConcat(color__hex_digit(Math.trunc(clamped / 16)), color__hex_digit(clamped - Math.trunc(clamped / 16) * 16));
}

function color__hex_digit(d) {
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

function color__css(c) {
  if (c.a >= 1.0) {
    return pykConcat(pykConcat(pykConcat('#', color__hex2(c.r)), color__hex2(c.g)), color__hex2(c.b));
  } else {
    return pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat('rgba(', pykFormat(color__part(c.r))), ', '), pykFormat(color__part(c.g))), ', '), pykFormat(color__part(c.b))), ', '), pykFloatStr(color__unit(c.a))), ')');
  }
}

function color__drawn(c) {
  return c.a <= 0.0 ? '' : color__css(c);
}

function color__paint_text(p) {
  const __subject = p;
  if (__subject.pykTag === 'Color__Plain') {
    const c = __subject.pykValues[0];
    return color__drawn(c);
  } else if (__subject.pykTag === 'Color__Linear') {
    const x1 = __subject.pykValues[0];
    const y1 = __subject.pykValues[1];
    const x2 = __subject.pykValues[2];
    const y2 = __subject.pykValues[3];
    const start = __subject.pykValues[4];
    const end = __subject.pykValues[5];
    const stops = __subject.pykValues[6];
    return pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat('linear-gradient(', floats4(x1, y1, x2, y2)), '); 0.0 '), color__css(start)), '; 1.0 '), color__css(end)), stops);
  } else if (__subject.pykTag === 'Color__Radial') {
    const x1 = __subject.pykValues[0];
    const y1 = __subject.pykValues[1];
    const r1 = __subject.pykValues[2];
    const x2 = __subject.pykValues[3];
    const y2 = __subject.pykValues[4];
    const r2 = __subject.pykValues[5];
    const start = __subject.pykValues[6];
    const end = __subject.pykValues[7];
    const stops = __subject.pykValues[8];
    return pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat('radial-gradient(', floats3(x1, y1, r1)), ' '), floats3(x2, y2, r2)), '); 0.0 '), color__css(start)), '; 1.0 '), color__css(end)), stops);
  } else if (__subject.pykTag === 'Color__Conic') {
    const x = __subject.pykValues[0];
    const y = __subject.pykValues[1];
    const angle = __subject.pykValues[2];
    const start = __subject.pykValues[3];
    const end = __subject.pykValues[4];
    const stops = __subject.pykValues[5];
    return pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat('conic-gradient(', floats3(x, y, angle)), '); 0.0 '), color__css(start)), '; 1.0 '), color__css(end)), stops);
  }
}

function color__painted(p) {
  const __subject = p;
  if (__subject.pykTag === 'Color__Plain') {
    const c = __subject.pykValues[0];
    return c.a > 0.0;
  } else {
    return true;
  }
}

function color__is_theme(c) {
  return c.a < 0.0;
}

function color__rgb(r, g, b) {
  return pykWithShape(Color__Color(color__part(r), color__part(g), color__part(b), 1.0), '(.,.,.,f)');
}

function color__rgba(r, g, b, a) {
  return pykWithShape(Color__Color(color__part(r), color__part(g), color__part(b), a < 0.0 ? 0.0 : a > 1.0 ? 1.0 : a), '(.,.,.,f)');
}

function color__hsl(h, s, l) {
  const hue = color__wrap(h, 360.0) / 60.0;
  const sat = color__unit(s / 100.0);
  const light = color__unit(l / 100.0);
  const chroma = (1.0 - color__absolute(2.0 * light - 1.0)) * sat;
  const x = chroma * (1.0 - color__absolute(color__wrap(hue, 2.0) - 1.0));
  const m = light - chroma / 2.0;
  const [r, g, b] = color__sector(pykTrunc(hue), chroma, x);
  return pykWithShape(Color__Color(color__byte(r + m), color__byte(g + m), color__byte(b + m), 1.0), '(.,.,.,f)');
}

function color__hex(n) {
  return pykWithShape(Color__Color(color__part(Math.trunc(n / 65536)), color__part(Math.trunc(n / 256) - Math.trunc(n / 65536) * 256), color__part(n - Math.trunc(n / 256) * 256), 1.0), '(.,.,.,f)');
}

function color__to_hex(c) {
  return color__part(c.r) * 65536 + color__part(c.g) * 256 + color__part(c.b);
}

function color__with_alpha(c, a) {
  return pykWithShape(Color__Color(c.r, c.g, c.b, color__unit(a)), '(.,.,.,f)');
}

function color__mix(a, b, t) {
  const k = color__unit(t);
  return pykWithShape(Color__Color(color__byte(color__between(a.r, b.r, k) / 255.0), color__byte(color__between(a.g, b.g, k) / 255.0), color__byte(color__between(a.b, b.b, k) / 255.0), a.a + (b.a - a.a) * k), '(.,.,.,f)');
}

function color__same(a, b) {
  return a.r === b.r ? a.g === b.g ? a.b === b.b ? a.a === b.a : false : false : false;
}

function color__palette(name) {
  const __subject = name;
  if (__subject === 'ocean') {
    return pykList([color__hex(197726), color__hex(30646), color__hex(46296), color__hex(9494767), color__hex(13299960)]);
  } else if (__subject === 'candy') {
    return pykList([color__hex(16740518), color__hex(16750448), color__hex(16766576), color__hex(15335280), color__hex(7395071)]);
  } else if (__subject === 'forest') {
    return pykList([color__hex(2976335), color__hex(4231532), color__hex(5420936), color__hex(9819570), color__hex(14218204)]);
  } else if (__subject === 'sunset') {
    return pykList([color__hex(16335172), color__hex(15954476), color__hex(16291358), color__hex(16369487), color__hex(9485933)]);
  } else if (__subject === 'neon') {
    return pykList([color__hex(16711935), color__hex(65535), color__hex(3800852), color__hex(16776960), color__hex(16724273)]);
  } else {
    debug(pykConcat(pykConcat('tinyweb: there is no palette called "', name), '"; the palettes are ocean, candy, forest, sunset and neon'));
    return pykList([]);
  }
}

const Color__Paint = 'Color__Paint';

function Color__Plain(v0) {
  return pykData('Color__Plain', [v0], [null]);
}

function Color__Linear(v0, v1, v2, v3, v4, v5, v6) {
  return pykData('Color__Linear', [v0, v1, v2, v3, v4, v5, v6], ['x1', 'y1', 'x2', 'y2', 'start', 'end', 'stops']);
}

function Color__Radial(v0, v1, v2, v3, v4, v5, v6, v7, v8) {
  return pykData('Color__Radial', [v0, v1, v2, v3, v4, v5, v6, v7, v8], ['x1', 'y1', 'r1', 'x2', 'y2', 'r2', 'start', 'end', 'stops']);
}

function Color__Conic(v0, v1, v2, v3, v4, v5) {
  return pykData('Color__Conic', [v0, v1, v2, v3, v4, v5], ['x', 'y', 'angle', 'start', 'end', 'stops']);
}

function color__stop(paint, at, c) {
  const more = pykConcat(pykConcat(pykConcat('; ', pykFloatStr(at)), ' '), color__css(c));
  const __subject = paint;
  if (__subject.pykTag === 'Color__Plain') {
    return paint;
  } else if (__subject.pykTag === 'Color__Linear') {
    const x1 = __subject.pykValues[0];
    const y1 = __subject.pykValues[1];
    const x2 = __subject.pykValues[2];
    const y2 = __subject.pykValues[3];
    const start = __subject.pykValues[4];
    const end = __subject.pykValues[5];
    const stops = __subject.pykValues[6];
    return pykWithShape(Color__Linear(x1, y1, x2, y2, start, end, pykConcat(stops, more)), '(f,f,f,f,.,.,.)');
  } else if (__subject.pykTag === 'Color__Radial') {
    const x1 = __subject.pykValues[0];
    const y1 = __subject.pykValues[1];
    const r1 = __subject.pykValues[2];
    const x2 = __subject.pykValues[3];
    const y2 = __subject.pykValues[4];
    const r2 = __subject.pykValues[5];
    const start = __subject.pykValues[6];
    const end = __subject.pykValues[7];
    const stops = __subject.pykValues[8];
    return pykWithShape(Color__Radial(x1, y1, r1, x2, y2, r2, start, end, pykConcat(stops, more)), '(f,f,f,f,f,f,.,.,.)');
  } else if (__subject.pykTag === 'Color__Conic') {
    const x = __subject.pykValues[0];
    const y = __subject.pykValues[1];
    const angle = __subject.pykValues[2];
    const start = __subject.pykValues[3];
    const end = __subject.pykValues[4];
    const stops = __subject.pykValues[5];
    return pykWithShape(Color__Conic(x, y, angle, start, end, pykConcat(stops, more)), '(f,f,f,.,.,.)');
  }
}

function web_init(port) {
  return tinyweb_external.web_start(port);
}

function Point(v0, v1) {
  return pykData('Point', [v0, v1], ['x', 'y']);
}

function field__default__Style__fill() {
  return color__black;
}

function field__default__Style__stroke() {
  return color__none;
}

function field__default__Style__paint() {
  return Color__Plain(color__none);
}

function Style(v0, v1, v2, v3, v4) {
  return pykData('Style', [v0, v1, v2, v3, v4], ['fill', 'stroke', 'width', 'alpha', 'paint']);
}

function Pointer(v0, v1, v2) {
  return pykData('Pointer', [v0, v1, v2], ['x', 'y', 'down']);
}

function fill_of(fill, paint, style) {
  if (color__painted(paint)) {
    return color__paint_text(paint);
  } else if (not_default_fill(fill)) {
    return color__drawn(fill);
  } else if (color__painted(style.paint)) {
    return color__paint_text(style.paint);
  } else {
    return color__drawn(style.fill);
  }
}

function not_default_fill(fill) {
  return color__same(fill, color__black) ? false : true;
}

function stroke_of(stroke, style) {
  return color__drawn(color__same(stroke, color__none) ? style.stroke : stroke);
}

function line_of(stroke, style) {
  if (not_default_fill(stroke)) {
    return color__drawn(stroke);
  } else if (color__same(style.stroke, color__none)) {
    return color__drawn(style.fill);
  } else {
    return color__drawn(style.stroke);
  }
}

function width_of(width, style) {
  return width === 1 ? style.width : width;
}

function alpha_of(alpha, style) {
  return alpha === 1.0 ? style.alpha : alpha;
}

function shape(c, kind, numbers, fill, stroke, width, alpha, paint, style) {
  return tinyweb_external.draw_shape(c, kind, numbers, fill_of(fill, paint, style), stroke_of(stroke, style), width_of(width, style), alpha_of(alpha, style));
}

function stroked(c, kind, numbers, stroke, width, alpha, style) {
  return tinyweb_external.draw_shape(c, kind, numbers, '', line_of(stroke, style), width_of(width, style), alpha_of(alpha, style));
}

function clear__default__fill() {
  return color__white;
}

function clear(c, fill) {
  return tinyweb_external.fill_canvas(c, color__css(fill));
}

function circle__default__fill() {
  return color__black;
}

function circle__default__stroke() {
  return color__none;
}

function circle__default__paint() {
  return Color__Plain(color__none);
}

function circle__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function circle(c, x, y, radius, fill, stroke, width, alpha, paint, style) {
  return shape(c, 'circle', numbers3(x, y, radius), fill, stroke, width, alpha, paint, style);
}

function rect__default__fill() {
  return color__black;
}

function rect__default__stroke() {
  return color__none;
}

function rect__default__paint() {
  return Color__Plain(color__none);
}

function rect__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function rect(c, x, y, w, h, fill, stroke, width, alpha, paint, style, radius) {
  return shape(c, 'rect', pykConcat(pykConcat(numbers4(x, y, w, h), ' '), pykFormat(radius)), fill, stroke, width, alpha, paint, style);
}

function ellipse__default__fill() {
  return color__black;
}

function ellipse__default__stroke() {
  return color__none;
}

function ellipse__default__paint() {
  return Color__Plain(color__none);
}

function ellipse__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function ellipse(c, x, y, rx, ry, fill, stroke, width, alpha, paint, style) {
  return shape(c, 'ellipse', numbers4(x, y, rx, ry), fill, stroke, width, alpha, paint, style);
}

function arc__default__fill() {
  return color__black;
}

function arc__default__stroke() {
  return color__none;
}

function arc__default__paint() {
  return Color__Plain(color__none);
}

function arc__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function arc(c, x, y, radius, start, end, fill, stroke, width, alpha, paint, style) {
  return shape(c, 'arc', pykConcat(pykConcat(numbers3(x, y, radius), ' '), floats2(start, end)), fill, stroke, width, alpha, paint, style);
}

function polygon__default__fill() {
  return color__black;
}

function polygon__default__stroke() {
  return color__none;
}

function polygon__default__paint() {
  return Color__Plain(color__none);
}

function polygon__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function polygon(c, points, fill, stroke, width, alpha, paint, style) {
  return shape(c, 'polygon', points_text(points), fill, stroke, width, alpha, paint, style);
}

function line__default__stroke() {
  return color__black;
}

function line__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function line(c, x1, y1, x2, y2, stroke, width, alpha, style) {
  return stroked(c, 'line', numbers4(x1, y1, x2, y2), stroke, width, alpha, style);
}

function path__default__stroke() {
  return color__black;
}

function path__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function path(c, points, stroke, width, alpha, style) {
  return stroked(c, 'path', points_text(points), stroke, width, alpha, style);
}

function curve__default__stroke() {
  return color__black;
}

function curve__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function curve(c, x1, y1, cx, cy, x2, y2, stroke, width, alpha, style) {
  return stroked(c, 'curve', pykConcat(pykConcat(numbers2(x1, y1), ' '), numbers4(cx, cy, x2, y2)), stroke, width, alpha, style);
}

function lines__default__stroke() {
  return color__black;
}

function lines__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function lines(c, segments, stroke, width, alpha, style) {
  return stroked(c, 'lines', segments_text(segments), stroke, width, alpha, style);
}

function bezier__default__stroke() {
  return color__black;
}

function bezier__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function bezier(c, x1, y1, ax, ay, bx, by, x2, y2, stroke, width, alpha, style) {
  return stroked(c, 'bezier', pykConcat(pykConcat(numbers4(x1, y1, ax, ay), ' '), numbers4(bx, by, x2, y2)), stroke, width, alpha, style);
}

function erase(c, x, y, w, h) {
  return tinyweb_external.draw_shape(c, 'erase', numbers4(x, y, w, h), '', '', 0.0, 1.0);
}

function line_style(c, cap, join, dash, gap, offset, dash2, gap2) {
  const first = dash <= 0.0 ? '' : gap <= 0.0 ? pykConcat(' ', floats2(dash, dash)) : pykConcat(' ', floats2(dash, gap));
  const second = dash <= 0.0 ? '' : dash2 <= 0.0 ? '' : gap2 <= 0.0 ? pykConcat(' ', floats2(dash2, dash2)) : pykConcat(' ', floats2(dash2, gap2));
  return tinyweb_external.set_state(c, 'line_style', pykConcat(pykConcat(cap, ' '), join), pykConcat(pykConcat(pykFloatStr(offset), first), second));
}

function clip_rect(c, x, y, w, h) {
  return tinyweb_external.set_state(c, 'clip', 'rect', pykConcat(numbers4(x, y, w, h), ' 0'));
}

function clip_circle(c, x, y, radius) {
  return tinyweb_external.set_state(c, 'clip', 'circle', numbers3(x, y, radius));
}

function clip_polygon(c, points) {
  return tinyweb_external.set_state(c, 'clip', 'polygon', points_text(points));
}

function text__default__fill() {
  return color__black;
}

function text__default__stroke() {
  return color__none;
}

function text__default__paint() {
  return Color__Plain(color__none);
}

function text__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function text2(c, x, y, words, fill, size, font, align, bold, alpha, baseline, stroke, width, paint, style) {
  return tinyweb_external.draw_text(c, x, y, words, fill_of(fill, paint, style), size, font, align, baseline, bold, stroke_of(stroke, style), width_of(width, style), alpha_of(alpha, style));
}

function measure_text(words, answer, size, font, bold) {
  return tinyweb_external.measure(words, size, font, bold, answer);
}

function translate(c, x, y) {
  return tinyweb_external.set_state(c, 'translate', '', floats2(x, y));
}

function rotate(c, angle) {
  return tinyweb_external.set_state(c, 'rotate', '', pykFloatStr(angle));
}

function scale(c, sx, sy) {
  return tinyweb_external.set_state(c, 'scale', '', floats2(sx, sy));
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

function shadow(c, shade, blur, dx, dy) {
  return tinyweb_external.set_state(c, 'shadow', color__drawn(shade), numbers3(blur, dx, dy));
}

function blend(c, mode) {
  const __subject = mode;
  if (__subject === 'normal' || __subject === 'add') {
    return tinyweb_external.set_state(c, 'blend', mode, '');
  } else {
    debug(pykConcat(pykConcat('tinyweb: there is no blending called "', mode), '"; the modes are normal and add'));
  }
}

function image(c, picture, x, y, w, h, alpha) {
  return tinyweb_external.draw_image(c, picture, x, y, w, h, alpha);
}

function button__default__on_click() {
  return nothing;
}

function button(title, on_click2) {
  return tinyweb_external.make_button(title, on_click2);
}

function slider__default__on_change() {
  return ignore;
}

function slider(low, high, value, on_change) {
  return tinyweb_external.make_slider(low, high, value, on_change);
}

function checkbox__default__on_change() {
  return ignore_bool;
}

function checkbox(title, checked, on_change) {
  return tinyweb_external.make_checkbox(title, checked, on_change);
}

function radio__default__on_pick() {
  return ignore_text;
}

function radio(group, title, chosen, on_pick) {
  return tinyweb_external.make_radio(group, title, chosen, on_pick);
}

function lines_of(options) {
  return joined_by(options, '\n');
}

function choice__default__on_change() {
  return ignore;
}

function choice(options, chosen, on_change) {
  return tinyweb_external.make_choice(lines_of(options), chosen, on_change);
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

function set_text(id, words) {
  return tinyweb_external.command('set_text', id, words, '', 1);
}

function show(id) {
  return tinyweb_external.command('visible', id, '', '1', 1);
}

function hide(id) {
  return tinyweb_external.command('visible', id, '', '0', 1);
}

function enable(id) {
  return tinyweb_external.command('enabled', id, '', '1', 1);
}

function disable(id) {
  return tinyweb_external.command('enabled', id, '', '0', 1);
}

function remove(id) {
  return tinyweb_external.command('remove', id, '', '', 0);
}

function value_of(id) {
  return tinyweb_external.report_text(pykConcat('value.', id));
}

function known_theme(name) {
  const __subject = name;
  if (__subject === 'light' || __subject === 'dark' || __subject === 'plain' || __subject === 'paper' || __subject === 'retro') {
    return true;
  } else {
    return false;
  }
}

function style_text(id, kind, property, value) {
  return value === '' ? [] : tinyweb_external.apply_style(id, kind, property, value);
}

function style_color(id, kind, property, c) {
  return color__is_theme(c) ? [] : tinyweb_external.apply_style(id, kind, property, color__css(c));
}

function style_border(id, kind, border, width) {
  if (color__is_theme(border)) {
    return width >= 0 ? tinyweb_external.apply_style(id, kind, 'border', pykConcat(pykFormat(width), 'px solid currentColor')) : [];
  } else if (border.a <= 0.0) {
    return tinyweb_external.apply_style(id, kind, 'border', 'none');
  } else {
    return tinyweb_external.apply_style(id, kind, 'border', pykConcat(pykConcat(pykFormat(width >= 0 ? width : 1), 'px solid '), color__css(border)));
  }
}

function style_pixels(id, kind, property, value) {
  return value < 0 ? [] : tinyweb_external.apply_style(id, kind, property, pykConcat(pykFormat(value), 'px'));
}

function theme(name) {
  if (known_theme(name)) {
    return tinyweb_external.apply_style('', 'theme', 'name', name);
  } else {
    debug(pykConcat(pykConcat('tinyweb: there is no theme called "', name), '"; the themes are light, dark, plain, paper and retro'));
  }
}

function page_style__default__background() {
  return color__theme;
}

function page_style__default__foreground() {
  return color__theme;
}

function page_style(background, foreground, font, size, padding, gap, align) {
  style_color('', 'page', 'background', background);
  style_color('', 'page', 'color', foreground);
  style_text('', 'page', 'font', font);
  style_pixels('', 'page', 'size', size);
  style_pixels('', 'page', 'padding', padding);
  style_pixels('', 'page', 'gap', gap);
  return style_text('', 'page', 'align', align);
}

function button_style__default__background() {
  return color__theme;
}

function button_style__default__foreground() {
  return color__theme;
}

function button_style__default__border() {
  return color__theme;
}

function button_style(background, foreground, border, border_width, radius, font, size, padding) {
  style_color('', 'button', 'background', background);
  style_color('', 'button', 'color', foreground);
  style_border('', 'button', border, border_width);
  style_pixels('', 'button', 'radius', radius);
  style_text('', 'button', 'font', font);
  style_pixels('', 'button', 'size', size);
  return style_pixels('', 'button', 'padding', padding);
}

function label_style__default__background() {
  return color__theme;
}

function label_style__default__foreground() {
  return color__theme;
}

function label_style__default__border() {
  return color__theme;
}

function label_style(background, foreground, border, border_width, radius, font, size, padding) {
  style_color('', 'label', 'background', background);
  style_color('', 'label', 'color', foreground);
  style_border('', 'label', border, border_width);
  style_pixels('', 'label', 'radius', radius);
  style_text('', 'label', 'font', font);
  style_pixels('', 'label', 'size', size);
  return style_pixels('', 'label', 'padding', padding);
}

function slider_style__default__accent() {
  return color__theme;
}

function slider_style__default__foreground() {
  return color__theme;
}

function slider_style(accent, width, foreground, font, size) {
  style_color('', 'slider', 'accent', accent);
  style_pixels('', 'slider', 'width', width);
  style_color('', 'slider', 'color', foreground);
  style_text('', 'slider', 'font', font);
  return style_pixels('', 'slider', 'size', size);
}

function canvas_style__default__border() {
  return color__theme;
}

function canvas_style(border, border_width, radius) {
  style_border('', 'canvas', border, border_width);
  return style_pixels('', 'canvas', 'radius', radius);
}

function set_style__default__background() {
  return color__theme;
}

function set_style__default__foreground() {
  return color__theme;
}

function set_style__default__border() {
  return color__theme;
}

function set_style__default__accent() {
  return color__theme;
}

function set_style(id, background, foreground, border, border_width, radius, font, size, padding, accent, width, weight, height) {
  style_color(id, 'element', 'background', background);
  style_color(id, 'element', 'color', foreground);
  style_border(id, 'element', border, border_width);
  style_pixels(id, 'element', 'radius', radius);
  style_text(id, 'element', 'font', font);
  style_pixels(id, 'element', 'size', size);
  style_pixels(id, 'element', 'padding', padding);
  style_color(id, 'element', 'accent', accent);
  style_pixels(id, 'element', 'width', width);
  if (weight >= 0) {
    style_text(id, 'element', 'weight', pykFormat(weight));
  }
  return style_pixels(id, 'element', 'height', height);
}

function on_click(c, f) {
  return tinyweb_external.on_mouse(c, f);
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

function track_mouse(c) {
  return tinyweb_external.watch_pointer(c, 'move', ignore2);
}

function mouse(c) {
  return Pointer(tinyweb_external.pointer(c, 'x'), tinyweb_external.pointer(c, 'y'), tinyweb_external.pointer(c, 'down') === 1);
}

function ignore2(x, y) {
  return [];
}

function after(seconds, f) {
  const id = tinyweb_external.fresh_id('timer');
  tinyweb_external.watch(id, 'timer', f);
  tinyweb_external.command('after', id, '', pykFloatStr(seconds), 0);
  return id;
}

function every(seconds, f) {
  const id = tinyweb_external.fresh_id('timer');
  tinyweb_external.watch(id, 'timer', f);
  tinyweb_external.command('every', id, '', pykFloatStr(seconds), 0);
  return id;
}

function cancel(timer) {
  return tinyweb_external.command('cancel', timer, '', '', 0);
}

function sound__settings(at, volume, rate, pan, voice) {
  const v = volume === 1.0 ? voice.volume : volume;
  const r = rate === 1.0 ? voice.rate : rate;
  const p = pan === 0.0 ? voice.pan : pan;
  return pykConcat(pykConcat(pykConcat(pykConcat(floats4(at, v, r, p), ' '), pykFormat(voice.channel)), ' '), bit(voice.reverse));
}

function play__default__voice() {
  return pykWithShape(Sound__Voice(1.0, 1.0, 0.0, 0, false, false), '(f,f,f,.,.,.)');
}

function play(sample, at, volume, rate, pan, voice) {
  return tinyweb_external.command('play', sample, '', sound__settings(at, volume, rate, pan, voice), 2);
}

function play_file(name) {
  return play(tinyweb_external.load_sample(name), 0.0, 1.0, 1.0, 0.0, play__default__voice());
}

function Sound__Voice(v0, v1, v2, v3, v4, v5) {
  return pykData('Sound__Voice', [v0, v1, v2, v3, v4, v5], ['volume', 'rate', 'pan', 'channel', 'looping', 'reverse']);
}

function sound__start__default__voice() {
  return pykWithShape(Sound__Voice(1.0, 1.0, 0.0, 0, false, false), '(f,f,f,.,.,.)');
}

function sound__start(sample, at, volume, rate, pan, looping, voice) {
  const id = tinyweb_external.fresh_id('voice');
  const looped = looping ? true : voice.looping;
  tinyweb_external.command('start', id, sample, pykConcat(pykConcat(sound__settings(at, volume, rate, pan, voice), ' '), bit(looped)), 2);
  return id;
}

function sound__stop(voice, at) {
  return tinyweb_external.command('stop', voice, '', pykFloatStr(at), 2);
}

function sound__fade(voice, volume, over) {
  return tinyweb_external.command('fade', voice, '', floats2(volume, over), 2);
}

function sound__stop_all() {
  return tinyweb_external.command('stop_all', '', '', '', 2);
}

function sound__master_volume(volume) {
  return tinyweb_external.command('master', '', '', pykFloatStr(volume), 1);
}

function sound__tone(frequency, at, duration, wave, volume, pan, channel) {
  return tinyweb_external.command('tone', '', wave, pykConcat(pykConcat(pykConcat(pykConcat(floats4(frequency, at, duration, volume), ' '), pykFloatStr(pan)), ' '), pykFormat(channel)), 2);
}

function sound__note(name) {
  const semitones = sound__semitones(name);
  return semitones < -1000 ? 0.0 : 440.0 * math2.pow(2.0, (semitones - 57) / 12.0);
}

function sound__rate_of(name, base) {
  const origin = sound__semitones(base);
  const target = sound__semitones(name);
  return origin < -1000 ? 1.0 : target < -1000 ? 1.0 : math2.pow(2.0, (target - origin) / 12.0);
}

function sound__semitones(name) {
  let __value = undefined;
  const __subject = strings.upper(strings.char_at(name, 0));
  if (__subject === 'C') {
    __value = 0;
  } else if (__subject === 'D') {
    __value = 2;
  } else if (__subject === 'E') {
    __value = 4;
  } else if (__subject === 'F') {
    __value = 5;
  } else if (__subject === 'G') {
    __value = 7;
  } else if (__subject === 'A') {
    __value = 9;
  } else if (__subject === 'B') {
    __value = 11;
  } else {
    __value = -10000;
  }
  const base = __value;
  let __value2 = undefined;
  const __subject2 = strings.char_at(name, 1);
  if (__subject2 === '#') {
    __value2 = 1;
  } else if (__subject2 === 'b') {
    __value2 = -1;
  } else {
    __value2 = 0;
  }
  const shift = __value2;
  const rest = strings.slice(name, shift === 0 ? 1 : 2, strings.length(name));
  const octave = rest === '' ? 4 : pykParseInt(rest);
  const valid = base < 0 ? false : rest === '' ? true : pykFormat(octave) === rest;
  return valid ? base + shift + octave * 12 : -10000;
}

function sound__tempo(bpm) {
  return tinyweb_external.command('tempo', '', '', pykFloatStr(bpm), 1);
}

function sound__swing(amount) {
  return tinyweb_external.command('swing', '', '', pykFloatStr(amount), 1);
}

function sound__on_beat(f, steps) {
  const id = tinyweb_external.fresh_id('beat');
  tinyweb_external.watch_step(id, 'beat', f);
  tinyweb_external.command('beat', id, '', pykFormat(steps), 0);
  return id;
}

function sound__beat() {
  return tinyweb_external.report_number('clock', 0);
}

function sound__latency() {
  return tinyweb_external.report_number('clock', 1);
}

function sound__pause() {
  return tinyweb_external.command('audio', '', 'pause', '', 2);
}

function sound__resume() {
  return tinyweb_external.command('audio', '', 'resume', '', 2);
}

function sound__channel_style(channel, volume, pan, echo, echo_time, feedback, reverb, low_pass) {
  return tinyweb_external.command('channel', pykFormat(channel), '', pykConcat(pykConcat(floats4(volume, pan, echo, echo_time), ' '), floats3(feedback, reverb, low_pass)), 1);
}

function sound__listen(bins, smoothing) {
  return tinyweb_external.command('listen', '', '', pykConcat(pykConcat(pykFormat(bins), ' '), pykFloatStr(smoothing)), 1);
}

function sound__level() {
  return tinyweb_external.report_number('level', 0);
}

function sound__band(k) {
  return tinyweb_external.report_number('band', k);
}

function sound__bands() {
  return tinyweb_external.report_count('band');
}

function sound__wave(k) {
  return tinyweb_external.report_number('wave', k);
}

function sound__render_wav__default__on_rendered() {
  return sound__ignore_rendered;
}

function sound__render_wav(seconds, f, name, on_rendered) {
  const id = tinyweb_external.fresh_id('render');
  tinyweb_external.watch_pair(id, 'rendered', on_rendered);
  tinyweb_external.command('render', id, name, pykFloatStr(seconds), 2);
  f();
  return tinyweb_external.command('render_end', id, '', '', 2);
}

function sound__ignore_rendered(took, peak) {
  return [];
}

function bitmap__bitmap__default__background() {
  return color__white;
}

function bitmap__bitmap(width, height, background) {
  return tinyweb_external.make_bitmap(width, height, color__to_hex(background));
}

function bitmap__set_pixel(b, x, y, pixel) {
  return tinyweb_external.set_pixel(b, x, y, color__to_hex(pixel));
}

function bitmap__get_pixel(b, x, y) {
  return color__hex(tinyweb_external.get_pixel(b, x, y));
}

function bitmap__fill_bitmap(b, fill) {
  return tinyweb_external.fill_bitmap(b, color__to_hex(fill));
}

function bitmap__show_bitmap(c, b, x, y, scale2) {
  return tinyweb_external.draw_bitmap(c, b, x, y, scale2);
}

function layout__row() {
  return tinyweb_external.row();
}

function layout__column() {
  return tinyweb_external.column();
}

function layout__inside(id) {
  return tinyweb_external.inside(id);
}

function layout__outside() {
  return tinyweb_external.outside();
}

function layout__text_area__default__on_change() {
  return ignore_text;
}

function layout__text_area(words, rows, columns, on_change) {
  const id = tinyweb_external.fresh_id('text');
  tinyweb_external.watch_text(id, 'change', pykConcat('value.', id), on_change);
  tinyweb_external.command('text_area', id, words, numbers2(rows, columns), 0);
  return id;
}

function net__save_canvas(c, name) {
  return tinyweb_external.command('save_canvas', c, name, '', 2);
}

function net__download(name, words) {
  return tinyweb_external.command('download', name, words, '', 2);
}

function net__file_button__default__on_load() {
  return ignore_text;
}

function net__file_button(title, on_load) {
  const id = tinyweb_external.fresh_id(title);
  tinyweb_external.watch_text(id, 'loaded', 'file', on_load);
  tinyweb_external.command('file_button', id, title, '', 0);
  return id;
}

function net__file_text() {
  return tinyweb_external.report_text('file.text');
}

function game__cursor(c, name) {
  return tinyweb_external.command('cursor', c, name, '', 1);
}

function Smooth__Point(v0, v1) {
  return pykData('Smooth__Point', [v0, v1], ['x', 'y']);
}

function smooth__width_of(width, style) {
  return width === 1.0 ? style.width : width;
}

function smooth__shape(c, kind, numbers, fill, stroke, width, alpha, paint, style) {
  return tinyweb_external.draw_shape(c, kind, numbers, fill_of(fill, paint, style), stroke_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style));
}

function smooth__stroked(c, kind, numbers, stroke, width, alpha, style) {
  return tinyweb_external.draw_shape(c, kind, numbers, '', line_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style));
}

function smooth__pairs(points) {
  return pykList(points.flatMap((__item) => {
  const p = __item;
  return [[p.x, p.y]];
}));
}

function smooth__circle__default__fill() {
  return color__black;
}

function smooth__circle__default__stroke() {
  return color__none;
}

function smooth__circle__default__paint() {
  return Color__Plain(color__none);
}

function smooth__circle__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function smooth__circle(c, x, y, radius, fill, stroke, width, alpha, paint, style) {
  return smooth__shape(c, 'circle', floats3(x, y, radius), fill, stroke, width, alpha, paint, style);
}

function smooth__circles__default__fill() {
  return color__black;
}

function smooth__circles__default__stroke() {
  return color__none;
}

function smooth__circles__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function smooth__circles(c, circles, fill, stroke, width, alpha, style) {
  return tinyweb_external.draw_triples(c, 'circles', circles, fill_of(fill, Color__Plain(color__none), style), stroke_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style));
}

function smooth__rect__default__fill() {
  return color__black;
}

function smooth__rect__default__stroke() {
  return color__none;
}

function smooth__rect__default__paint() {
  return Color__Plain(color__none);
}

function smooth__rect__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function smooth__rect(c, x, y, w, h, fill, stroke, width, alpha, paint, style, radius) {
  return smooth__shape(c, 'rect', pykConcat(pykConcat(floats4(x, y, w, h), ' '), pykFloatStr(radius)), fill, stroke, width, alpha, paint, style);
}

function smooth__ellipse__default__fill() {
  return color__black;
}

function smooth__ellipse__default__stroke() {
  return color__none;
}

function smooth__ellipse__default__paint() {
  return Color__Plain(color__none);
}

function smooth__ellipse__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function smooth__ellipse(c, x, y, rx, ry, fill, stroke, width, alpha, paint, style) {
  return smooth__shape(c, 'ellipse', floats4(x, y, rx, ry), fill, stroke, width, alpha, paint, style);
}

function smooth__arc__default__fill() {
  return color__black;
}

function smooth__arc__default__stroke() {
  return color__none;
}

function smooth__arc__default__paint() {
  return Color__Plain(color__none);
}

function smooth__arc__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function smooth__arc(c, x, y, radius, start, end, fill, stroke, width, alpha, paint, style) {
  return smooth__shape(c, 'arc', pykConcat(pykConcat(floats3(x, y, radius), ' '), floats2(start, end)), fill, stroke, width, alpha, paint, style);
}

function smooth__polygon__default__fill() {
  return color__black;
}

function smooth__polygon__default__stroke() {
  return color__none;
}

function smooth__polygon__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function smooth__polygon(c, points, fill, stroke, width, alpha, style) {
  return tinyweb_external.draw_pairs(c, 'polygon', smooth__pairs(points), fill_of(fill, Color__Plain(color__none), style), stroke_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style));
}

function smooth__line__default__stroke() {
  return color__black;
}

function smooth__line__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function smooth__line(c, x1, y1, x2, y2, stroke, width, alpha, style) {
  return smooth__stroked(c, 'line', floats4(x1, y1, x2, y2), stroke, width, alpha, style);
}

function smooth__lines__default__stroke() {
  return color__black;
}

function smooth__lines__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function smooth__lines(c, segments, stroke, width, alpha, style) {
  return tinyweb_external.draw_quads(c, 'lines', pykList(segments.flatMap((__item) => {
  const a = __item[0];
  const b = __item[1];
  return [[a.x, a.y, b.x, b.y]];
})), '', line_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style));
}

function smooth__path__default__stroke() {
  return color__black;
}

function smooth__path__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function smooth__path(c, points, stroke, width, alpha, style) {
  return tinyweb_external.draw_pairs(c, 'path', smooth__pairs(points), '', line_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style));
}

function smooth__curve__default__stroke() {
  return color__black;
}

function smooth__curve__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function smooth__curve(c, x1, y1, cx, cy, x2, y2, stroke, width, alpha, style) {
  return smooth__stroked(c, 'curve', pykConcat(pykConcat(floats2(x1, y1), ' '), floats4(cx, cy, x2, y2)), stroke, width, alpha, style);
}

function smooth__bezier__default__stroke() {
  return color__black;
}

function smooth__bezier__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function smooth__bezier(c, x1, y1, ax, ay, bx, by, x2, y2, stroke, width, alpha, style) {
  return smooth__stroked(c, 'bezier', pykConcat(pykConcat(floats4(x1, y1, ax, ay), ' '), floats4(bx, by, x2, y2)), stroke, width, alpha, style);
}

function smooth__text__default__fill() {
  return color__black;
}

function smooth__text__default__stroke() {
  return color__none;
}

function smooth__text__default__paint() {
  return Color__Plain(color__none);
}

function smooth__text__default__style() {
  return pykWithShape(Style(field__default__Style__fill(), field__default__Style__stroke(), 1, 1.0, field__default__Style__paint()), '(.,.,.,f,.)');
}

function smooth__text(c, x, y, words, fill, size, font, align, bold, alpha, baseline, stroke, width, paint, style) {
  return tinyweb_external.draw_text(c, x, y, words, fill_of(fill, paint, style), size, font, align, baseline, bold, stroke_of(stroke, style), smooth__width_of(width, style), alpha_of(alpha, style));
}

function smooth__clip_circle(c, x, y, radius) {
  return tinyweb_external.set_state(c, 'clip', 'circle', floats3(x, y, radius));
}

function smooth__clip_polygon(c, points) {
  return tinyweb_external.set_state(c, 'clip', 'polygon', float_points_text(points));
}

export { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop, web_init, Point, field__default__Style__fill, field__default__Style__stroke, field__default__Style__paint, Style, Pointer, clear__default__fill, clear, circle__default__fill, circle__default__stroke, circle__default__paint, circle__default__style, circle, rect__default__fill, rect__default__stroke, rect__default__paint, rect__default__style, rect, ellipse__default__fill, ellipse__default__stroke, ellipse__default__paint, ellipse__default__style, ellipse, arc__default__fill, arc__default__stroke, arc__default__paint, arc__default__style, arc, polygon__default__fill, polygon__default__stroke, polygon__default__paint, polygon__default__style, polygon, line__default__stroke, line__default__style, line, path__default__stroke, path__default__style, path, curve__default__stroke, curve__default__style, curve, lines__default__stroke, lines__default__style, lines, bezier__default__stroke, bezier__default__style, bezier, erase, line_style, clip_rect, clip_circle, clip_polygon, text__default__fill, text__default__stroke, text__default__paint, text__default__style, text2 as text, measure_text, translate, rotate, scale, push, pop, reset, shadow, blend, image, button__default__on_click, button, slider__default__on_change, slider, checkbox__default__on_change, checkbox, radio__default__on_pick, radio, choice__default__on_change, choice, text_input__default__on_enter, text_input, number_input__default__on_change, number_input, set_text, show, hide, enable, disable, remove, value_of, theme, page_style__default__background, page_style__default__foreground, page_style, button_style__default__background, button_style__default__foreground, button_style__default__border, button_style, label_style__default__background, label_style__default__foreground, label_style__default__border, label_style, slider_style__default__accent, slider_style__default__foreground, slider_style, canvas_style__default__border, canvas_style, set_style__default__background, set_style__default__foreground, set_style__default__border, set_style__default__accent, set_style, on_click, on_press, on_release, on_move, on_drag, track_mouse, mouse, after, every, cancel, play__default__voice, play, play_file, Sound__Voice, sound__start__default__voice, sound__start, sound__stop, sound__fade, sound__stop_all, sound__master_volume, sound__tone, sound__note, sound__rate_of, sound__tempo, sound__swing, sound__on_beat, sound__beat, sound__latency, sound__pause, sound__resume, sound__channel_style, sound__listen, sound__level, sound__band, sound__bands, sound__wave, sound__render_wav__default__on_rendered, sound__render_wav, bitmap__bitmap__default__background, bitmap__bitmap, bitmap__set_pixel, bitmap__get_pixel, bitmap__fill_bitmap, bitmap__show_bitmap, layout__row, layout__column, layout__inside, layout__outside, layout__text_area__default__on_change, layout__text_area, net__save_canvas, net__download, net__file_button__default__on_load, net__file_button, net__file_text, game__cursor, Smooth__Point, smooth__circle__default__fill, smooth__circle__default__stroke, smooth__circle__default__paint, smooth__circle__default__style, smooth__circle, smooth__circles__default__fill, smooth__circles__default__stroke, smooth__circles__default__style, smooth__circles, smooth__rect__default__fill, smooth__rect__default__stroke, smooth__rect__default__paint, smooth__rect__default__style, smooth__rect, smooth__ellipse__default__fill, smooth__ellipse__default__stroke, smooth__ellipse__default__paint, smooth__ellipse__default__style, smooth__ellipse, smooth__arc__default__fill, smooth__arc__default__stroke, smooth__arc__default__paint, smooth__arc__default__style, smooth__arc, smooth__polygon__default__fill, smooth__polygon__default__stroke, smooth__polygon__default__style, smooth__polygon, smooth__line__default__stroke, smooth__line__default__style, smooth__line, smooth__lines__default__stroke, smooth__lines__default__style, smooth__lines, smooth__path__default__stroke, smooth__path__default__style, smooth__path, smooth__curve__default__stroke, smooth__curve__default__style, smooth__curve, smooth__bezier__default__stroke, smooth__bezier__default__style, smooth__bezier, smooth__text__default__fill, smooth__text__default__stroke, smooth__text__default__paint, smooth__text__default__style, smooth__text, smooth__clip_circle, smooth__clip_polygon };
