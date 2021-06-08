#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * find_listint_loop - finds a loop in a linked list
 *
 * @head: head pointer to list to be printed
 *
 * Return: address of the node where the loop starts or NULL if no loop found
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hare, *tortoise;

	hare = head;

	while (hare)
	{
		tortoise = head;
		hare = hare->next;
		if (hare == NULL || hare == tortoise)
			return (hare);
		while (tortoise != hare)
		{
			if (tortoise->next == hare->next)
				return (tortoise->next);
			tortoise = tortoise->next;
		}
	}

	return (hare);
}
