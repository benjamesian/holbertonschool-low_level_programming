#include <stdlib.h>

/**
 * malloc_checked - allocate memory using malloc
 * @b: bytes to allocate
 *
 * Return: pointer to allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *buffer = NULL;

	buffer = malloc(b);
	if (buffer == NULL)
		exit(98);

	return (buffer);
}
