// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// What the module 'tinyweb' exports.

#ifndef PYK_TINYWEB_H
#define PYK_TINYWEB_H

#ifndef PYK_FN__V
#define PYK_FN__V
typedef void (*pyk_fn__v)(void);
#endif
#ifndef PYK_FN_I_V
#define PYK_FN_I_V
typedef void (*pyk_fn_i_v)(int);
#endif

int tinyweb_button(const char *title, pyk_fn__v on_click);
pyk_fn_i_v tinyweb_slider__default__on_change(void);
int tinyweb_slider(int low, int high, int value, pyk_fn_i_v on_change);
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

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
