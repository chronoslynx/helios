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
    printf("end of kernel is at %d", end_kernel);
}
