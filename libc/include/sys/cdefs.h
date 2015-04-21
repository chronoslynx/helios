#ifndef _SYS_CDEFS_H
#define _SYS_CDEFS_H 1

#define __helios_libc 1

#define __CONCAT (x, y) x ## y
#define __STRING(x) #x


/* Begin C Declarations and End C Declarations */
#if defined(__cplusplus)
#   define __BEGIN_CDECLS extern "C" {
#   define __END_CDECLS }
#else
#   define __BEGIN_CDECLS
#   define __END_CDECLS
#endif

#endif
