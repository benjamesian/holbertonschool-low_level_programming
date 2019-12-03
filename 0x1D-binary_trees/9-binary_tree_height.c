#include "binary_trees.h"

/**
 * max - return max value
 * @a: a value
 * @b: another value
 *
 * Return: The maximum of a and b
 */
size_t max(size_t a, size_t b)
{
	return (a > b ? a : b);
}

/**
 * _binary_tree_height - get raw height of a binary tree
 * @tree: tree to find height of
 *
 * Return: the height of the tree.
 */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + max(
		_binary_tree_height(tree->left),
		_binary_tree_height(tree->right)));
}

/**
 * binary_tree_height - get height of a binary tree from a node
 * @tree: tree to find height of
 *
 * Return: the height of the tree from a node.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_binary_tree_height(tree) - 1);
}
