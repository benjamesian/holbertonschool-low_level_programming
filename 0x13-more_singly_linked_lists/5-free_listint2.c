#include "lists.h"

/**
 * free_listint2 - free a linked list
 * @head: pointer to first element of the linked list
 */
void free_listint2(listint_t **head)
{
	if (!head || !*head)
		return;
	free_listint2(&((*head)->next));
	free(*head);
	*head = NULL;
}
