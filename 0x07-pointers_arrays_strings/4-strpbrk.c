/**
 * _strpbrk - search a string for any set of bytes
 * @s: string to search
 * @accept: bytes to search for
 *
 * Return: pointer to first matched byte or NULL
 */
char *_strpbrk(char *s, char *accept)
{
	char *p;
	int found;

	while (*s)
	{
		p = accept;
		found = 0;
		while (*p)
		{
			if (*p++ == *s)
			{
				found = 1;
				break;
			}
		}
		if (found)
			return (s);
		s++;
	}

	return (0);
}
