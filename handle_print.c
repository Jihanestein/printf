#include "main.h"

/**
  * handle_print - prints an argument based on its type
  * @fmt: formatted string in which to print arg
  * @list: list of arguments to be printed
  * @ind: ind
  * @buffer: buffer array to handle print
  * @flags: calculate active flags
  * @width: get width
  * @precision: precision specification
  * @size: size specifier
  * Return: numberof chars printed or -1 on error
  */
int handle_print(const char *fmt, int *i, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int unknown_len = 0;
	int j;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexadecimal}, {'p', print_pointer}, {'S', print_non_printable},
		{'R', print_rot13string}, {'\0', NULL}
	};
	for (j = 0; fmt_types[j].fmt != '\0'; j++)
	{
		if (fmt[*i] == fmt_types[j].fmt)
		{
			return fmt_types[j].fn(list, buffer, flags, width, precision, size);
		}
	}
	if (fmt_types[j].fmt == '\0')
	{
		if (fmt[*i] == '\0')
		{
			return (-1);
		}
		unknown_len += write(1, " ", 1);
		unknown_len += write(1, " ", 1);
	}
	else if (width)
	{
		unknown_len = handle_width(fmt, i);
		return (unknown_len);
	}
	unknown_len += write(1, &fmt[*i], 1);
	return (unknown_len);
}
/**
  * handle_width - handler the width specfier int the format string
  * @fmt: formatting string
  * @i: pointer
  * Return: 1
  */
int handle_width(const char *fmt, int *i)
{
	--(*i);
	while (fmt[*i] != ' ' && fmt[*i] != '%')
	{
		--(*i);
	}
	if (fmt[*i] == ' ')
	{
		--(*i);
	}
	return (1);
}
