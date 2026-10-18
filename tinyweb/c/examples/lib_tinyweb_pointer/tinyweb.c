// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Every multiply and add rounded on its own, as on every other target.
#if defined(__clang__)
#pragma STDC FP_CONTRACT OFF
#elif defined(__GNUC__)
#pragma GCC optimize ("fp-contract=off")
#endif

#include "tinyweb.h"

#ifndef PYK_TYPE_PYK_C_FII_U_
#define PYK_TYPE_PYK_C_FII_U_
typedef struct pyk_c_Fii_u_ {
    void (*fn)(void *, int, int);
    void *env;
    void (*plain)(int, int);
} pyk_c_Fii_u_;
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

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static const char *numbers2(int a, int b);
static const char *numbers3(int a, int b, int c);
static const char *numbers4(int a, int b, int c, int d);
void tinyweb_web_init(int port);
const char *tinyweb_circle__default__outline(void);
int tinyweb_circle__default__outline_width(void);
double tinyweb_circle__default__alpha(void);
void tinyweb_circle(const char *c, int x, int y, int radius, const char *color, const char *outline, int outline_width, double alpha);
double tinyweb_line__default__alpha(void);
void tinyweb_line(const char *c, int x1, int y1_, int x2, int y2, const char *color, int width, double alpha);
void tinyweb_on_press(const char *c, pyk_c_Fii_u_ f);
void tinyweb_on_release(const char *c, pyk_c_Fii_u_ f);
void tinyweb_on_move(const char *c, pyk_c_Fii_u_ f);
void tinyweb_on_drag(const char *c, pyk_c_Fii_u_ f);
int tinyweb_mouse_x(const char *c);
int tinyweb_mouse_y(const char *c);
bool tinyweb_mouse_down(const char *c);
void tinyweb_ignore2(int x, int y);

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

double tinyweb_line__default__alpha(void)
{
    return 1.0;
}

void tinyweb_line(const char *c, int x1, int y1_, int x2, int y2, const char *color, int width, double alpha)
{
    tinyweb_draw_shape(c, "line", numbers4(x1, y1_, x2, y2), "", color, (double)width, alpha);
}

void tinyweb_on_press(const char *c, pyk_c_Fii_u_ f)
{
    tinyweb_watch_pointer(c, "press", pyk_plain_Fii_u_(f));
}

void tinyweb_on_release(const char *c, pyk_c_Fii_u_ f)
{
    tinyweb_watch_pointer(c, "release", pyk_plain_Fii_u_(f));
}

void tinyweb_on_move(const char *c, pyk_c_Fii_u_ f)
{
    tinyweb_watch_pointer(c, "move", pyk_plain_Fii_u_(f));
}

void tinyweb_on_drag(const char *c, pyk_c_Fii_u_ f)
{
    tinyweb_watch_pointer(c, "drag", pyk_plain_Fii_u_(f));
}

int tinyweb_mouse_x(const char *c)
{
    return tinyweb_pointer(c, "x");
}

int tinyweb_mouse_y(const char *c)
{
    return tinyweb_pointer(c, "y");
}

bool tinyweb_mouse_down(const char *c)
{
    return tinyweb_pointer(c, "down") == 1;
}

void tinyweb_ignore2(int x, int y)
{

}

void tinyweb_init(void)
{

}
