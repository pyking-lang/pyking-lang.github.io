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

pyk_d_Dtinyweb_Color__Color__ tinyweb_color__hex(int n);
void tinyweb_web_init(int port);
void tinyweb_clear(const char *c, pyk_d_Dtinyweb_Color__Color__ fill);
void tinyweb_image(const char *c, const char *picture, int x, int y, int w, int h, double alpha);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
