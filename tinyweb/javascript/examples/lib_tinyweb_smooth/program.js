// Generated from lib_tinyweb_smooth.pyk by the Pyking compiler. Do not edit.
// Target: node24. Run with:  node <this file>

import { print } from './pyk-runtime.js';

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

// Pyking's `len`: a list's items, or a String's bytes in UTF-8.
function pykLen(value) {
  return Array.isArray(value) ? value.length : new TextEncoder().encode(value).length;
}

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { smooth__circle, smooth__circles, smooth__rect, smooth__ellipse, smooth__arc, smooth__polygon, smooth__line, smooth__lines, smooth__path, smooth__curve, smooth__bezier, smooth__text, smooth__clip_circle, smooth__clip_polygon, smooth__circle__default__color, smooth__circle__default__outline, smooth__circle__default__outline_width, smooth__circle__default__alpha, smooth__circles__default__color, smooth__circles__default__outline, smooth__circles__default__outline_width, smooth__circles__default__alpha, smooth__rect__default__color, smooth__rect__default__outline, smooth__rect__default__outline_width, smooth__rect__default__alpha, smooth__rect__default__radius, smooth__ellipse__default__color, smooth__ellipse__default__outline, smooth__ellipse__default__outline_width, smooth__ellipse__default__alpha, smooth__arc__default__color, smooth__arc__default__outline, smooth__arc__default__outline_width, smooth__arc__default__alpha, smooth__polygon__default__color, smooth__polygon__default__outline, smooth__polygon__default__outline_width, smooth__polygon__default__alpha, smooth__line__default__color, smooth__line__default__width, smooth__line__default__alpha, smooth__lines__default__color, smooth__lines__default__width, smooth__lines__default__alpha, smooth__path__default__color, smooth__path__default__width, smooth__path__default__alpha, smooth__curve__default__color, smooth__curve__default__width, smooth__curve__default__alpha, smooth__bezier__default__color, smooth__bezier__default__width, smooth__bezier__default__alpha, smooth__text__default__color, smooth__text__default__size, smooth__text__default__font, smooth__text__default__align, smooth__text__default__bold, smooth__text__default__alpha, smooth__text__default__baseline, smooth__text__default__outline, smooth__text__default__outline_width } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(200, 120);
smooth__polygon(c, pykList([[100.0, 10.5], [180.5, 90.5], [19.5, 90.5]]), 'orange', 'black', 0.5, smooth__polygon__default__alpha());
smooth__path(c, pykList([[10.0, 110.0], [60.5, 20.5], [110.25, 70.0], [190.0, 10.0]]), 'teal', 2.5, smooth__path__default__alpha());
const rays = pykList(pykRange(8).flatMap((__item) => {
  const i = __item;
  return [[100.0, 60.0, 100.0 + 45.0 * (i - Math.trunc(i / 3) * 3), 5.0 * i]];
}));
smooth__lines(c, rays, 'crimson', 0.8, 0.5);
tw.lines(c, pykList(pykRange(0, 200, 40).flatMap((__item) => {
  const x = __item;
  return [[x, 0, x, 120]];
})), '#cccccc', tw.lines__default__width(), tw.lines__default__alpha());
tw.push(c);
smooth__clip_polygon(c, pykList([[100.0, 5.5], [190.5, 115.0], [9.5, 115.0]]));
tw.rect(c, 0, 60, 200, 60, 'gold', tw.rect__default__outline(), tw.rect__default__outline_width(), 0.4, tw.rect__default__radius());
tw.pop(c);
tw.push(c);
tw.clip_polygon(c, pykList([[0, 0], [60, 0], [0, 60]]));
tw.rect(c, 0, 0, 60, 60, 'navy', tw.rect__default__outline(), tw.rect__default__outline_width(), tw.rect__default__alpha(), tw.rect__default__radius());
tw.pop(c);
const many = pykList(pykRange(300).flatMap((__item) => {
  const i = __item;
  return [[i, 0.0, i + 0.5, 120.0]];
}));
smooth__lines(c, many, 'black', 0.25, 0.1);
print('drew', pykLen(many), 'lines in one go');
