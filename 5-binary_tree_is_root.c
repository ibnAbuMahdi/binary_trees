#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if node is root
 * @node: the node
 * Return: 1 if node is root, o.w. 0
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node)
	{
		if (node->parent)
			return (0);
		else
			return (1);
	}
	return (0);
}
