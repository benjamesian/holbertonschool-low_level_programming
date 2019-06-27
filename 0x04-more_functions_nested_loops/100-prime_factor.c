#include <stdio.h>
#include <math.h>
#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int i;
	long n = 612852475143;
	long m = (long) pow(n, 0.5);

	for (i = m; i > 0; i--)
	{
		if (!(n % i))
		{
			printf("%d\n", i);
			break;
		}
	}

	return (0);
}
