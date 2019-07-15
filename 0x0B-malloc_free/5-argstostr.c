#include <stdlib.h>

int _strlen(char *str);

/**
 * argstostr - concatenate program args
 * @ac: arg count
 * @av: arg vals
 *
 * Return: concatenated args
 */
char *argstostr(int ac, char **av)
{
	char *buffer, *tmp;
	int len = 0;
	int i = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	i = ac;
	while (i--)
		len += _strlen(av[i]);

	buffer = malloc(len * sizeof(*buffer));
	if (!buffer)
		return (NULL);

	tmp = buffer;
	i = 0;
	while (i < ac)
	{
		while ((*buffer++ = *av[i]++))
			;
		*(buffer - 1) = '\n';
		i++;
	}
	*buffer = '\0';

	return (tmp);
}

/**
 * _strlen - get length of a string
 * @str: string
 *
 * Return: length of str
 */
int _strlen(char *str)
{
	int i = 0;

	while (*str++)
		i++;

	return (i);
}
