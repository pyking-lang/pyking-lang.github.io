// Generated from lib_tinyweb_splash_voice.pyk by the Pyking compiler. Do not edit.
// Target: node22. Run with:  node <this file>

import { print } from './pyk-runtime.js';

import * as tw from './tinyweb.js';
import * as tw_external from './tinyweb_external.js';
import { Sound__Voice, sound__start, sound__stop, sound__fade, sound__stop_all, sound__master_volume, sound__tone, sound__note, sound__rate_of, sound__tempo, sound__swing, sound__on_beat, sound__beat, sound__latency, sound__pause, sound__resume, sound__channel_style, sound__listen, sound__level, sound__band, sound__bands, sound__wave, sound__render_wav, sound__start__default__voice, sound__render_wav__default__on_rendered } from './tinyweb.js';
tw.web_init(0);
sound__tone(sound__note('A4'), 0.0, 0.25, 'sine', 0.5, 0.0, 0);

function hum() {
  print(((sample__arg) => ((voice__arg) => sound__start(sample__arg, 0.0, 0.3, 1.0, 0.0, true, voice__arg))(sound__start__default__voice()))(tw_external.load_sample('piano_c1.wav')));
}

tw.button('Hum', hum);
tw_external.splash();
