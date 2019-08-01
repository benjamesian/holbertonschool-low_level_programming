#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - add a new node to the end of a list_t list
 * @head: pointer to a pointer to the first element of the list
 * @str: string to store in the new element
 *
 * Return: pointer to the newly added element
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *temp, *p;

	temp = malloc(sizeof(*temp));
	if (!temp)
		return (NULL);

	temp->next = NULL;
	temp->str = strdup(str);
	temp->len = strlen(str);

	p = *head;

	if (!p)
		*head = temp;
	else
	{
		while (p->next)
			p = p->next;
		p->next = temp;
	}

	return (temp);
}
