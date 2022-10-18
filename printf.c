/*
 * Authors: Francis Ofori Anane and ..........add your name
 * Date: 18/10/2022
 */

#include <stdlib>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - Print output according to a specified format.
 *
 * @format: The specified format string
 */

_printf(const char *format, ...)
{
	/*interators*/
	int index, index2;

	/*store the buffer size of the whole arguments and also the length*/
	int buffer_size, length = 0;

	/* Allocates memory for list of arguments buffer*/
	char *whole_buffer, *data_to_print;

	/*Argument parameters*/
	va_list ap;

	if (format == NULL)
		exit(1);
	

}
