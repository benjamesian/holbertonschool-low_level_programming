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
	int op_len;
	char op;

	if (argc != 4)
	{
		puts("Error");
		exit(98);
	}

	op_len = strlen(argv[2]);

	op = argv[2][0];
	if (op_len != 1 ||
	    !(op == '+' || op == '-' || op == '*' || op == '/' || op == '%'))
	{
		puts("Error");
		exit(99);
	}

	if (!(strcmp("%", argv[2]) && strcmp("/", argv[2])) && !atoi(argv[3]))
	{
		puts("Error");
		exit(100);
	}


	printf("%d\n", get_op_func(argv[2])(atoi(argv[1]), atoi(argv[3])));

	return (0);
}
