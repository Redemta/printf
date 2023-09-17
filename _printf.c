#include "main.h"

/**
 * handle_char - function to handle the character format specifier.
 * @args: list of arguments.
 * @printed_chars: number of characters printed.
 */

void handle_char(va_list args, int *printed_chars)
{
	char char_arg = va_arg(args, int);

	write(1, &char_arg, 1);
	(*printed_chars)++;
}

/**
 * handle_str - function to handle the string format specifier.
 * @args: list of arguments.
 * @printed_chars: number of characters printed.
 */

void handle_str(va_list args, int *printed_chars)
{
	char *str_arg = va_arg(args, char *);
	size_t len = strlen(str_arg);

	write(1, str_arg, len);
	(*printed_chars) += len;
}

/**
 * handle_percent - function to handle percent format specifier.
 * @printed_chars: number of characters printed.
 */

void handle_percent(int *printed_chars)
{
	char percent = '%';

	write(1, &percent, 1);
	(*printed_chars)++;
}

/**
 * _printf - function that produces output according to a format.
 * @format: first argument.
 * Return: Number of characters printed.
 */

int _printf(const char *format, ...)
{
	int printed_chars = 0;

	va_list args;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
			{
				handle_char(args, &printed_chars);
			}
			else if (*format == 's')
			{
				handle_str(args, &printed_chars);
			}
			else if (*format == '%')
			{
				handle_percent(&printed_chars);
			}
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
