// Generated from lib_tinyweb_bitmap.pyk by the Pyking compiler. Do not edit.
// Target: node24. Run with:  node <this file>

import { print, pykTrunc } from './pyk-runtime.js';

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

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
tw.web_init(0);
const c = tw_external.canvas(160, 100);
const b = tw_external.bitmap(16, 10);
print('a new bitmap is black:', tw_external.get_pixel(b, 3, 3));
for (const y of pykRange(10)) {
  for (const x of pykRange(16)) {
    tw_external.set_pixel(b, x, y, tw.pixel_color(x * 16, y * 25, 128));
  }
}
tw.show_bitmap(c, b, tw.show_bitmap__default__x(), tw.show_bitmap__default__y(), 10.0);
const orange = tw.pixel_color(255, 136, 0);
print('orange is', orange, tw.red(orange), tw.green(orange), tw.blue(orange));
print('clamped:', tw.pixel_color(300, -5, 70));
tw_external.set_pixel(b, 4, 2, orange);
tw_external.set_pixel(b, 7, 5, orange);
tw_external.set_pixel(b, 40, 2, orange);
print('pixel (4, 2):', tw_external.get_pixel(b, 4, 2), 'outside:', tw_external.get_pixel(b, -1, 0));
tw.show_bitmap(c, b, 0, 0, 10.0);
tw.show_bitmap(c, b, 5, 5, tw.show_bitmap__default__scale());
const small = tw_external.bitmap(4, 4);
tw_external.fill_bitmap(small, tw.pixel_color(0, 0, 255));
print('filled:', tw.blue(tw_external.get_pixel(small, 3, 3)));
tw.show_bitmap(c, small, 120, 60, 0.5);

function frame(t) {
  tw_external.set_pixel(small, 1, 1, tw.pixel_color(pykTrunc(t * 100.0), 0, 0));
  return tw.show_bitmap(c, small, 120, 60, 2.0);
}

tw_external.on_frame(frame);
