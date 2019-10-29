#include "sort.h"

/**
 * swap - Function that swaps two values
 *
 * @a: Fisrt value
 * @b: Second value
 * Return: 0
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/**
 * gap_sort - sort array with gaps
 * @array: array to be sorted
 * @size: size of array
 * @gap: gap size
 */
void gap_sort(int *array, size_t size, unsigned int gap)
{
	size_t j, k;

	for (j = gap; j < size; j++)
	{
		k = j;
		while (k >= gap && array[k] < array[k - gap])
		{
			swap(array + k, array + k - gap);
			k -= gap;
		}
	}
}

/**
 * _shell_sort - recursive shell sort
 * @array: array to be sorted
 * @size: size of array
 * @gap: gap size
 */
void _shell_sort(int *array, size_t size, unsigned int gap)
{
	if (gap >= size)
		return;

	_shell_sort(array, size, 3 * gap + 1);
	gap_sort(array, size, gap);
	print_array(array, size);
}

/**
 * shell_sort - initiate recursive shell sort
 * @array: array to be sorted
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	_shell_sort(array, size, 1);
}
