#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__))
void
assert_fail(const char *cond, const char* file, const char* line, const char* func)
{
    printf("%s:%s: %s: Assertion `%s' failed.", file, line, func, cond);
    abort();
}
