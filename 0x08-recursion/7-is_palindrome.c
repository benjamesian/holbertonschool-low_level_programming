int palindrome_helper(char *, int, int);
int get_end(char *, int);

/**
 * is_palindrome - check if a word is a palindrome
 * @s: a word
 *
 * Return: 1 if s is a palindrome, else 0
 */
int is_palindrome(char *s)
{
	int i;

	if (!(*s))
		return (1);

	i = get_end(s, 0);

	return (palindrome_helper(s, 0, i - 1));
}

/**
 * palindrome_helper - check if a string is a palindrome
 * @s: a string
 * @i: left index
 * @j: right index
 *
 * Return: 1 if string is a palindrome, else 0
 */
int palindrome_helper(char *s, int i, int j)
{
	if (i >= j)
		return (1);

	return ((s[i] == s[j]) && palindrome_helper(s, ++i, --j));
}

/**
 * get_end - get length of a string
 * @s: string
 * @i: length counter
 *
 * Return: length of s
 */
int get_end(char *s, int i)
{
	if (!(*s))
		return (i);

	return (get_end(++s, i + 1));
}
