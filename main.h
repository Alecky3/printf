#ifndef _PRINTF_H_
#define _PRINTF_H_
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <string.h>
int select_function(char c, va_list args);
int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_d(va_list args);
int print_i(va_list args);
int print_u(va_list args);
int print_b(va_list args);
int print_o(va_list args);

#endif
