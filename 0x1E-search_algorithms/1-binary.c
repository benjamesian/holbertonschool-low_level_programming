#include "search_algos.h"

/**
 * binary_search - binary search algorithm
 * @array: array to search
 * @size: size of the array
 * @value: value to search for
 *
 * Return: some index where value is found or -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i, low = 0, high = size;

	while (low < high)
	{
		i = (high - low) / 2;
		if (array[low + i] == value)
			return (i);
		else if (array[i] < value)
			low = i + 1;
		else
			high = i - 1;
	}

	return (-1);
}
