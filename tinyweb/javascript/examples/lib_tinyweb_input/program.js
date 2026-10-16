// Generated from lib_tinyweb_input.pyk by the Pyking compiler. Do not edit.
// Target: node24. Run with:  node <this file>

import { print, pykFormat } from './pyk-runtime.js';

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
tw_external.web_init(0);
const c = tw_external.canvas(300, 200);
tw.rect(c, 0, 0, 300, 200, '#eeeeee');
tw.line(c, 0, 0, 300, 200, tw.line__default__color(), tw.line__default__width());
tw.line(c, 0, 200, 300, 0, 'red', 3);
tw.text(c, 10, 10, 'click "me"', tw.text__default__color(), 20);
const status = tw_external.label('nothing yet');

function clicked(x, y) {
  tw_external.set_label(status, pykConcat(pykConcat(pykConcat('clicked at ', pykFormat(x)), ', '), pykFormat(y)));
  return tw.circle(c, x, y, 5, 'blue');
}

function pressed(key) {
  print(pykConcat(pykConcat('key [', key), ']'));
  if (key === 'Enter') {
    tw.play_file('snare1.wav');
  }
}

function moved(value) {
  return tw_external.set_label(status, pykConcat('slider at ', pykFormat(value)));
}

tw_external.on_mouse(c, clicked);
tw_external.on_key(pressed);
tw.slider(0, 10, 5, moved);
tw.slider(1, 3, 2, tw.slider__default__on_change());
