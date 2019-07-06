/**
 * leet - encodes a string into leet
 * @n: String to be encoded
 *
 * Return: Pointer to the beginning of the string
 */
char *leet(char *n)
{
	int i;
	char *p = n;
	char *l = "aeotl";
	char *u = "AEOTL";
	char *m = "43071";

	while (*n)
	{
		for (i = 0; i < 5; i++)
			if (*n == l[i] || *n == u[i])
				*n = m[i];
		n++;
	}

	return (p);
}
