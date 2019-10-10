#include "hash_tables.h"

/**
 * key_index - Get index in hash table associated with a key.
 * @key: key to find index for
 * @size: size of the hash table.
 *
 * Return: index in hash table where key should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash = hash_djb2(key);

	return (hash % size);
}
