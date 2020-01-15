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
		a = a->express;
		printf("Value checked at index [%lu] = [%d]\n", a->index, a->n);

		b = a->express;
		if (!b)
		{
			b = a;
			while (b->next)
				b = b->next;
		}
		if (a != b && b->n > value)
		{
			printf("Value checked at index [%lu] = [%d]\n", b->index, b->n);
			break;
		}
	}

	printf("Value found between indexes [%lu] and [%lu]", a->index, b->index);

	while (a)
	{
		printf("Value checked at index [%lu] = [%d]\n", a->index, a->n);
		if (a->n == value)
			return (a->index);
		a = a->next;
	}

	return (NULL);
}
