#include <stdio.h>
#include <stdlib.h>

int _change(int *, int, int);

/**
 * main - print minimum number of coins needed to pay
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 if 2 arguments passed, else 1
 */
int main(int argc, char *argv[])
{
	int num, coins;

	if (argc != 2)
	{
		puts("Error");
		return (1);
	}

	num = atoi(argv[1]);

	coins = 0;
	coins = _change(&num, coins, 25);
	coins = _change(&num, coins, 10);
	coins = _change(&num, coins, 5);
	coins = _change(&num, coins, 2);
	coins = _change(&num, coins, 1);

	printf("%d\n", coins);

	return (0);
}

/**
 * _change - add coins of a value
 * @num: amount of cents
 * @coins: number of coins needed so far
 * @value: value of coin being considered
 *
 * Return: number of coins needed so far
 */
int _change(int *num, int coins, int value)
{
	while (*num >= value)
	{
		coins++;
		*num -= value;
	}

	return (coins);
}
