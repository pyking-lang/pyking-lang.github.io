// Generated from lib_tinyweb_paint.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

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

static const char *c;
static const char *sky;
static const char *sky2;
static const char *ball;
static const char *wheel;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void underline(double width);

static void pyk_w_underline(void *env, double p1)
{
    (void)env;
    underline(p1);
}

static void underline(double width)
{
    tinyweb_line(c, 10, 60, 10 + pyk_truncate(width), 60, "white", 2, tinyweb_line__default__alpha());
}

int main(void)
{
    const char *pyk_t1;
    int pyk_t2;
    double pyk_t3;
    double pyk_t4;
    const char *pyk_t5;
    const char *pyk_t6;
    double pyk_t7;
    double pyk_t8;
    double pyk_t9;
    const char *pyk_t10;
    int pyk_t11;
    const char *pyk_t12;
    int pyk_t13;
    double pyk_t14;
    const char *pyk_t15;
    const char *pyk_t16;
    bool pyk_t17;
    const char *pyk_t18;
    const char *pyk_t19;
    bool pyk_t20;
    double pyk_t21;
    const char *pyk_t22;
    const char *pyk_t23;
    const char *pyk_t24;
    bool pyk_t25;
    double pyk_t26;
    double pyk_t27;
    const char *pyk_t28;
    double pyk_t29;
    const char *pyk_t30;
    bool pyk_t31;
    double pyk_t32;
    const char *pyk_t33;
    const char *pyk_t34;
    int pyk_t35;
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(300, 200);
    sky = tinyweb_colors__linear_gradient(0.0, 0.0, 0.0, 200.0, "#1a237e", "#ffb74d");
    sky2 = tinyweb_colors__stop(sky, 0.6, "#e91e63");
    tinyweb_clear(c, sky2);
    ball = tinyweb_colors__radial_gradient(40.0, 40.0, 4.0, 50.0, 50.0, 30.0, "white", "crimson");
    (pyk_t1 = tinyweb_circle__default__outline(), pyk_t2 = tinyweb_circle__default__outline_width(), (tinyweb_circle(c, 50, 50, 30, ball, pyk_t1, pyk_t2, tinyweb_circle__default__alpha()), 0));
    wheel = tinyweb_colors__stop(tinyweb_colors__stop(tinyweb_colors__conic_gradient(150.0, 50.0, 90.0, "red", "red"), 0.33, "lime"), 0.67, "blue");
    tinyweb_circle(c, 150, 50, 30, wheel, "white", 2, tinyweb_circle__default__alpha());
    tinyweb_push(c);
    (pyk_t3 = tinyweb_line_style__default__dash2(), (tinyweb_line_style(c, "butt", "bevel", 8.0, 4.0, 2.0, pyk_t3, tinyweb_line_style__default__gap2()), 0));
    (pyk_t4 = tinyweb_rect__default__alpha(), (tinyweb_rect(c, 200, 20, 80, 60, "", "white", 3, pyk_t4, tinyweb_rect__default__radius()), 0));
    (pyk_t5 = tinyweb_line_style__default__cap(), pyk_t6 = tinyweb_line_style__default__join(), pyk_t7 = tinyweb_line_style__default__gap(), pyk_t8 = tinyweb_line_style__default__offset(), pyk_t9 = tinyweb_line_style__default__dash2(), (tinyweb_line_style(c, pyk_t5, pyk_t6, 3.0, pyk_t7, pyk_t8, pyk_t9, tinyweb_line_style__default__gap2()), 0));
    tinyweb_line(c, 200, 90, 280, 90, "yellow", 2, tinyweb_line__default__alpha());
    tinyweb_pop(c);
    tinyweb_push(c);
    tinyweb_clip_rect(c, 10, 100, 60, 40);
    (pyk_t10 = tinyweb_circle__default__outline(), pyk_t11 = tinyweb_circle__default__outline_width(), (tinyweb_circle(c, 40, 120, 35, "orange", pyk_t10, pyk_t11, tinyweb_circle__default__alpha()), 0));
    tinyweb_pop(c);
    tinyweb_push(c);
    tinyweb_clip_circle(c, 120, 130, 25);
    (pyk_t12 = tinyweb_rect__default__outline(), pyk_t13 = tinyweb_rect__default__outline_width(), pyk_t14 = tinyweb_rect__default__alpha(), (tinyweb_rect(c, 90, 100, 60, 60, "teal", pyk_t12, pyk_t13, pyk_t14, tinyweb_rect__default__radius()), 0));
    tinyweb_pop(c);
    tinyweb_bezier(c, 160, 160, 190, 100, 230, 200, 260, 120, "black", 3, tinyweb_bezier__default__alpha());
    tinyweb_erase(c, 270, 150, 20, 20);
    (pyk_t15 = tinyweb_text__default__font(), pyk_t16 = tinyweb_text__default__align(), pyk_t17 = tinyweb_text__default__bold(), (tinyweb_text(c, 10, 190, "bottom", "white", 14, pyk_t15, pyk_t16, pyk_t17, tinyweb_text__default__alpha(), "bottom", "black", 3), 0));
    (pyk_t18 = tinyweb_text__default__font(), pyk_t19 = tinyweb_text__default__align(), pyk_t20 = tinyweb_text__default__bold(), pyk_t21 = tinyweb_text__default__alpha(), pyk_t22 = tinyweb_text__default__outline(), (tinyweb_text(c, 80, 185, "middle", "white", 14, pyk_t18, pyk_t19, pyk_t20, pyk_t21, "middle", pyk_t22, tinyweb_text__default__outline_width()), 0));
    (pyk_t23 = tinyweb_text__default__font(), pyk_t24 = tinyweb_text__default__align(), pyk_t25 = tinyweb_text__default__bold(), pyk_t26 = tinyweb_text__default__alpha(), (tinyweb_text(c, 150, 185, "alphabetic", "", 14, pyk_t23, pyk_t24, pyk_t25, pyk_t26, "alphabetic", "white", tinyweb_text__default__outline_width()), 0));
    tinyweb_smooth__circle(c, 250.5, 130.25, 6.5, "gold", "black", 0.5, tinyweb_smooth__circle__default__alpha());
    (pyk_t27 = tinyweb_smooth__rect__default__outline_width(), (tinyweb_smooth__rect(c, 200.5, 100.5, 30.0, 15.0, "", "white", pyk_t27, tinyweb_smooth__rect__default__alpha(), 4.0), 0));
    (pyk_t28 = tinyweb_smooth__ellipse__default__outline(), pyk_t29 = tinyweb_smooth__ellipse__default__outline_width(), (tinyweb_smooth__ellipse(c, 100.0, 180.0, 12.5, 6.25, "plum", pyk_t28, pyk_t29, tinyweb_smooth__ellipse__default__alpha()), 0));
    tinyweb_smooth__arc(c, 30.0, 170.0, 10.0, 0.0, 270.0, "", "cyan", 2.5, tinyweb_smooth__arc__default__alpha());
    tinyweb_smooth__line(c, 0.0, 199.5, 300.0, 198.5, "white", 0.8, tinyweb_smooth__line__default__alpha());
    tinyweb_smooth__curve(c, 5.0, 5.0, 50.0, 0.5, 95.0, 5.0, "white", 1.5, tinyweb_smooth__curve__default__alpha());
    tinyweb_smooth__bezier(c, 5.0, 95.0, 30.0, 70.0, 70.0, 120.0, 95.0, 95.0, "white", 1.5, 0.5);
    (pyk_t30 = tinyweb_smooth__text__default__font(), pyk_t31 = tinyweb_smooth__text__default__bold(), pyk_t32 = tinyweb_smooth__text__default__alpha(), pyk_t33 = tinyweb_smooth__text__default__outline(), (tinyweb_smooth__text(c, 150.5, 100.25, "smooth", "white", 12, pyk_t30, "center", pyk_t31, pyk_t32, "middle", pyk_t33, tinyweb_smooth__text__default__outline_width()), 0));
    tinyweb_push(c);
    tinyweb_smooth__clip_circle(c, 50.5, 50.5, 20.0);
    (pyk_t34 = tinyweb_rect__default__outline(), pyk_t35 = tinyweb_rect__default__outline_width(), (tinyweb_rect(c, 30, 30, 20, 40, "black", pyk_t34, pyk_t35, 0.3, tinyweb_rect__default__radius()), 0));
    tinyweb_pop(c);
    tinyweb_measure_text("Hello, canvas!", pyk_mk_Ff_u_(pyk_w_underline, NULL, underline), 20, tinyweb_measure_text__default__font(), true);

    return 0;
}
