#include "binary_trees.h"

/**
 * bst_insert - insert a node into a bst
 * @tree: tree to insert node into
 * @value: value for new node to hold
 *
 * Return: pointer to new node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *p;

	if (!tree)
		return (NULL);
	new = binary_tree_node(NULL, value);
	if (!new)
		return (NULL);
	p = *tree;
	if (!p)
		*tree = new;
	else
		while (p)
		{
			if (value < p->n)
			{
				if (p->left)
					p = p->left;
				else
				{
					p->left = new;
					new->parent = p;
					break;
				}
			}
			else if (value > p->n)
			{
				if (p->right)
					p = p->right;
				else
				{
					p->right = new;
					new->parent = p;
					break;
				}
			}
			else
				return (NULL);
		}
	return (new);
}
