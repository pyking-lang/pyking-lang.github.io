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
const char *tinyweb_rect__default__outline(void);
int tinyweb_rect__default__outline_width(void);
double tinyweb_rect__default__alpha(void);
int tinyweb_rect__default__radius(void);
void tinyweb_rect(const char *c, int x, int y, int width, int height, const char *color, const char *outline, int outline_width, double alpha, int radius);
void tinyweb_translate(const char *c, double x, double y);
void tinyweb_rotate(const char *c, double degrees);
void tinyweb_scale(const char *c, double sx, double sy);
void tinyweb_push(const char *c);
void tinyweb_pop(const char *c);
void tinyweb_reset(const char *c);
int tinyweb_shadow__default__blur(void);
int tinyweb_shadow__default__dx(void);
int tinyweb_shadow__default__dy(void);
void tinyweb_shadow(const char *c, const char *color, int blur, int dx, int dy);
void tinyweb_blend(const char *c, const char *mode);

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

void tinyweb_translate(const char *c, double x, double y)
{
    tinyweb_set_state(c, "translate", "", pyk_concat(pyk_concat(pyk_float_str(x), " "), pyk_float_str(y)));
}

void tinyweb_rotate(const char *c, double degrees)
{
    tinyweb_set_state(c, "rotate", "", pyk_float_str(degrees));
}

void tinyweb_scale(const char *c, double sx, double sy)
{
    tinyweb_set_state(c, "scale", "", pyk_concat(pyk_concat(pyk_float_str(sx), " "), pyk_float_str(sy)));
}

void tinyweb_push(const char *c)
{
    tinyweb_set_state(c, "push", "", "");
}

void tinyweb_pop(const char *c)
{
    tinyweb_set_state(c, "pop", "", "");
}

void tinyweb_reset(const char *c)
{
    tinyweb_set_state(c, "reset", "", "");
}

int tinyweb_shadow__default__blur(void)
{
    return 10;
}

int tinyweb_shadow__default__dx(void)
{
    return 0;
}

int tinyweb_shadow__default__dy(void)
{
    return 0;
}

void tinyweb_shadow(const char *c, const char *color, int blur, int dx, int dy)
{
    tinyweb_set_state(c, "shadow", color, numbers3(blur, dx, dy));
}

void tinyweb_blend(const char *c, const char *mode)
{
    const char *pyk_s1 = mode;
    if (strcmp(pyk_s1, "normal") == 0 || strcmp(pyk_s1, "add") == 0) {
        {
            tinyweb_set_state(c, "blend", mode, "");
        }
    } else {
        {
            fprintf(stderr, "%s\n", pyk_concat(pyk_concat("tinyweb: there is no blending called \"", mode), "\"; the modes are normal and add"));
        }
    }
}

void tinyweb_init(void)
{

}
