#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - print all
 * @format: list of argument types
 */
void print_all(const char * const format, ...)
{
	va_list valist;
	unsigned int _len;
	char *s;

	va_start(valist, format);

	_len = 0;
	while (format && format[_len])
	{
		switch (format[_len++])
		{
		case 'c':
			printf("%c", va_arg(valist, int));
			break;
		case 'i':
			printf("%d", va_arg(valist, int));
			break;
		case 'f':
			printf("%f", va_arg(valist, double));
			break;
		case 's':
			s = va_arg(valist, char *);
			if (!s)
			{
				printf("(nil)");
				break;
			}
			printf("%s", s);
			break;
		default:
			continue;
		}
		if (format[_len])
			printf(", ");
	}

	va_end(valist);

	printf("\n");
}
