// Generated from lib_tinyweb_input.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

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
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(300, 200);
tw.rect(c, 0, 0, 300, 200, color__hex(15658734), tw.rect__default__stroke(), 1, 1.0, tw.rect__default__paint(), tw.rect__default__style(), 0);
tw.line(c, 0, 0, 300, 200, tw.line__default__stroke(), 1, 1.0, tw.line__default__style());
tw.line(c, 0, 200, 300, 0, color__red, 3, 1.0, tw.line__default__style());
tw.text(c, 10, 10, 'click "me"', tw.text__default__fill(), 20, '', 'left', false, 1.0, 'top', tw.text__default__stroke(), 1, tw.text__default__paint(), tw.text__default__style());
const status = tw_external.label('nothing yet');

function clicked(x, y) {
  tw.set_text(status, pykConcat(pykConcat(pykConcat('clicked at ', pykFormat(x)), ', '), pykFormat(y)));
  return tw.circle(c, x, y, 5, color__blue, tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style());
}

function pressed(key) {
  print(pykConcat(pykConcat('key [', key), ']'));
  if (key === 'Enter') {
    tw.play_file('snare1.wav');
  }
}

function moved(value) {
  return tw.set_text(status, pykConcat('slider at ', pykFormat(value)));
}

tw.on_click(c, clicked);
tw_external.on_key(pressed);
tw.slider(0, 10, 5, moved);
tw.slider(1, 3, 2, tw.slider__default__on_change());
tw_external.splash();
