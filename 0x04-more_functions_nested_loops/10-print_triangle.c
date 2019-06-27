#include "holberton.h"

/**
 * print_triangle - prints a triangle, followed by a new line
 * @size: the width of the triangle
 */
void print_triangle(int size)
{
	int i, j;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = size - 1; i >= 0; i--)
	{
		for (j = 0; j < size; j++)
		{
			if (j < i)
				_putchar(' ');
			else
				_putchar('#');
		}
		_putchar('\n');
	}
}
