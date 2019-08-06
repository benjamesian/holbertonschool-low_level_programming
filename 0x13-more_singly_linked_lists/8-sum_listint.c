#include "lists.h"

/**
 * sum_listint - sum integers held in a linked list
 * @head: first element in the linked list
 *
 * Return: sum of all integers held in the linked list
 */
int sum_listint(listint_t *head)
{
	if (!head)
		return (0);

	return (head->n + sum_listint(head->next));
}
