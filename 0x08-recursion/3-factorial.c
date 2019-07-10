/**
 * factorial - factorial of an integer
 * @n: an integer
 *
 * Return: factorial of n
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);

	return n * factorial(n - 1);
}
