// Generated from lib_tinyweb_input.pyk by the Pyking compiler. Do not edit.
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

#ifndef PYK_TYPE_PYK_C_FII_U_
#define PYK_TYPE_PYK_C_FII_U_
typedef struct pyk_c_Fii_u_ {
    void (*fn)(void *, int, int);
    void *env;
    void (*plain)(int, int);
} pyk_c_Fii_u_;
#endif

#ifndef PYK_TYPE_PYK_C_FS_U_
#define PYK_TYPE_PYK_C_FS_U_
typedef struct pyk_c_Fs_u_ {
    void (*fn)(void *, const char *);
    void *env;
    void (*plain)(const char *);
} pyk_c_Fs_u_;
#endif

#ifndef PYK_TYPE_PYK_C_FI_U_
#define PYK_TYPE_PYK_C_FI_U_
typedef struct pyk_c_Fi_u_ {
    void (*fn)(void *, int);
    void *env;
    void (*plain)(int);
} pyk_c_Fi_u_;
#endif

// What the external modules this one imports implement.
const char *tinyweb_canvas(int, int);
const char *tinyweb_label(const char *);
void tinyweb_splash(void);
#ifndef PYK_FN_S_V
#define PYK_FN_S_V
typedef void (*pyk_fn_s_v)(const char *);
#endif
void tinyweb_on_key(pyk_fn_s_v);

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

static pyk_c_Fii_u_ pyk_mk_Fii_u_(void (*fn)(void *, int, int), void *env, void (*plain)(int, int))
{
    pyk_c_Fii_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
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

static pyk_fn_s_v pyk_plain_Fs_u_(pyk_c_Fs_u_ c)
{
    if (c.plain == NULL) {
        fprintf(stderr, "a function that captures values cannot be handed to a module implemented in C\n");
        exit(1);
    }
    return c.plain;
}

static pyk_c_Fi_u_ pyk_mk_Fi_u_(void (*fn)(void *, int), void *env, void (*plain)(int))
{
    pyk_c_Fi_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static const char *c;
static const char *status;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void clicked(int x, int y);
static void pressed(const char *key);
static void moved(int value);

static void pyk_w_clicked(void *env, int p1, int p2)
{
    (void)env;
    clicked(p1, p2);
}

static void pyk_w_pressed(void *env, const char *p1)
{
    (void)env;
    pressed(p1);
}

static void pyk_w_moved(void *env, int p1)
{
    (void)env;
    moved(p1);
}

static void clicked(int x, int y)
{
    pyk_d_Dtinyweb_Color__Color__ pyk_t8;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t9;
    tinyweb_set_text(status, pyk_concat(pyk_concat(pyk_concat("clicked at ", pyk_int_str(x)), ", "), pyk_int_str(y)));
    (pyk_t8 = tinyweb_circle__default__stroke(), pyk_t9 = tinyweb_circle__default__paint(), (tinyweb_circle(c, x, y, 5, tinyweb_color__blue, pyk_t8, 1, 1.0, pyk_t9, tinyweb_circle__default__style()), 0));
}

static void pressed(const char *key)
{
    printf("%s\n", pyk_concat(pyk_concat("key [", key), "]"));
    if (strcmp(key, "Enter") == 0) {
        tinyweb_play_file("snare1.wav");
    }
}

static void moved(int value)
{
    tinyweb_set_text(status, pyk_concat("slider at ", pyk_int_str(value)));
}

int main(void)
{
    pyk_d_Dtinyweb_Color__Color__ pyk_t1;
    pyk_d_Dtinyweb_Color__Color__ pyk_t2;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t3;
    pyk_d_Dtinyweb_Color__Color__ pyk_t4;
    pyk_d_Dtinyweb_Color__Color__ pyk_t5;
    pyk_d_Dtinyweb_Color__Color__ pyk_t6;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t7;
    math_init();
    text_init();
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(300, 200);
    (pyk_t1 = tinyweb_color__hex(15658734), pyk_t2 = tinyweb_rect__default__stroke(), pyk_t3 = tinyweb_rect__default__paint(), (tinyweb_rect(c, 0, 0, 300, 200, pyk_t1, pyk_t2, 1, 1.0, pyk_t3, tinyweb_rect__default__style(), 0), 0));
    (pyk_t4 = tinyweb_line__default__stroke(), (tinyweb_line(c, 0, 0, 300, 200, pyk_t4, 1, 1.0, tinyweb_line__default__style()), 0));
    tinyweb_line(c, 0, 200, 300, 0, tinyweb_color__red, 3, 1.0, tinyweb_line__default__style());
    (pyk_t5 = tinyweb_text__default__fill(), pyk_t6 = tinyweb_text__default__stroke(), pyk_t7 = tinyweb_text__default__paint(), (tinyweb_text(c, 10, 10, "click \"me\"", pyk_t5, 20, "", "left", false, 1.0, "top", pyk_t6, 1, pyk_t7, tinyweb_text__default__style()), 0));
    status = tinyweb_label("nothing yet");
    tinyweb_on_click(c, pyk_mk_Fii_u_(pyk_w_clicked, NULL, clicked));
    tinyweb_on_key(pressed);
    tinyweb_slider(0, 10, 5, pyk_mk_Fi_u_(pyk_w_moved, NULL, moved));
    tinyweb_slider(1, 3, 2, tinyweb_slider__default__on_change());
    tinyweb_splash();

    return 0;
}
