// Generated from lib_tinyweb_splash_off.pyk by the Pyking compiler. Do not edit.
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

static const char *snare;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void hit(void);

static void pyk_w_hit(void *env)
{
    (void)env;
    hit();
}

static void hit(void)
{
    double pyk_t1;
    (pyk_t1 = tinyweb_play__default__at(), (tinyweb_play(snare, pyk_t1, 0.5, tinyweb_play__default__rate()), 0));
    printf("%s\n", "hit");
}

int main(void)
{
    tinyweb_init();
    tinyweb_web_init(0);
    tinyweb_set_splash("");
    snare = tinyweb_load_sample("snare1.wav");
    tinyweb_button("Hit", pyk_mk_F_u_(pyk_w_hit, NULL, hit));
    tinyweb_splash();

    return 0;
}
