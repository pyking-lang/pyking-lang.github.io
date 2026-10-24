// Generated from text.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include "text.h"

// What the external modules this one imports implement.
int text_host_length(const char *);
const char *text_host_slice(const char *, int, int);
int text_host_find(const char *, const char *, int);
int text_host_code(const char *, int);
const char *text_host_from_code(int);
const char *text_host_replace(const char *, const char *, const char *);
const char *text_host_upper(const char *);
const char *text_host_lower(const char *);

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static int within(int k, int top);
int text_length(const char *s);
const char *text_slice(const char *s, int start, int stop);
const char *text_char_at(const char *s, int k);
const char *text_upper(const char *s);

static int within(int k, int top)
{
    if (k < 0) {
        return 0;
    } else if (k > top) {
        return top;
    } else {
        return k;
    }
}

int text_length(const char *s)
{
    return text_host_length(s);
}

const char *text_slice(const char *s, int start, int stop)
{
    int n = text_host_length(s);
    int a = within(start, n);
    int b = within(stop, n);
    return b <= a ? "" : text_host_slice(s, a, b);
}

const char *text_char_at(const char *s, int k)
{
    if (k < 0) {
        return "";
    } else if (k < text_host_length(s)) {
        return text_host_slice(s, k, k + 1);
    } else {
        return "";
    }
}

const char *text_upper(const char *s)
{
    return text_host_upper(s);
}

void text_init(void)
{

}
