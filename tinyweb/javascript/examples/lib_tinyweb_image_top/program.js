// Generated from lib_tinyweb_image_top.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(200, 100);
const tile = tw_external.load_image('tile.png');
const star = tw_external.load_image('star.png');
const missing = tw_external.load_image('no_such_picture.png');
tw.image(c, tile, 0, 0, 200, 100, 1.0);
tw.rect(c, 20, 20, 60, 30, color__hex(2113664), tw.rect__default__stroke(), 1, 1.0, tw.rect__default__paint(), tw.rect__default__style(), 0);
tw.image(c, star, 100, 10, 50, 50, 0.5);
tw.image(c, missing, 10, 60, 30, 30, 1.0);
tw.circle(c, 170, 70, 15, color__hex(12595248), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style());
print('drawn');
