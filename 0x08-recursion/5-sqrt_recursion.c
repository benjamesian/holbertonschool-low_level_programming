int _sqrt_helper(int, int);

/**
 * _sqrt_recursion - get sqrt of an integer
 * @n: integer
 *
 * Return: square root of n if the root is an integer
 */
int _sqrt_recursion(int n)
{
	return _sqrt_helper(n, 0);
}

/**
 * _sqrt_helper - get square root of an integer
 * @n: number to find square root of
 * @m: counter that may take on value of square root
 *
 * Return: Get square root of a number
 */
int _sqrt_helper(int n, int m)
{
	int prod = m * m;

	if (prod == n)
		return (m);
	else if (prod > n)
		return (-1);

	return _sqrt_helper(n, m + 1);
}
