// Generated from lib_tinyweb_beat.pyk by the Pyking compiler. Do not edit.
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

#ifndef PYK_TYPE_PYK_C_FIF_U_
#define PYK_TYPE_PYK_C_FIF_U_
typedef struct pyk_c_Fif_u_ {
    void (*fn)(void *, int, double);
    void *env;
    void (*plain)(int, double);
} pyk_c_Fif_u_;
#endif

#ifndef PYK_TYPE_PYK_C_F_U_
#define PYK_TYPE_PYK_C_F_U_
typedef struct pyk_c_F_u_ {
    void (*fn)(void *);
    void *env;
    void (*plain)(void);
} pyk_c_F_u_;
#endif

#ifndef PYK_TYPE_PYK_C_FB_U_
#define PYK_TYPE_PYK_C_FB_U_
typedef struct pyk_c_Fb_u_ {
    void (*fn)(void *, bool);
    void *env;
    void (*plain)(bool);
} pyk_c_Fb_u_;
#endif

#ifndef PYK_TYPE_PYK_C_FFF_U_
#define PYK_TYPE_PYK_C_FFF_U_
typedef struct pyk_c_Fff_u_ {
    void (*fn)(void *, double, double);
    void *env;
    void (*plain)(double, double);
} pyk_c_Fff_u_;
#endif

// What the external modules this one imports implement.
const char *tinyweb_load_sample(const char *);
void tinyweb_splash(void);

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

static pyk_c_Fif_u_ pyk_mk_Fif_u_(void (*fn)(void *, int, double), void *env, void (*plain)(int, double))
{
    pyk_c_Fif_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static pyk_c_F_u_ pyk_mk_F_u_(void (*fn)(void *), void *env, void (*plain)(void))
{
    pyk_c_F_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static pyk_c_Fb_u_ pyk_mk_Fb_u_(void (*fn)(void *, bool), void *env, void (*plain)(bool))
{
    pyk_c_Fb_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static pyk_c_Fff_u_ pyk_mk_Fff_u_(void (*fn)(void *, double, double), void *env, void (*plain)(double, double))
{
    pyk_c_Fff_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static const char *kick;
static const char *hat;
static const char *steps;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void step(int n, double time);
static void listened(void);
static void toggle(bool on);
static void song(void);
static void done(double took, double peak);

static void pyk_w_step(void *env, int p1, double p2)
{
    (void)env;
    step(p1, p2);
}

static void pyk_w_listened(void *env)
{
    (void)env;
    listened();
}

static void pyk_w_toggle(void *env, bool p1)
{
    (void)env;
    toggle(p1);
}

static void pyk_w_song(void *env)
{
    (void)env;
    song();
}

static void pyk_w_done(void *env, double p1, double p2)
{
    (void)env;
    done(p1, p2);
}

static void step(int n, double time)
{
    printf("%s %d %s %s %s %s\n", "step", n, "at", pyk_float_str(time), "beat", pyk_float_str(tinyweb_sound__beat()));
    if (n - n / 4 * 4 == 0) {
        tinyweb_play(kick, time, 1.0, 1.0, 0.0, tinyweb_play__default__voice());
    }
    tinyweb_play(hat, time, 0.3, 1.0, 0.0, tinyweb_play__default__voice());
    if (n == 2) {
        tinyweb_sound__tempo(90.0);
    }
}

static void listened(void)
{
    double pyk_t1;
    int pyk_t2;
    double pyk_t3;
    double pyk_t4;
    double pyk_t5;
    (pyk_t1 = tinyweb_sound__level(), pyk_t2 = tinyweb_sound__bands(), pyk_t3 = tinyweb_sound__band(0), pyk_t4 = tinyweb_sound__band(7), pyk_t5 = tinyweb_sound__wave(0), printf("%s %s %s %d %s %s %s %s %s\n", "level", pyk_float_str(pyk_t1), "bands", pyk_t2, pyk_float_str(pyk_t3), pyk_float_str(pyk_t4), "wave", pyk_float_str(pyk_t5), pyk_float_str(tinyweb_sound__wave(3))));
}

static void toggle(bool on)
{
    if (on) {
        tinyweb_sound__resume();
    } else {
        tinyweb_sound__pause();
    }
    printf("%s %s\n", "playing", (on ? "true" : "false"));
}

static void song(void)
{
    tinyweb_play(kick, 0.0, 1.0, 1.0, 0.0, tinyweb_play__default__voice());
    tinyweb_play(kick, 0.5, 1.0, 1.0, 0.0, tinyweb_play__default__voice());
    tinyweb_sound__tone(220.0, 1.0, 0.25, "sine", 0.5, 0.0, 0);
}

static void done(double took, double peak)
{
    printf("%s %s %s %s\n", "rendered in", pyk_float_str(took), "seconds, peak", pyk_float_str(peak));
}

int main(void)
{
    math_init();
    text_init();
    tinyweb_init();
    tinyweb_web_init(0);
    kick = tinyweb_load_sample("kick1.wav");
    hat = tinyweb_load_sample("hihat1.wav");
    tinyweb_sound__tempo(120.0);
    tinyweb_sound__swing(0.2);
    tinyweb_sound__listen(8, 0.5);
    steps = tinyweb_sound__on_beat(pyk_mk_Fif_u_(pyk_w_step, NULL, step), 2);
    printf("%s\n", steps);
    tinyweb_button("Listen", pyk_mk_F_u_(pyk_w_listened, NULL, listened));
    tinyweb_checkbox("Playing", true, pyk_mk_Fb_u_(pyk_w_toggle, NULL, toggle));
    tinyweb_sound__render_wav(2.0, pyk_mk_F_u_(pyk_w_song, NULL, song), "song.wav", pyk_mk_Fff_u_(pyk_w_done, NULL, done));
    tinyweb_sound__render_wav(1.0, pyk_mk_F_u_(pyk_w_song, NULL, song), "tinyweb.wav", tinyweb_sound__render_wav__default__on_rendered());
    printf("%s %s\n", "latency", pyk_float_str(tinyweb_sound__latency()));
    tinyweb_splash();

    return 0;
}
