#ifndef _HELIOS_STDIO_H
#define _HELIOS_STDIO_H 1

#include <sys/cdefs.h>
__BEGIN_CDECLS

int printf(const char* __restrict, ...);
int putchar(int);
int puts(const char*);

__END_CDECLS
#endif
