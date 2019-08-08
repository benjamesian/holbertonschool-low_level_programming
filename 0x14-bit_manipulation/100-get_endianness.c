/**
 * get_endianness - check the endianness
 *
 * Return: 0 if big endian, else 1
 */
int get_endianness(void)
{
	int c = 0xff000000;

	char *p = (void *) &c;

	return (!*p);
}
