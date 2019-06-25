#include "holberton.h"

void print_times_table(int n)
{
	int i, j, h, t, o, prod;

	if (n > 15 || n < 0)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			prod = i * j;
			o = prod % 10;

			if (prod)
			{
				h = prod / 100;
				t = (prod / 10) % 10;
				_putchar(h ? '0' + h : ' ');
				_putchar((h || t) ? '0' + t : ' ');
			}
			else if (j)
			{
				_putchar(' ');
				_putchar(' ');
			}
			_putchar('0' + o);

			if (j < n)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
