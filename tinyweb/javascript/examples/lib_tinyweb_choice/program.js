// Generated from lib_tinyweb_choice.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { pykFormat } from './pyk-runtime.js';

// A Pyking list is a JavaScript array with a marker on it: a tuple
// is an array too, and the two print differently. A property rather
// than a class, so that a formatter in another module can read it.
function pykList(items) {
  items.pykList = true;
  return items;
}

// Pyking's `++` joins two strings or two lists. A list is an array
// here and JavaScript's `+` would stringify one, so which is meant
// is decided by looking -- this backend infers no types.
function pykConcat(a, b) {
  return Array.isArray(a) ? pykList([...a, ...b]) : a + b;
}

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
tw.web_init(0);
const names = pykList(['ocean', 'candy', 'forest']);
const shown = tw_external.label('ocean');

function changed(position) {
  return tw.set_text(shown, pykConcat('chose ', pykFormat(position)));
}

const menu = tw.choice(names, 0, changed);
tw.choice(pykList(['one']), 0, tw.choice__default__on_change());
tw_external.set_value(menu, 2);
