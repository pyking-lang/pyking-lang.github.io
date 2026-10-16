// Generated from lib_tinyweb_sound_graphics1.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#include "tinyweb.h"

// What the external modules this one imports implement.
void tinyweb_web_init(int);
int tinyweb_canvas(int, int);
int tinyweb_load_sample(const char *);

static const char *pyk_int_str(int n)
{
    char *out = malloc(24);
    sprintf(out, "%d", n);
    return out;
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
static int kick;
static int snare;
static int canvas;
static int presses;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void play_kick(void);
static void play_sound(void);

static void play_kick(void)
{
    double tmp1;
    double tmp2;
    (tmp1 = tinyweb_play__default__at(), tmp2 = tinyweb_play__default__volume(), tinyweb_play(kick, tmp1, tmp2, tinyweb_play__default__rate()));
}

static void play_sound(void)
{
    double tmp3;
    presses = presses + 1;
    printf("%s\n", pyk_concat("snare, press ", pyk_int_str(presses)));
    (tmp3 = tinyweb_play__default__at(), tinyweb_play(snare, tmp3, 0.5, tinyweb_play__default__rate()));
}

int main(void)
{
    tinyweb_init();
    tinyweb_web_init(0);
    kick = tinyweb_load_sample("kick1.wav");
    snare = tinyweb_load_sample("snare1.wav");
    canvas = tinyweb_canvas(400, 200);
    tinyweb_circle(canvas, 100, 50, 30, "#ff0000");
    tinyweb_circle(canvas, 100, 50, 20, tinyweb_circle__default__color());
    presses = 0;
    tinyweb_button("Play kick", play_kick);
    tinyweb_button("Play snare", play_sound);
    tinyweb_button("Does nothing", tinyweb_button__default__on_click());
    printf("%s\n", "built the page");

    return 0;
}
