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
 * next_in_order - find next highest valued node in order
 * @tree: tree to search
 * @value: value which should be less than next nodes value
 *
 * Return: next in-order node
 */
bst_t *next_in_order(const bst_t *tree, int value)
{
	const bst_t *next = NULL;

	while (tree)
	{
		if (value >= tree->n)
			tree = tree->right;
		else if (value < tree->n)
		{
			next = tree;
			tree = tree->left;
		}
	}

	return ((bst_t *) next);
}

/**
 * is_left_child - check if a node is a left child of another node
 * @node: a node
 *
 * Return: 1 if node is a left child, else 0
 */
int is_left_child(bst_t *node)
{
	return (node && node->parent && node == node->parent->left);
}

/**
 * bst_remove - remove a node from a bst
 * @root: root node of the tree
 * @value: value of node to remove
 *
 * Return: pointer to root of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node_to_replace, *next_node_in_order;

	node_to_replace = bst_search(root, value);
	if (!node_to_replace)
		return (root);
	next_node_in_order = next_in_order(node_to_replace, value);
	if (!next_node_in_order)
	{
		if (node_to_replace == root)
			root = node_to_replace->left;
		else if (is_left_child(node_to_replace))
			node_to_replace->parent->left = node_to_replace->left;
		else
			node_to_replace->parent->right = node_to_replace->left;
	}
	else
	{
		if (is_left_child(next_node_in_order))
			next_node_in_order->parent->left = next_node_in_order->right;
		else
			next_node_in_order->parent->right = next_node_in_order->right;
		if (next_node_in_order->right)
			next_node_in_order->right->parent = next_node_in_order->parent;
		next_node_in_order->left = node_to_replace->left;
		if (node_to_replace->left)
			node_to_replace->left->parent = next_node_in_order;
		next_node_in_order->right = node_to_replace->right;
		if (node_to_replace->right)
			node_to_replace->right->parent = next_node_in_order;
		next_node_in_order->parent = node_to_replace->parent;
		if (node_to_replace == root)
			root = next_node_in_order;
		else if (is_left_child(node_to_replace))
			next_node_in_order->parent->left = next_node_in_order;
		else
			next_node_in_order->parent->right = next_node_in_order;
	}
	free(node_to_replace);
	root->parent = NULL;
	return (root);
}
