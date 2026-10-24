// Generated from lib_tinyweb_transform.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>
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
#ifndef PYK_FN_F_V
#define PYK_FN_F_V
typedef void (*pyk_fn_f_v)(double);
#endif
void tinyweb_on_frame(pyk_fn_f_v);

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

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void draw(double t);

static void pyk_w_draw(void *env, double p1)
{
    (void)env;
    draw(p1);
}

static void draw(double t)
{
    pyk_d_Dtinyweb_Color__Color__ pyk_t1;
    pyk_d_Dtinyweb_Color__Color__ pyk_t2;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t3;
    pyk_d_Dtinyweb_Color__Color__ pyk_t4;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t5;
    pyk_d_Dtinyweb_Color__Color__ pyk_t6;
    pyk_d_Dtinyweb_Color__Color__ pyk_t7;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t8;
    pyk_d_Dtinyweb_Color__Color__ pyk_t9;
    pyk_d_Dtinyweb_Color__Color__ pyk_t10;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t11;
    pyk_d_Dtinyweb_Color__Color__ pyk_t12;
    pyk_d_Dtinyweb_Color__Color__ pyk_t13;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t14;
    tinyweb_clear(c, tinyweb_color__black);
    tinyweb_push(c);
    tinyweb_translate(c, 100.0, 100.0);
    tinyweb_rotate(c, t * math_pi / 2.0);
    (pyk_t1 = tinyweb_color__hex(14423100), pyk_t2 = tinyweb_rect__default__stroke(), pyk_t3 = tinyweb_rect__default__paint(), (tinyweb_rect(c, -20, -20, 40, 40, pyk_t1, pyk_t2, 1, 1.0, pyk_t3, tinyweb_rect__default__style(), 0), 0));
    tinyweb_push(c);
    tinyweb_scale(c, 0.5, 2.0);
    (pyk_t4 = tinyweb_circle__default__stroke(), pyk_t5 = tinyweb_circle__default__paint(), (tinyweb_circle(c, 60, 0, 10, tinyweb_color__white, pyk_t4, 1, 1.0, pyk_t5, tinyweb_circle__default__style()), 0));
    tinyweb_pop(c);
    tinyweb_pop(c);
    tinyweb_shadow(c, tinyweb_color__white, 12, 0, 0);
    (pyk_t6 = tinyweb_color__hex(16766720), pyk_t7 = tinyweb_circle__default__stroke(), pyk_t8 = tinyweb_circle__default__paint(), (tinyweb_circle(c, 30, 30, 10, pyk_t6, pyk_t7, 1, 1.0, pyk_t8, tinyweb_circle__default__style()), 0));
    tinyweb_shadow(c, tinyweb_color__none, 10, 0, 0);
    tinyweb_blend(c, "add");
    (pyk_t9 = tinyweb_color__hex(8388608), pyk_t10 = tinyweb_circle__default__stroke(), pyk_t11 = tinyweb_circle__default__paint(), (tinyweb_circle(c, 160, 160, 20, pyk_t9, pyk_t10, 1, 1.0, pyk_t11, tinyweb_circle__default__style()), 0));
    (pyk_t12 = tinyweb_color__hex(128), pyk_t13 = tinyweb_circle__default__stroke(), pyk_t14 = tinyweb_circle__default__paint(), (tinyweb_circle(c, 175, 160, 20, pyk_t12, pyk_t13, 1, 1.0, pyk_t14, tinyweb_circle__default__style()), 0));
    tinyweb_blend(c, "normal");
    tinyweb_blend(c, "multiply");
    tinyweb_reset(c);
}

int main(void)
{
    math_init();
    text_init();
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(200, 200);
    tinyweb_on_frame(draw);

    return 0;
}
