#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - Behaves like std library's printf
 * @format: The string that can contain 0 or more formats to print
 * Return: The number of chars that were printed
 */
int _printf(const char *format, ...)
{
	va_list params;
	int len = 0;

	if (format == NULL)
		return (-1);

	va_start(params, format);
	len = format_printer(format, params);
	va_end(params);

	return (len);
}
