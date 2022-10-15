#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int write_char(char);
int print_char(va_list args);
int print_string(va_list args);
int _printf(const char *format, ...);
int format_printer(const char *format, va_list args);
int fs_printer(char format, va_list args);
int nfs_printer(char prev_format, char format, int f_l);
int f_checker(char _type);

/**
  * struct symbols - Struct for specifiers
  * @s: The conversion symbol
  * @f: The function pointer
  */
typedef struct symbols
{
	char *s;
	int (*f)(va_list args);
} type_symbol;

#endif
