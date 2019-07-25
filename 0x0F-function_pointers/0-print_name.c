#include <stdlib.h>

/**
 * print_name - print a name
 * @name: name to print
 * @f: printer
 */
void print_name(char *name, void (*f)(char *))
{
	if (f == NULL)
		return;
	f(name);
}
