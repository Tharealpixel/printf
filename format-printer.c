#include "main.h"
#include <stdarg.h>

/**
 * print_c - Prints c (char data type)
 * @c: chars to print
 * Return: 1
 */
int print_c(va_list c)
{
	_putchar(va_arg(c, int));
	return (1);
}

/**
 * print_str - Prints a string
 * @s: string ;)
 * Return: @i the amount of chars
 */
int print_str(va_list s)
{
	int i;
	char *str;

	str = va_arg(s, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_per - Prints a percent symbol
 * @per: argument
 * Return: 1
 */
int print_per(__attribute__((unused))va_list per)
{
	_putchar('%');
	return (1);
}
