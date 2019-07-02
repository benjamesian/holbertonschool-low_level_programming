#include <limits.h>

/**
 * _atoi - Convert a string to an integer
 * @s: A string
 *
 * Return: An integer found in a string or 0
 */
int _atoi(char *s)
{
	int i, t, is_neg;
	unsigned int num;
	int found_number = -1;

	is_neg = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			if (found_number > -1)
				break;
			is_neg += (s[i] == '-');
		}
		else if (found_number == -1)
			found_number = i;
	}
/*
 *	i -= found_number;
 */
	num = 0;
	t = 1;
	if (found_number > -1)
	{
		while (found_number - i)
		{
			num = num * 10 + s[found_number] - '0';
			if (num > (unsigned int) INT_MAX)
				return ((is_neg % 2) ? INT_MIN : INT_MAX);
			found_number++;
			t *= 10;
		}
	}

	return ((int) ((is_neg % 2) ? -num : num));
}
