#include "search_algos.h"

/**
 * advanced_binary - binary search algorithm
 * @array: array to search
 * @size: size of the array
 * @value: value to search for
 *
 * Return: first index where value is found or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, mid = size / 2;
	int out;

	if (size == 0)
		return (-1);
	else if (size == 1)
		return (array[0] == value ? 0 : -1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");

	if (array[mid] >= value)
		out = advanced_binary(array, mid + 1, value);
	else
	{
		out = advanced_binary(array + mid + 1, size - (mid + 1), value);
		if (out != -1)
			out += mid + 1;
	}

	return (out);
}
