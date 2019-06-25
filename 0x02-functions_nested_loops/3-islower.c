/**
 * _islower - Return if input integer corresponds to a lowercase ASCII keycode
 * @c: an integer which may correspond to an ASCII key code
 *
 * Return: 1 if argument is the ASCII key code for a lowercase letter, else 0
 */
int _islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
