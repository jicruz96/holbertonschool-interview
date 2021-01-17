# Interview Prep: Linked List Palindrome

## Description of Problem

Write a function in C that checks if a singly linked list is a palindrome.
* Prototype: `int is_palindrome(listint_t **head);`
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
* An empty list is considered a palindrome

## Proposed Solution 💡

My solution is in file [0-is_palindrome.c](./0-is_palindrome.c) and below:

```C++
/**
 * is_palindrome - checks if a linked list of int is a palindrome
 * @head: head of list
 * Return: 1 if palindrome or empty, 0 if not
 **/
int is_palindrome(listint_t **head)
{
	int i, list_len = 0;
	listint_t *tmp, *end;

	/* if list is empty, return 1 */
	if (!head || !(*head))
		return (1);

	/* find list length */
	for (tmp = *head; tmp; tmp = tmp->next)
		list_len++;

	/* point end to middle of list */
	for (i = 0, end = *head; i < (list_len / 2); i++)
		end = end->next;
	tmp = *head;
	return (is_palindrome_recursion(&tmp, end));
}

/**
 * is_palindrome_recursion - does all the magic
 * @front: front pointer
 * @end: end pointer
 * Return: 1 if palindrome, 0 if not
 **/
int is_palindrome_recursion(listint_t **front, listint_t *end)
{
	if (end->next)
	{
		/* if there are more numbers, check those first */
		if (!is_palindrome_recursion(front, end->next))
			return (0);
		/* shift front ahead once to check against current end */
		*front = (*front)->next;
	}
	return ((*front)->n == end->n);
}
```
