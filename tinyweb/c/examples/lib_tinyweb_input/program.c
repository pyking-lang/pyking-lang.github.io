// Generated from lib_tinyweb_input.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tinyweb.h"

// A Pyking function is a pointer to a C function.
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
int tinyweb_label(const char *);
void tinyweb_set_label(int, const char *);
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

// What the top level binds, where every function can read it; the top level below is what fills each of them in.
static int c;
static int status;

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static void clicked(int x, int y);
static void pressed(const char *key);
static void moved(int value);

static void clicked(int x, int y)
{
    tinyweb_set_label(status, pyk_concat(pyk_concat(pyk_concat("clicked at ", pyk_int_str(x)), ", "), pyk_int_str(y)));
    tinyweb_circle(c, x, y, 5, "blue");
}

static void pressed(const char *key)
{
    printf("%s\n", pyk_concat(pyk_concat("key [", key), "]"));
    if (strcmp(key, "Enter") == 0) {
        tinyweb_play_file("snare1.wav");
    }
}

static void moved(int value)
{
    tinyweb_set_label(status, pyk_concat("slider at ", pyk_int_str(value)));
}

int main(void)
{
    const char *tmp1;
    tinyweb_init();
    tinyweb_web_init(0);
    c = tinyweb_canvas(300, 200);
    tinyweb_rect(c, 0, 0, 300, 200, "#eeeeee");
    (tmp1 = tinyweb_line__default__color(), tinyweb_line(c, 0, 0, 300, 200, tmp1, tinyweb_line__default__width()));
    tinyweb_line(c, 0, 200, 300, 0, "red", 3);
    tinyweb_text(c, 10, 10, "click \"me\"", tinyweb_text__default__color(), 20);
    status = tinyweb_label("nothing yet");
    tinyweb_on_mouse(c, clicked);
    tinyweb_on_key(pressed);
    tinyweb_slider(0, 10, 5, moved);
    tinyweb_slider(1, 3, 2, tinyweb_slider__default__on_change());

    return 0;
}
