#include "lists.h"

/**
 * find_listint_loop - print a listint
 * @head: pointer to first element in list
 *
 * Return: number of nodes in the list
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *t = head, *h = head;

	while (h && h->next)
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
