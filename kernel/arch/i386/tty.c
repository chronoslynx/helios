#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/vga.h>

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void terminal_initialize(void)
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	for ( size_t y = 0; y < VGA_HEIGHT; y++ )
	{
		for ( size_t x = 0; x < VGA_WIDTH; x++ )
		{
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = make_vgaentry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color)
{
	terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = make_vgaentry(c, color);
}

void terminal_scroll() {
    size_t i;
    size_t j;
    for (i = 1; i < VGA_HEIGHT; ++i) {
        for (j = 0; j < VGA_WIDTH; ++j) {
            const size_t index = i * VGA_WIDTH + j;
            terminal_buffer[index-VGA_WIDTH] = terminal_buffer[index];
        }
    }
    /* clear final row */
    i = (VGA_HEIGHT-1) * VGA_WIDTH;
    for (j = VGA_WIDTH-1; j; --j) {
        terminal_buffer[i+j] = (uint16_t)0;
    }
}

void terminal_putchar(char c)
{
    switch(c) {
        case '\n':
            terminal_column = 0;
            if ( ++terminal_row == VGA_HEIGHT )
            {
                terminal_row = VGA_HEIGHT-1;
                terminal_scroll();
            }
            break;
    default:
        terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
        if ( ++terminal_column == VGA_WIDTH )
        {
            terminal_column = 0;
            if ( ++terminal_row == VGA_HEIGHT )
            {
                terminal_row = VGA_HEIGHT-1;
                terminal_scroll();
            }
        }
        break;
    }

}

void terminal_write(const char* data, size_t size)
{
    for ( size_t i = 0; i < size; i++ ) {
        terminal_putchar(data[i]);
    }
}

void terminal_writestring(const char* data)
{
    terminal_write(data, strlen(data));
}
