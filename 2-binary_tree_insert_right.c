#include "binary_trees.h"

/**
 * binary_tree_insert_right - create a tree node and insert it to \
 * the right of @parent
 * @parent: the parent node
 * @val: the value of the node
 * Return: the pointer to the node or NULL if parent is NULL or on fail
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int val)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!node || !parent)
		return (NULL);
	if (parent->right)
	{
		binary_tree_t *lnode = parent->right;

		node->parent = parent;
		parent->right = node;
		node->right = lnode;
		node->left = NULL;
		node->n = val;
		lnode->parent = node;

	}
	else
	{
		parent->right = node;
		node->parent = parent;
		node->right = NULL;
		node->left = NULL;
		node->n = val;
	}

	return (node);
}
