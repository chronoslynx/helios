#if !defined(_HELIOS_ASSERT_H)
#define _HELIOS_ASSERT_H 1

#include <sys/cdefs.h>

__BEGIN_CDECLS
__attribute__((__noreturn__))
void assert_fail(const char* cond, const char* file, const int line, const char* func);
__END_CDECLS

#if defined(NDEBUG)
#   define assert(ignore)((void) (0))
#else
#   define __ASSERT_FUNC ((const char*) 0)
#   define assert(cond) (cond ? (void) (0) : assert_fail(__STRING(x), __FILE__, __LINE__, __func__))
#endif

#endif
