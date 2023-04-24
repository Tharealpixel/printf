#include "main.h"

/**
 * parser - parses each charachter to its specified function
 * @format: inputed string
 * @func: list of functions 
 * @args: arguments paassed to the program
 * Return: Amount of chars printed
 */
int parser(const char *format, conver_t func[], va_list args)
{
	int i, j, r_val, printed_chars;

	printed_chars = 0;
	for (i = 0; format[i] != NULL; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; func[j].sym != NULL; j++)
			{
				if (format[i + 1] == func[j].sym[0])
				{
					r_val = func[j].f(args);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (func[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					printed_chars = printed_chars + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
	}
	return (printed_chars);
}
