#include <stdio.h>
#include <stdlib.h>

/**
 * main - do multiplication between 2 args
 * @argc: number of arguments passed, should be 3
 * @argv: arguments passed
 *
 * Return: 0 if 3 arguments passed, else 1
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		puts("Error");
		return (1);
	}

	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));

	return (0);
}
