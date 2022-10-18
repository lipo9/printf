#include "main.h"

/**
 * print_string2 - Prints a string
 * by printing its non printables
 * character as '\x' followed by
 * the ASCII code in hex.
 * @args: A list of variadic arguments.
 *
 *
 * Return: Number of characters printed.
 */
int print_string2(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;
	int l = 0;

	if (str == NULL)
	{
		write_char('(');
		write_char('n');
		write_char('u');
		write_char('l');
		write_char('l');
		write_char(')');
		return (6);
	}

	while (str[i] != '\0')
	{
		if ((str[i] >= 1 &&
		    str[i] <= 31))
		{
			write_char('\\');
			write_char('x');

			if (str[i] < 16)
				write_char('0');

			recursive_HEX_printer(str[i]);
			l += 2;
		}
		else
		{
			write_char(str[i]);
			l++;
		}
		i++;
	}

	return (l);
}

