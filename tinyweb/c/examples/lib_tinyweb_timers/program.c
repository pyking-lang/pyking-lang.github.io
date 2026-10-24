// Generated from lib_tinyweb_timers.pyk by the Pyking compiler. Do not edit.
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

#ifndef PYK_TYPE_PYK_C_F_U_
#define PYK_TYPE_PYK_C_F_U_
typedef struct pyk_c_F_u_ {
    void (*fn)(void *);
    void *env;
    void (*plain)(void);
} pyk_c_F_u_;
#endif

// What the external modules this one imports implement.
double tinyweb_time(void);

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

static pyk_c_F_u_ pyk_mk_F_u_(void (*fn)(void *), void *env, void (*plain)(void))
{
    pyk_c_F_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static int ticks;
static const char *repeating;
static const char *later;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void tick(void);
static void once(void);

static void pyk_w_tick(void *env)
{
    (void)env;
    tick();
}

static void pyk_w_once(void *env)
{
    (void)env;
    once();
}

static void tick(void)
{
    ticks = ticks + 1;
    printf("%s %d %s\n", "tick", ticks, pyk_float_str(tinyweb_time()));
    if (ticks == 3) {
        tinyweb_cancel(repeating);
    }
}

static void once(void)
{
    double pyk_t1;
    double pyk_t2;
    double pyk_t3;
    int pyk_t4;
    double pyk_t5;
    double pyk_t6;
    (pyk_t1 = tinyweb_time(), pyk_t2 = tinyweb_sound__beat(), pyk_t3 = tinyweb_sound__latency(), printf("%s %s %s %s %s %s %s %s\n", "once at", pyk_float_str(pyk_t1), "beat", pyk_float_str(pyk_t2), "latency", pyk_float_str(pyk_t3), "level", pyk_float_str(tinyweb_sound__level())));
    (pyk_t4 = tinyweb_sound__bands(), pyk_t5 = tinyweb_sound__band(0), pyk_t6 = tinyweb_sound__band(1), printf("%s %d %s %s %s\n", "bands", pyk_t4, pyk_float_str(pyk_t5), pyk_float_str(pyk_t6), pyk_float_str(tinyweb_sound__band(9))));
    printf("%s %s\n", "typed", tinyweb_value_of("name"));
}

int main(void)
{
    math_init();
    text_init();
    tinyweb_init();
    tinyweb_web_init(0);
    ticks = 0;
    repeating = "";
    repeating = tinyweb_every(0.5, pyk_mk_F_u_(pyk_w_tick, NULL, tick));
    later = tinyweb_after(2.0, pyk_mk_F_u_(pyk_w_once, NULL, once));
    printf("%s %s\n", repeating, later);

    return 0;
}
