#include "binary_trees.h"

/**
 * binary_tree_nodes - count number of nodes (not leaves) in a tree
 * @tree: root of the tree
 *
 * Return: number of nodes in the tree.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->left || tree->right)
		return (1 +
			binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));

	return (binary_tree_nodes(tree->left) +
		binary_tree_nodes(tree->right));
}
