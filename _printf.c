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
	char c = format[*i];

	if (c == 'c')
	{
		return (handle_char(args));
	}
	else if (c == 's')
	{
		return (handle_string(args));
	}
	else if (c == '%')
	{
		return (handle_percent());
	}
	else if (c == 'd' || c == 'i')
	{
		return (handle_int(args));
	}
	return (0);
}

#include "main.h"

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
			write(1, &format[i], 1);
			printed_chars++;
		}
		else
		{
			i++;
			printed_chars += format_specifier(format, args, &i);
		}
	}
	va_end(args);

	return (printed_chars);
}
