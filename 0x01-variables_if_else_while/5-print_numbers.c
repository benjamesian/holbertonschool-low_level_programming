#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print every base 10 digit starting from 0 followed by a newline
 * Return: 0
 */
int main(void)
{
	char d;

	for (d = '0'; d <= '9'; d++)
		putchar(d);
	putchar('\n');

	return (0);
}
