// The host half of a compiled Pyking program: what it needs from the
// world. Every module of the program imports this one.

function pykFormat(value, inner, path = []) {
  if (value === undefined) return '()';
  if (typeof value === 'string') return inner ? pykQuote(value) : value;
  if (value === null || typeof value !== 'object') return String(value);
  // A print argument whose descriptor waited for the others (`pykLater`).
  if (value.pykLater !== undefined) return pykShaped(value.value, value.pykLater, inner, path);
  // `path` holds the values printing is inside of. Only an array or a
  // `var struct` can contain itself, and where one does, the repetition
  // prints as `...`; a value that is only shared is not on the path the
  // second time, and prints in full.
  // A view stands on the path for the array it is a view of, and a
  // pointer for the store its place is in.
  const holder =
    value.pykView === true ? value.owner : value.pykPtr === true ? value.store : value;
  if (path.includes(holder)) return '...';
  path.push(holder);
  const text = pykFormatHolder(value, path);
  path.pop();
  return text;
}

// A value holding others, on the path while its parts print.
function pykFormatHolder(value, path) {
  // A Pyking list and a Pyking tuple are both JavaScript arrays and
  // print differently, so a list carries a marker (see `pykList` in the
  // compiled program). A property rather than a class, because for the
  // `esm` target the two live in different modules.
  if (Array.isArray(value) && value.pykList === true) {
    return '[' + value.map((element) => pykFormat(element, true, path)).join(', ') + ']';
  }
  // A Pyking array carries a marker of its own (`pykArray`), and
  // prints as what makes one.
  if (Array.isArray(value) && value.pykArray === true) {
    return 'array([' + value.map((element) => pykFormat(element, true, path)).join(', ') + '])';
  }
  // A MutMap is a Map of [key, value] entries (`pykMutMap` in the compiled
  // program), each printed as the tuple it is; a Pyking Map is one
  // marked `pykMap` too.
  if (value.pykMutMap === true) {
    return (value.pykMap === true ? 'map([' : 'mutmap([') + Array.from(value.values(), (entry) => pykFormat(entry, true, path)).join(', ') + '])';
  }
  // A pointer prints as what it points at now.
  if (value.pykPtr === true) return 'Ptr(' + pykFormat(value.get(), true, path) + ')';
  // A view (`pykView` in the compiled program): its array's elements
  // from its offset, as they are now.
  if (value.pykView === true) {
    const items = value.owner.slice(value.offset, value.offset + value.length);
    return 'view([' + items.map((element) => pykFormat(element, true, path)).join(', ') + '])';
  }
  // A DynArray has its own marker (`pykDynArray`) too.
  if (Array.isArray(value) && value.pykDynArray === true) {
    return 'dynarray([' + value.map((element) => pykFormat(element, true, path)).join(', ') + '])';
  }
  if (Array.isArray(value)) {
    const parts = value.map((element) => pykFormat(element, true, path));
    return parts.length === 1 ? '(' + parts[0] + ',)' : '(' + parts.join(', ') + ')';
  }
  // An object whose class has `show` prints what it says.
  if (value.pykShow === true) return value.show();
  // A datatype's value, or a `var struct`'s: its constructor and its
  // fields by position, each Float one written as a Float where the
  // compiler said so.
  if (value.pykTag !== undefined) {
    const values = value.pykValues;
    if (values.length === 0) return value.pykTag;
    const shapes = value.pykShape === null ? null : pykShapeParts(value.pykShape.slice(1, -1));
    const parts = values.map((element, i) =>
      shapes === null ? pykFormat(element, true, path) : pykShaped(element, shapes[i], true, path));
    return value.pykTag + '(' + parts.join(', ') + ')';
  }
  return String(value);
}

// A String inside a list, tuple or datatype: in double quotes, with
// builtin.ml's escapes (quote_string).
function pykQuote(text) {
  return '"' + text.replace(/[\\"\n\t\r\0]/g, pykEscape) + '"';
}

// A Char inside one: in single quotes (quote_char).
function pykQuoteChar(code) {
  return "'" + String.fromCodePoint(code).replace(/[\\'\n\t\r\0]/g, pykEscape) + "'";
}

function pykEscape(c) {
  switch (c) {
    case '\n': return '\\n';
    case '\t': return '\\t';
    case '\r': return '\\r';
    case '\0': return '\\0';
    default: return '\\' + c;
  }
}

function pykFloatStr(x) {
  if (Number.isNaN(x)) return 'nan';
  if (x === Infinity) return 'inf';
  if (x === -Infinity) return '-inf';
  const sign = x < 0 || Object.is(x, -0) ? '-' : '';
  const a = Math.abs(x);
  if (a === 0) return sign + '0.0';
  if (a >= 1e-4 && a < 1e16) {
    const fixed = String(a);
    return sign + (fixed.indexOf('.') < 0 ? fixed + '.0' : fixed);
  }
  const s = String(a);
  const at = s.indexOf('e');
  const mant = at < 0 ? s : s.slice(0, at);
  const exp = at < 0 ? 0 : Number(s.slice(at + 1));
  const dot = mant.indexOf('.');
  const whole = dot < 0 ? mant : mant.slice(0, dot);
  const frac = dot < 0 ? '' : mant.slice(dot + 1);
  let digits = (whole + frac).replace(/^0+/, '');
  const decpt = whole === '0' ? exp - (frac.length - digits.length) : whole.length + exp;
  digits = digits.replace(/0+$/, '');
  if (digits === '') digits = '0';
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
    if (c === '[' || c === '(' || c === '{' || c === '<') depth++;
    else if (c === ']' || c === ')' || c === '}' || c === '>') depth--;
    else if (c === ',' && depth === 0) {
      parts.push(body.slice(start, i));
      start = i + 1;
    }
  }
  if (body.length > 0) parts.push(body.slice(start));
  return parts;
}

// `f` is a Float, `c` a Char (a code point), `.` anything pykFormat
// already prints right, `[s]` a list of s, `{s}` an array of s, `<s>`
// a DynArray of s, `v{s}` a view of s, `p(s)` a pointer to s, `@(k,v)` a
// MutMap or Map whose entries are (k, v), `(s,s)` a tuple, and `d(s,s)` a
// datatype's value whose type arguments are s, s -- its fields read
// through its constructor's template (`pykFields`), where `$i` is the
// i-th argument. `path` is pykFormat's: a value can only reach itself
// through a datatype's value, which guards it as pykFormat does.
function pykShaped(value, shape, inner, path = []) {
  if (shape === 'f') return pykFloatStr(value);
  if (shape === 'c') return inner ? pykQuoteChar(value) : String.fromCodePoint(value);
  if (shape === '.') return pykFormat(value, inner, path);
  if (shape[0] === 'p') return 'Ptr(' + pykShaped(value.get(), shape.slice(2, -1), true, path) + ')';
  if (shape[0] === 'v') {
    const items = value.owner.slice(value.offset, value.offset + value.length);
    return 'view([' + items.map((e) => pykShaped(e, shape.slice(2, -1), true, path)).join(', ') + '])';
  }
  if (shape[0] === 'd') {
    const fields = value !== null && typeof value === 'object' ? value.pykFields : undefined;
    if (fields === undefined || fields === null) return pykFormat(value, inner, path);
    const values = value.pykValues;
    if (values.length === 0) return value.pykTag;
    if (path.includes(value)) return '...';
    const args = pykShapeParts(shape.slice(2, -1));
    const shapes = pykShapeParts(fields.slice(1, -1))
      .map((s) => s.replace(/\$(\d+)/g, (_, i) => args[Number(i)] ?? '.'));
    path.push(value);
    const parts = values.map((e, i) => pykShaped(e, shapes[i], true, path));
    path.pop();
    return value.pykTag + '(' + parts.join(', ') + ')';
  }
  if (shape[0] === '@') {
    const entry = shape.slice(1);
    return (value.pykMap === true ? 'map([' : 'mutmap([') + Array.from(value.values(), (e) => pykShaped(e, entry, true, path)).join(', ') + '])';
  }
  const body = shape.slice(1, -1);
  if (shape[0] === '[') {
    return '[' + value.map((e) => pykShaped(e, body, true, path)).join(', ') + ']';
  }
  if (shape[0] === '{') {
    return 'array([' + value.map((e) => pykShaped(e, body, true, path)).join(', ') + '])';
  }
  if (shape[0] === '<') {
    return 'dynarray([' + value.map((e) => pykShaped(e, body, true, path)).join(', ') + '])';
  }
  const parts = pykShapeParts(body).map((s, i) => pykShaped(value[i], s, true, path));
  return parts.length === 1 ? '(' + parts[0] + ',)' : '(' + parts.join(', ') + ')';
}

// A `print` argument holding an array, a DynArray, a view or a MutMap whose
// parts need a descriptor: formatted by `print` itself, once every
// argument after it is worked out -- a later one may write into it.
function pykLater(value, shape) {
  return { pykLater: shape, value };
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

export { print, debug, pykFormat, pykFloatStr, pykShaped, pykLater, pykParseInt,
  pykTrunc, pykParseFloat };
