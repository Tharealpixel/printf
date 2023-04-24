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

/**
 * print_int - Prints an integer
 * @i: integer to print
 * Return: Will return the amount of characters printed.
 */
int print_int(va_list i)
{
	int num_length;

	num_length = print_num(i);
	return (num_length);
}

/**
 * unsigned_int - Prints Unsigned integers
 * @un: unsigned stuff
 * Return: -1 if negative or cou t of numbers
 */
int unsigned_int(va_list un)
{
	unsigned int num;

	num = va_arg(un, unsigned int);

	if (num == 0)
		return (print_unsigned_num(num));

	if (num < 1)
		return (-1);
	return (print_unsigned_num(num));
}
