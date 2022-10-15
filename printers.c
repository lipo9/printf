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
