/*
 * 🕷️ slibc - Spider OS Standard C Library & Compatibility Layer
 * Copyright (c) 2026 Spider OS Technologies. All Rights Reserved.
 * PROPRIETARY AND CONFIDENTIAL.
 */
#ifndef _SLIBC_H_
#define _SLIBC_H_

#define _GNU_SOURCE 1
#define _BSD_SOURCE 1

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#define SLIBC_VERSION_MAJOR 1
#define SLIBC_VERSION_MINOR 0
#define SLIBC_VERSION_PATCH 0
#define SLIBC_VERSION_STR   "1.0.0"

#ifndef alias
#define alias(old, new) \
    extern __typeof(old) new __attribute__((__alias__(#old)))
#endif

#ifndef weak_alias
#define weak_alias(old, new) \
    extern __typeof(old) new __attribute__((weak, __alias__(#old)))
#endif

#define SLIBC_EXPORT __attribute__((visibility("default")))

#endif /* _SLIBC_H_ */
