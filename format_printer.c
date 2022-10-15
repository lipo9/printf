#include "main.h"
#include <stdlib.h>

/**
  * format_printer - Prints format
  * @format: The format to be printed
  * @args: A list of arguments
  * Return: The length of the format
  */
int format_printer(const char *format, va_list args)
{
	int f_l = 0; /* format length*/
	int i = 0;
	const char *pf = format;

	while (pf && *(pf + i))
	{
		if (*(pf + i) == '%')
		{
			if (*(pf + i + 1) == '\0')
				return (-1);

			i++;

			while (*(pf + i) == ' ')
				i++;

			if (*(pf + i) == '%')
				f_l += write_char(*(pf + i));

			if (f_checker(*(pf + i)) == 0)
			{
				f_l = nfs_printer(*(pf + i - 1), *(pf + i), f_l);
			}
			else
			{
				f_l += fs_printer(*(pf + i), args);
			}
		}
		else
		{
			f_l += write_char(*(pf + i));
		}

		i++;
	}

	return (f_l);
}

/**
  * fs_printer - Prints a valid.s
  * @format: The specifier to prints
  * @args: A list of variadic arguments
  *
  * Return: The length of the specifier
  */
int fs_printer(char format, va_list args)
{
	int i  = 0, length = 0;
	type_symbol types[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};

	while (types[i].s)
	{
		if (*types[i].s == format)
			length = types[i].f(args);

		i++;
	}

	return (length);
}

/**
  * nfs_printer - Prints non.ss
  * @prev_format: The previous.s of the current one
  * @format: The.s to print
  * @f_l: The current count before printing non specifiers
  * Return: The current count after printing non specifierss
  */
int nfs_printer(char prev_format, char format, int f_l)
{
	f_l += write_char('%');

	if (prev_format == ' ')
	{
		f_l += write_char(' ');
		f_l += write_char(format);
	}
	else
	{
		f_l += write_char(format);
	}

	return (f_l);
}

/**
  * f_checker - validate the type
  * @_type: character to be comparate
  *
  * Return: 1 if char is equal to a type symbol
  */
int f_checker(char _type)
{
	char types[] = {'c', 's', '%'};
	int i = 0;

	while (types[i])
	{
		if (types[i] == _type)
			return (1);
		i++;
	}
	return (0);
}
