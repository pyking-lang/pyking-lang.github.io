// Generated from lib_tinyweb_splash.pyk by the Pyking compiler. Do not edit.
// Target: node24. Run with:  node <this file>

import { print } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
tw.web_init(0);
tw_external.set_splash('Click for drums');
const c = tw_external.canvas(200, 100);
tw.clear(c, '#202020');
const kick = tw_external.load_sample('kick1.wav');
tw.play(kick, 0.25, tw.play__default__volume(), tw.play__default__rate());
tw.circle(c, 100, 50, 30, '#ffcc00', tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha());

function again() {
  tw.play(kick, tw.play__default__at(), tw.play__default__volume(), tw.play__default__rate());
  print('kick again');
}

tw.button('Again', again);
print('built the page');
tw_external.splash();
