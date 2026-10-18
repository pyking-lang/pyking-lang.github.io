// Generated from lib_tinyweb_widgets.pyk by the Pyking compiler. Do not edit.
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
const shown = tw_external.label('nothing yet');

function trails(on) {
  return tw_external.set_label(shown, on ? 'trails on' : 'trails off');
}

function mode(title) {
  return tw_external.set_label(shown, pykConcat('mode: ', title));
}

function entered(name) {
  return tw_external.set_label(shown, pykConcat('hello, ', name));
}

function balls(n) {
  return tw_external.set_label(shown, pykConcat(pykFormat(n), ' balls'));
}

const box = tw.checkbox('Trails', tw.checkbox__default__checked(), trails);
tw.checkbox('Slow frames', true, tw.checkbox__default__on_change());
tw.radio('mode', 'time-based', tw.radio__default__chosen(), mode);
const frame_based = tw.radio('mode', 'frame-based', tw.radio__default__chosen(), mode);
tw.radio('speed', 'slow', tw.radio__default__chosen(), tw.radio__default__on_pick());
tw.radio('speed', 'fast', true, tw.radio__default__on_pick());
tw.text_input('your name', entered);
tw.text_input(tw.text_input__default__placeholder(), tw.text_input__default__on_enter());
const count = tw.number_input(1, 20, 3, balls);
const speed = tw.slider(0, 10, 5, tw.slider__default__on_change());
tw_external.set_checked(box, true);
tw_external.set_checked(frame_based, true);
tw_external.set_value(count, 5);
tw_external.set_value(speed, 8);
print(frame_based);
