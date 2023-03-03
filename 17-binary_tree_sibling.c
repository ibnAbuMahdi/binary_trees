#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling of node @node
 * @node: the node
 * Return: the pointer to the sibling node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = node->parent;

	if (!node || !parent)
		return (NULL);

	if ((node == parent->left && !(parent->right)) || (node == parent->right
			&& !(parent->left)))

		return (NULL);

	if (node == parent->left)
		return (parent->right);
	return (parent->left);
}
