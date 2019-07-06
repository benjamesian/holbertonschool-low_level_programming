#include "holberton.h"

/**
 * print_number - Print an integer value to stdout
 * @n: Any integer
 */
void print_number(int n)
{
	int int_min_last;
	int is_int_min = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	if (n < 0)
	{
		_putchar('-');

		is_int_min = (n * -1 < 0);
		if (is_int_min)
		{
			int_min_last = n % 10;
			n /= 10;
		}
		n *= -1;
	}

	if (n / 10)
		print_number(n / 10);
	_putchar('0' + (n % 10));

	if (is_int_min)
		_putchar('0' + int_min_last);
}
