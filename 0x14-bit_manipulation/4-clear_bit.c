/**
 * clear_bit - set the value of a bit to 0 at a given index
 * @n: number
 * @index: index at which to set bit to 0
 *
 * Return: 1 if the bit was set, else 0
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int max_bits = sizeof(unsigned long int) * 8;

	if (index > max_bits)
		return (-1);

	*n = *n & (~(1 << index));

	return (0);
}
