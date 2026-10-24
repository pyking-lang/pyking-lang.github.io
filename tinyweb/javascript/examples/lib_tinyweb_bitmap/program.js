// Generated from lib_tinyweb_bitmap.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print, pykFormat, pykFloatStr, pykTrunc } from './pyk-runtime.js';

// A Pyking list is a JavaScript array with a marker on it: a tuple
// is an array too, and the two print differently. A property rather
// than a class, so that a formatter in another module can read it.
function pykList(items) {
  items.pykList = true;
  return items;
}

// Pyking's `range`: a list of Ints, as builtin.ml says.
function pykRange(a, b, c) {
  const [start, stop, step] = b === undefined ? [0, a, 1] : [a, b, c === undefined ? 1 : c];
  if (step === 0) throw new Error("'range' step must not be zero");
  const items = [];
  for (let n = start; step > 0 ? n < stop : n > stop; n += step) items.push(n);
  return pykList(items);
}

// Pyking's `++` joins two strings or two lists. A list is an array
// here and JavaScript's `+` would stringify one, so which is meant
// is decided by looking -- this backend infers no types.
function pykConcat(a, b) {
  return Array.isArray(a) ? pykList([...a, ...b]) : a + b;
}

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { bitmap__bitmap, bitmap__set_pixel, bitmap__get_pixel, bitmap__fill_bitmap, bitmap__show_bitmap, bitmap__bitmap__default__background } from './tinyweb.js';
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(160, 100);

function show(p) {
  return pykConcat(pykConcat(pykConcat(pykConcat(pykFormat(p.r), ' '), pykFormat(p.g)), ' '), pykFormat(p.b));
}

const b = bitmap__bitmap(16, 10, bitmap__bitmap__default__background());
print('a new bitmap is white:', show(bitmap__get_pixel(b, 3, 3)));
print('or its background:', show(bitmap__get_pixel(bitmap__bitmap(2, 2, color__green), 1, 1)));
for (const y of pykRange(10)) {
  for (const x of pykRange(16)) {
    bitmap__set_pixel(b, x, y, color__rgb(x * 16, y * 25, 128));
  }
}
bitmap__show_bitmap(c, b, 0, 0, 10.0);
const orange = color__rgb(255, 136, 0);
bitmap__set_pixel(b, 4, 2, orange);
bitmap__set_pixel(b, 7, 5, orange);
bitmap__set_pixel(b, 40, 2, orange);
print('pixel (4, 2):', show(bitmap__get_pixel(b, 4, 2)), 'outside:', show(bitmap__get_pixel(b, -1, 0)), pykFloatStr(bitmap__get_pixel(b, -1, 0).a));
bitmap__show_bitmap(c, b, 0, 0, 10.0);
bitmap__show_bitmap(c, b, 5, 5, 1.0);
const small = bitmap__bitmap(4, 4, bitmap__bitmap__default__background());
bitmap__fill_bitmap(small, color__blue);
print('filled:', bitmap__get_pixel(small, 3, 3).b);

function frame(t) {
  bitmap__set_pixel(small, 1, 1, color__rgb(pykTrunc(t * 100.0), 0, 0));
  return bitmap__show_bitmap(c, small, 120, 60, 2.0);
}

bitmap__show_bitmap(c, small, 120, 60, 0.5);
tw_external.on_frame(frame);
