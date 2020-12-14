# Interview Prep: Insert a Node into a Singly Linked List

## Description of Problem, Constraints

You are given an integer `number` and the `head` of a sorted singly linked list of integers. Insert `number` into a node on the linked list and return a pointer to the node

* Prototype: `listint_t *insert_node(listint_t **head, int number);`


---


## My Proposed Solution 💡

### **14 december 2020** - there's only one real way to do this, so here it is

```c
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *tmp, *prev = NULL;

	/* Allocate memory for new node. If malloc fails, return NULL */
	node = malloc(sizeof(listint_t));
	if (!node)
		return (NULL);

	/* Populate node */
	node->n = number;
	node->next = NULL;

	/* Scan nodes until list done or value greater than number found */
	for (tmp = *head; tmp && tmp->n < number; tmp = tmp->next)
	{
		/* keep track of previous node */
		prev = tmp;
	}

	/* If previous node exists, make it point to node */
	if (prev)
		prev->next = node;
	else
		/* else, node *MUST* be first in list. Make it the head */
		*head = node;

	/* Node points to next node */
	node->next = tmp;
	return (node);
}
```
