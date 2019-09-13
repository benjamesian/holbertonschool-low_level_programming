#include "lists.h"

/**
 * insert_dnodeint_at_index - inset a new node at a given position
 * @h: a node in a dlistint list
 * @idx: index in dlistint list at which to insert new node
 * @n: data for newly created node
 *
 * Return: address of newly created node
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int idx)
{
	dlistint_t *p, *last = NULL;
	unsigned int i = idx;

	if (!head)
		return (-1);

	p = *head;
	while (p && p->prev)
		p = p->prev;

	while (p && idx)
	{
		last = p;
		p = p->next;
		idx--;
	}

	if (idx != 0 || !p)
		return (-1);

	if (last)
		last->next = p->next;
	if (p->next)
		p->next->prev = last;

	if (i == 0)
		*head = p->next;
	free(p);
	p = NULL;
	return (1);
}
