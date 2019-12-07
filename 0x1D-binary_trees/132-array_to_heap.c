#include "binary_trees.h"

/**
 * array_to_heap - convert an array into a max heap
 * @array: array to convert
 * @size: size of the array
 *
 * Return: root element of the new heap
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);
	return (root);
}
