#include "main.h"
#include <stdarg.h>

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len;
	conver_t func[] = {
		{"c", print_c},
		{"s", print_str},
		{"%", print_per},
		{"d", print_int},
		{"i", print_int},
		{"p", print_ptr},
		{"b", print_binary},
		{"R", print_rot13},
		{"u", print_un_int},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}};

	va_start(args, format);
	len = parser(format, func, args);
	va_end(args);

	return (len);
}
