#include "myfunctions0.h"
#include <stddef.h>
#include <unistd.h>

/**
 * _putchar - writes a caharacter to the standard output
 * Return: 1 upon successful completion
 * @c: The character to be written
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

#include "myfunctions0.h"
#include <unistd.h>

/**
 * _puts - writes a string to the standard output
 *@str: the string to be written
 * Return: The number of characters written
 */
int _puts(const char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		if (_putchar(str) < 0)
			return (-1);
		count++;
		str++;
	}

	return (count);
}

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
