#include "holberton.h"

/**
 * print_alphabet - Print all lowercase letters
 *
 * Description: Print all lowercase letters in ascending order
 * Return: void
 */
void print_alphabet(void)
{
	char a;

	for (a = 'a'; a <= 'z'; a++)
		_putchar(a);
	_putchar('\n');
}
