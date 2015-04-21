#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include <kernel/tty.h>

extern uint32_t end_kernel;

void kernel_early(void)
{
    terminal_initialize();
}

void kernel_main(void)
{
    printf("Hello, kernel World!\n");
    printf("Data sizes in bytes: \n");
    printf("- sizeof(char) = %z\n", sizeof(char));
    printf("- sizeof(short) = %z\n", sizeof(short));
    printf("- sizeof(int) = %z\n", sizeof(int));
    printf("- sizeof(long) = %z\n", sizeof(long));
    printf("- sizeof(long long) = %s\n", sizeof(long long));
    printf("- sizeof(double) = %z\n", sizeof(double));
    printf("- sizeof(long double) = %z\n", sizeof(long double));
}
