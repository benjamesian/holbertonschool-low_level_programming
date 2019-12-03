#include "binary_trees.h"

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *p;
	if (!tree)
		return (NULL);

	new = malloc(sizeof(*new));
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;

	p = *tree;
	if (!p)
		*tree = new;
	else
	{
		if (p->n < new->n)
		{
			new->left = p;
			new->left->parent = new;
			new->right = p->right;
			if (new->right)
				new->right->parent = new;
			p->right = NULL;
			*tree = new;
		}
		while (p->left && new->n < p->left->n)
		{
			p = p->left;
		}

	}
}
