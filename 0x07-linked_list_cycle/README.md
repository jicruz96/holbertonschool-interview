# Interview Prep: Linked List Cycle Detection

## Description of Problem

Write a function in C that checks if a singly linked list has a cycle in it.

* Prototype: `int check_cycle(listint_t *list);`
* Return `0` if there is no cycle or `1` if there is a cycle

## Proposed Solution 💡

### 2 february 2021

My solution is a straightforward "tortoise and hare" implementation. 

I, the hare, move through the list *two nodes at a time* and I maintain a trailing pointer, the tortoise (denoted by `trailer` pointer in my function), that moves through the list *one node at a time*.

If at any point the leading pointer is equal to the trailing pointer, then we must have looped through, so we return `1`. If our leading pointer reaches the end of the list, then we know there is no cycle and we return `0`.


int check_cycle(listint_t *list)
{
	listint_t *trailer;

	/* If there is no list, there is no cycle. Return 0 */
	if (!list)
		return (0);

	/* Set trailer to 1st node & list to 2nd node. */
	trailer = list;
	list = list->next;

	/* Traverse list until pointers meet or end of list found. */
	while (list && list->next && list != trailer)
	{
		trailer = trailer->next;
		list = list->next->next;
	}

	return (list == trailer);
}
```

We achieve this by creating a loop that moves the two pointers accordingly, but breaks out if `list == trailer` or if the end of the list is coming up (i.e. `list->next` is `NULL`). Then, we return the result of the condition `list == trailer`. (It's implied that `list == trailer` evaluates to false if there is no cycle, because list will be at the end of the list (`NULL`) while `trailer` will be somewhere on the list, so they can't possibly be equal to each other.)
