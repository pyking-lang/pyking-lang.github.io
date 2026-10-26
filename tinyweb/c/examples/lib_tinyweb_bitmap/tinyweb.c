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
static int color__part(int n);
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__rgb(int r, int g, int b);
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__hex(int n);
int tinyweb_color__to_hex(pyk_d_Dtinyweb_Color__Color__ c);
void tinyweb_web_init(int port);
void tinyweb_scale(const char *c, double sx, double sy);
pyk_d_Dtinyweb_Color__Color__ tinyweb_bitmap__bitmap__default__background(void);
const char *tinyweb_bitmap__bitmap(int width, int height, pyk_d_Dtinyweb_Color__Color__ background);
void tinyweb_bitmap__set_pixel(const char *b, int x, int y, pyk_d_Dtinyweb_Color__Color__ pixel);
pyk_d_Dtinyweb_Color__Color__ tinyweb_bitmap__get_pixel(const char *b, int x, int y);
void tinyweb_bitmap__fill_bitmap(const char *b, pyk_d_Dtinyweb_Color__Color__ fill);
void tinyweb_bitmap__show_bitmap(const char *c, const char *b, int x, int y, double scale);

static const char *floats2(double a, double b)
{
    return pyk_concat(pyk_concat(pyk_float_str(a), " "), pyk_float_str(b));
}

static int color__part(int n)
{
    return n < 0 ? 0 : n > 255 ? 255 : n;
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_color__rgb(int r, int g, int b)
{
    return pyk_mk_Dtinyweb_Color__Color___Color__Color(color__part(r), color__part(g), color__part(b), 1.0);
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_color__hex(int n)
{
    return pyk_mk_Dtinyweb_Color__Color___Color__Color(color__part(n / 65536), color__part(n / 256 - n / 65536 * 256), color__part(n - n / 256 * 256), 1.0);
}

int tinyweb_color__to_hex(pyk_d_Dtinyweb_Color__Color__ c)
{
    return color__part(c.r) * 65536 + color__part(c.g) * 256 + color__part(c.b);
}

void tinyweb_web_init(int port)
{
    tinyweb_web_start(port);
}

void tinyweb_scale(const char *c, double sx, double sy)
{
    tinyweb_set_state(c, "scale", "", floats2(sx, sy));
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_bitmap__bitmap__default__background(void)
{
    return tinyweb_color__white;
}

const char *tinyweb_bitmap__bitmap(int width, int height, pyk_d_Dtinyweb_Color__Color__ background)
{
    return tinyweb_make_bitmap(width, height, tinyweb_color__to_hex(background));
}

void tinyweb_bitmap__set_pixel(const char *b, int x, int y, pyk_d_Dtinyweb_Color__Color__ pixel)
{
    tinyweb_set_pixel(b, x, y, tinyweb_color__to_hex(pixel));
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_bitmap__get_pixel(const char *b, int x, int y)
{
    return tinyweb_color__hex(tinyweb_get_pixel(b, x, y));
}

void tinyweb_bitmap__fill_bitmap(const char *b, pyk_d_Dtinyweb_Color__Color__ fill)
{
    tinyweb_fill_bitmap(b, tinyweb_color__to_hex(fill));
}

void tinyweb_bitmap__show_bitmap(const char *c, const char *b, int x, int y, double scale)
{
    tinyweb_draw_bitmap(c, b, x, y, scale);
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
