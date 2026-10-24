// Generated from lib_tinyweb_style.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
tw.web_init(0);
tw.theme('paper');
tw.theme('no such theme');
tw.page_style(color__hex(16643811), color__hex(5795445), 'serif', 18, 12, 16, '');
tw.button_style(color__hex(2526162), color__white, color__none, -1, 14, 'monospace', 16, 8);
tw.label_style(color__hex(16777184), color__hex(3355443), color__hex(16766720), 1, 4, 'sans-serif', 14, 6);
tw.slider_style(color__hex(14423100), 240, color__hex(14423100), 'monospace', 20);
tw.canvas_style(color__teal, 3, 10);
const title = tw_external.label('Styled');
tw.set_style(title, color__navy, color__white, color__orange, 2, 0, 'Georgia', 28, 10, tw.set_style__default__accent(), 300, -1, -1);
const level = tw.slider(0, 10, 4, tw.slider__default__on_change());
tw.set_style(level, tw.set_style__default__background(), color__hex(3050327), tw.set_style__default__border(), -1, -1, '', -1, -1, tw.set_style__default__accent(), -1, -1, -1);
const c = tw_external.canvas(120, 60);
tw.set_style(c, tw.set_style__default__background(), tw.set_style__default__foreground(), color__black, 1, -1, '', -1, -1, tw.set_style__default__accent(), -1, -1, -1);

function pressed() {
  tw.theme('retro');
  tw.set_style(title, color__black, tw.set_style__default__foreground(), tw.set_style__default__border(), -1, -1, '', -1, -1, tw.set_style__default__accent(), -1, -1, -1);
  print('now retro');
}

const ok = tw.button('Retro', pressed);
((background__arg) => ((border__arg) => ((accent__arg) => tw.set_style(ok, background__arg, color__black, border__arg, -1, -1, '', -1, -1, accent__arg, -1, -1, -1))(tw.set_style__default__accent()))(tw.set_style__default__border()))(color__rgba(255, 215, 0, 0.5));
