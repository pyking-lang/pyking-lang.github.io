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

#ifndef PYK_TYPE_PYK_C_FF_U_
#define PYK_TYPE_PYK_C_FF_U_
typedef struct pyk_c_Ff_u_ {
    void (*fn)(void *, double);
    void *env;
    void (*plain)(double);
} pyk_c_Ff_u_;
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

static pyk_c_Ff_u_ pyk_mk_Ff_u_(void (*fn)(void *, double), void *env, void (*plain)(double))
{
    pyk_c_Ff_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static pyk_fn_f_v pyk_plain_Ff_u_(pyk_c_Ff_u_ c)
{
    if (c.plain == NULL) {
        fprintf(stderr, "a function that captures values cannot be handed to a module implemented in C\n");
        exit(1);
    }
    return c.plain;
}

// Declared ahead of their definitions: a Pyking function may be called before it is written.
void tinyweb_clear(const char *c, const char *color);
static const char *numbers2(int a, int b);
static const char *numbers3(int a, int b, int c);
static const char *numbers4(int a, int b, int c, int d);
static const char *floats2(double a, double b);
static const char *floats3(double a, double b, double c);
static const char *floats4(double a, double b, double c, double d);
void tinyweb_web_init(int port);
const char *tinyweb_circle__default__outline(void);
int tinyweb_circle__default__outline_width(void);
double tinyweb_circle__default__alpha(void);
void tinyweb_circle(const char *c, int x, int y, int radius, const char *color, const char *outline, int outline_width, double alpha);
const char *tinyweb_rect__default__outline(void);
int tinyweb_rect__default__outline_width(void);
double tinyweb_rect__default__alpha(void);
int tinyweb_rect__default__radius(void);
void tinyweb_rect(const char *c, int x, int y, int width, int height, const char *color, const char *outline, int outline_width, double alpha, int radius);
double tinyweb_line__default__alpha(void);
void tinyweb_line(const char *c, int x1, int y1_, int x2, int y2, const char *color, int width, double alpha);
double tinyweb_bezier__default__alpha(void);
void tinyweb_bezier(const char *c, int x1, int y1_, int ax, int ay, int bx, int by, int x2, int y2, const char *color, int width, double alpha);
void tinyweb_erase(const char *c, int x, int y, int width, int height);
const char *tinyweb_line_style__default__cap(void);
const char *tinyweb_line_style__default__join(void);
double tinyweb_line_style__default__gap(void);
double tinyweb_line_style__default__offset(void);
double tinyweb_line_style__default__dash2(void);
double tinyweb_line_style__default__gap2(void);
void tinyweb_line_style(const char *c, const char *cap, const char *join, double dash, double gap, double offset, double dash2, double gap2);
void tinyweb_clip_rect(const char *c, int x, int y, int width, int height);
void tinyweb_clip_circle(const char *c, int x, int y, int radius);
const char *tinyweb_text__default__font(void);
const char *tinyweb_text__default__align(void);
bool tinyweb_text__default__bold(void);
double tinyweb_text__default__alpha(void);
const char *tinyweb_text__default__outline(void);
int tinyweb_text__default__outline_width(void);
void tinyweb_text(const char *c, int x, int y, const char *words, const char *color, int size, const char *font, const char *align, bool bold, double alpha, const char *baseline, const char *outline, int outline_width);
const char *tinyweb_measure_text__default__font(void);
void tinyweb_measure_text(const char *words, pyk_c_Ff_u_ answer, int size, const char *font, bool bold);
void tinyweb_push(const char *c);
void tinyweb_pop(const char *c);
const char *tinyweb_colors__linear_gradient(double x1, double y1_, double x2, double y2, const char *start, const char *end);
const char *tinyweb_colors__radial_gradient(double x1, double y1_, double r1, double x2, double y2, double r2, const char *start, const char *end);
const char *tinyweb_colors__conic_gradient(double x, double y, double angle, const char *start, const char *end);
const char *tinyweb_colors__stop(const char *gradient, double at, const char *color);
double tinyweb_smooth__circle__default__alpha(void);
void tinyweb_smooth__circle(const char *c, double x, double y, double radius, const char *color, const char *outline, double outline_width, double alpha);
double tinyweb_smooth__rect__default__outline_width(void);
double tinyweb_smooth__rect__default__alpha(void);
void tinyweb_smooth__rect(const char *c, double x, double y, double width, double height, const char *color, const char *outline, double outline_width, double alpha, double radius);
const char *tinyweb_smooth__ellipse__default__outline(void);
double tinyweb_smooth__ellipse__default__outline_width(void);
double tinyweb_smooth__ellipse__default__alpha(void);
void tinyweb_smooth__ellipse(const char *c, double x, double y, double rx, double ry, const char *color, const char *outline, double outline_width, double alpha);
double tinyweb_smooth__arc__default__alpha(void);
void tinyweb_smooth__arc(const char *c, double x, double y, double radius, double start, double end, const char *color, const char *outline, double outline_width, double alpha);
double tinyweb_smooth__line__default__alpha(void);
void tinyweb_smooth__line(const char *c, double x1, double y1_, double x2, double y2, const char *color, double width, double alpha);
double tinyweb_smooth__curve__default__alpha(void);
void tinyweb_smooth__curve(const char *c, double x1, double y1_, double cx, double cy, double x2, double y2, const char *color, double width, double alpha);
void tinyweb_smooth__bezier(const char *c, double x1, double y1_, double ax, double ay, double bx, double by, double x2, double y2, const char *color, double width, double alpha);
const char *tinyweb_smooth__text__default__font(void);
bool tinyweb_smooth__text__default__bold(void);
double tinyweb_smooth__text__default__alpha(void);
const char *tinyweb_smooth__text__default__outline(void);
double tinyweb_smooth__text__default__outline_width(void);
void tinyweb_smooth__text(const char *c, double x, double y, const char *words, const char *color, int size, const char *font, const char *align, bool bold, double alpha, const char *baseline, const char *outline, double outline_width);
void tinyweb_smooth__clip_circle(const char *c, double x, double y, double radius);

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

const char *tinyweb_rect__default__outline(void)
{
    return "";
}

int tinyweb_rect__default__outline_width(void)
{
    return 1;
}

double tinyweb_rect__default__alpha(void)
{
    return 1.0;
}

int tinyweb_rect__default__radius(void)
{
    return 0;
}

void tinyweb_rect(const char *c, int x, int y, int width, int height, const char *color, const char *outline, int outline_width, double alpha, int radius)
{
    tinyweb_draw_shape(c, "rect", pyk_concat(pyk_concat(numbers4(x, y, width, height), " "), pyk_int_str(radius)), color, outline, (double)outline_width, alpha);
}

double tinyweb_line__default__alpha(void)
{
    return 1.0;
}

void tinyweb_line(const char *c, int x1, int y1_, int x2, int y2, const char *color, int width, double alpha)
{
    tinyweb_draw_shape(c, "line", numbers4(x1, y1_, x2, y2), "", color, (double)width, alpha);
}

double tinyweb_bezier__default__alpha(void)
{
    return 1.0;
}

void tinyweb_bezier(const char *c, int x1, int y1_, int ax, int ay, int bx, int by, int x2, int y2, const char *color, int width, double alpha)
{
    tinyweb_draw_shape(c, "bezier", pyk_concat(pyk_concat(numbers4(x1, y1_, ax, ay), " "), numbers4(bx, by, x2, y2)), "", color, (double)width, alpha);
}

void tinyweb_erase(const char *c, int x, int y, int width, int height)
{
    tinyweb_draw_shape(c, "erase", numbers4(x, y, width, height), "", "", 0.0, 1.0);
}

const char *tinyweb_line_style__default__cap(void)
{
    return "round";
}

const char *tinyweb_line_style__default__join(void)
{
    return "round";
}

double tinyweb_line_style__default__gap(void)
{
    return 0.0;
}

double tinyweb_line_style__default__offset(void)
{
    return 0.0;
}

double tinyweb_line_style__default__dash2(void)
{
    return 0.0;
}

double tinyweb_line_style__default__gap2(void)
{
    return 0.0;
}

void tinyweb_line_style(const char *c, const char *cap, const char *join, double dash, double gap, double offset, double dash2, double gap2)
{
    const char *first = dash <= 0.0 ? "" : gap <= 0.0 ? pyk_concat(" ", floats2(dash, dash)) : pyk_concat(" ", floats2(dash, gap));
    const char *second = dash <= 0.0 ? "" : dash2 <= 0.0 ? "" : gap2 <= 0.0 ? pyk_concat(" ", floats2(dash2, dash2)) : pyk_concat(" ", floats2(dash2, gap2));
    tinyweb_set_state(c, "line_style", pyk_concat(pyk_concat(cap, " "), join), pyk_concat(pyk_concat(pyk_float_str(offset), first), second));
}

void tinyweb_clip_rect(const char *c, int x, int y, int width, int height)
{
    tinyweb_set_state(c, "clip", "rect", pyk_concat(numbers4(x, y, width, height), " 0"));
}

void tinyweb_clip_circle(const char *c, int x, int y, int radius)
{
    tinyweb_set_state(c, "clip", "circle", numbers3(x, y, radius));
}

const char *tinyweb_text__default__font(void)
{
    return "";
}

const char *tinyweb_text__default__align(void)
{
    return "left";
}

bool tinyweb_text__default__bold(void)
{
    return false;
}

double tinyweb_text__default__alpha(void)
{
    return 1.0;
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

const char *tinyweb_measure_text__default__font(void)
{
    return "";
}

void tinyweb_measure_text(const char *words, pyk_c_Ff_u_ answer, int size, const char *font, bool bold)
{
    tinyweb_measure(words, size, font, bold, pyk_plain_Ff_u_(answer));
}

void tinyweb_push(const char *c)
{
    tinyweb_set_state(c, "push", "", "");
}

void tinyweb_pop(const char *c)
{
    tinyweb_set_state(c, "pop", "", "");
}

const char *tinyweb_colors__linear_gradient(double x1, double y1_, double x2, double y2, const char *start, const char *end)
{
    return pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat("linear-gradient(", floats4(x1, y1_, x2, y2)), "); 0.0 "), start), "; 1.0 "), end);
}

const char *tinyweb_colors__radial_gradient(double x1, double y1_, double r1, double x2, double y2, double r2, const char *start, const char *end)
{
    return pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat("radial-gradient(", floats3(x1, y1_, r1)), " "), floats3(x2, y2, r2)), "); 0.0 "), start), "; 1.0 "), end);
}

const char *tinyweb_colors__conic_gradient(double x, double y, double angle, const char *start, const char *end)
{
    return pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat("conic-gradient(", floats3(x, y, angle)), "); 0.0 "), start), "; 1.0 "), end);
}

const char *tinyweb_colors__stop(const char *gradient, double at, const char *color)
{
    return pyk_concat(pyk_concat(pyk_concat(pyk_concat(gradient, "; "), pyk_float_str(at)), " "), color);
}

double tinyweb_smooth__circle__default__alpha(void)
{
    return 1.0;
}

void tinyweb_smooth__circle(const char *c, double x, double y, double radius, const char *color, const char *outline, double outline_width, double alpha)
{
    tinyweb_draw_shape(c, "circle", floats3(x, y, radius), color, outline, outline_width, alpha);
}

double tinyweb_smooth__rect__default__outline_width(void)
{
    return 1.0;
}

double tinyweb_smooth__rect__default__alpha(void)
{
    return 1.0;
}

void tinyweb_smooth__rect(const char *c, double x, double y, double width, double height, const char *color, const char *outline, double outline_width, double alpha, double radius)
{
    tinyweb_draw_shape(c, "rect", pyk_concat(pyk_concat(floats4(x, y, width, height), " "), pyk_float_str(radius)), color, outline, outline_width, alpha);
}

const char *tinyweb_smooth__ellipse__default__outline(void)
{
    return "";
}

double tinyweb_smooth__ellipse__default__outline_width(void)
{
    return 1.0;
}

double tinyweb_smooth__ellipse__default__alpha(void)
{
    return 1.0;
}

void tinyweb_smooth__ellipse(const char *c, double x, double y, double rx, double ry, const char *color, const char *outline, double outline_width, double alpha)
{
    tinyweb_draw_shape(c, "ellipse", floats4(x, y, rx, ry), color, outline, outline_width, alpha);
}

double tinyweb_smooth__arc__default__alpha(void)
{
    return 1.0;
}

void tinyweb_smooth__arc(const char *c, double x, double y, double radius, double start, double end, const char *color, const char *outline, double outline_width, double alpha)
{
    tinyweb_draw_shape(c, "arc", pyk_concat(pyk_concat(floats3(x, y, radius), " "), floats2(start, end)), color, outline, outline_width, alpha);
}

double tinyweb_smooth__line__default__alpha(void)
{
    return 1.0;
}

void tinyweb_smooth__line(const char *c, double x1, double y1_, double x2, double y2, const char *color, double width, double alpha)
{
    tinyweb_draw_shape(c, "line", floats4(x1, y1_, x2, y2), "", color, width, alpha);
}

double tinyweb_smooth__curve__default__alpha(void)
{
    return 1.0;
}

void tinyweb_smooth__curve(const char *c, double x1, double y1_, double cx, double cy, double x2, double y2, const char *color, double width, double alpha)
{
    tinyweb_draw_shape(c, "curve", pyk_concat(pyk_concat(floats2(x1, y1_), " "), floats4(cx, cy, x2, y2)), "", color, width, alpha);
}

void tinyweb_smooth__bezier(const char *c, double x1, double y1_, double ax, double ay, double bx, double by, double x2, double y2, const char *color, double width, double alpha)
{
    tinyweb_draw_shape(c, "bezier", pyk_concat(pyk_concat(floats4(x1, y1_, ax, ay), " "), floats4(bx, by, x2, y2)), "", color, width, alpha);
}

const char *tinyweb_smooth__text__default__font(void)
{
    return "";
}

bool tinyweb_smooth__text__default__bold(void)
{
    return false;
}

double tinyweb_smooth__text__default__alpha(void)
{
    return 1.0;
}

const char *tinyweb_smooth__text__default__outline(void)
{
    return "";
}

double tinyweb_smooth__text__default__outline_width(void)
{
    return 1.0;
}

void tinyweb_smooth__text(const char *c, double x, double y, const char *words, const char *color, int size, const char *font, const char *align, bool bold, double alpha, const char *baseline, const char *outline, double outline_width)
{
    tinyweb_draw_text(c, x, y, words, color, size, font, align, baseline, bold, outline, outline_width, alpha);
}

void tinyweb_smooth__clip_circle(const char *c, double x, double y, double radius)
{
    tinyweb_set_state(c, "clip", "circle", floats3(x, y, radius));
}

void tinyweb_init(void)
{

}
