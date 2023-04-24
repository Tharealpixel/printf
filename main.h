#ifndef PRINT_F
#define PRINT_F

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * struct convert - defines a structure
 * @sym: operator
 * @f: function
*/
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
int print_int(va_list);
int print_num(va_list);
int print_binary(va_list);
int print_rever(va_list arg);
int rot13(va_list);
int unsigned_int(va_list);
int print_oct(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);

unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsigned_num(unsigned int);

#endif
