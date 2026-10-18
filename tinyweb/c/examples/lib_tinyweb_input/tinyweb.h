// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// What the module 'tinyweb' exports.

#ifndef PYK_TINYWEB_H
#define PYK_TINYWEB_H

#ifndef PYK_TYPE_PYK_C_FI_U_
#define PYK_TYPE_PYK_C_FI_U_
typedef struct pyk_c_Fi_u_ {
    void (*fn)(void *, int);
    void *env;
    void (*plain)(int);
} pyk_c_Fi_u_;
#endif

void tinyweb_web_init(int port);
const char *tinyweb_circle__default__outline(void);
int tinyweb_circle__default__outline_width(void);
double tinyweb_circle__default__alpha(void);
void tinyweb_circle(const char *c, int x, int y, int radius, const char *color, const char *outline, int outline_width, double alpha);
const char *tinyweb_rect__default__outline(void);
int tinyweb_rect__default__outline_width(void);
double tinyweb_rect__default__alpha(void);
int tinyweb_rect__default__radius(void);
void tinyweb_rect(const char *c, int x, int y, int width, int height, const char *color, const char *outline, int outline_width, double alpha, int radius);
const char *tinyweb_line__default__color(void);
int tinyweb_line__default__width(void);
double tinyweb_line__default__alpha(void);
void tinyweb_line(const char *c, int x1, int y1_, int x2, int y2, const char *color, int width, double alpha);
const char *tinyweb_text__default__color(void);
const char *tinyweb_text__default__font(void);
const char *tinyweb_text__default__align(void);
bool tinyweb_text__default__bold(void);
double tinyweb_text__default__alpha(void);
const char *tinyweb_text__default__baseline(void);
const char *tinyweb_text__default__outline(void);
int tinyweb_text__default__outline_width(void);
void tinyweb_text(const char *c, int x, int y, const char *words, const char *color, int size, const char *font, const char *align, bool bold, double alpha, const char *baseline, const char *outline, int outline_width);
pyk_c_Fi_u_ tinyweb_slider__default__on_change(void);
const char *tinyweb_slider(int low, int high, int value, pyk_c_Fi_u_ on_change);
double tinyweb_play__default__at(void);
double tinyweb_play__default__volume(void);
double tinyweb_play__default__rate(void);
void tinyweb_play(const char *sample, double at, double volume, double rate);
void tinyweb_play_file(const char *name);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
