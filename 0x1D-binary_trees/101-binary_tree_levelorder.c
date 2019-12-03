#include "binary_trees.h"

const binary_tree_t *has_children(const binary_tree_t *node)
{
	if (node->left || node->right)
		return (node);
	return (NULL);
}

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *left, *right;

	if (!tree)
		return;

	func(tree->n);
	if (tree->left)
	{
		func(tree->left->n);
		left = has_children(tree->left);
	}
	if (tree->right)
	{
		func(tree->right->n);
		right = has_children(tree->right);
	}
	
}
