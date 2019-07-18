#include <stdlib.h>

unsigned int _strlen(char *);

/**
 * string_nconcat - concatenate two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to take from s2
 *
 * Return: pointer to resulting string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *tmp;
	char *buffer = NULL;
	unsigned int s2_len;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	s2_len = _strlen(s2);
	if (s2_len < n)
		n = s2_len;

	buffer = malloc(sizeof(*buffer) * (_strlen(s1) + n + 1));
	if (buffer == NULL)
		return (NULL);

	tmp = buffer;

	while ((*buffer++ = *s1++))
		;
	buffer--;
	while (n-- && (*buffer++ = *s2++))
		;
	*buffer = '\0';

	return (tmp);
}

/**
 * _strlen - get the length of a string
 * @s: string with length
 *
 * Return: length of s
 */
unsigned int _strlen(char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
		;

	return (i);
}
