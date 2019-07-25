#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * main - entry point
 * @argc: number of args provided
 * @argv: args provided to the program
 *
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	if (argc != 4)
		return (-1);

	printf("%d\n", get_op_func(argv[2])(atoi(argv[1]), atoi(argv[3])));

	return (0);
}
