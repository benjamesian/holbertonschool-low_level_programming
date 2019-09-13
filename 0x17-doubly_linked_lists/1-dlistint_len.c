#include "lists.h"

/**
 * dlistint_len - return the number of elements in a dlistint list
 * @h: a node in the dlistint list
 *
 * Return: The number of elements in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t num_nodes = 0;

	while (h && h->prev)
		h = h->prev;

	while (h)
	{
		num_nodes++;
		h = h->next;
	}

	return (num_nodes);
}
