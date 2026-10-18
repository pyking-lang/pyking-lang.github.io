// Generated from lib_tinyweb_shapes.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>

// Every multiply and add rounded on its own, as on every other target.
#if defined(__clang__)
#pragma STDC FP_CONTRACT OFF
#elif defined(__GNUC__)
#pragma GCC optimize ("fp-contract=off")
#endif

#include "tinyweb.h"

// What the external modules this one imports implement.
const char *tinyweb_canvas(int, int);

static const char *c;

int main(void)
{
    const char *pyk_t1;
    int pyk_t2;
    int pyk_t3;
    const char *pyk_t4;
    const char *pyk_t5;
    int pyk_t6;
    double pyk_t7;
    const char *pyk_t8;
    const char *pyk_t9;
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(300, 200);
    tinyweb_clear(c, tinyweb_colors__rgb(17, 17, 17));
    tinyweb_circle(c, 50, 50, 30, "gold", "white", 3, tinyweb_circle__default__alpha());
    (pyk_t1 = tinyweb_circle__default__outline(), pyk_t2 = tinyweb_circle__default__outline_width(), (tinyweb_circle(c, 80, 50, 30, tinyweb_colors__rgba(0, 128, 255, 0.5), pyk_t1, pyk_t2, tinyweb_circle__default__alpha()), 0));
    (pyk_t3 = tinyweb_rect__default__outline_width(), (tinyweb_rect(c, 120, 20, 60, 40, "", tinyweb_colors__hsl(120, 100, 50), pyk_t3, tinyweb_rect__default__alpha(), 8), 0));
    (pyk_t4 = tinyweb_ellipse__default__outline(), (tinyweb_ellipse(c, 220, 40, 50, 20, "orchid", pyk_t4, tinyweb_ellipse__default__outline_width(), 0.75), 0));
    (pyk_t5 = tinyweb_arc__default__outline(), pyk_t6 = tinyweb_arc__default__outline_width(), (tinyweb_arc(c, 50, 140, 40, 30.0, 330.0, "yellow", pyk_t5, pyk_t6, tinyweb_arc__default__alpha()), 0));
    tinyweb_arc(c, 150, 140, 40, 180.0, 360.0, "", "red", 4, tinyweb_arc__default__alpha());
    tinyweb_line(c, 200, 100, 290, 190, "cyan", 2, tinyweb_line__default__alpha());
    tinyweb_curve(c, 200, 190, 245, 60, 290, 190, "white", 2, 0.5);
    (pyk_t7 = tinyweb_text__default__alpha(), pyk_t8 = tinyweb_text__default__baseline(), pyk_t9 = tinyweb_text__default__outline(), (tinyweb_text(c, 150, 180, "Step 1", "white", 18, "serif", "center", true, pyk_t7, pyk_t8, pyk_t9, tinyweb_text__default__outline_width()), 0));
    printf("%s\n", tinyweb_colors__rgb(255, 136, 0));
    printf("%s\n", tinyweb_colors__rgb(-5, 300, 16));
    printf("%s\n", tinyweb_colors__hsl(200, 50, 25));

    return 0;
}
