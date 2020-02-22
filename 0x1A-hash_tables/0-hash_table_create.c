#include "hash_tables.h"

/**
 * hash_table_create - Create an empty hash table.
 * @size: size of the hash table
 *
 * Return: newly created hash table or NULL if memory could not be allocated
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

	ht = malloc(sizeof(*ht));
	if (!ht)
		return (NULL);

	ht->array = calloc(size, sizeof(*ht->array));
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	ht->size = size;

	return (ht);
}
