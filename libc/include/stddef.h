#ifndef HELIOS_STDDEF_H
#define HELIOS_STDDEF_H 1

#include <sys/cdefs.h>
#include <stdint.h>

#define NULL ((void *) 0)

#ifdef __cplusplus
extern "C" {
#endif
    typedef uint32_t size_t;
#ifdef __cplusplus
}
#endif
#endif
