/**
 * _strspn - Get length of a string prefix
 * @s: String
 * @accept: prefix to check for
 *
 * Return: Length of prefix that matched
 */
unsigned int _strspn(char *s, char *accept)
{
	char *p;
	int found;
	unsigned int len = 0;

	while (*s)
	{
		p = accept;
		found = 0;
		while (*p)
			if (*p++ == *s)
			{
				found = 1;
				break;
			}
		if (!found)
			break;
		len++;
		s++;
	}

	return (len);
}
