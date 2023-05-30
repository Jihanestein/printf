#include "main.h"

/** print_unsigned - fucntion print an ungn number
  *@types: list of arg
  *@buffer: buffer array to handle print
  *@flags: calcluate active flags
  *@width: width
  *@precision: specifiy precision
  *@size: specifiy size
  *Return: number of cahar
  */

int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precison, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}
	
	a++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size);

/**
  *print_octal - fct that print unsigned num in octal not
  *types: list of arg
  *width: width
  *@flags: calcul active flags
  *@buffer: array to handle print
  *@precison: specify precision
  *@size: specify size
  *return: num of char printed
  */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	
	UNUSED(width)

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[a--] = '0';
	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precison, size));
}

/**
  *print_hexadecimal - print an ungsnd number in hexa notation
  *@types: list of arg
  *@buffer: array handle a print
  *@flags: calculat active flags
  *@width: width
  *@precision: specify precision
  *size: specify size
  *Return: char printed
  */

int print_hexadecima(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'X', width, precision, size));
}

/**
  *print_hexa_upper - print unsgnd num in upper hexa not
  *@types: list of arg
  *@flags: active flags
  *@buffer: array handle a print
  *@width: width
  *@precision: specify precision
  *@size: specifiy size
  *Return: char printed
  */

int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));

}

/**
  *print_hexa - print hexa num in upper or lower
  *@types: list of arg
  *@map_to: value to map the num
  *@buffer: array handle a print
  *@flags: active flags
  *@flag_ch: calclate active flags
  *@width: width
  *@precision: precision
  *@size: size specifyer 
  *Return: num of char printed
  */

int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width)

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, buffer, flags, width, precision, size));
}
