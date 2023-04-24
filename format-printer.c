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
 * unsigned_integer - Prints Unsigned integers
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


/**
 * print_num - pritns!!
 * @args: List of arguments
 * Return: The number of arguments printed
 */
int print_num(va_list args)
{
        int n;
        int d;
        int l;
        unsigned int num;

        n  = va_arg(args, int);
        d = 1;
        l = 0;

        if (n < 0)
        {
                l += _putchar('-');
                num = n * -1;
        }
        else
                num = n;

        for (; num / d > 9; )
                d *= 10;

        for (; d != 0; )
        {
                l += _putchar('0' + num / d);
                num %= d;
                d /= 10;
        }

        return (l);
}
/**
 * print_unsigned_num - Prints studf!!
 * @n: unsigned int
 * Return: lenght
 */
int print_unsigned_num(unsigned int n)
{
        int d;
        int l;
        unsigned int num;

        d = 1;
        l = 0;

        num = n;

        for (; num / d > 9; )
                d = d * 10;

        for (; d != 0; )
        {
                l += _putchar('0' + num / d);
                num %= d;
                d /= 10;
        }

        return (l);
}
