// Generated from lib_tinyweb_paint.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { pykTrunc } from './pyk-runtime.js';

// Which fields of a datatype's value are Floats, which only the
// compiler knows: a JavaScript number cannot say.
function pykWithShape(value, shape) {
  value.pykShape = shape;
  return value;
}

import * as math2 from './math.js';
import * as math2_external from './math_external.js';
import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
import { Smooth__Point, smooth__circle, smooth__circles, smooth__rect, smooth__ellipse, smooth__arc, smooth__polygon, smooth__line, smooth__lines, smooth__path, smooth__curve, smooth__bezier, smooth__text, smooth__clip_circle, smooth__clip_polygon, smooth__circle__default__fill, smooth__circle__default__stroke, smooth__circle__default__paint, smooth__circle__default__style, smooth__circles__default__fill, smooth__circles__default__stroke, smooth__circles__default__style, smooth__rect__default__fill, smooth__rect__default__stroke, smooth__rect__default__paint, smooth__rect__default__style, smooth__ellipse__default__fill, smooth__ellipse__default__stroke, smooth__ellipse__default__paint, smooth__ellipse__default__style, smooth__arc__default__fill, smooth__arc__default__stroke, smooth__arc__default__paint, smooth__arc__default__style, smooth__polygon__default__fill, smooth__polygon__default__stroke, smooth__polygon__default__style, smooth__line__default__stroke, smooth__line__default__style, smooth__lines__default__stroke, smooth__lines__default__style, smooth__path__default__stroke, smooth__path__default__style, smooth__curve__default__stroke, smooth__curve__default__style, smooth__bezier__default__stroke, smooth__bezier__default__style, smooth__text__default__fill, smooth__text__default__stroke, smooth__text__default__paint, smooth__text__default__style } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(300, 200);
const sky = pykWithShape(Color__Linear(0.0, 0.0, 0.0, 200.0, color__hex(1713022), color__hex(16758605), ''), '(f,f,f,f,.,.,.)');
tw.rect(c, 0, 0, 300, 200, tw.rect__default__fill(), tw.rect__default__stroke(), 1, 1.0, color__stop(sky, 0.6, color__hex(15277667)), tw.rect__default__style(), 0);
const ball = pykWithShape(Color__Radial(40.0, 40.0, 4.0, 50.0, 50.0, 30.0, color__white, color__hex(14423100), ''), '(f,f,f,f,f,f,.,.,.)');
tw.circle(c, 50, 50, 30, tw.circle__default__fill(), tw.circle__default__stroke(), 1, 1.0, ball, tw.circle__default__style());
const wheel = color__stop(color__stop(pykWithShape(Color__Conic(150.0, 50.0, math2.pi / 2.0, color__red, color__red, ''), '(f,f,f,.,.,.)'), 0.33, color__hex(65280)), 0.67, color__blue);
((fill__arg) => ((style__arg) => tw.circle(c, 150, 50, 30, fill__arg, color__white, 2, 1.0, wheel, style__arg))(tw.circle__default__style()))(tw.circle__default__fill());
tw.push(c);
tw.line_style(c, 'butt', 'bevel', 8.0, 4.0, 2.0, 0.0, 0.0);
tw.rect(c, 200, 20, 80, 60, color__none, color__white, 3, 1.0, tw.rect__default__paint(), tw.rect__default__style(), 0);
tw.line_style(c, 'round', 'round', 3.0, 0.0, 0.0, 0.0, 0.0);
tw.line(c, 200, 90, 280, 90, color__yellow, 2, 1.0, tw.line__default__style());
tw.pop(c);
tw.push(c);
tw.clip_rect(c, 10, 100, 60, 40);
tw.circle(c, 40, 120, 35, color__orange, tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style());
tw.pop(c);
tw.push(c);
tw.clip_circle(c, 120, 130, 25);
tw.rect(c, 90, 100, 60, 60, color__teal, tw.rect__default__stroke(), 1, 1.0, tw.rect__default__paint(), tw.rect__default__style(), 0);
tw.pop(c);
tw.bezier(c, 160, 160, 190, 100, 230, 200, 260, 120, color__black, 3, 1.0, tw.bezier__default__style());
tw.erase(c, 270, 150, 20, 20);
tw.text(c, 10, 190, 'bottom', color__white, 14, '', 'left', false, 1.0, 'bottom', color__black, 3, tw.text__default__paint(), tw.text__default__style());
tw.text(c, 80, 185, 'middle', color__white, 14, '', 'left', false, 1.0, 'middle', tw.text__default__stroke(), 1, tw.text__default__paint(), tw.text__default__style());
tw.text(c, 150, 185, 'alphabetic', color__none, 14, '', 'left', false, 1.0, 'alphabetic', color__white, 1, tw.text__default__paint(), tw.text__default__style());
smooth__circle(c, 250.5, 130.25, 6.5, color__hex(16766720), color__black, 0.5, 1.0, smooth__circle__default__paint(), smooth__circle__default__style());
smooth__rect(c, 200.5, 100.5, 30.0, 15.0, color__none, color__white, 1.0, 1.0, smooth__rect__default__paint(), smooth__rect__default__style(), 4.0);
smooth__ellipse(c, 100.0, 180.0, 12.5, 6.25, color__hex(14524637), smooth__ellipse__default__stroke(), 1.0, 1.0, smooth__ellipse__default__paint(), smooth__ellipse__default__style());
smooth__arc(c, 30.0, 170.0, 10.0, 0.0, 1.5 * math2.pi, color__none, color__cyan, 2.5, 1.0, smooth__arc__default__paint(), smooth__arc__default__style());
smooth__line(c, 0.0, 199.5, 300.0, 198.5, color__white, 0.8, 1.0, smooth__line__default__style());
smooth__curve(c, 5.0, 5.0, 50.0, 0.5, 95.0, 5.0, color__white, 1.5, 1.0, smooth__curve__default__style());
smooth__bezier(c, 5.0, 95.0, 30.0, 70.0, 70.0, 120.0, 95.0, 95.0, color__white, 1.5, 0.5, smooth__bezier__default__style());
smooth__text(c, 150.5, 100.25, 'smooth', color__white, 12, '', 'center', false, 1.0, 'middle', smooth__text__default__stroke(), 1.0, smooth__text__default__paint(), smooth__text__default__style());
tw.push(c);
smooth__clip_circle(c, 50.5, 50.5, 20.0);
tw.rect(c, 30, 30, 20, 40, color__black, tw.rect__default__stroke(), 1, 0.3, tw.rect__default__paint(), tw.rect__default__style(), 0);
tw.pop(c);
const outlined = pykWithShape(tw.Style(color__navy, color__yellow, 2, 0.8, tw.field__default__Style__paint()), '(.,.,.,f,.)');
tw.circle(c, 20, 20, 8, tw.circle__default__fill(), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), outlined);
tw.rect(c, 40, 10, 20, 20, color__red, tw.rect__default__stroke(), 1, 1.0, tw.rect__default__paint(), outlined, 0);
tw.line(c, 0, 0, 30, 30, tw.line__default__stroke(), 1, 1.0, outlined);
tw.circle(c, 70, 20, 8, tw.circle__default__fill(), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), pykWithShape(tw.Style(tw.field__default__Style__fill(), tw.field__default__Style__stroke(), 1, 1.0, ball), '(.,.,.,f,.)'));
smooth__circle(c, 90.0, 20.0, 8.0, smooth__circle__default__fill(), smooth__circle__default__stroke(), 1.0, 1.0, smooth__circle__default__paint(), outlined);

function underline(width) {
  return tw.line(c, 10, 60, 10 + pykTrunc(width), 60, color__white, 2, 1.0, tw.line__default__style());
}

tw.measure_text('Hello, canvas!', underline, 20, '', true);
