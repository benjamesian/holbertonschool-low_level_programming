#include "lists.h"

/**
 * reverse_listint - reverse a linked list
 * @head: pointer to a pointer to the first element
 *
 * Return: address of the first element after the list has been reversed
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next;

	if (!(*head))
		return (NULL);

	next = (*head)->next;
	while (next)
	{
		(*head)->next = prev;
		prev = *head;
		*head = next;
		next = (*head)->next;
	}
	(*head)->next = prev;

	return (*head);
}
