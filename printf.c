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

	/*Format characters*/
	char c = 'c', s = 's', d = 'd', i = 'i', o = 'o', u = 'u', x = 'x', X = 'X', p = 'p';

	/*store the buffer size of the whole arguments and also the length*/
	int buffer_size, length = 0;

	/* Allocates memory for list of arguments buffer*/
	char *whole_buffer, *data_to_print;

	/*Argument parameters*/
	va_list ap;

	if (format == NULL)
		exit(1);

	buffer_size = (format);

	va_start(ap, format);

	/*Increment the buffer_size*/
	for (index = 0; index < strlen(format); index++)
	{
		if (format[index] == '%')

			switch(format[index + 1])
			{
			case c:
				buffer_size += sizeof(va_arg(ap, char));
				break;

			case s:
                                buffer_size += sizeof(va_arg(ap, char*));
                                break;
			case d:
				buffer_size += sizeof(va_arg(ap, int));
                               break;
			case i:
				buffer_size += sizeof(va_arg(ap, int));
                               break;
			}
	}

}
