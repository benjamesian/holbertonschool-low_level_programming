#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - print all elements of a dlistint list
 * @h: a node in the dlistint list
 *
 * Return: The number of elements in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t num_nodes = 0;

	while (h && h->prev)
		h = h->prev;

	while (h)
	{
		num_nodes++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (num_nodes);
}
