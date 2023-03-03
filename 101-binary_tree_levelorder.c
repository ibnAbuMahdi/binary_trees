#include "binary_trees.h"

/**
 * binary_tree_levelorder - levelorder traversal of a binary tree
 * @tree: the tree
 * @func: pointer to a function to call for each node.
 * Return: nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int r = 0;

	if (tree && func)
	{
		size_t h = binary_tree_height(tree);
		int d = 0;

		while ((size_t) d <= h)
		{
			dive(tree, func, d, r);
			d++;
		}
	}
}

/**
 * dive - dives to the required depth and exec @func on node data
 * @tree: the tree
 * @func: the func to call on node data
 * @d: the depth to print nodes
 * @r: height tracker
 */

void dive(const binary_tree_t *tree, void (*func)(int), int d, int r)
{
	if (r == d)
	{
		func(tree->n);
		return;
	}
	if (tree->left)
	{
		r++;
		dive(tree->left, func, d, r);
	}
	if (tree->right)
	{
		if (!(tree->left))
			r++;
		dive(tree->right, func, d, r);
	}
}

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


