#include <stdlib.h>
#include "lists.h"

/**
 * free_list - free a list_t list
 * @head: pointer to first element in list
 */
void free_list(list_t *head)
{
	if (!head)
		return;

	free_list(head->next);
	free(head->str);
	free(head);
}
