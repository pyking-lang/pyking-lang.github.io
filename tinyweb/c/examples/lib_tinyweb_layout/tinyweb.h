// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// What the module 'tinyweb' exports.

#ifndef PYK_TINYWEB_H
#define PYK_TINYWEB_H

#ifndef PYK_TYPE_PYK_D_DTINYWEB_COLOR__COLOR__
#define PYK_TYPE_PYK_D_DTINYWEB_COLOR__COLOR__
typedef struct pyk_d_Dtinyweb_Color__Color__ {
    int r;
    int g;
    int b;
    double a;
} pyk_d_Dtinyweb_Color__Color__;
#endif

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

#ifndef PYK_TYPE_PYK_C_FII_U_
#define PYK_TYPE_PYK_C_FII_U_
typedef struct pyk_c_Fii_u_ {
    void (*fn)(void *, int, int);
    void *env;
    void (*plain)(int, int);
} pyk_c_Fii_u_;
#endif

#ifndef PYK_TYPE_PYK_C_FS_U_
#define PYK_TYPE_PYK_C_FS_U_
typedef struct pyk_c_Fs_u_ {
    void (*fn)(void *, const char *);
    void *env;
    void (*plain)(const char *);
} pyk_c_Fs_u_;
#endif

extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__black;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__white;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__gray;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__red;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__green;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__blue;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__yellow;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__orange;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__purple;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__pink;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__navy;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__teal;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__brown;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__cyan;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__magenta;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__none;
extern pyk_d_Dtinyweb_Color__Color__ tinyweb_color__theme;

void tinyweb_web_init(int port);
pyk_c_F_u_ tinyweb_button__default__on_click(void);
const char *tinyweb_button(const char *title, pyk_c_F_u_ on_click);
pyk_c_Fi_u_ tinyweb_slider__default__on_change(void);
const char *tinyweb_slider(int low, int high, int value, pyk_c_Fi_u_ on_change);
const char *tinyweb_value_of(const char *id);
pyk_d_Dtinyweb_Color__Color__ tinyweb_page_style__default__background(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_page_style__default__foreground(void);
void tinyweb_page_style(pyk_d_Dtinyweb_Color__Color__ background, pyk_d_Dtinyweb_Color__Color__ foreground, const char *font, int size, int padding, int gap, const char *align);
pyk_d_Dtinyweb_Color__Color__ tinyweb_set_style__default__background(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_set_style__default__foreground(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_set_style__default__border(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_set_style__default__accent(void);
void tinyweb_set_style(const char *id, pyk_d_Dtinyweb_Color__Color__ background, pyk_d_Dtinyweb_Color__Color__ foreground, pyk_d_Dtinyweb_Color__Color__ border, int border_width, int radius, const char *font, int size, int padding, pyk_d_Dtinyweb_Color__Color__ accent, int width, int weight, int height);
void tinyweb_on_click(const char *c, pyk_c_Fii_u_ f);
const char *tinyweb_layout__row(void);
const char *tinyweb_layout__column(void);
void tinyweb_layout__inside(const char *id);
void tinyweb_layout__outside(void);
pyk_c_Fs_u_ tinyweb_layout__text_area__default__on_change(void);
const char *tinyweb_layout__text_area(const char *words, int rows, int columns, pyk_c_Fs_u_ on_change);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
