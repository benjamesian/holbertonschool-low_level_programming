#include "binary_trees.h"

/**
 * binary_tree_sibling - get the sibling of a node in a binary tree
 * @node: node to find sibling of
 *
 * Return: pointer to sibling of node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return ((node->parent->left == node)
		? node->parent->right
		: node->parent->left);
}

/**
 * binary_tree_uncle - get the uncle of a node in a binary tree
 * @node: node to find uncle of
 *
 * Return: pointer to uncle of node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
