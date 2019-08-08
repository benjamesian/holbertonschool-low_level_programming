/**
 * get_bit - return the value of a bit at a given index
 * @n: a number
 * @index: index of the bit to get
 *
 * Return: 1 if bit is set, else 0
 */
int get_bit(unsigned long int n, unsigned int index)
{
	return ((n >> index) & 1);
}
