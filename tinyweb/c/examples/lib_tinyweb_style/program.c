// Generated from lib_tinyweb_style.pyk by the Pyking compiler. Do not edit.
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
const char *tinyweb_label(const char *);

static pyk_d_Dtinyweb_Color__Color__ pyk_mk_Dtinyweb_Color__Color___Color__Color(int r, int g, int b, double a)
{
    pyk_d_Dtinyweb_Color__Color__ v;
    v.r = r;
    v.g = g;
    v.b = b;
    v.a = a;
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

static const char *title;
static const char *level;
static const char *c;
static const char *ok;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void pressed(void);

static void pyk_w_pressed(void *env)
{
    (void)env;
    pressed();
}

static void pressed(void)
{
    pyk_d_Dtinyweb_Color__Color__ pyk_t10;
    pyk_d_Dtinyweb_Color__Color__ pyk_t11;
    tinyweb_theme("retro");
    (pyk_t10 = tinyweb_set_style__default__foreground(), pyk_t11 = tinyweb_set_style__default__border(), (tinyweb_set_style(title, tinyweb_color__black, pyk_t10, pyk_t11, -1, -1, "", -1, -1, tinyweb_set_style__default__accent(), -1, -1, -1), 0));
    printf("%s\n", "now retro");
}

int main(void)
{
    pyk_d_Dtinyweb_Color__Color__ pyk_t1;
    pyk_d_Dtinyweb_Color__Color__ pyk_t2;
    pyk_d_Dtinyweb_Color__Color__ pyk_t3;
    pyk_d_Dtinyweb_Color__Color__ pyk_t4;
    pyk_d_Dtinyweb_Color__Color__ pyk_t5;
    pyk_d_Dtinyweb_Color__Color__ pyk_t6;
    pyk_d_Dtinyweb_Color__Color__ pyk_t7;
    pyk_d_Dtinyweb_Color__Color__ pyk_t8;
    pyk_d_Dtinyweb_Color__Color__ pyk_t9;
    pyk_d_Dtinyweb_Color__Color__ pyk_t12;
    pyk_d_Dtinyweb_Color__Color__ pyk_t13;
    pyk_d_Dtinyweb_Color__Color__ pyk_t14;
    math_init();
    text_init();
    tinyweb_init();
    tinyweb_web_init(0);
    tinyweb_theme("paper");
    tinyweb_theme("no such theme");
    (pyk_t1 = tinyweb_color__hex(16643811), (tinyweb_page_style(pyk_t1, tinyweb_color__hex(5795445), "serif", 18, 12, 16, ""), 0));
    tinyweb_button_style(tinyweb_color__hex(2526162), tinyweb_color__white, tinyweb_color__none, -1, 14, "monospace", 16, 8);
    (pyk_t2 = tinyweb_color__hex(16777184), pyk_t3 = tinyweb_color__hex(3355443), (tinyweb_label_style(pyk_t2, pyk_t3, tinyweb_color__hex(16766720), 1, 4, "sans-serif", 14, 6), 0));
    (pyk_t4 = tinyweb_color__hex(14423100), (tinyweb_slider_style(pyk_t4, 240, tinyweb_color__hex(14423100), "monospace", 20), 0));
    tinyweb_canvas_style(tinyweb_color__teal, 3, 10);
    title = tinyweb_label("Styled");
    tinyweb_set_style(title, tinyweb_color__navy, tinyweb_color__white, tinyweb_color__orange, 2, 0, "Georgia", 28, 10, tinyweb_set_style__default__accent(), 300, -1, -1);
    level = tinyweb_slider(0, 10, 4, tinyweb_slider__default__on_change());
    (pyk_t5 = tinyweb_set_style__default__background(), pyk_t6 = tinyweb_color__hex(3050327), pyk_t7 = tinyweb_set_style__default__border(), (tinyweb_set_style(level, pyk_t5, pyk_t6, pyk_t7, -1, -1, "", -1, -1, tinyweb_set_style__default__accent(), -1, -1, -1), 0));
    c = tinyweb_canvas(120, 60);
    (pyk_t8 = tinyweb_set_style__default__background(), pyk_t9 = tinyweb_set_style__default__foreground(), (tinyweb_set_style(c, pyk_t8, pyk_t9, tinyweb_color__black, 1, -1, "", -1, -1, tinyweb_set_style__default__accent(), -1, -1, -1), 0));
    ok = tinyweb_button("Retro", pyk_mk_F_u_(pyk_w_pressed, NULL, pressed));
    (pyk_t12 = tinyweb_color__rgba(255, 215, 0, 0.5), (pyk_t13 = tinyweb_set_style__default__border(), (pyk_t14 = tinyweb_set_style__default__accent(), (tinyweb_set_style(ok, pyk_t12, tinyweb_color__black, pyk_t13, -1, -1, "", -1, -1, pyk_t14, -1, -1, -1), 0))));

    return 0;
}
