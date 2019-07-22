#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - make a dog
 * @d: pointer to new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: name of owner of dog
 *
 * Return: pointer to newly initialized dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
