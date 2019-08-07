#include <stdio.h>
#include "lists.h"

listint_t *get_loop_addr(listint_t *h, seen_t **seen_nodes);

/**
 * find_listint_loop - print a listint
 * @head: pointer to first element in list
 *
 * Return: number of nodes in the list
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *t = head, *h = head;

	while (*h && *h->next)
	{
		h = h->next->next;
		t = t->next;

		if (t == h)
		{
			h = head;
			while (t != h)
			{
				t = t->next;
				h = h->next;
			}
			return (t);
		}
	}

	return (NULL);
}
