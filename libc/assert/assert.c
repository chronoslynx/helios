#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__))
void
assert_fail(const char *cond, const char* file, const int line, const char* func)
{
    printf("%s:%d: %s: Assertion `%s' failed.\n", file, line, func, cond);
    abort();
}
