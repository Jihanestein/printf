#include "myfunctions0.h"
#include <stddef.h>
#include <unistd.h>

/**
 * _putchar - writes a character to the standard output
 * Return: 1 upon successful completion
 * @c: The character to be written
 */
int _putchar(int c)
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
		if (_putchar(*str) < 0)
			return (-1);
		count++;
		str++;
	}

	return (count);
}

/**
 * get_print_func - A function that retrieves the print function
 * @format: The format specifier
 * @index: the index
 * Return: The pointer to the print function
 */
int (*get_print_func(const char *format, int index))(va_list arguments, char *buffer, unsigned int ibuf)
{
	(void)format;
	(void)index;

	return (NULL);
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
