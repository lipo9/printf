#include "main.h"
#include<stdlib.h>
#include<stdarg.h>
/**
 * print_octal - Prints the octal representation of an integrer.
 * @args: variadic args list
 *
 * Return: The number of the printed digits
 */
int print_octal(va_list args)
{
	int i = 1;
	unsigned int m = 0, n = 0;

	m = va_arg(args, int);
	n = m;
	while (m >= 8)
	{
		m = m / 8;
		i++;
	}

	recursive_octal_printer(n);
	return (i);
}

/**
 * recursive_octal_printer - Prints digits of octal value
 * of an integer number recursively
 * @n: integer
 * Return: Void
 */
void recursive_octal_printer(int n)
{
	unsigned int m;

	m = n;
	if (m / 8)
		recursive_octal_printer(m / 8);
	write_char(m % 8 + '0');
}
