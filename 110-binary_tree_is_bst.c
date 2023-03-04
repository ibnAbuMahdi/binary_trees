#include "binary_trees.h"

/**
 * binary_tree_is_bst - check whether a binary tree is bst
 * @tree: the tree
 * Return: 1 if bst, 0 o.w.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int min, b = 1;

	if (tree)
	{
		min = check_bst(tree, &b);
		(void) min;
	}
	return (tree ? b : 0);
}

/**
 * check_bst - check whether tree @tree is bst
 * @tree: the tree
 * @b: switch for bst
 * Return: Max if left or Min if right
 */

int check_bst(const binary_tree_t *tree, int *b)
{
	int max, min;
	binary_tree_t *parent = tree->parent;

	if (tree->left)
		max = check_bst(tree->left, b);
	if (tree->right)
		min = check_bst(tree->right, b);
	if (!(tree->right) && !(tree->left))
		return (tree->n);

	if ((tree->left && !(tree->right) && max >= tree->n) || (tree->right &&
				!(tree->left) && min <= tree->n) ||
			(tree->right && tree->left &&
			 (max >= tree->n || min <= tree->n)))
	{
		*b = 0;
		return (tree->left ? max : min);
	}
	else if (parent && parent->left == tree)
	{
		if (!(tree->right))
			return (tree->n);
		return (min);
	}
	else if (parent && parent->right == tree)
	{
		if (!(tree->left))
			return (tree->n);
		return (max);
	}
	return (INT_MAX);

}


