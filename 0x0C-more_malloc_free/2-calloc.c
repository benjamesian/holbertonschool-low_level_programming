#include <stdlib.h>

/**
 * _calloc - allocate memory for an array
 * @nmemb: number of elements in array
 * @size: size of an array element in bytes
 *
 * Return: pointer to start of array
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *buffer = NULL;
	unsigned char *tmp;
	size_t b;

	if (nmemb == 0 || size == 0)
		return (NULL);

	b = nmemb * size;

	buffer = malloc(b);
	if (buffer == NULL)
		return (NULL);

	tmp = buffer;
	while (b--)
		*tmp++ = 0;

	return (buffer);
}
