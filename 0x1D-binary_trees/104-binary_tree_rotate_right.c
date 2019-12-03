#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (!tree || !tree->left)
		return (tree);

	tree->parent = tree->left;
	tree->left = tree->left->right;
	if (tree->left)
		tree->left->parent = tree;
	tree->parent->right = tree;
	tree->parent->parent = NULL;

	return (tree->parent);
}
