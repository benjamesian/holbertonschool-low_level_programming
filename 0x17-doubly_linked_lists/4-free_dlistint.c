#include "lists.h"

/**
 * free_dlistint - free a dlistint list
 * @head: a node in a dlistint list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *p = head;

	while (head && head->prev)
		head = head->prev;

	while (head)
	{
		p = head;
		head = head->next;
		free(p);
		p = NULL;
	}
}
