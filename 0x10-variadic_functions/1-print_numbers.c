#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - print numbers
 * @separator: separator for printing
 * @n: amount of numbers to print
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list valist;
	unsigned int i;

	if (n == 0)
	{
		putchar('\n');
		return;
	}

	if (!separator)
		separator = "";

	va_start(valist, n);

	for (i = 1; i < n; i++)
		printf("%d%s", va_arg(valist, int), separator);
	printf("%d\n", va_arg(valist, int));

	va_end(valist);
}
