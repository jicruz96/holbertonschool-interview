#include "binary_trees.h"
#include <stdlib.h>

/** heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node | 0 if root is NULL
 **/
int heap_extract(heap_t **root)
{
    int n, height;
	heap_t *last_node;

    if (root == NULL || *root == NULL)
        return (0);

    /* Find the last node */
	n = (*root)->n;

	/* Get height of tree */
	height = heap_height(*root, 0);

	/* Get last node (level-order) */
	last_node = heap_last_node_level_order(*root);

    /* Place last node's data at the root */
	(*root)->n = last_node->n;

	/* if root is last node, set root to NULL */
	if (*root == last_node)
		*root = NULL;
	
	/* Delete last node */
	free(last_node);

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
		return (height);
	
	left_height = heap_height(node->left, height + 1);
	right_height = heap_height(node->right, height + 1);

	return (max(left_height, right_height));
}

/**
 * heap_last_node_level_order - return the last node (in level-order) of a heap
 * @node: pointer to node in the heap
 * Return: pointer to last level order node in heap
 **/
heap_t *heap_last_node_level_order(heap_t *node)
{
	heap_t *tmp;

	if (!node || (!node->right && !node->left))
		return (node);
	
	tmp = heap_last_node_level_order(node->right);

	if (tmp)
		return (tmp);
	
	return (heap_last_node_level_order(node->left));
}
