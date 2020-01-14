#include "search_algos.h"

/**
 * linear_search - linear search algorithm
 * @array: array to search
 * @size: size of the array
 * @value: value to search for
 *
 * Return: first index where value is found or -1
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%d] = [%zu]", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
