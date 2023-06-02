#include "main.h"

/**
  *print_char - prints a char
  *@types: list of arg
  *@buffer: handle print
  *@flags: active flags
  *@width: width
  *@precision: specify precision
  *@size: specify size
  *Return: num of char printed
  */

int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
  *print_string - fct that print a string
  *@types: list of aeg
  *@buffer: handle a print
  *@flags: active flags
  *@width: width
  *@precision: specify precision
  *@size: specify size
  *Return: num of string printed
  */

int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = 0, b;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "     ";
	}

	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_minus)
		{
			write(1, &str[0], len);
			for (b = width - len; b > 0; b--)
				write(1, "  ", 1);
			return (width);
		}
		else
		{
			for (b = width - len; b > 0; b--)
				write(1, "  ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
  *print_ percent - print the percent sign
  *@types: list of arg
  *@buffer: handle a print
  *@flags: active flags
  *@width: width
  *@precision: specify precison
  *@size: specify size
  *Return: print the precent sign
  */

int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/**
  *print_int - print int
  *@types: list of arg
  *@buffer: habdle print
  *@width: width
  *@flags: active flags
  *@precision: specifiy precision
  *@size: specify size
  *Return: num of int printed
  */

int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int b = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[b--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[b--] = (num % 10) + '0';
		num /= 10;
	}

	b++;

	return (write_number(is_negative, b, buffer, flags, width, precision, size));
}

/**
  *print_binary - print an binary num
  *@types: list of arg
  *@buffer: handle print
  *@flags: active flags
  *@width: width
  *@precision: specify precision
  *@size: specify size
  *Return: num unsgn printed
  */

int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
