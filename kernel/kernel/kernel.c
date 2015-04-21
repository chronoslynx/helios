#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

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
    printf("- sizeof(char) = %d\n", sizeof(char));
    printf("- sizeof(short) = %d\n", sizeof(short));
    printf("- sizeof(int) = %d\n", sizeof(int));
    printf("- sizeof(long) = %d\n", sizeof(long));
    printf("- sizeof(long long) = %d\n", sizeof(long long));
    printf("- sizeof(double) = %d\n", sizeof(double));
    printf("- sizeof(long double) = %d\n", sizeof(long double));
    /*printf("end of kernel is at %du", (int)end_kernel);*/
}
