#include "holberton.h"

/**
 * times_table - Print the ten times table
 */
void times_table(void)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			int prod = i * j;

			if (prod < 10)
			{
				if (j)
					_putchar(' ');
				_putchar('0' + prod);
			}
			else
			{
				_putchar('0' + (prod / 10));
				_putchar('0' + (prod % 10));
			}
			if (j < 9)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
