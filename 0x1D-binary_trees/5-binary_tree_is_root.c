#include "binary_trees.h"

/**
 * binary_tree_is_root - check if a node is the root node in a tree
 * @node: node which may be root
 *
 * Return: 1 if the node is the root node, else 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node && !node->parent);
}
