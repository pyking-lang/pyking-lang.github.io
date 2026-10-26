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

#ifndef PYK_TYPE_PYK_D_DTINYWEB_COLOR__PAINT__
#define PYK_TYPE_PYK_D_DTINYWEB_COLOR__PAINT__
typedef struct pyk_d_Dtinyweb_Color__Paint__ {
    int tag;
    union {
        struct {
            pyk_d_Dtinyweb_Color__Color__ f0;
        } Color__Plain;
        struct {
            double f0;
            double f1;
            double f2;
            double f3;
            pyk_d_Dtinyweb_Color__Color__ f4;
            pyk_d_Dtinyweb_Color__Color__ f5;
            const char *f6;
        } Color__Linear;
        struct {
            double f0;
            double f1;
            double f2;
            double f3;
            double f4;
            double f5;
            pyk_d_Dtinyweb_Color__Color__ f6;
            pyk_d_Dtinyweb_Color__Color__ f7;
            const char *f8;
        } Color__Radial;
        struct {
            double f0;
            double f1;
            double f2;
            pyk_d_Dtinyweb_Color__Color__ f3;
            pyk_d_Dtinyweb_Color__Color__ f4;
            const char *f5;
        } Color__Conic;
    } u;
} pyk_d_Dtinyweb_Color__Paint__;
#endif

#ifndef PYK_TYPE_PYK_D_DTINYWEB_STYLE__
#define PYK_TYPE_PYK_D_DTINYWEB_STYLE__
typedef struct pyk_d_Dtinyweb_Style__ {
    pyk_d_Dtinyweb_Color__Color__ fill;
    pyk_d_Dtinyweb_Color__Color__ stroke;
    int width;
    double alpha;
    pyk_d_Dtinyweb_Color__Paint__ paint;
} pyk_d_Dtinyweb_Style__;
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

static const char *pyk_int_str(int n)
{
    char *out = malloc(24);
    sprintf(out, "%d", n);
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

static pyk_d_Dtinyweb_Color__Color__ pyk_mk_Dtinyweb_Color__Color___Color__Color(int r, int g, int b, double a)
{
    pyk_d_Dtinyweb_Color__Color__ v;
    v.r = r;
    v.g = g;
    v.b = b;
    v.a = a;
    return v;
}

static pyk_d_Dtinyweb_Color__Paint__ pyk_mk_Dtinyweb_Color__Paint___Color__Plain(pyk_d_Dtinyweb_Color__Color__ f0)
{
    pyk_d_Dtinyweb_Color__Paint__ v;
    v.tag = 0;
    v.u.Color__Plain.f0 = f0;
    return v;
}

static pyk_d_Dtinyweb_Color__Paint__ pyk_mk_Dtinyweb_Color__Paint___Color__Linear(double f0, double f1, double f2, double f3, pyk_d_Dtinyweb_Color__Color__ f4, pyk_d_Dtinyweb_Color__Color__ f5, const char *f6)
{
    pyk_d_Dtinyweb_Color__Paint__ v;
    v.tag = 1;
    v.u.Color__Linear.f0 = f0;
    v.u.Color__Linear.f1 = f1;
    v.u.Color__Linear.f2 = f2;
    v.u.Color__Linear.f3 = f3;
    v.u.Color__Linear.f4 = f4;
    v.u.Color__Linear.f5 = f5;
    v.u.Color__Linear.f6 = f6;
    return v;
}

static pyk_d_Dtinyweb_Color__Paint__ pyk_mk_Dtinyweb_Color__Paint___Color__Radial(double f0, double f1, double f2, double f3, double f4, double f5, pyk_d_Dtinyweb_Color__Color__ f6, pyk_d_Dtinyweb_Color__Color__ f7, const char *f8)
{
    pyk_d_Dtinyweb_Color__Paint__ v;
    v.tag = 2;
    v.u.Color__Radial.f0 = f0;
    v.u.Color__Radial.f1 = f1;
    v.u.Color__Radial.f2 = f2;
    v.u.Color__Radial.f3 = f3;
    v.u.Color__Radial.f4 = f4;
    v.u.Color__Radial.f5 = f5;
    v.u.Color__Radial.f6 = f6;
    v.u.Color__Radial.f7 = f7;
    v.u.Color__Radial.f8 = f8;
    return v;
}

static pyk_d_Dtinyweb_Color__Paint__ pyk_mk_Dtinyweb_Color__Paint___Color__Conic(double f0, double f1, double f2, pyk_d_Dtinyweb_Color__Color__ f3, pyk_d_Dtinyweb_Color__Color__ f4, const char *f5)
{
    pyk_d_Dtinyweb_Color__Paint__ v;
    v.tag = 3;
    v.u.Color__Conic.f0 = f0;
    v.u.Color__Conic.f1 = f1;
    v.u.Color__Conic.f2 = f2;
    v.u.Color__Conic.f3 = f3;
    v.u.Color__Conic.f4 = f4;
    v.u.Color__Conic.f5 = f5;
    return v;
}

static pyk_d_Dtinyweb_Style__ pyk_mk_Dtinyweb_Style___Style(pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Color__ stroke, int width, double alpha, pyk_d_Dtinyweb_Color__Paint__ paint)
{
    pyk_d_Dtinyweb_Style__ v;
    v.fill = fill;
    v.stroke = stroke;
    v.width = width;
    v.alpha = alpha;
    v.paint = paint;
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
static const char *numbers2(int a, int b);
static const char *numbers3(int a, int b, int c);
static const char *numbers4(int a, int b, int c, int d);
static const char *floats2(double a, double b);
static const char *floats3(double a, double b, double c);
static const char *floats4(double a, double b, double c, double d);
static int color__part(int n);
static double color__unit(double x);
static const char *color__hex2(int n);
static const char *color__hex_digit(int d);
static const char *color__css(pyk_d_Dtinyweb_Color__Color__ c);
static const char *color__drawn(pyk_d_Dtinyweb_Color__Color__ c);
static const char *color__paint_text(pyk_d_Dtinyweb_Color__Paint__ p);
static bool color__painted(pyk_d_Dtinyweb_Color__Paint__ p);
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__hex(int n);
bool tinyweb_color__same(pyk_d_Dtinyweb_Color__Color__ a, pyk_d_Dtinyweb_Color__Color__ b);
void tinyweb_web_init(int port);
pyk_d_Dtinyweb_Color__Color__ tinyweb_field__default__Style__fill(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_field__default__Style__stroke(void);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_field__default__Style__paint(void);
static const char *fill_of(pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style);
static bool not_default_fill(pyk_d_Dtinyweb_Color__Color__ fill);
static const char *stroke_of(pyk_d_Dtinyweb_Color__Color__ stroke, pyk_d_Dtinyweb_Style__ style);
static double width_of(int width, pyk_d_Dtinyweb_Style__ style);
static double alpha_of(double alpha, pyk_d_Dtinyweb_Style__ style);
static void shape(const char *c, const char *kind, const char *numbers, pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Color__ stroke, int width, double alpha, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style);
pyk_d_Dtinyweb_Color__Color__ tinyweb_circle__default__stroke(void);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_circle__default__paint(void);
pyk_d_Dtinyweb_Style__ tinyweb_circle__default__style(void);
void tinyweb_circle(const char *c, int x, int y, int radius, pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Color__ stroke, int width, double alpha, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style);
pyk_d_Dtinyweb_Color__Color__ tinyweb_rect__default__stroke(void);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_rect__default__paint(void);
pyk_d_Dtinyweb_Style__ tinyweb_rect__default__style(void);
void tinyweb_rect(const char *c, int x, int y, int w, int h, pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Color__ stroke, int width, double alpha, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style, int radius);
void tinyweb_image(const char *c, const char *picture, int x, int y, int w, int h, double alpha);

static const char *numbers2(int a, int b)
{
    return pyk_concat(pyk_concat(pyk_int_str(a), " "), pyk_int_str(b));
}

static const char *numbers3(int a, int b, int c)
{
    return pyk_concat(pyk_concat(numbers2(a, b), " "), pyk_int_str(c));
}

static const char *numbers4(int a, int b, int c, int d)
{
    return pyk_concat(pyk_concat(numbers2(a, b), " "), numbers2(c, d));
}

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

static int color__part(int n)
{
    return n < 0 ? 0 : n > 255 ? 255 : n;
}

static double color__unit(double x)
{
    return x < 0.0 ? 0.0 : x > 1.0 ? 1.0 : x;
}

static const char *color__hex2(int n)
{
    int clamped = color__part(n);
    return pyk_concat(color__hex_digit(clamped / 16), color__hex_digit(clamped - clamped / 16 * 16));
}

static const char *color__hex_digit(int d)
{
    int pyk_s1 = d;
    if (pyk_s1 == 0) {
        {
            return "0";
        }
    } else if (pyk_s1 == 1) {
        {
            return "1";
        }
    } else if (pyk_s1 == 2) {
        {
            return "2";
        }
    } else if (pyk_s1 == 3) {
        {
            return "3";
        }
    } else if (pyk_s1 == 4) {
        {
            return "4";
        }
    } else if (pyk_s1 == 5) {
        {
            return "5";
        }
    } else if (pyk_s1 == 6) {
        {
            return "6";
        }
    } else if (pyk_s1 == 7) {
        {
            return "7";
        }
    } else if (pyk_s1 == 8) {
        {
            return "8";
        }
    } else if (pyk_s1 == 9) {
        {
            return "9";
        }
    } else if (pyk_s1 == 10) {
        {
            return "a";
        }
    } else if (pyk_s1 == 11) {
        {
            return "b";
        }
    } else if (pyk_s1 == 12) {
        {
            return "c";
        }
    } else if (pyk_s1 == 13) {
        {
            return "d";
        }
    } else if (pyk_s1 == 14) {
        {
            return "e";
        }
    } else {
        {
            return "f";
        }
    }
}

static const char *color__css(pyk_d_Dtinyweb_Color__Color__ c)
{
    if (c.a >= 1.0) {
        return pyk_concat(pyk_concat(pyk_concat("#", color__hex2(c.r)), color__hex2(c.g)), color__hex2(c.b));
    } else {
        return pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat("rgba(", pyk_int_str(color__part(c.r))), ", "), pyk_int_str(color__part(c.g))), ", "), pyk_int_str(color__part(c.b))), ", "), pyk_float_str(color__unit(c.a))), ")");
    }
}

static const char *color__drawn(pyk_d_Dtinyweb_Color__Color__ c)
{
    return c.a <= 0.0 ? "" : color__css(c);
}

static const char *color__paint_text(pyk_d_Dtinyweb_Color__Paint__ p)
{
    pyk_d_Dtinyweb_Color__Paint__ pyk_s2 = p;
    if (pyk_s2.tag == 0) {
        {
            pyk_d_Dtinyweb_Color__Color__ c = pyk_s2.u.Color__Plain.f0;
            return color__drawn(c);
        }
    } else if (pyk_s2.tag == 1) {
        {
            double x1 = pyk_s2.u.Color__Linear.f0;
            double y1_ = pyk_s2.u.Color__Linear.f1;
            double x2 = pyk_s2.u.Color__Linear.f2;
            double y2 = pyk_s2.u.Color__Linear.f3;
            pyk_d_Dtinyweb_Color__Color__ start = pyk_s2.u.Color__Linear.f4;
            pyk_d_Dtinyweb_Color__Color__ end = pyk_s2.u.Color__Linear.f5;
            const char *stops = pyk_s2.u.Color__Linear.f6;
            return pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat("linear-gradient(", floats4(x1, y1_, x2, y2)), "); 0.0 "), color__css(start)), "; 1.0 "), color__css(end)), stops);
        }
    } else if (pyk_s2.tag == 2) {
        {
            double x12 = pyk_s2.u.Color__Radial.f0;
            double y1_2 = pyk_s2.u.Color__Radial.f1;
            double r1 = pyk_s2.u.Color__Radial.f2;
            double x22 = pyk_s2.u.Color__Radial.f3;
            double y22 = pyk_s2.u.Color__Radial.f4;
            double r2 = pyk_s2.u.Color__Radial.f5;
            pyk_d_Dtinyweb_Color__Color__ start2 = pyk_s2.u.Color__Radial.f6;
            pyk_d_Dtinyweb_Color__Color__ end2 = pyk_s2.u.Color__Radial.f7;
            const char *stops2 = pyk_s2.u.Color__Radial.f8;
            return pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat("radial-gradient(", floats3(x12, y1_2, r1)), " "), floats3(x22, y22, r2)), "); 0.0 "), color__css(start2)), "; 1.0 "), color__css(end2)), stops2);
        }
    } else {
        {
            double x = pyk_s2.u.Color__Conic.f0;
            double y = pyk_s2.u.Color__Conic.f1;
            double angle = pyk_s2.u.Color__Conic.f2;
            pyk_d_Dtinyweb_Color__Color__ start3 = pyk_s2.u.Color__Conic.f3;
            pyk_d_Dtinyweb_Color__Color__ end3 = pyk_s2.u.Color__Conic.f4;
            const char *stops3 = pyk_s2.u.Color__Conic.f5;
            return pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat("conic-gradient(", floats3(x, y, angle)), "); 0.0 "), color__css(start3)), "; 1.0 "), color__css(end3)), stops3);
        }
    }
}

static bool color__painted(pyk_d_Dtinyweb_Color__Paint__ p)
{
    pyk_d_Dtinyweb_Color__Paint__ pyk_s3 = p;
    if (pyk_s3.tag == 0) {
        {
            pyk_d_Dtinyweb_Color__Color__ c = pyk_s3.u.Color__Plain.f0;
            return c.a > 0.0;
        }
    } else {
        {
            return true;
        }
    }
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_color__hex(int n)
{
    return pyk_mk_Dtinyweb_Color__Color___Color__Color(color__part(n / 65536), color__part(n / 256 - n / 65536 * 256), color__part(n - n / 256 * 256), 1.0);
}

bool tinyweb_color__same(pyk_d_Dtinyweb_Color__Color__ a, pyk_d_Dtinyweb_Color__Color__ b)
{
    return a.r == b.r ? a.g == b.g ? a.b == b.b ? a.a == b.a : false : false : false;
}

void tinyweb_web_init(int port)
{
    tinyweb_web_start(port);
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_field__default__Style__fill(void)
{
    return tinyweb_color__black;
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_field__default__Style__stroke(void)
{
    return tinyweb_color__none;
}

pyk_d_Dtinyweb_Color__Paint__ tinyweb_field__default__Style__paint(void)
{
    return pyk_mk_Dtinyweb_Color__Paint___Color__Plain(tinyweb_color__none);
}

static const char *fill_of(pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style)
{
    if (color__painted(paint)) {
        return color__paint_text(paint);
    } else if (not_default_fill(fill)) {
        return color__drawn(fill);
    } else if (color__painted(style.paint)) {
        return color__paint_text(style.paint);
    } else {
        return color__drawn(style.fill);
    }
}

static bool not_default_fill(pyk_d_Dtinyweb_Color__Color__ fill)
{
    return tinyweb_color__same(fill, tinyweb_color__black) ? false : true;
}

static const char *stroke_of(pyk_d_Dtinyweb_Color__Color__ stroke, pyk_d_Dtinyweb_Style__ style)
{
    return color__drawn(tinyweb_color__same(stroke, tinyweb_color__none) ? style.stroke : stroke);
}

static double width_of(int width, pyk_d_Dtinyweb_Style__ style)
{
    return (double)(width == 1 ? style.width : width);
}

static double alpha_of(double alpha, pyk_d_Dtinyweb_Style__ style)
{
    return alpha == 1.0 ? style.alpha : alpha;
}

static void shape(const char *c, const char *kind, const char *numbers, pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Color__ stroke, int width, double alpha, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style)
{
    tinyweb_draw_shape(c, kind, numbers, fill_of(fill, paint, style), stroke_of(stroke, style), width_of(width, style), alpha_of(alpha, style));
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_circle__default__stroke(void)
{
    return tinyweb_color__none;
}

pyk_d_Dtinyweb_Color__Paint__ tinyweb_circle__default__paint(void)
{
    return pyk_mk_Dtinyweb_Color__Paint___Color__Plain(tinyweb_color__none);
}

pyk_d_Dtinyweb_Style__ tinyweb_circle__default__style(void)
{
    return pyk_mk_Dtinyweb_Style___Style(tinyweb_field__default__Style__fill(), tinyweb_field__default__Style__stroke(), 1, 1.0, tinyweb_field__default__Style__paint());
}

void tinyweb_circle(const char *c, int x, int y, int radius, pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Color__ stroke, int width, double alpha, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style)
{
    shape(c, "circle", numbers3(x, y, radius), fill, stroke, width, alpha, paint, style);
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_rect__default__stroke(void)
{
    return tinyweb_color__none;
}

pyk_d_Dtinyweb_Color__Paint__ tinyweb_rect__default__paint(void)
{
    return pyk_mk_Dtinyweb_Color__Paint___Color__Plain(tinyweb_color__none);
}

pyk_d_Dtinyweb_Style__ tinyweb_rect__default__style(void)
{
    return pyk_mk_Dtinyweb_Style___Style(tinyweb_field__default__Style__fill(), tinyweb_field__default__Style__stroke(), 1, 1.0, tinyweb_field__default__Style__paint());
}

void tinyweb_rect(const char *c, int x, int y, int w, int h, pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Color__ stroke, int width, double alpha, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style, int radius)
{
    shape(c, "rect", pyk_concat(pyk_concat(numbers4(x, y, w, h), " "), pyk_int_str(radius)), fill, stroke, width, alpha, paint, style);
}

void tinyweb_image(const char *c, const char *picture, int x, int y, int w, int h, double alpha)
{
    tinyweb_draw_image(c, picture, x, y, w, h, alpha);
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
