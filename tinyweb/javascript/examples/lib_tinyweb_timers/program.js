// Generated from lib_tinyweb_timers.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print, pykFloatStr } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Sound__Voice, sound__start, sound__stop, sound__fade, sound__stop_all, sound__master_volume, sound__tone, sound__note, sound__rate_of, sound__tempo, sound__swing, sound__on_beat, sound__beat, sound__latency, sound__pause, sound__resume, sound__channel_style, sound__listen, sound__level, sound__band, sound__bands, sound__wave, sound__render_wav, sound__start__default__voice, sound__render_wav__default__on_rendered } from './tinyweb.js';
tw.web_init(0);
let ticks = 0;
let repeating = '';

function tick() {
  ticks = ticks + 1;
  print('tick', ticks, pykFloatStr(tw_external.time()));
  if (ticks === 3) {
    tw.cancel(repeating);
  }
}

function once() {
  print('once at', pykFloatStr(tw_external.time()), 'beat', pykFloatStr(sound__beat()), 'latency', pykFloatStr(sound__latency()), 'level', pykFloatStr(sound__level()));
  print('bands', sound__bands(), pykFloatStr(sound__band(0)), pykFloatStr(sound__band(1)), pykFloatStr(sound__band(9)));
  print('typed', tw.value_of('name'));
}

repeating = tw.every(0.5, tick);
const later = tw.after(2.0, once);
print(repeating, later);
