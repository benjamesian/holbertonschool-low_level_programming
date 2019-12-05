#include "binary_trees.h"

/**
 * _binary_tree_is_bst - recursively check if a binary tree is a bst
 * @node: node to inspect
 * @prev: a parent of the current node or the same as node
 *
 * Return: 1 if tree is a bst, else 0
 */
int _binary_tree_is_bst(const binary_tree_t *node, const binary_tree_t *prev)
{
	if (!node)
		return (1);

	if (node->n == prev->n)
	{
		if ((node->left && node->left->n > prev->n)
			|| (node->right && node->right->n < prev->n))
			return (0);
	}
	else if (node->n < prev->n)
	{
		if ((node->left && node->left->n > prev->n)
			|| (node->right && node->right->n > prev->n))
			return (0);
	}
	else
	{
		if ((node->left && node->left->n < prev->n)
			|| (node->right && node->right->n < prev->n))
			return (0);
	}
	return (_binary_tree_is_bst(node->left, prev) && _binary_tree_is_bst(node->right, prev));
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
		return (1);

	return (_binary_tree_is_bst(tree, tree) && _binary_tree_is_bst(tree->left, tree->left) && _binary_tree_is_bst(tree->right, tree->right));
}
