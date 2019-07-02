#include "holberton.h"

/**
 * puts2 - Write every other letter in a string to stdout
 * @str: A string
 */
void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (!(i % 2))
			_putchar(str[i]);
	_putchar('\n');
}
