// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
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
const char *tinyweb_bitmap(int, int);
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
void tinyweb_play_sample(const char *, double, double, double);
void tinyweb_splash(void);
void tinyweb_set_splash(const char *);
double tinyweb_time(void);
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

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void nothing(void);
static void ignore(int value);
int tinyweb_web_init__default__port(void);
void tinyweb_web_init(int port);
pyk_c_F_u_ tinyweb_button__default__on_click(void);
const char *tinyweb_button(const char *title, pyk_c_F_u_ on_click);
pyk_c_Fi_u_ tinyweb_slider__default__on_change(void);
const char *tinyweb_slider(int low, int high, int value, pyk_c_Fi_u_ on_change);
static void style_text(const char *id, const char *kind, const char *property, const char *value);
static void style_pixels(const char *id, const char *kind, const char *property, int value);
const char *tinyweb_page_style__default__background(void);
const char *tinyweb_page_style__default__color(void);
const char *tinyweb_page_style__default__font(void);
int tinyweb_page_style__default__size(void);
int tinyweb_page_style__default__padding(void);
int tinyweb_page_style__default__gap(void);
void tinyweb_page_style(const char *background, const char *color, const char *font, int size, int padding, int gap, const char *align);
const char *tinyweb_set_style__default__background(void);
const char *tinyweb_set_style__default__color(void);
const char *tinyweb_set_style__default__border(void);
int tinyweb_set_style__default__radius(void);
const char *tinyweb_set_style__default__font(void);
int tinyweb_set_style__default__size(void);
int tinyweb_set_style__default__padding(void);
const char *tinyweb_set_style__default__accent(void);
int tinyweb_set_style__default__width(void);
int tinyweb_set_style__default__weight(void);
int tinyweb_set_style__default__height(void);
void tinyweb_set_style(const char *id, const char *background, const char *color, const char *border, int radius, const char *font, int size, int padding, const char *accent, int width, int weight, int height);

static void pyk_w_nothing(void *env)
{
    (void)env;
    nothing();
}

static void pyk_w_ignore(void *env, int p1)
{
    (void)env;
    ignore(p1);
}

static void nothing(void)
{

}

static void ignore(int value)
{

}

int tinyweb_web_init__default__port(void)
{
    return 0;
}

void tinyweb_web_init(int port)
{
    tinyweb_web_start(port);
}

pyk_c_F_u_ tinyweb_button__default__on_click(void)
{
    return pyk_mk_F_u_(pyk_w_nothing, NULL, nothing);
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

static void style_text(const char *id, const char *kind, const char *property, const char *value)
{
    if (strcmp(value, "") == 0) {

    } else {
        tinyweb_apply_style(id, kind, property, value);
    }
}

static void style_pixels(const char *id, const char *kind, const char *property, int value)
{
    if (value < 0) {

    } else {
        tinyweb_apply_style(id, kind, property, pyk_concat(pyk_int_str(value), "px"));
    }
}

const char *tinyweb_page_style__default__background(void)
{
    return "";
}

const char *tinyweb_page_style__default__color(void)
{
    return "";
}

const char *tinyweb_page_style__default__font(void)
{
    return "";
}

int tinyweb_page_style__default__size(void)
{
    return -1;
}

int tinyweb_page_style__default__padding(void)
{
    return -1;
}

int tinyweb_page_style__default__gap(void)
{
    return -1;
}

void tinyweb_page_style(const char *background, const char *color, const char *font, int size, int padding, int gap, const char *align)
{
    style_text("", "page", "background", background);
    style_text("", "page", "color", color);
    style_text("", "page", "font", font);
    style_pixels("", "page", "size", size);
    style_pixels("", "page", "padding", padding);
    style_pixels("", "page", "gap", gap);
    style_text("", "page", "align", align);
}

const char *tinyweb_set_style__default__background(void)
{
    return "";
}

const char *tinyweb_set_style__default__color(void)
{
    return "";
}

const char *tinyweb_set_style__default__border(void)
{
    return "";
}

int tinyweb_set_style__default__radius(void)
{
    return -1;
}

const char *tinyweb_set_style__default__font(void)
{
    return "";
}

int tinyweb_set_style__default__size(void)
{
    return -1;
}

int tinyweb_set_style__default__padding(void)
{
    return -1;
}

const char *tinyweb_set_style__default__accent(void)
{
    return "";
}

int tinyweb_set_style__default__width(void)
{
    return -1;
}

int tinyweb_set_style__default__weight(void)
{
    return -1;
}

int tinyweb_set_style__default__height(void)
{
    return -1;
}

void tinyweb_set_style(const char *id, const char *background, const char *color, const char *border, int radius, const char *font, int size, int padding, const char *accent, int width, int weight, int height)
{
    style_text(id, "element", "background", background);
    style_text(id, "element", "color", color);
    style_text(id, "element", "border", border);
    style_pixels(id, "element", "radius", radius);
    style_text(id, "element", "font", font);
    style_pixels(id, "element", "size", size);
    style_pixels(id, "element", "padding", padding);
    style_text(id, "element", "accent", accent);
    style_pixels(id, "element", "width", width);
    if (weight >= 0) {
        style_text(id, "element", "weight", pyk_int_str(weight));
    }
    style_pixels(id, "element", "height", height);
}

void tinyweb_init(void)
{

}
