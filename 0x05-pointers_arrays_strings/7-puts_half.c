#include "holberton.h"

/**
 * puts_half - Write the second half of a string to stdout
 * @str: A string
 */
void puts_half(char *str)
{
	int len, i;

	for (len = 0; str[len] != '\0'; len++)
		;

	for (i = len / 2; i < len; i++)
		_putchar(str[i]);
	_putchar('\n');
}
