// Generated from lib_tinyweb_pointer.pyk by the Pyking compiler. Do not edit.
// Target: node24. Run with:  node <this file>

import { print, pykFloatStr } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
tw.web_init(0);
const c = tw_external.canvas(200, 100);
const other = tw_external.canvas(50, 50);

function pressed(x, y) {
  print('press at', x, y, 'down', tw.mouse_down(c));
  return tw.circle(c, x, y, 4, 'crimson', tw.circle__default__outline(), tw.circle__default__outline_width(), tw.circle__default__alpha());
}

function dragged(x, y) {
  print('drag to', x, y);
  return tw.line(c, tw.mouse_x(c), tw.mouse_y(c), x, y, 'black', 2, tw.line__default__alpha());
}

function moved(x, y) {
  print('move to', x, y, 'down', tw.mouse_down(c));
}

function released(x, y) {
  print('release at', x, y, 'down', tw.mouse_down(c));
}

tw.on_press(c, pressed);
tw.on_drag(c, dragged);
tw.on_move(c, moved);
tw.on_release(c, released);
tw.on_move(other, tw.ignore2);
print('before any event', tw.mouse_x(c), tw.mouse_y(c), tw.mouse_down(c));

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
