#include "myfunctions0.h"
#include <stddef.h>

/**
 * handl_buf - A funcntion that handles a buffer
 * @buffer: The buffer to be handled
 * @format: The format specifier
 * @size: The size of the buffer
 */
void handl_buf(char *buffer, char format, unsigned int size)
{
	(void)buffer;
	(void)format;
	(void)size;
}

/**
 * ev_print_func - Event print function
 * @format: The format specifier
 * @index: The index
 * Return: Always 0 on success
 */
int ev_print_func(const char *format, int index)
{
	(void)format;
	(void)index;
	return (0);
}

