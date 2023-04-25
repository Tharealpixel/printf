#include "main.h"
#include <stdio.h>
int hex_check(int, char);

/**
 * print_binary - transform to binary
 * @list: args passed
 * Return: returning the length
 */
int print_binary(va_list list)
{
	unsigned int num;
	int i, len;
	char *str;
	char *rev_str;

	num = va_arg(list, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num = num / 2;
	}
	str[i] = '\0';
	rev_str = rev_string(str);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(str);
	free(rev_str);
	return (len);
}

/**
 * print_oct - number in octal
 * @list: args passed
 * Return: returns symbols
 */
int print_oct(va_list list)
{
	unsigned int num;
	int len;
	char *octal_rep;
	char *rev_str;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 8);

	octal_rep = malloc(sizeof(char) * len + 1);
	if (octal_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		octal_rep[len] = (num % 8) + 48;
		num = num / 8;

	}
	octal_rep[len] = '\0';
	rev_str = rev_string(octal_rep);
	if (rev_str == NULL)
		return (-1);

	write_base(rev_str);
	free(octal_rep);
	free(rev_str);
	return (len);
}

/**
 * print_hex - prints an unsigned int in hexadecimal format (lowercase)
 * @args: va_list containing the unsigned integer to print
 * Return: number of characters printed
 */
int print_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char hex[100];
	int i = 0, len = 0;

	if (num == 0)
		return (_putchar('0'));

	while (num != 0)
	{
		int temp = 0;

		temp = num % 16;
		if (temp < 10)
			hex[i] = temp + 48;
		else
			hex[i] = temp + 87;
		num /= 16;
		i++;
	}

	len = i;

	for (i = len - 1; i >= 0; i--)
		_putchar(hex[i]);

	return (len);
}

/**
 * print_heX - decimal on base 16
 * @list: args passed
 * Return: chars printed
 */
int print_heX(va_list list)
{
	unsigned int num;
	int len;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	hex_rep = malloc(sizeof(char) * len + 1);
	if (hex_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = hex_check(rem_num, 'X');
			hex_rep[len] = rem_num;
		}
		else
			hex_rep[len] = rem_num + 48;
		num = num / 16;
	}
	hex_rep[len] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (len);
}

/**
 * hex_check - checkHex
 * @num: Number to letter
 * @x: idk what this x do
 * Return: Ascii of a letter
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}
