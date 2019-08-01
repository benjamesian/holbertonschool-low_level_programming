#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - add a new node at the beginning of a list_t list
 * @head: pointer to a pointer to the beginning of the list
 * @str: string to store in the new node
 *
 * Return: address of the new element
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *temp;

	temp = malloc(sizeof(*temp));
	if (!temp)
		return (NULL);

	temp->next = *head;
	temp->str = strdup(str);
	temp->len = strlen(str);

	*head = temp;

	return (temp);
}
