// Generated from lib_tinyweb_transform.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import * as math2 from './math.js';
import * as math2_external from './math_external.js';
import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(200, 200);

function draw(t) {
  tw.clear(c, color__black);
  tw.push(c);
  tw.translate(c, 100.0, 100.0);
  tw.rotate(c, t * math2.pi / 2.0);
  tw.rect(c, -20, -20, 40, 40, color__hex(14423100), tw.rect__default__stroke(), 1, 1.0, tw.rect__default__paint(), tw.rect__default__style(), 0);
  tw.push(c);
  tw.scale(c, 0.5, 2.0);
  tw.circle(c, 60, 0, 10, color__white, tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style());
  tw.pop(c);
  tw.pop(c);
  tw.shadow(c, color__white, 12, 0, 0);
  tw.circle(c, 30, 30, 10, color__hex(16766720), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style());
  tw.shadow(c, color__none, 10, 0, 0);
  tw.blend(c, 'add');
  tw.circle(c, 160, 160, 20, color__hex(8388608), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style());
  tw.circle(c, 175, 160, 20, color__hex(128), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style());
  tw.blend(c, 'normal');
  tw.blend(c, 'multiply');
  return tw.reset(c);
}

tw_external.on_frame(draw);
