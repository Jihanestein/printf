#ifndef MYFUNCTIONS0_H
#define MYFUNCTIONS0_H
#include <stdarg.h>

int _putchar(int c);
int _puts(const char *str);
void handle_write_char(char c);
void convert_size_number(int num);
void write_number(int num);
void print_buf(char *buffer, unsigned int size);
int (*get_print_func(const char *format, int index))
	(va_list arguments, char *buffer, unsigned int ibuf);
void handl_buf(char *buffer, char format, unsigned int size);
int ev_print_func(const char *format, int index);

#endif /* MYFUNCTIONS0_H */
