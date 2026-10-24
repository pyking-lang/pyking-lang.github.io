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

#ifndef PYK_TYPE_PYK_C_F_U_
#define PYK_TYPE_PYK_C_F_U_
typedef struct pyk_c_F_u_ {
    void (*fn)(void *);
    void *env;
    void (*plain)(void);
} pyk_c_F_u_;
#endif

#ifndef PYK_TYPE_PYK_C_FB_U_
#define PYK_TYPE_PYK_C_FB_U_
typedef struct pyk_c_Fb_u_ {
    void (*fn)(void *, bool);
    void *env;
    void (*plain)(bool);
} pyk_c_Fb_u_;
#endif

#ifndef PYK_TYPE_PYK_C_FII_U_
#define PYK_TYPE_PYK_C_FII_U_
typedef struct pyk_c_Fii_u_ {
    void (*fn)(void *, int, int);
    void *env;
    void (*plain)(int, int);
} pyk_c_Fii_u_;
#endif

#ifndef PYK_TYPE_PYK_D_DTINYWEB_SOUND__VOICE__
#define PYK_TYPE_PYK_D_DTINYWEB_SOUND__VOICE__
typedef struct pyk_d_Dtinyweb_Sound__Voice__ {
    double volume;
    double rate;
    double pan;
    int channel;
    bool looping;
    bool reverse;
} pyk_d_Dtinyweb_Sound__Voice__;
#endif

#ifndef PYK_TYPE_PYK_C_FIF_U_
#define PYK_TYPE_PYK_C_FIF_U_
typedef struct pyk_c_Fif_u_ {
    void (*fn)(void *, int, double);
    void *env;
    void (*plain)(int, double);
} pyk_c_Fif_u_;
#endif

#ifndef PYK_TYPE_PYK_C_FFF_U_
#define PYK_TYPE_PYK_C_FFF_U_
typedef struct pyk_c_Fff_u_ {
    void (*fn)(void *, double, double);
    void *env;
    void (*plain)(double, double);
} pyk_c_Fff_u_;
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

void tinyweb_web_init(int port);
const char *tinyweb_button(const char *title, pyk_c_F_u_ on_click);
const char *tinyweb_checkbox(const char *title, bool checked, pyk_c_Fb_u_ on_change);
void tinyweb_on_click(const char *c, pyk_c_Fii_u_ f);
pyk_d_Dtinyweb_Sound__Voice__ tinyweb_play__default__voice(void);
void tinyweb_play(const char *sample, double at, double volume, double rate, double pan, pyk_d_Dtinyweb_Sound__Voice__ voice);
void tinyweb_sound__tone(double frequency, double at, double duration, const char *wave, double volume, double pan, int channel);
void tinyweb_sound__tempo(double bpm);
void tinyweb_sound__swing(double amount);
const char *tinyweb_sound__on_beat(pyk_c_Fif_u_ f, int steps);
double tinyweb_sound__beat(void);
double tinyweb_sound__latency(void);
void tinyweb_sound__pause(void);
void tinyweb_sound__resume(void);
void tinyweb_sound__listen(int bins, double smoothing);
double tinyweb_sound__level(void);
double tinyweb_sound__band(int k);
int tinyweb_sound__bands(void);
double tinyweb_sound__wave(int k);
pyk_c_Fff_u_ tinyweb_sound__render_wav__default__on_rendered(void);
void tinyweb_sound__render_wav(double seconds, pyk_c_F_u_ f, const char *name, pyk_c_Fff_u_ on_rendered);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void tinyweb_init(void);

#endif  // PYK_TINYWEB_H
