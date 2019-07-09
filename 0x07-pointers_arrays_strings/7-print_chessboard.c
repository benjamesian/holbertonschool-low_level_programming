#include "holberton.h"

/**
 * print_chessboard - print a chessboard
 * @a: board config
 */
void print_chessboard(char (*a)[8])
{
	int i, j;

	i = 0;
	while (8 - i)
	{
		j = 0;
		while (8 - j)
		{
			_putchar(a[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
}
