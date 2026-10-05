/*
 * 🕷️ slibc - Fortified Security Check Mappings
 * Maps glibc __*_chk functions to standard BSD implementations.
 */
#include "slibc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

SLIBC_EXPORT void __chk_fail(void) {
    abort();
}

SLIBC_EXPORT int __vprintf_chk(int flag, const char *format, va_list ap) {
    (void)flag;
    return vprintf(format, ap);
}

SLIBC_EXPORT int __printf_chk(int flag, const char *format, ...) {
    (void)flag;
    va_list ap;
    va_start(ap, format);
    int ret = vprintf(format, ap);
    va_end(ap);
    return ret;
}

SLIBC_EXPORT int __vfprintf_chk(FILE *stream, int flag, const char *format, va_list ap) {
    (void)flag;
    return vfprintf(stream, format, ap);
}

SLIBC_EXPORT int __fprintf_chk(FILE *stream, int flag, const char *format, ...) {
    (void)flag;
    va_list ap;
    va_start(ap, format);
    int ret = vfprintf(stream, format, ap);
    va_end(ap);
    return ret;
}

SLIBC_EXPORT int __vsprintf_chk(char *s, int flag, size_t slen, const char *format, va_list ap) {
    (void)flag;
    (void)slen;
    return vsprintf(s, format, ap);
}

SLIBC_EXPORT int __sprintf_chk(char *s, int flag, size_t slen, const char *format, ...) {
    (void)flag;
    (void)slen;
    va_list ap;
    va_start(ap, format);
    int ret = vsprintf(s, format, ap);
    va_end(ap);
    return ret;
}

SLIBC_EXPORT int __vsnprintf_chk(char *s, size_t maxlen, int flag, size_t slen, const char *format, va_list ap) {
    (void)flag;
    (void)slen;
    return vsnprintf(s, maxlen, format, ap);
}

SLIBC_EXPORT int __snprintf_chk(char *s, size_t maxlen, int flag, size_t slen, const char *format, ...) {
    (void)flag;
    (void)slen;
    va_list ap;
    va_start(ap, format);
    int ret = vsnprintf(s, maxlen, format, ap);
    va_end(ap);
    return ret;
}

SLIBC_EXPORT int __vdprintf_chk(int fd, int flag, const char *format, va_list ap) {
    (void)flag;
    return vdprintf(fd, format, ap);
}

SLIBC_EXPORT int __dprintf_chk(int fd, int flag, const char *format, ...) {
    (void)flag;
    va_list ap;
    va_start(ap, format);
    int ret = vdprintf(fd, format, ap);
    va_end(ap);
    return ret;
}
