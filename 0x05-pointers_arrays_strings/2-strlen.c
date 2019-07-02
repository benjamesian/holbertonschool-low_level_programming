/**
 * _strlen - Return the length of a string
 * @s: A string
 *
 * Return: The length of the string s
 */
int _strlen(char *s)
{
	int l;

	for (l = 0; s[l] != '\0'; l++)
		;

	return (l);
}
