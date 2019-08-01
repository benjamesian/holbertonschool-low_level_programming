#include <stdlib.h>
#include "lists.h"

/**
 * list_len - get the number of elements in a list_t list
 * @h: pointer to the first element in the list
 *
 * Return: the number of elements in the list
 */
size_t list_len(const list_t *h)
{
	size_t len = 0;

	while (h)
	{
		h = h->next;
		len++;
	}

	return (len);
}
