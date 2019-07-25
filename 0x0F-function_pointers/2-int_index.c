#include <stdlib.h>

/**
 * int_index - search for an integer
 * @array: array to search
 * @size: size of the array
 * @cmp: comparison function
 *
 * Return: index of match or -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(arr[i]))
			return (i);
	}

	return (-1);
}
