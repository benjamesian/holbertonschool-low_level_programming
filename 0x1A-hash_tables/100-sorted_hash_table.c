#include "hash_tables.h"

/**
 * shash_table_create - Create an empty shash table.
 * @size: size of the shash table
 *
 * Return: newly created hash table or NULL if memory could not be allocated
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	shash_node_t **arr;

	ht = malloc(sizeof(*ht));
	if (!ht)
		return (NULL);

	arr = malloc(sizeof(*arr) * size);
	if (!arr)
	{
		free(ht);
		return (NULL);
	}

	ht->size = size;
	ht->array = arr;
	ht->shead = NULL;
	ht->stail = NULL;

	while (size--)
		arr[size] = 0;

	return (ht);
}

/**
 * insert_sorted - insert sorted.
 * @ht: shash table
 * @node: node
 */
void insert_sorted(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *p;

	if (!ht->shead)
	{
		ht->shead = node;
		ht->stail = node;
		node->snext = NULL;
		node->sprev = NULL;
	}
	else
	{
		if (strcmp(node->key, ht->shead->key) <= 0)
		{
			node->snext = ht->shead;
			node->sprev = NULL;
			ht->shead->sprev = node;
			ht->shead = node;
		}
		else
		{
			p = ht->shead;
			while (p && p->snext)
			{
				if (strcmp(node->key, p->snext->key) <= 0)
				{
					node->snext = p->snext;
					p->snext->sprev = node;
					node->sprev = p;
					p->snext = node;
					break;
				}
				p = p->snext;
			}
			if (!p->snext)
			{
				p->snext = node;
				node->snext = NULL;
				node->sprev = p;
				ht->stail = node;
			}
		}
	}
}

/**
 * shash_table_set - Add an element to a shash table.
 * @ht: shash table to add element to
 * @key: key of element
 * @value: value of element
 *
 * Return: 1 if element successfully added else 0
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t **head, *new, *p;

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
	insert_sorted(ht, new);

	return (1);
}

/**
 * shash_table_get - get the value associated with a key in a shash table.
 * @ht: shash table
 * @key: key in shash table
 *
 * Return: value associated with key or NULL if key does not exist in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *head;

	if (!ht || !key || !*key)
		return (NULL);
	head = ht->array[key_index((const unsigned char *)key, ht->size)];
	while (head)
	{
		if (strcmp(head->key, key) == 0)
			return (head->value);
		head = head->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Print the data stored in a shash table.
 * @ht: shash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *head;
	int add_comma = 0;

	if (!ht)
		return;

	putchar('{');
	head = ht->shead;
	while (head)
	{
		if (add_comma)
			printf(", ");
		else
			add_comma = 1;
		printf("'%s': '%s'", head->key, head->value);
		head = head->snext;
	}
	putchar('}');
	putchar('\n');
}

/**
 * shash_table_print - Print the data stored in a shash table in reverse order.
 * @ht: shash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *head;
	int add_comma = 0;

	if (!ht)
		return;

	putchar('{');
	head = ht->stail;
	while (head)
	{
		if (add_comma)
			printf(", ");
		else
			add_comma = 1;
		printf("'%s': '%s'", head->key, head->value);
		head = head->sprev;
	}
	putchar('}');
	putchar('\n');
}

/**
 * free_arr - Free a linked list.
 * @head: head of the linked list
 */
void free_arrs(shash_node_t *head)
{
	shash_node_t *p;

	if (!head)
		return;

	while (head)
	{
		p = head;
		head = head->next;
		free(p->key);
		free(p->value);
		free(p);
	}
}

/**
 * shash_table_delete - Free all memory used by a shash table.
 * @ht: shash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	size_t index;

	for (index = 0; index < ht->size; index++)
		free_arrs(ht->array[index]);
	free(ht->array);
	free(ht);
}
