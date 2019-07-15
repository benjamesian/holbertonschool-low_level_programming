#include <stdlib.h>

/**
 * free_grid - free memory allocated for a 2-d grid
 * @grid: grid to free
 * @height: number of arrays in grid
 */
void free_grid(int **grid, int height)
{
	int **tmp = grid;

	while (height--)
		free(*grid++);

	free(tmp);
}
