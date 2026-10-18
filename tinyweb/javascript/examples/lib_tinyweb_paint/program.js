// Generated from lib_tinyweb_paint.pyk by the Pyking compiler. Do not edit.
// Target: node24. Run with:  node <this file>

import { pykTrunc } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { colors__rgb, colors__rgba, colors__hsl, colors__palette, colors__linear_gradient, colors__radial_gradient, colors__conic_gradient, colors__stop } from './tinyweb.js';
import { smooth__circle, smooth__circles, smooth__rect, smooth__ellipse, smooth__arc, smooth__polygon, smooth__line, smooth__lines, smooth__path, smooth__curve, smooth__bezier, smooth__text, smooth__clip_circle, smooth__clip_polygon, smooth__circle__default__color, smooth__circle__default__outline, smooth__circle__default__outline_width, smooth__circle__default__alpha, smooth__circles__default__color, smooth__circles__default__outline, smooth__circles__default__outline_width, smooth__circles__default__alpha, smooth__rect__default__color, smooth__rect__default__outline, smooth__rect__default__outline_width, smooth__rect__default__alpha, smooth__rect__default__radius, smooth__ellipse__default__color, smooth__ellipse__default__outline, smooth__ellipse__default__outline_width, smooth__ellipse__default__alpha, smooth__arc__default__color, smooth__arc__default__outline, smooth__arc__default__outline_width, smooth__arc__default__alpha, smooth__polygon__default__color, smooth__polygon__default__outline, smooth__polygon__default__outline_width, smooth__polygon__default__alpha, smooth__line__default__color, smooth__line__default__width, smooth__line__default__alpha, smooth__lines__default__color, smooth__lines__default__width, smooth__lines__default__alpha, smooth__path__default__color, smooth__path__default__width, smooth__path__default__alpha, smooth__curve__default__color, smooth__curve__default__width, smooth__curve__default__alpha, smooth__bezier__default__color, smooth__bezier__default__width, smooth__bezier__default__alpha, smooth__text__default__color, smooth__text__default__size, smooth__text__default__font, smooth__text__default__align, smooth__text__default__bold, smooth__text__default__alpha, smooth__text__default__baseline, smooth__text__default__outline, smooth__text__default__outline_width } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(300, 200);
const sky = colors__linear_gradient(0.0, 0.0, 0.0, 200.0, '#1a237e', '#ffb74d');
const sky2 = colors__stop(sky, 0.6, '#e91e63');
tw.clear(c, sky2);
const ball = colors__radial_gradient(40.0, 40.0, 4.0, 50.0, 50.0, 30.0, 'white', 'crimson');
tw.circle(c, 50, 50, 30, ball, tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha());
const wheel = colors__stop(colors__stop(colors__conic_gradient(150.0, 50.0, 90.0, 'red', 'red'), 0.33, 'lime'), 0.67, 'blue');
tw.circle(c, 150, 50, 30, wheel, 'white', 2, tw.circle__default__alpha());
tw.push(c);
tw.line_style(c, 'butt', 'bevel', 8.0, 4.0, 2.0, tw.line_style__default__dash2(), tw.line_style__default__gap2());
tw.rect(c, 200, 20, 80, 60, '', 'white', 3, tw.rect__default__alpha(), tw.rect__default__radius());
tw.line_style(c, tw.line_style__default__cap(), tw.line_style__default__join(), 3.0, tw.line_style__default__gap(), tw.line_style__default__offset(), tw.line_style__default__dash2(), tw.line_style__default__gap2());
tw.line(c, 200, 90, 280, 90, 'yellow', 2, tw.line__default__alpha());
tw.pop(c);
tw.push(c);
tw.clip_rect(c, 10, 100, 60, 40);
tw.circle(c, 40, 120, 35, 'orange', tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha());
tw.pop(c);
tw.push(c);
tw.clip_circle(c, 120, 130, 25);
tw.rect(c, 90, 100, 60, 60, 'teal', tw.rect__default__outline(), tw.rect__default__outline_width(), tw.rect__default__alpha(), tw.rect__default__radius());
tw.pop(c);
tw.bezier(c, 160, 160, 190, 100, 230, 200, 260, 120, 'black', 3, tw.bezier__default__alpha());
tw.erase(c, 270, 150, 20, 20);
tw.text(c, 10, 190, 'bottom', 'white', 14, tw.text__default__font(), tw.text__default__align(), tw.text__default__bold(), tw.text__default__alpha(), 'bottom', 'black', 3);
tw.text(c, 80, 185, 'middle', 'white', 14, tw.text__default__font(), tw.text__default__align(), tw.text__default__bold(), tw.text__default__alpha(), 'middle', tw.text__default__outline(), tw.text__default__outline_width());
tw.text(c, 150, 185, 'alphabetic', '', 14, tw.text__default__font(), tw.text__default__align(), tw.text__default__bold(), tw.text__default__alpha(), 'alphabetic', 'white', tw.text__default__outline_width());
smooth__circle(c, 250.5, 130.25, 6.5, 'gold', 'black', 0.5, smooth__circle__default__alpha());
smooth__rect(c, 200.5, 100.5, 30.0, 15.0, '', 'white', smooth__rect__default__outline_width(), smooth__rect__default__alpha(), 4.0);
smooth__ellipse(c, 100.0, 180.0, 12.5, 6.25, 'plum', smooth__ellipse__default__outline(), smooth__ellipse__default__outline_width(), smooth__ellipse__default__alpha());
smooth__arc(c, 30.0, 170.0, 10.0, 0.0, 270.0, '', 'cyan', 2.5, smooth__arc__default__alpha());
smooth__line(c, 0.0, 199.5, 300.0, 198.5, 'white', 0.8, smooth__line__default__alpha());
smooth__curve(c, 5.0, 5.0, 50.0, 0.5, 95.0, 5.0, 'white', 1.5, smooth__curve__default__alpha());
smooth__bezier(c, 5.0, 95.0, 30.0, 70.0, 70.0, 120.0, 95.0, 95.0, 'white', 1.5, 0.5);
smooth__text(c, 150.5, 100.25, 'smooth', 'white', 12, smooth__text__default__font(), 'center', smooth__text__default__bold(), smooth__text__default__alpha(), 'middle', smooth__text__default__outline(), smooth__text__default__outline_width());
tw.push(c);
smooth__clip_circle(c, 50.5, 50.5, 20.0);
tw.rect(c, 30, 30, 20, 40, 'black', tw.rect__default__outline(), tw.rect__default__outline_width(), 0.3, tw.rect__default__radius());
tw.pop(c);

function underline(width) {
  return tw.line(c, 10, 60, 10 + pykTrunc(width), 60, 'white', 2, tw.line__default__alpha());
}

tw.measure_text('Hello, canvas!', underline, 20, tw.measure_text__default__font(), true);
