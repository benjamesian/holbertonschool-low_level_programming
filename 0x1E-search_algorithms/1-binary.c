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
	size_t i, j, low = 0, high = size - 1;

	if (!array)
		return (-1);
	while (low <= high)
	{
		printf("Searching in array: ");
		for (j = low; j <= high; j++)
		{
			printf("%d", array[j]);
			if (j < high)
				printf(", ");
		}
		printf("\n");

		i = low + (high - low) / 2;
		if (array[i] == value)
			return (i);
		else if (array[i] < value)
			low = i + 1;
		else
			high = i - 1;
	}

	return (-1);
}
