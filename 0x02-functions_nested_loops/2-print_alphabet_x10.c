#include "holberton.h"

/**
 * print_alphabet_x10 - Print the alphabet ten times
 *
 * Description: Print the alphabet in ascending order ten times on different
 * lines
 */
void print_alphabet_x10(void)
{
	char a;
	int i = 10;

	while (i--)
	{
		for (a = 'a'; a <= 'z'; a++)
			_putchar(a);
		_putchar('\n');
	}
}
