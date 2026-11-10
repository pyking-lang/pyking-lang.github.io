// Generated from lib_tinyweb_load_bitmap_top.pyk by the Pyking compiler. Do not edit.
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

#ifndef PYK_TYPE_PYK_T_TII_
#define PYK_TYPE_PYK_T_TII_
typedef struct pyk_t_Tii_ {
    int a0;
    int a1;
} pyk_t_Tii_;
#endif

#ifndef PYK_TYPE_PYK_D_DTINYWEB_COLOR__COLOR__
#define PYK_TYPE_PYK_D_DTINYWEB_COLOR__COLOR__
typedef struct pyk_d_Dtinyweb_Color__Color__ {
    int r;
    int g;
    int b;
    double a;
} pyk_d_Dtinyweb_Color__Color__;
#endif

#ifndef PYK_TYPE_PYK_C_FS_U_
#define PYK_TYPE_PYK_C_FS_U_
typedef struct pyk_c_Fs_u_ {
    void (*fn)(void *, const char *);
    void *env;
    void (*plain)(const char *);
} pyk_c_Fs_u_;
#endif

// What the external modules this one imports implement.
const char *tinyweb_canvas(int, int);

static pyk_t_Tii_ pyk_mk_Tii_(int a0, int a1)
{
    pyk_t_Tii_ v;
    v.a0 = a0;
    v.a1 = a1;
    return v;
}

static pyk_d_Dtinyweb_Color__Color__ pyk_mk_Dtinyweb_Color__Color___Color__Color(int r, int g, int b, double a)
{
    pyk_d_Dtinyweb_Color__Color__ v;
    v.r = r;
    v.g = g;
    v.b = b;
    v.a = a;
    return v;
}

static pyk_c_Fs_u_ pyk_mk_Fs_u_(void (*fn)(void *, const char *), void *env, void (*plain)(const char *))
{
    pyk_c_Fs_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static const char *c;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void loaded(const char *b);

static void pyk_w_loaded(void *env, const char *p1)
{
    (void)env;
    loaded(p1);
}

static void loaded(const char *b)
{
    pyk_t_Tii_ pyk_t1 = tinyweb_bitmap__size(b);
    int w = pyk_t1.a0;
    int h = pyk_t1.a1;
    printf("%s %d %s %d\n", "ball.png is", w, "by", h);
    pyk_d_Dtinyweb_Color__Color__ p = tinyweb_bitmap__get_pixel(b, w / 2, h / 2);
    printf("%s %d %d %d\n", "its middle:", p.r, p.g, p.b);
    tinyweb_bitmap__show_bitmap(c, b, 10, 10, 1.0);
}

int main(void)
{
    math_init();
    text_init();
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(100, 100);
    tinyweb_bitmap__load_bitmap("ball.png", pyk_mk_Fs_u_(pyk_w_loaded, NULL, loaded));
    tinyweb_bitmap__load_bitmap("no_such_picture.png", pyk_mk_Fs_u_(pyk_w_loaded, NULL, loaded));
    printf("%s\n", "asked for two pictures");

    return 0;
}
