#include "search_algos.h"
#include <math.h>

/**
 * jump_list - jump search algorithm
 * @list: array to search
 * @size: size of the array
 * @value: value to search for
 *
 * Return: first node where value is found or NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *a = list, *b = list;
	size_t i, skkrt = sqrt(size);

	if (!list)
		return (NULL);

	while (b->next && b->n < value)
	{
		a = b;
		for (i = 0; b->next && i < skkrt; i++)
			b = b->next;

		printf("Value checked at index [%lu] = [%d]\n", b->index, b->n);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", a->index, b->index);
	while (a->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", a->index, a->n);
		a = a->next;
		if (a == b)
			break;
	}

	printf("Value checked at index [%lu] = [%d]\n", a->index, a->n);
	if (a->n == value)
		return (a);
	return (NULL);
}
