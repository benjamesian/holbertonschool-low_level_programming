#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print every base 10 digit starting from 0 separated with a
 * comma and space followed by a newline
 * Return: 0
 */
int main(void)
{
	int d;

	for (d = 0; d <= 9; d++)
	{
		putchar('0' + d);
		if (d < 9)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');

	return (0);
}
