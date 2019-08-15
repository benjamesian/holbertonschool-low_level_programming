#include <stdlib.h>

int count_seps(char *, char);
int count_until(char *, char);

/**
 * strtow - cut string into words array
 * @str: string
 *
 * Return: pointer to array of words
 */
char **strtow(char *str)
{
	char **p, **tmp, **cpy;
	char *pc;
	int i;
	int nwords = 0;

	if (!str || !*str)
		return (NULL);

	nwords = count_seps(str, ' ');
	p = malloc((nwords + 1) * sizeof(*p));
	if (!nwords || !p)
		return (NULL);

	tmp = p;

	while (*str)
	{
		while (*str == ' ')
			str++;
		if (!*str)
			break;
		i = count_until(str, ' ');
		*p = malloc(i * sizeof(**p));
		if (!*p)
		{
			cpy = tmp;
			while (tmp != p)
				free(*tmp++);
			free(cpy);
			return (NULL);
		}
		pc = *p;
		while (*str && *str != ' ')
			*pc++ = *str++;
		*pc = '\0';
		p++;
	}
	*p = NULL;

	return (tmp);
}

/**
 * count_seps - count words
 * @str: string
 * @sep: word sep
 *
 * Return: number of words
 */
int count_seps(char *str, char sep)
{
	if (!*str)
		return (0);

	while (*str == sep)
		str++;

	if (*str)
	{
		while (*str && *str++ != sep)
			;
		return (1 + count_seps(str, sep));
	}
	else
		return (0);
}

/**
 * count_until - count until break
 * @str: string
 * @stop: when to stop counting
 *
 * Return: num chars until stop
 */
int count_until(char *str, char stop)
{
	int i = 0;

	while (str && *str != stop)
	{
		str++;
		i++;
	}

	return (i);
}
