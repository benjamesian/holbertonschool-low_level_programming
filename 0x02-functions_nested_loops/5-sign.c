#include "holberton.h"

/**
 * print_sign - Print the sign of a number
 * @n: A number which may be positive or negative
 *
 * Description: If n is negative print '-', else if n is positive print '+',
 * else print '0'
 * Return: The result 1 if n positive, -1 if n negative, else 0
 */
int print_sign(int n)
{
	int output;

	if (n < 0)
	{
		output = -1;
		_putchar('-');
	}
	else if (n > 0)
	{
		output = 1;
		_putchar('+');
	}
	else
	{
		output = 0;
		_putchar('0');
	}

	return (output);
}
