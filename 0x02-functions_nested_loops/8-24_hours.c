#include "holberton.h"

/**
 * jack_bauer - Print all hour/minute combos in ascending order
 *
 * Description: Print hour minute combos in ascending order separated by
 * new lines and in the format hh:mm
 */
void jack_bauer(void)
{
	int h, m;

	for (h = 0; h < 24; h++)
	{
		for (m = 0; m < 60; m++)
		{
			_putchar('0' + h / 10);
			_putchar('0' + h % 10);
			_putchar(':');
			_putchar('0' + m / 10);
			_putchar('0' + m % 10);
			_putchar('\n');
		}
	}
}
