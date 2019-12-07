#include "binary_trees.h"

/**
 * __binary_tree_size - get the size of a binary tree
 * @tree: tree to find the size of
 *
 * Return: size of the tree.
 */
size_t __binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 +
		__binary_tree_size(tree->left) +
		__binary_tree_size(tree->right));
}

/**
 * heap_to_sorted_array - convert a heap to a sorted array
 * @heap: heap to convert
 * @size: size of the heap
 *
 * Return: array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i;

	if (!heap)
		return (NULL);

	i = __binary_tree_size(heap);
	array = malloc(sizeof(*array) * i);
	if (!array)
		return (NULL);
	*size = i;
	for (i = 0; i < *size; i++)
		array[i] = heap_extract(&heap);
	
	return (array);
}
