/**
 * _strcmp - Compare two strings s1 and s2
 * @s1: A string
 * @s2: A string
 *
 * Return: 0 if s1 is equal to s2, -1 if s1 is less than s2, else 1
 */
int _strcmp(char *s1, char *s2)
{
	if ((!*s1 && !*s2) || *s1 != *s2)
		return (*s1 - *s2);

	return (_strcmp(++s1, ++s2));
}
