#include "myfunctions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - a function that produces output according to format
 * @format: a character string containing the format specifications
 * @...:
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
			format++;

		switch (*format)
		{
			case 'c':
				printed_chars += _putchar(va_arg(args, int));
				break;
			case 's':
				printed_chars += _puts(va_arg(args, char *));
				break;
				case '%'
					printed_chars += _putchar('%');
				break;
			default:
				printed_chars += _putchar('%');
				printed_chars += _putchar(*format);
				break;
		}
	}
	else
	{
		printed_chars += _putchar(*format);
		format++;
	}
	va_end(arg);

	return (printed_chars);
}
