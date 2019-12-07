#include "binary_trees.h"

/**
 * bst_search - find a node in a bst
 * @tree: bst to search
 * @value: value of node to find
 *
 * Return: Pointer to node with value, or NULL if no such node
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	while (tree)
	{
		if (value > tree->n)
			tree = tree->right;
		else if (value < tree->n)
			tree = tree->left;
		else
			return ((bst_t *) tree);
	}

	return (NULL);
}

/**
 * bst_insert - insert a node into a bst
 * @tree: tree to insert node into
 * @value: value for new node to hold
 *
 * Return: pointer to new node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *p;

	if (!tree)
		return (NULL);
	new = binary_tree_node(NULL, value);
	if (!new)
		return (NULL);
	p = *tree;
	if (!p)
		*tree = new;
	else
		while (p)
		{
			if (value < p->n)
			{
				if (!p->left)
				{
					p->left = new;
					new->parent = p;
					break;
				}
				p = p->left;
			}
			else if (value > p->n)
			{
				if (!p->right)
				{
					p->right = new;
					new->parent = p;
					break;
				}
				p = p->right;
			}
			else
			{
				free(new);
				return (NULL);
			}
		}
	return (new);
}

/**
 * bt_height - get raw height of a binary tree
 * @tree: tree to find height of
 *
 * Return: the height of the tree.
 */
size_t bt_height(const binary_tree_t *tree)
{
	size_t a, b;

	if (!tree)
		return (0);

	a = bt_height(tree->left);
	b = bt_height(tree->right);
	return (1 + (a > b ? a : b));
}

/**
 * _binary_tree_is_avl - recursively check if a binary tree is an AVL tree
 * @tree: tree to inspect
 *
 * Return: 1 if binary tree is an AVL tree, else 0
 */
int _binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;

	if (!tree)
		return (1);

	balance = bt_height(tree->left) - bt_height(tree->right);
	if (balance * balance > 1)
		return (0);

	return (_binary_tree_is_avl(tree->left) && _binary_tree_is_avl(tree->right));
}

/**
 * avl_insert - insert a node into an AVL tree
 * @tree: tree to insert node into
 * @value: value of node to insert
 *
 * Return: address of newly inserted node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new, *p;
	int a;

	if (!tree || bst_search(*tree, value))
		return (NULL);
	new = bst_insert(tree, value);
	if (!new)
		return (NULL);

	p = new;
	if (!_binary_tree_is_avl(*tree))
		while (p->parent)
		{
			a = binary_tree_balance(p->parent);
			a = a * a;
			if (a < 2 && p->parent->parent &&
				((p->n > p->parent->n && p->parent->n > p->parent->parent->n)
				|| (p->n < p->parent->n && p->parent->n < p->parent->parent->n)))
				p = p->parent;
			else if (p->n > p->parent->n)
				p = binary_tree_rotate_left(p->parent);
			else
				p = binary_tree_rotate_right(p->parent);

			if (a > 1)
			{
				a = 0;
				while (p->parent)
				{
					a = binary_tree_balance(p->parent);
					if (a > 1)
						break;
					p = p->parent;
				}
			}
		}
	if (!p->parent)
		*tree = p;

	return (new);
}
