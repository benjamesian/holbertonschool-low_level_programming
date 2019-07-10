int palindrome_helper(char *, int, int);

/**
 * is_palindrome - check if a word is a palindrome
 * @s: a word
 *
 * Return: 1 if s is a palindrome, else 0
 */
int is_palindrome(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;

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
