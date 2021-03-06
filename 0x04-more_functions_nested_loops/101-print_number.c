#include "holberton.h"

/**
 * print_number - prints an integer
 * @n: An integer to be printed
 */
void print_number(int n)
{
	int m, l, is_smallest;

	is_smallest = (n != 0 && -n == n);
	if (is_smallest)
		n += 1;
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	else if (n == 0)
	{
		_putchar('0');
		return;
	}

	m = n;
	l = 1;
	while (m / 10)
	{
		m /= 10;
		l *= 10;
	}

	m = n;
	while (l)
	{
		int q = m / l;

		if (q)
		{
			if (is_smallest && !(l / 10))
				_putchar('0' + (q % 10) + 1);
			else
				_putchar('0' + q % 10);
		}
		l /= 10;
	}
}
