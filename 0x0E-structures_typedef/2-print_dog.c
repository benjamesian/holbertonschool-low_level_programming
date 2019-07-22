#include <stdlib.h>
#include <stdio.h>
#include "dog.h"

/**
 * print_dog - print info about a dog
 * @d: struct containing info about a dog
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	printf("Name: %s\n", (d->name == NULL) ? "(nil)" : d->name);
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", (d->owner == NULL) ? "(nil)" : d->owner);
}
