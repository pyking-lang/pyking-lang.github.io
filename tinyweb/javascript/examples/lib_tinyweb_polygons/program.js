// Generated from lib_tinyweb_polygons.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print } from './pyk-runtime.js';

// A Pyking list is a JavaScript array with a marker on it: a tuple
// is an array too, and the two print differently. A property rather
// than a class, so that a formatter in another module can read it.
function pykList(items) {
  items.pykList = true;
  return items;
}

// Pyking's `len`: a list's items, or a String's code points.
function pykLen(value) {
  if (Array.isArray(value)) return value.length;
  let n = 0;
  for (const _ of value) n++;
  return n;
}

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
import { color__palette as palette } from './tinyweb.js';
import { Point } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(200, 200);
const ocean = palette('ocean');
print(pykLen(ocean));
tw.polygon(c, pykList([Point(100, 10), Point(130, 90), Point(70, 90)]), color__orange, color__black, 1, 1.0, tw.polygon__default__paint(), tw.polygon__default__style());
tw.path(c, pykList([Point(10, 190), Point(60, 120), Point(110, 170), Point(190, 110)]), color__teal, 3, 1.0, tw.path__default__style());
tw.polygon(c, pykList([]), color__red, tw.polygon__default__stroke(), 1, 1.0, tw.polygon__default__paint(), tw.polygon__default__style());
tw.lines(c, pykList([[Point(0, 0), Point(20, 20)], [Point(20, 0), Point(0, 20)]]), color__navy, 1, 1.0, tw.lines__default__style());
print(pykLen(palette('nothing')));
