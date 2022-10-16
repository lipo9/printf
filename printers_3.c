#include "main.h"
#include<stdlib.h>
#include<stdarg.h>
/**
 * print_HEX - Prints the HEX representation of an integrer (unsigned)
 * @args: variadic args list
 *
 * Return: The number of the printed digits
 */
int print_HEX(va_list args)
{
	int i = 1;
	unsigned int m = 0, n = 0;

	m = va_arg(args, int);
	n = m;
	while (m >= 16)
	{
		m = m / 16;
		i++;
	}

	recursive_HEX_printer(n);
	return (i);
}

/**
 * recursive_HEX_printer - Prints  HEX  value of an integer
 * number recursively (unsigned)
 * @n: integer
 * Return: Void
 */
void recursive_HEX_printer(int n)
{
	unsigned int m, r;
	char c;

	m = n;
	if (m / 16)
		recursive_HEX_printer(m / 16);
	r = m % 16;
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


/**
 * print_hex - Prints the hex representation of an integrer (unsigned)
 * @args: variadic args list
 *
 * Return: The number of the printed digits
 */
int print_hex(va_list args)
{
	int i = 1;
	unsigned int m = 0, n = 0;

	m = va_arg(args, int);
	n = m;
	while (m >= 16)
	{
		m = m / 16;
		i++;
	}

	recursive_hex_printer(n);
	return (i);
}

/**
 * recursive_hex_printer - Prints  hex  value of an integer
 * number recursively (unsigned)
 * @n: integer
 * Return: Void
 */
void recursive_hex_printer(int n)
{
	unsigned int m, r;
	char c;

	m = n;
	if (m / 16)
		recursive_hex_printer(m / 16);
	r = m % 16;
	if (r >= 10)
	{
		switch (r)
		{
			case 10:
				c = 'a';
				break;
			case 11:
				c = 'b';
				break;
			case 12:
				c = 'c';
				break;
			case 13:
				c = 'd';
				break;
			case 14:
				c = 'e';
				break;
			case 15:
				c = 'f';
				break;
		}
		write_char(c);
	}
	else
		write_char(r + '0');
}
