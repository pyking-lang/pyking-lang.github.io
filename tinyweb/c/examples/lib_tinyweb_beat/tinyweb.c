// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
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

#include "tinyweb.h"
#include "math.h"
#include "text.h"

#ifndef PYK_TYPE_PYK_D_DTINYWEB_COLOR__COLOR__
#define PYK_TYPE_PYK_D_DTINYWEB_COLOR__COLOR__
typedef struct pyk_d_Dtinyweb_Color__Color__ {
    int r;
    int g;
    int b;
    double a;
} pyk_d_Dtinyweb_Color__Color__;
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

#ifndef PYK_TYPE_PYK_C_FII_U_
#define PYK_TYPE_PYK_C_FII_U_
typedef struct pyk_c_Fii_u_ {
    void (*fn)(void *, int, int);
    void *env;
    void (*plain)(int, int);
} pyk_c_Fii_u_;
#endif

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

#ifndef PYK_TYPE_PYK_C_FIF_U_
#define PYK_TYPE_PYK_C_FIF_U_
typedef struct pyk_c_Fif_u_ {
    void (*fn)(void *, int, double);
    void *env;
    void (*plain)(int, double);
} pyk_c_Fif_u_;
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
void tinyweb_web_start(int);
const char *tinyweb_canvas(int, int);
void tinyweb_fill_canvas(const char *, const char *);
void tinyweb_draw_shape(const char *, const char *, const char *, const char *, const char *, double, double);
void tinyweb_draw_text(const char *, double, double, const char *, const char *, int, const char *, const char *, const char *, bool, const char *, double, double);
void tinyweb_set_state(const char *, const char *, const char *, const char *);
#ifndef PYK_FN_F_V
#define PYK_FN_F_V
typedef void (*pyk_fn_f_v)(double);
#endif
void tinyweb_measure(const char *, int, const char *, bool, pyk_fn_f_v);
#ifndef PYK_FN_II_V
#define PYK_FN_II_V
typedef void (*pyk_fn_ii_v)(int, int);
#endif
void tinyweb_watch_pointer(const char *, const char *, pyk_fn_ii_v);
int tinyweb_pointer(const char *, const char *);
void tinyweb_draw_image(const char *, const char *, int, int, int, int, double);
const char *tinyweb_make_bitmap(int, int, int);
void tinyweb_set_pixel(const char *, int, int, int);
int tinyweb_get_pixel(const char *, int, int);
void tinyweb_fill_bitmap(const char *, int);
void tinyweb_draw_bitmap(const char *, const char *, int, int, double);
const char *tinyweb_load_image(const char *);
#ifndef PYK_FN__V
#define PYK_FN__V
typedef void (*pyk_fn__v)(void);
#endif
const char *tinyweb_make_button(const char *, pyk_fn__v);
const char *tinyweb_label(const char *);
const char *tinyweb_row(void);
const char *tinyweb_column(void);
void tinyweb_inside(const char *);
void tinyweb_outside(void);
void tinyweb_set_label(const char *, const char *);
#ifndef PYK_FN_I_V
#define PYK_FN_I_V
typedef void (*pyk_fn_i_v)(int);
#endif
const char *tinyweb_make_slider(int, int, int, pyk_fn_i_v);
#ifndef PYK_FN_B_V
#define PYK_FN_B_V
typedef void (*pyk_fn_b_v)(bool);
#endif
const char *tinyweb_make_checkbox(const char *, bool, pyk_fn_b_v);
#ifndef PYK_FN_S_V
#define PYK_FN_S_V
typedef void (*pyk_fn_s_v)(const char *);
#endif
const char *tinyweb_make_radio(const char *, const char *, bool, pyk_fn_s_v);
#ifndef PYK_FN_I_V
#define PYK_FN_I_V
typedef void (*pyk_fn_i_v)(int);
#endif
const char *tinyweb_make_choice(const char *, int, pyk_fn_i_v);
#ifndef PYK_FN_S_V
#define PYK_FN_S_V
typedef void (*pyk_fn_s_v)(const char *);
#endif
const char *tinyweb_make_text_input(const char *, pyk_fn_s_v);
#ifndef PYK_FN_I_V
#define PYK_FN_I_V
typedef void (*pyk_fn_i_v)(int);
#endif
const char *tinyweb_make_number_input(int, int, int, pyk_fn_i_v);
void tinyweb_set_checked(const char *, bool);
void tinyweb_set_value(const char *, int);
void tinyweb_apply_style(const char *, const char *, const char *, const char *);
const char *tinyweb_load_sample(const char *);
const char *tinyweb_fresh_id(const char *);
void tinyweb_command(const char *, const char *, const char *, const char *, int);
#ifndef PYK_FN__V
#define PYK_FN__V
typedef void (*pyk_fn__v)(void);
#endif
void tinyweb_watch(const char *, const char *, pyk_fn__v);
double tinyweb_report_number(const char *, int);
const char *tinyweb_report_text(const char *);
int tinyweb_report_count(const char *);
#ifndef PYK_FN_S_V
#define PYK_FN_S_V
typedef void (*pyk_fn_s_v)(const char *);
#endif
void tinyweb_watch_text(const char *, const char *, const char *, pyk_fn_s_v);
#ifndef PYK_FN_IF_V
#define PYK_FN_IF_V
typedef void (*pyk_fn_if_v)(int, double);
#endif
void tinyweb_watch_step(const char *, const char *, pyk_fn_if_v);
#ifndef PYK_FN_FF_V
#define PYK_FN_FF_V
typedef void (*pyk_fn_ff_v)(double, double);
#endif
void tinyweb_watch_pair(const char *, const char *, pyk_fn_ff_v);
void tinyweb_splash(void);
void tinyweb_set_splash(const char *);
double tinyweb_time(void);
void tinyweb_sdelay(double);
#ifndef PYK_FN_F_V
#define PYK_FN_F_V
typedef void (*pyk_fn_f_v)(double);
#endif
void tinyweb_on_frame(pyk_fn_f_v);
#ifndef PYK_FN_II_V
#define PYK_FN_II_V
typedef void (*pyk_fn_ii_v)(int, int);
#endif
void tinyweb_on_mouse(const char *, pyk_fn_ii_v);
#ifndef PYK_FN_S_V
#define PYK_FN_S_V
typedef void (*pyk_fn_s_v)(const char *);
#endif
void tinyweb_on_key(pyk_fn_s_v);
#ifndef PYK_FN_S_V
#define PYK_FN_S_V
typedef void (*pyk_fn_s_v)(const char *);
#endif
void tinyweb_on_key_up(pyk_fn_s_v);
bool tinyweb_key_down(const char *);

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

static const char *pyk_concat(const char *a, const char *b)
{
    size_t la = strlen(a);
    size_t lb = strlen(b);
    char *result = malloc(la + lb + 1);
    memcpy(result, a, la);
    memcpy(result + la, b, lb + 1);
    return result;
}

static pyk_d_Dtinyweb_Color__Color__ pyk_mk_Dtinyweb_Color__Color___Color__Color(int r, int g, int b, double a)
{
    pyk_d_Dtinyweb_Color__Color__ v;
    v.r = r;
    v.g = g;
    v.b = b;
    v.a = a;
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

static pyk_fn__v pyk_plain_F_u_(pyk_c_F_u_ c)
{
    if (c.plain == NULL) {
        fprintf(stderr, "a function that captures values cannot be handed to a module implemented in C\n");
        exit(1);
    }
    return c.plain;
}

static pyk_c_Fb_u_ pyk_mk_Fb_u_(void (*fn)(void *, bool), void *env, void (*plain)(bool))
{
    pyk_c_Fb_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static pyk_fn_b_v pyk_plain_Fb_u_(pyk_c_Fb_u_ c)
{
    if (c.plain == NULL) {
        fprintf(stderr, "a function that captures values cannot be handed to a module implemented in C\n");
        exit(1);
    }
    return c.plain;
}

static pyk_c_Fii_u_ pyk_mk_Fii_u_(void (*fn)(void *, int, int), void *env, void (*plain)(int, int))
{
    pyk_c_Fii_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static pyk_fn_ii_v pyk_plain_Fii_u_(pyk_c_Fii_u_ c)
{
    if (c.plain == NULL) {
        fprintf(stderr, "a function that captures values cannot be handed to a module implemented in C\n");
        exit(1);
    }
    return c.plain;
}

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

static const char *pyk_int_str(int n)
{
    char *out = malloc(24);
    sprintf(out, "%d", n);
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

static pyk_fn_if_v pyk_plain_Fif_u_(pyk_c_Fif_u_ c)
{
    if (c.plain == NULL) {
        fprintf(stderr, "a function that captures values cannot be handed to a module implemented in C\n");
        exit(1);
    }
    return c.plain;
}

static pyk_c_Fff_u_ pyk_mk_Fff_u_(void (*fn)(void *, double, double), void *env, void (*plain)(double, double))
{
    pyk_c_Fff_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static pyk_fn_ff_v pyk_plain_Fff_u_(pyk_c_Fff_u_ c)
{
    if (c.plain == NULL) {
        fprintf(stderr, "a function that captures values cannot be handed to a module implemented in C\n");
        exit(1);
    }
    return c.plain;
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_color__black;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__white;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__gray;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__red;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__green;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__blue;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__yellow;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__orange;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__purple;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__pink;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__navy;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__teal;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__brown;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__cyan;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__magenta;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__none;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__theme;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static const char *floats2(double a, double b);
static const char *floats4(double a, double b, double c, double d);
static const char *bit(bool on);
void tinyweb_web_init(int port);
const char *tinyweb_button(const char *title, pyk_c_F_u_ on_click);
const char *tinyweb_checkbox(const char *title, bool checked, pyk_c_Fb_u_ on_change);
void tinyweb_on_click(const char *c, pyk_c_Fii_u_ f);
static const char *sound__settings(double at, double volume, double rate, double pan, pyk_d_Dtinyweb_Sound__Voice__ voice);
pyk_d_Dtinyweb_Sound__Voice__ tinyweb_play__default__voice(void);
void tinyweb_play(const char *sample, double at, double volume, double rate, double pan, pyk_d_Dtinyweb_Sound__Voice__ voice);
void tinyweb_sound__tone(double frequency, double at, double duration, const char *wave, double volume, double pan, int channel);
void tinyweb_sound__tempo(double bpm);
void tinyweb_sound__swing(double amount);
const char *tinyweb_sound__on_beat(pyk_c_Fif_u_ f, int steps);
double tinyweb_sound__beat(void);
double tinyweb_sound__latency(void);
void tinyweb_sound__pause(void);
void tinyweb_sound__resume(void);
void tinyweb_sound__listen(int bins, double smoothing);
double tinyweb_sound__level(void);
double tinyweb_sound__band(int k);
int tinyweb_sound__bands(void);
double tinyweb_sound__wave(int k);
pyk_c_Fff_u_ tinyweb_sound__render_wav__default__on_rendered(void);
void tinyweb_sound__render_wav(double seconds, pyk_c_F_u_ f, const char *name, pyk_c_Fff_u_ on_rendered);
static void sound__ignore_rendered(double took, double peak);

static void pyk_w_sound__ignore_rendered(void *env, double p1, double p2)
{
    (void)env;
    sound__ignore_rendered(p1, p2);
}

static const char *floats2(double a, double b)
{
    return pyk_concat(pyk_concat(pyk_float_str(a), " "), pyk_float_str(b));
}

static const char *floats4(double a, double b, double c, double d)
{
    return pyk_concat(pyk_concat(floats2(a, b), " "), floats2(c, d));
}

static const char *bit(bool on)
{
    return on ? "1" : "0";
}

void tinyweb_web_init(int port)
{
    tinyweb_web_start(port);
}

const char *tinyweb_button(const char *title, pyk_c_F_u_ on_click)
{
    return tinyweb_make_button(title, pyk_plain_F_u_(on_click));
}

const char *tinyweb_checkbox(const char *title, bool checked, pyk_c_Fb_u_ on_change)
{
    return tinyweb_make_checkbox(title, checked, pyk_plain_Fb_u_(on_change));
}

void tinyweb_on_click(const char *c, pyk_c_Fii_u_ f)
{
    tinyweb_on_mouse(c, pyk_plain_Fii_u_(f));
}

static const char *sound__settings(double at, double volume, double rate, double pan, pyk_d_Dtinyweb_Sound__Voice__ voice)
{
    double v = volume == 1.0 ? voice.volume : volume;
    double r = rate == 1.0 ? voice.rate : rate;
    double p = pan == 0.0 ? voice.pan : pan;
    return pyk_concat(pyk_concat(pyk_concat(pyk_concat(floats4(at, v, r, p), " "), pyk_int_str(voice.channel)), " "), bit(voice.reverse));
}

pyk_d_Dtinyweb_Sound__Voice__ tinyweb_play__default__voice(void)
{
    return pyk_mk_Dtinyweb_Sound__Voice___Sound__Voice(1.0, 1.0, 0.0, 0, false, false);
}

void tinyweb_play(const char *sample, double at, double volume, double rate, double pan, pyk_d_Dtinyweb_Sound__Voice__ voice)
{
    tinyweb_command("play", sample, "", sound__settings(at, volume, rate, pan, voice), 2);
}

void tinyweb_sound__tone(double frequency, double at, double duration, const char *wave, double volume, double pan, int channel)
{
    tinyweb_command("tone", "", wave, pyk_concat(pyk_concat(pyk_concat(pyk_concat(floats4(frequency, at, duration, volume), " "), pyk_float_str(pan)), " "), pyk_int_str(channel)), 2);
}

void tinyweb_sound__tempo(double bpm)
{
    tinyweb_command("tempo", "", "", pyk_float_str(bpm), 1);
}

void tinyweb_sound__swing(double amount)
{
    tinyweb_command("swing", "", "", pyk_float_str(amount), 1);
}

const char *tinyweb_sound__on_beat(pyk_c_Fif_u_ f, int steps)
{
    const char *id = tinyweb_fresh_id("beat");
    tinyweb_watch_step(id, "beat", pyk_plain_Fif_u_(f));
    tinyweb_command("beat", id, "", pyk_int_str(steps), 0);
    return id;
}

double tinyweb_sound__beat(void)
{
    return tinyweb_report_number("clock", 0);
}

double tinyweb_sound__latency(void)
{
    return tinyweb_report_number("clock", 1);
}

void tinyweb_sound__pause(void)
{
    tinyweb_command("audio", "", "pause", "", 2);
}

void tinyweb_sound__resume(void)
{
    tinyweb_command("audio", "", "resume", "", 2);
}

void tinyweb_sound__listen(int bins, double smoothing)
{
    tinyweb_command("listen", "", "", pyk_concat(pyk_concat(pyk_int_str(bins), " "), pyk_float_str(smoothing)), 1);
}

double tinyweb_sound__level(void)
{
    return tinyweb_report_number("level", 0);
}

double tinyweb_sound__band(int k)
{
    return tinyweb_report_number("band", k);
}

int tinyweb_sound__bands(void)
{
    return tinyweb_report_count("band");
}

double tinyweb_sound__wave(int k)
{
    return tinyweb_report_number("wave", k);
}

pyk_c_Fff_u_ tinyweb_sound__render_wav__default__on_rendered(void)
{
    return pyk_mk_Fff_u_(pyk_w_sound__ignore_rendered, NULL, sound__ignore_rendered);
}

void tinyweb_sound__render_wav(double seconds, pyk_c_F_u_ f, const char *name, pyk_c_Fff_u_ on_rendered)
{
    const char *id = tinyweb_fresh_id("render");
    tinyweb_watch_pair(id, "rendered", pyk_plain_Fff_u_(on_rendered));
    tinyweb_command("render", id, name, pyk_float_str(seconds), 2);
    f.fn(f.env);
    tinyweb_command("render_end", id, "", "", 2);
}

static void sound__ignore_rendered(double took, double peak)
{

}

void tinyweb_init(void)
{
    tinyweb_color__black = pyk_mk_Dtinyweb_Color__Color___Color__Color(0, 0, 0, 1.0);
    tinyweb_color__white = pyk_mk_Dtinyweb_Color__Color___Color__Color(255, 255, 255, 1.0);
    tinyweb_color__gray = pyk_mk_Dtinyweb_Color__Color___Color__Color(128, 128, 128, 1.0);
    tinyweb_color__red = pyk_mk_Dtinyweb_Color__Color___Color__Color(255, 0, 0, 1.0);
    tinyweb_color__green = pyk_mk_Dtinyweb_Color__Color___Color__Color(0, 128, 0, 1.0);
    tinyweb_color__blue = pyk_mk_Dtinyweb_Color__Color___Color__Color(0, 0, 255, 1.0);
    tinyweb_color__yellow = pyk_mk_Dtinyweb_Color__Color___Color__Color(255, 255, 0, 1.0);
    tinyweb_color__orange = pyk_mk_Dtinyweb_Color__Color___Color__Color(255, 165, 0, 1.0);
    tinyweb_color__purple = pyk_mk_Dtinyweb_Color__Color___Color__Color(128, 0, 128, 1.0);
    tinyweb_color__pink = pyk_mk_Dtinyweb_Color__Color___Color__Color(255, 192, 203, 1.0);
    tinyweb_color__navy = pyk_mk_Dtinyweb_Color__Color___Color__Color(0, 0, 128, 1.0);
    tinyweb_color__teal = pyk_mk_Dtinyweb_Color__Color___Color__Color(0, 128, 128, 1.0);
    tinyweb_color__brown = pyk_mk_Dtinyweb_Color__Color___Color__Color(139, 69, 19, 1.0);
    tinyweb_color__cyan = pyk_mk_Dtinyweb_Color__Color___Color__Color(0, 255, 255, 1.0);
    tinyweb_color__magenta = pyk_mk_Dtinyweb_Color__Color___Color__Color(255, 0, 255, 1.0);
    tinyweb_color__none = pyk_mk_Dtinyweb_Color__Color___Color__Color(0, 0, 0, 0.0);
    tinyweb_color__theme = pyk_mk_Dtinyweb_Color__Color___Color__Color(-1, -1, -1, -1.0);
}
