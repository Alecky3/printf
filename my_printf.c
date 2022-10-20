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
		int count = 0, i;
		va_list args;
		char *buffer;

		buffer = malloc(INT_MAX);
		va_start(args, format);
		i = 0;
		if (format[0] == '%' && format[1] == '\0')
			return (-1);
		while (format != NULL && format[i] != '\0')
		{
			if (format[i] == '%')
			{
				if (format[i + 1] == '%')
				{
					count += write(STDOUT_FILENO, &format[i], 1);
					i += 2;
				}
				else
				{
					switch (format[i + 1])
					{
						case 'd':
							int n = va_arg(args, int);

							sprintf(buffer, "%d", n);
							break;
						case 'c':
							n = va_arg(args, int);
							sprintf(buffer, "%c", n);
							break;
						case 's':
							char *str = va_arg(args, char *);

							buffer = str;
							break;
					}
					count += write(STDOUT_FILENO, buffer, strlen(buffer));
					i += 2;

				}
			}
			else
			{
				count += write(STDOUT_FILENO, &format[i], 1);
				i++;
			}
		}
		va_end(args);
		return (count);
	}
	return (-1);
}
