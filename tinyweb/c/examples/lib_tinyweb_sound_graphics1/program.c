// Generated from lib_tinyweb_sound_graphics1.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static const char *pyk_int_str(int n)
{
    char *out = malloc(24);
    sprintf(out, "%d", n);
    return out;
}

static const char *pyk_concat(const char *a, const char *b)
{
    size_t la = strlen(a);
    size_t lb = strlen(b);
    char *result = malloc(la + lb + 1);
    memcpy(result, a, la);
    memcpy(result + la, b, lb + 1);
    return result;
}

static pyk_c_F_u_ pyk_mk_F_u_(void (*fn)(void *), void *env, void (*plain)(void))
{
    pyk_c_F_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static const char *kick;
static const char *snare;
static const char *canvas;
static int presses;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void play_kick(void);
static void play_sound(void);

static void pyk_w_play_kick(void *env)
{
    (void)env;
    play_kick();
}

static void pyk_w_play_sound(void *env)
{
    (void)env;
    play_sound();
}

static void play_kick(void)
{
    double pyk_t6;
    double pyk_t7;
    (pyk_t6 = tinyweb_play__default__at(), pyk_t7 = tinyweb_play__default__volume(), (tinyweb_play(kick, pyk_t6, pyk_t7, tinyweb_play__default__rate()), 0));
}

static void play_sound(void)
{
    double pyk_t8;
    presses = presses + 1;
    printf("%s\n", pyk_concat("snare, press ", pyk_int_str(presses)));
    (pyk_t8 = tinyweb_play__default__at(), (tinyweb_play(snare, pyk_t8, 0.5, tinyweb_play__default__rate()), 0));
}

int main(void)
{
    const char *pyk_t1;
    int pyk_t2;
    const char *pyk_t3;
    const char *pyk_t4;
    int pyk_t5;
    tinyweb_init();
    tinyweb_web_init(0);
    kick = tinyweb_load_sample("kick1.wav");
    snare = tinyweb_load_sample("snare1.wav");
    canvas = tinyweb_canvas(400, 200);
    (pyk_t1 = tinyweb_circle__default__outline(), pyk_t2 = tinyweb_circle__default__outline_width(), (tinyweb_circle(canvas, 100, 50, 30, "#ff0000", pyk_t1, pyk_t2, tinyweb_circle__default__alpha()), 0));
    (pyk_t3 = tinyweb_circle__default__color(), pyk_t4 = tinyweb_circle__default__outline(), pyk_t5 = tinyweb_circle__default__outline_width(), (tinyweb_circle(canvas, 100, 50, 20, pyk_t3, pyk_t4, pyk_t5, tinyweb_circle__default__alpha()), 0));
    presses = 0;
    tinyweb_button("Play kick", pyk_mk_F_u_(pyk_w_play_kick, NULL, play_kick));
    tinyweb_button("Play snare", pyk_mk_F_u_(pyk_w_play_sound, NULL, play_sound));
    tinyweb_button("Does nothing", tinyweb_button__default__on_click());
    printf("%s\n", "built the page");
    tinyweb_splash();

    return 0;
}
