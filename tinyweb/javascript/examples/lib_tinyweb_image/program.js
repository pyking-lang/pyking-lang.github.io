// Generated from lib_tinyweb_image.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print, pykTrunc } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(200, 100);
const ball = tw_external.load_image('ball.png');
const star = tw_external.load_image('star.png');
const again = tw_external.load_image('ball.png');
print(again);

function draw(t) {
  tw.clear(c, color__hex(2105408));
  tw.image(c, ball, pykTrunc(t * 100.0), 20, 40, 40, 1.0);
  return tw.image(c, star, 140, 20, 50, 50, 0.5);
}

tw_external.on_frame(draw);
