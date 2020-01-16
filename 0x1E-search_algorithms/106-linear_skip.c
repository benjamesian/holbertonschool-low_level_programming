#include "search_algos.h"

/**
 * linear_skip - linear skip search algorithm
 * @list: array to search
 * @value: value to search for
 *
 * Return: first node where value is found or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *a = list, *b = list;

	if (!list)
		return (NULL);

	while (a->express)
	{
		b = a->express;
		printf("Value checked at index [%lu] = [%d]\n", b->index, b->n);
		if (b->n >= value)
			break;
		a = b;
		if (a->express)
			b = a->express;
		else
			while (b->next)
				b = b->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", a->index, b->index);

	while (a)
	{
		printf("Value checked at index [%lu] = [%d]\n", a->index, a->n);
		if (a->n == value)
			return (a);
		a = a->next;
	}

	return (NULL);
}
