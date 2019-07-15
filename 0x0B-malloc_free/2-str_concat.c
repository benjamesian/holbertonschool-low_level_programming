#include <stdlib.h>

/**
 * str_concat - concatenate two strings
 * @s1: first string
 * @s2: string to concatenate to first string
 *
 * Return: pointer to resulting string
 */
char *str_concat(char *s1, char *s2)
{
	int s1_len, s2_len;
	char *s = NULL;
	char *tmp;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";

	for (s1_len = 0; s1[s1_len]; s1_len++)
		;

	s2_len = 0;
	while (s2[s2_len++])
		;

	s = malloc((s1_len + s2_len) + sizeof(*s));
	tmp = s;
	if (!s)
		return (NULL);

	while ((*s++ = *s1++))
		;
	s--;
	while ((*s++ = *s2++))
		;

	return (tmp);
}
