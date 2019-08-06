#include <stdio.h>
#include "lists.h"

listint_t *get_loop_addr(listint_t *h, seen_t **seen_nodes);

/**
 * find_listint_loop - print a listint
 * @head: pointer to first element in list
 *
 * Return: number of nodes in the list
 */
listint_t *find_listint_loop(listint_t *head)
{
	seen_t *s = NULL;
	listint_t *found;

	found = get_loop_addr(head, &s);

	return (found);
}

/**
 * get_loop_addr - free a listint
 * @h: pointer to first element in linked list
 * @seen_nodes: linked list of nodes that have been seen before
 *
 * Return: address where loop starts
 */
listint_t *get_loop_addr(listint_t *h, seen_t **seen_nodes)
{
	seen_t new;
	seen_t *a = NULL;

	a = *seen_nodes;
	new.addr = h;
	new.next = *seen_nodes;
	*seen_nodes = &new;

	if (!h)
		return (NULL);

	while (a)
	{
		if (a->addr == h)
			return (h);
		a = a->next;
	}

	return (get_loop_addr(h->next, seen_nodes));
}
