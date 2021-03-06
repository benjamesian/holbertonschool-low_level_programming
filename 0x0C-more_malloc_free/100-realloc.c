#include <stdlib.h>

/**
 * _realloc - reallocate memory
 * @ptr: pointer to memory that is allocated
 * @old_size: size of memory allocated at ptr
 * @new_size: amount of memory to allocate
 *
 * Return: pointer to newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *buffer;
	unsigned char *stmp, *dtmp;
	unsigned int mem_to_cpy;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	buffer = malloc(new_size);
	if (buffer == NULL)
	{
		free(ptr);
		return (NULL);
	}

	mem_to_cpy = (new_size < old_size) ? new_size : old_size;

	stmp = ptr;
	dtmp = buffer;
	if (ptr)
		while (mem_to_cpy--)
			*dtmp++ = *stmp++;

	free(ptr);

	return (buffer);
}
