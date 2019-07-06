/**
 * string_toupper - Capitalize a string
 * @n: A string
 *
 * Return: Pointer to the beginning of the string
 */
char *string_toupper(char *n)
{
	char *m = n;

	while (*n)
	{
		if (*n >= 'a' && *n <= 'z')
			*n = (*n - 'a') + 'A';
		n++;
	}

	return (m);
}
