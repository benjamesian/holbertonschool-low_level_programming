#include "lists.h"

/**
 * sum_dlistint - return the sum of all data in a dlistint list
 * @head: a node in a dlistint list
 *
 * Return: The sum of all data in a dlistint list
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head)
	{
		while (head->prev)
			head = head->prev;

		while (head)
		{
			sum += head->n;
			head = head->next;
		}
	}

	return (sum);
}
