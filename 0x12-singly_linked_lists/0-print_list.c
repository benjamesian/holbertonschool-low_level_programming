#include <stdio.h>
#include "lists.h"

/**
 * print_list - print all the elements of a list_t list
 * @h: pointer to the first element in the list
 *
 * Return: number of elements in the list
 */
size_t print_list(const list_t *h)
{
	size_t num_nodes = 0;

	while (h)
	{
		printf("[%d] %s\n", h->len, (h->str) ? h->str : "(nil)");
		h = h->next;
		num_nodes++;
	}

	return (num_nodes);
}
