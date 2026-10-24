// Generated from lib_tinyweb_shapes.pyk by the Pyking compiler. Do not edit.
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

// What the external modules this one imports implement.
const char *tinyweb_canvas(int, int);

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

static const char *c;
static pyk_d_Dtinyweb_Color__Color__ gold;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static const char *show(pyk_d_Dtinyweb_Color__Color__ c2);

static const char *show(pyk_d_Dtinyweb_Color__Color__ c2)
{
    return pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_int_str(c2.r), " "), pyk_int_str(c2.g)), " "), pyk_int_str(c2.b)), " "), pyk_float_str(c2.a));
}

int main(void)
{
    pyk_d_Dtinyweb_Color__Paint__ pyk_t1;
    pyk_d_Dtinyweb_Color__Color__ pyk_t2;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t3;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t4;
    pyk_d_Dtinyweb_Color__Color__ pyk_t5;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t6;
    pyk_d_Dtinyweb_Color__Color__ pyk_t7;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t8;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t9;
    pyk_d_Dtinyweb_Color__Color__ pyk_t10;
    pyk_d_Dtinyweb_Color__Paint__ pyk_t11;
    math_init();
    text_init();
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(300, 200);
    tinyweb_clear(c, tinyweb_color__rgb(17, 17, 17));
    gold = tinyweb_color__hex(16766720);
    (pyk_t1 = tinyweb_circle__default__paint(), (tinyweb_circle(c, 50, 50, 30, gold, tinyweb_color__white, 3, 1.0, pyk_t1, tinyweb_circle__default__style()), 0));
    (pyk_t2 = tinyweb_circle__default__stroke(), pyk_t3 = tinyweb_circle__default__paint(), (tinyweb_circle(c, 80, 50, 30, tinyweb_color__rgba(0, 128, 255, 0.5), pyk_t2, 1, 1.0, pyk_t3, tinyweb_circle__default__style()), 0));
    (pyk_t4 = tinyweb_rect__default__paint(), (tinyweb_rect(c, 120, 20, 60, 40, tinyweb_color__none, tinyweb_color__hsl(120.0, 100.0, 50.0), 1, 1.0, pyk_t4, tinyweb_rect__default__style(), 8), 0));
    (pyk_t5 = tinyweb_ellipse__default__stroke(), pyk_t6 = tinyweb_ellipse__default__paint(), (tinyweb_ellipse(c, 220, 40, 50, 20, tinyweb_color__hex(14315734), pyk_t5, 1, 0.75, pyk_t6, tinyweb_ellipse__default__style()), 0));
    (pyk_t7 = tinyweb_arc__default__stroke(), pyk_t8 = tinyweb_arc__default__paint(), (tinyweb_arc(c, 50, 140, 40, math_pi / 6.0, 11.0 * math_pi / 6.0, tinyweb_color__yellow, pyk_t7, 1, 1.0, pyk_t8, tinyweb_arc__default__style()), 0));
    (pyk_t9 = tinyweb_arc__default__paint(), (tinyweb_arc(c, 150, 140, 40, math_pi, 2.0 * math_pi, tinyweb_color__none, tinyweb_color__red, 4, 1.0, pyk_t9, tinyweb_arc__default__style()), 0));
    tinyweb_line(c, 200, 100, 290, 190, tinyweb_color__cyan, 2, 1.0, tinyweb_line__default__style());
    tinyweb_curve(c, 200, 190, 245, 60, 290, 190, tinyweb_color__white, 2, 0.5, tinyweb_curve__default__style());
    (pyk_t10 = tinyweb_text__default__stroke(), pyk_t11 = tinyweb_text__default__paint(), (tinyweb_text(c, 150, 180, "Step 1", tinyweb_color__white, 18, "serif", "center", true, 1.0, "top", pyk_t10, 1, pyk_t11, tinyweb_text__default__style()), 0));
    printf("%s\n", show(tinyweb_color__rgb(255, 136, 0)));
    printf("%s\n", show(tinyweb_color__rgb(-5, 300, 16)));
    printf("%s\n", show(tinyweb_color__hsl(200.0, 50.0, 25.0)));
    printf("%d %d\n", tinyweb_color__to_hex(tinyweb_color__hex(16746496)), tinyweb_color__to_hex(tinyweb_color__rgb(1, 2, 3)));
    printf("%s %s\n", (tinyweb_color__same(tinyweb_color__hex(65535), tinyweb_color__cyan) ? "true" : "false"), (tinyweb_color__same(tinyweb_color__red, tinyweb_color__blue) ? "true" : "false"));
    printf("%s\n", show(tinyweb_color__mix(tinyweb_color__black, tinyweb_color__white, 0.5)));
    printf("%s\n", show(tinyweb_color__with_alpha(tinyweb_color__red, 0.25)));
    printf("%s %s\n", show(tinyweb_color__rgba(10, 20, 30, 0.5)), show(tinyweb_color__none));

    return 0;
}
