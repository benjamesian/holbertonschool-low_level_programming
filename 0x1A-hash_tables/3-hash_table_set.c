#include "hash_tables.h"

/**
 * hash_table_set - Add an element to a hash table.
 * @ht: hash table to add element to
 * @key: key of element
 * @value: value of element
 *
 * Return: 1 if element successfully added else 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t **head, *new, *p;

	if (!ht || !key || !*key || !value)
		return (0);
	index = key_index((const unsigned char *) key, ht->size);
	p = ht->array[index];
	while (p)
	{
		if (strcmp(p->key, key) == 0)
		{
			free(p->value);
			p->value = strdup(value);
			return (1);
		}
		p = p->next;
	}
	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	head = &(ht->array[index]);
	new->key = strdup(key);
	if (!new->key)
	{
		free(new);
		return (0);
	}
	new->value = strdup(value);
	if (!new->value)
	{
		free(new->key);
		free(new);
		return (0);
	}
	new->next = *head;

	*head = new;

	return (1);
}
