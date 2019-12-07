#include "binary_trees.h"

/**
 * heap_to_sorted_array - convert a heap to a sorted array
 * @heap: heap to convert
 * @size: size of the heap
 *
 * Return: array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array, value;

	array = malloc(sizeof(*array) * (*size));
	if (!array)
		return (NULL);
	*size = *size - 1;
	while ((value = heap_extract(&heap)))
		*array++ = value;

	return (array);
}
