/**
 * reverse_array - Reverse an array in place
 * @a: Array to be reversed
 * @n: Length of the array
 */
void reverse_array(int *a, int n)
{
	int tmp, i = 0;

	while (i++ < n / 2)
	{
		tmp = a[i - 1];
		a[i - 1] = a[n - i];
		a[n - i] = tmp;
	}
}
