/*
 * 🕷️ slibc - GNU Miscellaneous & Device Macros
 * Clean-room BSD implementations of GNU-specific extensions.
 */
#include "slibc.h"
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <string.h>
#include <pthread.h>

SLIBC_EXPORT unsigned int gnu_dev_major(dev_t dev) {
    return major(dev);
}

SLIBC_EXPORT unsigned int gnu_dev_minor(dev_t dev) {
    return minor(dev);
}

SLIBC_EXPORT dev_t gnu_dev_makedev(unsigned int maj, unsigned int min) {
    return makedev(maj, min);
}

/* __rawmemchr: scans memory without length bound until byte c is found */
SLIBC_EXPORT void *__rawmemchr(const void *s, int c) {
    const unsigned char *p = (const unsigned char *)s;
    unsigned char uc = (unsigned char)c;
    while (*p != uc) {
        p++;
    }
    return (void *)p;
}

/* pthread atfork hook */
SLIBC_EXPORT int __register_atfork(void (*prepare)(void), void (*parent)(void),
                                   void (*child)(void), void *dso_handle) {
    (void)dso_handle;
    return pthread_atfork(prepare, parent, child);
}
