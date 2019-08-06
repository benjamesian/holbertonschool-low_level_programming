#include <stdio.h>
#include "lists.h"

size_t _free_listint_safe(listint_t *h, seen_t *seen_nodes);

/**
 * free_listint_safe - print a listint
 * @h: pointer to first element in list
 *
 * Return: number of nodes in the list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t num_nodes;
	seen_t *s = NULL;

	num_nodes = _free_listint_safe(*h, s);

	_free_list(&s);

	return (num_nodes);
}

/**
 * _free_listint_safe - free a listint
 * @h: pointer to first element in linked list
 * @seen_nodes: linked list of nodes that have been seen before
 *
 * Return: number of nodes that have been freed
 */
size_t _free_listint_safe(listint_t *h, seen_t *seen_nodes)
{
	seen_t *added = NULL;

	if (!h || already_seen(h, seen_nodes))
		return (0);

	added = add_node(&seen_nodes, h);
	if (!added)
		exit(98);

	return (1 + _free_listint_safe(h->next, seen_nodes));
}
