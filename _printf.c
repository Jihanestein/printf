#include "myfunctions0.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
  *_printf - formated output conversion and print data.
  * @format: input string.
  *
  * Return: number of char printed.
  */

int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, ibuf = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);

	va_start(arguments, format);
	if (!format[i])
	{
		va_end(arguments);
		free(buffer);
		return (0);
	}

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				print_buf(buffer, ibuf);
				free(buffer);
				va_end(arguments);
				return (-1);
			}
			else
			{
				function = get_print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' &&!format[i + 2])
						return (-1);
					handl_buf(buffer, format[i], ibuf), len++, i--;
				}
				else
				{
					len += function(arguments, buffer, ibuf);
					i += ev_print_func(format, i + 1);
				}
			}
			i++;
		}
		else
		{
			handl_buf(buffer, format[i], ibuf), 
			len++;
		}
	}
	print_buf(buffer, ibuf);
	free(buffer);
	va_end(arguments);
	
	return (len);
}
