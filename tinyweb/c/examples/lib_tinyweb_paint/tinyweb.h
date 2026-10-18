// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// What the module 'tinyweb' exports.

#ifndef PYK_TINYWEB_H
#define PYK_TINYWEB_H

#ifndef PYK_TYPE_PYK_C_FF_U_
#define PYK_TYPE_PYK_C_FF_U_
typedef struct pyk_c_Ff_u_ {
    void (*fn)(void *, double);
    void *env;
    void (*plain)(double);
} pyk_c_Ff_u_;
#endif

void tinyweb_clear(const char *c, const char *color);
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
double tinyweb_line__default__alpha(void);
void tinyweb_line(const char *c, int x1, int y1_, int x2, int y2, const char *color, int width, double alpha);
double tinyweb_bezier__default__alpha(void);
void tinyweb_bezier(const char *c, int x1, int y1_, int ax, int ay, int bx, int by, int x2, int y2, const char *color, int width, double alpha);
void tinyweb_erase(const char *c, int x, int y, int width, int height);
const char *tinyweb_line_style__default__cap(void);
const char *tinyweb_line_style__default__join(void);
double tinyweb_line_style__default__gap(void);
double tinyweb_line_style__default__offset(void);
double tinyweb_line_style__default__dash2(void);
double tinyweb_line_style__default__gap2(void);
void tinyweb_line_style(const char *c, const char *cap, const char *join, double dash, double gap, double offset, double dash2, double gap2);
void tinyweb_clip_rect(const char *c, int x, int y, int width, int height);
void tinyweb_clip_circle(const char *c, int x, int y, int radius);
const char *tinyweb_text__default__font(void);
const char *tinyweb_text__default__align(void);
bool tinyweb_text__default__bold(void);
double tinyweb_text__default__alpha(void);
const char *tinyweb_text__default__outline(void);
int tinyweb_text__default__outline_width(void);
void tinyweb_text(const char *c, int x, int y, const char *words, const char *color, int size, const char *font, const char *align, bool bold, double alpha, const char *baseline, const char *outline, int outline_width);
const char *tinyweb_measure_text__default__font(void);
void tinyweb_measure_text(const char *words, pyk_c_Ff_u_ answer, int size, const char *font, bool bold);
void tinyweb_push(const char *c);
void tinyweb_pop(const char *c);
const char *tinyweb_colors__linear_gradient(double x1, double y1_, double x2, double y2, const char *start, const char *end);
const char *tinyweb_colors__radial_gradient(double x1, double y1_, double r1, double x2, double y2, double r2, const char *start, const char *end);
const char *tinyweb_colors__conic_gradient(double x, double y, double angle, const char *start, const char *end);
const char *tinyweb_colors__stop(const char *gradient, double at, const char *color);
double tinyweb_smooth__circle__default__alpha(void);
void tinyweb_smooth__circle(const char *c, double x, double y, double radius, const char *color, const char *outline, double outline_width, double alpha);
double tinyweb_smooth__rect__default__outline_width(void);
double tinyweb_smooth__rect__default__alpha(void);
void tinyweb_smooth__rect(const char *c, double x, double y, double width, double height, const char *color, const char *outline, double outline_width, double alpha, double radius);
const char *tinyweb_smooth__ellipse__default__outline(void);
double tinyweb_smooth__ellipse__default__outline_width(void);
double tinyweb_smooth__ellipse__default__alpha(void);
void tinyweb_smooth__ellipse(const char *c, double x, double y, double rx, double ry, const char *color, const char *outline, double outline_width, double alpha);
double tinyweb_smooth__arc__default__alpha(void);
void tinyweb_smooth__arc(const char *c, double x, double y, double radius, double start, double end, const char *color, const char *outline, double outline_width, double alpha);
double tinyweb_smooth__line__default__alpha(void);
void tinyweb_smooth__line(const char *c, double x1, double y1_, double x2, double y2, const char *color, double width, double alpha);
double tinyweb_smooth__curve__default__alpha(void);
void tinyweb_smooth__curve(const char *c, double x1, double y1_, double cx, double cy, double x2, double y2, const char *color, double width, double alpha);
void tinyweb_smooth__bezier(const char *c, double x1, double y1_, double ax, double ay, double bx, double by, double x2, double y2, const char *color, double width, double alpha);
const char *tinyweb_smooth__text__default__font(void);
bool tinyweb_smooth__text__default__bold(void);
double tinyweb_smooth__text__default__alpha(void);
const char *tinyweb_smooth__text__default__outline(void);
double tinyweb_smooth__text__default__outline_width(void);
void tinyweb_smooth__text(const char *c, double x, double y, const char *words, const char *color, int size, const char *font, const char *align, bool bold, double alpha, const char *baseline, const char *outline, double outline_width);
void tinyweb_smooth__clip_circle(const char *c, double x, double y, double radius);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
