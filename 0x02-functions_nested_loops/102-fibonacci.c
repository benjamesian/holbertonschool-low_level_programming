#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print the first 50 fibonacci numbers
 * Return: 0 (Success)
 */
int main(void)
{
	long old = 0;
	long new = 1;
	long temp;
	int i = 50;

	while (i--)
	{
		temp = new;
		new += old;
		old = temp;
		printf("%ld", new);
		if (i)
			printf(", ");
	}
	printf("\n");

	return (0);
}
