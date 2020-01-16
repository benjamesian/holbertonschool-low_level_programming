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
	size_t l = 0, m, h = size - 1;

	if (size < 1)
		return (-1);
	else if (size == 1)
	{
		printf("Value checked array[%d] = [%d]\n", 0, array[0]);
		return (value == array[0] ? 0 : -1);
	}

	while (array[h] != array[l] && value >= array[l] && value <= array[h])
	{
		m = l + (((double)(h - l) / (array[h] - array[l])) * (value - array[l]));
		if (m >= size)
		{
			printf("Value checked array[%lu] is out of range\n", l);
			break;
		}

		printf("Value checked array[%lu] = [%d]\n", m, array[m]);
		if (array[m] < value)
			l = m + 1;
		else if (value < array[m])
			h = m - 1;
		else
			return (m);
	}

	return (-1);
}
