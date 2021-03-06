#ifndef _HELIOS__STRING_H
#define _HELIOS_STRING_H 1

#include <sys/cdefs.h>

#include <stddef.h>

__BEGIN_CDECLS

int memcmp(const void*, const void*, size_t);
void* memcpy(void* __restrict, const void* __restrict, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);
size_t strlen(const char*);

__END_CDECLS
#endif
