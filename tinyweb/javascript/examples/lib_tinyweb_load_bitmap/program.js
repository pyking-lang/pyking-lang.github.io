// Generated from lib_tinyweb_load_bitmap.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print, pykFormat, pykFloatStr } from './pyk-runtime.js';

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
import { bitmap__bitmap, bitmap__set_pixel, bitmap__get_pixel, bitmap__fill_bitmap, bitmap__show_bitmap, bitmap__load_bitmap, bitmap__size, bitmap__bitmap__default__background } from './tinyweb.js';
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(40, 40);

function show(p) {
  return pykConcat(pykConcat(pykConcat(pykConcat(pykFormat(p.r), ' '), pykFormat(p.g)), ' '), pykFormat(p.b));
}

const made = bitmap__bitmap(5, 3, bitmap__bitmap__default__background());
print('made:', bitmap__size(made), 'not a bitmap:', bitmap__size('nothing'));

function loaded(b) {
  const [w, h] = bitmap__size(b);
  print('loaded', b, 'of', w, 'by', h);
  for (const y of pykRange(h)) {
    for (const x of pykRange(w)) {
      print(' ', x, y, show(bitmap__get_pixel(b, x, y)), pykFloatStr(bitmap__get_pixel(b, x, y).a));
    }
  }
  bitmap__set_pixel(b, 1, 1, color__black);
  return bitmap__show_bitmap(c, b, 0, 0, 10.0);
}

function broken(b) {
  print('never called for', b);
}

bitmap__load_bitmap('pic.png', loaded);
bitmap__load_bitmap('broken.png', broken);
print('asked for both');
