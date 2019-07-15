#include <stdlib.h>

/**
 * _strdup - create a copy of a string using malloc
 * @str: string to copy
 *
 * Return: pointer to copy
 */
char *_strdup(char *str)
{
	char *tmp;
	char *buffer = NULL;
	int i = 0;

	while (str[i++])
		;

	buffer = malloc(i * sizeof(*buffer));
	if (!buffer)
		return (NULL);

	tmp = buffer;

	if (buffer)
		while ((*buffer++ = *str++))
			;

	return (tmp);
}
