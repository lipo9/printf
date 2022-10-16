#include "main.h"
#include<stdlib.h>
#include <stdarg.h>

/**
  * print_char - Prints a char
  * @args: A list of variadic arguments
  *
  * Return: The length of the character
  */
int print_char(va_list args)
{
	write_char(va_arg(args, int));
	return (1);
}

/**
  * print_string - Prints a string
  * @args: A list of variadic arguments
  *
  * Return: The length of the string
  */
int print_string(va_list args)
{
	char *arg = va_arg(args, char *);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			write_char(arg[i]);
			i++;
		}

		return (i);
	}

	write_char('(');
	write_char('n');
	write_char('u');
	write_char('l');
	write_char('l');
	write_char(')');
	return (6);
}


/**
 * print_int - Prints an integrer.
 * @args: variadic args list
 *
 * Return: The length of the string printed
 */
int print_int(va_list args)
{
	int i = 1, n = 0;
	unsigned int m = 0;

	m = va_arg(args, int);
	n = m;
	if (n < 0)
	{
		i++;
		write_char('-');
		n = n * -1;
		m = n;
	}
	while (m >= 10)
	{
		m = m / 10;
		i++;
	}

	recursive_int_printer(n);
	return (i);
}

/**
 * recursive_int_printer - Prints digits of integer number recursively
 * @n: integer
 * Return: Void
 */
void recursive_int_printer(int n)
{
	unsigned int m;

	m = n;
	if (m / 10)
		recursive_int_printer(m / 10);
	write_char(m % 10 + '0');
}


/**
 * print_unsigned_int - Prints an unsigned integrer.
 * @args: variadic args list
 *
 * Return: The number of printed digits
 */
int print_unsigned_int(va_list args)
{
	int i = 1;
	unsigned int m = 0, n = 0;

	m = va_arg(args, int);
	n = m;
	while (m >= 10)
	{
		m = m / 10;
		i++;
	}

	recursive_int_printer(n);
	return (i);
}


