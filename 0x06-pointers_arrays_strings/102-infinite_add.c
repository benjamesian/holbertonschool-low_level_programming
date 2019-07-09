void rev_arr(char *arr, int size);
int arr_len(char *arr);

/**
 * infinite_add - Add numbers in strings
 * @n1: first string summand
 * @n2: second string summand
 * @r: pointer to start of resulting string
 * @size_r: size of result string
 *
 * Return: A string containing the result of the addition
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int l1, l2, l3, d_sum;

	l1 = arr_len(n1);
	l2 = arr_len(n2);
	l3 = 0;
	r[0] = '0';

	while (l1 && l2)
	{
		l1--;
		l2--;
		d_sum = (r[l3] - '0') + (n1[l1] - '0') + (n2[l2] - '0');
		r[l3] = '0' + d_sum % 10;
		r[l3 + 1] = '0' + d_sum / 10;
		l3++;
	}

	do {
		if (l1)
		{
			r[l3] += n1[l1];
			l1--;
		}
		else if (l2)
		{
			r[l3] += n2[l2];
			l2--;
		}
		r[l3 + 1] = '0';
		if (r[l3] > '9')
		{
			r[l3] = '0';
			r[l3 + 1] = '1';
		}

		l3++;
	} while (l1 || l2);
	if (r[l3] == '1')
		l3++;
	r[l3] = '\0';

	rev_arr(r, l3);
	if (*r == '0')
		r++;

	if (l3 >= size_r)
		return (0);

	return (r);
}

/**
 * rev_arr - reverse an array in place
 * @arr: the array to reverse
 * @size: the length of the array
 */
void rev_arr(char *arr, int size)
{
	int tmp, i;

	for (i = 0; i < size / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = tmp;
	}
}

/**
 * arr_len - get the length of a string
 * @arr: a string
 *
 * Return: the length of the string
 */
int arr_len(char *arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		;

	return (i);
}
