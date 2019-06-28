#include "holberton.h"

/**
 * print_number - prints an integer
 * @n: An integer to be printed
 */
void print_number(int n)
{
	int m, l, is_smallest, last;

	is_smallest = (n != 0 && -n == n);
	if (is_smallest)
	{
		last = -(n % 10);
		n /= 10;
	}

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
			_putchar('0' + q % 10);
		}
		l /= 10;
	}
	if (is_smallest)
		_putchar('0' + last);
}
