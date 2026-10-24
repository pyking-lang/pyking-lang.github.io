// Generated from lib_tinyweb_frames.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print, pykFloatStr, pykTrunc } from './pyk-runtime.js';

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

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(200, 100);
const kick = tw_external.load_sample('kick1.wav');
const beat = 0.5;
let next_beat = 0.0;

function draw(t) {
  tw.clear(c, color__hex(1118481));
  tw.circle(c, pykTrunc(t * 100.0), 50, 10, color__hex(16763904), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style());
  if (t >= next_beat) {
    print(pykConcat(pykConcat(pykConcat('beat scheduled at ', pykFloatStr(next_beat + beat)), ', drawn at '), pykFloatStr(t)));
    tw.play(kick, next_beat + beat, 1.0, 1.0, 0.0, tw.play__default__voice());
    next_beat = next_beat + beat;
  }
}

tw_external.on_frame(draw);
print(pykFloatStr(tw_external.time()));
tw_external.splash();
