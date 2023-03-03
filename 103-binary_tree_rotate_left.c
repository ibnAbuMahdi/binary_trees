#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate tree left
 * @tree: the tree
 * Return: the new root node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	int rh, i = 1, mid;
	binary_tree_t *temp, *temp2, *temp3, *gparent;

	if (tree)
	{
		temp2 = temp = tree;
		rh = 1;
		while (temp->right)
		{
			rh++;
			temp = temp->right;
		}
		if (rh == 1)
			return (tree);
		mid = rh % 2 == 0 ? rh / 2 : (rh / 2) + 1;
		mid = mid == 1 ? 2 : mid;

		while (i < mid)
		{
			temp2 = temp2->right;
			i++;
		}
		temp3 = temp2->left;
		temp2->parent->right = temp3;
		gparent = temp2->parent->parent;
		temp2->parent->parent = temp2;
		temp2->left = temp2->parent;
		if (temp3)
			temp3->parent = temp2->left;
		temp2->parent = gparent;
		if (gparent && gparent->right == temp2->left)
			gparent->right = temp2;
		else if (gparent && gparent->left == temp2->left)
			gparent->left = temp2;
		return (temp2);

	}
	return (NULL);
}
