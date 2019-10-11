#include "hash_tables.h"

/**
 * hash_table_get - get the value associated with a key in a hash table.
 * @ht: hash table
 * @key: key in hash table
 *
 * Return: value associated with key or NULL if key does not exist in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *head;

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
