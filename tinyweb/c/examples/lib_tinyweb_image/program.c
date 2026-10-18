// Generated from lib_tinyweb_image.pyk by the Pyking compiler. Do not edit.
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
const char *tinyweb_load_image(const char *);
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
static const char *ball;
static const char *star;
static const char *again;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void draw(double t);

static void pyk_w_draw(void *env, double p1)
{
    (void)env;
    draw(p1);
}

static void draw(double t)
{
    tinyweb_clear(c, "#202040");
    tinyweb_image(c, ball, pyk_truncate(t * 100.0), 20, 40, 40, tinyweb_image__default__alpha());
    tinyweb_image(c, star, 140, 20, 50, 50, 0.5);
}

int main(void)
{
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(200, 100);
    ball = tinyweb_load_image("ball.png");
    star = tinyweb_load_image("star.png");
    again = tinyweb_load_image("ball.png");
    printf("%s\n", again);
    tinyweb_on_frame(draw);

    return 0;
}
