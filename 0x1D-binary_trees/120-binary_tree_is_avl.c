#include "binary_trees.h"
#include <limits.h>


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
 * _binary_tree_is_bst - recursively check if a binary tree is a bst
 * @node: node to inspect
 * @prev: a parent of the current node or the same as node
 *
 * Return: 1 if tree is a bst, else 0
 */
int _binary_tree_is_bst(const binary_tree_t *node, const binary_tree_t *prev)
{
	if (!node)
		return (1);

	if (node->n == prev->n)
	{
		return ((node->left ? node->left->n < prev->n : 1)
			&& (node->right ? node->right->n > prev->n : 1)
			&& _binary_tree_is_bst(node->left, prev)
			&& _binary_tree_is_bst(node->right, prev));
	}
	else if (node->n < prev->n)
	{
		return ((node->left ? node->left->n < prev->n : 1)
			&& (node->right ? node->right->n < prev->n : 1)
			&& _binary_tree_is_bst(node->right, prev));
	}
	else
	{
		return ((node->left ? node->left->n > prev->n : 1)
			&& (node->right ? node->right->n > prev->n : 1)
			&& _binary_tree_is_bst(node->left, prev));
	}
}

/**
 * binary_tree_is_bst - check if a binary tree is a bst
 * @tree: tree to inspect
 *
 * Return: 1 if tree is a bst, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_binary_tree_is_bst(tree, tree)
		&& (tree->left ? binary_tree_is_bst(tree->left) : 1)
		&& (tree->right ? binary_tree_is_bst(tree->right) : 1));
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
 * binary_tree_is_avl - check if a binary tree is an AVL tree
 * @tree: tree to inspect
 *
 * Return: 1 if binary tree is an AVL tree, else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_is_bst(tree) && _binary_tree_is_avl(tree));
}
