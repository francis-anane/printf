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

int print_char(char c)
{
	write(1, &c, 1);
	return (sizeof(c));
}

/**
 * print_int - print an integer value.
 *
 * @n: The value to print.
 *
 * Return: (1) for length.
 */

int print_int(int n)
{
	int i = 0, j = 0;
	int tmp = n;
	char *int_str;

	while ((tmp % 10) != 0)
	{
		tmp /= 10;
		i++;
	}
	int_str = malloc(i * (sizeof(n % 10) + '0'));
	while ((n % 10) != 0)
	{
		int_str[j] = (n % 10) + '0';
		n /= 10;
		j += 1;
	}

	/*print by reversing the string*/
	while (j >= 0)
	{
		write(1, &int_str[j], 1);
		j--;
	}
	free(int_str);
	return (1);
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
	int len = 0, i;
	char *str;

	if (format == NULL)
		return (-1);

	if (format[0] == '%' && strlen(format) == 1)
		return (-1);

	va_start(ap, format);

	/*print out data by format*/
	for (i = 0; i < (int) strlen(format); i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			len += print_char(va_arg(ap, int));
			i += 1;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(ap, char *);
			if (str == NULL)
				len += print_string("(null)");
			else
				len += print_string(str);
			i += 1;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			len += print_char('%');
			i += 1;
		}
		else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			len += print_int(va_arg(ap, int));
			i += 1;
		}
		else
			len += print_char(format[i]);
	}
	va_end(ap);
	return (len);
}
