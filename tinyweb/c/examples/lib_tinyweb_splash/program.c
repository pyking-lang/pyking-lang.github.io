// Generated from lib_tinyweb_splash.pyk by the Pyking compiler. Do not edit.
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

#ifndef PYK_TYPE_PYK_C_F_U_
#define PYK_TYPE_PYK_C_F_U_
typedef struct pyk_c_F_u_ {
    void (*fn)(void *);
    void *env;
    void (*plain)(void);
} pyk_c_F_u_;
#endif

// What the external modules this one imports implement.
const char *tinyweb_canvas(int, int);
const char *tinyweb_load_sample(const char *);
void tinyweb_splash(void);
void tinyweb_set_splash(const char *);

static pyk_c_F_u_ pyk_mk_F_u_(void (*fn)(void *), void *env, void (*plain)(void))
{
    pyk_c_F_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static const char *c;
static const char *kick;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void again(void);

static void pyk_w_again(void *env)
{
    (void)env;
    again();
}

static void again(void)
{
    double pyk_t4;
    double pyk_t5;
    (pyk_t4 = tinyweb_play__default__at(), pyk_t5 = tinyweb_play__default__volume(), (tinyweb_play(kick, pyk_t4, pyk_t5, tinyweb_play__default__rate()), 0));
    printf("%s\n", "kick again");
}

int main(void)
{
    double pyk_t1;
    const char *pyk_t2;
    int pyk_t3;
    tinyweb_init();
    tinyweb_web_init(0);
    tinyweb_set_splash("Click for drums");
    c = tinyweb_canvas(200, 100);
    tinyweb_clear(c, "#202020");
    kick = tinyweb_load_sample("kick1.wav");
    (pyk_t1 = tinyweb_play__default__volume(), (tinyweb_play(kick, 0.25, pyk_t1, tinyweb_play__default__rate()), 0));
    (pyk_t2 = tinyweb_circle__default__outline(), pyk_t3 = tinyweb_circle__default__outline_width(), (tinyweb_circle(c, 100, 50, 30, "#ffcc00", pyk_t2, pyk_t3, tinyweb_circle__default__alpha()), 0));
    tinyweb_button("Again", pyk_mk_F_u_(pyk_w_again, NULL, again));
    printf("%s\n", "built the page");
    tinyweb_splash();

    return 0;
}
