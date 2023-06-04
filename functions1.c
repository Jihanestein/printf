#include "main.h"

/**
  * print_unsigned - print unsigned number
  * @types: list a of arguments
  * @buffer: buffer array to handle print
  * @flags: calculates active flags
  * @width: get width
  * @precision: precision specification
  * @size: size specifier
  * Return: Number of char printed
  */

int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************************PRINT UNSGNED NUM IN OCTAL*****/

/**
  * print_octal - prints an unsigned num in ocatl
  * @types: list of arg
  * @buffer: buffer array to handle pront
  * @flags: calculate active flags
  * @width: get width
  * @precision: precision specification
  * @size: size specifier
  * Return: num of char printed
  */

int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/*********PRINT UNSIGNED NUM IN HEXADICIMAL******/
/**
  * print_hexadecimal - print unsgnd num in hexadecimal notation
  * @types: list of arg
  * @buffer: buffer array to handle pront
  * @flags: calculate active flags
  * @width: get width
  * @precision: precision specification
  * @size: size specifier
  * Return: num of char printed
  */

int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'X', width, precision, size));
}
/**********PRINT HEXX NUM IN LOWER OR UPPER******/
/**
  * print_hexadecimal - num in upper or lower
  * @types: list of arg
  * @map_to: Array of values to map the number to
  * @buffer: buffer array to handle pront
  * @flags: calculate active flags
  * @flag_h: calculate active flags
  * @width: get width
  * @precision: precision specification
  * @size: size specifier
  * @size: size specification
  * Return: num of char printed
  */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_h, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num %  16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_h;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
