#include "binary_trees.h"

/**
 * binary_tree_is_perfect - check whether a binary tree is perfect
 * @tree: the tree
 * Return: 1 if perfect, 0 o.w.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h = 0, d = 0;
	int p = 1;

	if (tree)
		check(tree, d, &h, &p);
	return (p);
}

/**
 * check - check whether tree @tree is perfect
 * @tree: the tree
 * @d: the path length
 * @h: the max height
 * @p: switch for perfect
 * Return: nothing
 */

void check(const binary_tree_t *tree, size_t d, size_t *h, int *p)
{
	if (tree->left)
	{
		d++;
		check(tree->left, d, h, p);
	}
	if (tree->right)
	{
		if (!(*p))
			return;
		if (!(tree->left))
			d++;
		check(tree->right, d, h, p);
	}
	if (d == 0 && !(tree->left) && !(tree->right))
	{
		*p = 0;
		return;
	}
	if (*h > 0 && d != *h && !(tree->left) && !(tree->right))
		*p = 0;

	if (d > *h)
		*h = d;
}


