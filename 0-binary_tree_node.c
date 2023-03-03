#include "binary_trees.h"

/**
 * binary_tree_node - create a tree node
 * @parent: the parent node
 * @val: the value of the node
 * Return: the pointer to the node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int val)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);

	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = val;

	return (node);
}
