// Generated from lib_tinyweb_bitmap.pyk by the Pyking compiler. Do not edit.
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

static pyk_d_Dtinyweb_Color__Color__ pyk_mk_Dtinyweb_Color__Color___Color__Color(int r, int g, int b, double a)
{
    pyk_d_Dtinyweb_Color__Color__ v;
    v.r = r;
    v.g = g;
    v.b = b;
    v.a = a;
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

static int pyk_truncate(double x)
{
    if (x != x || x <= -2147483649.0 || x >= 2147483648.0) {
        return 0;
    }
    return (int)x;
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
static const char *b;
static pyk_d_Dtinyweb_Color__Color__ orange;
static const char *small;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static const char *show(pyk_d_Dtinyweb_Color__Color__ p);
static void frame(double t);

static void pyk_w_frame(void *env, double p1)
{
    (void)env;
    frame(p1);
}

static const char *show(pyk_d_Dtinyweb_Color__Color__ p)
{
    return pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_int_str(p.r), " "), pyk_int_str(p.g)), " "), pyk_int_str(p.b));
}

static void frame(double t)
{
    tinyweb_bitmap__set_pixel(small, 1, 1, tinyweb_color__rgb(pyk_truncate(t * 100.0), 0, 0));
    tinyweb_bitmap__show_bitmap(c, small, 120, 60, 2.0);
}

int main(void)
{
    math_init();
    text_init();
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(160, 100);
    b = tinyweb_bitmap__bitmap(16, 10, tinyweb_bitmap__bitmap__default__background());
    printf("%s %s\n", "a new bitmap is white:", show(tinyweb_bitmap__get_pixel(b, 3, 3)));
    printf("%s %s\n", "or its background:", show(tinyweb_bitmap__get_pixel(tinyweb_bitmap__bitmap(2, 2, tinyweb_color__green), 1, 1)));
    int y_stop = 10;
    int y_step = 1;
    int y;
    for (y = 0; y_step > 0 ? y < y_stop : y > y_stop; y += y_step) {
        int x_stop = 16;
        int x_step = 1;
        int x;
        for (x = 0; x_step > 0 ? x < x_stop : x > x_stop; x += x_step) {
            tinyweb_bitmap__set_pixel(b, x, y, tinyweb_color__rgb(x * 16, y * 25, 128));
        }
        0;
    }
    tinyweb_bitmap__show_bitmap(c, b, 0, 0, 10.0);
    orange = tinyweb_color__rgb(255, 136, 0);
    tinyweb_bitmap__set_pixel(b, 4, 2, orange);
    tinyweb_bitmap__set_pixel(b, 7, 5, orange);
    tinyweb_bitmap__set_pixel(b, 40, 2, orange);
    printf("%s %s %s %s %s\n", "pixel (4, 2):", show(tinyweb_bitmap__get_pixel(b, 4, 2)), "outside:", show(tinyweb_bitmap__get_pixel(b, -1, 0)), pyk_float_str(tinyweb_bitmap__get_pixel(b, -1, 0).a));
    tinyweb_bitmap__show_bitmap(c, b, 0, 0, 10.0);
    tinyweb_bitmap__show_bitmap(c, b, 5, 5, 1.0);
    small = tinyweb_bitmap__bitmap(4, 4, tinyweb_bitmap__bitmap__default__background());
    tinyweb_bitmap__fill_bitmap(small, tinyweb_color__blue);
    printf("%s %d\n", "filled:", tinyweb_bitmap__get_pixel(small, 3, 3).b);
    tinyweb_bitmap__show_bitmap(c, small, 120, 60, 0.5);
    tinyweb_on_frame(frame);

    return 0;
}
