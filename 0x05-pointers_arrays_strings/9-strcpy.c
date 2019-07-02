/**
 * _strcpy - copy source string into destination string
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}
