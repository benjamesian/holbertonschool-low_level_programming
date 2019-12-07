#include "binary_trees.h"

/**
 * max - return max value
 * @a: a value
 * @b: another value
 *
 * Return: The maximum of a and b
 */
size_t max(size_t a, size_t b)
{
	return (a > b ? a : b);
}

/**
 * _binary_tree_height - get raw height of a binary tree
 * @tree: tree to find height of
 *
 * Return: the height of the tree.
 */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + max(
		_binary_tree_height(tree->left),
		_binary_tree_height(tree->right)));
}

/**
 * binary_tree_balance - Check if a binary tree is balanced.
 * @tree: tree to inspect
 *
 * Return: balance factor of a binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_binary_tree_height(tree->left) -
		_binary_tree_height(tree->right));
}

/**
 * heap_insert - insert a new node into a max heap
 * @root: root value of new node
 * @value: value of node to insert
 *
 * Return: pointer to new node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *p;
	int temp;

	if (!root)
		return (NULL);
	new = binary_tree_node(NULL, value);
	if (!new)
		return (NULL);
	p = *root;
	if (!p)
		*root = new;
	else
		while (1)
		{
			if (!p->left)
			{
				p->left = new;
				new->parent = p;
			}
			else if (!p->right)
			{
				p->right = new;
				new->parent = p;
			}
			else if (binary_tree_balance(p) < 0 && binary_tree_balance(p->left) == 0)
				p = p->right;
			else
				p = p->left;
		}
	while (p->parent && p->parent->n < p->n)
	{
		temp = p->parent->n;
		p->parent->n = p->n;
		p->n = temp;
		p = p->parent;
	}

	return (new);
}
