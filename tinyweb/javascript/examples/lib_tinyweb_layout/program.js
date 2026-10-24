// Generated from lib_tinyweb_layout.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { layout__row, layout__column, layout__inside, layout__outside, layout__text_area, layout__text_area__default__on_change } from './tinyweb.js';
tw.web_init(0);
tw.page_style(tw.page_style__default__background(), tw.page_style__default__foreground(), '', -1, -1, -1, 'center');
const title = tw_external.label('Layout');
tw.set_style(title, tw.set_style__default__background(), tw.set_style__default__foreground(), tw.set_style__default__border(), -1, -1, '', 28, -1, tw.set_style__default__accent(), -1, 700, -1);
const buttons = layout__row();
layout__inside(buttons);

function clicked() {
  print('clicked');
}

tw.button('one', clicked);
tw.button('two', tw.button__default__on_click());
layout__outside();
tw_external.canvas(100, 40);
const controls = layout__row();
layout__inside(controls);
tw_external.label('speed');
tw.slider(0, 10, 5, tw.slider__default__on_change());
layout__inside(buttons);
tw.button('three', tw.button__default__on_click());
layout__outside();
const figures = layout__row();
layout__inside(figures);
const left = layout__column();
layout__inside(left);
const small = tw_external.canvas(50, 20);
tw.set_style(small, tw.set_style__default__background(), tw.set_style__default__foreground(), tw.set_style__default__border(), -1, -1, '', -1, -1, tw.set_style__default__accent(), 100, -1, 40);
tw_external.label('stretched');
layout__inside(figures);
const right = layout__column();
layout__inside(right);
tw_external.canvas(100, 40);
tw_external.label('as it is');
layout__outside();

function edited(words) {
  print('notes:', words);
}

const notes = layout__text_area('first line\nsecond "line"', 3, 30, edited);
layout__text_area('', 4, 40, layout__text_area__default__on_change());
tw_external.label('the end');
print(notes, tw.value_of(notes));
