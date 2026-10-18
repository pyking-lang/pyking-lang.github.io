// Generated from lib_tinyweb_layout.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>
#include <stdlib.h>

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
const char *tinyweb_label(const char *);
const char *tinyweb_row(void);
const char *tinyweb_column(void);
void tinyweb_inside(const char *);
void tinyweb_outside(void);

static pyk_c_F_u_ pyk_mk_F_u_(void (*fn)(void *), void *env, void (*plain)(void))
{
    pyk_c_F_u_ v;
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

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void clicked(void);

static void pyk_w_clicked(void *env)
{
    (void)env;
    clicked();
}

static void clicked(void)
{
    printf("%s\n", "clicked");
}

int main(void)
{
    const char *pyk_t1;
    const char *pyk_t2;
    const char *pyk_t3;
    int pyk_t4;
    int pyk_t5;
    const char *pyk_t6;
    const char *pyk_t7;
    const char *pyk_t8;
    int pyk_t9;
    const char *pyk_t10;
    int pyk_t11;
    const char *pyk_t12;
    int pyk_t13;
    const char *pyk_t14;
    const char *pyk_t15;
    const char *pyk_t16;
    int pyk_t17;
    const char *pyk_t18;
    int pyk_t19;
    int pyk_t20;
    const char *pyk_t21;
    tinyweb_init();
    tinyweb_web_init(tinyweb_web_init__default__port());
    (pyk_t1 = tinyweb_page_style__default__background(), pyk_t2 = tinyweb_page_style__default__color(), pyk_t3 = tinyweb_page_style__default__font(), pyk_t4 = tinyweb_page_style__default__size(), pyk_t5 = tinyweb_page_style__default__padding(), (tinyweb_page_style(pyk_t1, pyk_t2, pyk_t3, pyk_t4, pyk_t5, tinyweb_page_style__default__gap(), "center"), 0));
    title = tinyweb_label("Layout");
    (pyk_t6 = tinyweb_set_style__default__background(), pyk_t7 = tinyweb_set_style__default__color(), pyk_t8 = tinyweb_set_style__default__border(), pyk_t9 = tinyweb_set_style__default__radius(), pyk_t10 = tinyweb_set_style__default__font(), pyk_t11 = tinyweb_set_style__default__padding(), pyk_t12 = tinyweb_set_style__default__accent(), pyk_t13 = tinyweb_set_style__default__width(), (tinyweb_set_style(title, pyk_t6, pyk_t7, pyk_t8, pyk_t9, pyk_t10, 28, pyk_t11, pyk_t12, pyk_t13, 700, tinyweb_set_style__default__height()), 0));
    buttons = tinyweb_row();
    tinyweb_inside(buttons);
    tinyweb_button("one", pyk_mk_F_u_(pyk_w_clicked, NULL, clicked));
    tinyweb_button("two", tinyweb_button__default__on_click());
    tinyweb_outside();
    tinyweb_canvas(100, 40);
    controls = tinyweb_row();
    tinyweb_inside(controls);
    tinyweb_label("speed");
    tinyweb_slider(0, 10, 5, tinyweb_slider__default__on_change());
    tinyweb_inside(buttons);
    tinyweb_button("three", tinyweb_button__default__on_click());
    tinyweb_outside();
    figures = tinyweb_row();
    tinyweb_inside(figures);
    left = tinyweb_column();
    tinyweb_inside(left);
    small = tinyweb_canvas(50, 20);
    (pyk_t14 = tinyweb_set_style__default__background(), pyk_t15 = tinyweb_set_style__default__color(), pyk_t16 = tinyweb_set_style__default__border(), pyk_t17 = tinyweb_set_style__default__radius(), pyk_t18 = tinyweb_set_style__default__font(), pyk_t19 = tinyweb_set_style__default__size(), pyk_t20 = tinyweb_set_style__default__padding(), pyk_t21 = tinyweb_set_style__default__accent(), (tinyweb_set_style(small, pyk_t14, pyk_t15, pyk_t16, pyk_t17, pyk_t18, pyk_t19, pyk_t20, pyk_t21, 100, tinyweb_set_style__default__weight(), 40), 0));
    tinyweb_label("stretched");
    tinyweb_inside(figures);
    right = tinyweb_column();
    tinyweb_inside(right);
    tinyweb_canvas(100, 40);
    tinyweb_label("as it is");
    tinyweb_outside();
    tinyweb_label("the end");

    return 0;
}
