#include "list.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - adds node to end of a circular doubly linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or `NULL` on failure
 */
List *add_node_end(List **list, char *str)
{
	if (*list == NULL)
	{
		*list = list_node_init(str, NULL, NULL);
		(*list)->prev = *list;
		(*list)->next = *list;
		return (*list);
	}

	(*list)->prev->next = list_node_init(str, *list, (*list)->prev);
	(*list)->prev = (*list)->prev->next;
	return ((*list)->prev);
}

/**
 * add_node_begin - adds node to beginning of a circular doubly linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or `NULL` on failure
 */
List *add_node_begin(List **list, char *str)
{
	*list = add_node_end(list, str);
	return (*list);
}

/**
 * list_node_init - create a new list node
 * @str: string to copy into new node
 * @next: next pointer
 * @prev: prev pointer
 * Return: pointer to new node
 */
List *list_node_init(char *str, List *next, List *prev)
{
	List *node = malloc(sizeof(List));

	if (node)
	{
		node->str = strdup(str);
		node->next = next;
		node->prev = prev;
	}

	return (node);
}
