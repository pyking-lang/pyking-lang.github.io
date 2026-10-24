// Generated from lib_tinyweb_smooth.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

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

// Which fields of a datatype's value are Floats, which only the
// compiler knows: a JavaScript number cannot say.
function pykWithShape(value, shape) {
  value.pykShape = shape;
  return value;
}

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
import { Smooth__Point, smooth__circle, smooth__circles, smooth__rect, smooth__ellipse, smooth__arc, smooth__polygon, smooth__line, smooth__lines, smooth__path, smooth__curve, smooth__bezier, smooth__text, smooth__clip_circle, smooth__clip_polygon, smooth__circle__default__fill, smooth__circle__default__stroke, smooth__circle__default__paint, smooth__circle__default__style, smooth__circles__default__fill, smooth__circles__default__stroke, smooth__circles__default__style, smooth__rect__default__fill, smooth__rect__default__stroke, smooth__rect__default__paint, smooth__rect__default__style, smooth__ellipse__default__fill, smooth__ellipse__default__stroke, smooth__ellipse__default__paint, smooth__ellipse__default__style, smooth__arc__default__fill, smooth__arc__default__stroke, smooth__arc__default__paint, smooth__arc__default__style, smooth__polygon__default__fill, smooth__polygon__default__stroke, smooth__polygon__default__style, smooth__line__default__stroke, smooth__line__default__style, smooth__lines__default__stroke, smooth__lines__default__style, smooth__path__default__stroke, smooth__path__default__style, smooth__curve__default__stroke, smooth__curve__default__style, smooth__bezier__default__stroke, smooth__bezier__default__style, smooth__text__default__fill, smooth__text__default__stroke, smooth__text__default__paint, smooth__text__default__style } from './tinyweb.js';
import { Point } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(200, 120);
smooth__polygon(c, pykList([pykWithShape(Smooth__Point(100.0, 10.5), '(f,f)'), pykWithShape(Smooth__Point(180.5, 90.5), '(f,f)'), pykWithShape(Smooth__Point(19.5, 90.5), '(f,f)')]), color__orange, color__black, 0.5, 1.0, smooth__polygon__default__style());
smooth__path(c, pykList([pykWithShape(Smooth__Point(10.0, 110.0), '(f,f)'), pykWithShape(Smooth__Point(60.5, 20.5), '(f,f)'), pykWithShape(Smooth__Point(110.25, 70.0), '(f,f)'), pykWithShape(Smooth__Point(190.0, 10.0), '(f,f)')]), color__teal, 2.5, 1.0, smooth__path__default__style());
const rays = pykList(pykRange(8).flatMap((__item) => {
  const i = __item;
  return [[pykWithShape(Smooth__Point(100.0, 60.0), '(f,f)'), pykWithShape(Smooth__Point(100.0 + 45.0 * (i - Math.trunc(i / 3) * 3), 5.0 * i), '(f,f)')]];
}));
smooth__lines(c, rays, color__hex(14423100), 0.8, 0.5, smooth__lines__default__style());
tw.lines(c, pykList(pykRange(0, 200, 40).flatMap((__item) => {
  const x = __item;
  return [[Point(x, 0), Point(x, 120)]];
})), color__hex(13421772), 1, 1.0, tw.lines__default__style());
smooth__circles(c, pykList([[10.5, 10.5, 3.0], [20.0, 10.0, 2.5]]), color__navy, smooth__circles__default__stroke(), 1.0, 1.0, smooth__circles__default__style());
tw.push(c);
smooth__clip_polygon(c, pykList([pykWithShape(Smooth__Point(100.0, 5.5), '(f,f)'), pykWithShape(Smooth__Point(190.5, 115.0), '(f,f)'), pykWithShape(Smooth__Point(9.5, 115.0), '(f,f)')]));
tw.rect(c, 0, 60, 200, 60, color__hex(16766720), tw.rect__default__stroke(), 1, 0.4, tw.rect__default__paint(), tw.rect__default__style(), 0);
tw.pop(c);
tw.push(c);
tw.clip_polygon(c, pykList([Point(0, 0), Point(60, 0), Point(0, 60)]));
tw.rect(c, 0, 0, 60, 60, color__navy, tw.rect__default__stroke(), 1, 1.0, tw.rect__default__paint(), tw.rect__default__style(), 0);
tw.pop(c);
const many = pykList(pykRange(300).flatMap((__item) => {
  const i = __item;
  return [[pykWithShape(Smooth__Point(i, 0.0), '(f,f)'), pykWithShape(Smooth__Point(i + 0.5, 120.0), '(f,f)')]];
}));
smooth__lines(c, many, color__black, 0.25, 0.1, smooth__lines__default__style());
print('drew', pykLen(many), 'lines in one go');
