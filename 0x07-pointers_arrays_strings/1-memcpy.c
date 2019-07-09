/**
 * _memcpy - copy n bytes of from memory area src to memory are dest
 * @dest: Beginning of memory area to copy to
 * @src: Beginning of memory area to copy from
 * @n: number of bytes to copy
 *
 * Return: Pointer to beginning of destination memory area
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *p = dest;

	while (n--)
		*dest++ = *src++;

	return (p);
}
