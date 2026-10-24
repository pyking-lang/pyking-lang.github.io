// Generated from lib_tinyweb_voices.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print, pykFloatStr } from './pyk-runtime.js';

// Which fields of a datatype's value are Floats, which only the
// compiler knows: a JavaScript number cannot say.
function pykWithShape(value, shape) {
  value.pykShape = shape;
  return value;
}

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Sound__Voice, sound__start, sound__stop, sound__fade, sound__stop_all, sound__master_volume, sound__tone, sound__note, sound__rate_of, sound__tempo, sound__swing, sound__on_beat, sound__beat, sound__latency, sound__pause, sound__resume, sound__channel_style, sound__listen, sound__level, sound__band, sound__bands, sound__wave, sound__render_wav, sound__start__default__voice, sound__render_wav__default__on_rendered } from './tinyweb.js';
tw.web_init(0);
const kick = tw_external.load_sample('kick1.wav');
const piano = tw_external.load_sample('piano_c1.wav');
sound__master_volume(0.8);
sound__channel_style(1, 0.7, -0.5, 0.4, 0.25, 0.5, 0.0, 0.0);
sound__channel_style(2, 1.0, 0.0, 0.0, 0.3, 0.35, 0.6, 1200.0);
sound__channel_style(1, 0.9, 0.0, 0.0, 0.3, 0.35, 0.0, 0.0);
tw.play(kick, 0.0, 1.0, 1.0, 0.0, tw.play__default__voice());
tw.play(kick, 0.5, 0.5, 2.0, 1.0, tw.play__default__voice());
const soft = pykWithShape(Sound__Voice(0.25, 1.0, 0.0, 1, false, false), '(f,f,f,.,.,.)');
tw.play(kick, 0.0, 1.0, 1.0, 0.0, soft);
tw.play(kick, 0.0, 0.75, 1.0, 0.0, soft);
tw.play(piano, 0.0, 1.0, 1.0, 0.0, pykWithShape(Sound__Voice(1.0, 1.0, 0.0, 2, false, true), '(f,f,f,.,.,.)'));
const hum = sound__start(piano, 0.0, 0.3, 1.0, 0.0, true, sound__start__default__voice());
const other = sound__start(piano, 1.0, 1.0, 1.0, 0.0, false, pykWithShape(Sound__Voice(1.0, 0.5, 0.0, 2, true, false), '(f,f,f,.,.,.)'));
print(hum, other);
sound__tone(440.0, 0.0, 0.5, 'sine', 0.5, 0.0, 0);
sound__tone(sound__note('C5'), 0.25, 0.125, 'square', 0.2, 0.5, 1);
print(pykFloatStr(sound__note('A4')), pykFloatStr(sound__note('C4')), pykFloatStr(sound__note('C#4')), pykFloatStr(sound__note('Db4')), pykFloatStr(sound__note('H2')), pykFloatStr(sound__note('C')));
print(pykFloatStr(sound__rate_of('C5', 'C4')), pykFloatStr(sound__rate_of('C3', 'C4')), pykFloatStr(sound__rate_of('G4', 'G3')), pykFloatStr(sound__rate_of('nothing', 'C4')));

function quieter() {
  sound__fade(hum, 0.0, 2.0);
  print('fading');
}

function stop() {
  sound__stop(other, 0.0);
  sound__stop(hum, 3.0);
  print('stopped');
}

function silence() {
  sound__stop_all();
  print('silence');
}

tw.button('Quieter', quieter);
tw.button('Stop', stop);
tw.button('Silence', silence);
tw_external.splash();
