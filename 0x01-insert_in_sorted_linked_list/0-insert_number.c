#include "lists.h"

/**
 * insert_node - inserts a node into a sorted singly linked list
 * @head: double pointer to head of list
 * @number: number to add to linked list
 * Return: pointer to new node
 **/
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
