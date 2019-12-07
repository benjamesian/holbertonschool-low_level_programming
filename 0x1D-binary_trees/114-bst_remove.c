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
 * get_next_in_order_node - find next highest valued node in order
 * @tree: tree to search
 * @value: value which should be less than next nodes value
 *
 * Return: next in-order node
 */
bst_t *get_next_in_order_node(const bst_t *tree, int value)
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
 * get_child - get a child of a node if it exists
 * @node: bst
 *
 * Return: the child or NULL
 */
bst_t *get_child(bst_t *node)
{
	if (node->left)
		return (node->left);
	return (node->right);
}

/**
 * assign_parent_child - assign a parent's child
 * @old_child: the original child
 * @new_child: the new child
 */
void assign_parent_child(bst_t *old_child, bst_t *new_child)
{
	if (old_child == old_child->parent->left)
		old_child->parent->left = new_child;
	else
		old_child->parent->right = new_child;
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
	bst_t *remove, *next;

	remove = bst_search(root, value);
	if (!remove)
		return (root);
	if (!(remove->left && remove->right))
	{ /* node to replace is not full, simple replacement */
		next = get_child(remove);
		if (next)
			next->parent = remove->parent;
	}
	else
	{ /* need to replace with next in-order node (not necessarily a child) */
		next = get_next_in_order_node(remove, value);
		if (next == next->parent->left)
		{ /* next has no left child */
			next->parent->left = next->right;
			if (next->right)
				next->right->parent = next->parent;
			next->right = remove->right;
			remove->right->parent = next;
		}
		next->left = remove->left;
		if (next->left)
			next->left->parent = next;
		next->parent = remove->parent;
	}
	if (remove == root)
		root = next;
	else
		assign_parent_child(remove, next);
	free(remove);
	root->parent = NULL;
	return (root);
}
