#include "lists.h"

/**
 * add_nodeint - add a node to a linked list
 * @head: pointer to pointer to first node
 * @n: data that new node will hold
 *
 * Return: pointer to newly created node.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
