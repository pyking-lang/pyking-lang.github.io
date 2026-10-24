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
    tinyweb_play(kick, 0.0, 1.0, 1.0, 0.0, tinyweb_play__default__voice());
}

static void play_sound(void)
{
    presses = presses + 1;
    printf("%s\n", pyk_concat("snare, press ", pyk_int_str(presses)));
    tinyweb_play(snare, 0.0, 0.5, 1.0, 0.0, tinyweb_play__default__voice());
}

int main(void)
{
    pyk_d_Dtinyweb_Color__Color__ pyk_t1;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t2;
    pyk_d_Dtinyweb_Color__Color__ pyk_t3;
    pyk_d_Dtinyweb_Color__Color__ pyk_t4;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t5;
    math_init();
    text_init();
    tinyweb_init();
    tinyweb_web_init(0);
    kick = tinyweb_load_sample("kick1.wav");
    snare = tinyweb_load_sample("snare1.wav");
    canvas = tinyweb_canvas(400, 200);
    (pyk_t1 = tinyweb_circle__default__stroke(), pyk_t2 = tinyweb_circle__default__paint(), (tinyweb_circle(canvas, 100, 50, 30, tinyweb_color__red, pyk_t1, 1, 1.0, pyk_t2, tinyweb_circle__default__style()), 0));
    (pyk_t3 = tinyweb_circle__default__fill(), pyk_t4 = tinyweb_circle__default__stroke(), pyk_t5 = tinyweb_circle__default__paint(), (tinyweb_circle(canvas, 100, 50, 20, pyk_t3, pyk_t4, 1, 1.0, pyk_t5, tinyweb_circle__default__style()), 0));
    presses = 0;
    tinyweb_button("Play kick", pyk_mk_F_u_(pyk_w_play_kick, NULL, play_kick));
    tinyweb_button("Play snare", pyk_mk_F_u_(pyk_w_play_sound, NULL, play_sound));
    tinyweb_button("Does nothing", tinyweb_button__default__on_click());
    printf("%s\n", "built the page");
    tinyweb_splash();

    return 0;
}
