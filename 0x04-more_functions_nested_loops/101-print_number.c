#include "holberton.h"

/**
 * print_number - prints an integer
 * @n: An integer to be printed
 */
void print_number(int n)
{
	int m, l;

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
	while (m)
	{
		m /= 10;
		l *= 10;
	}

	m = n;
	while (l)
	{
		if (m / l)
			_putchar('0' + (m / l) % 10);
		l /= 10;
	}
}
