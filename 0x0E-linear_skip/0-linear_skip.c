#include "search.h"

/**
 * linear_skip - finds a value in a sorted (asc.) linked list of integers
 * @list: pointer to a node in the list
 * @value: value to find
 * Return: pointer to node with value, or NULL if not in list or list is empty
 **/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t i = 0;
	skiplist_t *tmp;

	if (list == NULL)
		return (NULL);

	tmp = list->express;
	if (tmp)
		i = (tmp->index * tmp->index) - 1;
	else if (list->next)
		i = 1 + (list->next->next != NULL);

	for (; tmp; list = tmp, tmp = list->express)
	{
		printf("Value checked at index [%lu] = [%d]\n", tmp->index, tmp->n);
		if (tmp->n > value)
		{
			i = tmp->index;
			break;
		}
	}

	printf("Value found between indexes [%lu] and [%lu]\n", list->index, i);
	for (; list != tmp; list = list->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (list->n == value)
			break;
	}

	return (list);
}
