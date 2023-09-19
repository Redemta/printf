#include "main.h"

/**
 * format_specifier - Helper function to handle format specifiers.
 * @format: the format string.
 * @args: the variable argument list.
 * @i: pointer to current position in the format string.
 * Return: The number of characters printed by this format specifier.
 */

static int format_specifier(const char *format, va_list args, int *i)
{
	char c = format[*i];
	int printed_chars = 0;

	if (c == 'c')
	{
		char ch = va_arg(args, int);

		printed_chars += print_char(ch);
	}
	else if (c == 's')
	{
		char *str = va_arg(args, char*);

		printed_chars += print_string(str);
	}
	else if (c == '%')
	{
		printed_chars += print_percent('%');
	}
	else if (c == 'd' || c == 'i')
	{
		int num = va_arg(args, int);
		char num_str[12];

		sprintf(num_str, "%d", num);
		printed_chars += print_string(num_str);
	}
	else if (c == 'b')
	{
		printed_chars += print_binary('b');
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
			printed_chars += print_char(format[i]);
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
