#include "main.h"

/**
 * print_char - function to print character.
 * @c: The character to print.
 * Return: No of characters printed.
 */

int print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - function to print string.
 * @str: the string to print.
 * Return: No of characters printed.
 */

int print_string(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

/**
 * print_percent - function to print percent.
 * @c: The character to print.
 * Return: No of characters printed.
 */

int print_percent(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * print_int - function to print 'd' and 'i'
 * @num: The integer to print.
 * Return: No of characters printed.
 */

int print_int(int num)
{
	char num_str[12];

	sprintf(num_str, "%d", num);

	return (print_string(num_str));
}

/**
 * print_binary - function to print unsigned int in binary format.
 * @num: The unsigned int to print.
 * Return: No of characters printed.
 */

int print_binary(unsigned int num)
{
	char bin_str[33];

	int i;

	for (i = 31; i >= 0; i--)
	{
		bin_str[31 - i] = ((num >> i) & 1) ? '1' : '0';
	}
	bin_str[32] = '\0';

	return (print_string(bin_str));
}

