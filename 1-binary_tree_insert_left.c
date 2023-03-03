#include "binary_trees.h"

/**
 * binary_tree_insert_left- create a tree node
 * @parent: the parent node
 * @val: the value of the node
 * Return: the pointer to the node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int val)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!node || !parent)
		return (NULL);
	if (parent->left)
	{
		binary_tree_t *lnode = parent->left;

		node->parent = parent;
		parent->left = node;
		node->left = lnode;
		node->right = NULL;
		node->n = val;
		lnode->parent = node;

	}
	else
	{
		parent->left = node;
		node->parent = parent;
		node->left = NULL;
		node->right = NULL;
		node->n = val;
	}

	return (node);
}
