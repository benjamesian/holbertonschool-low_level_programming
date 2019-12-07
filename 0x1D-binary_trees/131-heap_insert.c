#include "binary_trees.h"

/**
 * binary_tree_size - get the size of a binary tree
 * @tree: tree to find the size of
 *
 * Return: size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 +
		binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}

/**
 * find_next_parent - find next node that can hold a child
 * @root: root of the tree
 * @size: size of the tree
 *
 * Return: next parent
 */
heap_t *find_next_parent(heap_t *root, size_t size)
{
	if (size < 2)
		return (root);
	if (size % 2)
		return (find_next_parent(root, size / 2)->right);
	return (find_next_parent(root, size / 2)->left);
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
	{
		p = find_next_parent(p, (binary_tree_size(p) + 1) / 2);
		new->parent = p;
		if (p->left)
			p->right = new;
		else
			p->left = new;

		p = new;
		while (p->parent && p->parent->n < p->n)
		{
			temp = p->n;
			p->n = p->parent->n;
			p->parent->n = temp;
			p = p->parent;
		}
	}
	return (p);
}
