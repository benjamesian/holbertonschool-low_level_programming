/**
 * _strncat - Add at most n characters from src array to end of dest array
 * @dest: Array to add characters from src to the end of
 * @src: Array whose characters will be copied to the end of dest
 * @n: Number of characters to copy from src to dest
 *
 * Return: Pointer to start of dest array
 */
char *_strncat(char *dest, char *src, int n)
{
/* go to end of dest arr */
	char *p = dest;

	while (*p)
		p++;

/* write out src arr */
	while (n-- && (*p++ = *src++))
		;

/* return dest */
	return (dest);
}
