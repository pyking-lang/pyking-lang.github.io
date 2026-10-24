// Generated from lib_tinyweb_paint.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdlib.h>

// Every multiply and add rounded on its own, as on every other target.
#if defined(__clang__)
#pragma STDC FP_CONTRACT OFF
#elif defined(__GNUC__)
#pragma GCC optimize ("fp-contract=off")
#endif

#include "math.h"
#include "text.h"
#include "tinyweb.h"

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
static pyk_d_Dtinyweb_Color__Paint__ sky;
static pyk_d_Dtinyweb_Color__Paint__ ball;
static pyk_d_Dtinyweb_Color__Paint__ wheel;
static pyk_d_Dtinyweb_Style__ outlined;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void underline(double width);

static void pyk_w_underline(void *env, double p1)
{
    (void)env;
    underline(p1);
}

static void underline(double width)
{
    tinyweb_line(c, 10, 60, 10 + pyk_truncate(width), 60, tinyweb_color__white, 2, 1.0, tinyweb_line__default__style());
}

int main(void)
{
    pyk_d_Dtinyweb_Color__Color__ pyk_t1;
    pyk_d_Dtinyweb_Color__Color__ pyk_t2;
    pyk_d_Dtinyweb_Color__Color__ pyk_t3;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t4;
    pyk_d_Dtinyweb_Color__Color__ pyk_t5;
    pyk_d_Dtinyweb_Color__Color__ pyk_t6;
    pyk_d_Dtinyweb_Color__Color__ pyk_t7;
    pyk_d_Dtinyweb_Style__ pyk_t8;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t9;
    pyk_d_Dtinyweb_Color__Color__ pyk_t10;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t11;
    pyk_d_Dtinyweb_Color__Color__ pyk_t12;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t13;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t14;
    pyk_d_Dtinyweb_Color__Color__ pyk_t15;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t16;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t17;
    pyk_d_Dtinyweb_Color__Color__ pyk_t18;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t19;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t20;
    pyk_d_Dtinyweb_Color__Color__ pyk_t21;
    pyk_d_Dtinyweb_Color__Color__ pyk_t22;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t23;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t24;
    pyk_d_Dtinyweb_Color__Color__ pyk_t25;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t26;
    pyk_d_Dtinyweb_Color__Color__ pyk_t27;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t28;
    pyk_d_Dtinyweb_Color__Color__ pyk_t29;
    pyk_d_Dtinyweb_Color__Color__ pyk_t30;
    pyk_d_Dtinyweb_Color__Color__ pyk_t31;
    pyk_d_Dtinyweb_Color__Color__ pyk_t32;
    pyk_d_Dtinyweb_Color__Color__ pyk_t33;
    pyk_d_Dtinyweb_Color__Color__ pyk_t34;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t35;
    pyk_d_Dtinyweb_Color__Color__ pyk_t36;
    pyk_d_Dtinyweb_Color__Color__ pyk_t37;
    math_init();
    text_init();
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(300, 200);
    sky = (pyk_t1 = tinyweb_color__hex(1713022), pyk_mk_Dtinyweb_Color__Paint___Color__Linear(0.0, 0.0, 0.0, 200.0, pyk_t1, tinyweb_color__hex(16758605), ""));
    (pyk_t2 = tinyweb_rect__default__fill(), pyk_t3 = tinyweb_rect__default__stroke(), pyk_t4 = tinyweb_color__stop(sky, 0.6, tinyweb_color__hex(15277667)), (tinyweb_rect(c, 0, 0, 300, 200, pyk_t2, pyk_t3, 1, 1.0, pyk_t4, tinyweb_rect__default__style(), 0), 0));
    ball = pyk_mk_Dtinyweb_Color__Paint___Color__Radial(40.0, 40.0, 4.0, 50.0, 50.0, 30.0, tinyweb_color__white, tinyweb_color__hex(14423100), "");
    (pyk_t5 = tinyweb_circle__default__fill(), pyk_t6 = tinyweb_circle__default__stroke(), (tinyweb_circle(c, 50, 50, 30, pyk_t5, pyk_t6, 1, 1.0, ball, tinyweb_circle__default__style()), 0));
    wheel = tinyweb_color__stop(tinyweb_color__stop(pyk_mk_Dtinyweb_Color__Paint___Color__Conic(150.0, 50.0, math_pi / 2.0, tinyweb_color__red, tinyweb_color__red, ""), 0.33, tinyweb_color__hex(65280)), 0.67, tinyweb_color__blue);
    (pyk_t7 = tinyweb_circle__default__fill(), (pyk_t8 = tinyweb_circle__default__style(), (tinyweb_circle(c, 150, 50, 30, pyk_t7, tinyweb_color__white, 2, 1.0, wheel, pyk_t8), 0)));
    tinyweb_push(c);
    tinyweb_line_style(c, "butt", "bevel", 8.0, 4.0, 2.0, 0.0, 0.0);
    (pyk_t9 = tinyweb_rect__default__paint(), (tinyweb_rect(c, 200, 20, 80, 60, tinyweb_color__none, tinyweb_color__white, 3, 1.0, pyk_t9, tinyweb_rect__default__style(), 0), 0));
    tinyweb_line_style(c, "round", "round", 3.0, 0.0, 0.0, 0.0, 0.0);
    tinyweb_line(c, 200, 90, 280, 90, tinyweb_color__yellow, 2, 1.0, tinyweb_line__default__style());
    tinyweb_pop(c);
    tinyweb_push(c);
    tinyweb_clip_rect(c, 10, 100, 60, 40);
    (pyk_t10 = tinyweb_circle__default__stroke(), pyk_t11 = tinyweb_circle__default__paint(), (tinyweb_circle(c, 40, 120, 35, tinyweb_color__orange, pyk_t10, 1, 1.0, pyk_t11, tinyweb_circle__default__style()), 0));
    tinyweb_pop(c);
    tinyweb_push(c);
    tinyweb_clip_circle(c, 120, 130, 25);
    (pyk_t12 = tinyweb_rect__default__stroke(), pyk_t13 = tinyweb_rect__default__paint(), (tinyweb_rect(c, 90, 100, 60, 60, tinyweb_color__teal, pyk_t12, 1, 1.0, pyk_t13, tinyweb_rect__default__style(), 0), 0));
    tinyweb_pop(c);
    tinyweb_bezier(c, 160, 160, 190, 100, 230, 200, 260, 120, tinyweb_color__black, 3, 1.0, tinyweb_bezier__default__style());
    tinyweb_erase(c, 270, 150, 20, 20);
    (pyk_t14 = tinyweb_text__default__paint(), (tinyweb_text(c, 10, 190, "bottom", tinyweb_color__white, 14, "", "left", false, 1.0, "bottom", tinyweb_color__black, 3, pyk_t14, tinyweb_text__default__style()), 0));
    (pyk_t15 = tinyweb_text__default__stroke(), pyk_t16 = tinyweb_text__default__paint(), (tinyweb_text(c, 80, 185, "middle", tinyweb_color__white, 14, "", "left", false, 1.0, "middle", pyk_t15, 1, pyk_t16, tinyweb_text__default__style()), 0));
    (pyk_t17 = tinyweb_text__default__paint(), (tinyweb_text(c, 150, 185, "alphabetic", tinyweb_color__none, 14, "", "left", false, 1.0, "alphabetic", tinyweb_color__white, 1, pyk_t17, tinyweb_text__default__style()), 0));
    (pyk_t18 = tinyweb_color__hex(16766720), pyk_t19 = tinyweb_smooth__circle__default__paint(), (tinyweb_smooth__circle(c, 250.5, 130.25, 6.5, pyk_t18, tinyweb_color__black, 0.5, 1.0, pyk_t19, tinyweb_smooth__circle__default__style()), 0));
    (pyk_t20 = tinyweb_smooth__rect__default__paint(), (tinyweb_smooth__rect(c, 200.5, 100.5, 30.0, 15.0, tinyweb_color__none, tinyweb_color__white, 1.0, 1.0, pyk_t20, tinyweb_smooth__rect__default__style(), 4.0), 0));
    (pyk_t21 = tinyweb_color__hex(14524637), pyk_t22 = tinyweb_smooth__ellipse__default__stroke(), pyk_t23 = tinyweb_smooth__ellipse__default__paint(), (tinyweb_smooth__ellipse(c, 100.0, 180.0, 12.5, 6.25, pyk_t21, pyk_t22, 1.0, 1.0, pyk_t23, tinyweb_smooth__ellipse__default__style()), 0));
    (pyk_t24 = tinyweb_smooth__arc__default__paint(), (tinyweb_smooth__arc(c, 30.0, 170.0, 10.0, 0.0, 1.5 * math_pi, tinyweb_color__none, tinyweb_color__cyan, 2.5, 1.0, pyk_t24, tinyweb_smooth__arc__default__style()), 0));
    tinyweb_smooth__line(c, 0.0, 199.5, 300.0, 198.5, tinyweb_color__white, 0.8, 1.0, tinyweb_smooth__line__default__style());
    tinyweb_smooth__curve(c, 5.0, 5.0, 50.0, 0.5, 95.0, 5.0, tinyweb_color__white, 1.5, 1.0, tinyweb_smooth__curve__default__style());
    tinyweb_smooth__bezier(c, 5.0, 95.0, 30.0, 70.0, 70.0, 120.0, 95.0, 95.0, tinyweb_color__white, 1.5, 0.5, tinyweb_smooth__bezier__default__style());
    (pyk_t25 = tinyweb_smooth__text__default__stroke(), pyk_t26 = tinyweb_smooth__text__default__paint(), (tinyweb_smooth__text(c, 150.5, 100.25, "smooth", tinyweb_color__white, 12, "", "center", false, 1.0, "middle", pyk_t25, 1.0, pyk_t26, tinyweb_smooth__text__default__style()), 0));
    tinyweb_push(c);
    tinyweb_smooth__clip_circle(c, 50.5, 50.5, 20.0);
    (pyk_t27 = tinyweb_rect__default__stroke(), pyk_t28 = tinyweb_rect__default__paint(), (tinyweb_rect(c, 30, 30, 20, 40, tinyweb_color__black, pyk_t27, 1, 0.3, pyk_t28, tinyweb_rect__default__style(), 0), 0));
    tinyweb_pop(c);
    outlined = pyk_mk_Dtinyweb_Style___Style(tinyweb_color__navy, tinyweb_color__yellow, 2, 0.8, tinyweb_field__default__Style__paint());
    (pyk_t29 = tinyweb_circle__default__fill(), pyk_t30 = tinyweb_circle__default__stroke(), (tinyweb_circle(c, 20, 20, 8, pyk_t29, pyk_t30, 1, 1.0, tinyweb_circle__default__paint(), outlined), 0));
    (pyk_t31 = tinyweb_rect__default__stroke(), (tinyweb_rect(c, 40, 10, 20, 20, tinyweb_color__red, pyk_t31, 1, 1.0, tinyweb_rect__default__paint(), outlined, 0), 0));
    tinyweb_line(c, 0, 0, 30, 30, tinyweb_line__default__stroke(), 1, 1.0, outlined);
    (pyk_t33 = tinyweb_circle__default__fill(), pyk_t34 = tinyweb_circle__default__stroke(), pyk_t35 = tinyweb_circle__default__paint(), (tinyweb_circle(c, 70, 20, 8, pyk_t33, pyk_t34, 1, 1.0, pyk_t35, (pyk_t32 = tinyweb_field__default__Style__fill(), pyk_mk_Dtinyweb_Style___Style(pyk_t32, tinyweb_field__default__Style__stroke(), 1, 1.0, ball))), 0));
    (pyk_t36 = tinyweb_smooth__circle__default__fill(), pyk_t37 = tinyweb_smooth__circle__default__stroke(), (tinyweb_smooth__circle(c, 90.0, 20.0, 8.0, pyk_t36, pyk_t37, 1.0, 1.0, tinyweb_smooth__circle__default__paint(), outlined), 0));
    tinyweb_measure_text("Hello, canvas!", pyk_mk_Ff_u_(pyk_w_underline, NULL, underline), 20, "", true);

    return 0;
}
