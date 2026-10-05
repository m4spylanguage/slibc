/*
 * 🕷️ slibc - Dynamic Linker & Runtime Internals
 * Implements private runtime functions expected by GCC and modern ELF loaders.
 */
#include "slibc.h"
#include <stddef.h>

/* Structure for _dl_find_object expected by GCC unwind */
struct dl_find_object {
    unsigned long long dlfo_flags;
    void *dlfo_map_start;
    void *dlfo_map_end;
    struct link_map *dlfo_link_map;
    void *dlfo_eh_frame;
};

/* Return -1 indicates the address could not be resolved in the private table */
SLIBC_EXPORT int _dl_find_object(void *address, struct dl_find_object *result) {
    (void)address;
    (void)result;
    return -1;
}

/* CPU model stubs for GCC multiversioning */
SLIBC_EXPORT int __cpu_indicator_init(void) {
    return 0;
}

struct __processor_model {
    unsigned int __cpu_vendor;
    unsigned int __cpu_type;
    unsigned int __cpu_subtype;
    unsigned int __cpu_features[1];
};

SLIBC_EXPORT struct __processor_model __cpu_model = {0, 0, 0, {0}};

/* glibc version query string */
SLIBC_EXPORT const char *gnu_get_libc_version(void) {
    return "2.38 (slibc " SLIBC_VERSION_STR ")";
}

SLIBC_EXPORT const char *gnu_get_libc_release(void) {
    return "stable";
}

/* Threading stack markers */
SLIBC_EXPORT void *__libc_stack_end = NULL;
SLIBC_EXPORT char __libc_single_threaded = 0;
