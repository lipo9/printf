#include <unistd.h>

/**
 * write_char - writes a char to the standard output
 * @c: The character to print
 * Return: 1 if successful, -1 if not
 */
int write_char(char c)
{
	return (write(1, &c, 1));
}
