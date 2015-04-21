#ifndef _HELIOS_STDDEF_H
#define _HELIOS_STDDEF_H 1

#include <sys/cdefs.h>
#include <stdint.h>

#define NULL ((void *) 0)
#define offsetof(type,member) ((unsigned long) &(((type*)0)->member))

#ifdef __cplusplus
extern "C" {
#endif
    typedef uint32_t size_t;
    typedef size_t uintptr_t;
    typedef uint32_t ptrdiff_t;
#ifdef __cplusplus
}
#endif
#endif
