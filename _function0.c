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
	int len = snprintf(num_str, sizeof(num_str), "%d", num);

	write(1, num_str, len);
	return (len);
}
