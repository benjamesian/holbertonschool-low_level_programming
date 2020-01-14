#include "search_algos.h"

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
