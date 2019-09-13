#include "lists.h"

/**
 * add_dnodeint_end - add a new node at the end of a dlistint list
 * @head: a node in a dlistint list
 * @n: data to be stored in the new node
 *
 * Return: address of the newly created node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *p;

	if (!head)
		return (NULL);

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->n = n;

	p = *head;
	while (p && p->next)
		p = p->next;
	new->prev = p;

	if (!*head)
		*head = new;
	else
		p->next = new;

	return (new);
}
