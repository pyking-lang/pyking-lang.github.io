// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>
#include <stdlib.h>

// Every multiply and add rounded on its own, as on every other target.
#if defined(__clang__)
#pragma STDC FP_CONTRACT OFF
#elif defined(__GNUC__)
#pragma GCC optimize ("fp-contract=off")
#endif

#include "tinyweb.h"

#ifndef PYK_TYPE_PYK_C_FI_U_
#define PYK_TYPE_PYK_C_FI_U_
typedef struct pyk_c_Fi_u_ {
    void (*fn)(void *, int);
    void *env;
    void (*plain)(int);
} pyk_c_Fi_u_;
#endif

#ifndef PYK_TYPE_PYK_C_FB_U_
#define PYK_TYPE_PYK_C_FB_U_
typedef struct pyk_c_Fb_u_ {
    void (*fn)(void *, bool);
    void *env;
    void (*plain)(bool);
} pyk_c_Fb_u_;
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

static pyk_c_Fb_u_ pyk_mk_Fb_u_(void (*fn)(void *, bool), void *env, void (*plain)(bool))
{
    pyk_c_Fb_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static pyk_fn_b_v pyk_plain_Fb_u_(pyk_c_Fb_u_ c)
{
    if (c.plain == NULL) {
        fprintf(stderr, "a function that captures values cannot be handed to a module implemented in C\n");
        exit(1);
    }
    return c.plain;
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

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void ignore(int value);
static void ignore_bool(bool value);
static void ignore_text(const char *value);
void tinyweb_web_init(int port);
pyk_c_Fi_u_ tinyweb_slider__default__on_change(void);
const char *tinyweb_slider(int low, int high, int value, pyk_c_Fi_u_ on_change);
bool tinyweb_checkbox__default__checked(void);
pyk_c_Fb_u_ tinyweb_checkbox__default__on_change(void);
const char *tinyweb_checkbox(const char *title, bool checked, pyk_c_Fb_u_ on_change);
bool tinyweb_radio__default__chosen(void);
pyk_c_Fs_u_ tinyweb_radio__default__on_pick(void);
const char *tinyweb_radio(const char *group, const char *title, bool chosen, pyk_c_Fs_u_ on_pick);
const char *tinyweb_text_input__default__placeholder(void);
pyk_c_Fs_u_ tinyweb_text_input__default__on_enter(void);
const char *tinyweb_text_input(const char *placeholder, pyk_c_Fs_u_ on_enter);
const char *tinyweb_number_input(int low, int high, int value, pyk_c_Fi_u_ on_change);

static void pyk_w_ignore(void *env, int p1)
{
    (void)env;
    ignore(p1);
}

static void pyk_w_ignore_bool(void *env, bool p1)
{
    (void)env;
    ignore_bool(p1);
}

static void pyk_w_ignore_text(void *env, const char *p1)
{
    (void)env;
    ignore_text(p1);
}

static void ignore(int value)
{

}

static void ignore_bool(bool value)
{

}

static void ignore_text(const char *value)
{

}

void tinyweb_web_init(int port)
{
    tinyweb_web_start(port);
}

pyk_c_Fi_u_ tinyweb_slider__default__on_change(void)
{
    return pyk_mk_Fi_u_(pyk_w_ignore, NULL, ignore);
}

const char *tinyweb_slider(int low, int high, int value, pyk_c_Fi_u_ on_change)
{
    return tinyweb_make_slider(low, high, value, pyk_plain_Fi_u_(on_change));
}

bool tinyweb_checkbox__default__checked(void)
{
    return false;
}

pyk_c_Fb_u_ tinyweb_checkbox__default__on_change(void)
{
    return pyk_mk_Fb_u_(pyk_w_ignore_bool, NULL, ignore_bool);
}

const char *tinyweb_checkbox(const char *title, bool checked, pyk_c_Fb_u_ on_change)
{
    return tinyweb_make_checkbox(title, checked, pyk_plain_Fb_u_(on_change));
}

bool tinyweb_radio__default__chosen(void)
{
    return false;
}

pyk_c_Fs_u_ tinyweb_radio__default__on_pick(void)
{
    return pyk_mk_Fs_u_(pyk_w_ignore_text, NULL, ignore_text);
}

const char *tinyweb_radio(const char *group, const char *title, bool chosen, pyk_c_Fs_u_ on_pick)
{
    return tinyweb_make_radio(group, title, chosen, pyk_plain_Fs_u_(on_pick));
}

const char *tinyweb_text_input__default__placeholder(void)
{
    return "";
}

pyk_c_Fs_u_ tinyweb_text_input__default__on_enter(void)
{
    return pyk_mk_Fs_u_(pyk_w_ignore_text, NULL, ignore_text);
}

const char *tinyweb_text_input(const char *placeholder, pyk_c_Fs_u_ on_enter)
{
    return tinyweb_make_text_input(placeholder, pyk_plain_Fs_u_(on_enter));
}

const char *tinyweb_number_input(int low, int high, int value, pyk_c_Fi_u_ on_change)
{
    return tinyweb_make_number_input(low, high, value, pyk_plain_Fi_u_(on_change));
}

void tinyweb_init(void)
{

}
