#include "holberton.h"

/**
 * print_numbers - Print the characters from '0' to '9' followed by a new line
 */
void print_numbers(void)
{
	int n;

	for (n = 0; n < 10; n++)
		_putchar('0' + n);
	_putchar('\n');
}
