#include "search_algos.h"

/**
 * interpolation_search - interpolation search algorithm
 * @array: array to search
 * @size: size of the array
 * @value: value to search for
 *
 * Return: some index where value is found or -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t l = 0, h = size - 1;

	while (l < size && array[h] != array[l])
	{
		l += (((double)(h - l) / (array[h] - array[l])) * (value - array[l]));
		if (l < size)
			printf("Value checked array[%lu] = [%d]\n", l, array[l]);
		else
		{
			printf("Value checked array[%lu] is out of range\n", l);
			break;
		}

		if (array[l] == value)
			return (l);
	}

	return (-1);
}
