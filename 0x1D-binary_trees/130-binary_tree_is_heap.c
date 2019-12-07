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
 * binary_tree_is_complete - check if binary tree is complete
 * @tree: tree to inspect
 *
 * Return: 1 if complete, else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	pq_t *pq = NULL, *p;

	if (!tree)
		return (0);

	build_pq(tree, &pq, 1);

	p = pq;
	while (pq && pq->next)
	{
		if (pq->next->priority - pq->priority > 1)
		{
			while (p)
			{
				pq = p;
				p = p->next;
				free(pq);
			}
			return (0);
		}

		pq = pq->next;
	}

	while (p)
	{
		pq = p;
		p = p->next;
		free(pq);
	}
	return (1);
}

/**
 * _binary_tree_is_heap - recursively check if a binary tree is a heap
 * @tree: tree to inspect
 *
 * Return: 1 if tree is a heap, else 0
 */
int _binary_tree_is_heap(const binary_tree_t *tree)
{
	return ((tree->left ? tree->n > tree->left->n
			&& _binary_tree_is_heap(tree->left) : 1)
		&& (tree->right ? tree->n > tree->right->n
			&& _binary_tree_is_heap(tree->right) : 1));
}

/**
 * binary_tree_is_heap - check if a binary tree is a heap
 * @tree: tree to inspect
 *
 * Return: 1 if tree is a heap, else 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_is_complete(tree) && _binary_tree_is_heap(tree));
}
