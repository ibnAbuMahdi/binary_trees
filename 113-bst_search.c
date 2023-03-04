#include "binary_trees.h"

/**
 * bst_search - search the bst for val
 * @tree: the tree
 * @val: the value to find
 * Return: the node if found or NULL o.w.
 */

bst_t *bst_search(const bst_t *tree, int val)
{
	bst_t *node = NULL;

	if (!tree)
		return (NULL);
	if (tree->left)
	{
		node = bst_search(tree->left, val);
	}
	if (tree->right)
		if (!node)
			node = bst_search(tree->right, val);

	if (tree->n == val)
		return ((bst_t *) tree);
	return (node);
}


