// Generated from math.pyk by the Pyking compiler. Do not edit.
// Target: node22. A module of the program, imported as 'math'.

import { pykTrunc } from './pyk-runtime.js';

import * as math_external from './math_external.js';
const pi = 3.141592653589793;
const tau = 6.283185307179586;
const e = 2.718281828459045;
const inf = Infinity;
const nan = 0.0 / 0.0;

function is_nan(x) {
  return x === x ? false : true;
}

function is_finite(x) {
  return x - x === 0.0;
}

function to_radians(deg) {
  return deg * pi / 180.0;
}

function to_degrees(rad) {
  return rad * 180.0 / pi;
}

function int__abs(x) {
  return x < 0 ? -x : x;
}

function float__abs(x) {
  return x <= 0.0 ? 0.0 - x : x;
}

function int__min(x, y) {
  return y < x ? y : x;
}

function float__min(x, y) {
  if (is_nan(x)) {
    return x;
  } else if (is_nan(y)) {
    return y;
  } else {
    return y < x ? y : x;
  }
}

function int__max(x, y) {
  return y > x ? y : x;
}

function float__max(x, y) {
  if (is_nan(x)) {
    return x;
  } else if (is_nan(y)) {
    return y;
  } else {
    return y > x ? y : x;
  }
}

function int__clamp(x, low, high) {
  return int__max(low, int__min(x, high));
}

function float__clamp(x, low, high) {
  return float__max(low, float__min(x, high));
}

function int__sign(x) {
  if (x < 0) {
    return -1;
  } else if (x > 0) {
    return 1;
  } else {
    return 0;
  }
}

function float__sign(x) {
  if (x < 0.0) {
    return -1.0;
  } else if (x > 0.0) {
    return 1.0;
  } else if (x === 0.0) {
    return 0.0;
  } else {
    return x;
  }
}

function int__mod(x, y) {
  const r = x - Math.trunc(x / y) * y;
  if (r < 0) {
    return y > 0 ? r + y : r;
  } else if (r > 0) {
    return y < 0 ? r + y : r;
  } else {
    return 0;
  }
}

function float__mod(x, y) {
  const r = x - y * math_external.host_floor(x / y);
  if (y > 0.0) {
    return r >= y ? 0.0 : r;
  } else {
    return r <= y ? 0.0 : r;
  }
}

function sin(angle) {
  return math_external.host_sin(angle);
}

function cos(angle) {
  return math_external.host_cos(angle);
}

function tan(angle) {
  return math_external.host_tan(angle);
}

function asin(x) {
  return math_external.host_asin(x);
}

function acos(x) {
  return math_external.host_acos(x);
}

function atan(x) {
  return math_external.host_atan(x);
}

function atan2(y, x) {
  return math_external.host_atan2(y, x);
}

function sinh(x) {
  return math_external.host_sinh(x);
}

function cosh(x) {
  return math_external.host_cosh(x);
}

function tanh(x) {
  return math_external.host_tanh(x);
}

function exp(x) {
  return math_external.host_exp(x);
}

function log(x) {
  return math_external.host_log(x);
}

function log2(x) {
  return math_external.host_log2(x);
}

function log10(x) {
  return math_external.host_log10(x);
}

function sqrt(x) {
  return math_external.host_sqrt(x);
}

function cbrt(x) {
  const root = math_external.host_cbrt(x);
  const nearest = math_external.host_floor(root + 0.5);
  return nearest * nearest * nearest === x ? nearest : root;
}

function pow(x, y) {
  return math_external.host_pow(x, y);
}

function hypot(x, y) {
  return math_external.host_hypot(x, y);
}

function distance(x1, y1, x2, y2) {
  return math_external.host_hypot(x2 - x1, y2 - y1);
}

function floor(x) {
  return pykTrunc(math_external.host_floor(x));
}

function ceil(x) {
  return pykTrunc(math_external.host_ceil(x));
}

function trunc(x) {
  return pykTrunc(math_external.host_trunc(x));
}

function round(x) {
  const whole = math_external.host_trunc(x);
  const part = x - whole;
  if (part >= 0.5) {
    return pykTrunc(whole + 1.0);
  } else if (part <= -0.5) {
    return pykTrunc(whole - 1.0);
  } else {
    return pykTrunc(whole);
  }
}

function euclid(x, y) {
  let [x2, y2] = [x, y];
  while (true) {
    if (y2 === 0) {
      return x2;
    } else {
      [x2, y2] = [y2, x2 - Math.trunc(x2 / y2) * y2];
    }
  }
  return [x2, y2];
}

function gcd(x, y) {
  return euclid(int__abs(x), int__abs(y));
}

function lcm(x, y) {
  if (x === 0) {
    return 0;
  } else if (y === 0) {
    return 0;
  } else {
    return int__abs(Math.trunc(x / gcd(x, y)) * y);
  }
}

function lerp(a, b, t) {
  return a + (b - a) * t;
}

function map_range(x, from_low, from_high, to_low, to_high) {
  return to_low + (x - from_low) * (to_high - to_low) / (from_high - from_low);
}

export { pi, tau, e, inf, nan, is_nan, is_finite, to_radians, to_degrees, int__abs, float__abs, int__min, float__min, int__max, float__max, int__clamp, float__clamp, int__sign, float__sign, int__mod, float__mod, sin, cos, tan, asin, acos, atan, atan2, sinh, cosh, tanh, exp, log, log2, log10, sqrt, cbrt, pow, hypot, distance, floor, ceil, trunc, round, gcd, lcm, lerp, map_range };
