#include "binary_trees.h"

/**
 * binary_tree_node - create a new node.
 * @parent: pointer to parent of new node.
 * @value: value that the new node should store.
 *
 * Return: A pointer to the newly created node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
