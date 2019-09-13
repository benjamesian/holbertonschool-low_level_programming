#include "lists.h"

/**
 * add_dnodeint - add a new node at the beginning of a dlistint list
 * @head: a node in the dlistint list
 * @n: data to be stored in the new node
 *
 * Return: address of the newly created node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (!head)
		return (NULL);

	while (*head && (*head)->prev)
		(*head) = (*head)->prev;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);

	new->prev = NULL;
	new->next = *head;
	new->n = n;

	if (*head)
		(*head)->prev = new;
	*head = new;

	return (new);
}
