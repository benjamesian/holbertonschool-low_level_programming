#include "binary_trees.h"

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *p;
	if (!tree)
		return (NULL);

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;

	p = *tree;
	if (!p)
		*tree = new;
	else
	{
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
	}

	return (new);
}
