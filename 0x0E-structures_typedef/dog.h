#ifndef _DOG_H_
#define _DOG_H_

void _putchar(char);

/**
 * struct dog - describes a dog
 * @name: name of dog
 * @age: age of dog
 * @owner: name of owner of dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_t;

#endif /* #ifndef _DOG_H_ */
