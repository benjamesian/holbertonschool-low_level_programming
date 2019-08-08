/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @b: a string of 0 and 1 characters
 *
 * Return: the binary string converted into a number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int u = 0;
	unsigned int len = 0;
	unsigned int mult = 1;

	if (!b)
		return (0);

	while (b[len])
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
		len++;
	}

	while (len--)
	{
		u += (b[len] - '0') * mult;
		mult <<= 1;
	}

	return (u);
}
