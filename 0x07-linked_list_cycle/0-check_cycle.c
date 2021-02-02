#include "lists.h"

/**
 * check_cycle - checks if a linked list has a cycle
 * @list: list
 * Return: 1 if there's a cycle | 0 if not
 **/
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
