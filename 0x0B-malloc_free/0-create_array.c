#include <stdlib.h>

/**
 * create_array - create an array of chars initialized with a specific char
 * @size: size of array in bytes
 * @c: character to initialize array with
 *
 * Return: pointer to start of initialized array
 */
char *create_array(unsigned int size, char c)
{
	char *buffer = NULL;

	buffer = malloc(size * sizeof(*buffer));
	if (!buffer)
		return (NULL);

	while (size--)
		buffer[size] = c;

	return (buffer);
}
