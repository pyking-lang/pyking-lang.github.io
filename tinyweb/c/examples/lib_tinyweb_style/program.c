// Generated from lib_tinyweb_style.pyk by the Pyking compiler. Do not edit.
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
    tinyweb_theme("retro");
    tinyweb_set_colors(title, tinyweb_set_colors__default__color(), "black");
    printf("%s\n", "now retro");
}

int main(void)
{
    const char *pyk_t1;
    int pyk_t2;
    const char *pyk_t3;
    const char *pyk_t4;
    int pyk_t5;
    const char *pyk_t6;
    int pyk_t7;
    int pyk_t8;
    const char *pyk_t9;
    int pyk_t10;
    int pyk_t11;
    tinyweb_init();
    tinyweb_web_init(0);
    tinyweb_theme("paper");
    tinyweb_theme("no such theme");
    tinyweb_page_style("#fdf6e3", "#586e75", "serif", 18, 12, 16, tinyweb_page_style__default__align());
    tinyweb_button_style("#268bd2", "white", "none", 14, "monospace", 16, 8);
    tinyweb_label_style("lightyellow", "#333333", "1px solid gold", 4, "sans-serif", 14, 6);
    tinyweb_slider_style("crimson", 240, "crimson", "monospace", 20);
    tinyweb_canvas_style("3px solid teal", 10);
    title = tinyweb_label("Styled");
    (pyk_t1 = tinyweb_set_style__default__accent(), pyk_t2 = tinyweb_set_style__default__weight(), (tinyweb_set_style(title, "navy", "white", "2px dashed orange", 0, "Georgia", 28, 10, pyk_t1, 300, pyk_t2, tinyweb_set_style__default__height()), 0));
    level = tinyweb_slider(0, 10, 4, tinyweb_slider__default__on_change());
    tinyweb_set_colors(level, "seagreen", tinyweb_set_colors__default__background());
    c = tinyweb_canvas(120, 60);
    (pyk_t3 = tinyweb_set_style__default__background(), pyk_t4 = tinyweb_set_style__default__color(), pyk_t5 = tinyweb_set_style__default__radius(), pyk_t6 = tinyweb_set_style__default__font(), pyk_t7 = tinyweb_set_style__default__size(), pyk_t8 = tinyweb_set_style__default__padding(), pyk_t9 = tinyweb_set_style__default__accent(), pyk_t10 = tinyweb_set_style__default__width(), pyk_t11 = tinyweb_set_style__default__weight(), (tinyweb_set_style(c, pyk_t3, pyk_t4, "1px solid black", pyk_t5, pyk_t6, pyk_t7, pyk_t8, pyk_t9, pyk_t10, pyk_t11, tinyweb_set_style__default__height()), 0));
    ok = tinyweb_button("Retro", pyk_mk_F_u_(pyk_w_pressed, NULL, pressed));
    tinyweb_set_colors(ok, "black", "gold");

    return 0;
}
