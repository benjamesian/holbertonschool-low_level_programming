#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - print strings
 * @separator: string separator
 * @n: number of strings to print
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list valist;
	unsigned int i;
	char *c;

	if (n == 0)
		return;

	if (separator == NULL)
		separator = "";

	va_start(valist, n);
	for (i = 1; i < n; i++)
	{
		c = va_arg(valist, char*);
		printf("%s%s", (c == NULL) ? "(nil)" : c, separator);
	}
	c = va_arg(valist, char*);
	printf("%s\n", (c == NULL) ? "(nil)" : c);

	va_end(valist);
}
