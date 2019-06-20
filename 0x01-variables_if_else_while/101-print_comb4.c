#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print 2 digit numbers that don't each share the same digits
 * Return: 0
 */
int main(void)
{
	int h;
	int t;
	int d;

	for (h = 0; h <= 9; h++)
	{
		for (t = h + 1; t <= 9; t++)
		{
			for (d = t + 1; d <= 9; d++)
			{
				putchar('0' + h);
				putchar('0' + t);
				putchar('0' + d);
				if (!(h == 7 && t == 8 && d == 9))
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');

	return (0);
}
