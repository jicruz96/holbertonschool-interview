#include "binary_trees.h"
#include <limits.h>
#include <stdio.h>

/**
 * binary_tree_is_avl - determines if a binary tree is a valid AVL tree
 * @tree: pointer to tree
 * Return: 1 if tree is a valid AVL Tree | 0 if not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	return (is_bst(tree, INT_MIN, INT_MAX) && is_balanced(tree));
}

/**
 * is_balanced - determines whether a tree is balanced or not
 *
 * @tree: pointer to tree
 * Return: 1 if tree is balanced | 0 if not
 */
int is_balanced(const binary_tree_t *tree)
{
	return (
		tree &&
		(!tree->left || is_balanced(tree->left)) &&
		(!tree->right || is_balanced(tree->right)) &&
		(abs(tree_height(tree->right) - tree_height(tree->left)) <= 1)
	);
}

/**
 * is_bst - determines if a binary tree is a valid BST tree
 * @tree: pointer to tree
 * @min_val: minimum value allowed in tree
 * @max_val: maximum value allowed in tree
 * Return: 1 if tree is a valid BST Tree | 0 if not
 */
int is_bst(const binary_tree_t *tree, int min_val, int max_val)
{
	return (
		tree &&
		(
			!tree->right ||
			(
				tree->right->n > tree->n &&
				(tree->right->n < max_val || tree->right->n == INT_MAX) &&
				is_bst(tree->right, tree->n, max_val)
			)
		) &&
		(
			!tree->left  ||
			(
				tree->left->n < tree->n &&
				(tree->left->n > min_val || tree->left->n == INT_MIN) &&
				is_bst(tree->left, min_val, tree->n)
			)
		)
	);
}

/**
 * tree_height - computes the height of a binary tree
 *
 * @t: pointer to tree
 * Return: tree height
 */
int tree_height(const binary_tree_t *t)
{
	return (t ? 1 + max(tree_height(t->right), tree_height(t->left)) : 0);
}

/**
 * max - computes maximum of two numbers
 *
 * @a: number a
 * @b: number b
 * Return: max of a and b
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}
