/**
 * _atoi - Convert a string to an integer
 * @s: A string
 *
 * Return: An integer found in a string or 0
 */
int _atoi(char *s)
{
	int i, num, t, is_neg;
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
	i -= found_number;

	num = 0;
	t = 1;
	if (found_number > -1)
	{
		if (i > 10) /* INT_MAX len */
			return (-1);
		while (i)
		{
			num += (s[found_number + i - 1] - '0') * t;
			if (num < 0)
			{
				if (num - 1 > 0)
					return (num);
				else
					return (-1);
			}
			i--;
			t *= 10;
		}
	}

	return ((is_neg % 2) ? -num : num);
}
