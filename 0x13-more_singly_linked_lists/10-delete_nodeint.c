#include "lists.h"

/**
 * delete_nodeint_at_index - delete a node at an index
 * @head: pointer to pointer to start of list
 * @index: index of node to delete
 *
 * Return: data held in deleted node
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int current = 0;
	listint_t *p = *head, *_p;

	while (p && current < index - 1)
	{
		p = p->next;
		current++;
	}

	if (p)
	{
		if (p->next)
		{
			_p = p->next;
			p->next = p->next->next;
			free(_p);
		}
		else
			p->next = NULL;
		return (1);
	}

	return (-1);
}
