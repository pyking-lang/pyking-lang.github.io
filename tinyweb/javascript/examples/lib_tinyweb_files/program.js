// Generated from lib_tinyweb_files.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print } from './pyk-runtime.js';

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
import { game__cursor } from './tinyweb.js';
import { net__save_canvas, net__download, net__file_button, net__file_text, net__file_button__default__on_load } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(100, 100);
tw.circle(c, 50, 50, 40, color__green, tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style());
game__cursor(c, 'crosshair');
game__cursor(c, 'none');
net__save_canvas(c, 'canvas.png');
net__save_canvas(c, 'circle.png');
net__download('notes.txt', 'line one\nline "two"');
print('before:', pykConcat(pykConcat('[', net__file_text()), ']'));

function loaded(name) {
  print('loaded', name, 'holding', net__file_text());
}

const picker = net__file_button('Open', loaded);
print(picker);
