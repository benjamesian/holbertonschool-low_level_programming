#include "lists.h"

/**
 * get_nodeint_at_index - get node at index n
 * @head: first node in the list
 * @index: index of node to get
 *
 * Return: pointer to node found at index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int current = 0;

	while (head && current++ < index)
		head = head->next;

	return ((head) ? head : NULL);
}
