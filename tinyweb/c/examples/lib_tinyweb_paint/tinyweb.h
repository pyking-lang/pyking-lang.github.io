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

#ifndef PYK_TYPE_PYK_C_FF_U_
#define PYK_TYPE_PYK_C_FF_U_
typedef struct pyk_c_Ff_u_ {
    void (*fn)(void *, double);
    void *env;
    void (*plain)(double);
} pyk_c_Ff_u_;
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
bool tinyweb_color__same(pyk_d_Dtinyweb_Color__Color__ a, pyk_d_Dtinyweb_Color__Color__ b);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_color__stop(pyk_d_Dtinyweb_Color__Paint__ paint, double at, pyk_d_Dtinyweb_Color__Color__ c);
void tinyweb_web_init(int port);
pyk_d_Dtinyweb_Color__Color__ tinyweb_field__default__Style__fill(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_field__default__Style__stroke(void);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_field__default__Style__paint(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_circle__default__fill(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_circle__default__stroke(void);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_circle__default__paint(void);
pyk_d_Dtinyweb_Style__ tinyweb_circle__default__style(void);
void tinyweb_circle(const char *c, int x, int y, int radius, pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Color__ stroke, int width, double alpha, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style);
pyk_d_Dtinyweb_Color__Color__ tinyweb_rect__default__fill(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_rect__default__stroke(void);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_rect__default__paint(void);
pyk_d_Dtinyweb_Style__ tinyweb_rect__default__style(void);
void tinyweb_rect(const char *c, int x, int y, int w, int h, pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Color__ stroke, int width, double alpha, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style, int radius);
pyk_d_Dtinyweb_Color__Color__ tinyweb_line__default__stroke(void);
pyk_d_Dtinyweb_Style__ tinyweb_line__default__style(void);
void tinyweb_line(const char *c, int x1, int y1_, int x2, int y2, pyk_d_Dtinyweb_Color__Color__ stroke, int width, double alpha, pyk_d_Dtinyweb_Style__ style);
pyk_d_Dtinyweb_Style__ tinyweb_bezier__default__style(void);
void tinyweb_bezier(const char *c, int x1, int y1_, int ax, int ay, int bx, int by, int x2, int y2, pyk_d_Dtinyweb_Color__Color__ stroke, int width, double alpha, pyk_d_Dtinyweb_Style__ style);
void tinyweb_erase(const char *c, int x, int y, int w, int h);
void tinyweb_line_style(const char *c, const char *cap, const char *join, double dash, double gap, double offset, double dash2, double gap2);
void tinyweb_clip_rect(const char *c, int x, int y, int w, int h);
void tinyweb_clip_circle(const char *c, int x, int y, int radius);
pyk_d_Dtinyweb_Color__Color__ tinyweb_text__default__stroke(void);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_text__default__paint(void);
pyk_d_Dtinyweb_Style__ tinyweb_text__default__style(void);
void tinyweb_text(const char *c, int x, int y, const char *words, pyk_d_Dtinyweb_Color__Color__ fill, int size, const char *font, const char *align, bool bold, double alpha, const char *baseline, pyk_d_Dtinyweb_Color__Color__ stroke, int width, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style);
void tinyweb_measure_text(const char *words, pyk_c_Ff_u_ answer, int size, const char *font, bool bold);
void tinyweb_push(const char *c);
void tinyweb_pop(const char *c);
pyk_d_Dtinyweb_Color__Color__ tinyweb_smooth__circle__default__fill(void);
pyk_d_Dtinyweb_Color__Color__ tinyweb_smooth__circle__default__stroke(void);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_smooth__circle__default__paint(void);
pyk_d_Dtinyweb_Style__ tinyweb_smooth__circle__default__style(void);
void tinyweb_smooth__circle(const char *c, double x, double y, double radius, pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Color__ stroke, double width, double alpha, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_smooth__rect__default__paint(void);
pyk_d_Dtinyweb_Style__ tinyweb_smooth__rect__default__style(void);
void tinyweb_smooth__rect(const char *c, double x, double y, double w, double h, pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Color__ stroke, double width, double alpha, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style, double radius);
pyk_d_Dtinyweb_Color__Color__ tinyweb_smooth__ellipse__default__stroke(void);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_smooth__ellipse__default__paint(void);
pyk_d_Dtinyweb_Style__ tinyweb_smooth__ellipse__default__style(void);
void tinyweb_smooth__ellipse(const char *c, double x, double y, double rx, double ry, pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Color__ stroke, double width, double alpha, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_smooth__arc__default__paint(void);
pyk_d_Dtinyweb_Style__ tinyweb_smooth__arc__default__style(void);
void tinyweb_smooth__arc(const char *c, double x, double y, double radius, double start, double end, pyk_d_Dtinyweb_Color__Color__ fill, pyk_d_Dtinyweb_Color__Color__ stroke, double width, double alpha, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style);
pyk_d_Dtinyweb_Style__ tinyweb_smooth__line__default__style(void);
void tinyweb_smooth__line(const char *c, double x1, double y1_, double x2, double y2, pyk_d_Dtinyweb_Color__Color__ stroke, double width, double alpha, pyk_d_Dtinyweb_Style__ style);
pyk_d_Dtinyweb_Style__ tinyweb_smooth__curve__default__style(void);
void tinyweb_smooth__curve(const char *c, double x1, double y1_, double cx, double cy, double x2, double y2, pyk_d_Dtinyweb_Color__Color__ stroke, double width, double alpha, pyk_d_Dtinyweb_Style__ style);
pyk_d_Dtinyweb_Style__ tinyweb_smooth__bezier__default__style(void);
void tinyweb_smooth__bezier(const char *c, double x1, double y1_, double ax, double ay, double bx, double by, double x2, double y2, pyk_d_Dtinyweb_Color__Color__ stroke, double width, double alpha, pyk_d_Dtinyweb_Style__ style);
pyk_d_Dtinyweb_Color__Color__ tinyweb_smooth__text__default__stroke(void);
pyk_d_Dtinyweb_Color__Paint__ tinyweb_smooth__text__default__paint(void);
pyk_d_Dtinyweb_Style__ tinyweb_smooth__text__default__style(void);
void tinyweb_smooth__text(const char *c, double x, double y, const char *words, pyk_d_Dtinyweb_Color__Color__ fill, int size, const char *font, const char *align, bool bold, double alpha, const char *baseline, pyk_d_Dtinyweb_Color__Color__ stroke, double width, pyk_d_Dtinyweb_Color__Paint__ paint, pyk_d_Dtinyweb_Style__ style);
void tinyweb_smooth__clip_circle(const char *c, double x, double y, double radius);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
