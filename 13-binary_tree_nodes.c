#include "binary_trees.h"

/**
 * binary_tree_nodes - count the number of nodes with atleast one child
 * @tree: the tree
 * Return: number of nodes
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t size;

	if (tree)
	{
		if (tree->left)
		{
			if (!(tree->left->left) && !(tree->left->right))
				return (1);
			size = binary_tree_nodes(tree->left);
		}
		if (tree->right)
		{
			if (!(tree->right->left) && !(tree->right->right))
				return (1);
			if (tree->left)
				size = size + binary_tree_nodes(tree->right);
			else
				size = binary_tree_nodes(tree->right);
		}
		if ((tree->left) || (tree->right))
			size = size + 1;
		else
			size = 0;
		return (size);
	}
	else
	{
		return (0);
	}
}
