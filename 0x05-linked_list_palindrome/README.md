# Interview Prep: Linked List Palindrome

## Description of Problem

Write a function in C that checks if a singly linked list is a palindrome.
* Prototype: `int is_palindrome(listint_t **head);`
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
* An empty list is considered a palindrome

## Proposed Solution 💡

My solution is in file [0-is_palindrome.c](./0-is_palindrome.c) and below:

```C++
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
```
