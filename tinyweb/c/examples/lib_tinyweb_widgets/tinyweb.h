// Generated from tinyweb.pyk by the Pyking compiler. Do not edit.
// What the module 'tinyweb' exports.

#ifndef PYK_TINYWEB_H
#define PYK_TINYWEB_H

#ifndef PYK_TYPE_PYK_C_FI_U_
#define PYK_TYPE_PYK_C_FI_U_
typedef struct pyk_c_Fi_u_ {
    void (*fn)(void *, int);
    void *env;
    void (*plain)(int);
} pyk_c_Fi_u_;
#endif

#ifndef PYK_TYPE_PYK_C_FB_U_
#define PYK_TYPE_PYK_C_FB_U_
typedef struct pyk_c_Fb_u_ {
    void (*fn)(void *, bool);
    void *env;
    void (*plain)(bool);
} pyk_c_Fb_u_;
#endif

#ifndef PYK_TYPE_PYK_C_FS_U_
#define PYK_TYPE_PYK_C_FS_U_
typedef struct pyk_c_Fs_u_ {
    void (*fn)(void *, const char *);
    void *env;
    void (*plain)(const char *);
} pyk_c_Fs_u_;
#endif

void tinyweb_web_init(int port);
pyk_c_Fi_u_ tinyweb_slider__default__on_change(void);
const char *tinyweb_slider(int low, int high, int value, pyk_c_Fi_u_ on_change);
bool tinyweb_checkbox__default__checked(void);
pyk_c_Fb_u_ tinyweb_checkbox__default__on_change(void);
const char *tinyweb_checkbox(const char *title, bool checked, pyk_c_Fb_u_ on_change);
bool tinyweb_radio__default__chosen(void);
pyk_c_Fs_u_ tinyweb_radio__default__on_pick(void);
const char *tinyweb_radio(const char *group, const char *title, bool chosen, pyk_c_Fs_u_ on_pick);
const char *tinyweb_text_input__default__placeholder(void);
pyk_c_Fs_u_ tinyweb_text_input__default__on_enter(void);
const char *tinyweb_text_input(const char *placeholder, pyk_c_Fs_u_ on_enter);
const char *tinyweb_number_input(int low, int high, int value, pyk_c_Fi_u_ on_change);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
