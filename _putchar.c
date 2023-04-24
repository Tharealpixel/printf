#include "main.h"

/**
 * _putchar - print the char.
 * @c: char to print
 *
 * Return: 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
