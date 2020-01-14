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
	size_t a = 0, b, skkrt = sqrt(size);

	b = skkrt;
	while (array[(b < size ? b : size) - 1] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", a, array[a]);
		a = b;
		b += skkrt;
		if (a >= size)
			break;
	}
	if (a > 0)
	{
		a -= skkrt;
		b -= skkrt;
	}
	else
		printf("Value checked array[%lu] = [%d]\n", a, array[a]);

	printf("Value found between indexes [%lu] and [%lu]\n", a, b);
	b = (b < size) ? b : size;
	while (array[a] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", a, array[a]);
		a += 1;
		if (a == b)
			break;
	}

	if (array[a] == value)
	{
		printf("Value checked array[%lu] = [%d]\n", a, array[a]);
		return (a);
	}
	return (-1);
}
