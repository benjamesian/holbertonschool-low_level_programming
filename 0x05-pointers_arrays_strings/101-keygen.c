#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

/**
 * main - entry point
 * Return: 0 (Success)
 */
int main(void)
{
	double d, rd;
	int c;
	int sum = 0;

	srand(time(0));

	while (1)
	{
		rd = ((double) rand()) / ((double) RAND_MAX);
		d = 93.0 * rd + 33.0;
		c = (int) d;

		if (sum + c < 2772)
		{
			sum += c;
			putchar(c);
		}
		else
			break;
	}
	putchar(2772 - sum);

	return (0);
}
