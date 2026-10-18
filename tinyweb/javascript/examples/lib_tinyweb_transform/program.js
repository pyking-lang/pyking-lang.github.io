// Generated from lib_tinyweb_transform.pyk by the Pyking compiler. Do not edit.
// Target: node24. Run with:  node <this file>

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
tw.web_init(0);
const c = tw_external.canvas(200, 200);

function draw(t) {
  tw.clear(c, 'black');
  tw.push(c);
  tw.translate(c, 100.0, 100.0);
  tw.rotate(c, t * 90.0);
  tw.rect(c, -20, -20, 40, 40, 'crimson', tw.rect__default__outline(), tw.rect__default__outline_width(), tw.rect__default__alpha(), tw.rect__default__radius());
  tw.push(c);
  tw.scale(c, 0.5, 2.0);
  tw.circle(c, 60, 0, 10, 'white', tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha());
  tw.pop(c);
  tw.pop(c);
  tw.shadow(c, 'white', 12, tw.shadow__default__dx(), tw.shadow__default__dy());
  tw.circle(c, 30, 30, 10, 'gold', tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha());
  tw.shadow(c, '', tw.shadow__default__blur(), tw.shadow__default__dx(), tw.shadow__default__dy());
  tw.blend(c, 'add');
  tw.circle(c, 160, 160, 20, '#800000', tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha());
  tw.circle(c, 175, 160, 20, '#000080', tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha());
  tw.blend(c, 'normal');
  tw.blend(c, 'multiply');
  return tw.reset(c);
}

tw_external.on_frame(draw);
