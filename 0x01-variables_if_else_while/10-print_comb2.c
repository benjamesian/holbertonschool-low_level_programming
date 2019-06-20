#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print every base 10 number starting from 0 up to 100 separated
 * with a comma and space followed by a newline
 * Return: 0
 */
int main(void)
{
	int t;
	int d;

	for (t = 0; t <= 9; t++)
	{
		for (d = 0; d <= 9; d++)
		{
			putchar('0' + t);
			putchar('0' + d);
			if (!(t == 9 && d == 9))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
