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

#ifndef PYK_TYPE_PYK_D_DTINYWEB_COLOR__PAINT__
#define PYK_TYPE_PYK_D_DTINYWEB_COLOR__PAINT__
typedef struct pyk_d_Dtinyweb_Color__Paint__ {
    int tag;
    union {
        struct {
            pyk_d_Dtinyweb_Color__Color__ f0;
        } Color__Plain;
        struct {
            double f0;
            double f1;
            double f2;
            double f3;
            pyk_d_Dtinyweb_Color__Color__ f4;
            pyk_d_Dtinyweb_Color__Color__ f5;
            const char *f6;
        } Color__Linear;
        struct {
            double f0;
            double f1;
            double f2;
            double f3;
            double f4;
            double f5;
            pyk_d_Dtinyweb_Color__Color__ f6;
            pyk_d_Dtinyweb_Color__Color__ f7;
            const char *f8;
        } Color__Radial;
        struct {
            double f0;
            double f1;
            double f2;
            pyk_d_Dtinyweb_Color__Color__ f3;
            pyk_d_Dtinyweb_Color__Color__ f4;
            const char *f5;
        } Color__Conic;
    } u;
} pyk_d_Dtinyweb_Color__Paint__;
#endif

#ifndef PYK_TYPE_PYK_D_DTINYWEB_STYLE__
#define PYK_TYPE_PYK_D_DTINYWEB_STYLE__
typedef struct pyk_d_Dtinyweb_Style__ {
    pyk_d_Dtinyweb_Color__Color__ fill;
    pyk_d_Dtinyweb_Color__Color__ stroke;
    int width;
    double alpha;
    pyk_d_Dtinyweb_Color__Paint__ paint;
} pyk_d_Dtinyweb_Style__;
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

bool tinyweb_color__same(pyk_d_Dtinyweb_Color__Color__ a, pyk_d_Dtinyweb_Color__Color__ b);
void tinyweb_web_init(int port);
pyk_d_Dtinyweb_Color__Color__ tinyweb_field__default__Style__fill(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_field__default__Style__stroke(void);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_field__default__Style__paint(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_circle__default__stroke(void);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_circle__default__paint(void);
pyk_d_Dtinyweb_Style__ tinyweb_circle__default__style(void);
void tinyweb_circle(const char *c, int x, int y, int radius, pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Color__ stroke, int width, double alpha, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style);
void tinyweb_net__save_canvas(const char *c, const char *name);
void tinyweb_net__download(const char *name, const char *words);
const char *tinyweb_net__file_button(const char *title, pyk_c_Fs_u_ on_load);
const char *tinyweb_net__file_text(void);
void tinyweb_game__cursor(const char *c, const char *name);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
