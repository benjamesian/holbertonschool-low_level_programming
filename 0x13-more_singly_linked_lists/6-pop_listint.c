#include "lists.h"

/**
 * pop_listint - pop the first element of a linked list
 * @head: pointer to pointer to first element of linked list
 *
 * Return: data in popped node
 */
int pop_listint(listint_t **head)
{
	int data;

	if (!head)
		return (0);

	data = (*head)->n;
	free(*head);
	*head = (*head)->next;

	return (data);
}
