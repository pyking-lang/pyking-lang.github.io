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

static int pyk_int_of_string(const char *s)
{
    const char *p = s;
    double value = 0.0;
    int negative = 0;
    if (*p == '-' || *p == '+') {
        negative = *p == '-';
        p++;
    }
    if (*p == '\0') {
        return 0;
    }
    for (; *p != '\0'; p++) {
        if (*p < '0' || *p > '9') {
            return 0;
        }
        value = value * 10.0 + (*p - '0');
        if (value > 2147483648.0) {
            return 0;
        }
    }
    if (negative) {
        value = -value;
    }
    if (value > 2147483647.0) {
        return 0;
    }
    return (int)value;
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
static const char *floats3(double a, double b, double c);
static const char *floats4(double a, double b, double c, double d);
static const char *bit(bool on);
void tinyweb_web_init(int port);
const char *tinyweb_button(const char *title, pyk_c_F_u_ on_click);
void tinyweb_on_click(const char *c, pyk_c_Fii_u_ f);
static const char *sound__settings(double at, double volume, double rate, double pan, pyk_d_Dtinyweb_Sound__Voice__ voice);
pyk_d_Dtinyweb_Sound__Voice__ tinyweb_play__default__voice(void);
void tinyweb_play(const char *sample, double at, double volume, double rate, double pan, pyk_d_Dtinyweb_Sound__Voice__ voice);
pyk_d_Dtinyweb_Sound__Voice__ tinyweb_sound__start__default__voice(void);
const char *tinyweb_sound__start(const char *sample, double at, double volume, double rate, double pan, bool looping, pyk_d_Dtinyweb_Sound__Voice__ voice);
void tinyweb_sound__stop(const char *voice, double at);
void tinyweb_sound__fade(const char *voice, double volume, double over);
void tinyweb_sound__stop_all(void);
void tinyweb_sound__master_volume(double volume);
void tinyweb_sound__tone(double frequency, double at, double duration, const char *wave, double volume, double pan, int channel);
double tinyweb_sound__note(const char *name);
double tinyweb_sound__rate_of(const char *name, const char *base);
static int sound__semitones(const char *name);
void tinyweb_sound__channel_style(int channel, double volume, double pan, double echo, double echo_time, double feedback, double reverb, double low_pass);

static const char *floats2(double a, double b)
{
    return pyk_concat(pyk_concat(pyk_float_str(a), " "), pyk_float_str(b));
}

static const char *floats3(double a, double b, double c)
{
    return pyk_concat(pyk_concat(floats2(a, b), " "), pyk_float_str(c));
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

pyk_d_Dtinyweb_Sound__Voice__ tinyweb_sound__start__default__voice(void)
{
    return pyk_mk_Dtinyweb_Sound__Voice___Sound__Voice(1.0, 1.0, 0.0, 0, false, false);
}

const char *tinyweb_sound__start(const char *sample, double at, double volume, double rate, double pan, bool looping, pyk_d_Dtinyweb_Sound__Voice__ voice)
{
    const char *id = tinyweb_fresh_id("voice");
    bool looped = looping ? true : voice.looping;
    tinyweb_command("start", id, sample, pyk_concat(pyk_concat(sound__settings(at, volume, rate, pan, voice), " "), bit(looped)), 2);
    return id;
}

void tinyweb_sound__stop(const char *voice, double at)
{
    tinyweb_command("stop", voice, "", pyk_float_str(at), 2);
}

void tinyweb_sound__fade(const char *voice, double volume, double over)
{
    tinyweb_command("fade", voice, "", floats2(volume, over), 2);
}

void tinyweb_sound__stop_all(void)
{
    tinyweb_command("stop_all", "", "", "", 2);
}

void tinyweb_sound__master_volume(double volume)
{
    tinyweb_command("master", "", "", pyk_float_str(volume), 1);
}

void tinyweb_sound__tone(double frequency, double at, double duration, const char *wave, double volume, double pan, int channel)
{
    tinyweb_command("tone", "", wave, pyk_concat(pyk_concat(pyk_concat(pyk_concat(floats4(frequency, at, duration, volume), " "), pyk_float_str(pan)), " "), pyk_int_str(channel)), 2);
}

double tinyweb_sound__note(const char *name)
{
    int semitones = sound__semitones(name);
    return semitones < -1000 ? 0.0 : 440.0 * math_pow(2.0, (double)(semitones - 57) / 12.0);
}

double tinyweb_sound__rate_of(const char *name, const char *base)
{
    int origin = sound__semitones(base);
    int target = sound__semitones(name);
    return origin < -1000 ? 1.0 : target < -1000 ? 1.0 : math_pow(2.0, (double)(target - origin) / 12.0);
}

static int sound__semitones(const char *name)
{
    int pyk_v1;
    const char *pyk_s2 = text_upper(text_char_at(name, 0));
    if (strcmp(pyk_s2, "C") == 0) {
        {
            pyk_v1 = 0;
        }
    } else if (strcmp(pyk_s2, "D") == 0) {
        {
            pyk_v1 = 2;
        }
    } else if (strcmp(pyk_s2, "E") == 0) {
        {
            pyk_v1 = 4;
        }
    } else if (strcmp(pyk_s2, "F") == 0) {
        {
            pyk_v1 = 5;
        }
    } else if (strcmp(pyk_s2, "G") == 0) {
        {
            pyk_v1 = 7;
        }
    } else if (strcmp(pyk_s2, "A") == 0) {
        {
            pyk_v1 = 9;
        }
    } else if (strcmp(pyk_s2, "B") == 0) {
        {
            pyk_v1 = 11;
        }
    } else {
        {
            pyk_v1 = -10000;
        }
    }
    int base = pyk_v1;
    int pyk_v3;
    const char *pyk_s4 = text_char_at(name, 1);
    if (strcmp(pyk_s4, "#") == 0) {
        {
            pyk_v3 = 1;
        }
    } else if (strcmp(pyk_s4, "b") == 0) {
        {
            pyk_v3 = -1;
        }
    } else {
        {
            pyk_v3 = 0;
        }
    }
    int shift = pyk_v3;
    const char *rest = text_slice(name, shift == 0 ? 1 : 2, text_length(name));
    int octave = strcmp(rest, "") == 0 ? 4 : pyk_int_of_string(rest);
    bool valid = base < 0 ? false : strcmp(rest, "") == 0 ? true : strcmp(pyk_int_str(octave), rest) == 0;
    return valid ? base + shift + octave * 12 : -10000;
}

void tinyweb_sound__channel_style(int channel, double volume, double pan, double echo, double echo_time, double feedback, double reverb, double low_pass)
{
    tinyweb_command("channel", pyk_int_str(channel), "", pyk_concat(pyk_concat(floats4(volume, pan, echo, echo_time), " "), floats3(feedback, reverb, low_pass)), 1);
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
