// Generated from lib_tinyweb_shapes.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print, pykFormat, pykFloatStr } from './pyk-runtime.js';

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

import * as math2 from './math.js';
import * as math2_external from './math_external.js';
import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(300, 200);
tw.clear(c, color__rgb(17, 17, 17));
const gold = color__hex(16766720);
tw.circle(c, 50, 50, 30, gold, color__white, 3, 1.0, tw.circle__default__paint(), tw.circle__default__style());
tw.circle(c, 80, 50, 30, color__rgba(0, 128, 255, 0.5), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style());
tw.rect(c, 120, 20, 60, 40, color__none, color__hsl(120.0, 100.0, 50.0), 1, 1.0, tw.rect__default__paint(), tw.rect__default__style(), 8);
tw.ellipse(c, 220, 40, 50, 20, color__hex(14315734), tw.ellipse__default__stroke(), 1, 0.75, tw.ellipse__default__paint(), tw.ellipse__default__style());
tw.arc(c, 50, 140, 40, math2.pi / 6.0, 11.0 * math2.pi / 6.0, color__yellow, tw.arc__default__stroke(), 1, 1.0, tw.arc__default__paint(), tw.arc__default__style());
tw.arc(c, 150, 140, 40, math2.pi, 2.0 * math2.pi, color__none, color__red, 4, 1.0, tw.arc__default__paint(), tw.arc__default__style());
tw.line(c, 200, 100, 290, 190, color__cyan, 2, 1.0, tw.line__default__style());
tw.curve(c, 200, 190, 245, 60, 290, 190, color__white, 2, 0.5, tw.curve__default__style());
tw.text(c, 150, 180, 'Step 1', color__white, 18, 'serif', 'center', true, 1.0, 'top', tw.text__default__stroke(), 1, tw.text__default__paint(), tw.text__default__style());

function show(c2) {
  return pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykConcat(pykFormat(c2.r), ' '), pykFormat(c2.g)), ' '), pykFormat(c2.b)), ' '), pykFloatStr(c2.a));
}

print(show(color__rgb(255, 136, 0)));
print(show(color__rgb(-5, 300, 16)));
print(show(color__hsl(200.0, 50.0, 25.0)));
print(color__to_hex(color__hex(16746496)), color__to_hex(color__rgb(1, 2, 3)));
print(color__same(color__hex(65535), color__cyan), color__same(color__red, color__blue));
print(show(color__mix(color__black, color__white, 0.5)));
print(show(color__with_alpha(color__red, 0.25)));
print(show(color__rgba(10, 20, 30, 0.5)), show(color__none));
