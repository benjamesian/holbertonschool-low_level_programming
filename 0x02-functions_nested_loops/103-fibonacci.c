#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print the sum of all even fibonacci numbers that do not exceed
 * 4,000,000
 * Return: 0 (Success)
 */
int main(void)
{
	unsigned int old = 0;
	unsigned int new = 1;
	unsigned int temp;
	unsigned long sum = 0;

	while (old < 4000000)
	{
		temp = new;
		new += old;
		old = temp;
		if (!(new % 2))
			sum += new;
	}

	printf("%lu\n", sum);

	return (0);
}
