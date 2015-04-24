#ifndef _HELIOS_STDDEF_H
#define _HELIOS_STDDEF_H 1

#include <sys/cdefs.h>
#include <stdint.h>

#define NULL ((void *) 0)
#define offsetof(type,member) ((unsigned long) &(((type*)0)->member))

__BEGIN_CDECLS

typedef uint32_t size_t;
typedef size_t uintptr_t;
typedef uint32_t ptrdiff_t;

__END_CDECLS
#endif
