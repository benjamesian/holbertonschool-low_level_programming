/**
 * _strncpy - Copy n bytes from src string to dest string
 * @dest: Pointer to destination string
 * @src: Pointer to source string
 * @n: Maximum number of bytes to be copied from src to dest
 *
 * Return: Pointer to dest string
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *p = dest;

	while (n-- && (*p++ = *src++))
		;

	while (n-- > 0)
		*p++ = '\0';

	return (dest);
}
