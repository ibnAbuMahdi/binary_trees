#include "binary_trees.h"

/**
 * binary_tree_uncle - find the uncle of node @node
 * @node: the node
 * Return: the pointer to the uncle node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent = node->parent, *gparent;

	if (!node || !parent || !(parent->parent))
		return (NULL);
	gparent = parent->parent;
	if ((parent == gparent->left && !(gparent->right)) || (parent ==
				gparent->right && !(gparent->left)))

		return (NULL);

	if (parent == gparent->left)
		return (gparent->right);
	return (gparent->left);
}
