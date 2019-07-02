#include <stdio.h>

/**
 * print_array - print all the numbers in an array separated by commas
 * @a: an array of numbers
 * @n: The length of the provided array
 */
void print_array(int *a, int n)
{
	int i;

	for (i = n; i; i--)
	{
		printf("%d", a[n - i]);
		if (i - 1)
			printf(", ");
	}
	putchar('\n');
}
