#include "main.h"

/**
 * handle_char - function to handle character.
 * @args: list of arguments.
 * Return: No of characters to print.
 */

int handle_char(va_list args)
{
	char ch = va_arg(args, int);

	return (write(1, &ch, 1));
}

/**
 * handle_string - function to handle string.
 * @args: List og arguments.
 * Return: No of characters to print.
 */

int handle_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	while (str[len])
		len++;
	return (write(1, str, len));
}

/**
 * handle_percent - function to handle percent.
 * Return: No of characters to print.
 */

int handle_percent(void)
{
	char c = '%';

	return (write(1, &c, 1));
}

/**
 * handle_int - function to handle integers d and i.
 * @args: List of arguments.
 * Return: No of characters to print.
 */

int handle_int(va_list args)
{
	int num = va_arg(args, int);
	char buffer[12];

	int len = sprintf(buffer, "%d", num);

	return (write(1, buffer, len));
}

/**
 * handle_binary - function to handle binary conversion.
 * @args: List of arguments.
 * Return: No of characters to print.
 */

int handle_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[33];

	int len = snprintf(buffer, sizeof(buffer), "%u", num);

	return (write(1, buffer, len));
}
