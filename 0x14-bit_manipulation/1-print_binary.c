#include "holberton.h"

void _print_binary(unsigned long int n);

/**
 * print_binary - print the binary representation of a number
 * @n: a number to be represented in binary form
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		_putchar('0');
		return;
	}

	_print_binary(n);
}

/**
 * _print_binary - print the binary representation of a number
 * @n: a number to be represented in binary form
 */
void _print_binary(unsigned long int n)
{
	if (n == 0)
		return;

	_print_binary(n / 2);
	_putchar('0' + (n % 2));
}
