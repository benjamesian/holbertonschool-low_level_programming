#include <stdio.h>

/**
 * print_diagsums - print sums of diagonals
 * @a: square array of numbers
 * @size: size of square
 */
void print_diagsums(int *a, int size)
{
	int t, sum1, sum2;
	int *p = a;

	t = size;
	sum1 = 0;
	sum2 = 0;
	while (t--)
	{
		sum1 += *p;
		p += size + 1;
	}

	t = size;
	p = a;
	while (t--)
	{
		p += size - 1;
		sum2 += *p;
	}

	printf("%d, %d\n", sum1, sum2);
}
