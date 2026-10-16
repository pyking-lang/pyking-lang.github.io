// Generated from lib_tinyweb_frames.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#include "tinyweb.h"

// A Pyking function is a pointer to a C function.
#ifndef PYK_FN_F_V
#define PYK_FN_F_V
typedef void (*pyk_fn_f_v)(double);
#endif

// What the external modules this one imports implement.
void tinyweb_web_init(int);
int tinyweb_canvas(int, int);
int tinyweb_load_sample(const char *);
double tinyweb_time(void);
void tinyweb_on_frame(pyk_fn_f_v);

static int pyk_truncate(double x)
{
    if (x != x || x <= -2147483649.0 || x >= 2147483648.0) {
        return 0;
    }
    return (int)x;
}

// Concatenation allocates and never frees: Pyking has no ownership to compile into a free.
static const char *pyk_concat(const char *a, const char *b)
{
    size_t la = strlen(a);
    size_t lb = strlen(b);
    char *result = malloc(la + lb + 1);
    memcpy(result, a, la);
    memcpy(result + la, b, lb + 1);
    return result;
}

// A Float is written by this rather than by a printf conversion: no host spells a double the way Pyking does. It allocates and never frees, as concatenation does.
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

// What the top level binds, where every function can read it; the top level below is what fills each of them in.
static int c;
static int kick;
static double beat;
static double next_beat;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void draw(double t);

static void draw(double t)
{
    double tmp1;
    tinyweb_clear(c, "#111111");
    tinyweb_circle(c, pyk_truncate(t * 100.0), 50, 10, "#ffcc00");
    if (t >= next_beat) {
        printf("%s\n", pyk_concat(pyk_concat(pyk_concat("beat scheduled at ", pyk_float_str(next_beat + beat)), ", drawn at "), pyk_float_str(t)));
        (tmp1 = tinyweb_play__default__volume(), tinyweb_play(kick, next_beat + beat, tmp1, tinyweb_play__default__rate()));
        next_beat = next_beat + beat;
    }
}

int main(void)
{
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(200, 100);
    kick = tinyweb_load_sample("kick1.wav");
    beat = 0.5;
    next_beat = 0.0;
    tinyweb_on_frame(draw);
    printf("%s\n", pyk_float_str(tinyweb_time()));

    return 0;
}
