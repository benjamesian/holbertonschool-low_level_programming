#include "hash_tables.h"

/**
 * free_arr - Free a linked list.
 * @head: head of the linked list
 */
void free_arr(hash_node_t *head)
{
	hash_node_t *p;

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
 * hash_table_delete - Free all memory used by a hash table.
 * @ht: hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	size_t index;

	for (index = 0; index < ht->size; index++)
		free_arr(ht->array[index]);

	free(ht->array);
	free(ht);
}
