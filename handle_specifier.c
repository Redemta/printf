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
 * @args: List of arguments.
 * Return: No of characters to print.
 */

int handle_percent(void)
{
	char c = '%';

	return (write(1, &c, 1));
}
