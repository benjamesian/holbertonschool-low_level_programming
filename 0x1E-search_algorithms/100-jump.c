#include "search_algos.h"
#include <math.h>

/**
 * jump_search - jump search algorithm
 * @array: array to search
 * @size: size of the array
 * @value: value to search for
 *
 * Return: first index where value is found or -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i = 0, s;

	if (!array)
		return (-1);
	else if (size == 1)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		printf("Value found between indexes [%d] and [%d]\n", 0, 1);
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		return (array[0] == value ? 0 : -1);
	}

	s = sqrt(size);
	while (i < size && array[i] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		i += s;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", i - s, i);
	if (i >= size)
		printf("Value checked array[%lu] = [%d]\n", i - s, array[i - s]);
	else
	{
		i -= s;
		do {
			printf("Value checked array[%lu] = [%d]\n", i, array[i]);
			if (array[i] == value)
				return (i);
			i++;
		} while (s-- && i < size);
	}

	return (-1);
}
