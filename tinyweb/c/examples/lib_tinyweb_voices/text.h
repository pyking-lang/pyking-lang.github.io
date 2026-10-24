// Generated from text.pyk by the Pyking compiler. Do not edit.
// What the module 'text' exports.

#ifndef PYK_TEXT_H
#define PYK_TEXT_H

int text_length(const char *s);
const char *text_slice(const char *s, int start, int stop);
const char *text_char_at(const char *s, int k);
const char *text_upper(const char *s);

// Runs the module's own top level; the program calls it once, before any module that imports this one.
void text_init(void);

#endif  // PYK_TEXT_H
