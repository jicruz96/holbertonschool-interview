# Interview Prep: Insert a Node into a Max Binary Heap

## Description of Problems, Constraints

### Task 0: Write a function that creates a binary tree node

* Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
<br>

### Task 1: Write a function that inserts a node into a max binary heap.

* Prototype: `heap_t *heap_insert(heap_t **head, int value);`
* The function can have up to 5 helper functions.
<br>

### What is a [max binary heap](https://en.wikipedia.org/wiki/Heap_(data_structure)), you ask?

In essence, it's a tree-like data structure where values are sorted from greatest to lowest.

Details in the [wiki page](https://en.wikipedia.org/wiki/Heap_(data_structure)).
<br>

## Proposed Solution 💡

### 21 december 2020 2.0

My final version of `heap_insert()` is almost identical to my first version, except that it gets rid of an unnecesary helper function, `adjust_node()`, which moved a node to the right spot in the tree. Instead of swapping node connections, which is costly, this new approach simply swaps the number values of two nodes.

All functions for version 2.0 can be seen in the file [1-heap_insert.c](./1-heap_insert.c). The principal `heap_insert()` function can be seen below.

```c
heap_t *heap_insert(heap_t **head, int value)
{
	heap_t *node, *tmp;
	int i;

	/* If no tree exists, make node head of tree and return */
	if (*head == NULL)
	{
		node = binary_tree_node(NULL, value);
		*head = node;
		return (node);
	}

	/* Get tree height */
	i = binary_tree_height(*head) - 1;

	/* Use helper function to insert node */
	node = complete_tree_insert(*head, value, i, 1);

	/* If node was not inserted, then node goes as left as possible */
	if (!node)
	{
		for (tmp = *head; tmp->left; tmp = tmp->left)
			;
		node = binary_tree_node(tmp, value);
		tmp->left = node;
	}

	/* heapify the tree! */
	while (node->parent && node->n > node->parent->n)
	{
		i = node->n;
		node->n = node->parent->n;
		node->parent->n = i;
		node = node->parent;
	}

	return (node);
}
```


### 19 december 2020 v 1.0


My first version of `heap_insert()` used three self-built helper functions to get the job done: 
* `binary_tree_height()` -> computes heap height; needed for insertion
* `complete_tree_insert()` -> inserts new node, preserving completeness of heap
* `adjust_node()` -> moves node to appropriate spot in tree to preserve heap nature
	* **This helper function proved to be unnecesary and was removed in version 2.0.** 
All function definitions can be seen in [history/first_heap_insert.c](./history/first_heap_insert.c)


The main function can also be seeen below:

```c
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

	/* Insert node tree into node without regard for sorting */
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
```
