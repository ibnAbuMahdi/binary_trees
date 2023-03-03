#include "binary_trees.h"

/**
 * binary_tree_leaves - count the leaves in a binary tree
 * @tree: the tree
 * Return: number of leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t size;

	if (tree)
	{
		if (tree->left)
			size = binary_tree_leaves(tree->left);
		if (tree->right)
		{
			if (tree->left)
				size = size + binary_tree_leaves(tree->right);
			else
				size = binary_tree_leaves(tree->right);
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
