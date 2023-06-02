#include "myfunctions0.h"
#include <unistd.h>

/**
 * _putchar - writes a character to the standard output
 * Return: 1 upon successful completion
 * @c: The character to be written
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
