#include <stdio.h>

void print_array(int *a, int n)
{
	int i;

	for (i = n; i; i--)
	{
		printf("%d", a[n - i]);
		if (i)
			printf(", ");
	}
	putchar('\n');
}
