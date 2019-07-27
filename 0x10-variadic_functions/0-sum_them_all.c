#include <stdarg.h>

/**
 * sum_them_all - sum args
 * @n: number of integers to sum
 *
 * Return: sum of the integers
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum;
	va_list valist;

	if (n == 0)
		return (0);

	va_start(valist, n);

	sum = 0;
	for (i = 0; i < n; i++)
		sum += va_arg(valist, int);

	va_end(valist);

	return (sum);
}
