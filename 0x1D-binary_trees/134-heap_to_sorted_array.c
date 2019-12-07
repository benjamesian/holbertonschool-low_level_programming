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
	heap_t *node;
	int *array;

	array = malloc(sizeof(*array) * (*size));
	if (!array)
		return (NULL);
	*size--;
	while ((node = heap_extract(&heap)))
		*array++ = node->n;

	return (array);
}
