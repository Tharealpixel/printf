#include "main.h"
#include <stdarg.h>

/**
 * parser - parses each character to its specified function
 * @format: input string
 * @func: list of conversion functions
 * @args: variable argument list
 * Return: number of characters printed
 */
int parser(const char *format, conver_t func[], va_list args)
{
	int len = 0;
	int i, val;

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			for (i = 0; func[i].sym != NULL; i++)
			{
				if (*format == *(func[i].sym))
				{
					val = func[i].f(args);
					if (val < 0)
						return (-1);
					len += val;
					break;
				}
			}
			if (func[i].sym == NULL)
			{
				_putchar('%');
				_putchar(*format);
				len += 2;
			}
		}
		else
		{
			_putchar(*format);
			len++;
		}
		format++;
	}
	return (len);
}
