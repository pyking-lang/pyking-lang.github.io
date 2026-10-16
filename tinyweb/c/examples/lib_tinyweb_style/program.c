// Generated from lib_tinyweb_style.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>

#include "tinyweb.h"

// What the external modules this one imports implement.
void tinyweb_web_init(int);
int tinyweb_canvas(int, int);
int tinyweb_label(const char *);

// What the top level binds, where every function can read it; the top level below is what fills each of them in.
static int title;
static int level;
static int c;
static int ok;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void pressed(void);

static void pressed(void)
{
    tinyweb_theme("retro");
    tinyweb_set_colors(title, tinyweb_set_colors__default__color(), "black");
    printf("%s\n", "now retro");
}

int main(void)
{
    const char *tmp1;
    const char *tmp2;
    int tmp3;
    const char *tmp4;
    int tmp5;
    int tmp6;
    const char *tmp7;
    tinyweb_init();
    tinyweb_web_init(0);
    tinyweb_theme("paper");
    tinyweb_theme("no such theme");
    tinyweb_page_style("#fdf6e3", "#586e75", "serif", 18, 12, 16);
    tinyweb_button_style("#268bd2", "white", "none", 14, "monospace", 16, 8);
    tinyweb_label_style("lightyellow", "#333333", "1px solid gold", 4, "sans-serif", 14, 6);
    tinyweb_slider_style("crimson", 240, "crimson", "monospace", 20);
    tinyweb_canvas_style("3px solid teal", 10);
    title = tinyweb_label("Styled");
    tinyweb_set_style(title, "navy", "white", "2px dashed orange", 0, "Georgia", 28, 10, tinyweb_set_style__default__accent(), 300);
    level = tinyweb_slider(0, 10, 4, tinyweb_slider__default__on_change());
    tinyweb_set_colors(level, "seagreen", tinyweb_set_colors__default__background());
    c = tinyweb_canvas(120, 60);
    (tmp1 = tinyweb_set_style__default__background(), tmp2 = tinyweb_set_style__default__color(), tmp3 = tinyweb_set_style__default__radius(), tmp4 = tinyweb_set_style__default__font(), tmp5 = tinyweb_set_style__default__size(), tmp6 = tinyweb_set_style__default__padding(), tmp7 = tinyweb_set_style__default__accent(), tinyweb_set_style(c, tmp1, tmp2, "1px solid black", tmp3, tmp4, tmp5, tmp6, tmp7, tinyweb_set_style__default__width()));
    ok = tinyweb_button("Retro", pressed);
    tinyweb_set_colors(ok, "black", "gold");

    return 0;
}
