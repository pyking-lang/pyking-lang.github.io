// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// What the module 'tinyweb' exports.

#ifndef PYK_TINYWEB_H
#define PYK_TINYWEB_H

#ifndef PYK_TYPE_PYK_C_F_U_
#define PYK_TYPE_PYK_C_F_U_
typedef struct pyk_c_F_u_ {
    void (*fn)(void *);
    void *env;
    void (*plain)(void);
} pyk_c_F_u_;
#endif

void tinyweb_web_init(int port);
const char *tinyweb_button(const char *title, pyk_c_F_u_ on_click);
double tinyweb_play__default__at(void);
double tinyweb_play__default__rate(void);
void tinyweb_play(const char *sample, double at, double volume, double rate);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
