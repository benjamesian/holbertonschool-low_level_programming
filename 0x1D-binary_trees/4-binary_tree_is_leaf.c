#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if a node in a binary tree is a leaf
 * @node: node to inspect
 *
 * Return: 1 if node is a leaf, else 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node && !node->left && !node->right);
}
