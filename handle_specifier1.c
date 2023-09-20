#include "main.h"

/**
 * unsigned_int - function to handle unsigned integers.
 * @args: List of arguments.
 * Return: No of characters printed.
 */

int unsigned_int(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[12];

	int len = snprintf(buffer, sizeof(buffer), "%u", num);

	return (write(1, buffer, len));
}

/**
 * handle_octal - function to handle octal integers.
 * @args: List of arguments.
 * Return: No of characters printed.
 */

int handle_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[12];

	int len = snprintf(buffer, sizeof(buffer), "%o", num);

	return (write(1, buffer, len));
}

/**
 * handle_hexadecimal - Function to handle hexadecimal integers ('x' and 'X').
 * @args: List of arguments.
 * @is_uppercase: format determinant.
 * Return: No of characters printed.
 */

int handle_hexadecimal(va_list args, int is_uppercase)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[12];

	const char *format = is_uppercase ? "%X" : "%x";

	int len = snprintf(buffer, sizeof(buffer), format, num);

	return (write(1, buffer, len));
}
