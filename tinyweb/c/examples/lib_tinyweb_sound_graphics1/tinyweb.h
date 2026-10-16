// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// What the module 'tinyweb' exports.

#ifndef PYK_TINYWEB_H
#define PYK_TINYWEB_H

#ifndef PYK_FN__V
#define PYK_FN__V
typedef void (*pyk_fn__v)(void);
#endif

const char *tinyweb_circle__default__color(void);
void tinyweb_circle(int c, int x, int y, int radius, const char *color);
pyk_fn__v tinyweb_button__default__on_click(void);
int tinyweb_button(const char *title, pyk_fn__v on_click);
double tinyweb_play__default__at(void);
double tinyweb_play__default__volume(void);
double tinyweb_play__default__rate(void);
void tinyweb_play(int sample, double at, double volume, double rate);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
