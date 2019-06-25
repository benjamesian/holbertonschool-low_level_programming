/**
 * _isalpha - Determine if arg is an ASCII key code for a letter
 * @c: An integer which may be the ASCII key code for a letter
 *
 * Return: 1 if c is the ASCII keycode for a letter, else 0
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
