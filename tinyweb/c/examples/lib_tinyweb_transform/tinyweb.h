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
const char *tinyweb_rect__default__outline(void);
int tinyweb_rect__default__outline_width(void);
double tinyweb_rect__default__alpha(void);
int tinyweb_rect__default__radius(void);
void tinyweb_rect(const char *c, int x, int y, int width, int height, const char *color, const char *outline, int outline_width, double alpha, int radius);
void tinyweb_translate(const char *c, double x, double y);
void tinyweb_rotate(const char *c, double degrees);
void tinyweb_scale(const char *c, double sx, double sy);
void tinyweb_push(const char *c);
void tinyweb_pop(const char *c);
void tinyweb_reset(const char *c);
int tinyweb_shadow__default__blur(void);
int tinyweb_shadow__default__dx(void);
int tinyweb_shadow__default__dy(void);
void tinyweb_shadow(const char *c, const char *color, int blur, int dx, int dy);
void tinyweb_blend(const char *c, const char *mode);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
