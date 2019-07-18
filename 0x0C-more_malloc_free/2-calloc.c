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
	char *tmp;

	if (nmemb < 1 || size < 1)
		return (NULL);

	buffer = malloc(size * nmemb);
	if (buffer == NULL)
		return (NULL);

	tmp = buffer;
	while (size--)
		while (nmemb--)
			tmp[size + nmemb] = '\0';

	return (buffer);
}
