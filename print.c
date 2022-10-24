#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int _printf(const char *format, ...)
{
	va_list ap;
	int len = 0, i;

	if(format == NULL)
		return(0);

	va_start(ap, format);

	for(i = 0; i <strlen(format); i++)
	{
		if(format[i] == '%')
			switch(format[i + 1])
			{
			case 'c':
				putchar(va_arg(ap, int));
				len += 1;
				break;
			case 's':
				len += printf("%s", va_arg(ap, char*));
				break;
			}
		else
		{
			putchar(format[i]);
			len += 1;
		}
	}

	va_end(ap);

	return (len);
}

int main(void)
{
	char *fname = "Francis";
	char *lname = "Anane";
	char c = 'c';


	_printf("My first name is %s and last name is %s %c.", fname, lname, c);

	return (0);
}
