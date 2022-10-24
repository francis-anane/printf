#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * print_string - print a string of characters
 *
 * @str: The string to print.
 *
 * Return: The length of the string.
 */

int print_string(char *str)
{
	int len;
	char c;

	if (str == NULL)
		return (0);

	for (len = 0; len < (int) strlen(str); len++)
	{
		c = str[len];
		write(1, &c, 1);
	}

	return (len);
}

/**
 * print_char - print a single character.
 *
 * @c: The character to print.
 *
 * Return: (1) for character byte size.
 */

size_t print_char(char c)
{
	write(1, &c, 1);
	return (sizeof(c));
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
	va_list ap;

	int len = 0, index;

	if(format == NULL)
		return(0);

	va_start(ap, format);

	/*print out data by format*/
	for(index = 0; index < (int) strlen(format); index++)
	{
		if(format[index] == '%' && format[index +1] == 'c')
		{
			len += print_char(va_arg(ap, int));
			index += 1;
		}

		else if(format[index] == '%' && format[index +1] == 's')
		{
			len += print_string(va_arg(ap, char*));
			index += 1;
		}

		else if(format[index] == '%' && format[index +1] == '%')
		{
			len += print_char('%');
			index += 1;
		}
		else
			len += print_char(format[index]);
	}

	va_end(ap);

	return (len);
}
