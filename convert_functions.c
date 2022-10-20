#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_c - prints a character
 * @args: character argument to print
 * Return: number of characters written to stdout
 */
int print_c(va_list args)
{
	int c;

	c = va_arg(args, int);
	return (write(STDOUT_FILENO, &c, 1));
}
/**
 * print_s - prints a string
 * @args: string  argument
 * Return: number of characters written to stdout
 */
int print_s(va_list args)
{
	int count = 0;
	char *str;

	str = va_arg(args, char*);
	count = write(STDOUT_FILENO, str, strlen(str) + 1);
	return (count);
}
/**
 * print_d - prints a decimal
 * @args: decimal argument
 * Return: number of decimals printed
 */
int print_d(va_list args)
{

	unsigned int absolute, aux, countnum, count;
	int n;

	count = 0;
	n = va_arg(args, int);
		if (n < 0)
		{
			absolute = (n * -1);
			count += write(STDOUT_FILENO, "-", 1);
		}
		else
			absolute = n;

	aux = absolute;
	countnum = 1;
	while (aux > 9)
	{
		aux /= 10;
		countnum *= 10;
	}
	while (countnum >= 1)
	{
		char c = ((absolute / countnum) % 10) + '0';

		count += write(STDOUT_FILENO, &c, 1);
		countnum /= 10;
	}
	return (count);
}
/**
 * print_i - prints integer in base 10
 * @args: integer argument
 * Return: the decimal function
 */

int print_i(va_list args)
{
	return (print_d(args));
}
/**
 * print_u - prints unsigned integer
 * @args: the integer to print
 * Return: number of characters writen to stsout
 */
int print_u(va_list args)
{
	unsigned int absolute, aux, countnum, count;
	int n;

	count = 0;
	n = va_arg(args, int);
		if (n < 0)
		{
			absolute = (n * -1);
		}
		else
			absolute = n;

	aux = absolute;
	countnum = 1;
	while (aux > 9)
	{
		aux /= 10;
		countnum *= 10;
	}
	while (countnum >= 1)
	{
		char c = ((absolute / countnum) % 10) + '0';

		count += write(STDOUT_FILENO, &c, 1);
		countnum /= 10;
	}
	return (count);
}

