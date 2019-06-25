#include "holberton.h"

/**
 * print_last_digit - Print and return the last digit of an integer
 * @n: An integer
 *
 * Return: The last digit of the integer n
 */
int print_last_digit(int n)
{
	int _abs = n < 0 ? -n : n;

	_putchar('0' + _abs % 10);
	return (_abs % 10);
}
