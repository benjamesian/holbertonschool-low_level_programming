char is_sep(char);

/**
 * cap_string - Capitalize first letter of words in a string
 * @n: A string
 *
 * Return: A pointer to the beginning of the string
 */
char *cap_string(char *n)
{
	char make_cap = 0;
	char *m = n;

	while (1)
	{
		while (is_sep(*n))
		{
			n++;
			make_cap = 1;
		}

		if (make_cap && *n >= 'a' && *n <= 'z')
		{
			*n = (*n - 'a') + 'A';
			while (!is_sep(*n))
				n++;
			n--;
		}
		if (!*n)
			break;
		n++;
		make_cap = 0;
	}

	return (m);
}

/**
 * is_sep - Check if a character is a word separator
 * @n: A character
 *
 * Return: 1 if n is a word separator, else 0
 */
char is_sep(char n)
{
	return (n == ' ' || n == '\t' || n == '\n' || n == ',' || n == '.' ||
		n == '?' || n == '"' || n == '(' || n == ')' || n == '{' ||
		n == '}' || n == ';');
}
