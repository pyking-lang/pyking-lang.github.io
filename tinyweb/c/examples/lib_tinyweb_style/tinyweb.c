// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
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
#include "math.h"
#include "text.h"

#ifndef PYK_TYPE_PYK_D_DTINYWEB_COLOR__COLOR__
#define PYK_TYPE_PYK_D_DTINYWEB_COLOR__COLOR__
typedef struct pyk_d_Dtinyweb_Color__Color__ {
    int r;
    int g;
    int b;
    double a;
} pyk_d_Dtinyweb_Color__Color__;
#endif

#ifndef PYK_TYPE_PYK_C_F_U_
#define PYK_TYPE_PYK_C_F_U_
typedef struct pyk_c_F_u_ {
    void (*fn)(void *);
    void *env;
    void (*plain)(void);
} pyk_c_F_u_;
#endif

#ifndef PYK_TYPE_PYK_C_FI_U_
#define PYK_TYPE_PYK_C_FI_U_
typedef struct pyk_c_Fi_u_ {
    void (*fn)(void *, int);
    void *env;
    void (*plain)(int);
} pyk_c_Fi_u_;
#endif

#ifndef PYK_TYPE_PYK_C_FII_U_
#define PYK_TYPE_PYK_C_FII_U_
typedef struct pyk_c_Fii_u_ {
    void (*fn)(void *, int, int);
    void *env;
    void (*plain)(int, int);
} pyk_c_Fii_u_;
#endif

// What the external modules this one imports implement.
void tinyweb_web_start(int);
const char *tinyweb_canvas(int, int);
void tinyweb_fill_canvas(const char *, const char *);
void tinyweb_draw_shape(const char *, const char *, const char *, const char *, const char *, double, double);
void tinyweb_draw_text(const char *, double, double, const char *, const char *, int, const char *, const char *, const char *, bool, const char *, double, double);
void tinyweb_set_state(const char *, const char *, const char *, const char *);
#ifndef PYK_FN_F_V
#define PYK_FN_F_V
typedef void (*pyk_fn_f_v)(double);
#endif
void tinyweb_measure(const char *, int, const char *, bool, pyk_fn_f_v);
#ifndef PYK_FN_II_V
#define PYK_FN_II_V
typedef void (*pyk_fn_ii_v)(int, int);
#endif
void tinyweb_watch_pointer(const char *, const char *, pyk_fn_ii_v);
int tinyweb_pointer(const char *, const char *);
void tinyweb_draw_image(const char *, const char *, int, int, int, int, double);
const char *tinyweb_make_bitmap(int, int, int);
void tinyweb_set_pixel(const char *, int, int, int);
int tinyweb_get_pixel(const char *, int, int);
void tinyweb_fill_bitmap(const char *, int);
void tinyweb_draw_bitmap(const char *, const char *, int, int, double);
const char *tinyweb_load_image(const char *);
#ifndef PYK_FN__V
#define PYK_FN__V
typedef void (*pyk_fn__v)(void);
#endif
const char *tinyweb_make_button(const char *, pyk_fn__v);
const char *tinyweb_label(const char *);
const char *tinyweb_row(void);
const char *tinyweb_column(void);
void tinyweb_inside(const char *);
void tinyweb_outside(void);
void tinyweb_set_label(const char *, const char *);
#ifndef PYK_FN_I_V
#define PYK_FN_I_V
typedef void (*pyk_fn_i_v)(int);
#endif
const char *tinyweb_make_slider(int, int, int, pyk_fn_i_v);
#ifndef PYK_FN_B_V
#define PYK_FN_B_V
typedef void (*pyk_fn_b_v)(bool);
#endif
const char *tinyweb_make_checkbox(const char *, bool, pyk_fn_b_v);
#ifndef PYK_FN_S_V
#define PYK_FN_S_V
typedef void (*pyk_fn_s_v)(const char *);
#endif
const char *tinyweb_make_radio(const char *, const char *, bool, pyk_fn_s_v);
#ifndef PYK_FN_I_V
#define PYK_FN_I_V
typedef void (*pyk_fn_i_v)(int);
#endif
const char *tinyweb_make_choice(const char *, int, pyk_fn_i_v);
#ifndef PYK_FN_S_V
#define PYK_FN_S_V
typedef void (*pyk_fn_s_v)(const char *);
#endif
const char *tinyweb_make_text_input(const char *, pyk_fn_s_v);
#ifndef PYK_FN_I_V
#define PYK_FN_I_V
typedef void (*pyk_fn_i_v)(int);
#endif
const char *tinyweb_make_number_input(int, int, int, pyk_fn_i_v);
void tinyweb_set_checked(const char *, bool);
void tinyweb_set_value(const char *, int);
void tinyweb_apply_style(const char *, const char *, const char *, const char *);
const char *tinyweb_load_sample(const char *);
const char *tinyweb_fresh_id(const char *);
void tinyweb_command(const char *, const char *, const char *, const char *, int);
#ifndef PYK_FN__V
#define PYK_FN__V
typedef void (*pyk_fn__v)(void);
#endif
void tinyweb_watch(const char *, const char *, pyk_fn__v);
double tinyweb_report_number(const char *, int);
const char *tinyweb_report_text(const char *);
int tinyweb_report_count(const char *);
#ifndef PYK_FN_S_V
#define PYK_FN_S_V
typedef void (*pyk_fn_s_v)(const char *);
#endif
void tinyweb_watch_text(const char *, const char *, const char *, pyk_fn_s_v);
#ifndef PYK_FN_IF_V
#define PYK_FN_IF_V
typedef void (*pyk_fn_if_v)(int, double);
#endif
void tinyweb_watch_step(const char *, const char *, pyk_fn_if_v);
#ifndef PYK_FN_FF_V
#define PYK_FN_FF_V
typedef void (*pyk_fn_ff_v)(double, double);
#endif
void tinyweb_watch_pair(const char *, const char *, pyk_fn_ff_v);
void tinyweb_splash(void);
void tinyweb_set_splash(const char *);
double tinyweb_time(void);
void tinyweb_sdelay(double);
#ifndef PYK_FN_F_V
#define PYK_FN_F_V
typedef void (*pyk_fn_f_v)(double);
#endif
void tinyweb_on_frame(pyk_fn_f_v);
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
#ifndef PYK_FN_S_V
#define PYK_FN_S_V
typedef void (*pyk_fn_s_v)(const char *);
#endif
void tinyweb_on_key_up(pyk_fn_s_v);
bool tinyweb_key_down(const char *);

static pyk_d_Dtinyweb_Color__Color__ pyk_mk_Dtinyweb_Color__Color___Color__Color(int r, int g, int b, double a)
{
    pyk_d_Dtinyweb_Color__Color__ v;
    v.r = r;
    v.g = g;
    v.b = b;
    v.a = a;
    return v;
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

static const char *pyk_int_str(int n)
{
    char *out = malloc(24);
    sprintf(out, "%d", n);
    return out;
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

static pyk_c_F_u_ pyk_mk_F_u_(void (*fn)(void *), void *env, void (*plain)(void))
{
    pyk_c_F_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static pyk_fn__v pyk_plain_F_u_(pyk_c_F_u_ c)
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

static pyk_fn_i_v pyk_plain_Fi_u_(pyk_c_Fi_u_ c)
{
    if (c.plain == NULL) {
        fprintf(stderr, "a function that captures values cannot be handed to a module implemented in C\n");
        exit(1);
    }
    return c.plain;
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

pyk_d_Dtinyweb_Color__Color__ tinyweb_color__black;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__white;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__gray;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__red;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__green;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__blue;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__yellow;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__orange;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__purple;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__pink;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__navy;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__teal;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__brown;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__cyan;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__magenta;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__none;
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__theme;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void ignore(int value);
static int color__part(int n);
static double color__unit(double x);
static const char *color__hex2(int n);
static const char *color__hex_digit(int d);
static const char *color__css(pyk_d_Dtinyweb_Color__Color__ c);
static bool color__is_theme(pyk_d_Dtinyweb_Color__Color__ c);
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__rgba(int r, int g, int b, double a);
pyk_d_Dtinyweb_Color__Color__ tinyweb_color__hex(int n);
void tinyweb_web_init(int port);
const char *tinyweb_button(const char *title, pyk_c_F_u_ on_click);
pyk_c_Fi_u_ tinyweb_slider__default__on_change(void);
const char *tinyweb_slider(int low, int high, int value, pyk_c_Fi_u_ on_change);
static bool known_theme(const char *name);
static void style_text(const char *id, const char *kind, const char *property, const char *value);
static void style_color(const char *id, const char *kind, const char *property, pyk_d_Dtinyweb_Color__Color__ c);
static void style_border(const char *id, const char *kind, pyk_d_Dtinyweb_Color__Color__ border, int width);
static void style_pixels(const char *id, const char *kind, const char *property, int value);
void tinyweb_theme(const char *name);
void tinyweb_page_style(pyk_d_Dtinyweb_Color__Color__ background, pyk_d_Dtinyweb_Color__Color__ foreground, const char *font, int size, int padding, int gap, const char *align);
void tinyweb_button_style(pyk_d_Dtinyweb_Color__Color__ background, pyk_d_Dtinyweb_Color__Color__ foreground, pyk_d_Dtinyweb_Color__Color__ border, int border_width, int radius, const char *font, int size, int padding);
void tinyweb_label_style(pyk_d_Dtinyweb_Color__Color__ background, pyk_d_Dtinyweb_Color__Color__ foreground, pyk_d_Dtinyweb_Color__Color__ border, int border_width, int radius, const char *font, int size, int padding);
void tinyweb_slider_style(pyk_d_Dtinyweb_Color__Color__ accent, int width, pyk_d_Dtinyweb_Color__Color__ foreground, const char *font, int size);
void tinyweb_canvas_style(pyk_d_Dtinyweb_Color__Color__ border, int border_width, int radius);
pyk_d_Dtinyweb_Color__Color__ tinyweb_set_style__default__background(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_set_style__default__foreground(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_set_style__default__border(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_set_style__default__accent(void);
void tinyweb_set_style(const char *id, pyk_d_Dtinyweb_Color__Color__ background, pyk_d_Dtinyweb_Color__Color__ foreground, pyk_d_Dtinyweb_Color__Color__ border, int border_width, int radius, const char *font, int size, int padding, pyk_d_Dtinyweb_Color__Color__ accent, int width, int weight, int height);
void tinyweb_on_click(const char *c, pyk_c_Fii_u_ f);

static void pyk_w_ignore(void *env, int p1)
{
    (void)env;
    ignore(p1);
}

static void ignore(int value)
{

}

static int color__part(int n)
{
    return n < 0 ? 0 : n > 255 ? 255 : n;
}

static double color__unit(double x)
{
    return x < 0.0 ? 0.0 : x > 1.0 ? 1.0 : x;
}

static const char *color__hex2(int n)
{
    int clamped = color__part(n);
    return pyk_concat(color__hex_digit(clamped / 16), color__hex_digit(clamped - clamped / 16 * 16));
}

static const char *color__hex_digit(int d)
{
    int pyk_s1 = d;
    if (pyk_s1 == 0) {
        {
            return "0";
        }
    } else if (pyk_s1 == 1) {
        {
            return "1";
        }
    } else if (pyk_s1 == 2) {
        {
            return "2";
        }
    } else if (pyk_s1 == 3) {
        {
            return "3";
        }
    } else if (pyk_s1 == 4) {
        {
            return "4";
        }
    } else if (pyk_s1 == 5) {
        {
            return "5";
        }
    } else if (pyk_s1 == 6) {
        {
            return "6";
        }
    } else if (pyk_s1 == 7) {
        {
            return "7";
        }
    } else if (pyk_s1 == 8) {
        {
            return "8";
        }
    } else if (pyk_s1 == 9) {
        {
            return "9";
        }
    } else if (pyk_s1 == 10) {
        {
            return "a";
        }
    } else if (pyk_s1 == 11) {
        {
            return "b";
        }
    } else if (pyk_s1 == 12) {
        {
            return "c";
        }
    } else if (pyk_s1 == 13) {
        {
            return "d";
        }
    } else if (pyk_s1 == 14) {
        {
            return "e";
        }
    } else {
        {
            return "f";
        }
    }
}

static const char *color__css(pyk_d_Dtinyweb_Color__Color__ c)
{
    if (c.a >= 1.0) {
        return pyk_concat(pyk_concat(pyk_concat("#", color__hex2(c.r)), color__hex2(c.g)), color__hex2(c.b));
    } else {
        return pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat(pyk_concat("rgba(", pyk_int_str(color__part(c.r))), ", "), pyk_int_str(color__part(c.g))), ", "), pyk_int_str(color__part(c.b))), ", "), pyk_float_str(color__unit(c.a))), ")");
    }
}

static bool color__is_theme(pyk_d_Dtinyweb_Color__Color__ c)
{
    return c.a < 0.0;
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_color__rgba(int r, int g, int b, double a)
{
    return pyk_mk_Dtinyweb_Color__Color___Color__Color(color__part(r), color__part(g), color__part(b), a < 0.0 ? 0.0 : a > 1.0 ? 1.0 : a);
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_color__hex(int n)
{
    return pyk_mk_Dtinyweb_Color__Color___Color__Color(color__part(n / 65536), color__part(n / 256 - n / 65536 * 256), color__part(n - n / 256 * 256), 1.0);
}

void tinyweb_web_init(int port)
{
    tinyweb_web_start(port);
}

const char *tinyweb_button(const char *title, pyk_c_F_u_ on_click)
{
    return tinyweb_make_button(title, pyk_plain_F_u_(on_click));
}

pyk_c_Fi_u_ tinyweb_slider__default__on_change(void)
{
    return pyk_mk_Fi_u_(pyk_w_ignore, NULL, ignore);
}

const char *tinyweb_slider(int low, int high, int value, pyk_c_Fi_u_ on_change)
{
    return tinyweb_make_slider(low, high, value, pyk_plain_Fi_u_(on_change));
}

static bool known_theme(const char *name)
{
    const char *pyk_s2 = name;
    if (strcmp(pyk_s2, "light") == 0 || strcmp(pyk_s2, "dark") == 0 || strcmp(pyk_s2, "plain") == 0 || strcmp(pyk_s2, "paper") == 0 || strcmp(pyk_s2, "retro") == 0) {
        {
            return true;
        }
    } else {
        {
            return false;
        }
    }
}

static void style_text(const char *id, const char *kind, const char *property, const char *value)
{
    (void)(strcmp(value, "") == 0 ? 0 : (tinyweb_apply_style(id, kind, property, value), 0));
}

static void style_color(const char *id, const char *kind, const char *property, pyk_d_Dtinyweb_Color__Color__ c)
{
    (void)(color__is_theme(c) ? 0 : (tinyweb_apply_style(id, kind, property, color__css(c)), 0));
}

static void style_border(const char *id, const char *kind, pyk_d_Dtinyweb_Color__Color__ border, int width)
{
    if (color__is_theme(border)) {
        (void)(width >= 0 ? (tinyweb_apply_style(id, kind, "border", pyk_concat(pyk_int_str(width), "px solid currentColor")), 0) : 0);
    } else if (border.a <= 0.0) {
        tinyweb_apply_style(id, kind, "border", "none");
    } else {
        tinyweb_apply_style(id, kind, "border", pyk_concat(pyk_concat(pyk_int_str(width >= 0 ? width : 1), "px solid "), color__css(border)));
    }
}

static void style_pixels(const char *id, const char *kind, const char *property, int value)
{
    (void)(value < 0 ? 0 : (tinyweb_apply_style(id, kind, property, pyk_concat(pyk_int_str(value), "px")), 0));
}

void tinyweb_theme(const char *name)
{
    if (known_theme(name)) {
        tinyweb_apply_style("", "theme", "name", name);
    } else {
        fprintf(stderr, "%s\n", pyk_concat(pyk_concat("tinyweb: there is no theme called \"", name), "\"; the themes are light, dark, plain, paper and retro"));
    }
}

void tinyweb_page_style(pyk_d_Dtinyweb_Color__Color__ background, pyk_d_Dtinyweb_Color__Color__ foreground, const char *font, int size, int padding, int gap, const char *align)
{
    style_color("", "page", "background", background);
    style_color("", "page", "color", foreground);
    style_text("", "page", "font", font);
    style_pixels("", "page", "size", size);
    style_pixels("", "page", "padding", padding);
    style_pixels("", "page", "gap", gap);
    style_text("", "page", "align", align);
}

void tinyweb_button_style(pyk_d_Dtinyweb_Color__Color__ background, pyk_d_Dtinyweb_Color__Color__ foreground, pyk_d_Dtinyweb_Color__Color__ border, int border_width, int radius, const char *font, int size, int padding)
{
    style_color("", "button", "background", background);
    style_color("", "button", "color", foreground);
    style_border("", "button", border, border_width);
    style_pixels("", "button", "radius", radius);
    style_text("", "button", "font", font);
    style_pixels("", "button", "size", size);
    style_pixels("", "button", "padding", padding);
}

void tinyweb_label_style(pyk_d_Dtinyweb_Color__Color__ background, pyk_d_Dtinyweb_Color__Color__ foreground, pyk_d_Dtinyweb_Color__Color__ border, int border_width, int radius, const char *font, int size, int padding)
{
    style_color("", "label", "background", background);
    style_color("", "label", "color", foreground);
    style_border("", "label", border, border_width);
    style_pixels("", "label", "radius", radius);
    style_text("", "label", "font", font);
    style_pixels("", "label", "size", size);
    style_pixels("", "label", "padding", padding);
}

void tinyweb_slider_style(pyk_d_Dtinyweb_Color__Color__ accent, int width, pyk_d_Dtinyweb_Color__Color__ foreground, const char *font, int size)
{
    style_color("", "slider", "accent", accent);
    style_pixels("", "slider", "width", width);
    style_color("", "slider", "color", foreground);
    style_text("", "slider", "font", font);
    style_pixels("", "slider", "size", size);
}

void tinyweb_canvas_style(pyk_d_Dtinyweb_Color__Color__ border, int border_width, int radius)
{
    style_border("", "canvas", border, border_width);
    style_pixels("", "canvas", "radius", radius);
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_set_style__default__background(void)
{
    return tinyweb_color__theme;
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_set_style__default__foreground(void)
{
    return tinyweb_color__theme;
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_set_style__default__border(void)
{
    return tinyweb_color__theme;
}

pyk_d_Dtinyweb_Color__Color__ tinyweb_set_style__default__accent(void)
{
    return tinyweb_color__theme;
}

void tinyweb_set_style(const char *id, pyk_d_Dtinyweb_Color__Color__ background, pyk_d_Dtinyweb_Color__Color__ foreground, pyk_d_Dtinyweb_Color__Color__ border, int border_width, int radius, const char *font, int size, int padding, pyk_d_Dtinyweb_Color__Color__ accent, int width, int weight, int height)
{
    style_color(id, "element", "background", background);
    style_color(id, "element", "color", foreground);
    style_border(id, "element", border, border_width);
    style_pixels(id, "element", "radius", radius);
    style_text(id, "element", "font", font);
    style_pixels(id, "element", "size", size);
    style_pixels(id, "element", "padding", padding);
    style_color(id, "element", "accent", accent);
    style_pixels(id, "element", "width", width);
    if (weight >= 0) {
        style_text(id, "element", "weight", pyk_int_str(weight));
    }
    style_pixels(id, "element", "height", height);
}

void tinyweb_on_click(const char *c, pyk_c_Fii_u_ f)
{
    tinyweb_on_mouse(c, pyk_plain_Fii_u_(f));
}

void tinyweb_init(void)
{
    tinyweb_color__black = pyk_mk_Dtinyweb_Color__Color___Color__Color(0, 0, 0, 1.0);
    tinyweb_color__white = pyk_mk_Dtinyweb_Color__Color___Color__Color(255, 255, 255, 1.0);
    tinyweb_color__gray = pyk_mk_Dtinyweb_Color__Color___Color__Color(128, 128, 128, 1.0);
    tinyweb_color__red = pyk_mk_Dtinyweb_Color__Color___Color__Color(255, 0, 0, 1.0);
    tinyweb_color__green = pyk_mk_Dtinyweb_Color__Color___Color__Color(0, 128, 0, 1.0);
    tinyweb_color__blue = pyk_mk_Dtinyweb_Color__Color___Color__Color(0, 0, 255, 1.0);
    tinyweb_color__yellow = pyk_mk_Dtinyweb_Color__Color___Color__Color(255, 255, 0, 1.0);
    tinyweb_color__orange = pyk_mk_Dtinyweb_Color__Color___Color__Color(255, 165, 0, 1.0);
    tinyweb_color__purple = pyk_mk_Dtinyweb_Color__Color___Color__Color(128, 0, 128, 1.0);
    tinyweb_color__pink = pyk_mk_Dtinyweb_Color__Color___Color__Color(255, 192, 203, 1.0);
    tinyweb_color__navy = pyk_mk_Dtinyweb_Color__Color___Color__Color(0, 0, 128, 1.0);
    tinyweb_color__teal = pyk_mk_Dtinyweb_Color__Color___Color__Color(0, 128, 128, 1.0);
    tinyweb_color__brown = pyk_mk_Dtinyweb_Color__Color___Color__Color(139, 69, 19, 1.0);
    tinyweb_color__cyan = pyk_mk_Dtinyweb_Color__Color___Color__Color(0, 255, 255, 1.0);
    tinyweb_color__magenta = pyk_mk_Dtinyweb_Color__Color___Color__Color(255, 0, 255, 1.0);
    tinyweb_color__none = pyk_mk_Dtinyweb_Color__Color___Color__Color(0, 0, 0, 0.0);
    tinyweb_color__theme = pyk_mk_Dtinyweb_Color__Color___Color__Color(-1, -1, -1, -1.0);
}
