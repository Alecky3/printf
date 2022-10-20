#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <string.h>
/**
 * _printf - prints character format
 * @format: the format to print
 * Return: number of characters written
 */

int _printf(const char *format, ...)
{
	if (format != NULL)
	{
		int count = 0, i, chars_count = 0;
		va_list args;

		va_start(args, format);
		i = 0;
		if (format[0] == '%' && format[1] == '\0')
			return (0);
		while (format != NULL && format[i] != '\0')
		{
			if (format[i] == '%')
			{
				if (format[i + 1] == '%')
				{
					count += write(STDOUT_FILENO, &format[i + 1], 1);
					i += 2;
				}
				else
				{
					chars_count = select_function(format[i + 1], args);
					count += chars_count;
					i += 2;
				}
			}
			count += write(STDOUT_FILENO, &format[i], 1);
			i++;
		}
		va_end(args);
		return (count);
	}
	return (0);
}
