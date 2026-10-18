// Generated from lib_tinyweb_layout.pyk by the Pyking compiler. Do not edit.
// Target: node24. Run with:  node <this file>

import { print } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
tw.web_init(tw.web_init__default__port());
tw.page_style(tw.page_style__default__background(), tw.page_style__default__color(), tw.page_style__default__font(), tw.page_style__default__size(), tw.page_style__default__padding(), tw.page_style__default__gap(), 'center');
const title = tw_external.label('Layout');
tw.set_style(title, tw.set_style__default__background(), tw.set_style__default__color(), tw.set_style__default__border(), tw.set_style__default__radius(), tw.set_style__default__font(), 28, tw.set_style__default__padding(), tw.set_style__default__accent(), tw.set_style__default__width(), 700, tw.set_style__default__height());
const buttons = tw_external.row();
tw_external.inside(buttons);

function clicked() {
  print('clicked');
}

tw.button('one', clicked);
tw.button('two', tw.button__default__on_click());
tw_external.outside();
tw_external.canvas(100, 40);
const controls = tw_external.row();
tw_external.inside(controls);
tw_external.label('speed');
tw.slider(0, 10, 5, tw.slider__default__on_change());
tw_external.inside(buttons);
tw.button('three', tw.button__default__on_click());
tw_external.outside();
const figures = tw_external.row();
tw_external.inside(figures);
const left = tw_external.column();
tw_external.inside(left);
const small = tw_external.canvas(50, 20);
tw.set_style(small, tw.set_style__default__background(), tw.set_style__default__color(), tw.set_style__default__border(), tw.set_style__default__radius(), tw.set_style__default__font(), tw.set_style__default__size(), tw.set_style__default__padding(), tw.set_style__default__accent(), 100, tw.set_style__default__weight(), 40);
tw_external.label('stretched');
tw_external.inside(figures);
const right = tw_external.column();
tw_external.inside(right);
tw_external.canvas(100, 40);
tw_external.label('as it is');
tw_external.outside();
tw_external.label('the end');
