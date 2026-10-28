// Generated from text.pyk by the Pyking compiler. Do not edit.
// Target: c23. One translation unit of the program; compile it with the others.

#include <stdio.h>
#include <stdlib.h>

#include "text.h"

// What the external modules this one imports implement.
int text_host_length(const char *);
const char *text_host_slice(const char *, int, int);
int text_host_find(const char *, const char *, int);
int text_host_code(const char *, int);
const char *text_host_replace(const char *, const char *, const char *);
const char *text_host_upper(const char *);
const char *text_host_lower(const char *);

static const char *pyk_utf8_step(const char *p, int *c)
{
    const unsigned char *s = (const unsigned char *)p;
    int n, k, v;
    if (*s == 0) {
        return NULL;
    }
    if (*s < 0x80) {
        *c = *s;
        return p + 1;
    }
    if (*s >= 0xF8 || *s < 0xC0) {
        *c = 0xFFFD;
        return p + 1;
    }
    n = *s >= 0xF0 ? 3 : *s >= 0xE0 ? 2 : 1;
    v = *s & (0x3F >> n);
    for (k = 1; k <= n; k++) {
        if ((s[k] & 0xC0) != 0x80) {
            *c = 0xFFFD;
            return p + 1;
        }
        v = (v << 6) | (s[k] & 0x3F);
    }
    *c = v;
    return p + 1 + n;
}

static int pyk_utf8_length(const char *s)
{
    int c, n = 0;
    while ((s = pyk_utf8_step(s, &c)) != NULL) {
        n++;
    }
    return n;
}

static int pyk_char_at(const char *s, int i)
{
    const char *p = s;
    int c = 0, k = 0, n;
    if (i >= 0) {
        while ((p = pyk_utf8_step(p, &c)) != NULL) {
            if (k == i) {
                return c;
            }
            k++;
        }
    }
    n = pyk_utf8_length(s);
    fprintf(stderr, "error: the index %d is outside a String of %d character%s\n", i, n, n == 1 ? "" : "s");
    exit(1);
    return 0;
}

// Declared ahead of their definitions: a Pyking function may be called before it is written.
static int within(int k, int top);
int text_length(const char *s);
const char *text_slice(const char *s, int start, int stop);
int text_char_at(const char *s, int k);

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

int text_char_at(const char *s, int k)
{
    if (k < 0) {
        return 0;
    } else if (k < pyk_utf8_length(s)) {
        return pyk_char_at(s, k);
    } else {
        return 0;
    }
}

void text_init(void)
{

}
