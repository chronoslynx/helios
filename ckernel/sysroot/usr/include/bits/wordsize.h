#ifndef _HELIOS_BITS_WSIZE_H
#define _HELIOS_BITS_WSIZE_H 1

#if defined(_M_I86)
#define ARCH_X86 1
#elif defined(_M_X64) || defined(_M_AMD64)
#define ARCH_X64 1
#endif

#if defined(__X86__) || defined(__i386__)
#define ARCH_X86 1
#elif defined(__x86_64__) || defined(__amd64__) || defined(__ia64__)
#define ARCH_X64 1
#endif

#endif
