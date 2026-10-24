// Generated from lib_tinyweb_pointer.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print, pykFloatStr } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Color__Color, color__black, color__white, color__gray, color__red, color__green, color__blue, color__yellow, color__orange, color__purple, color__pink, color__navy, color__teal, color__brown, color__cyan, color__magenta, color__none, color__theme, color__rgb, color__rgba, color__hsl, color__hex, color__to_hex, color__with_alpha, color__mix, color__same, color__palette, Color__Paint, Color__Plain, Color__Linear, Color__Radial, Color__Conic, color__stop } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(200, 100);
const other = tw_external.canvas(50, 50);
tw.track_mouse(c);

function pressed(x, y) {
  print('press at', x, y, 'down', tw.mouse(c).down);
  return tw.circle(c, x, y, 4, color__hex(14423100), tw.circle__default__stroke(), 1, 1.0, tw.circle__default__paint(), tw.circle__default__style());
}

function dragged(x, y) {
  print('drag to', x, y, 'down', tw.mouse(c).down);
  return tw.line(c, 0, 0, x, y, color__black, 2, 1.0, tw.line__default__style());
}

function moved(x, y) {
  print('move to', x, y, 'down', tw.mouse(c).down);
}

function released(x, y) {
  print('release at', x, y, 'down', tw.mouse(c).down);
}

function nothing(x, y) {
  return [];
}

tw.on_press(c, pressed);
tw.on_drag(c, dragged);
tw.on_move(c, moved);
tw.on_release(c, released);
tw.on_move(other, nothing);
const start = tw.mouse(c);
print('before any event', start.x, start.y, start.down);

function let_go(key) {
  print('let go of', key, 'still held:', tw_external.key_down(key));
}

tw_external.on_key_up(let_go);

function frame(t) {
  const left = tw_external.key_down('ArrowLeft');
  const right = tw_external.key_down('ArrowRight');
  print('frame', pykFloatStr(t), 'left', left, 'right', right);
}

tw_external.on_frame(frame);
