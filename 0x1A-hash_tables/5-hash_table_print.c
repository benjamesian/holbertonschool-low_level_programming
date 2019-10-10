#include "hash_tables.h"

/**
 * hash_table_print - Print the data stored in a hash table.
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	size_t index;
	hash_node_t *head;
	int add_comma = 0;

	putchar('{');
	for (index = 0; index < ht->size; index++)
	{
		head = ht->array[index];
		while (head)
		{
			if (add_comma)
				printf(", ");
			add_comma = 1;
			printf("'%s': '%s'", head->key, head->value);
			if (head->next)
				printf(", ");
			head = head->next;
		}
	}
	putchar('}');
	putchar('\n');
}
