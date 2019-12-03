#include "binary_trees.h"

int _binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	return (_binary_tree_is_bst(tree->left)
		&& _binary_tree_is_bst(tree->right));

}

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_binary_tree_is_bst(tree));
}
