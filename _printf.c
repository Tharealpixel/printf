#include "main.h"

/**
 * _printf - prints string by calling write function for
 * 	right data type
 * @format: inputed string
 * Return: the printed string
 */
int _printf(const char *format, ...)
{
	int printed_c;
	conver_t func[] = {
		{"c", print_c},
		{"s", print_str},
		{"%", print_per},
		{NULL, NULL}
	};
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	printed_c = parser(format, func, args);

	va_end(args);
	return (printed_c);
}
