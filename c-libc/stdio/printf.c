#include <stdbool.h>
#include <stdarg.h>
/*#include <stdint.h>*/
#include <stdio.h>
#include <string.h>

#define PRINTF_NUMBUF_SZ (32)

static void print(const char* data, size_t data_length)
{
    for ( size_t i = 0; i < data_length; i++ )
    {
        putchar((int) ((const unsigned char*) data)[i]);
    }
}

static char *int_to_string(char *c, int n, int len)
{
    int idx = len;
    int neg = n < 0;
    c[--idx] = 0; /* Null terminate */
    while (n >= 10)
    {
        int dig = n % 10;
        n /= 10;
        c[--idx] = dig + '0';
    }
    c[--idx] = n + '0';
    if (neg) {
        c[--idx] = '-';
    }
    return &c[idx];
}

static char *uint_to_string(char *c, unsigned int n, int len)
{
    int idx = len;
    c[--idx] = 0; /* NULL terminate */
    while (n >= 10)
    {
        int dig = n % 10;
        n /= 10;
        c[--idx] = dig + '0';
    }
    c[--idx] = n + '0';
    return &c[idx];
}

int printf(const char* restrict format, ...)
{
    va_list parameters;
    va_start(parameters, format);

    int written = 0;
    size_t amount;
    bool rejected_bad_specifier = false;
    char num_buffer[PRINTF_NUMBUF_SZ];
    while ( *format != '\0' )
    {
        if ( *format != '%' )
        {
        print_c:
            amount = 1;
            while ( format[amount] && format[amount] != '%' )
                amount++;
            print(format, amount);
            format += amount;
            written += amount;
            continue;
        }

        const char* format_begun_at = format;

        if ( *(++format) == '%' )
        {
            goto print_c;
        }

        if ( rejected_bad_specifier )
        {
        incomprehensible_conversion:
            rejected_bad_specifier = true;
            format = format_begun_at;
            goto print_c;
        }

        if ( *format == 'c' )
        {
            format++;
            char c = (char) va_arg(parameters, int /* char promotes to int */);
            print(&c, sizeof(c));
        }
        else if (*format == 'd')
        {
            format++;
            if (*format == 'u')
            { /* unsigned */
                format++;
                unsigned int n = (unsigned int) va_arg(parameters, unsigned int);
                const char *c = uint_to_string(num_buffer, n, PRINTF_NUMBUF_SZ);
                print(c, strlen(c));
            }
            else
            {
                int n = (int) va_arg(parameters, int);
                const char *c = int_to_string(num_buffer, n, PRINTF_NUMBUF_SZ);
                print(c, strlen(c));
            }
        }
        else if (*format == 'z')
        {
            format++;
            size_t s = (size_t) va_arg(parameters, size_t);
            const char *c = uint_to_string(num_buffer, s, PRINTF_NUMBUF_SZ);
            print(c, strlen(c));
        }
        else if ( *format == 's' )
        {
            format++;
            const char* s = va_arg(parameters, const char*);
            print(s, strlen(s));
        }
        else
        {
            goto incomprehensible_conversion;
        }
    }

    va_end(parameters);

    return written;
}
