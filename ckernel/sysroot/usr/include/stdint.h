#ifndef _HELIOS_STDINT_H
#define _HELIOS_STDINT_H 1

#include <sys/cdefs.h>
#include <bits/wordsize.h>
__BEGIN_CDECLS

#   define PRI32 "d"
#   define PRIu32 "du"
#   define PRI64 "ll"
#   define PRIu64 "llu"
    typedef char int8_t;
    typedef unsigned char uint8_t;
#if defined(ARCH_X86)
    typedef short int16_t;
    typedef unsigned short uint16_t;
    typedef int int32_t;
    typedef unsigned int uint32_t;
    typedef long long int64_t;
    typedef unsigned long long uint64_t;
#elif defined(ARCH_X64)
    /* These are unknown right now. Kernel doesn't support
    * 64-bit architectures at the moment. */
#endif

__END_CDECLS
#endif
