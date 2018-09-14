#ifndef STRBUF_H
#define STRBUF_H

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct strbuf {
    char *data;
    int   len;
    int   cap;
};

struct strbuf *strbuf_new(void);

void strbuf_free(struct strbuf *buf);

int strbuf_append(struct strbuf *buf, const char *fmt, ...);

#endif /* STRBUF_H */
