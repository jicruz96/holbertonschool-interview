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
	node = insert_heap_node(*head, value, height - 1, 1);

	/* If node was not inserted, then node goes as left as possible */
	if (!node)
	{
		for (tmp = *head; tmp->left; tmp = tmp->left)
			;
		node = binary_tree_node(tmp, value);
		tmp->left = node;
	}

	/* heapify the tree! */
	adjust_heap(node);

	/* If the node, after heapification, is the head, point head to it */
	if (node->parent == NULL)
		*head = node;
	return (node);
}

/**
 * adjust_heap - sorts heap
 * @node: node that needs sorting within heap
 **/
void adjust_heap(heap_t *node)
{
	heap_t *tmp;

	while (node->parent && node->n > node->parent->n)
	{
		if (node->left)
			node->left->parent = node->parent;
		if (node->right)
			node->right->parent = node->parent;

		if (node->parent->parent)
		{
			if (node->parent->parent->left == node->parent)
				node->parent->parent->left = node;
			else
				node->parent->parent->right = node;
		}

		tmp = node->parent->left, node->parent->left = node->left;
		if (tmp != node)
		{
			node->left = tmp;
			if (tmp)
				tmp->parent = node;
		}
		else
			node->left = node->parent;

		tmp = node->parent->right, node->parent->right = node->right;
		if (tmp != node)
		{
			node->right = tmp;
			if (tmp)
				tmp->parent = node;
		}
		else
			node->right = node->parent;

		tmp = node->parent->parent, node->parent->parent = node;
		node->parent = tmp;
	}
}

/**
 * insert_heap_node - helper function for heap_insert
 * @head: head of tree
 * @val: value to insert to node
 * @target: target height to verify insertion
 * @current: current height (recursion flag for comparison with target)
 * Return: pointer to new inserted node
 **/
heap_t *insert_heap_node(heap_t *head, int val, int target, int current)
{
	heap_t *node;

	if (current < target)
	{
		node = insert_heap_node(head->left, val, target, current + 1);
		if (!node)
			node = insert_heap_node(head->right, val, target, current + 1);
		return (node);
	}

	if (current == target)
	{
		if (head->left == NULL)
		{
			head->left = binary_tree_node(head, val);
			return (head->left);
		}
		if (head->right == NULL)
		{
			head->right = binary_tree_node(head, val);
			return (head->right);
		}
	}

	return (NULL);
}

/**
 * binary_tree_height - returns height of a binary tree
 * @head: head of tree
 * Return: height of tree
 **/
int binary_tree_height(binary_tree_t *head)
{
	int left_height, right_height;

	if (head == NULL)
		return (0);

	if (head->right == NULL && head->left == NULL)
		return (1);

	left_height = binary_tree_height(head->left);
	right_height = binary_tree_height(head->right);

	return (max(left_height, right_height) + 1);
}
