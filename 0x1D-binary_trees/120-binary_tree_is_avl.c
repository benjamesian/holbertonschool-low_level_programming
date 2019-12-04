#include "binary_trees.h"
#include <limits.h>

/**
 * _binary_tree_height - get raw height of a binary tree
 * @tree: tree to find height of
 *
 * Return: the height of the tree.
 */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t a, b;

	if (!tree)
		return (0);

	a = _binary_tree_height(tree->left);
	b = _binary_tree_height(tree->right);
	return (1 + (a > b ? a : b));
}

/**
 * binary_tree_balance - Check if a binary tree is balanced.
 * @tree: tree to inspect
 *
 * Return: balance factor of a binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_binary_tree_height(tree->left) -
		_binary_tree_height(tree->right));
}

int _binary_tree_is_bst(const binary_tree_t *tree, int max_right, int min_left)
{
	if (!tree)
		return (1);
	if (tree->left && tree->left->n < min_left)
		return (0);
	if (tree->right && tree->right->n > max_right)
		return (0);
	return (_binary_tree_is_bst(tree->left, tree->n, min_left)
		&& _binary_tree_is_bst(tree->right, max_right, tree->n));

}

int _binary_tree_is_avl(const binary_tree_t *tree)
{
	int a;

	if (!tree)
		return (1);

	a = binary_tree_balance(tree->left) - binary_tree_balance(tree->right);
	if (a * a > 1)
		return (0);

	return (_binary_tree_is_avl(tree->left) && _binary_tree_is_avl(tree->right));
}

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_binary_tree_is_bst(tree, INT_MAX, INT_MIN) && _binary_tree_is_avl(tree));
}
