#include "binary_trees.h"

/**
 * bst_insert - insert a node into bst
 * @tree: memory address of the pointer to the tree
 * @val: the value of the new node to insert
 * Return: a pointer to the newly created node
 */

bst_t *bst_insert(bst_t **tree, int val)
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
		return (node);
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
		return (NULL);
	if (val > temp->n)
		add_node(temp, node, 1);
	else
		add_node(temp, node, -1);
	return (node);
}

/**
 * add_node - adds a node to a bst tree
 * @leaf: the leaf node
 * @new: the new node to add to leaf
 * @pos: left or right
 * Return: nothing
 */

void add_node(bst_t *leaf, bst_t *new, int pos)
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


