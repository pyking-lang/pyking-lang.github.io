// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// What the module 'tinyweb' exports.

#ifndef PYK_TINYWEB_H
#define PYK_TINYWEB_H

#ifndef PYK_TYPE_PYK_C_FII_U_
#define PYK_TYPE_PYK_C_FII_U_
typedef struct pyk_c_Fii_u_ {
    void (*fn)(void *, int, int);
    void *env;
    void (*plain)(int, int);
} pyk_c_Fii_u_;
#endif

void tinyweb_web_init(int port);
const char *tinyweb_circle__default__outline(void);
int tinyweb_circle__default__outline_width(void);
double tinyweb_circle__default__alpha(void);
void tinyweb_circle(const char *c, int x, int y, int radius, const char *color, const char *outline, int outline_width, double alpha);
double tinyweb_line__default__alpha(void);
void tinyweb_line(const char *c, int x1, int y1_, int x2, int y2, const char *color, int width, double alpha);
void tinyweb_on_press(const char *c, pyk_c_Fii_u_ f);
void tinyweb_on_release(const char *c, pyk_c_Fii_u_ f);
void tinyweb_on_move(const char *c, pyk_c_Fii_u_ f);
void tinyweb_on_drag(const char *c, pyk_c_Fii_u_ f);
int tinyweb_mouse_x(const char *c);
int tinyweb_mouse_y(const char *c);
bool tinyweb_mouse_down(const char *c);
void tinyweb_ignore2(int x, int y);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
