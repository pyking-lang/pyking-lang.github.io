// Generated from lib_tinyweb_widgets.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tinyweb.h"

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

#ifndef PYK_TYPE_PYK_C_FI_U_
#define PYK_TYPE_PYK_C_FI_U_
typedef struct pyk_c_Fi_u_ {
    void (*fn)(void *, int);
    void *env;
    void (*plain)(int);
} pyk_c_Fi_u_;
#endif

// What the external modules this one imports implement.
const char *tinyweb_label(const char *);
void tinyweb_set_label(const char *, const char *);
void tinyweb_set_checked(const char *, bool);
void tinyweb_set_value(const char *, int);

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

static pyk_c_Fb_u_ pyk_mk_Fb_u_(void (*fn)(void *, bool), void *env, void (*plain)(bool))
{
    pyk_c_Fb_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static pyk_c_Fs_u_ pyk_mk_Fs_u_(void (*fn)(void *, const char *), void *env, void (*plain)(const char *))
{
    pyk_c_Fs_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static pyk_c_Fi_u_ pyk_mk_Fi_u_(void (*fn)(void *, int), void *env, void (*plain)(int))
{
    pyk_c_Fi_u_ v;
    v.fn = fn;
    v.env = env;
    v.plain = plain;
    return v;
}

static const char *shown;
static const char *box;
static const char *frame_based;
static const char *count;
static const char *speed;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void trails(bool on);
static void mode(const char *title);
static void entered(const char *name);
static void balls(int n);

static void pyk_w_trails(void *env, bool p1)
{
    (void)env;
    trails(p1);
}

static void pyk_w_mode(void *env, const char *p1)
{
    (void)env;
    mode(p1);
}

static void pyk_w_entered(void *env, const char *p1)
{
    (void)env;
    entered(p1);
}

static void pyk_w_balls(void *env, int p1)
{
    (void)env;
    balls(p1);
}

static void trails(bool on)
{
    tinyweb_set_label(shown, on ? "trails on" : "trails off");
}

static void mode(const char *title)
{
    tinyweb_set_label(shown, pyk_concat("mode: ", title));
}

static void entered(const char *name)
{
    tinyweb_set_label(shown, pyk_concat("hello, ", name));
}

static void balls(int n)
{
    tinyweb_set_label(shown, pyk_concat(pyk_int_str(n), " balls"));
}

int main(void)
{
    bool pyk_t1;
    const char *pyk_t2;
    tinyweb_init();
    tinyweb_web_init(0);
    shown = tinyweb_label("nothing yet");
    box = tinyweb_checkbox("Trails", tinyweb_checkbox__default__checked(), pyk_mk_Fb_u_(pyk_w_trails, NULL, trails));
    tinyweb_checkbox("Slow frames", true, tinyweb_checkbox__default__on_change());
    tinyweb_radio("mode", "time-based", tinyweb_radio__default__chosen(), pyk_mk_Fs_u_(pyk_w_mode, NULL, mode));
    frame_based = tinyweb_radio("mode", "frame-based", tinyweb_radio__default__chosen(), pyk_mk_Fs_u_(pyk_w_mode, NULL, mode));
    (pyk_t1 = tinyweb_radio__default__chosen(), tinyweb_radio("speed", "slow", pyk_t1, tinyweb_radio__default__on_pick()));
    tinyweb_radio("speed", "fast", true, tinyweb_radio__default__on_pick());
    tinyweb_text_input("your name", pyk_mk_Fs_u_(pyk_w_entered, NULL, entered));
    (pyk_t2 = tinyweb_text_input__default__placeholder(), tinyweb_text_input(pyk_t2, tinyweb_text_input__default__on_enter()));
    count = tinyweb_number_input(1, 20, 3, pyk_mk_Fi_u_(pyk_w_balls, NULL, balls));
    speed = tinyweb_slider(0, 10, 5, tinyweb_slider__default__on_change());
    tinyweb_set_checked(box, true);
    tinyweb_set_checked(frame_based, true);
    tinyweb_set_value(count, 5);
    tinyweb_set_value(speed, 8);
    printf("%s\n", frame_based);

    return 0;
}
