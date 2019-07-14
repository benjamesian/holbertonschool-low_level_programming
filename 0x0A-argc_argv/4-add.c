#include <stdio.h>
#include <stdlib.h>

/**
 * main - print result of addition of arguments
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 if only positive integer args passed (after program name), else 1
 */
int main(int argc, char *argv[])
{
	int i, sum;

	sum = 0;
	while (argc-- > 1)
	{
		for (i = 0; argv[argc][i] != '\0'; i++)
			if (argv[argc][i] > '9' || argv[argc][i] < '0')
			{
				puts("Error");
				return (1);
			}

		sum += atoi(argv[argc]);
	}

	printf("%d\n", sum);

	return (0);
}
