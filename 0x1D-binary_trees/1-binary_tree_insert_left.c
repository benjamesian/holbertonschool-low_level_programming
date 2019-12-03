#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a new node to the left of parent.
 * @parent: parent node
 * @value: value for new node to store
 *
 * Return: pointer to the newly created node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = parent->left;
	if (new->left)
		new->left->parent = new;
	new->right = NULL;

	parent->left = new;

	return (new);
}
