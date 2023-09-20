#include "main.h"

/**
 * format_specifier - helper function to handle format specifiers.
 * @format: the format string.
 * @args: The list of arguments.
 * @i: pointer to current position in the format string.
 * Return: No of character printed by this format specifier.
 */

int format_specifier(const char *format, va_list args, int *i)
{
	int printed_chars = 0;
	char c = format[*i];

	if (c == 'c')
	{
		char ch = va_arg(args, int);

		write(1, &ch, 1);
	}
	else if (c == 's')
	{
		char *str = va_arg(args, char *);
		int len = 0;

		while (str[len])
			len++;
		write(1, str, len);
	}
	else if (c == '%')
	{
		write(1, &c, 1);
	}
	return (printed_chars);
}

/**
 * _printf - function that produces output according to a format.
 * @format: character string.
 * Return: No of characters printed.
 */

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	int i;

	va_list args;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			printed_chars += format_specifier(format, args, &i);
		}
	}
	va_end(args);

	return (printed_chars);
}
