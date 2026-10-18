// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// What the module 'tinyweb' exports.

#ifndef PYK_TINYWEB_H
#define PYK_TINYWEB_H

void tinyweb_clear(const char *c, const char *color);
void tinyweb_web_init(int port);
const char *tinyweb_circle__default__outline(void);
int tinyweb_circle__default__outline_width(void);
double tinyweb_circle__default__alpha(void);
void tinyweb_circle(const char *c, int x, int y, int radius, const char *color, const char *outline, int outline_width, double alpha);
int tinyweb_rect__default__outline_width(void);
double tinyweb_rect__default__alpha(void);
void tinyweb_rect(const char *c, int x, int y, int width, int height, const char *color, const char *outline, int outline_width, double alpha, int radius);
const char *tinyweb_ellipse__default__outline(void);
int tinyweb_ellipse__default__outline_width(void);
void tinyweb_ellipse(const char *c, int x, int y, int rx, int ry, const char *color, const char *outline, int outline_width, double alpha);
const char *tinyweb_arc__default__outline(void);
int tinyweb_arc__default__outline_width(void);
double tinyweb_arc__default__alpha(void);
void tinyweb_arc(const char *c, int x, int y, int radius, double start, double end, const char *color, const char *outline, int outline_width, double alpha);
double tinyweb_line__default__alpha(void);
void tinyweb_line(const char *c, int x1, int y1_, int x2, int y2, const char *color, int width, double alpha);
void tinyweb_curve(const char *c, int x1, int y1_, int cx, int cy, int x2, int y2, const char *color, int width, double alpha);
double tinyweb_text__default__alpha(void);
const char *tinyweb_text__default__baseline(void);
const char *tinyweb_text__default__outline(void);
int tinyweb_text__default__outline_width(void);
void tinyweb_text(const char *c, int x, int y, const char *words, const char *color, int size, const char *font, const char *align, bool bold, double alpha, const char *baseline, const char *outline, int outline_width);
const char *tinyweb_colors__rgb(int r, int g, int b);
const char *tinyweb_colors__rgba(int r, int g, int b, double a);
const char *tinyweb_colors__hsl(int h, int s, int l);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
