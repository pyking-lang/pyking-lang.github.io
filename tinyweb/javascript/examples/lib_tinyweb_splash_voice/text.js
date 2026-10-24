// Generated from text.pyk by the Pyking compiler. Do not edit.
// Target: node22. A module of the program, imported as 'text'.

// A Pyking list is a JavaScript array with a marker on it: a tuple
// is an array too, and the two print differently. A property rather
// than a class, so that a formatter in another module can read it.
function pykList(items) {
  items.pykList = true;
  return items;
}

// Pyking's `++` joins two strings or two lists. A list is an array
// here and JavaScript's `+` would stringify one, so which is meant
// is decided by looking -- this backend infers no types.
function pykConcat(a, b) {
  return Array.isArray(a) ? pykList([...a, ...b]) : a + b;
}

import * as text_external from './text_external.js';

function within(k, top) {
  if (k < 0) {
    return 0;
  } else if (k > top) {
    return top;
  } else {
    return k;
  }
}

function blank(c) {
  const __subject = c;
  if (__subject === 32 || __subject === 9 || __subject === 10 || __subject === 13) {
    return true;
  } else {
    return false;
  }
}

function filled(s) {
  return s === '' ? false : true;
}

function length(s) {
  return text_external.host_length(s);
}

function slice(s, start, stop) {
  const n = text_external.host_length(s);
  const a = within(start, n);
  const b = within(stop, n);
  return b <= a ? '' : text_external.host_slice(s, a, b);
}

function char_at(s, k) {
  if (k < 0) {
    return '';
  } else if (k < text_external.host_length(s)) {
    return text_external.host_slice(s, k, k + 1);
  } else {
    return '';
  }
}

function code(s, k) {
  if (k < 0) {
    return -1;
  } else if (k < text_external.host_length(s)) {
    return text_external.host_code(s, k);
  } else {
    return -1;
  }
}

function from_code(n) {
  if (n <= 0) {
    return '';
  } else if (n > 1114111) {
    return '';
  } else if (n < 55296) {
    return text_external.host_from_code(n);
  } else if (n <= 57343) {
    return '';
  } else {
    return text_external.host_from_code(n);
  }
}

function find(s, part, start) {
  const n = text_external.host_length(s);
  if (start > n) {
    return -1;
  } else if (part === '') {
    return within(start, n);
  } else {
    return text_external.host_find(s, part, within(start, n));
  }
}

function contains(s, part) {
  return find(s, part, 0) >= 0;
}

function starts_with(s, prefix) {
  return slice(s, 0, text_external.host_length(prefix)) === prefix;
}

function ends_with(s, suffix) {
  const n = text_external.host_length(s);
  const m = text_external.host_length(suffix);
  return m > n ? false : text_external.host_slice(s, n - m, n) === suffix;
}

function upper(s) {
  return text_external.host_upper(s);
}

function lower(s) {
  return text_external.host_lower(s);
}

function trim(s) {
  const n = text_external.host_length(s);
  let i = 0;
  while (i < n) {
    if (blank(text_external.host_code(s, i))) {
      i = i + 1;
    } else {
      break;
    }
  }
  const first = i;
  let j = n;
  while (j > first) {
    if (blank(text_external.host_code(s, j - 1))) {
      j = j - 1;
    } else {
      break;
    }
  }
  const last = j;
  return last <= first ? '' : text_external.host_slice(s, first, last);
}

function replace(s, old, new2) {
  return old === '' ? s : text_external.host_replace(s, old, new2);
}

function repeat(s, n) {
  let [k, piece, out] = [n, s, ''];
  while (true) {
    if (k <= 0) {
      break;
    } else {
      const half = Math.trunc(k / 2);
      const more = k - half * 2 === 1 ? pykConcat(out, piece) : out;
      [k, piece, out] = [half, half === 0 ? piece : pykConcat(piece, piece), more];
    }
  }
  const [_, _2, out2] = [k, piece, out];
  return out2;
}

function split(s, by) {
  if (by === '') {
    return pykList([s]);
  } else {
    const m = text_external.host_length(by);
    let [at, parts] = [0, pykList([])];
    while (true) {
      const k = text_external.host_find(s, by, at);
      if (k < 0) {
        break;
      } else {
        [at, parts] = [k + m, pykConcat(parts, pykList([text_external.host_slice(s, at, k)]))];
      }
    }
    const [at2, parts2] = [at, parts];
    return pykConcat(parts2, pykList([text_external.host_slice(s, at2, text_external.host_length(s))]));
  }
}

function words(s) {
  const spaced = text_external.host_replace(text_external.host_replace(text_external.host_replace(s, '\t', ' '), '\n', ' '), '\r', ' ');
  return pykList(split(spaced, ' ').flatMap((__item) => {
  const w = __item;
  return filled(w) ? [w] : [];
}));
}

function join(parts, between) {
  let whole = '';
  let chunk = '';
  let count = 0;
  let chunks = 0;
  for (const part of parts) {
    chunk = count === 0 ? part : pykConcat(pykConcat(chunk, between), part);
    count = count + 1;
    if (count === 128) {
      whole = chunks === 0 ? chunk : pykConcat(pykConcat(whole, between), chunk);
      chunks = chunks + 1;
      chunk = '';
      count = 0;
    }
  }
  return count === 0 ? whole : chunks === 0 ? chunk : pykConcat(pykConcat(whole, between), chunk);
}

function lines(s) {
  if (s === '') {
    return pykList([]);
  } else {
    const unix = text_external.host_replace(s, '\r\n', '\n');
    const ended = ends_with(unix, '\n') ? text_external.host_slice(unix, 0, text_external.host_length(unix) - 1) : unix;
    return split(ended, '\n');
  }
}

export { length, slice, char_at, code, from_code, find, contains, starts_with, ends_with, upper, lower, trim, replace, repeat, split, words, join, lines };
