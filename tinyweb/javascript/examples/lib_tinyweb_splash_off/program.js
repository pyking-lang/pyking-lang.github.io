// Generated from lib_tinyweb_splash_off.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
tw.web_init(0);
tw_external.set_splash('');
const snare = tw_external.load_sample('snare1.wav');

function hit() {
  tw.play(snare, 0.0, 0.5, 1.0, 0.0, tw.play__default__voice());
  print('hit');
}

tw.button('Hit', hit);
tw_external.splash();
