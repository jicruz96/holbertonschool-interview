#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node | 0 if root is NULL
 **/
int heap_extract(heap_t **root)
{
	int n;
	heap_t *last_node;

	if (root == NULL || *root == NULL)
		return (0);

    /* Save root value */
	n = (*root)->n;

	/* Get last node (level-order) */
	last_node = heap_last_node_level_order(*root, heap_height(*root, 1), 1);
    /* Place last node's data at the root */
	(*root)->n = last_node->n;

	/* if root is last node, set root to NULL */
	if (*root == last_node)
		*root = NULL;
	else if (last_node->parent->right == last_node)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;

	/* Delete last node */
	free(last_node);

	/* heapify the heap */
	heapify(*root);

	/* Return number */
	return (n);
}

/**
 * heap_height - returns the height of a heap structure
 * @node: node in a heap
 * @height: height value of the node within the heap
 * Return: height of heap
 **/
int heap_height(heap_t *node, int height)
{
	int left_height, right_height;

	if (node == NULL)
		return (height - 1);

	left_height = heap_height(node->left, height + 1);
	right_height = heap_height(node->right, height + 1);
	return (max(left_height, right_height));
}

/**
 * heap_last_node_level_order - return the last node (in level-order) of a heap
 * @node: pointer to node in the heap
 * @height: height of heap
 * @curr_height: height of current node within heap
 * Return: pointer to last level order node in heap
 **/
heap_t *heap_last_node_level_order(heap_t *node, int height, int curr_height)
{
	heap_t *tmp;

	if (!node)
		return (NULL);

	if (curr_height == height - 1)
		return (node->right ? node->right : node->left);

	tmp = heap_last_node_level_order(node->right, height, curr_height + 1);

	if (tmp)
		return (tmp);

	return (heap_last_node_level_order(node->left, height, curr_height + 1));
}

/**
 * heapify - heapifies a broken heap
 * @node: pointer to node in heap
 **/
void heapify(heap_t *node)
{
	heap_t *largest;
	int n;

	if (!node)
		return;

	largest = node;

	if (node->left && node->left->n >= largest->n)
		largest = node->left;

	if (node->right)
	{
		if (largest == node->left && node->right->n > largest->n)
			largest = node->right;
		else if (node->right->n >= largest->n)
			largest = node->right;
	}

	if (largest != node)
	{
		n = node->n;
		node->n = largest->n;
		largest->n = n;
		heapify(largest);
	}
}
