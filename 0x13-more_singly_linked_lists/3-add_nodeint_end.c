#include "lists.h"

/**
 * add_nodeint_end - add a node to the end of a linked list
 * @head: pointer to pointer to first node
 * @n: data to store in new node
 *
 * Return: pointer to newly created node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(*new));
	listint_t *p;

	if (!new)
		return (NULL);

	new->n = n;
	p = *head;
	if (!p)
		*head = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}

	return (new);
}
