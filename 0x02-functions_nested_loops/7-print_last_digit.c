#include "holberton.h"

/**
 * print_last_digit - Print and return the last digit of an integer
 * @n: An integer
 *
 * Return: The last digit of the integer n
 */
int print_last_digit(int n)
{
	int _abs, last;

	if (n < 0)
		_abs = -n;
	else
		_abs = n;

	last = _abs % 10;

	_putchar('0' + last);
	return (last);
}
