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
	char op;

	if (argc != 4)
	{
		puts("Error");
		exit(98);
	}

	op = argv[2][0];
	if (!(op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
	    || argv[2][1] != '\0')
	{
		puts("Error");
		exit(99);
	}

	if ((op == '/' || op == '%') && atoi(argv[3]) == 0)
	{
		puts("Error");
		exit(100);
	 }

	printf("%d\n", get_op_func(argv[2])(atoi(argv[1]), atoi(argv[3])));

	return (0);
}
