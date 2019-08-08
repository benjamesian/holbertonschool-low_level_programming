/**
 * flip_bits - get number of bits you would need to flip to convert numbers
 * @n: first number
 * @m: second number
 *
 * Return: number of bits that needed to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int flip_counter = 0;
	unsigned long dummy;

	dummy = n ^ m;
	while (dummy)
	{
		flip_counter += dummy & 1;
		dummy >>= 1;
	}

	return (flip_counter);
}
