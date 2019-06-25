#include "holberton.h"

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
