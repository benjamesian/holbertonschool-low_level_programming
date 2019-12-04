#include "binary_trees.h"
#include <limits.h>

/**
 * _binary_tree_is_bst - recursively check if a binary tree is a bst
 * @tree: tree to inspect
 * @max_right: max value a right node can hold
 * @min_left: min value a left child can have
 *
 * Return: 1 if tree is a bst, else 0
 */
int _binary_tree_is_bst(const binary_tree_t *tree, int max_right, int min_left)
{
	if (!tree)
		return (1);
	if (tree->left && (tree->left->n > tree->n || tree->left->n < min_left))
		return (0);
	if (tree->right && (tree->right->n < tree->n || tree->right->n > max_right))
		return (0);
	return (_binary_tree_is_bst(tree->left, tree->n, min_left)
		&& _binary_tree_is_bst(tree->right, max_right, tree->n));
}

/**
 * binary_tree_is_bst - check if a binary tree is a bst
 * @tree: tree to inspect
 *
 * Return: 1 if tree is a bst, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_binary_tree_is_bst(tree, INT_MAX, INT_MIN));
}
