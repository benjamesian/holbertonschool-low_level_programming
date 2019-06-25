#include "holberton.h"

int print_last_digit(int n)
{
	int _abs = n < 0 ? -n : n;
	_putchar('0' + _abs % 10);
	return (_abs % 10);
}
