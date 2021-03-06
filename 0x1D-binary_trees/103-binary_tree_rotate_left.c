#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate binary tree left
 * @tree: tree to rotate
 *
 * Return: Pointer to new head node.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (!tree || !tree->right)
		return (tree);

	if (tree->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = tree->right;
		else
			tree->parent->right = tree->right;
		tree->right->parent = tree->parent;
	}
	else
		tree->right->parent = NULL;

	tree->parent = tree->right;
	tree->right = tree->right->left;
	if (tree->right)
		tree->right->parent = tree;
	tree->parent->left = tree;

	return (tree->parent);
}
