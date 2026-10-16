// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tinyweb.h"

// A Pyking function is a pointer to a C function.
#ifndef PYK_FN__V
#define PYK_FN__V
typedef void (*pyk_fn__v)(void);
#endif
#ifndef PYK_FN_I_V
#define PYK_FN_I_V
typedef void (*pyk_fn_i_v)(int);
#endif
#ifndef PYK_FN_F_V
#define PYK_FN_F_V
typedef void (*pyk_fn_f_v)(double);
#endif
#ifndef PYK_FN_II_V
#define PYK_FN_II_V
typedef void (*pyk_fn_ii_v)(int, int);
#endif
#ifndef PYK_FN_S_V
#define PYK_FN_S_V
typedef void (*pyk_fn_s_v)(const char *);
#endif

// What the external modules this one imports implement.
void tinyweb_web_init(int);
int tinyweb_canvas(int, int);
void tinyweb_fill_canvas(int, const char *);
void tinyweb_draw_circle(int, int, int, int, const char *);
void tinyweb_draw_rect(int, int, int, int, int, const char *);
void tinyweb_draw_line(int, int, int, int, int, const char *, int);
void tinyweb_draw_text(int, int, int, const char *, const char *, int);
int tinyweb_make_button(const char *, pyk_fn__v);
int tinyweb_label(const char *);
void tinyweb_set_label(int, const char *);
int tinyweb_make_slider(int, int, int, pyk_fn_i_v);
void tinyweb_apply_style(int, const char *, const char *, const char *);
int tinyweb_load_sample(const char *);
void tinyweb_play_sample(int, double, double, double);
double tinyweb_time(void);
void tinyweb_on_frame(pyk_fn_f_v);
void tinyweb_on_mouse(int, pyk_fn_ii_v);
void tinyweb_on_key(pyk_fn_s_v);

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

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void ignore(int value);
int tinyweb_button(const char *title, pyk_fn__v on_click);
pyk_fn_i_v tinyweb_slider__default__on_change(void);
int tinyweb_slider(int low, int high, int value, pyk_fn_i_v on_change);
static bool known_theme(const char *name);
static void style_text(int id, const char *kind, const char *property, const char *value);
static void style_pixels(int id, const char *kind, const char *property, int value);
void tinyweb_theme(const char *name);
void tinyweb_page_style(const char *background, const char *color, const char *font, int size, int padding, int gap);
void tinyweb_button_style(const char *background, const char *color, const char *border, int radius, const char *font, int size, int padding);
void tinyweb_label_style(const char *background, const char *color, const char *border, int radius, const char *font, int size, int padding);
void tinyweb_slider_style(const char *accent, int width, const char *color, const char *font, int size);
void tinyweb_canvas_style(const char *border, int radius);
const char *tinyweb_set_colors__default__color(void);
const char *tinyweb_set_colors__default__background(void);
void tinyweb_set_colors(int id, const char *color, const char *background);
const char *tinyweb_set_style__default__background(void);
const char *tinyweb_set_style__default__color(void);
int tinyweb_set_style__default__radius(void);
const char *tinyweb_set_style__default__font(void);
int tinyweb_set_style__default__size(void);
int tinyweb_set_style__default__padding(void);
const char *tinyweb_set_style__default__accent(void);
int tinyweb_set_style__default__width(void);
void tinyweb_set_style(int id, const char *background, const char *color, const char *border, int radius, const char *font, int size, int padding, const char *accent, int width);

static void ignore(int value)
{

}

int tinyweb_button(const char *title, pyk_fn__v on_click)
{
    return tinyweb_make_button(title, on_click);
}

pyk_fn_i_v tinyweb_slider__default__on_change(void)
{
    return ignore;
}

int tinyweb_slider(int low, int high, int value, pyk_fn_i_v on_change)
{
    return tinyweb_make_slider(low, high, value, on_change);
}

static bool known_theme(const char *name)
{
    const char *__subject = name;
    if (strcmp(__subject, "light") == 0) {
        return true;
    } else if (strcmp(__subject, "dark") == 0) {
        return true;
    } else if (strcmp(__subject, "plain") == 0) {
        return true;
    } else if (strcmp(__subject, "paper") == 0) {
        return true;
    } else if (strcmp(__subject, "retro") == 0) {
        return true;
    } else {
        return false;
    }
}

static void style_text(int id, const char *kind, const char *property, const char *value)
{
    if (strcmp(value, "") == 0) {

    } else {
        tinyweb_apply_style(id, kind, property, value);
    }
}

static void style_pixels(int id, const char *kind, const char *property, int value)
{
    if (value < 0) {

    } else {
        tinyweb_apply_style(id, kind, property, pyk_concat(pyk_int_str(value), "px"));
    }
}

void tinyweb_theme(const char *name)
{
    if (known_theme(name)) {
        tinyweb_apply_style(0, "theme", "name", name);
    } else {
        fprintf(stderr, "%s\n", pyk_concat(pyk_concat("tinyweb: there is no theme called \"", name), "\"; the themes are light, dark, plain, paper and retro"));
    }
}

void tinyweb_page_style(const char *background, const char *color, const char *font, int size, int padding, int gap)
{
    style_text(0, "page", "background", background);
    style_text(0, "page", "color", color);
    style_text(0, "page", "font", font);
    style_pixels(0, "page", "size", size);
    style_pixels(0, "page", "padding", padding);
    style_pixels(0, "page", "gap", gap);
}

void tinyweb_button_style(const char *background, const char *color, const char *border, int radius, const char *font, int size, int padding)
{
    style_text(0, "button", "background", background);
    style_text(0, "button", "color", color);
    style_text(0, "button", "border", border);
    style_pixels(0, "button", "radius", radius);
    style_text(0, "button", "font", font);
    style_pixels(0, "button", "size", size);
    style_pixels(0, "button", "padding", padding);
}

void tinyweb_label_style(const char *background, const char *color, const char *border, int radius, const char *font, int size, int padding)
{
    style_text(0, "label", "background", background);
    style_text(0, "label", "color", color);
    style_text(0, "label", "border", border);
    style_pixels(0, "label", "radius", radius);
    style_text(0, "label", "font", font);
    style_pixels(0, "label", "size", size);
    style_pixels(0, "label", "padding", padding);
}

void tinyweb_slider_style(const char *accent, int width, const char *color, const char *font, int size)
{
    style_text(0, "slider", "accent", accent);
    style_pixels(0, "slider", "width", width);
    style_text(0, "slider", "color", color);
    style_text(0, "slider", "font", font);
    style_pixels(0, "slider", "size", size);
}

void tinyweb_canvas_style(const char *border, int radius)
{
    style_text(0, "canvas", "border", border);
    style_pixels(0, "canvas", "radius", radius);
}

const char *tinyweb_set_colors__default__color(void)
{
    return "";
}

const char *tinyweb_set_colors__default__background(void)
{
    return "";
}

void tinyweb_set_colors(int id, const char *color, const char *background)
{
    style_text(id, "element", "color", color);
    style_text(id, "element", "accent", color);
    style_text(id, "element", "background", background);
}

const char *tinyweb_set_style__default__background(void)
{
    return "";
}

const char *tinyweb_set_style__default__color(void)
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

void tinyweb_set_style(int id, const char *background, const char *color, const char *border, int radius, const char *font, int size, int padding, const char *accent, int width)
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
}

void tinyweb_init(void)
{

}
