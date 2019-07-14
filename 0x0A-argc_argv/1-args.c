#include <stdio.h>

/**
 * main - print number of arguments passed to program
 * @argc: number of arguments passed to program
 * @argv: arguments passed to program
 *
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	(void) argv;

	printf("%d\n", argc - 1);

	return (0);
}
