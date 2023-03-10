#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <limits.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s bst_t;

typedef struct binary_tree_s avl_t;

binary_tree_t *binary_tree_node(binary_tree_t *, int);

void binary_tree_print(const binary_tree_t *tree);

binary_tree_t *binary_tree_insert_left(binary_tree_t *, int);

binary_tree_t *binary_tree_insert_right(binary_tree_t *, int);

void binary_tree_delete(binary_tree_t *);

int binary_tree_is_leaf(const binary_tree_t *);

int binary_tree_is_root(const binary_tree_t *node);

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

size_t binary_tree_height(const binary_tree_t *tree);

void measure(const binary_tree_t *, size_t, size_t *);

void measure_sub(const binary_tree_t *, int, int *);

size_t binary_tree_depth(const binary_tree_t *tree);

size_t binary_tree_size(const binary_tree_t *tree);

size_t binary_tree_leaves(const binary_tree_t *tree);

size_t binary_tree_nodes(const binary_tree_t *);

int binary_tree_is_full(const binary_tree_t *);

int binary_tree_balance(const binary_tree_t *);

int binary_tree_is_perfect(const binary_tree_t *);

void check(const binary_tree_t *, size_t, size_t *, int *);

binary_tree_t *binary_tree_sibling(binary_tree_t *node);

binary_tree_t *binary_tree_uncle(binary_tree_t *);

binary_tree_t *binary_trees_ancestor(const binary_tree_t *, const binary_tree_t *);

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

void dive(const binary_tree_t *, void (*func)(int), int, int);

int binary_tree_is_complete(const binary_tree_t *);

void check_c(const binary_tree_t *, int, size_t *, int *, int);

binary_tree_t *binary_tree_rotate_left(binary_tree_t *);

binary_tree_t *binary_tree_rotate_right(binary_tree_t *);

int binary_tree_is_bst(const binary_tree_t *);

int check_bst(const binary_tree_t *, int *);

bst_t *bst_insert(bst_t **tree, int value);

void add_node(bst_t *, bst_t *, int);

bst_t *array_to_bst(int *, size_t);

bst_t *insert_bst(bst_t **tree, int value);

void add_node_bst(bst_t *, bst_t *, int);

bst_t *bst_search(const bst_t *, int);
#endif /* BINARY_TREES_H */
