/**
 * _memset - fill n bytes of memory starting at s with b
 * @s: First address to fill
 * @b: Constant byte to fill addresses with
 * @n: Number of bytes to fill
 *
 * Return: Pointer to first address filled
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *p = s;

	while (n--)
		*s++ = b;

	return (p);
}
