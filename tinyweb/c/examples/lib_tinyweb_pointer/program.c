// Generated from lib_tinyweb_pointer.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

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

#ifndef PYK_TYPE_PYK_C_FF_U_
#define PYK_TYPE_PYK_C_FF_U_
typedef struct pyk_c_Ff_u_ {
    void (*fn)(void *, double);
    void *env;
    void (*plain)(double);
} pyk_c_Ff_u_;
#endif

// What the external modules this one imports implement.
const char *tinyweb_canvas(int, int);
#ifndef PYK_FN_F_V
#define PYK_FN_F_V
typedef void (*pyk_fn_f_v)(double);
#endif
void tinyweb_on_frame(pyk_fn_f_v);
#ifndef PYK_FN_S_V
#define PYK_FN_S_V
typedef void (*pyk_fn_s_v)(const char *);
#endif
void tinyweb_on_key_up(pyk_fn_s_v);
bool tinyweb_key_down(const char *);

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

static const char *pyk_float_str(double x)
{
    char buf[64];
    char digits[32];
    char *out = malloc(64);
    double a;
    int negative, p, at, i, n, decpt, k;
    const char *e;
    if (x != x) { strcpy(out, "nan"); return out; }
    if (x > DBL_MAX) { strcpy(out, "inf"); return out; }
    if (x < -DBL_MAX) { strcpy(out, "-inf"); return out; }
    negative = x < 0.0 || (x == 0.0 && 1.0 / x < 0.0);
    a = negative ? -x : x;
    if (a == 0.0) { strcpy(out, negative ? "-0.0" : "0.0"); return out; }
    for (p = 0; p < 16; p++) {
        sprintf(buf, "%.*e", p, a);
        if (strtod(buf, NULL) == a) break;
    }
    if (p == 16) sprintf(buf, "%.*e", 16, a);
    e = strchr(buf, 'e');
    at = (int)(e - buf);
    n = 0;
    for (i = 0; i < at; i++) if (buf[i] != '.') digits[n++] = buf[i];
    while (n > 1 && digits[n - 1] == '0') n--;
    digits[n] = '\0';
    decpt = atoi(e + 1) + 1;
    k = 0;
    if (negative) out[k++] = '-';
    if (decpt <= -4 || decpt > 16) {
        out[k++] = digits[0];
        if (n > 1) { out[k++] = '.'; strcpy(out + k, digits + 1); k += n - 1; }
        sprintf(out + k, "e%d", decpt - 1);
        return out;
    }
    if (decpt <= 0) {
        out[k++] = '0';
        out[k++] = '.';
        for (i = 0; i < -decpt; i++) out[k++] = '0';
        strcpy(out + k, digits);
        return out;
    }
    if (decpt >= n) {
        strcpy(out + k, digits);
        k += n;
        for (i = 0; i < decpt - n; i++) out[k++] = '0';
        strcpy(out + k, ".0");
        return out;
    }
    for (i = 0; i < decpt; i++) out[k++] = digits[i];
    out[k++] = '.';
    strcpy(out + k, digits + decpt);
    return out;
}

static pyk_c_Ff_u_ pyk_mk_Ff_u_(void (*fn)(void *, double), void *env, void (*plain)(double))
{
    pyk_c_Ff_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static pyk_fn_f_v pyk_plain_Ff_u_(pyk_c_Ff_u_ c)
{
    if (c.plain == NULL) {
        fprintf(stderr, "a function that captures values cannot be handed to a module implemented in C\n");
        exit(1);
    }
    return c.plain;
}

static const char *c;
static const char *other;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void pressed(int x, int y);
static void dragged(int x, int y);
static void moved(int x, int y);
static void released(int x, int y);
static void let_go(const char *key);
static void frame(double t);

static void pyk_w_pressed(void *env, int p1, int p2)
{
    (void)env;
    pressed(p1, p2);
}

static void pyk_w_dragged(void *env, int p1, int p2)
{
    (void)env;
    dragged(p1, p2);
}

static void pyk_w_moved(void *env, int p1, int p2)
{
    (void)env;
    moved(p1, p2);
}

static void pyk_w_released(void *env, int p1, int p2)
{
    (void)env;
    released(p1, p2);
}

static void pyk_w_tinyweb_ignore2(void *env, int p1, int p2)
{
    (void)env;
    tinyweb_ignore2(p1, p2);
}

static void pyk_w_let_go(void *env, const char *p1)
{
    (void)env;
    let_go(p1);
}

static void pyk_w_frame(void *env, double p1)
{
    (void)env;
    frame(p1);
}

static void pressed(int x, int y)
{
    const char *pyk_t1;
    int pyk_t2;
    printf("%s %d %d %s %s\n", "press at", x, y, "down", (tinyweb_mouse_down(c) ? "true" : "false"));
    (pyk_t1 = tinyweb_circle__default__outline(), pyk_t2 = tinyweb_circle__default__outline_width(), (tinyweb_circle(c, x, y, 4, "crimson", pyk_t1, pyk_t2, tinyweb_circle__default__alpha()), 0));
}

static void dragged(int x, int y)
{
    int pyk_t3;
    int pyk_t4;
    printf("%s %d %d\n", "drag to", x, y);
    (pyk_t3 = tinyweb_mouse_x(c), pyk_t4 = tinyweb_mouse_y(c), (tinyweb_line(c, pyk_t3, pyk_t4, x, y, "black", 2, tinyweb_line__default__alpha()), 0));
}

static void moved(int x, int y)
{
    printf("%s %d %d %s %s\n", "move to", x, y, "down", (tinyweb_mouse_down(c) ? "true" : "false"));
}

static void released(int x, int y)
{
    printf("%s %d %d %s %s\n", "release at", x, y, "down", (tinyweb_mouse_down(c) ? "true" : "false"));
}

static void let_go(const char *key)
{
    printf("%s %s %s %s\n", "let go of", key, "still held:", (tinyweb_key_down(key) ? "true" : "false"));
}

static void frame(double t)
{
    bool left = tinyweb_key_down("ArrowLeft");
    bool right = tinyweb_key_down("ArrowRight");
    printf("%s %s %s %s %s %s\n", "frame", pyk_float_str(t), "left", (left ? "true" : "false"), "right", (right ? "true" : "false"));
}

int main(void)
{
    int pyk_t5;
    int pyk_t6;
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(200, 100);
    other = tinyweb_canvas(50, 50);
    tinyweb_on_press(c, pyk_mk_Fii_u_(pyk_w_pressed, NULL, pressed));
    tinyweb_on_drag(c, pyk_mk_Fii_u_(pyk_w_dragged, NULL, dragged));
    tinyweb_on_move(c, pyk_mk_Fii_u_(pyk_w_moved, NULL, moved));
    tinyweb_on_release(c, pyk_mk_Fii_u_(pyk_w_released, NULL, released));
    tinyweb_on_move(other, pyk_mk_Fii_u_(pyk_w_tinyweb_ignore2, NULL, tinyweb_ignore2));
    (pyk_t5 = tinyweb_mouse_x(c), pyk_t6 = tinyweb_mouse_y(c), printf("%s %d %d %s\n", "before any event", pyk_t5, pyk_t6, (tinyweb_mouse_down(c) ? "true" : "false")));
    tinyweb_on_key_up(let_go);
    tinyweb_on_frame(frame);

    return 0;
}
