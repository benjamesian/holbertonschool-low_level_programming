#include "holberton.h"

/**
 * print_rev - Print a string backwards
 * @s: A string
 */
void print_rev(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	while (i--)
		_putchar(s[i]);
	_putchar('\n');
}
