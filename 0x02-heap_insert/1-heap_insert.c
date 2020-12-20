#include "binary_trees.h"
#include <stdio.h>

/**
 * heap_insert - insert a new node into a max binary heap
 * @head: head of heap
 * @value: value to add to heap
 * Return: pointer to new node
 **/
heap_t *heap_insert(heap_t **head, int value)
{
	heap_t *node, *tmp;
	int height;

	/* If no tree exists, make node head of tree and return */
	if (*head == NULL)
	{
		node = binary_tree_node(NULL, value);
		*head = node;
		return (node);
	}

	/* Get tree height */
	height = binary_tree_height(*head);

	/* Use helper function to insert node */
	node = complete_tree_insert(*head, value, height - 1, 1);

	/* If node was not inserted, then node goes as left as possible */
	if (!node)
	{
		for (tmp = *head; tmp->left; tmp = tmp->left)
			;
		node = binary_tree_node(tmp, value);
		tmp->left = node;
	}

	/* heapify the tree! */
	adjust_node(node);

	/* If node, after heapification, is the head, set head equal to it */
	if (node->parent == NULL)
		*head = node;

	return (node);
}


/**
 * binary_tree_height - returns height of a binary tree
 * @head: head of tree
 * Return: height of tree
 **/
int binary_tree_height(binary_tree_t *head)
{
	int left_height, right_height;

	/* No tree? no height */
	if (head == NULL)
		return (0);

	/* Head has no children? Return height of 1 */
	if (head->right == NULL && head->left == NULL)
		return (1);

	/* get height of left and right sub-trees */
	left_height = binary_tree_height(head->left);
	right_height = binary_tree_height(head->right);

	/* return height of taller sub-tree plus 1 (to represent current node) */
	return (max(left_height, right_height) + 1);
}

/**
 * complete_tree_insert - helper function for heap_insert
 * @head: head of tree
 * @val: value to insert to node
 * @target: target height to verify insertion
 * @current: current height (recursion flag for comparison with target)
 * Return: pointer to new inserted node
 **/
heap_t *complete_tree_insert(heap_t *head, int val, int target, int current)
{
	heap_t *node;


	/* While we still haven't hit the target level, keep recursing */
	if (current < target)
	{
		/* Try to insert to the left */
		node = complete_tree_insert(head->left, val, target, current + 1);

		/* If no space in left side, try the right side */
		if (!node)
			node = complete_tree_insert(head->right, val, target, current + 1);

		/* Return node (or NULL if insertion failed) */
		return (node);
	}

	/* When you've hit the target level... */
	if (current == target)
	{
		/* If node can be inserted to the left, insert and return */
		if (head->left == NULL)
		{
			head->left = binary_tree_node(head, val);
			return (head->left);
		}
		/* else, try the right side */
		if (head->right == NULL)
		{
			head->right = binary_tree_node(head, val);
			return (head->right);
		}
	}
	/* if all else fails, return NULL */
	return (NULL);
}

/**
 * adjust_node - sorts heap
 * @node: node that needs sorting within heap
 **/
void adjust_node(heap_t *node)
{
	heap_t *tmp;

	for (; node->parent && node->n > node->parent->n; node->parent = tmp)
	{
		/* Make children point to node's parent */
		if (node->left)
			node->left->parent = node->parent;
		if (node->right)
			node->right->parent = node->parent;
		/* Make node's parent point to node */
		if (node->parent->parent)
		{
			if (node->parent->parent->left == node->parent)
				node->parent->parent->left = node;
			else
				node->parent->parent->right = node;
		}
		/* Swap left children */
		tmp = node->parent->left, node->parent->left = node->left;
		if (tmp != node)
		{
			node->left = tmp;
			if (tmp)
				tmp->parent = node;
		}
		else
			node->left = node->parent;
		/* Swap right children */
		tmp = node->parent->right, node->parent->right = node->right;
		if (tmp != node)
		{
			node->right = tmp;
			if (tmp)
				tmp->parent = node;
		}
		else
			node->right = node->parent;
		/* Swap parents */
		tmp = node->parent->parent, node->parent->parent = node;
	}
}
