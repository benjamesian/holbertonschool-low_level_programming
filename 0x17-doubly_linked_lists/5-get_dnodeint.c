#include "lists.h"

/**
 * get_dnode_at_index - return the nth node in a dlistint list
 * @head: a node in a dlistint list
 * @index: index of node in dlistint list to return
 *
 * Return: node at nth index of dlistint list
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	if (!head)
		return (NULL);

	while (head->prev)
		head = head->prev;

	while (head && index--)
		head = head->next;

	if (head)
		return (head);

	return (NULL);
}
