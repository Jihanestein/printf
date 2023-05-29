#include "main.h"
#include <stdarg.h>
#include <stdio.h>

void print_buffer(char buffer[], int *buff_ind);

/**
  *_printf - printf fucntion
  * @format: format
  * Return: character printed
  */

int _printf(const char *format, ...)
{
	int a;
	int output = 0;
	int print_chars = 0;
	int flags,width,precision,size,buff_ind = 0;
	va_list printlist;
	char buffer[BUFF_SIZE];

	if ( format == NULL)
		return (-1);

	va_start(printlist, format);


