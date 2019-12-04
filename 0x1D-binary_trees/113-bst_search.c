#include "binary_trees.h"

/**
 * bst_search - find a node in a bst
 * @tree: bst to search
 * @value: value of node to find
 *
 * Return: Pointer to node with value, or NULL if no such node
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	while (tree)
	{
		if (value > tree->n)
			tree = tree->right;
		else if (value < tree->n)
			tree = tree->left;
		else
			return ((bst_t *) tree);
	}

	return (NULL);
}
