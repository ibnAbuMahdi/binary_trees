#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance of a binary tree
 * @tree: the tree
 * Return: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int hl = 0, hr = 0, r = 0, l = 0;

	if (!tree || (!(tree->left) && !(tree->right)))
		return (0);
	if (tree->left)
		measure_sub(tree->left, ++l, &hl);
	if (tree->right)
		measure_sub(tree->right, ++r, &hr);
	return (hl - hr);
}

/**
 * measure_sub - measures the height
 * @tree: the tree
 * @d: the path length
 * @h: the max height
 * Return: nothing
 */

void measure_sub(const binary_tree_t *tree, int d, int *h)
{
	if (tree->left)
	{
		d++;
		measure_sub(tree->left, d, h);
	}
	if (tree->right)
	{
		if (!(tree->left))
			d++;
		measure_sub(tree->right, d, h);
	}
	if (d > *h)
		*h = d;
}


