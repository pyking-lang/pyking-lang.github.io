// Generated from lib_tinyweb_voices.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

// Every multiply and add rounded on its own, as on every other target.
#if defined(__clang__)
#pragma STDC FP_CONTRACT OFF
#elif defined(__GNUC__)
#pragma GCC optimize ("fp-contract=off")
#endif

#include "math.h"
#include "text.h"
#include "tinyweb.h"

#ifndef PYK_TYPE_PYK_D_DTINYWEB_SOUND__VOICE__
#define PYK_TYPE_PYK_D_DTINYWEB_SOUND__VOICE__
typedef struct pyk_d_Dtinyweb_Sound__Voice__ {
    double volume;
    double rate;
    double pan;
    int channel;
    bool looping;
    bool reverse;
} pyk_d_Dtinyweb_Sound__Voice__;
#endif

#ifndef PYK_TYPE_PYK_C_F_U_
#define PYK_TYPE_PYK_C_F_U_
typedef struct pyk_c_F_u_ {
    void (*fn)(void *);
    void *env;
    void (*plain)(void);
} pyk_c_F_u_;
#endif

// What the external modules this one imports implement.
const char *tinyweb_load_sample(const char *);
void tinyweb_splash(void);

static pyk_d_Dtinyweb_Sound__Voice__ pyk_mk_Dtinyweb_Sound__Voice___Sound__Voice(double volume, double rate, double pan, int channel, bool looping, bool reverse)
{
    pyk_d_Dtinyweb_Sound__Voice__ v;
    v.volume = volume;
    v.rate = rate;
    v.pan = pan;
    v.channel = channel;
    v.looping = looping;
    v.reverse = reverse;
    return v;
}

static const char *pyk_float_str(double x)
{
    char buf[64];
    char digits[32];
    char *out = malloc(64);
    double a;
    int negative, p, at, i, n, decpt, k;
    const char *e;
    if (x != x) { strcpy(out, "nan"); return out; }
    if (x > DBL_MAX) { strcpy(out, "inf"); return out; }
    if (x < -DBL_MAX) { strcpy(out, "-inf"); return out; }
    negative = x < 0.0 || (x == 0.0 && 1.0 / x < 0.0);
    a = negative ? -x : x;
    if (a == 0.0) { strcpy(out, negative ? "-0.0" : "0.0"); return out; }
    for (p = 0; p < 16; p++) {
        sprintf(buf, "%.*e", p, a);
        if (strtod(buf, NULL) == a) break;
    }
    if (p == 16) sprintf(buf, "%.*e", 16, a);
    e = strchr(buf, 'e');
    at = (int)(e - buf);
    n = 0;
    for (i = 0; i < at; i++) if (buf[i] != '.') digits[n++] = buf[i];
    while (n > 1 && digits[n - 1] == '0') n--;
    digits[n] = '\0';
    decpt = atoi(e + 1) + 1;
    k = 0;
    if (negative) out[k++] = '-';
    if (decpt <= -4 || decpt > 16) {
        out[k++] = digits[0];
        if (n > 1) { out[k++] = '.'; strcpy(out + k, digits + 1); k += n - 1; }
        sprintf(out + k, "e%d", decpt - 1);
        return out;
    }
    if (decpt <= 0) {
        out[k++] = '0';
        out[k++] = '.';
        for (i = 0; i < -decpt; i++) out[k++] = '0';
        strcpy(out + k, digits);
        return out;
    }
    if (decpt >= n) {
        strcpy(out + k, digits);
        k += n;
        for (i = 0; i < decpt - n; i++) out[k++] = '0';
        strcpy(out + k, ".0");
        return out;
    }
    for (i = 0; i < decpt; i++) out[k++] = digits[i];
    out[k++] = '.';
    strcpy(out + k, digits + decpt);
    return out;
}

static pyk_c_F_u_ pyk_mk_F_u_(void (*fn)(void *), void *env, void (*plain)(void))
{
    pyk_c_F_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static const char *kick;
static const char *piano;
static pyk_d_Dtinyweb_Sound__Voice__ soft;
static const char *hum;
static const char *other;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void quieter(void);
static void stop(void);
static void silence(void);

static void pyk_w_quieter(void *env)
{
    (void)env;
    quieter();
}

static void pyk_w_stop(void *env)
{
    (void)env;
    stop();
}

static void pyk_w_silence(void *env)
{
    (void)env;
    silence();
}

static void quieter(void)
{
    tinyweb_sound__fade(hum, 0.0, 2.0);
    printf("%s\n", "fading");
}

static void stop(void)
{
    tinyweb_sound__stop(other, 0.0);
    tinyweb_sound__stop(hum, 3.0);
    printf("%s\n", "stopped");
}

static void silence(void)
{
    tinyweb_sound__stop_all();
    printf("%s\n", "silence");
}

int main(void)
{
    double pyk_t1;
    double pyk_t2;
    double pyk_t3;
    double pyk_t4;
    double pyk_t5;
    double pyk_t6;
    double pyk_t7;
    double pyk_t8;
    math_init();
    text_init();
    tinyweb_init();
    tinyweb_web_init(0);
    kick = tinyweb_load_sample("kick1.wav");
    piano = tinyweb_load_sample("piano_c1.wav");
    tinyweb_sound__master_volume(0.8);
    tinyweb_sound__channel_style(1, 0.7, -0.5, 0.4, 0.25, 0.5, 0.0, 0.0);
    tinyweb_sound__channel_style(2, 1.0, 0.0, 0.0, 0.3, 0.35, 0.6, 1200.0);
    tinyweb_sound__channel_style(1, 0.9, 0.0, 0.0, 0.3, 0.35, 0.0, 0.0);
    tinyweb_play(kick, 0.0, 1.0, 1.0, 0.0, tinyweb_play__default__voice());
    tinyweb_play(kick, 0.5, 0.5, 2.0, 1.0, tinyweb_play__default__voice());
    soft = pyk_mk_Dtinyweb_Sound__Voice___Sound__Voice(0.25, 1.0, 0.0, 1, false, false);
    tinyweb_play(kick, 0.0, 1.0, 1.0, 0.0, soft);
    tinyweb_play(kick, 0.0, 0.75, 1.0, 0.0, soft);
    tinyweb_play(piano, 0.0, 1.0, 1.0, 0.0, pyk_mk_Dtinyweb_Sound__Voice___Sound__Voice(1.0, 1.0, 0.0, 2, false, true));
    hum = tinyweb_sound__start(piano, 0.0, 0.3, 1.0, 0.0, true, tinyweb_sound__start__default__voice());
    other = tinyweb_sound__start(piano, 1.0, 1.0, 1.0, 0.0, false, pyk_mk_Dtinyweb_Sound__Voice___Sound__Voice(1.0, 0.5, 0.0, 2, true, false));
    printf("%s %s\n", hum, other);
    tinyweb_sound__tone(440.0, 0.0, 0.5, "sine", 0.5, 0.0, 0);
    tinyweb_sound__tone(tinyweb_sound__note("C5"), 0.25, 0.125, "square", 0.2, 0.5, 1);
    (pyk_t1 = tinyweb_sound__note("A4"), pyk_t2 = tinyweb_sound__note("C4"), pyk_t3 = tinyweb_sound__note("C#4"), pyk_t4 = tinyweb_sound__note("Db4"), pyk_t5 = tinyweb_sound__note("H2"), printf("%s %s %s %s %s %s\n", pyk_float_str(pyk_t1), pyk_float_str(pyk_t2), pyk_float_str(pyk_t3), pyk_float_str(pyk_t4), pyk_float_str(pyk_t5), pyk_float_str(tinyweb_sound__note("C"))));
    (pyk_t6 = tinyweb_sound__rate_of("C5", "C4"), pyk_t7 = tinyweb_sound__rate_of("C3", "C4"), pyk_t8 = tinyweb_sound__rate_of("G4", "G3"), printf("%s %s %s %s\n", pyk_float_str(pyk_t6), pyk_float_str(pyk_t7), pyk_float_str(pyk_t8), pyk_float_str(tinyweb_sound__rate_of("nothing", "C4"))));
    tinyweb_button("Quieter", pyk_mk_F_u_(pyk_w_quieter, NULL, quieter));
    tinyweb_button("Stop", pyk_mk_F_u_(pyk_w_stop, NULL, stop));
    tinyweb_button("Silence", pyk_mk_F_u_(pyk_w_silence, NULL, silence));
    tinyweb_splash();

    return 0;
}
