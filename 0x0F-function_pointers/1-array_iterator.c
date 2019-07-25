#include <stdlib.h>

/**
 * array_iterator - execute action on array elements
 * @array: array with elements
 * @size: size of array
 * @action: action to perform on array elements
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	int i;

	if (action == NULL || array == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
