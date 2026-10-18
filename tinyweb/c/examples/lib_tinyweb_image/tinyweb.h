// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// What the module 'tinyweb' exports.

#ifndef PYK_TINYWEB_H
#define PYK_TINYWEB_H

void tinyweb_clear(const char *c, const char *color);
void tinyweb_web_init(int port);
double tinyweb_image__default__alpha(void);
void tinyweb_image(const char *c, const char *picture, int x, int y, int width, int height, double alpha);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
