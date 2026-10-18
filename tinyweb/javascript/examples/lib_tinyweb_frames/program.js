// Generated from lib_tinyweb_frames.pyk by the Pyking compiler. Do not edit.
// Target: node24. Run with:  node <this file>

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
tw.web_init(0);
const c = tw_external.canvas(200, 100);
const kick = tw_external.load_sample('kick1.wav');
const beat = 0.5;
let next_beat = 0.0;

function draw(t) {
  tw.clear(c, '#111111');
  tw.circle(c, pykTrunc(t * 100.0), 50, 10, '#ffcc00', tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha());
  if (t >= next_beat) {
    print(pykConcat(pykConcat(pykConcat('beat scheduled at ', pykFloatStr(next_beat + beat)), ', drawn at '), pykFloatStr(t)));
    tw.play(kick, next_beat + beat, tw.play__default__volume(), tw.play__default__rate());
    next_beat = next_beat + beat;
  }
}

tw_external.on_frame(draw);
print(pykFloatStr(tw_external.time()));
tw_external.splash();
