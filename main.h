#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int write_char(char);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
void recursive_int_printer(int n);
int print_unsigned_int(va_list args);
int print_octal(va_list args);
void recursive_octal_printer(int n);

int print_hex(va_list args);
void recursive_hex_printer(int n);
int print_HEX(va_list args);
void recursive_HEX_printer(int n);

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
