#include "lists.h"

/**
 * listint_len - get number of elements in a linked list
 * @h: linked list of numbers
 *
 * Return: Number of elements in the list
 */
size_t listint_len(const listint_t *h)
{
	int num_nodes = 0;

	while (h)
	{
		h = h->next;
		num_nodes++;
	}

	return (num_nodes);
}
