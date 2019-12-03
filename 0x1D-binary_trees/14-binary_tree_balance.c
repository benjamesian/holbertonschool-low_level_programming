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
 * binary_tree_balance - Check if a binary tree is balanced.
 * @tree: tree to inspect
 *
 * Return: 1 if tree is balanced, else 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_binary_tree_height(tree->left) -
		_binary_tree_height(tree->right));
}
