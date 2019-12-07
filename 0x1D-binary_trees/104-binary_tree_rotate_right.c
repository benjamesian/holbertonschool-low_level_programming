#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate binary tree right
 * @tree: tree to rotate
 *
 * Return: Pointer to new head node.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (!tree || !tree->left)
		return (tree);

	if (tree->parent)
		tree->parent->left = tree->left;
	else
		tree->left->parent = NULL;

	tree->parent = tree->left;
	tree->left = tree->left->right;
	if (tree->left)
		tree->left->parent = tree;
	tree->parent->right = tree;

	return (tree->parent);
}
