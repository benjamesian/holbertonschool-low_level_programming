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
	listint_t *p, *_p;

	if (!head || !*head)
		return (-1);

	p = *head;
	while (index && *head && current < index - 1)
	{
		*head = (*head)->next;
		current++;
	}

	if (*head)
	{
		if (index == 0)
		{
			*head = (*head)->next;
			free(p);
		}
		else if ((*head)->next)
		{
			_p = (*head)->next;
			(*head)->next = (*head)->next->next;
			free(_p);
			*head = p;
		}
		else
		{
			*head = p;
			return (-1);
		}
		return (1);
	}
	*head = p;

	return (-1);
}
