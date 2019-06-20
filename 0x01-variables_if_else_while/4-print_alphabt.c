#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print every letter in the alphabet except 'e' and 'q' followed
 * by a newline
 * Return: 0
 */
int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		if (letter != 'e' && letter != 'q')
			putchar(letter);
	}
	putchar('\n');

	return (0);
}
