---
title: tinyweb.sound
description: "Sound beyond `play`: voices that can be stopped and faded, tones made without a sample, a beat scheduled ahead of time, channels with effects, and listening to what plays."
sidebar:
  label: sound
  parent: tinyweb
  position: 3
---

Sound beyond `play`: voices that can be stopped and faded, tones made
without a sample, a beat scheduled ahead of time, channels with
effects, and listening to what plays.

Most sounds are fired and forgotten with `tw.play`. A sound that has
to be controlled while it plays -- music that loops until the level
ends, a note held while a key is down -- is a voice: `start` begins
one and answers its identifier, which `stop` and `fade` take.

The beat is kept by the page, a little ahead of time, so it stays
exact however far away the program runs: `on_beat` calls a function
for each step with the step's exact time, and a sound played `at` that
time lands on it.

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
kick = tw.load_sample("kick1.wav")
hat = tw.load_sample("hihat1.wav")
def step(n: Int, time: Float):
    if n - n / 4 * 4 == 0:
        tw.play(kick, at = time)
    tw.play(hat, at = time, volume = 0.4)
sound.tempo(110.0)
sound.on_beat(step, steps = 4)
```

```pyking norun
import tinyweb.sound as sound
```

| Topic | |
|---|---|
| [Voices](#voices) | [`Voice`](#soundvoice), [`start`](#soundstart), [`stop`](#soundstop), [`fade`](#soundfade), [`stop_all`](#soundstop_all), [`master_volume`](#soundmaster_volume) |
| [Tones and notes](#tones-and-notes) | [`tone`](#soundtone), [`note`](#soundnote), [`rate_of`](#soundrate_of) |
| [The beat](#the-beat) | [`tempo`](#soundtempo), [`swing`](#soundswing), [`on_beat`](#soundon_beat), [`beat`](#soundbeat), [`latency`](#soundlatency), [`pause`](#soundpause), [`resume`](#soundresume) |
| [Channels and effects](#channels-and-effects) | [`channel_style`](#soundchannel_style) |
| [Listening](#listening) | [`listen`](#soundlisten), [`level`](#soundlevel), [`band`](#soundband), [`bands`](#soundbands), [`wave`](#soundwave) |
| [Rendering](#rendering) | [`render_wav`](#soundrender_wav) |

## Voices

<div class="pyk-api">

### sound.Voice

<pre class="pyk-sig"><code><span class="k">struct</span> <span class="n">sound.Voice</span>(volume = 1.0, rate = 1.0, pan = 0.0, channel = 0, looping = false, reverse = false)</code></pre>

How a sound is played, defined once and given to `tw.play` and
`start` as `voice = ...`. A sound's own argument left at its default
takes the voice's value.

<p class="pyk-api-label">Parameters</p>

- `volume`: how loud, as a multiple of the sample's own volume.
- `rate`: how fast: 2.0 is twice as fast and an octave higher.
- `pan`: where it is heard, from -1.0 (left) to 1.0 (right).
- `channel`: the channel it goes through, from 0; 0 by default.
- `looping`: whether `start` plays it again and again until stopped.
- `reverse`: whether it plays backwards.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.sound as sound
soft = sound.Voice(volume = 0.3, pan = -0.5)
print(soft.volume, soft.rate, soft.channel, sound.Voice(reverse = true, ..soft).reverse)
```

```stdout visible = true
0.3 1.0 0 true
```

</div>

<div class="pyk-api">

### sound.start

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.start</span>(
    <span class="p">sample</span>: <span class="t">String</span>,
    <span class="p">at</span>: <span class="t">Float</span> = 0.0,
    <span class="p">volume</span>: <span class="t">Float</span> = 1.0,
    <span class="p">rate</span>: <span class="t">Float</span> = 1.0,
    <span class="p">pan</span>: <span class="t">Float</span> = 0.0,
    <span class="p">looping</span>: <span class="t">Bool</span> = false,
    <span class="p">voice</span>: sound.Voice = sound.Voice(),
) -&gt; <span class="t">String</span></code></pre>

Starts playing a sample as a voice, which `stop` and `fade` can
change while it plays: music that loops, an engine that hums while a
key is held.

<p class="pyk-api-label">Parameters</p>

- `sample`: the sample, as `tw.load_sample` answered.
- `at`: when, on the page's clock; now by default.
- `volume`: how loud.
- `rate`: how fast: 2.0 is twice as fast and an octave higher.
- `pan`: where it is heard, from -1.0 (left) to 1.0 (right).
- `looping`: whether it plays again and again until stopped.
- `voice`: a `Voice` for what is not given here.

<p class="pyk-api-label">Returns</p>

The voice's identifier: `"voice"`, with a number added where something
on the page has that name already.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
hum = tw.load_sample("hihat1.wav")
print(sound.start(hum, looping = true, volume = 0.3))
```

```stdout visible = true
voice
```

</div>

<div class="pyk-api">

### sound.stop

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.stop</span>(<span class="p">voice</span>: <span class="t">String</span>, <span class="p">at</span>: <span class="t">Float</span> = 0.0) -&gt; ()</code></pre>

Stops a voice, now or at a time on the page's clock.

<p class="pyk-api-label">Parameters</p>

- `voice`: the voice, as `start` answered.
- `at`: when; now by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
music = sound.start(tw.load_sample("piano_c1.wav"), looping = true)
sound.stop(music, at = tw.time() + 2.0)
```

</div>

<div class="pyk-api">

### sound.fade

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.fade</span>(<span class="p">voice</span>: <span class="t">String</span>, <span class="p">volume</span>: <span class="t">Float</span>, <span class="p">over</span>: <span class="t">Float</span> = 1.0) -&gt; ()</code></pre>

Changes a voice's volume smoothly, from what it is now to `volume`
over `over` seconds: a fade to 0.0 and then a `stop` is a fade-out.

<p class="pyk-api-label">Parameters</p>

- `voice`: the voice, as `start` answered.
- `volume`: the volume to reach.
- `over`: how long it takes, in seconds; 1.0 by default.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
music = sound.start(tw.load_sample("piano_c1.wav"), looping = true)
def game_over():
    sound.fade(music, 0.0, over = 2.0)
    sound.stop(music, at = tw.time() + 2.0)
tw.button("Game over", on_click = game_over)
```

</div>

<div class="pyk-api">

### sound.stop_all

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.stop_all</span>() -&gt; ()</code></pre>

Stops every sound: every voice, and every sound `play` or `tone` has
scheduled that has not ended -- what jumping to another place in a
song needs.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
tw.button("Silence", on_click = sound.stop_all)
```

</div>

<div class="pyk-api">

### sound.master_volume

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.master_volume</span>(<span class="p">volume</span>: <span class="t">Float</span>) -&gt; ()</code></pre>

Sets how loud everything is, at once.

<p class="pyk-api-label">Parameters</p>

- `volume`: 1.0 as it is, 0.0 silent.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
sound.master_volume(0.5)
```

</div>

## Tones and notes

<div class="pyk-api">

### sound.tone

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.tone</span>(
    <span class="p">frequency</span>: <span class="t">Float</span>,
    <span class="p">at</span>: <span class="t">Float</span> = 0.0,
    <span class="p">duration</span>: <span class="t">Float</span> = 0.5,
    <span class="p">wave</span>: <span class="t">String</span> = &quot;sine&quot;,
    <span class="p">volume</span>: <span class="t">Float</span> = 0.5,
    <span class="p">pan</span>: <span class="t">Float</span> = 0.0,
    <span class="p">channel</span>: <span class="t">Int</span> = 0,
) -&gt; ()</code></pre>

Plays a tone made without a sample: a wave at `frequency`, with a
short attack and release so it does not click.

<p class="pyk-api-label">Parameters</p>

- `frequency`: how high, in hertz: 440.0 is the A above middle C.
- `at`: when, on the page's clock; now by default.
- `duration`: how long, in seconds.
- `wave`: its shape: `"sine"`, `"square"`, `"triangle"` or `"sawtooth"`.
- `volume`: how loud; 0.5 by default.
- `pan`: where it is heard, from -1.0 (left) to 1.0 (right).
- `channel`: the channel it goes through.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
def beep():
    sound.tone(sound.note("A4"), duration = 0.2, wave = "square", volume = 0.2)
tw.button("Beep", on_click = beep)
```

</div>

<div class="pyk-api">

### sound.note

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.note</span>(<span class="p">name</span>: <span class="t">String</span>) -&gt; <span class="t">Float</span></code></pre>

The frequency of a note named the usual way: a letter from A to G, a
`#` or `b` for sharp or flat, and the octave, where `"A4"` is 440 Hz
and `"C4"` is middle C.

<p class="pyk-api-label">Parameters</p>

- `name`: the note, such as `"C4"`, `"F#3"` or `"Bb5"`.

<p class="pyk-api-label">Returns</p>

Its frequency in hertz; 0.0 for a name that is not a note.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.sound as sound
print(sound.note("A4"), sound.note("A5"), sound.note("C4") > 261.0)
```

```stdout visible = true
440.0 880.0 true
```

</div>

<div class="pyk-api">

### sound.rate_of

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.rate_of</span>(<span class="p">name</span>: <span class="t">String</span>, <span class="p">base</span>: <span class="t">String</span> = &quot;C4&quot;) -&gt; <span class="t">Float</span></code></pre>

The `rate` that plays a sample recorded at the note `base` at the note
`name`: how one piano sample plays a whole melody.

<p class="pyk-api-label">Parameters</p>

- `name`: the note to play.
- `base`: the note the sample is; `"C4"` by default.

<p class="pyk-api-label">Returns</p>

The rate: 2.0 an octave up, 0.5 an octave down.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb.sound as sound
print(sound.rate_of("C5"), sound.rate_of("C3"), sound.rate_of("C4"))
```

```stdout visible = true
2.0 0.5 1.0
```

</div>

## The beat

<div class="pyk-api">

### sound.tempo

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.tempo</span>(<span class="p">bpm</span>: <span class="t">Float</span>) -&gt; ()</code></pre>

Sets the beats per minute the beat goes at; 120 until it is set. A
change takes effect at the next step, and the beat goes on from where
it is.

<p class="pyk-api-label">Parameters</p>

- `bpm`: beats per minute.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
sound.tempo(90.0)
```

</div>

<div class="pyk-api">

### sound.swing

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.swing</span>(<span class="p">amount</span>: <span class="t">Float</span>) -&gt; ()</code></pre>

Delays every other step, for a shuffling, swung beat.

<p class="pyk-api-label">Parameters</p>

- `amount`: how far each odd step is delayed, as a part of a step: 0.0 straight, 0.33 a triplet shuffle.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
sound.swing(0.33)
```

</div>

<div class="pyk-api">

### sound.on_beat

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.on_beat</span>(<span class="p">f</span>: (<span class="t">Int</span>, <span class="t">Float</span>) -&gt; (), <span class="p">steps</span>: <span class="t">Int</span> = 4) -&gt; <span class="t">String</span></code></pre>

Calls `f` a little ahead of each step of the beat, `steps` to a beat,
with the step's number, counting from 0 when the beat started, and
its exact time on the page's clock: a step sequencer is the steps to
play and an `on_beat` that plays them `at` that time.

<p class="pyk-api-label">Parameters</p>

- `f`: what is called with each step and its time.
- `steps`: how many steps a beat is cut into: 4 is sixteenth notes.

<p class="pyk-api-label">Returns</p>

The beat's identifier, which `tw.cancel` stops.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
kick = tw.load_sample("kick1.wav")
def step(n: Int, time: Float):
    if n - n / 4 * 4 == 0:
        tw.play(kick, at = time)
print(sound.on_beat(step))
```

```stdout visible = true
beat
```

</div>

<div class="pyk-api">

### sound.beat

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.beat</span>() -&gt; <span class="t">Float</span></code></pre>

Where the beat is, as of the last event, as a number of beats with a
fraction: what a frame draws a pulse from.

<p class="pyk-api-label">Returns</p>

The beat; 0.0 until a beat has started.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
c = tw.canvas(100, 100)
def frame(t: Float):
    phase = sound.beat() - float(int(sound.beat()))
    tw.clear(c)
    tw.circle(c, 50, 50, 40 - int(phase * 30.0))
tw.on_frame(frame)
```

</div>

<div class="pyk-api">

### sound.latency

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.latency</span>() -&gt; <span class="t">Float</span></code></pre>

How late sound comes out of the speakers after it is played, in
seconds, as the browser reports it: what to hold a picture back by to
see it with the sound.

<p class="pyk-api-label">Returns</p>

The latency; 0.0 until sound has started.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
print(sound.latency() >= 0.0)
```

```stdout visible = true
true
```

</div>

<div class="pyk-api">

### sound.pause

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.pause</span>() -&gt; ()</code></pre>

Pauses the page's clock, and every sound with it: everything freezes,
and `resume` goes on from exactly there.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
tw.button("Pause", on_click = sound.pause)
tw.button("Resume", on_click = sound.resume)
```

</div>

<div class="pyk-api">

### sound.resume

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.resume</span>() -&gt; ()</code></pre>

Lets the page's clock, and every sound, go on after `pause`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
sound.resume()
```

</div>

## Channels and effects

<div class="pyk-api">

### sound.channel_style

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.channel_style</span>(
    <span class="p">channel</span>: <span class="t">Int</span>,
    <span class="p">volume</span>: <span class="t">Float</span> = 1.0,
    <span class="p">pan</span>: <span class="t">Float</span> = 0.0,
    <span class="p">echo</span>: <span class="t">Float</span> = 0.0,
    <span class="p">echo_time</span>: <span class="t">Float</span> = 0.3,
    <span class="p">feedback</span>: <span class="t">Float</span> = 0.35,
    <span class="p">reverb</span>: <span class="t">Float</span> = 0.0,
    <span class="p">low_pass</span>: <span class="t">Float</span> = 0.0,
) -&gt; ()</code></pre>

Sets how a channel sounds: every sound played through it (`channel`
in a `Voice`, or `tone`'s) goes through its volume, pan, filter, echo
and reverb. Channel 0 is where every sound goes unless told otherwise.

<p class="pyk-api-label">Parameters</p>

- `channel`: the channel, from 0.
- `volume`: how loud.
- `pan`: where it is heard, from -1.0 (left) to 1.0 (right).
- `echo`: how loud its echo is, 0.0 (none) to 1.0.
- `echo_time`: how long after the sound the echo comes, in seconds.
- `feedback`: how much of each echo echoes again, 0.0 to 0.95.
- `reverb`: how much of a room it sounds in, 0.0 to 1.0.
- `low_pass`: a filter's frequency in hertz: above it the sound dulls; 0.0 for no filter.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
sound.channel_style(1, echo = 0.4, echo_time = 0.25, reverb = 0.3)
snare = tw.load_sample("snare1.wav")
def hit():
    tw.play(snare, voice = sound.Voice(channel = 1))
tw.button("Snare", on_click = hit)
```

</div>

## Listening

<div class="pyk-api">

### sound.listen

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.listen</span>(<span class="p">bins</span>: <span class="t">Int</span> = 32, <span class="p">smoothing</span>: <span class="t">Float</span> = 0.8) -&gt; ()</code></pre>

Starts listening to what plays: from then on every frame the page
reports how loud it is (`level`), how loud each of `bins` frequency
bands is (`band`) and the wave itself (`wave`).

<p class="pyk-api-label">Parameters</p>

- `bins`: how many bands and wave points; 32 by default, up to 1024.
- `smoothing`: how much each frame's bands are kept from the last one's, 0.0 to 0.99.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
sound.listen(bins = 64)
```

</div>

<div class="pyk-api">

### sound.level

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.level</span>() -&gt; <span class="t">Float</span></code></pre>

How loud what plays is, as of the last frame, once `listen` has
started.

<p class="pyk-api-label">Returns</p>

From 0.0 (silent) to 1.0.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
print(sound.level())
```

```stdout visible = true
0.0
```

</div>

<div class="pyk-api">

### sound.band

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.band</span>(<span class="p">k</span>: <span class="t">Int</span>) -&gt; <span class="t">Float</span></code></pre>

How loud one band of frequencies is, as of the last frame, once
`listen` has started: band 0 is the lowest.

<p class="pyk-api-label">Parameters</p>

- `k`: the band, from 0 to `bands() - 1`.

<p class="pyk-api-label">Returns</p>

From 0.0 to 1.0; 0.0 for a band there is none of.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
print(sound.band(0))
```

```stdout visible = true
0.0
```

</div>

<div class="pyk-api">

### sound.bands

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.bands</span>() -&gt; <span class="t">Int</span></code></pre>

How many bands the last frame reported.

<p class="pyk-api-label">Returns</p>

The number of bands; 0 before `listen`.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
print(sound.bands())
```

```stdout visible = true
0
```

</div>

<div class="pyk-api">

### sound.wave

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.wave</span>(<span class="p">k</span>: <span class="t">Int</span>) -&gt; <span class="t">Float</span></code></pre>

One point of the wave that played, as of the last frame, once `listen`
has started: what an oscilloscope draws.

<p class="pyk-api-label">Parameters</p>

- `k`: the point, from 0 to `bands() - 1`.

<p class="pyk-api-label">Returns</p>

From -1.0 to 1.0.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
print(sound.wave(0))
```

```stdout visible = true
0.0
```

</div>

## Rendering

<div class="pyk-api">

### sound.render_wav

<pre class="pyk-sig"><code><span class="k">def</span> <span class="n">sound.render_wav</span>(
    <span class="p">seconds</span>: <span class="t">Float</span>,
    <span class="p">f</span>: () -&gt; (),
    <span class="p">name</span>: <span class="t">String</span> = &quot;tinyweb.wav&quot;,
    <span class="p">on_rendered</span>: (<span class="t">Float</span>, <span class="t">Float</span>) -&gt; () = sound.ignore_rendered,
) -&gt; ()</code></pre>

Renders sound into a WAV file instead of playing it: everything `f`
plays or starts, with times from 0.0, through the channels as they are
set, much faster than it would play. The file is offered to the reader
to save, and `on_rendered` is called with how long rendering took and
how loud its loudest moment is.

<p class="pyk-api-label">Parameters</p>

- `seconds`: how long the file is.
- `f`: what plays the sound, with `at` from 0.0.
- `name`: the file's name.
- `on_rendered`: what is called with the seconds rendering took and the peak level, 0.0 to 1.0.

<p class="pyk-api-label">Example</p>

```pyking
import tinyweb as tw
import tinyweb.sound as sound
tw.web_init(0)
kick = tw.load_sample("kick1.wav")
def beat():
    for k in range(4):
        tw.play(kick, at = float(k) * 0.5)
def done(took: Float, peak: Float):
    print("rendered in", took)
sound.render_wav(2.0, beat, name = "beat.wav", on_rendered = done)
```

</div>
