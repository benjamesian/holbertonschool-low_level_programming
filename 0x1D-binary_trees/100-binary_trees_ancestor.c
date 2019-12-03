#include "binary_trees.h"

/**
 * binary_tree_depth - get the depth of a binary tree node
 * @tree: node to find the depth of
 *
 * Return: depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}

/**
 * binary_trees_ancestor - find common ancestor of 2 nodes
 * @first: a node
 * @second: another node
 *
 * Return: pointer to common ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t left, right;

	if (!first || !second)
		return (NULL);

	left = binary_tree_depth(first);
	right = binary_tree_depth(second);

	while (left != right)
	{
		if (left > right)
		{
			left--;
			first = first->parent;
		}
		else
		{
			right--;
			second = second->parent;
		}
	}

	while (first && second)
	{
		if (first == second)
			return (first);
		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
