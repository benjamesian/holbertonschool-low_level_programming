/**
 * _isupper - Check if an integer is the ascii code of an uppercase character
 * @c: An integer
 *
 * Return: 1 is c is the ascii code of an uppercase letter, else 0
 */
int _isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}
