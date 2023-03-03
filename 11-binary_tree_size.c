#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree @tree
 * @tree: the tree
 * Return: the size
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	if (tree)
	{
		if (tree->left)
			size = binary_tree_size(tree->left) + 1;
		if (tree->right)
		{
			if (!(tree->left))
				size = binary_tree_size(tree->right) + 1;
			else
				size = size + binary_tree_size(tree->right);
		}
		if (!(tree->left) && !(tree->right))
			size = 1;
		return (size);
	}
	else
	{
		return (0);
	}
}
