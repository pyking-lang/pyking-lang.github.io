// Generated from lib_tinyweb_sound_graphics1.pyk by the Pyking compiler. Do not edit.
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
tw.web_init(0);
const kick = tw_external.load_sample('kick1.wav');
const snare = tw_external.load_sample('snare1.wav');
const canvas = tw_external.canvas(400, 200);
tw.circle(canvas, 100, 50, 30, '#ff0000', tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha());
tw.circle(canvas, 100, 50, 20, tw.circle__default__color(), tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha());
let presses = 0;

function play_kick() {
  return tw.play(kick, tw.play__default__at(), tw.play__default__volume(), tw.play__default__rate());
}

function play_sound() {
  presses = presses + 1;
  print(pykConcat('snare, press ', pykFormat(presses)));
  return tw.play(snare, tw.play__default__at(), 0.5, tw.play__default__rate());
}

tw.button('Play kick', play_kick);
tw.button('Play snare', play_sound);
tw.button('Does nothing', tw.button__default__on_click());
print('built the page');
tw_external.splash();
