/**
 * _strstr - locate a subtring
 * @haystack: string to search
 * @needle: substring
 *
 * Return: Location of start of substring or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	char *ph, *pn;

	while (*haystack)
	{
		ph = haystack;
		pn = needle;

		while (*pn && *ph++ == *pn++)
		       ;
		if (!(*pn))
			return (haystack);

		haystack++;
	}

	return (0);
}
