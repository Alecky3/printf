#include "main.h"

/**
 * select_function - selects the function to return based on the passed
 * parameter
 * @c: the paramater to determine the select function.
 * @args: argument to pass to the selected function.
 * Return: convert_function
 */
int select_function(char c, va_list args)
{
	switch (c)
	{
		case 'c':
			return (print_c(args));
		case 'd':
			return (print_d(args));
		case 's':
			return (print_s(args));
		case 'i':
			return (print_i(args));
		default:
			return (0);
	}
	return (0);
}
