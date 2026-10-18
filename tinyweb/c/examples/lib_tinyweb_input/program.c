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

#include "tinyweb.h"

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
void tinyweb_set_label(const char *, const char *);
void tinyweb_splash(void);
#ifndef PYK_FN_II_V
#define PYK_FN_II_V
typedef void (*pyk_fn_ii_v)(int, int);
#endif
void tinyweb_on_mouse(const char *, pyk_fn_ii_v);
#ifndef PYK_FN_S_V
#define PYK_FN_S_V
typedef void (*pyk_fn_s_v)(const char *);
#endif
void tinyweb_on_key(pyk_fn_s_v);

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

static pyk_fn_ii_v pyk_plain_Fii_u_(pyk_c_Fii_u_ c)
{
    if (c.plain == NULL) {
        fprintf(stderr, "a function that captures values cannot be handed to a module implemented in C\n");
        exit(1);
    }
    return c.plain;
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
    const char *pyk_t13;
    int pyk_t14;
    tinyweb_set_label(status, pyk_concat(pyk_concat(pyk_concat("clicked at ", pyk_int_str(x)), ", "), pyk_int_str(y)));
    (pyk_t13 = tinyweb_circle__default__outline(), pyk_t14 = tinyweb_circle__default__outline_width(), (tinyweb_circle(c, x, y, 5, "blue", pyk_t13, pyk_t14, tinyweb_circle__default__alpha()), 0));
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
    tinyweb_set_label(status, pyk_concat("slider at ", pyk_int_str(value)));
}

int main(void)
{
    const char *pyk_t1;
    int pyk_t2;
    double pyk_t3;
    const char *pyk_t4;
    int pyk_t5;
    const char *pyk_t6;
    const char *pyk_t7;
    const char *pyk_t8;
    bool pyk_t9;
    double pyk_t10;
    const char *pyk_t11;
    const char *pyk_t12;
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(300, 200);
    (pyk_t1 = tinyweb_rect__default__outline(), pyk_t2 = tinyweb_rect__default__outline_width(), pyk_t3 = tinyweb_rect__default__alpha(), (tinyweb_rect(c, 0, 0, 300, 200, "#eeeeee", pyk_t1, pyk_t2, pyk_t3, tinyweb_rect__default__radius()), 0));
    (pyk_t4 = tinyweb_line__default__color(), pyk_t5 = tinyweb_line__default__width(), (tinyweb_line(c, 0, 0, 300, 200, pyk_t4, pyk_t5, tinyweb_line__default__alpha()), 0));
    tinyweb_line(c, 0, 200, 300, 0, "red", 3, tinyweb_line__default__alpha());
    (pyk_t6 = tinyweb_text__default__color(), pyk_t7 = tinyweb_text__default__font(), pyk_t8 = tinyweb_text__default__align(), pyk_t9 = tinyweb_text__default__bold(), pyk_t10 = tinyweb_text__default__alpha(), pyk_t11 = tinyweb_text__default__baseline(), pyk_t12 = tinyweb_text__default__outline(), (tinyweb_text(c, 10, 10, "click \"me\"", pyk_t6, 20, pyk_t7, pyk_t8, pyk_t9, pyk_t10, pyk_t11, pyk_t12, tinyweb_text__default__outline_width()), 0));
    status = tinyweb_label("nothing yet");
    tinyweb_on_mouse(c, clicked);
    tinyweb_on_key(pressed);
    tinyweb_slider(0, 10, 5, pyk_mk_Fi_u_(pyk_w_moved, NULL, moved));
    tinyweb_slider(1, 3, 2, tinyweb_slider__default__on_change());
    tinyweb_splash();

    return 0;
}
