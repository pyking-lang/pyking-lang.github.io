// Generated from lib_tinyweb_load_bitmap.pyk by the Pyking compiler. Do not edit.
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

#ifndef PYK_TYPE_PYK_T_TII_
#define PYK_TYPE_PYK_T_TII_
typedef struct pyk_t_Tii_ {
    int a0;
    int a1;
} pyk_t_Tii_;
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

static pyk_t_Tii_ pyk_mk_Tii_(int a0, int a1)
{
    pyk_t_Tii_ v;
    v.a0 = a0;
    v.a1 = a1;
    return v;
}

static const char *pyk_show_Tii_(pyk_t_Tii_ v)
{
    const char *out = "(";
    out = pyk_concat(out, pyk_int_str(v.a0));
    out = pyk_concat(out, ", ");
    out = pyk_concat(out, pyk_int_str(v.a1));
    return pyk_concat(out, ")");
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

static pyk_c_Fs_u_ pyk_mk_Fs_u_(void (*fn)(void *, const char *), void *env, void (*plain)(const char *))
{
    pyk_c_Fs_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static const char *c;
static const char *made;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static const char *show(pyk_d_Dtinyweb_Color__Color__ p);
static void loaded(const char *b);
static void broken(const char *b);

static void pyk_w_loaded(void *env, const char *p1)
{
    (void)env;
    loaded(p1);
}

static void pyk_w_broken(void *env, const char *p1)
{
    (void)env;
    broken(p1);
}

static const char *show(pyk_d_Dtinyweb_Color__Color__ p)
{
    return pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_int_str(p.r), " "), pyk_int_str(p.g)), " "), pyk_int_str(p.b));
}

static void loaded(const char *b)
{
    const char *pyk_t3;
    pyk_t_Tii_ pyk_t2 = tinyweb_bitmap__size(b);
    int w = pyk_t2.a0;
    int h = pyk_t2.a1;
    printf("%s %s %s %d %s %d\n", "loaded", b, "of", w, "by", h);
    int y_stop = h;
    int y_step = 1;
    int y;
    for (y = 0; y_step > 0 ? y < y_stop : y > y_stop; y += y_step) {
        int x_stop = w;
        int x_step = 1;
        int x;
        for (x = 0; x_step > 0 ? x < x_stop : x > x_stop; x += x_step) {
            (pyk_t3 = show(tinyweb_bitmap__get_pixel(b, x, y)), printf("%s %d %d %s %s\n", " ", x, y, pyk_t3, pyk_float_str(tinyweb_bitmap__get_pixel(b, x, y).a)));
        }
        0;
    }
    tinyweb_bitmap__set_pixel(b, 1, 1, tinyweb_color__black);
    tinyweb_bitmap__show_bitmap(c, b, 0, 0, 10.0);
}

static void broken(const char *b)
{
    printf("%s %s\n", "never called for", b);
}

int main(void)
{
    pyk_t_Tii_ pyk_t1;
    math_init();
    text_init();
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(40, 40);
    made = tinyweb_bitmap__bitmap(5, 3, tinyweb_bitmap__bitmap__default__background());
    (pyk_t1 = tinyweb_bitmap__size(made), printf("%s %s %s %s\n", "made:", pyk_show_Tii_(pyk_t1), "not a bitmap:", pyk_show_Tii_(tinyweb_bitmap__size("nothing"))));
    tinyweb_bitmap__load_bitmap("pic.png", pyk_mk_Fs_u_(pyk_w_loaded, NULL, loaded));
    tinyweb_bitmap__load_bitmap("broken.png", pyk_mk_Fs_u_(pyk_w_broken, NULL, broken));
    printf("%s\n", "asked for both");

    return 0;
}
