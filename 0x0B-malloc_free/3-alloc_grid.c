#include <stdlib.h>

/**
 * alloc_grid  -make a 2-d array
 * @width: width
 * @height: height
 *
 * Return: pointer to grid
 */
int **alloc_grid(int width, int height)
{
	int **grid, **tmp;
	int *row;
	int i, j;

	if (width < 1 || height < 1)
		return (NULL);

	grid = malloc(height * sizeof(row));
	if (!grid)
		return (NULL);
	tmp = grid;

	j = height;
	while (j--)
	{
		row = malloc(width * sizeof(*row));
		if (!row)
			return (NULL);
		*grid++ = row;
		for (i = 0; i < width; i++)
			row[i] = 0;
	}

	return (tmp);
}
