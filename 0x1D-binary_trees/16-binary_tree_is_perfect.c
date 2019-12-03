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
 * _binary_tree_is_perfect - check if a binary tree is perfect recursively
 * @tree: tree to inspect
 * @height: expected height of the tree from current node
 *
 * Return: 1 if tree is perfect, else 0
 */
int _binary_tree_is_perfect(const binary_tree_t *tree, size_t height)
{
	if (!tree)
		return (height == 0);
	else if (height == 1)
		return (!tree->left && !tree->right);
	else if (!tree->left || !tree->right)
		return (0);
	return (_binary_tree_is_perfect(tree->left, height - 1)
		&& _binary_tree_is_perfect(tree->right, height - 1));
}

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: tree to inspect
 *
 * Return: 1 if tree is perfect, else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;

	if (!tree)
		return (0);
	height = _binary_tree_height(tree);

	return (_binary_tree_is_perfect(tree, height));
}
