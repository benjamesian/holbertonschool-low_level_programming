#include <stdio.h>

/**
 * main - print arguments passed to program
 * @argc: number of arguments passed to program
 * @argv: arguments passed to program
 *
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	int i = 0;

	while (argc--)
	{
		puts(argv[i]);
		i++;
	}

	return (0);
}
