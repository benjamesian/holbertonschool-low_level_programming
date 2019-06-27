#include "holberton.h"

/**
 * print_triangle - prints a triangle, followed by a new line
 * @size: the width of the triangle
 */
void print_triangle(int size)
{
	int i, j;

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
