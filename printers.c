#include "main.h"
#include <stdlib.h>
#include <stdio.h>

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
	int n = va_arg(args, int);
	int m;
	int i = 1;

	if (n < 0)
	{
		write_char('-');
		n *= -1;
		i++;
	}

	m = n;
	while (m >= 10)
	{
		i++;
		m /= 10;
	}

	_recursive_int_printer(n);
}

