#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print every letter in the alphabet in reverse order followed by
 * a newline
 * Return: 0
 */
int main(void)
{
	char letter;

	for (letter = 'z'; letter >= 'a'; letter--)
		putchar(letter);
	putchar('\n');

	return (0);
}
