#include "lists.h"

/**
 * insert_nodeint_at_index - insert a new node at index
 * @head: pointer to pointer to first node in linked list
 * @idx: index at which the new node should be inserted
 * @n: data to be held in the new node
 *
 * Return: address of new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int current = 0;
	listint_t *p = *head;
	listint_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		*head = new;
		new->next = (p) ? p : NULL;
		return (new);
	}

	while (p && current < idx - 1)
	{
		p = p->next;
		current++;
	}

	if (p && current == idx - 1)
	{
		new->next = p->next;
		p->next = new;
		return (new);
	}
	return (NULL);
}
