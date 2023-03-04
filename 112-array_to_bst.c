#include "binary_trees.h"

/**
 * array_to_bst - convert an array into bst
 * @array: the array of values
 * @size: the size of the array
 * Return: a pointer to the root of the tree
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root = NULL;

	while (i < size)
	{
		root = insert_bst(&root, array[i]);
		i++;
	}
	return (root);
}

/**
 * insert_bst - insert a node into a bst
 * @tree: address of the pointer to the root
 * @val: the val of the new node
 * Return: pointer to the root
 */

bst_t *insert_bst(bst_t **tree, int val)
{
	bst_t *node = malloc(sizeof(bst_t));
	bst_t *head, *temp;

	if (!node)
		return (NULL);
	node->n = val;
	if (!*tree)
	{
		node->parent = NULL;
		node->left = NULL;
		node->right = NULL;
		*tree = node;
		return (*tree);
	}
	head = *tree;
	while (head && head->n != val)
	{
		if (val > head->n)
		{
			temp = head;
			head = head->right;
		}
		else
		{
			temp = head;
			head = head->left;
		}
	}
	if (head && head->n == val)
		return (*tree);
	if (val > temp->n)
		add_node(temp, node, 1);
	else if (val < temp->n)
		add_node(temp, node, -1);
	return (*tree);
}

/**
 * add_node_bst - adds a node to a bst tree
 * @leaf: the leaf node
 * @new: the new node to add to leaf
 * @pos: left or right
 * Return: nothing
 */

void add_node_bst(bst_t *leaf, bst_t *new, int pos)
{
	if (pos == 1)
	{
		leaf->right = new;
		new->parent = leaf;
	}
	else if (pos == -1)
	{
		leaf->left = new;
		new->parent = leaf;
	}
}


