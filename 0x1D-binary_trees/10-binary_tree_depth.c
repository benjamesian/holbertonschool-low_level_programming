#include "binary_trees.h"

/**
 * binary_tree_depth - get the depth of a binary tree node
 * @tree: node to find the depth of
 *
 * Return: depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}
