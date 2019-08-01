#include <stdlib.h>
#include <string.h>
#include "lists.h"

unsigned int _strlen(const char *s);

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
	temp->len = _strlen(str);

	*head = temp;

	return (temp);
}

/**
 * _strlen - get the length of a string
 * @s: a string
 *
 * Return: The length of the string
 */
unsigned int _strlen(const char *s)
{
	unsigned int i;

	if (s)
		for (i = 0; s[i]; i++)
			;
	else
		return (0);

	return (i);
}
