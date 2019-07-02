/**
 * _atoi - Convert a string to an integer
 * @s: A string
 *
 * Return: An integer found in a string or 0
 */
int _atoi(char *s)
{
	int i, num_len, num, t, is_neg;
	int found_number = -1;

	num_len = 0;
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
		{
			found_number = i;
			num_len = 0;
		}
		num_len++;
	}

	num = 0;
	t = 1;
	if (found_number > -1)
	{
		while (num_len)
		{
			num += (s[found_number + num_len - 1] - '0') * t;
			num_len--;
			t *= 10;
		}
	}

	return ((is_neg % 2) ? -num : num);
}
