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
