#include "main.h"
#include <stdarg.h>
/**
 * parser - parses each charachter to its specified function
 * @format: inputed string
 * @func: list of functions
 * @args: arguments paassed to the program
 * Return: Amount of chars printed
 */
int parser(const char *format, conver_t func[], va_list args)
{
	int printed_chars = 0;
	int i, r_val;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			for (i = 0; func[i].sym; i++)
			{
				if (*format == *(func[i].sym))
				{
					r_val = func[i].f(args);
					if (r_val < 0)
						return (-1);
					printed_chars += r_val;
					break;
				}
				else if (!*(func[i + 1].sym) || *format != ' ')
				{
					_putchar('%');
					_putchar(*format);
					printed_chars += 2;
					break;
				}
			}
		}
		else
		{
			_putchar(*format);
			printed_chars++;
		}
		format++;
	}
	return (printed_chars);
}
