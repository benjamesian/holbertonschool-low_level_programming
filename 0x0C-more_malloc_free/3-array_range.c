#include <stdlib.h>

/**
 * array_range - create an array of integers
 * @min: smallest int in array
 * @max: largest int in array
 *
 * Return: pointer to start of array
 */
int *array_range(int min, int max)
{
	int *arr;
	size_t els, i;

	if (min > max)
		return (NULL);

	els = max - min + 1;
	arr = malloc(sizeof(*arr) * els);
	if (arr == NULL)
		return (NULL);

	i = 0;
	while (i < els)
	{
		arr[i] = min + i;
		i++;
	}

	return (arr);
}
