// Generated from lib_tinyweb_beat.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print, pykFloatStr } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Sound__Voice, sound__start, sound__stop, sound__fade, sound__stop_all, sound__master_volume, sound__tone, sound__note, sound__rate_of, sound__tempo, sound__swing, sound__on_beat, sound__beat, sound__latency, sound__pause, sound__resume, sound__channel_style, sound__listen, sound__level, sound__band, sound__bands, sound__wave, sound__render_wav, sound__start__default__voice, sound__render_wav__default__on_rendered } from './tinyweb.js';
tw.web_init(0);
const kick = tw_external.load_sample('kick1.wav');
const hat = tw_external.load_sample('hihat1.wav');
sound__tempo(120.0);
sound__swing(0.2);
sound__listen(8, 0.5);

function step(n, time) {
  print('step', n, 'at', pykFloatStr(time), 'beat', pykFloatStr(sound__beat()));
  if (n - Math.trunc(n / 4) * 4 === 0) {
    tw.play(kick, time, 1.0, 1.0, 0.0, tw.play__default__voice());
  }
  tw.play(hat, time, 0.3, 1.0, 0.0, tw.play__default__voice());
  if (n === 2) {
    sound__tempo(90.0);
  }
}

const steps = sound__on_beat(step, 2);
print(steps);

function listened() {
  print('level', pykFloatStr(sound__level()), 'bands', sound__bands(), pykFloatStr(sound__band(0)), pykFloatStr(sound__band(7)), 'wave', pykFloatStr(sound__wave(0)), pykFloatStr(sound__wave(3)));
}

tw.button('Listen', listened);

function toggle(on) {
  if (on) {
    sound__resume();
  } else {
    sound__pause();
  }
  print('playing', on);
}

tw.checkbox('Playing', true, toggle);

function song() {
  tw.play(kick, 0.0, 1.0, 1.0, 0.0, tw.play__default__voice());
  tw.play(kick, 0.5, 1.0, 1.0, 0.0, tw.play__default__voice());
  return sound__tone(220.0, 1.0, 0.25, 'sine', 0.5, 0.0, 0);
}

function done(took, peak) {
  print('rendered in', pykFloatStr(took), 'seconds, peak', pykFloatStr(peak));
}

sound__render_wav(2.0, song, 'song.wav', done);
sound__render_wav(1.0, song, 'tinyweb.wav', sound__render_wav__default__on_rendered());
print('latency', pykFloatStr(sound__latency()));
tw_external.splash();
