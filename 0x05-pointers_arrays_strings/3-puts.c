#include "holberton.h"

/**
 * _puts - Write a string to stdout
 * @str: A string
 */
void _puts(char *str)
{
	int l;

	for (l = 0; str[l] != '\0'; l++)
		_putchar(str[l]);
	_putchar('\n');
}
