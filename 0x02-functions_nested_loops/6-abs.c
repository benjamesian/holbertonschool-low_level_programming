/**
 * _abs - return the absolute value of an integer
 * @a: An integer which may be positive of negative
 *
 * Return: The absolute value of a
 */
int _abs(int a)
{
	int output;

	if (a < 0)
		output = -a;
	else
		output = a;

	return (output);
}
