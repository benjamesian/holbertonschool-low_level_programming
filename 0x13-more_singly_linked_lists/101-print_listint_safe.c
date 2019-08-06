#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - print a listint
 * @head: pointer to first element in list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t num_nodes = 0;
	seen_t *seen_nodes = NULL, *added = NULL;

	while (head)
	{
		printf("[%p] %d\n", (void *) head, head->n);

		added = add_node(&seen_nodes, head);
		if (!added)
			exit(98);

		head = head->next;
		if (already_seen(head, seen_nodes))
		{
			printf("-> [%p] %d\n", (void *) head, head->n);
			break;
		}

		num_nodes++;
	}

	_free_list(&seen_nodes);

	return (num_nodes);
}

/**
 * already_seen - check if a node exists in a linked list
 * @p: node which may exist in a linked list
 * @ll: linked list to check
 *
 * Return: 1 if node exists in the linked list, else 0
 */
int already_seen(const listint_t *p, seen_t *ll)
{
	while (ll)
	{
		if (ll->addr == p)
			return (1);
		ll = ll->next;
	}

	return (0);
}

/**
 * add_node - add a node to a linked list
 * @head: pointer to pointer to first node
 * @addr: data that new node will hold
 *
 * Return: pointer to newly created node.
 */
seen_t *add_node(seen_t **head, const listint_t *addr)
{
	seen_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);

	new->addr = addr;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * _free_list - free a linked list
 * @head: pointer to first element of the linked list
 */
void _free_list(seen_t **head)
{
	if (!head || !*head)
		return;
	_free_list(&((*head)->next));
	free(*head);
	*head = NULL;
}
