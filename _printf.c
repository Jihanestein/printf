#include "main.h"
#include <stdarg.h>
#include <stdio.h>

void print_buffer(char buffer[], int *buff_ind);

/**
  *_printf - printf fucntion
  * @format: format
  *print_buffer - fucntions that print buffer content
  *get_flags - get flags
  *get_width - get width
  *get_precision - get precision
  *get_size - get size
  *handle_print - print handle print
  * Return: character printed
  */

int _printf(const char *format, ...)
{
	int a;
	int output = 0;
	int print_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list printlist;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(printlist, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/*print(1, &format[a], 1);*/
			print_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &a);
			width = get_width(format, &a, printlist);
			precision = get_precision(format, &a, printlist);
			size = get_size(format, &a);
			a++;
			output = handle_print(format, &a, printlist, buffer,
				flags, width, precision, size);
			if (output == -1)
				return (-1);
			print_chars += output;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(printlist);
	return (print_chars);
}

/**
  *print_buffer - print buffer content if it exict
  *@buffer: array of chars
  *@buff_ind: represent the lenght, index to add next char
  */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
