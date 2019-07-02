int _atoi(char *s)
{
	int i, j, n, t, is_neg;
	int found_number = -1;

	j = 0;
	is_neg = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			if (found_number > -1)
				break;
			else
				is_neg += (s[i] == '-');
		}

		j++;
		if (found_number == -1 && s[i] >= '0' && s[i] <= '9')
		{
			found_number = i;
			j = 0;
		}
	}

	n = 0;
	t = 1;
	if (found_number > -1)
	{
		while (j + 1)
		{
			n += (s[found_number + j] - '0') * t;
			j--;
			t *= 10;
		}
	}

	return (is_neg % 2) ? -n : n;
}
