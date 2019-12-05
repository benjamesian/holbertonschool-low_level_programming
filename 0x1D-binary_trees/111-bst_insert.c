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
				if (!p->left)
				{
					p->left = new;
					new->parent = p;
					break;
				}
				p = p->left;
			}
			else if (value > p->n)
			{
				if (!p->right)
				{
					p->right = new;
					new->parent = p;
					break;
				}
				p = p->right;
			}
			else
			{
				free(new);
				return (NULL);
			}
		}
	return (new);
}
