#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if node is leaf
 * @node: the node
 * Return: 1 if node is leaf, o.w. 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node)
	{
		if (node->left || node->right)
			return (0);
		else
			return (1);
	}
	return (0);
}
