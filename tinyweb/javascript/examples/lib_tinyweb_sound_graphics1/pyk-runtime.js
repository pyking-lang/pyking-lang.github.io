// The host half of a compiled Pyking program: what it needs from the
// world. Every module of the program imports this one.

function pykFormat(value, inner) {
  if (value === undefined) return '()';
  if (typeof value === 'string') return inner ? pykQuote(value) : value;
  // A Pyking list and a Pyking tuple are both JavaScript arrays and
  // print differently, so a list carries a marker (see `pykList` in the
  // compiled program). A property rather than a class, because for the
  // `esm` target the two live in different modules.
  if (Array.isArray(value) && value.pykList === true) {
    return '[' + value.map((element) => pykFormat(element, true)).join(', ') + ']';
  }
  if (Array.isArray(value)) {
    const parts = value.map((element) => pykFormat(element, true));
    return parts.length === 1 ? '(' + parts[0] + ',)' : '(' + parts.join(', ') + ')';
  }
  return String(value);
}

function pykQuote(text) {
  return "'" + text
    .replace(/\\/g, '\\\\')
    .replace(/'/g, "\\'")
    .replace(/\n/g, '\\n')
    .replace(/\t/g, '\\t')
    .replace(/\r/g, '\\r') + "'";
}

function pykFloatStr(x) {
  if (Number.isNaN(x)) return 'nan';
  if (x === Infinity) return 'inf';
  if (x === -Infinity) return '-inf';
  const sign = x < 0 || Object.is(x, -0) ? '-' : '';
  const a = Math.abs(x);
  if (a === 0) return sign + '0.0';
  let s = '';
  for (let p = 0; p <= 16; p++) {
    s = a.toExponential(p);
    if (Number(s) === a) break;
  }
  const at = s.indexOf('e');
  let digits = s.slice(0, at).replace('.', '').replace(/0+$/, '');
  if (digits === '') digits = '0';
  const decpt = Number(s.slice(at + 1)) + 1;
  const n = digits.length;
  if (decpt <= -4 || decpt > 16) {
    const mantissa = n === 1 ? digits : digits[0] + '.' + digits.slice(1);
    return sign + mantissa + 'e' + (decpt - 1);
  }
  if (decpt <= 0) return sign + '0.' + '0'.repeat(-decpt) + digits;
  if (decpt >= n) return sign + digits + '0'.repeat(decpt - n) + '.0';
  return sign + digits.slice(0, decpt) + '.' + digits.slice(decpt);
}

// The comma-separated parts of a tuple descriptor, split at the
// top level so a nested list or tuple stays whole.
function pykShapeParts(body) {
  const parts = [];
  let depth = 0;
  let start = 0;
  for (let i = 0; i < body.length; i++) {
    const c = body[i];
    if (c === '[' || c === '(') depth++;
    else if (c === ']' || c === ')') depth--;
    else if (c === ',' && depth === 0) {
      parts.push(body.slice(start, i));
      start = i + 1;
    }
  }
  if (body.length > 0) parts.push(body.slice(start));
  return parts;
}

// `f` is a Float, `.` anything pykFormat already prints right,
// `[s]` a list of s and `(s,s)` a tuple.
function pykShaped(value, shape, inner) {
  if (shape === 'f') return pykFloatStr(value);
  if (shape === '.') return pykFormat(value, inner);
  const body = shape.slice(1, -1);
  if (shape[0] === '[') {
    return '[' + value.map((e) => pykShaped(e, body, true)).join(', ') + ']';
  }
  const parts = pykShapeParts(body).map((s, i) => pykShaped(value[i], s, true));
  return parts.length === 1 ? '(' + parts[0] + ',)' : '(' + parts.join(', ') + ')';
}

function pykParseInt(text) {
  if (!/^[+-]?[0-9]+$/.test(text)) return 0;
  const n = Number(text);
  return n >= -2147483648 && n <= 2147483647 && n !== 0 ? n : 0;
}

function pykTrunc(x) {
  const t = Math.trunc(x);
  return t >= -2147483648 && t <= 2147483647 && t !== 0 ? t : 0;
}

function pykParseFloat(text) {
  if (text === 'inf' || text === '+inf') return Infinity;
  if (text === '-inf') return -Infinity;
  if (text === 'nan') return NaN;
  return /^[+-]?[0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?$/.test(text) ? Number(text) : NaN;
}

function print(...values) {
  console.log(values.map((value) => pykFormat(value)).join(' '));
}

function debug(...values) {
  console.error(values.map((value) => pykFormat(value)).join(' '));
}

export { print, debug, pykFormat, pykFloatStr, pykShaped, pykParseInt, pykTrunc,
  pykParseFloat };
