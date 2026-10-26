// Generated from lib_tinyweb_sdelay.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print, pykFloatStr } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(200, 40);
const piano = tw_external.load_sample('piano_c1.wav');
let round = 0;
while (true) {
  tw.play(piano, 0.0, 1.0, 1.0, 0.0, tw.play__default__voice());
  print('round', round, 'at', pykFloatStr(tw_external.time()));
  tw.circle(c, 10 + 20 * round, 20, 8, color__orange, tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style());
  round = round + 1;
  if (round === 8) {
    break;
  }
  tw_external.sdelay(round === 4 ? 0.5 : 0.25);
}
tw_external.splash();
