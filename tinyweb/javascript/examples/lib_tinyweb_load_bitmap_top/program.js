// Generated from lib_tinyweb_load_bitmap_top.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { bitmap__bitmap, bitmap__set_pixel, bitmap__get_pixel, bitmap__fill_bitmap, bitmap__show_bitmap, bitmap__load_bitmap, bitmap__size, bitmap__bitmap__default__background } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(100, 100);

function loaded(b) {
  const [w, h] = bitmap__size(b);
  print('ball.png is', w, 'by', h);
  const p = bitmap__get_pixel(b, Math.trunc(w / 2), Math.trunc(h / 2));
  print('its middle:', p.r, p.g, p.b);
  return bitmap__show_bitmap(c, b, 10, 10, 1.0);
}

bitmap__load_bitmap('ball.png', loaded);
bitmap__load_bitmap('no_such_picture.png', loaded);
print('asked for two pictures');
