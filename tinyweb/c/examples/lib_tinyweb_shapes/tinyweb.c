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
const char *tinyweb_bitmap(int, int);
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
void tinyweb_play_sample(const char *, double, double, double);
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

// Declared ahead of their definitions: a Pyking function may be called before it is written.
void tinyweb_clear(const char *c, const char *color);
static const char *numbers2(int a, int b);
static const char *numbers3(int a, int b, int c);
static const char *numbers4(int a, int b, int c, int d);
void tinyweb_web_init(int port);
const char *tinyweb_circle__default__outline(void);
int tinyweb_circle__default__outline_width(void);
double tinyweb_circle__default__alpha(void);
void tinyweb_circle(const char *c, int x, int y, int radius, const char *color, const char *outline, int outline_width, double alpha);
int tinyweb_rect__default__outline_width(void);
double tinyweb_rect__default__alpha(void);
void tinyweb_rect(const char *c, int x, int y, int width, int height, const char *color, const char *outline, int outline_width, double alpha, int radius);
const char *tinyweb_ellipse__default__outline(void);
int tinyweb_ellipse__default__outline_width(void);
void tinyweb_ellipse(const char *c, int x, int y, int rx, int ry, const char *color, const char *outline, int outline_width, double alpha);
const char *tinyweb_arc__default__outline(void);
int tinyweb_arc__default__outline_width(void);
double tinyweb_arc__default__alpha(void);
void tinyweb_arc(const char *c, int x, int y, int radius, double start, double end, const char *color, const char *outline, int outline_width, double alpha);
double tinyweb_line__default__alpha(void);
void tinyweb_line(const char *c, int x1, int y1_, int x2, int y2, const char *color, int width, double alpha);
void tinyweb_curve(const char *c, int x1, int y1_, int cx, int cy, int x2, int y2, const char *color, int width, double alpha);
double tinyweb_text__default__alpha(void);
const char *tinyweb_text__default__baseline(void);
const char *tinyweb_text__default__outline(void);
int tinyweb_text__default__outline_width(void);
void tinyweb_text(const char *c, int x, int y, const char *words, const char *color, int size, const char *font, const char *align, bool bold, double alpha, const char *baseline, const char *outline, int outline_width);
static const char *colors__hex2(int n);
static const char *colors__hex_digit(int d);
const char *tinyweb_colors__rgb(int r, int g, int b);
const char *tinyweb_colors__rgba(int r, int g, int b, double a);
const char *tinyweb_colors__hsl(int h, int s, int l);

void tinyweb_clear(const char *c, const char *color)
{
    tinyweb_fill_canvas(c, color);
}

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

void tinyweb_web_init(int port)
{
    tinyweb_web_start(port);
}

const char *tinyweb_circle__default__outline(void)
{
    return "";
}

int tinyweb_circle__default__outline_width(void)
{
    return 1;
}

double tinyweb_circle__default__alpha(void)
{
    return 1.0;
}

void tinyweb_circle(const char *c, int x, int y, int radius, const char *color, const char *outline, int outline_width, double alpha)
{
    tinyweb_draw_shape(c, "circle", numbers3(x, y, radius), color, outline, (double)outline_width, alpha);
}

int tinyweb_rect__default__outline_width(void)
{
    return 1;
}

double tinyweb_rect__default__alpha(void)
{
    return 1.0;
}

void tinyweb_rect(const char *c, int x, int y, int width, int height, const char *color, const char *outline, int outline_width, double alpha, int radius)
{
    tinyweb_draw_shape(c, "rect", pyk_concat(pyk_concat(numbers4(x, y, width, height), " "), pyk_int_str(radius)), color, outline, (double)outline_width, alpha);
}

const char *tinyweb_ellipse__default__outline(void)
{
    return "";
}

int tinyweb_ellipse__default__outline_width(void)
{
    return 1;
}

void tinyweb_ellipse(const char *c, int x, int y, int rx, int ry, const char *color, const char *outline, int outline_width, double alpha)
{
    tinyweb_draw_shape(c, "ellipse", numbers4(x, y, rx, ry), color, outline, (double)outline_width, alpha);
}

const char *tinyweb_arc__default__outline(void)
{
    return "";
}

int tinyweb_arc__default__outline_width(void)
{
    return 1;
}

double tinyweb_arc__default__alpha(void)
{
    return 1.0;
}

void tinyweb_arc(const char *c, int x, int y, int radius, double start, double end, const char *color, const char *outline, int outline_width, double alpha)
{
    tinyweb_draw_shape(c, "arc", pyk_concat(pyk_concat(pyk_concat(pyk_concat(numbers3(x, y, radius), " "), pyk_float_str(start)), " "), pyk_float_str(end)), color, outline, (double)outline_width, alpha);
}

double tinyweb_line__default__alpha(void)
{
    return 1.0;
}

void tinyweb_line(const char *c, int x1, int y1_, int x2, int y2, const char *color, int width, double alpha)
{
    tinyweb_draw_shape(c, "line", numbers4(x1, y1_, x2, y2), "", color, (double)width, alpha);
}

void tinyweb_curve(const char *c, int x1, int y1_, int cx, int cy, int x2, int y2, const char *color, int width, double alpha)
{
    tinyweb_draw_shape(c, "curve", pyk_concat(pyk_concat(numbers2(x1, y1_), " "), numbers4(cx, cy, x2, y2)), "", color, (double)width, alpha);
}

double tinyweb_text__default__alpha(void)
{
    return 1.0;
}

const char *tinyweb_text__default__baseline(void)
{
    return "top";
}

const char *tinyweb_text__default__outline(void)
{
    return "";
}

int tinyweb_text__default__outline_width(void)
{
    return 1;
}

void tinyweb_text(const char *c, int x, int y, const char *words, const char *color, int size, const char *font, const char *align, bool bold, double alpha, const char *baseline, const char *outline, int outline_width)
{
    tinyweb_draw_text(c, (double)x, (double)y, words, color, size, font, align, baseline, bold, outline, (double)outline_width, alpha);
}

static const char *colors__hex2(int n)
{
    int clamped = n < 0 ? 0 : n > 255 ? 255 : n;
    return pyk_concat(colors__hex_digit(clamped / 16), colors__hex_digit(clamped - clamped / 16 * 16));
}

static const char *colors__hex_digit(int d)
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

const char *tinyweb_colors__rgb(int r, int g, int b)
{
    return pyk_concat(pyk_concat(pyk_concat("#", colors__hex2(r)), colors__hex2(g)), colors__hex2(b));
}

const char *tinyweb_colors__rgba(int r, int g, int b, double a)
{
    return pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat("rgba(", pyk_int_str(r)), ", "), pyk_int_str(g)), ", "), pyk_int_str(b)), ", "), pyk_float_str(a)), ")");
}

const char *tinyweb_colors__hsl(int h, int s, int l)
{
    return pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat("hsl(", pyk_int_str(h)), ", "), pyk_int_str(s)), "%, "), pyk_int_str(l)), "%)");
}

void tinyweb_init(void)
{

}
