/**
 * _strchr - locate a character in a string
 * @s: string to search
 * @c: character to search for
 *
 * Return: Location of first occurence of character or NULL
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++);

	return (0);
}
