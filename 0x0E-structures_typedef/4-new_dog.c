#include <stdlib.h>
#include "dog.h"

char *_strdup(char *s);

/**
 * new_dog - make a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the owner of the dog
 *
 * Return: pointer to the new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	if (name == NULL || owner == NULL)
		return (NULL);

	d = malloc(sizeof(*d));
	if (d == NULL)
		return (NULL);

	d->name = _strdup(name);
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}
	d->age = age;
	d->owner = _strdup(owner);
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	return (d);
}

/**
 * _strdup - duplicate a string on the heap
 * @s: string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(char *s)
{
	char *buffer, *tmp;
	int i;

	for (i = 0; s[i]; i++)
		;

	buffer = malloc(sizeof(*buffer) * i);
	if (buffer == NULL)
		return (NULL);

	tmp = buffer;

	while ((*tmp++ = *s++))
		;

	return (buffer);
}
