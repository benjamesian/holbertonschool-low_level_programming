#include <stdio.h>
#include "lists.h"

/**
 * print_listint - print a list of numbers
 * @h: linked list of numbers
 *
 * Return: Number of elements in the list
 */
size_t print_listint(const listint_t *h)
{
	int num_nodes = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		num_nodes++;
	}

	return (num_nodes);
}
