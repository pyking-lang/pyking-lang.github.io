// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// What the module 'tinyweb' exports.

#ifndef PYK_TINYWEB_H
#define PYK_TINYWEB_H

#ifndef PYK_FN_I_V
#define PYK_FN_I_V
typedef void (*pyk_fn_i_v)(int);
#endif

void tinyweb_circle(int c, int x, int y, int radius, const char *color);
void tinyweb_rect(int c, int x, int y, int width, int height, const char *color);
const char *tinyweb_line__default__color(void);
int tinyweb_line__default__width(void);
void tinyweb_line(int c, int x1, int y12, int x2, int y2, const char *color, int width);
const char *tinyweb_text__default__color(void);
void tinyweb_text(int c, int x, int y, const char *words, const char *color, int size);
pyk_fn_i_v tinyweb_slider__default__on_change(void);
int tinyweb_slider(int low, int high, int value, pyk_fn_i_v on_change);
double tinyweb_play__default__at(void);
double tinyweb_play__default__volume(void);
double tinyweb_play__default__rate(void);
void tinyweb_play(int sample, double at, double volume, double rate);
void tinyweb_play_file(const char *name);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
