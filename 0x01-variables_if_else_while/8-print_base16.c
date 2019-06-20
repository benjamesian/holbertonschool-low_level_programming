#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print every base 16 number in lowercase and then in uppercase
 * followed by a newline
 * Return: 0
 */
int main(void)
{
	char letter;

	for (letter = '0'; letter <= '9'; letter++)
		putchar(letter);
	for (letter = 'a'; letter <= 'f'; letter++)
		putchar(letter);
	putchar('\n');

	return (0);
}
