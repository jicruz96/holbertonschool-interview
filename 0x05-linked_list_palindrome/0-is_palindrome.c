#include "lists.h"



/**
 * is_palindrome - checks if linked list is palindrome
 * @head: pointer to head of list
 * Return: 1 if palindrome or empty | 0 if not
 **/
int is_palindrome(listint_t **head)
{
	listint_t *previous_nums_reversed = NULL, *tmp, *new;

	/* If list is empty or one node long, return 1 */
	if (!head || !(*head) || !(*head)->next)
		return (1);


	/* At each node, check if rest of list is same as list behind, reversed */
	for (tmp = *head; tmp->next; tmp = tmp->next)
	{
		/* Add current number to front of previous_nums_reversed list */
		new = malloc(sizeof(listint_t));
		new->n = tmp->n;
		new->next = previous_nums_reversed;
		previous_nums_reversed = new;

		/* check... */
		if (rest_is_same_as_prevs_reversed(tmp->next, previous_nums_reversed))
			return (1);
	}

	/* if no matches are found, return 0 */
	return (0);
}

/**
 * rest_is_same_as_prevs_reversed - helper function for is_palindrome
 * @rest: the rest of the list
 * @prevs_reversed: the previous numbers in reverse order of appearance
 * Return: 1 if true | 0 if false
 **/
int rest_is_same_as_prevs_reversed(listint_t *rest, listint_t *prevs_reversed)
{

	if (rest->n != prevs_reversed->n)
		prevs_reversed = prevs_reversed->next;

	while (rest && prevs_reversed)
	{
		if (rest->n != prevs_reversed->n)
			return (0);
		rest = rest->next;
		prevs_reversed = prevs_reversed->next;
	}

	return (rest == prevs_reversed);
}
