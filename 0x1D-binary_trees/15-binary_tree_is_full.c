#include "binary_trees.h"

/**
 * node_full - check if a node has 0 or 2 children
 * @tree: node to inspect
 *
 * Return: 1 if the node has 0 or 2 children, else 0
 */
int node_full(const binary_tree_t *tree)
{
	return ((tree->left && tree->right) ||
		(!tree->left && !tree->right));
}

/**
 * _binary_tree_is_full - check if a binary tree is full recursively
 * @tree: tree to inspect
 *
 * Return: 1 if tree is full, else 0
 */
int _binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	return (node_full(tree)
		&& _binary_tree_is_full(tree->left)
		&& _binary_tree_is_full(tree->right));
}

/**
 * binary_tree_is_full - check if a binary tree is full
 * @tree: tree to inspect
 *
 * Return: 1 if tree is full, else 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_binary_tree_is_full(tree));
}
