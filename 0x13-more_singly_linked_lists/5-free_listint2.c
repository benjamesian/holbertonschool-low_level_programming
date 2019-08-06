#include "lists.h"

/**
 * free_listint2 - free a linked list
 * @head: pointer to first element of the linked list
 */
void free_listint2(listint_t **head)
{
	free_listint(*head);
	*head = NULL;
}

/**
 * free_listint - free a linked list
 * @head: pointer to first element of the linked list
 */
void free_listint(listint_t *head)
{
	if (!head)
		return;
	free_listint(head->next);
	free(head);
}
