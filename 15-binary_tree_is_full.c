#include "binary_trees.h"

/**
 * binary_tree_is_full - check whether tree @tree is full
 * @tree: the tree
 * Return: 1 if full, 0 o.w.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree)
	{
		if (tree->left)
		{
			size = binary_tree_is_full(tree->left);
		}
		if (tree->right)
		{
			if (size == 1)
				size = binary_tree_is_full(tree->right);
		}
		if (((tree->left) && !(tree->right)) || ((tree->right) && !(tree->left)))
			size = 0;
		return (size);
	}
	else
	{
		return (0);
	}
}
