#include "binary_trees.h"

/**
 * array_to_bst - convert an array into a binary search tree
 * @array: array to convert
 * @size: size of the array
 *
 * Return: pointer to root of newly created bst
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *node = NULL;
	size_t i;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
		bst_insert(&node, array[i]);

	return (node);
}
