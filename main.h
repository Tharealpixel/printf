#ifndef PRINT_F
#define PRINT_F

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int parser(const char *format, conver_t f_list[], va_list arg_list);
int _printf(const char *format, ...);
int _putchar(char);
int print_c(va_list);
int print_str(va_list);
int print_%(va_list);

struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;
