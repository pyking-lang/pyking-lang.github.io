// Generated from lib_tinyweb_layout.pyk by the Pyking compiler. Do not edit.
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

static pyk_c_Fs_u_ pyk_mk_Fs_u_(void (*fn)(void *, const char *), void *env, void (*plain)(const char *))
{
    pyk_c_Fs_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static const char *title;
static const char *buttons;
static const char *controls;
static const char *figures;
static const char *left;
static const char *small;
static const char *right;
static const char *notes;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void clicked(void);
static void edited(const char *words);

static void pyk_w_clicked(void *env)
{
    (void)env;
    clicked();
}

static void pyk_w_edited(void *env, const char *p1)
{
    (void)env;
    edited(p1);
}

static void clicked(void)
{
    printf("%s\n", "clicked");
}

static void edited(const char *words)
{
    printf("%s %s\n", "notes:", words);
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
    math_init();
    text_init();
    tinyweb_init();
    tinyweb_web_init(0);
    (pyk_t1 = tinyweb_page_style__default__background(), (tinyweb_page_style(pyk_t1, tinyweb_page_style__default__foreground(), "", -1, -1, -1, "center"), 0));
    title = tinyweb_label("Layout");
    (pyk_t2 = tinyweb_set_style__default__background(), pyk_t3 = tinyweb_set_style__default__foreground(), pyk_t4 = tinyweb_set_style__default__border(), (tinyweb_set_style(title, pyk_t2, pyk_t3, pyk_t4, -1, -1, "", 28, -1, tinyweb_set_style__default__accent(), -1, 700, -1), 0));
    buttons = tinyweb_layout__row();
    tinyweb_layout__inside(buttons);
    tinyweb_button("one", pyk_mk_F_u_(pyk_w_clicked, NULL, clicked));
    tinyweb_button("two", tinyweb_button__default__on_click());
    tinyweb_layout__outside();
    tinyweb_canvas(100, 40);
    controls = tinyweb_layout__row();
    tinyweb_layout__inside(controls);
    tinyweb_label("speed");
    tinyweb_slider(0, 10, 5, tinyweb_slider__default__on_change());
    tinyweb_layout__inside(buttons);
    tinyweb_button("three", tinyweb_button__default__on_click());
    tinyweb_layout__outside();
    figures = tinyweb_layout__row();
    tinyweb_layout__inside(figures);
    left = tinyweb_layout__column();
    tinyweb_layout__inside(left);
    small = tinyweb_canvas(50, 20);
    (pyk_t5 = tinyweb_set_style__default__background(), pyk_t6 = tinyweb_set_style__default__foreground(), pyk_t7 = tinyweb_set_style__default__border(), (tinyweb_set_style(small, pyk_t5, pyk_t6, pyk_t7, -1, -1, "", -1, -1, tinyweb_set_style__default__accent(), 100, -1, 40), 0));
    tinyweb_label("stretched");
    tinyweb_layout__inside(figures);
    right = tinyweb_layout__column();
    tinyweb_layout__inside(right);
    tinyweb_canvas(100, 40);
    tinyweb_label("as it is");
    tinyweb_layout__outside();
    notes = tinyweb_layout__text_area("first line\nsecond \"line\"", 3, 30, pyk_mk_Fs_u_(pyk_w_edited, NULL, edited));
    tinyweb_layout__text_area("", 4, 40, tinyweb_layout__text_area__default__on_change());
    tinyweb_label("the end");
    printf("%s %s\n", notes, tinyweb_value_of(notes));

    return 0;
}
