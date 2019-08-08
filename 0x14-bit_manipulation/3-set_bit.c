/**
 * set_bit - set the value of a bit to 1 at a given index
 * @n: pointer to number whose bit we want to set
 * @index: index of bit to set
 *
 * Return: 1 if bit was properly set, else -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int max_bits = sizeof(unsigned long int) * 8;

	if (index > max_bits)
		return (-1);

	*n = *n | (1 << index);

	return (1);
}
