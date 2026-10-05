/*
 * 🕷️ slibc - C23 ABI Compatibility Mappings
 * Maps glibc 2.38+ __isoc23_* functions to standard BSD/C implementations.
 */
#include "slibc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

SLIBC_EXPORT long __isoc23_strtol(const char *nptr, char **endptr, int base) {
    return strtol(nptr, endptr, base);
}

SLIBC_EXPORT unsigned long __isoc23_strtoul(const char *nptr, char **endptr, int base) {
    return strtoul(nptr, endptr, base);
}

SLIBC_EXPORT long long __isoc23_strtoll(const char *nptr, char **endptr, int base) {
    return strtoll(nptr, endptr, base);
}

SLIBC_EXPORT unsigned long long __isoc23_strtoull(const char *nptr, char **endptr, int base) {
    return strtoull(nptr, endptr, base);
}

SLIBC_EXPORT float __isoc23_strtof(const char *nptr, char **endptr) {
    return strtof(nptr, endptr);
}

SLIBC_EXPORT double __isoc23_strtod(const char *nptr, char **endptr) {
    return strtod(nptr, endptr);
}

SLIBC_EXPORT long double __isoc23_strtold(const char *nptr, char **endptr) {
    return strtold(nptr, endptr);
}

SLIBC_EXPORT int __isoc23_vsscanf(const char *s, const char *format, va_list ap) {
    return vsscanf(s, format, ap);
}

SLIBC_EXPORT int __isoc23_sscanf(const char *s, const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    int ret = vsscanf(s, format, ap);
    va_end(ap);
    return ret;
}

SLIBC_EXPORT int __isoc23_vfscanf(FILE *stream, const char *format, va_list ap) {
    return vfscanf(stream, format, ap);
}

SLIBC_EXPORT int __isoc23_fscanf(FILE *stream, const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    int ret = vfscanf(stream, format, ap);
    va_end(ap);
    return ret;
}

SLIBC_EXPORT int __isoc23_vscanf(const char *format, va_list ap) {
    return vscanf(format, ap);
}

SLIBC_EXPORT int __isoc23_scanf(const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    int ret = vscanf(format, ap);
    va_end(ap);
    return ret;
}
