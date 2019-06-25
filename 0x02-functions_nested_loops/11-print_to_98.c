#include <stdio.h>

/**
 * print_to_98 - Print numbers from th provided number to 98
 * @n: Any integer
 *
 * Description: If n is less than 98 print all numbers from n to 98 in
 * ascending order separated by ", ", otherwise print all numbers from n to 98
 * in descending order
 */
void print_to_98(int n)
{
	int m;

	if (n < 98)
	{
		for (m = n; m < 98; m++)
			printf("%d, ", m);
	}
	else if (n > 98)
	{
		for (m = n; m > 98; m--)
			printf("%d, ", m);
	}
	printf("98\n");
}
