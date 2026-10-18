// Generated from lib_tinyweb_image.pyk by the Pyking compiler. Do not edit.
// Target: node24. Run with:  node <this file>

import { print, pykTrunc } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
tw.web_init(0);
const c = tw_external.canvas(200, 100);
const ball = tw_external.load_image('ball.png');
const star = tw_external.load_image('star.png');
const again = tw_external.load_image('ball.png');
print(again);

function draw(t) {
  tw.clear(c, '#202040');
  tw.image(c, ball, pykTrunc(t * 100.0), 20, 40, 40, tw.image__default__alpha());
  return tw.image(c, star, 140, 20, 50, 50, 0.5);
}

tw_external.on_frame(draw);
