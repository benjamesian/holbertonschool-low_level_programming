char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, l1, l2, l3, d_sum, tmp;

	for (l1 = 0; n1[l1] != '\0'; l1++)
		;
	for (l2 = 0; n2[l2] != '\0'; l2++)
		;

	l3 = 0;
	r[0] = '0';
	while (l1 && l2)
	{
		l1--;
		l2--;
		d_sum = (r[l3] - '0') + (n1[l1] - '0') + (n2[l2] - '0');
		r[l3] = '0' + d_sum % 10;
		r[l3 + 1] = '0' + d_sum / 10;
		l3++;
	}

	do {
		if (l1)
		{
			r[l3] += n1[l1];
			l1--;
		}
		else if (l2)
		{
			r[l3] += n2[l2];
			l2--;
		}
		r[l3 + 1] = '0';
		if (r[l3] > '9')
		{
			r[l3] = '0';
			r[l3 + 1] = '1';
		}

		l3++;
	} while (l1 || l2);
	if (r[l3] == '1')
		l3++;
	r[l3] = '\0';

	for (i = 0; i < l3 / 2; i++)
	{
		tmp = r[i];
		r[i] = r[l3 - i - 1];
		r[l3 - i - 1] = tmp;
	}

	if (l3 >= size_r)
		return (0);

	return (r);
}
