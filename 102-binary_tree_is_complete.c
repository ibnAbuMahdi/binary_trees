#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * binary_tree_is_complete - check whether a binary tree is complete
 * @tree: the tree
 * Return: 1 if complete, 0 o.w.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t e = 0;
	int c = 1, h = 0, d = 0;

	if (tree)
	{	h = binary_tree_height(tree);
		check_c(tree, d, &e, &c, h);
	}
	return (c);
}

/**
 * check_c - check whether tree @tree is complete
 * @tree: the tree
 * @d: the depth
 * @h: the max height
 * @c: switch for complete
 * @e: switch to check leaves are to the right
 * Return: nothing
 */

void check_c(const binary_tree_t *tree, int d, size_t *e, int *c, int h)
{
	const binary_tree_t *lleaf = !(tree->left) && (tree->right) ? tree
		: NULL;
	const binary_tree_t *rleaf = (tree->left) && !(tree->right) ? tree
		: NULL;

	if (tree->left)
	{
		d++;
		check_c(tree->left, d, e, c, h);
	}
	if (tree->right)
	{
		if (!(*c))
			return;
		if (!(tree->left))
			d++;
		check_c(tree->right, d, e, c, h);
	}
	if (tree == lleaf || (*e && (tree == lleaf || tree == rleaf)) ||
			(tree == rleaf && d < h))
	{
		*c = 0;
		return;
	}

	if (tree == rleaf)
		*e = 1;
}


