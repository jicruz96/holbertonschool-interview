#include "binary_trees.h"

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
	n = root->n;

	/* Get height of tree */
	height = heap_height(*root);

	/* Get last node (level-order) */
	last_node = heap_last_node_level_order(*root);

    /* Place last node's data at the root */
	root->n = last_node->n;

	/* if root is last node, set root to NULL */
	if (*root == last_node)
		root = NULL;
	
	/* Delete last node */
	free(last_node);

	/* Return number */
    return (n);
}
