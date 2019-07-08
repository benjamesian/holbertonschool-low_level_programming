/**
 * rot13 - encode a string in rot13
 * @s: A string
 *
 * Return: Pointer to the beginning of s
 */
char *rot13(char *s)
{
	char w;
	char *c = s;
	int l, u;

	while (*s)
	{
		l = (*s >= 'a' && *s <= 'z');
		u = (*s >= 'A' && *s <= 'Z');
		w = l * 'a' + u * 'A';
		if (w)
			*s = (((*s - w) + 13) % 26) + w;
		s++;
	}

	return (c);
}
