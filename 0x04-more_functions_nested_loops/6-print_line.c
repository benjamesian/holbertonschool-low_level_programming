#include "holberton.h"

/**
 * print_line - draws a straight line in the terminal
 * @n: The length of the line
 *
 * Description: The line will be n underscores and will be followed by a new
 * line, negative numbers and 0 will result in a new line being printed
 */
void print_line(int n)
{
	int c;

	if (n > 0)
		for (c = 0; c < n; c++)
			_putchar('_');
	_putchar('\n');
}
