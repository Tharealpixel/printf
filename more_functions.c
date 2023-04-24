#include "main.h"
#include <stdarg.h>

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
