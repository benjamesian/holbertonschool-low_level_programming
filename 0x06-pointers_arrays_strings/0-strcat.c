/**
 * _strcat - add the contents of src to the end of dest
 * @dest: Array to append src to
 * @src: Array to append to the end of dest
 *
 * Return: Pointer to start of dest array
 */
char *_strcat(char *dest, char *src)
{
/* go to end of dest arr */
	char *p = dest;

	while (*p)
		p++;

/* write out src arr */
	while ((*p++ = *src++))
		;

/* return dest */
	return (dest);
}
