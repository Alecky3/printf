#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * format_b - function to convert unsigned integer to binary
 * @args: character argurment to print
 * Return: number of characters printed
 */
int print_b(va_list args)
{
	int count = 0;
	int c, i, n;
	char *nums;

	nums = va_arg(args, char*);
	int a[10];

	n = va_arg(args, int);
	for (i = 0; n > 0; i++)
	{
		a[i] = n % 2;
		n = n / 2;
	}
	count = (write(STDOUT_FILENO, &c, 1));
	return (count);
}
/**
 * print_o - function to convert unsigned integer to octal
 * @args: character argurment to print
 * Return: number of characters printed
*/

int print_o(va_list args)
{

}
/**
 * print_x - function to convert unsigned integer to lowercase hexadecimal
 * @args: character argurment to print
 * Return: number of characters printed
*/

int print_x(va_list args)
{

}
/**
 * print_X - function to convert unsigned integer to Uppercase hexadecimal
 * @args: character argurment to print
 * Return: number of characters printed
*/

int print_X(va_list args)
{

}
