// Generated from lib_tinyweb_polygons.pyk by the Pyking compiler. Do not edit.
// Target: node24. Run with:  node <this file>

import { print } from './pyk-runtime.js';

// A Pyking list is a JavaScript array with a marker on it: a tuple
// is an array too, and the two print differently. A property rather
// than a class, so that a formatter in another module can read it.
function pykList(items) {
  items.pykList = true;
  return items;
}

// Pyking's `len`: a list's items, or a String's bytes in UTF-8.
function pykLen(value) {
  return Array.isArray(value) ? value.length : new TextEncoder().encode(value).length;
}

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { colors__palette as palette } from './tinyweb.js';
tw.web_init(0);
const c = tw_external.canvas(200, 200);
const ocean = palette('ocean');
print(pykLen(ocean));
tw.polygon(c, pykList([[100, 10], [130, 90], [70, 90]]), 'orange', 'black', tw.polygon__default__outline_width(), tw.polygon__default__alpha());
tw.path(c, pykList([[10, 190], [60, 120], [110, 170], [190, 110]]), 'teal', 3, tw.path__default__alpha());
tw.polygon(c, pykList([]), 'red', tw.polygon__default__outline(), tw.polygon__default__outline_width(), tw.polygon__default__alpha());
print(palette('nothing'));
