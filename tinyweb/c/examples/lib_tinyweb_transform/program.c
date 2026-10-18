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
#ifndef PYK_FN_F_V
#define PYK_FN_F_V
typedef void (*pyk_fn_f_v)(double);
#endif
void tinyweb_on_frame(pyk_fn_f_v);

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
    const char *pyk_t1;
    int pyk_t2;
    double pyk_t3;
    const char *pyk_t4;
    int pyk_t5;
    int pyk_t6;
    const char *pyk_t7;
    int pyk_t8;
    int pyk_t9;
    int pyk_t10;
    const char *pyk_t11;
    int pyk_t12;
    const char *pyk_t13;
    int pyk_t14;
    tinyweb_clear(c, "black");
    tinyweb_push(c);
    tinyweb_translate(c, 100.0, 100.0);
    tinyweb_rotate(c, t * 90.0);
    (pyk_t1 = tinyweb_rect__default__outline(), pyk_t2 = tinyweb_rect__default__outline_width(), pyk_t3 = tinyweb_rect__default__alpha(), (tinyweb_rect(c, -20, -20, 40, 40, "crimson", pyk_t1, pyk_t2, pyk_t3, tinyweb_rect__default__radius()), 0));
    tinyweb_push(c);
    tinyweb_scale(c, 0.5, 2.0);
    (pyk_t4 = tinyweb_circle__default__outline(), pyk_t5 = tinyweb_circle__default__outline_width(), (tinyweb_circle(c, 60, 0, 10, "white", pyk_t4, pyk_t5, tinyweb_circle__default__alpha()), 0));
    tinyweb_pop(c);
    tinyweb_pop(c);
    (pyk_t6 = tinyweb_shadow__default__dx(), (tinyweb_shadow(c, "white", 12, pyk_t6, tinyweb_shadow__default__dy()), 0));
    (pyk_t7 = tinyweb_circle__default__outline(), pyk_t8 = tinyweb_circle__default__outline_width(), (tinyweb_circle(c, 30, 30, 10, "gold", pyk_t7, pyk_t8, tinyweb_circle__default__alpha()), 0));
    (pyk_t9 = tinyweb_shadow__default__blur(), pyk_t10 = tinyweb_shadow__default__dx(), (tinyweb_shadow(c, "", pyk_t9, pyk_t10, tinyweb_shadow__default__dy()), 0));
    tinyweb_blend(c, "add");
    (pyk_t11 = tinyweb_circle__default__outline(), pyk_t12 = tinyweb_circle__default__outline_width(), (tinyweb_circle(c, 160, 160, 20, "#800000", pyk_t11, pyk_t12, tinyweb_circle__default__alpha()), 0));
    (pyk_t13 = tinyweb_circle__default__outline(), pyk_t14 = tinyweb_circle__default__outline_width(), (tinyweb_circle(c, 175, 160, 20, "#000080", pyk_t13, pyk_t14, tinyweb_circle__default__alpha()), 0));
    tinyweb_blend(c, "normal");
    tinyweb_blend(c, "multiply");
    tinyweb_reset(c);
}

int main(void)
{
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(200, 200);
    tinyweb_on_frame(draw);

    return 0;
}
