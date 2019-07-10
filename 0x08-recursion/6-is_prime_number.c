int is_prime_helper(int, int);

/**
 * is_prime_numer - Check if an integer is a prime
 * @n: an integer
 *
 * Return: 1 if n is prime, else 0
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);

	return (is_prime_helper(n, n - 1));
}

/**
 * is_prime_helper - check if a number is a prime
 * @n: number which may be a prime
 * @m: counter to help check if n is prime
 *
 * Return: 1 if n is prime, else 0
 */
int is_prime_helper(int n, int m)
{
	if (m < 2)
		return (1);

	if (!(n % m))
		return (0);

	return (is_prime_helper(n, m - 1));
}
