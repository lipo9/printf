#include "main.h"

/**
 * print_HEX_2 - Prints 2 chars  of the HEX representation of an int (unsigned)
 * @arg: integer
 * Return: void
 */
void print_HEX_2(int arg)
{
	int i = 1;
	unsigned int m = 0, n = 0;

	m = arg;
	n = m;
	while (m >= 16)
	{
		m = m / 16;
		i++;
	}

	if (i == 1)
		write_char('0');
	recursive_HEX_2_printer(n);
}

/**
 * recursive_HEX_2_printer - Prints  2 chars of the HEX  value of an integer
 * number recursively (unsigned)
 * @n: integer
 * Return: void
 */
void recursive_HEX_2_printer(int n)
{
	unsigned int m, r;
	char c;
	int i = 0;

	m = n;
	if (m / 16)
		recursive_HEX_2_printer(m / 16);
	i++;
	r = m % 16;
	if (i <= 2)
	{
		if (r >= 10)
		{
			switch (r)
			{
				case 10:
					c = 'A';
					break;
				case 11:
					c = 'B';
					break;
				case 12:
					c = 'C';
					break;
				case 13:
					c = 'D';
					break;
				case 14:
					c = 'E';
					break;
				case 15:
					c = 'F';
					break;
			}
			write_char(c);
		}
		else
			write_char(r + '0');
	}
}

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
		if ((str[i] >= 1 && (
		    str[i] <= 31 || str[i] >= 127)))
		{
			write_char('\\');
			write_char('x');
			print_HEX_2((int)str[i]);
			l += 4;
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

