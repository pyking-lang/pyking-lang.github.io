// Generated from lib_tinyweb_shapes.pyk by the Pyking compiler. Do not edit.
// Target: node24. Run with:  node <this file>

import { print } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { colors__rgb, colors__rgba, colors__hsl, colors__palette, colors__linear_gradient, colors__radial_gradient, colors__conic_gradient, colors__stop } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(300, 200);
tw.clear(c, colors__rgb(17, 17, 17));
tw.circle(c, 50, 50, 30, 'gold', 'white', 3, tw.circle__default__alpha());
tw.circle(c, 80, 50, 30, colors__rgba(0, 128, 255, 0.5), tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha());
tw.rect(c, 120, 20, 60, 40, '', colors__hsl(120, 100, 50), tw.rect__default__outline_width(), tw.rect__default__alpha(), 8);
tw.ellipse(c, 220, 40, 50, 20, 'orchid', tw.ellipse__default__outline(), tw.ellipse__default__outline_width(), 0.75);
tw.arc(c, 50, 140, 40, 30.0, 330.0, 'yellow', tw.arc__default__outline(), tw.arc__default__outline_width(), tw.arc__default__alpha());
tw.arc(c, 150, 140, 40, 180.0, 360.0, '', 'red', 4, tw.arc__default__alpha());
tw.line(c, 200, 100, 290, 190, 'cyan', 2, tw.line__default__alpha());
tw.curve(c, 200, 190, 245, 60, 290, 190, 'white', 2, 0.5);
tw.text(c, 150, 180, 'Step 1', 'white', 18, 'serif', 'center', true, tw.text__default__alpha(), tw.text__default__baseline(), tw.text__default__outline(), tw.text__default__outline_width());
print(colors__rgb(255, 136, 0));
print(colors__rgb(-5, 300, 16));
print(colors__hsl(200, 50, 25));
