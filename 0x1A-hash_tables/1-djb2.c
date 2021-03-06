/**
 * hash_djb2 - a hash function
 * @str: string to create a hash for
 *
 * Return: hash for the string
 */
unsigned long hash_djb2(const unsigned char *str)
{
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (hash);
}
