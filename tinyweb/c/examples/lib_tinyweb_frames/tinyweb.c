// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdlib.h>
#include <string.h>
#include <float.h>

#include "tinyweb.h"

// A Pyking function is a pointer to a C function.
#ifndef PYK_FN__V
#define PYK_FN__V
typedef void (*pyk_fn__v)(void);
#endif
#ifndef PYK_FN_I_V
#define PYK_FN_I_V
typedef void (*pyk_fn_i_v)(int);
#endif
#ifndef PYK_FN_F_V
#define PYK_FN_F_V
typedef void (*pyk_fn_f_v)(double);
#endif
#ifndef PYK_FN_II_V
#define PYK_FN_II_V
typedef void (*pyk_fn_ii_v)(int, int);
#endif
#ifndef PYK_FN_S_V
#define PYK_FN_S_V
typedef void (*pyk_fn_s_v)(const char *);
#endif

// What the external modules this one imports implement.
void tinyweb_web_init(int);
int tinyweb_canvas(int, int);
void tinyweb_fill_canvas(int, const char *);
void tinyweb_draw_circle(int, int, int, int, const char *);
void tinyweb_draw_rect(int, int, int, int, int, const char *);
void tinyweb_draw_line(int, int, int, int, int, const char *, int);
void tinyweb_draw_text(int, int, int, const char *, const char *, int);
int tinyweb_make_button(const char *, pyk_fn__v);
int tinyweb_label(const char *);
void tinyweb_set_label(int, const char *);
int tinyweb_make_slider(int, int, int, pyk_fn_i_v);
void tinyweb_apply_style(int, const char *, const char *, const char *);
int tinyweb_load_sample(const char *);
void tinyweb_play_sample(int, double, double, double);
double tinyweb_time(void);
void tinyweb_on_frame(pyk_fn_f_v);
void tinyweb_on_mouse(int, pyk_fn_ii_v);
void tinyweb_on_key(pyk_fn_s_v);

// Declared ahead of their definitions: a Pyking function may be called before it is written.
void tinyweb_clear(int c, const char *color);
void tinyweb_circle(int c, int x, int y, int radius, const char *color);
double tinyweb_play__default__volume(void);
double tinyweb_play__default__rate(void);
void tinyweb_play(int sample, double at, double volume, double rate);

void tinyweb_clear(int c, const char *color)
{
    tinyweb_fill_canvas(c, color);
}

void tinyweb_circle(int c, int x, int y, int radius, const char *color)
{
    tinyweb_draw_circle(c, x, y, radius, color);
}

double tinyweb_play__default__volume(void)
{
    return 1.0;
}

double tinyweb_play__default__rate(void)
{
    return 1.0;
}

void tinyweb_play(int sample, double at, double volume, double rate)
{
    tinyweb_play_sample(sample, at, volume, rate);
}

void tinyweb_init(void)
{

}
