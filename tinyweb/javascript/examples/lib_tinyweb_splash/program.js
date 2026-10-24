// Generated from lib_tinyweb_splash.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
tw.web_init(0);
tw_external.set_splash('Click for drums');
const c = tw_external.canvas(200, 100);
tw.clear(c, color__hex(2105376));
const kick = tw_external.load_sample('kick1.wav');
tw.play(kick, 0.25, 1.0, 1.0, 0.0, tw.play__default__voice());
tw.circle(c, 100, 50, 30, color__hex(16763904), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style());

function again() {
  tw.play(kick, 0.0, 1.0, 1.0, 0.0, tw.play__default__voice());
  print('kick again');
}

tw.button('Again', again);
print('built the page');
tw_external.splash();
