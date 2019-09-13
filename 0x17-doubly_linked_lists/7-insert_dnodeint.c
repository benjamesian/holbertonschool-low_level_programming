#include "lists.h"

/**
 * insert_dnodeint_at_index - inset a new node at a given position
 * @h: a node in a dlistint list
 * @idx: index in dlistint list at which to insert new node
 * @n: data for newly created node
 *
 * Return: address of newly created node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *p, *last = NULL;
	unsigned int i = idx;

	if (!h)
		return (NULL);

	p = *h;
	while (p && p->prev)
		p = p->prev;

	while (p && idx)
	{
		last = p;
		p = p->next;
		idx--;
	}

	if (idx != 0)
		return (NULL);

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = p;
	new->prev = last;

	if (last)
		last->next = new;
	if (p)
		p->prev = new;
	if (i == 0)
		*h = new;

	return (new);
}
