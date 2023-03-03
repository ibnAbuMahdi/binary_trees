#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of
 * nodes @first and @second
 * @first: the first node
 * @second: the second node
 * Return: pointer to the ancestor or NULL if not exists
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *temp;

	if (!first || !second)
		return (NULL);

	while (first)
	{
		temp = second;
		while (temp)
		{
			if (first == temp)
				return ((binary_tree_t *) first);
			temp = temp->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
