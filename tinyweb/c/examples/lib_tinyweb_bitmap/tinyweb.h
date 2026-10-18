// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// What the module 'tinyweb' exports.

#ifndef PYK_TINYWEB_H
#define PYK_TINYWEB_H

void tinyweb_web_init(int port);
void tinyweb_scale(const char *c, double sx, double sy);
int tinyweb_show_bitmap__default__x(void);
int tinyweb_show_bitmap__default__y(void);
double tinyweb_show_bitmap__default__scale(void);
void tinyweb_show_bitmap(const char *c, const char *b, int x, int y, double scale);
int tinyweb_pixel_color(int r, int g, int b);
int tinyweb_red(int color);
int tinyweb_green(int color);
int tinyweb_blue(int color);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
