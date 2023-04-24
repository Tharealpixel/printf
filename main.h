#ifndef PRINT_F
#define PRINT_F

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

struct convert
{
        char *sym;
        int (*f)(va_list);
};
typedef struct convert conver_t;

int parser(const char *format, conver_t func[], va_list args);
int _printf(const char *format, ...);
int _putchar(char);
int print_c(va_list);
int print_str(va_list);
int print_per(va_list);

#endif
