// Generated from lib_tinyweb_bitmap.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>
#include <stdlib.h>

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
const char *tinyweb_canvas(int, int);
const char *tinyweb_bitmap(int, int);
void tinyweb_set_pixel(const char *, int, int, int);
int tinyweb_get_pixel(const char *, int, int);
void tinyweb_fill_bitmap(const char *, int);
#ifndef PYK_FN_F_V
#define PYK_FN_F_V
typedef void (*pyk_fn_f_v)(double);
#endif
void tinyweb_on_frame(pyk_fn_f_v);

static int pyk_truncate(double x)
{
    if (x != x || x <= -2147483649.0 || x >= 2147483648.0) {
        return 0;
    }
    return (int)x;
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

static const char *c;
static const char *b;
static int orange;
static const char *small;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void frame(double t);

static void pyk_w_frame(void *env, double p1)
{
    (void)env;
    frame(p1);
}

static void frame(double t)
{
    tinyweb_set_pixel(small, 1, 1, tinyweb_pixel_color(pyk_truncate(t * 100.0), 0, 0));
    tinyweb_show_bitmap(c, small, 120, 60, 2.0);
}

int main(void)
{
    int pyk_t1;
    int pyk_t2;
    int pyk_t3;
    int pyk_t4;
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(160, 100);
    b = tinyweb_bitmap(16, 10);
    printf("%s %d\n", "a new bitmap is black:", tinyweb_get_pixel(b, 3, 3));
    int y_stop = 10;
    int y_step = 1;
    int y;
    for (y = 0; y_step > 0 ? y < y_stop : y > y_stop; y += y_step) {
        int x_stop = 16;
        int x_step = 1;
        int x;
        for (x = 0; x_step > 0 ? x < x_stop : x > x_stop; x += x_step) {
            tinyweb_set_pixel(b, x, y, tinyweb_pixel_color(x * 16, y * 25, 128));
        }
        0;
    }
    (pyk_t1 = tinyweb_show_bitmap__default__x(), (tinyweb_show_bitmap(c, b, pyk_t1, tinyweb_show_bitmap__default__y(), 10.0), 0));
    orange = tinyweb_pixel_color(255, 136, 0);
    (pyk_t2 = tinyweb_red(orange), pyk_t3 = tinyweb_green(orange), printf("%s %d %d %d %d\n", "orange is", orange, pyk_t2, pyk_t3, tinyweb_blue(orange)));
    printf("%s %d\n", "clamped:", tinyweb_pixel_color(300, -5, 70));
    tinyweb_set_pixel(b, 4, 2, orange);
    tinyweb_set_pixel(b, 7, 5, orange);
    tinyweb_set_pixel(b, 40, 2, orange);
    (pyk_t4 = tinyweb_get_pixel(b, 4, 2), printf("%s %d %s %d\n", "pixel (4, 2):", pyk_t4, "outside:", tinyweb_get_pixel(b, -1, 0)));
    tinyweb_show_bitmap(c, b, 0, 0, 10.0);
    tinyweb_show_bitmap(c, b, 5, 5, tinyweb_show_bitmap__default__scale());
    small = tinyweb_bitmap(4, 4);
    tinyweb_fill_bitmap(small, tinyweb_pixel_color(0, 0, 255));
    printf("%s %d\n", "filled:", tinyweb_blue(tinyweb_get_pixel(small, 3, 3)));
    tinyweb_show_bitmap(c, small, 120, 60, 0.5);
    tinyweb_on_frame(frame);

    return 0;
}
