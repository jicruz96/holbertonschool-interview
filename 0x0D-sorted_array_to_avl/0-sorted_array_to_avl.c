#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_node - creates AVL tree node
 * @value: value of node
 * @parent: node parent
 * Return: node
 **/
avl_t *create_node(int value, avl_t *parent)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * sorted_array_to_avl - sorted array to avl
 * @array: array
 * @size: size
 * Return: tree
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (helper(array, 0, size - 1, NULL));
}

/**
 * helper - helper
 * @array: array
 * @start: start
 * @end: end
 * @parent: parent
 * Return: tree
 **/
avl_t *helper(int *array, int start, int end, avl_t *parent)
{
	int mid = (start + end) / 2;
	avl_t *node = NULL;

	if (start <= end)
	{
		node = create_node(array[mid], parent);
		if (node == NULL)
			return (NULL);
		node->left = helper(array, start, mid - 1, node);
		node->right = helper(array, mid + 1, end, node);
	}
	return (node);
}
