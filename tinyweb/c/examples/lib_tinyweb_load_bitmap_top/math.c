// Generated from math.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <math.h>

// Every multiply and add rounded on its own, as on every other target.
#if defined(__clang__)
#pragma STDC FP_CONTRACT OFF
#elif defined(__GNUC__)
#pragma GCC optimize ("fp-contract=off")
#endif

#include "math.h"

// What the external modules this one imports implement.
double math_host_sin(double);
double math_host_cos(double);
double math_host_tan(double);
double math_host_asin(double);
double math_host_acos(double);
double math_host_atan(double);
double math_host_atan2(double, double);
double math_host_sinh(double);
double math_host_cosh(double);
double math_host_tanh(double);
double math_host_exp(double);
double math_host_log(double);
double math_host_log2(double);
double math_host_log10(double);
double math_host_sqrt(double);
double math_host_cbrt(double);
double math_host_pow(double, double);
double math_host_hypot(double, double);
double math_host_floor(double);
double math_host_ceil(double);
double math_host_trunc(double);

double math_pi;
double math_tau;
double math_e;
double math_inf;
double math_nan;

void math_init(void)
{
    math_pi = 3.141592653589793;
    math_tau = 6.283185307179586;
    math_e = 2.718281828459045;
    math_inf = HUGE_VAL;
    math_nan = 0.0 / 0.0;
}
