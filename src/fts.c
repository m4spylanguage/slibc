/*
 * 🕷️ slibc - File Hierarchy Traversal (fts64) Compatibility
 * Maps 64-bit glibc fts64_* functions to standard BSD/POSIX fts implementations.
 */
#include "slibc.h"
#include <fts.h>

SLIBC_EXPORT FTS *fts64_open(char * const *path_argv, int options,
                             int (*compar)(const FTSENT **, const FTSENT **)) {
    return fts_open(path_argv, options, compar);
}

SLIBC_EXPORT FTSENT *fts64_read(FTS *ftsp) {
    return fts_read(ftsp);
}

SLIBC_EXPORT FTSENT *fts64_children(FTS *ftsp, int options) {
    return fts_children(ftsp, options);
}

SLIBC_EXPORT int fts64_set(FTS *ftsp, FTSENT *f, int options) {
    return fts_set(ftsp, f, options);
}

SLIBC_EXPORT int fts64_close(FTS *ftsp) {
    return fts_close(ftsp);
}
