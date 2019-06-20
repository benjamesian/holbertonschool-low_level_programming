#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print 2 digit numbers that don't each share the same digits
 * Return: 0
 */
int main(void)
{
	int a;
	int b;

	for (a = 0; a <= 99; a++)
	{
		for (b = a + 1; b <= 99; b++)
		{
			putchar('0' + a / 10);
			putchar('0' + a % 10);
			putchar(' ');
			putchar('0' + b / 10);
			putchar('0' + b % 10);
			if (!(a == 98 && b == 99))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
