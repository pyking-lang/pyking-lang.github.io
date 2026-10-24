// Generated from lib_tinyweb_splash_voice.pyk by the Pyking compiler. Do not edit.
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

#ifndef PYK_TYPE_PYK_D_DTINYWEB_SOUND__VOICE__
#define PYK_TYPE_PYK_D_DTINYWEB_SOUND__VOICE__
typedef struct pyk_d_Dtinyweb_Sound__Voice__ {
    double volume;
    double rate;
    double pan;
    int channel;
    bool looping;
    bool reverse;
} pyk_d_Dtinyweb_Sound__Voice__;
#endif

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

static pyk_d_Dtinyweb_Sound__Voice__ pyk_mk_Dtinyweb_Sound__Voice___Sound__Voice(double volume, double rate, double pan, int channel, bool looping, bool reverse)
{
    pyk_d_Dtinyweb_Sound__Voice__ v;
    v.volume = volume;
    v.rate = rate;
    v.pan = pan;
    v.channel = channel;
    v.looping = looping;
    v.reverse = reverse;
    return v;
}

static pyk_c_F_u_ pyk_mk_F_u_(void (*fn)(void *), void *env, void (*plain)(void))
{
    pyk_c_F_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void hum(void);

static void pyk_w_hum(void *env)
{
    (void)env;
    hum();
}

static void hum(void)
{
    const char *pyk_t1;
    pyk_d_Dtinyweb_Sound__Voice__ pyk_t2;
    printf("%s\n", (pyk_t1 = tinyweb_load_sample("piano_c1.wav"), (pyk_t2 = tinyweb_sound__start__default__voice(), tinyweb_sound__start(pyk_t1, 0.0, 0.3, 1.0, 0.0, true, pyk_t2))));
}

int main(void)
{
    math_init();
    text_init();
    tinyweb_init();
    tinyweb_web_init(0);
    tinyweb_sound__tone(tinyweb_sound__note("A4"), 0.0, 0.25, "sine", 0.5, 0.0, 0);
    tinyweb_button("Hum", pyk_mk_F_u_(pyk_w_hum, NULL, hum));
    tinyweb_splash();

    return 0;
}
