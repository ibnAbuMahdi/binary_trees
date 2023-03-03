#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: the tree
 * Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h = 0, d = 0;

	if (tree)
		measure(tree, d, &h);
	return (h);
}

/**
 * measure - measures the height
 * @tree: the tree
 * @d: the path length
 * @h: the max height
 * Return: nothing
 */

void measure(const binary_tree_t *tree, size_t d, size_t *h)
{
	if (tree->left)
	{
		d++;
		measure(tree->left, d, h);
	}
	if (tree->right)
	{
		if (!(tree->left))
			d++;
		measure(tree->right, d, h);
	}
	if (d > *h)
		*h = d;
}


