/**
 * swap_int - swap the values that two pointers are referencing
 * @a: A pointer to an integer
 * @b: A pointer to an integer
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
