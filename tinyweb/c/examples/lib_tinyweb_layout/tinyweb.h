// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// What the module 'tinyweb' exports.

#ifndef PYK_TINYWEB_H
#define PYK_TINYWEB_H

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

int tinyweb_web_init__default__port(void);
void tinyweb_web_init(int port);
pyk_c_F_u_ tinyweb_button__default__on_click(void);
const char *tinyweb_button(const char *title, pyk_c_F_u_ on_click);
pyk_c_Fi_u_ tinyweb_slider__default__on_change(void);
const char *tinyweb_slider(int low, int high, int value, pyk_c_Fi_u_ on_change);
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

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
