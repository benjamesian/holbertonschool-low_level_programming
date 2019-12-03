#include "binary_trees.h"

/**
 * binary_tree_preorder - traverse a binary tree using pre-order traversal
 * @tree: tree to traverse
 * @func: function to call at each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return (NULL);

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
