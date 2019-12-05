#include "binary_trees.h"

/**
 * pq_add - add a node to a priority queue
 * @pq: queue to add node to
 * @priority: priority of the new node
 * @value: data for the new node to hold
 *
 * Return: pointer to newly created node
 */
pq_t *pq_add(pq_t **pq, size_t priority, int value)
{
	pq_t *p, *new;

	if (!pq)
		return (NULL);

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->priority = priority;
	new->value = value;
	new->next = NULL;

	if (!*pq)
		*pq = new;
	else
	{
		p = *pq;
		while (p->next && p->next->priority < new->priority)
		{
			p = p->next;
		}

		if (p == *pq && p->priority > new->priority)
		{
			new->next = p;
			*pq = new;
		}
		else
		{
			new->next = p->next;
			p->next = new;
		}
	}

	return (new);
}

/**
 * pq_free - free a priority queue
 * @pq: queue to free
 */
void pq_free(pq_t *pq)
{
	if (!pq)
		return;
	pq_free(pq->next);
	free(pq);
}


/**
 * pq_apply - apply a function to all nodes in a priority queue in order
 * @pq: the queue
 * @func: function to apply to data of each node
 */
void pq_apply(pq_t *pq, void (*func)(int))
{
	while (pq)
	{
		func(pq->value);
		pq = pq->next;
	}
}

/**
 * build_pq - build a priority queue for easy level order traversal
 * @tree: binary tree to traverse
 * @pq: priority queue to construct
 * @priority: current priority level for a node
 */
void build_pq(const binary_tree_t *tree, pq_t **pq, size_t priority)
{
	if (!tree)
		return;
	pq_add(pq, priority, tree->n);
	build_pq(tree->left, pq, priority * 2);
	build_pq(tree->right, pq, priority * 2 + 1);
}

/**
 * binary_tree_levelorder - apply a function to a binary tree level-order
 * @tree: the tree
 * @func: function to apply to tree node data
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	pq_t *pq = NULL;

	if (!tree || !func)
		return;

	build_pq(tree, &pq, 1);

	pq_apply(pq, func);
	pq_free(pq);
}
