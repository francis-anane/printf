/*
 * Authors: Francis Ofori Anane and ..........add your name
 * Date: 18/10/2022
 */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/**
 * copy_string - Copy string from src to dest at a giving index.
 *
 * @dest: A pointer to the receiving buffer
 * @src: A pointer to the source buffer.
 * @index: The index to start coping from.
 *
 * Return: A pointer to the dest,
 * (NULL) if src or index is NULL
 */

char *copy_string(char *dest, const char *src, int *index)
{
	int i;

	if (src == NULL || index == NULL)
		return (NULL);

	for (i = 0; i < strlen(src); i++)
        {
               *(dest + *index) = src[i];
               *index += 1;
        }

	return (dest);
}

/**
 * set_size - Set a byte size from list of arguments.
 * @str: The length of argument list.
 *
 * Return: The size of of argument paramters.
*/

int set_size(const char *str, ...)
{
	/*store the buffer size of the whole arguments using index for interation*/
	int index, buffer_size;

	/*Argument parameters*/
	va_list ap;

	if (str == NULL)
		exit(1);

	/*Initialize argument list*/
	va_start(ap, str);

	buffer_size = sizeof(str);

	for (index = 0; index < strlen(str); index++)
	{
		if (str[index] == '%')

			switch(str[index + 1])
			{
			case 'c':
				buffer_size += sizeof(va_arg(ap, char));
				break;

			case 's':
                                buffer_size += sizeof(va_arg(ap, char*));
                                break;
			case 'd':
				buffer_size += sizeof(va_arg(ap, int));
				break;
			case 'i':
				buffer_size += sizeof(va_arg(ap, int));
				break;
			case 'u':
				buffer_size += sizeof(va_arg(ap, unsigned int));
				break;
			case 'p':
				buffer_size += sizeof(va_arg(ap, void *));
				break;
			case 'o':
				buffer_size += sizeof(va_arg(ap, char));
				break;
			}
	}

	va_end(ap);

	return (buffer_size);
}

/**
 * _printf - Print output according to a specified format.
 *
 * @format: The specified format string
 *
 * Return: The length of characters printed out.
 */

int _printf(const char *format, ...)
{
	/*interators*/
	int index = 0, index2 = 0;

	/*store the length argument of characters*/
	int length = 0;

	/* Allocates memory for list of arguments*/
	char *whole_buffer, *data_to_print;

	/*Argument parameters*/
	va_list ap;

	if (format == NULL)
		exit(1);


	whole_buffer = malloc(set_size(format));

	va_start(ap, format);

	copy_string(whole_buffer, format, &index);

	for (index2 = 0; index2 < strlen(format); index2++)
	{
		if (format[index2] == '%' && format[index2 + 1] == 'c')

			whole_buffer[index] = va_arg(ap, char);

		else if (format[index2] == '%' && format[index2 + 1] == 's')

			copy_string(whole_buffer, va_arg(ap, char*), &index);

		else if (format[index2] == '%' && format[index2 + 1] == 'd')

			whole_buffer[index] = va_arg(ap, int);

		else if (format[index2] == '%' && format[index2 + 1] == 'i')

			whole_buffer[index] = va_arg(ap, int);
	}

	/* For testing output whiles I code Function */

	while(*whole_buffer)
	{
		putchar(*whole_buffer);
		whole_buffer++;
	}


}

/* For testing function whiles i code it*/
int main(void)
{
	char *name = "Francis Ofori Anane";

	printf("%d\n", sizeof("Francis Ofori Anane"));
        _printf("Your Name is %s", name);

	return (0);
}
