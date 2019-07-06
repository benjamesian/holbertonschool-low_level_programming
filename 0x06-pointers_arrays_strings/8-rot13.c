/**
 * rot13 - encode a string in rot13
 * @s: A string
 *
 * Return: Pointer to the beginning of s
 */
char *rot13(char *s)
{
	char *c = s;

	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s = (((*s - 'a') + 13) % 26) + 'a';
		else if (*s >= 'A' && *s <= 'Z')
			*s = (((*s - 'A') + 13) % 26) + 'A';
		s++;
	}

	return (c);
}
